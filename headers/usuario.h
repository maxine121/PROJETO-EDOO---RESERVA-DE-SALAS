#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
private:
    int Id;
    std::string Nome;
    std::string Cpf;

    public:
    Usuario(int id, const std::string& nome, const std::string& cpf): Id(id), Nome(nome), Cpf(cpf){};
    int getId();
    void setId(int id);
    std::string getNome() const;
    void setNome(const std::string& nome);
    std::string getCpf() const;
    void setCpf(const std::string& cpf);

};



#endif