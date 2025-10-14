#ifndef SALA_H
#define SALA_H

#include <string>
#include <iostream>

class Sala{
private:
    int Id;
    std::string Tipo;
public:
    Sala() = default;

    Sala(const int id, const std::string& tipo) : Id(id), Tipo(tipo){

    }
    //declaração dos métodos
    //id de sala
    void setId(int id);

    int getId();
    //tipo de sala
    void setTipo(const std::string& tipo);

    std::string getTipo() const;
};


#endif