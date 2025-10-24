//
// Created by italo on 20/10/2025.
//

#include "../headers/admSalas.h"
#include <fstream>
#include <sstream>
#include <iostream>
bool AdmSalas::addReserva(const Reserva& r) {
    if (salaExiste(r.getId()) && isDisponivel(r.getId(), r.getData(), r.getHorario())) {
        reservas.push_back(r);
        return true;
    }
    std::cout << "Sala nao encontrada ou horario/data nao informados corretamente.\n";
    return false;
}
bool AdmSalas::isDisponivel(int salaId, const std::string& data, const std::string& horario) const {
    for (const auto& res : reservas) {
        if (res.getId() == salaId &&
            res.getData() == data &&
            res.getHorario() == horario) {
            return false;
            }
    }
    return true;
}
void AdmSalas::listarReservas() const {
    if (reservas.empty()) {
        std::cout << "Nao existem reservas no momento" << std::endl;}
    for (const auto& res : reservas) {
        std::cout << "Sala " << res.getId()
                  << " reservada por " << res.getReservadoPor()
                  << " para " << res.getData()
                  << " de " << res.getHorario() << "\n";
    }
}
bool AdmSalas::cancelarReserva(int salaId, const std::string& data, const std::string& horario) {
    for (auto it = reservas.begin(); it != reservas.end(); ++it) {
        if (it->getId() == salaId &&
            it->getData() == data &&
            it->getHorario() == horario) {
            reservas.erase(it);
            return true;
            }
    }
    return false;
}
void AdmSalas::salvarNoArquivo(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& res : reservas) {
        out << res.getId() << "|"
            << res.getData() << "|"
            << res.getHorario() << "|"
            << res.getReservadoPor() << "\n";
    }
    out.close();
}
void AdmSalas::carregarDoArquivo(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, data, horario, reservadoPor;

        std::getline(ss, idStr, '|');
        std::getline(ss, data, '|');
        std::getline(ss, horario, '|');
        std::getline(ss, reservadoPor, '|');

        int id = std::stoi(idStr);
        reservas.push_back(Reserva(id, data, horario, reservadoPor));
    }
    in.close();
}

void AdmSalas::addSala(const Sala& s) {
    salas.push_back(s);
}

void AdmSalas::listarSalas() const {
    for (const auto& s : salas) {
        std::cout << "ID: " << s.getId() << " - " << s.getNome() << "\n";
    }
}

bool AdmSalas::salaExiste(int id) const {
    for (const auto& s : salas) {
        if (s.getId() == id) return true;
    }
    return false;
}

void AdmSalas::carregarSalasDeArquivo(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, nome;

        std::getline(ss, idStr, '|');
        std::getline(ss, nome, '|');

        int id = std::stoi(idStr);
        salas.push_back(Sala(id, nome));
    }
    in.close();
}