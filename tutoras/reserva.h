//
// Created by italo on 19/10/2025.
//

#ifndef TUTORAS_RESERVA_H
#define TUTORAS_RESERVA_H
#include <string>


class Reserva {
private:
    int salaId;
    std::string ReservadoPor;
    std::string Data;
    std::string Horario;
    public:
    Reserva(int id, const std::string &data, const std::string &horario, const std::string &reservadoPor); //Construtor
    [[nodiscard]] int getId() const;
    [[nodiscard]] std::string getData() const;
    [[nodiscard]] std::string getHorario() const;
    [[nodiscard]] std::string getReservadoPor() const;
    void setId(int id);
    void setData(const std::string &data);
    void setHorario(const std::string &horario);
    void setReservadoPor(const std::string &reservadoPor);
};


#endif //TUTORAS_RESERVA_H