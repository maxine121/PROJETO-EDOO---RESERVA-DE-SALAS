#include <iostream>
#include "headers/sala.h"
int main() {
    Sala lab1(1, "laboratorio");
    std::cout << "id: " << lab1.getId() << std::endl;
    std::cout << "Tipo: " << lab1.getTipo() << std::endl;
    return 0;
}