//
// Created by italo on 19/10/2025.
//

#ifndef EDOO_RESERVA_H
#define EDOO_RESERVA_H
#include <string>


class Reserva {
private:
    int salaId;
    std::string ReservadoPor;
    std::string Data;
    std::string Horario;
    int Duracao;



    public:
    Reserva(int id, const std::string &data, const std::string &horario, const std::string &reservadoPor, int duracao); //Construtor
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


#endif //EDOO_RESERVA_H