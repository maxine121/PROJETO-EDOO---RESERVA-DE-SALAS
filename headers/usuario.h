//
// Created by italo on 25/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_USUARIO_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_USUARIO_H
#include <string>


class Usuario {
    //Aqui em protected as informações são acessadas pela mesma classe ou por classes derivadas
protected:
    std::string Nome;
    std::string Senha;
    std::string Cpf;
public:
    // Declaração de informações de nome, senha e cpf dos usuários;
    Usuario(const std::string &nome, const std::string &senha, const std::string &cpf );
    [[nodiscard]] std::string getNome() const;
    [[nodiscard]] std::string getSenha() const;
    [[nodiscard]] std::string getCPF() const;
    void setNome(const std::string &nome);
    void setSenha(const std::string &senha);
    void setCPF(const std::string &cpf);
    std::string printNome() const;
};


#endif //PROJETO_EDOO_RESERVA_DE_SALAS_USUARIO_H