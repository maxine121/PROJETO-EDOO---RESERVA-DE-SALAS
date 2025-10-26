//
// Created by italo on 20/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H
#include <vector>

#include "reserva.h"
#include "sala.h"

class AdmSalas {
private:
    std::vector<Sala> salas;
    std::vector<Reserva> reservas;
    public:
    bool addReserva(const Reserva& r);
    bool isDisponivel(int salaId, const std::string& data, const std::string& horario) const;
    void listarReservas() const;
    bool cancelarReserva(int salaId, const std::string& data, const std::string& horario);
    void salvarNoArquivo(const std::string& filename) const;
    void carregarDoArquivo(const std::string& filename);
    void addSala(const Sala& s);
    void listarSalas() const;
    bool salaExiste(int id) const;
    void carregarSalasDeArquivo(const std::string& filename);
};


#endif //PROJETO_EDOO_RESERVA_DE_SALAS_ADMSALAS_H