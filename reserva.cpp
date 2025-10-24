//
// Created by italo on 19/10/2025.
//

#include "reserva.h"

Reserva::Reserva(const int id, const std::string &data, const std::string &horario, const std::string &reservadoPor)
    : salaId(id), ReservadoPor(reservadoPor), Data(data), Horario(horario) {}
    int Reserva::getId() const {
    return salaId;
}
    std::string Reserva::getData() const {
        return Data;
    }
    std::string Reserva::getHorario() const {
        return Horario;
    }
    std::string Reserva::getReservadoPor() const {
        return ReservadoPor;
    }
    void Reserva::setId(const int id) {
        salaId = id;
    }
    void Reserva::setData(const std::string &data) {
        Data = data;
    }
    void Reserva::setHorario(const std::string &horario) {
        Horario = horario;
    }
    void Reserva::setReservadoPor(const std::string &reservadoPor) {
        ReservadoPor = reservadoPor;
    }