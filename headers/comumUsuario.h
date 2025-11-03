//Created by italo on 25/10/2025.
// headers/comumUsuario.h

#ifndef PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H
#define PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H

#include "usuario.h"
// Removido: #include <vector> (não é mais necessário aqui)

class ComumUsuario : public Usuario {
    //Aqui define o nível de acesso que um usuário comum possui à biblioteca;
private:
    int acessoNivel = 1;
public:
    //Nesse ponto,
    using Usuario::Usuario;
    int getAcessoNivel() const;
};

#endif //PROJETO_EDOO_RESERVA_DE_SALAS_COMUMUSUARIO_H