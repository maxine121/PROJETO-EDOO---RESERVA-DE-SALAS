#include <iostream>
#include <string>
#include "headers/reserva.h"
#include "headers/admSalas.h"
#include "headers/admUsuario.h"
#include "headers/comumUsuario.h"
#include "headers/gerenciadorUsuariosComuns.h"


//Arquivo principal do projeto;
int main() {
    AdmSalas adm; //Instancia um objeto da classe AdmSalas com todos os métodos necessários para administrar salas e reservas.
    GerenciadorUsuariosComuns pre_uc; // Objeto para gerenciar usuários comuns
    AdmUsuario pre_ua("","","");


    adm.carregarSalasDeArquivo("salas.txt");
    adm.carregarDoArquivo("reservas.txt");
    pre_ua.carregarUsuariosAdms("usuarios_adms.txt");
    pre_uc.carregarUsuariosComuns("usuarios_comuns.txt"); // Corrigido: chama no objeto pre_uc
    int escolha;
    int acesso = 0; // Inicializar acesso
    do {
        //Mensagem inicial da biblioteca;
        std::cout << "\n--- Sistema de Reservas do CIN ---\n"
        << "Boas vindas, o que deseja fazer?\n"
        << "1. Criar Usuario comum\n"
        << "2. Entrar como usuario comum\n"
        << "3. Entrar como administrador\n"
        << "4. Sair\n";
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            escolha = 9;
            // Caso seja digitado uma string, ou algo diferente de um número inteiro, ele limpa o que foi digitado e não armazena;
        }
        std::cin.ignore(100, '\n');
        switch (escolha) {
            case 1: {
                std::string nome, senha, cpf;
                std::cout << "Insira o nome do usuario: ";
                std::cin >> nome;
                std::cout << std::endl << "Insira a senha: ";
                std::cin >> senha;
                std::cout << std::endl << "Insira o cpf: ";
                std::cin >> cpf;
                std::cout << std::endl;

                if (!pre_uc.cpfRepetido(cpf)) {
                    // Corrigido: chama em pre_uc
                    ComumUsuario u(nome, senha, cpf); // Corrigido: 'u' é um ComumUsuario
                    acesso = u.getAcessoNivel();

                    pre_uc.addUsuario(u); // Corrigido: 'pre_uc' adiciona o usuário
                    pre_uc.salvarUsuariosComuns("usuarios_comuns.txt"); // Corrigido: 'pre_uc' salva

                    std::cout << "Usuario adicionado com sucesso" << std::endl;
                } else {
                    std::cout << "O Cpf inserido ja esta em uso por outro usuario." << std::endl;
                    escolha = 9;
                }
                break;
            }
            case 2: {
                std::string nome, senha, cpf;
                std::cout << "Insira o nome do usuario: ";
                std::cin >> nome;
                std::cout << std::endl << "Insira a senha: ";
                std::cin >> senha;
                std::cout << std::endl << "Insira a cpf: ";
                std::cin >> cpf;
                std::cout << std::endl;
                if (pre_uc.login(nome, senha, cpf)) {
                    
                    ComumUsuario u(nome, senha, cpf);
                    acesso = u.getAcessoNivel(); // Corrigido: pegando o nível de acesso no login
                    //removido bug lógico: u.addUsuario(u); (Não se adiciona usuário no login)
                } else {
                    std::cout << "Credenciais invalidas. Tente novamente." << std::endl;
                    escolha = 9;
                }

            }break;
            case 3: {
                std::string nome, senha, cpf;
                std::cout << "Insira o nome do usuario: ";
                std::cin >> nome;
                std::cout << std::endl << "Insira a senha: ";
                std::cin >> senha;
                std::cout << std::endl << "Insira a cpf: ";
                std::cin >> cpf;
                std::cout << std::endl;
                if (pre_ua.login(nome, senha, cpf)) {
                    AdmUsuario u(nome, senha, cpf);
                    acesso = u.getAcessoNivel();
                } else {
                    // Adicionado feedback para login de admin falho
                    std::cout << "Credenciais invalidas. Tente novamente." << std::endl;
                    escolha = 9;
                }
            }break;
            case 4: {
                    return 0;
                }
            default:
                //Aqui ele volta ao loop quando a escolha for diferente de 1, 2 e 3;
                std::cout << "Escolha invalida, tente outra vez.\n";
            }
        }   while (escolha != 1 && escolha != 2 && escolha != 3);

    do {
        //Acesso às salas disponíveis no momento;
        std::cout << "\n--- Sistema de Reservas do CIN ---\n";
        std::cout << "Essas sao as salas atualmente disponiveis:\n";
        adm.listarSalas();
        std::cout << "1. Adicionar reserva\n";
        std::cout << "2. Listar reservas atuais\n";
        std::cout << "3. Cancelar Reserva\n";
        std::cout << "4. Adicionar nova sala (Admin)\n"; 
        std::cout << "5. Sair e salvar\n";
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            escolha = 9;
        }
        std::cin.ignore(100, '\n');
        switch (escolha) {
            case 1: {
                int id, duracao;

                std::string data, horario, reservadoPor;
                //informações necessárias de reserva de sala;

                std::cout << "Digite o id da sala: ";
                std::cin >> id;

                std::cout << "Digite a data quando deseja reservar (Dia-Mes-Ano): ";
                std::cin >> data;

                std::cout << "Digite o horario de inicio de reserva (ex.: 14): ";
                std::cin >> horario;

                std::cout << "digite por quantas horas (ex.: 2): ";
                std::cin >> duracao;

                std::cin.ignore();
                std::cout << "Digite seu nome: ";
                std::getline(std::cin, reservadoPor);


                Reserva r(id, data, horario, reservadoPor, duracao); //Instancia um obj da classe Reserva.


                if (adm.addReserva(r)) { //Tenta adicioná-lo ao vetor reservas caso não seja igual a outro.
                    std::cout << "Reserva adicionada com sucesso.\n";
                    adm.salvarNoArquivo("reservas.txt");
                }
            }
                break;
            case 2:
                adm.listarReservas();
                break;
            case 3: {
                if (acesso == 2) { // Acesso de Admin

                    int id;
                    std::string data, horario;

                    std::cout << "Digite o id da sala da qual deseja cancelar a reserva: ";
                    std::cin >> id;

                    std::cout << "Digite a data para qual esta reservada: ";
                    std::cin >> data;

                    std::cout << "Digite o horario de inicio para qual esta reservada: ";
                    std::cin >> horario;

                    if (adm.cancelarReserva(id, data, horario)) {
                        std::cout << "Reserva cancelada.\n";
                        adm.salvarNoArquivo("reservas.txt");
                    } else {
                        std::cout << "Sala ou horario não encontrado(s).\n";
                    }
                }
                else {
                    std::cout<<"Acesso negado" << std::endl;
                }
            }
            break; // Adicionado break faltando
            case 4: {
                if (acesso == 2){ // Acesso de Admin
                    int id;
                    std::string nome;

                    std::cout << "Digite o ID da nova sala: ";
                    std::cin >> id;

                    if (adm.salaExiste(id)){
                        //Essa condição impede que exista uma sala com ID repetido;
                        std::cout << "Erro: Ja existe uma sala com este ID.\n";
                    }else{
                        std::cin.ignore(); //limpa o buffer
                        std::cout << "Digite o nome da nova sala: ";
                        std::getline(std::cin, nome);

                        Sala novaSala(id, nome);
                        adm.addSala(novaSala);
                        adm.salvarSalasEmArquivo("salas.txt");
                        std::cout << "Sala adicionada com sucesso. \n";
                    }
                } else {
                    std::cout<<"Acesso negado" << std::endl;
                }
            }
                break;
            case 5: //Assim que o usuário sai do sistema, ele salva o estado do vetor reservas em reservas.txt.
                adm.salvarNoArquivo("reservas.txt");
                adm.salvarSalasEmArquivo("salas.txt");
                std::cout << "Saindo e salvando...\n";
                break;
            default:
                std::cout << "Escolha invalida, tente outra vez.\n";
        }
    } while (escolha != 5);
    return 0;
}