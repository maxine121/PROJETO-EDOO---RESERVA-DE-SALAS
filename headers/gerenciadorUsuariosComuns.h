#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_GERENCIADORUSUARIOSCOMUNS_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_GERENCIADORUSUARIOSCOMUNS_H

#include <vector>
#include <string>
#include "comumUsuario.h" //precisa saber o que é um ComumUsuario

class GerenciadorUsuariosComuns {
private:
    std::vector<ComumUsuario> usuariosComuns; //alista fica AQUI

public:
    //todas as funções de gerenciamento vêm para cá
    void addUsuario(const ComumUsuario& uc);
    bool login(const std::string& nomeInserido, const std::string& senhaInserida, const std::string& cpfInserido);
    void carregarUsuariosComuns(const std::string& filename);
    void salvarUsuariosComuns(const std::string& filename) const;
    bool nomeExiste(const std::string& nome);
    bool cpfRepetido(const std::string& cpf) const;
};

#endif //PROJETO_EDOO_RESERVA_DE_SALAS_GERENCIADORUSUARIOSCOMUNS_H