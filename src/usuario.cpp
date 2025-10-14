#include "../headers/usuario.h"
void Usuario::setId(int id) {
    Id = id;
}
int Usuario::getId() {
    return Id;
}
void Usuario::setCpf(const std::string &cpf) {
    Cpf = cpf;
}
std::string Usuario::getCpf() const {
    return Cpf;
}
void Usuario::setNome(const std::string &nome) {
    Nome = nome;
}
std::string Usuario::getNome() const {
    return Nome;
}

