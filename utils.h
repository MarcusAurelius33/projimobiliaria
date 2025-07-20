#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <map>
#include <string>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"

double haversine(double lat1, double lon1, double lat2, double lon2);

void lerEntrada(std::vector<Corretor>& corretores, std::vector<Cliente>& clientes, std::vector<Imovel>& imoveis);

void roundRobin (std::vector<Imovel>& imoveis, const std::vector<Corretor>& corretores);
// Agendamento
class Imovel;
class Corretor;

struct Agendamento {
    int imovelId;
    int corretorId;
    std::string horario;
};

std::vector<Agendamento> agendarVisitasPorVizinhoMaisProximo(
    std::vector<Imovel>& imoveis,
    const std::vector<Corretor>& corretores
);
#endif 
