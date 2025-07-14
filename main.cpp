#include <iostream>
#include <vector>
#include "utils.h"

int main() {
    // 1. Crie os vetores para armazenar os objetos
    std::vector<Corretor> corretores;
    std::vector<Cliente> clientes;
    std::vector<Imovel> imoveis;
    
    lerEntrada(corretores, clientes, imoveis);
    
    // Exemplo de verificação:
    // std::cout << "Foram lidos " << corretores.size() << " corretores." << std::endl;
    // std::cout << "Foram lidos " << imoveis.size() << " imoveis." << std::endl;

    return 0;
}
