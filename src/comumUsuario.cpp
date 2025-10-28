//
// Created by italo on 25/10/2025.
//

#include "../headers/comumUsuario.h"
#include <fstream>
#include <sstream>



void ComumUsuario::addUsuario(const ComumUsuario& uc) {
    usuariosComuns.push_back(uc);
}

bool ComumUsuario::login(const std::string& nomeInserido,const std::string& senhaInserida, const std::string& cpfInserido) {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getSenha() == senhaInserida && ucm.getNome() == nomeInserido && ucm.getCPF() == cpfInserido) {
            return true;
        }
    }
    return false;
};

void ComumUsuario::carregarUsuariosComuns(const std::string& filename) {
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string nome, senha, cpf;

        std::getline(ss, nome, '|');
        std::getline(ss, senha, '|');
        std::getline(ss, cpf, '|');

        usuariosComuns.push_back(ComumUsuario(nome, senha, cpf));
    }
    in.close();

};

void ComumUsuario::salvarUsuariosComuns(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& ucm : usuariosComuns ) {
        out << ucm.getNome() << "|"
            << ucm.getSenha() << "|"
            << ucm.getCPF() << "\n";
    }
    out.close();
};

bool ComumUsuario::nomeExiste(const std::string& nome) {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getNome() == nome) {
            return true;
        }
    }
    return false;
}
bool ComumUsuario::cpfRepetido(const std::string& cpf) {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getCPF() == cpf) {
            return true;
        }
    }
    return false;
}
int ComumUsuario::getAcessoNivel() const {
    return acessoNivel;
}
