#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_GERENCIADORUSUARIOSCOMUNS_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_GERENCIADORUSUARIOSCOMUNS_H

//atrelando classes para usuários a fim de armazenar os dados de cada instância deles dentro de um vetor
#include <vector>
#include <string>
#include "comumUsuario.h"

class GerenciadorUsuariosComuns {
private:
    std::vector<ComumUsuario> usuariosComuns; //a lista fica AQUI

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