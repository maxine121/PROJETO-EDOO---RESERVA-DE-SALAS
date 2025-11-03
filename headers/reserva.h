//
// Created by italo on 19/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_RESERVA_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_RESERVA_H
#include <string>


class Reserva {
    // Declaração de ID, pessoa que reservou, data, horário e duração
private:
    int salaId;
    std::string ReservadoPor;
    std::string Data;
    std::string Horario;
    int Duracao;



    public:
    Reserva(int id, const std::string &data, const std::string &horario, const std::string &reservadoPor, int duracao); //Construtor
    // uso de nodiscard para melhorar confiança e segurança no código
    [[nodiscard]] int getId() const;
    [[nodiscard]] std::string getData() const;
    [[nodiscard]] std::string getHorario() const;
    [[nodiscard]] std::string getReservadoPor() const;
    [[nodiscard]] int getDuracao() const;
    void setId(int id);
    void setData(const std::string &data);
    void setHorario(const std::string &horario);
    void setReservadoPor(const std::string &reservadoPor);
    void setDuracao(int duracao);
};


#endif //PROJETO_EDOO_RESERVA_DE_SALAS_RESERVA_H