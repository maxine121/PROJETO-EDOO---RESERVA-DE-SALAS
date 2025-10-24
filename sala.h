//
// Created by italo on 19/10/2025.
//

#ifndef EDOO_SALA_H
#define EDOO_SALA_H
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

#endif //EDOO_SALA_H