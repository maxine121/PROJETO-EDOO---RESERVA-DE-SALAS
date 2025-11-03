//
// Created by italo on 20/10/2025.
//

#include "../headers/admSalas.h"
#include <fstream>
#include <sstream>
#include <iostream>
bool AdmSalas::addReserva(const Reserva& r) {
    if (salaExiste(r.getId()) && isDisponivel(r.getId(), r.getData(), r.getHorario(), r.getDuracao())) {
        reservas.push_back(r);
        return true;
    }
    std::cout << "Sala nao encontrada ou horario/data nao informados corretamente.\n";
    return false;
}
bool AdmSalas::isDisponivel(int salaId, const std::string& data, const std::string& horario, int duracao) const {
    int novo_inicio;
    try {
        //tenta converter o novo horário para um número
        novo_inicio = std::stoi(horario);
    } catch (...) {
        //se 'horario' for algo como "14h" ou "abc", std::stoi falha
        std::cout << "Erro: formato de horario invalido. Use apenas numeros (ex: 14)." << std::endl;
        return false; //n eh um número
    }
    
    //calcula o período da nova reserva
    int novo_fim = novo_inicio + duracao;

    for (const auto& res : reservas) {
        //checa apenas reservas para a mesma sala na mesma data
        if (res.getId() == salaId && res.getData() == data) {
            
            int existente_inicio;
            try {
                //converte o horário da reserva existente para um número
                existente_inicio = std::stoi(res.getHorario());
            } catch (...) {
                //ignora reservas mal formatadas no arquivo .txt
                continue; 
            }

            //calcula o período da reserva existente
            int existente_duracao = res.getDuracao();
            int existente_fim = existente_inicio + existente_duracao;

            //checagem de sobreposição de intervalo
            //(InicioA < FimB) E (InicioB < FimA)
            if (novo_inicio < existente_fim && existente_inicio < novo_fim) {
                std::cout << "Erro: Conflito de horario! Sala ja reservada de " 
                          << existente_inicio << ":00 as " << existente_fim << ":00." << std::endl;
                return false; //CONFLITO! Não está disponível.
            }
        }
    }
    return true;//nenhum conflito encontrado
}
void AdmSalas::listarReservas() const {
    if (reservas.empty()) {
        std::cout << "Nao existem reservas no momento" << std::endl;}
    for (const auto& res : reservas) {
        std::cout << "Sala " << res.getId()
                  << " reservada por " << res.getReservadoPor()
                  << " para " << res.getData()
                  << " de " << res.getHorario() << ":00 "
                  << " por " << res.getDuracao() << " horas"
        <<"\n";
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
            << res.getReservadoPor() <<"|"
            << res.getDuracao() << "\n";
    }
    out.close();
}
void AdmSalas::carregarDoArquivo(const std::string& filename) {
    try {std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string idStr, data, horario, reservadoPor, reservadoDuracao;

        std::getline(ss, idStr, '|');
        std::getline(ss, data, '|');
        std::getline(ss, horario, '|');
        std::getline(ss, reservadoPor, '|');
        std::getline(ss, reservadoDuracao, '|');


        int id = std::stoi(idStr);
        int duracao = std::stoi(reservadoDuracao);
        reservas.push_back(Reserva(id, data, horario, reservadoPor, duracao));
    }
    in.close();
} catch (...) {
    return;
}
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

void AdmSalas::salvarSalasEmArquivo(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& s : salas) {
        out << s.getId() << "|"
            << s.getNome() << "\n";
    }
    out.close();
}
