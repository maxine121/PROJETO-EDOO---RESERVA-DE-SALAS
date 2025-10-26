//
// Created by italo on 25/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H
#include <vector>

#include "usuario.h"

class ComumUsuario : public Usuario{
private:
    std::vector<ComumUsuario> usuariosComuns;
    int acessoNivel = 1;
public:
    using Usuario::Usuario;
    void addUsuario(const ComumUsuario& uc);
    bool login(const std::string& nomeInserido,const std::string& senhaInserida, const std::string& cpfInserido);
    void carregarUsuariosComuns(const std::string& filename);
    void salvarUsuariosComuns(const std::string& filename) const;
    bool nomeExiste(const std::string& nome);
    bool cpfRepetido(const std::string& cpf);
};

#endif //PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H