#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "utils.h"
#include <iostream>
#include <algorithm>
using namespace std;

constexpr double EARTH_R = 6371.0; 

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void lerEntrada(std::vector<Corretor>& corretores, std::vector<Cliente>& clientes, std::vector<Imovel>& imoveis) {
    // --- LEITURA DOS CORRETORES ---
    int numCorretores;
    std::cin >> numCorretores;

    for (int i = 0; i < numCorretores; ++i) {
        std::string telefone, nome;
        bool avaliador_flag;
        double lat, lng;

        std::cin >> telefone >> avaliador_flag >> lat >> lng;

        std::getline(std::cin >> std::ws, nome);

        corretores.emplace_back(nome, telefone, avaliador_flag, lat, lng);
    }

    // --- LEITURA DOS CLIENTES ---
    int numClientes;
    std::cin >> numClientes;
    for (int i = 0; i < numClientes; ++i) {
        std::string telefone, nome;

        // Formato de entrada: [telefone] [nome]
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);

        // O construtor do Cliente está correto.
        clientes.emplace_back(nome, telefone);
    }

    // --- LEITURA DOS IMÓVEIS ---
    int numImoveis;
    std::cin >> numImoveis;
    for (int i = 0; i < numImoveis; ++i) {
        std::string tipo_str, endereco;
        int proprietarioId;
        double lat, lng, preco;

        std::cin >> tipo_str >> proprietarioId >> lat >> lng >> preco;
        std::getline(std::cin >> std::ws, endereco);

        // Converte a string lida para o tipo enumerado 'Imovel::Tipo'
        Imovel::Tipo tipo_enum;
        if (tipo_str == "Casa") {
            tipo_enum = Imovel::Tipo::Casa;
        } else if (tipo_str == "Apartamento") {
            tipo_enum = Imovel::Tipo::Apartamento;
        } else { // if (tipo_str == "Terreno")
            tipo_enum = Imovel::Tipo::Terreno;
        }
 
        imoveis.emplace_back(tipo_enum, proprietarioId, lat, lng, endereco, preco);
    }

    // --- DISTRIBUIR IMÓVEIS ---
    void roundRobin (vector<Imovel>& imoveis, const vector<Corretor>& corretores) {
        // Ordena imóveis por ID
        sort(imoveis.begin(), imoveis.end(), [](const Imovel& a, const Imovel& b) {
            return a.id < b.id;
        });
    
        // Filtra corretores avaliadores
        vector<Corretor> avaliadores;
        for (const auto& c : corretores) {
            if (c.avaliador)
                avaliadores.push_back(c);
        }
    
        // Atribui imóveis aos avaliadores de forma circular
        if (avaliadores.empty()) return;
    
        int idx = 0;
        for (auto& imovel : imoveis) {
            imovel.idCorretorAvaliador = avaliadores[idx].id;
            idx = (idx + 1) % avaliadores.size(); // volta ao início ao fim da lista
        }
    }
}
