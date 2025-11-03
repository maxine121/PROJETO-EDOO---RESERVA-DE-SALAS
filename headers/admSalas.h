//
// Created by italo on 20/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H
#include <vector>

#include "reserva.h"
#include "sala.h"
class AdmSalas {
//Aqui é uma classe particular, com funcões que apenas administradores podem ter acesso;
private:
    std::vector<Sala> salas; //Vetores para salvar as diferentes salas e reservas;
    std::vector<Reserva> reservas;
    public:
    // Aqui podem haver funcionaliades e mudanças nas variáveis;
    //Essa classe, que é uma classe de negócios, tem o intuito de gerenciar o funcionamento do sistema
    bool addReserva(const Reserva& r);
    bool isDisponivel(int salaId, const std::string& data, const std::string& horario, int duracao) const;
    void listarReservas() const;
    bool cancelarReserva(int salaId, const std::string& data, const std::string& horario);
    void salvarNoArquivo(const std::string& filename) const;
    void carregarDoArquivo(const std::string& filename);
    void addSala(const Sala& s);
    void listarSalas() const;
    bool salaExiste(int id) const;
    void carregarSalasDeArquivo(const std::string& filename);
    void salvarSalasEmArquivo(const std::string& filename) const;
};


#endif //PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H