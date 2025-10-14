#include "../headers/sala.h"

// definição dos métodos
//id de sala
void Sala::setId(int id) {
    Id = id;
}
int Sala::getId(){
    return Id;
}
//tipo de sala
void Sala::setTipo(const std::string& tipo){
    Tipo = tipo;
}
std::string Sala::getTipo() const {
    return Tipo;
}


