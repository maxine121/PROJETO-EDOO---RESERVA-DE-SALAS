//
// Created by italo on 19/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_SALA_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_SALA_H
#include <string>


class Sala {
    //Cada sala tem seu ID específico, que é declarado em "private" juntamente com "nome"
private:
    int id;
    std::string Nome;
    //Aqui esses dados podem ser modificados;
public:
    Sala(int id, const std::string& nome);
    int getId() const;
    std::string getNome() const;
};

#endif //PROJETO_EDOO_RESERVA_DE_SALAS_SALA_H