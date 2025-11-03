
#include "../headers/sala.h"
// Definição de ID e NOME da sala
Sala::Sala(int id, const std::string& nome) : id(id), Nome(nome) {}
int Sala::getId() const { return id; }
std::string Sala::getNome() const { return Nome; }