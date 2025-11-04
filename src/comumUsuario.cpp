// comumUsuario.cpp

#include "../headers/comumUsuario.h"
//Define o nível do usuário comum;
int ComumUsuario::getAcessoNivel() const {
    return acessoNivel;
}
std::string ComumUsuario::printNome() const {
    return Nome + " (usuario comum).";
}