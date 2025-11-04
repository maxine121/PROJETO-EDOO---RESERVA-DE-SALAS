//
// Created by italo on 25/10/2025.
//

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_ADMUSUARIO_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_ADMUSUARIO_H
#include <vector>

#include "usuario.h"

class AdmUsuario : Usuario{
private:
    std::vector<AdmUsuario> usuariosAdms;
    int acessoNivel = 2;
public:
    using Usuario::Usuario;
    void addUsuario(const AdmUsuario& ua);
    bool login(const std::string& nomeInserido, const std::string& senhaInserida, const std::string& cpfInserido);
    void carregarUsuariosAdms(const std::string& filename);
    bool nomeExiste(const std::string& nome);
    bool cpfRepetido(const std::string& cpf);
    int getAcessoNivel() const;
    std::string printNome() const;
};


#endif //PROJETO_EDOO_RESERVA_DE_SALAS_ADMUSUARIO_H