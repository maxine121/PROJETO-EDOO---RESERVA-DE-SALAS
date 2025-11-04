//
// Created by italo on 25/10/2025.
//
// Definição de cada componente inerente ao usuário;
#include "../headers/usuario.h"
Usuario::Usuario(const std::string &nome, const std::string &senha, const std::string &cpf )
    : Nome(nome), Senha(senha), Cpf(cpf) {}

std::string Usuario::getNome() const {
    return Nome;
}

std::string Usuario::getSenha() const {
    return Senha;
}

std::string Usuario::getCPF() const {
    return Cpf;
}

void Usuario::setNome(const std::string &nome) {
    Nome = nome;
}

void Usuario::setSenha(const std::string &senha) {
    Senha = senha;
}

void Usuario::setCPF(const std::string &cpf) {
    Cpf = cpf;
}
std::string Usuario::printNome() const {
    return Nome;
}