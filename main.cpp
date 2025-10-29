#include <iostream>
#include <string>
#include <cstdlib> //lib para limpar tela
#include "headers/reserva.h"
#include "headers/admSalas.h"
#include "headers/admUsuario.h"
#include "headers/comumUsuario.h"

void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    // Assume sistemas POSIX (Linux, macOS)
    system("clear");
#endif
}

int main() {
    AdmSalas adm; //Instancia um objeto da classe AdmSalas com todos os métodos necessários para administrar salas e reservas.
    ComumUsuario pre_uc("","","");
    AdmUsuario pre_ua("","","");


    adm.carregarSalasDeArquivo("salas.txt");
    adm.carregarDoArquivo("reservas.txt");
    pre_ua.carregarUsuariosAdms("usuarios_adms.txt");
    pre_uc.carregarUsuariosComuns("usuarios_comuns.txt");
    int escolha;
    int acesso;
    escolha_invalida:
    do {
        limparTela();
        std::cout << "\n--- Sistema de Reservas do CIN ---\n"
        << "Boas vindas, o que deseja fazer?\n"
        << "1. Criar Usuario comum\n"
        << "2. Entrar como usuario comum\n"
        << "3. Entrar como administrador\n"
        << "4. Sair\n"
        << "Digite sua escolha: ";
        std::cin >> escolha;

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

                if (pre_uc.cpfRepetido(cpf)) {
                    std::cout << "Esse cpf ja esta cadastrado a outra conta." << std::endl;
                    goto escolha_invalida;
                }
                if (!pre_uc.login(nome, senha, cpf)) {
                    ComumUsuario u(nome, senha, cpf);
                    acesso = u.getAcessoNivel();
                    u.addUsuario(u);
                    u.salvarUsuariosComuns("usuarios_comuns.txt");

                    std::cout << "Usuario adicionado com sucesso" << std::endl;
                }

            } break;
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
                    acesso = u.getAcessoNivel();
                    u.addUsuario(u);
                } else {
                    std::cout << "Credenciais invalidas. Tente novamente." << std::endl;
                    goto escolha_invalida;
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
                }
            }break;
            case 4: {
                    return 0;
                }
                default:
                std::cout << "Escolha invalida, tente outra vez.\n";
            }
        }   while (escolha != 1 && escolha != 2 && escolha != 3);

    do {
        limparTela();
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

        switch (escolha) {
            case 1: {
                int id, duracao;

                std::string data, horario, reservadoPor;

                std::cout << "Digite o id da sala: ";
                std::cin >> id;

                std::cout << "Digite a data quando deseja reservar (Ano-Mes-Dia): ";
                std::cin >> data;

                std::cout << "Digite o horario de inicio de reserva (ex.: 14): ";
                std::cin >> horario;

                std::cout << "digite por quantas horas (ex.: 2): ";
                std::cin >> duracao;

                std::cin.ignore();
                std::cout << "Digite seu nome: ";
                std::getline(std::cin, reservadoPor);


                Reserva r(id, data, horario, reservadoPor, duracao); // Instancia um obj da classe Reserva.


                if (adm.addReserva(r)) { //Tenta adicioná-lo ao vetor reservas caso não seja igual a outro.
                    std::cout << "Reserva adicionada com sucesso.\n";
                }
            }
                break;
            case 2:
                adm.listarReservas();
                break;
            case 3: {
                if (acesso == 2) {

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
                    } else {
                        std::cout << "Sala ou horario não encontrado(s).\n";
                    }
                }
                else {
                    std::cout<<"Acesso negado" << std::endl;
                }
            }
            case 4: {
                if (acesso == 2){
                    int id;
                    std::string nome;

                    std::cout << "Digite o ID da nova sala: ";
                    std::cin >> id;

                    if (adm.salaExiste(id)){
                        std::cout << "Erro: Ja existe uma sala com este ID.\n";
                    }else{
                        std::cin.ignore(); //limpa o buffer
                        std::cout << "Digite o numero da nova sala: ";
                        std::getline(std::cin, nome);

                        Sala novaSala(id, nome);
                        adm.addSala(novaSala);
                        std::cout << "Sala adicionada com sucesso. \n";
                    }
                }
            }
                break;
            case 5: //Assim que o usuário sai do sistema, ele salva o estado do vetor reservas em reservas.txt.
                adm.salvarNoArquivo("reservas.txt");
                adm.salvarSalasEmArquivo("salas.txt");
                limparTela();
                std::cout << "Saindo e salvando...\n";
                break;
            default:
                std::cout << "Escolha invalida, tente outra vez.\n";
        }
    } while (escolha != 5);
    return 0;
}
