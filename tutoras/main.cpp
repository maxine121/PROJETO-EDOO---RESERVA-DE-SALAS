#include <iostream>
#include <string>
#include "reserva.h"
#include "admSalas.h"

int main() {
    std::cout << "Ola e bem vindo(a) ao sistema de reservas de salas do CIN" << std::endl;
    AdmSalas adm;
    adm.carregarSalasDeArquivo("salas.txt");
    adm.carregarDoArquivo("reservas.txt");
    int escolha;
    do {
        std::cout << "\n--- Sistema de Reservas do CIN ---\n";
        std::cout << "Essas sao as salas atualmente disponiveis:\n";
        adm.listarSalas();
        std::cout << "1. Adicionar reserva\n";
        std::cout << "2. Listar reservas atuais\n";
        std::cout << "3. Cancelar Reserva\n";
        std::cout << "4. Sair e salvar\n";
        std::cout << "Digite sua escolha: ";
        std::cin >> escolha;

        // Handle each option below
        switch (escolha) {
            case 1: {
                int id;
                std::string data, horario, reservadoPor;

                std::cout << "Digite o id da sala: ";
                std::cin >> id;

                std::cout << "Digite a data quando deseja reservar (Ano-Mes-Dia): ";
                std::cin >> data;

                std::cout << "Digite o horario de inicio de reserva (ex.: 14:00): ";
                std::cin >> horario;

                std::cin.ignore(); // Clear leftover newline
                std::cout << "Digite seu nome: ";
                std::getline(std::cin, reservadoPor);

                // Create reservation object
                Reserva r(id, data, horario, reservadoPor);

                // Try to add it
                if (adm.addReserva(r)) {
                    std::cout << "Reserva adicionada com sucesso.\n";
                }
            }
                break;
            case 2:
                adm.listarReservas();
                break;
            case 3:{
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
                break;
            case 4:
                adm.salvarNoArquivo("reservas.txt");
                std::cout << "Saindo e salvando...\n";
                break;
            default:
                std::cout << "Escolha invalida, tente outra vez.\n";
        }
    } while (escolha != 4);
    return 0;
}
