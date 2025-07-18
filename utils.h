#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>
#include <string>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"

/**
 * @brief Calcula a distância em quilômetros entre duas coordenadas geográficas usando a fórmula de Haversine.
 * @param lat1 Latitude do ponto 1.
 * @param lon1 Longitude do ponto 1.
 * @param lat2 Latitude do ponto 2.
 * @param lon2 Longitude do ponto 2.
 * @return A distância em km.
 */
double haversine(double lat1, double lon1, double lat2, double lon2);

/**
 * @brief Lê os dados de corretores, clientes e imóveis da entrada padrão (cin)
 * e preenche os vetores fornecidos.
 * @param corretores Vetor de Corretores a ser preenchido (passado por referência).
 * @param clientes Vetor de Clientes a ser preenchido (passado por referência).
 * @param imoveis Vetor de Imóveis a ser preenchido (passado por referência).
 */
void lerEntrada(std::vector<Corretor>& corretores, std::vector<Cliente>& clientes, std::vector<Imovel>& imoveis);

void roundRobin (vector<Imovel>& imoveis, const vector<Corretor>& corretores);

// Agendamento
class Imovel;
class Corretor;

struct Agendamento {
    int imovelId;
    int corretorId;
    std::string horario;
};

std::string minutosParaHorario(int minutos);

std::vector<Agendamento> agendarVisitasPorVizinhoMaisProximo(
    std::vector<Imovel>& imoveis,
    const std::vector<Corretor>& corretores,
    const std::map<int, int>& imovelParaCorretor
);



#endif // UTILS_H
