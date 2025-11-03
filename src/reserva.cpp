//
// Created by italo on 19/10/2025.
//

#include "../headers/reserva.h"
//Aqui constam todos os dados necessários para reservar salas, como ID, responsável, data, horário e duração;
Reserva::Reserva(const int id, const std::string &data, const std::string &horario, const std::string &reservadoPor, const int duracao)
    : salaId(id), ReservadoPor(reservadoPor), Data(data), Horario(horario), Duracao(duracao) {}
    int Reserva::getId() const {
    return salaId;
}
//Aqui define dados de reserva de sala, como ID, duração e data;
    std::string Reserva::getData() const {
        return Data;
    }
    std::string Reserva::getHorario() const {
        return Horario;
    }
    std::string Reserva::getReservadoPor() const {
        return ReservadoPor;
    }
    int  Reserva::getDuracao() const {
        return Duracao;
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
    void Reserva::setDuracao(const int duracao) {
        Duracao = duracao;
    }