#include <iostream>
#include <vector>
#include <algorithm> 
#include "utils.h"   

void ordenarAgenda(std::vector<Agendamento>& agenda) {
    std::sort(agenda.begin(), agenda.end(), [](const Agendamento& a, const Agendamento& b) {
        if (a.corretorId != b.corretorId) {
            return a.corretorId < b.corretorId;
        }
        // Compara horários como strings, que funciona para o formato "HH:MM"
        return a.horario < b.horario;
    });
}

int main() {
    //Cria os vetores para armazenar os objetos
    std::vector<Corretor> corretores;
    std::vector<Cliente> clientes;
    std::vector<Imovel> imoveis;
    
    //Chama a função para ler os dados e preencher os vetores
    lerEntrada(corretores, clientes, imoveis);
    
    //Distribui os imóveis entre os corretores avaliadores
    roundRobin(imoveis, corretores);

    //Gera a agenda de visitas usando o algoritmo do vizinho mais próximo
    std::vector<Agendamento> agendaFinal = agendarVisitasPorVizinhoMaisProximo(imoveis, corretores);
    
    //Ordena a agenda final por corretor e depois por horário
    ordenarAgenda(agendaFinal);

    //Percorre a agenda retornada e imprima os resultados
    int corretorIdAtual = -1; 
    for (const auto& agendamento : agendaFinal) {
        if (agendamento.corretorId != corretorIdAtual) {
            if (corretorIdAtual != -1) {
                std::cout << std::endl;
            }
            corretorIdAtual = agendamento.corretorId;
            std::cout << "Corretor " << corretorIdAtual << std::endl;
        }
        std::cout << agendamento.horario << " Imóvel " << agendamento.imovelId << std::endl;
    }

    return 0;
}
