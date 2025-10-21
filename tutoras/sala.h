//
// Created by italo on 19/10/2025.
//

#ifndef TUTORAS_SALA_H
#define TUTORAS_SALA_H
#include <string>


class Sala {
private:
    int id;
    std::string Nome;

public:
    Sala(int id, const std::string& nome);
    int getId() const;
    std::string getNome() const;
};

#endif //TUTORAS_SALA_H