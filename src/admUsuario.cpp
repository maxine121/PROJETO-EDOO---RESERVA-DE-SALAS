//
// Created by italo on 25/10/2025.
//

#include "../headers/admUsuario.h"
#include <fstream>
#include <sstream>

//Aqui dá a oportunidade de criar mais um usuário no banco de dados, especificamente no arquivo .txt
void AdmUsuario::addUsuario(const AdmUsuario& ua) {
    usuariosAdms.push_back(ua);
}

bool AdmUsuario::login(const std::string& nomeInserido, const std::string& senhaInserida, const std::string& cpfInserido) {
    for (const auto& ucm : usuariosAdms) {
        if (ucm.getNome() == nomeInserido, ucm.getSenha() == senhaInserida, ucm.getCPF() == cpfInserido) {
            return true;
        }
    }
    // Conferir se a senha do usuário administrador está correta para fazer login e entrar
    return false;
};

void AdmUsuario::carregarUsuariosAdms(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string nome, senha, cpf;

        std::getline(ss, nome, '|');
        std::getline(ss, senha, '|');
        std::getline(ss, cpf, '|');
        //Mais uma vez dividimos as informações de nome, senha e cpf entre barras verticais
        usuariosAdms.push_back(AdmUsuario(nome, senha, cpf));
    }
    in.close();

};

bool AdmUsuario::nomeExiste(const std::string& nome) {
    for (const auto& uadm : usuariosAdms) {
        if (uadm.getNome() == nome) {
            return true;
        }
        //Conferir se um determinado nome já existe no arquivo .txt de armazenamento de dados;
    }
    return false;
}
bool AdmUsuario::cpfRepetido(const std::string& cpf) {
    for (const auto& uadm : usuariosAdms) {
        if (uadm.getCPF() == cpf) {
            return true;
        }
        //Não podem haver duas pessoas com mesmo cpf;
    }
    return false;
}
int AdmUsuario::getAcessoNivel() const {
    //Dá a permissão de visualizar o nível de cada usuário;
    return acessoNivel;
}
