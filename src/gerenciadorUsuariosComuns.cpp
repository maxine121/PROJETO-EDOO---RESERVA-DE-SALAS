#include "../headers/gerenciadorUsuariosComuns.h"
#include <fstream>
#include <sstream>
#include <iostream> 

void GerenciadorUsuariosComuns::addUsuario(const ComumUsuario& uc) {
    usuariosComuns.push_back(uc);
    std::cout << "[DEBUG] Usuário " << uc.getNome() << " adicionado ao vetor em memória." << std::endl;
    //Aqui mostra que a função de cadastro foi realizada com sucesso;
}

bool GerenciadorUsuariosComuns::login(const std::string& nomeInserido, const std::string& senhaInserida, const std::string& cpfInserido) {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getSenha() == senhaInserida && ucm.getNome() == nomeInserido && ucm.getCPF() == cpfInserido) {
            return true;
        }
        //Aqui compara se a senha do usuário está correta;
    }
    return false;
}

void GerenciadorUsuariosComuns::carregarUsuariosComuns(const std::string& filename) {
    std::ifstream in(filename);
    
    // DEBUG: Checar se o arquivo abriu
    if (!in.is_open()) {
        std::cout << "[DEBUG] ERRO: Nao foi possivel abrir o arquivo " << filename << std::endl;
        std::cout << "[DEBUG] O arquivo sera criado na proxima vez que salvar." << std::endl;
        return; // Sai da função
    }
    
    std::cout << "[DEBUG] Carregando usuarios de " << filename << "..." << std::endl;
    
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string nome, senha, cpf;

        std::getline(ss, nome, '|');
        std::getline(ss, senha, '|');
        std::getline(ss, cpf, '|');
        //Adiciona os dados na mesma linha e separados por barra vertical;
        // Adiciona ao vetor DO GERENCIADOR
        usuariosComuns.emplace_back(nome, senha, cpf);
        
        // DEBUG: Mostrar quem foi carregado
        std::cout << "[DEBUG] ... Usuario carregado: " << nome << std::endl;
    }
    
    // DEBUG: Mostrar o total
    std::cout << "[DEBUG] Carregamento concluido. Total de usuarios na memoria: " << usuariosComuns.size() << std::endl;
    
    in.close();

} // <--- ESTA É A CHAVE '}' QUE FALTAVA NA VERSÃO ANTERIOR!

void GerenciadorUsuariosComuns::salvarUsuariosComuns(const std::string& filename) const {
    // Modo padrão (sobrescrever), que agora está CORRETO
    std::ofstream out(filename); 
    
    if (!out.is_open()) {
        std::cout << "[DEBUG] ERRO: Nao foi possivel abrir " << filename << " para salvar!" << std::endl;
        return;
    }

    std::cout << "[DEBUG] Salvando " << usuariosComuns.size() << " usuarios no arquivo..." << std::endl;

    for (const auto& ucm : usuariosComuns) { // Itera sobre a lista do gerenciador
        out << ucm.getNome() << "|"
            << ucm.getSenha() << "|"
            << ucm.getCPF() << "\n";
    }
    
    out.close();
    std::cout << "[DEBUG] Salvamento concluido." << std::endl;
}
//Aqui compara se o NOME corresponde a algum outro já existente no documento .txt, impedindo que haja duplicação.
bool GerenciadorUsuariosComuns::nomeExiste(const std::string& nome) {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getNome() == nome) {
            return true;
        }
    }
    return false;
}
//Aqui compara se o CPF corresponde a algum outro já existente no documento .txt, impedindo que haja duplicação.
bool GerenciadorUsuariosComuns::cpfRepetido(const std::string& cpf) const {
    for (const auto& ucm : usuariosComuns) {
        if (ucm.getCPF() == cpf) {
            return true;
        }
    }
    return false;
}