//
// Created by italo on 19/10/2025.
//

#include "sala.h"

Sala::Sala(int id, const std::string& nome) : id(id), Nome(nome) {}
int Sala::getId() const { return id; }
std::string Sala::getNome() const { return Nome; }