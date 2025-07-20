#include "imovel.h"

int Imovel::nextId=1;

// Construtor
Imovel::Imovel(Tipo tipo, int proprietarioId, double lat, double lng, std::string endereco, double preco)
    : id(nextId++), tipo(tipo), proprietarioId(proprietarioId), lat(lat), lng(lng), endereco(endereco), preco(preco), idCorretorAvaliador(-1) {}

// Getters
int Imovel::getId() const { return id; }
Imovel::Tipo Imovel::getTipo() const { return tipo; }
int Imovel::getProprietarioId() const { return proprietarioId; }
double Imovel::getLat() const { return lat; }
double Imovel::getLng() const { return lng; }
std::string Imovel::getEndereco() const { return endereco; }
double Imovel::getPreco() const { return preco; }
int Imovel::getIdCorretorAvaliador() const {return idCorretorAvaliador;}

// Setters
void Imovel::setId(int id) { this->id = id; }
void Imovel::setTipo(Tipo tipo) { this->tipo = tipo; }
void Imovel::setProprietarioId(int proprietarioId) { this->proprietarioId = proprietarioId; }
void Imovel::setLat(double lat) { this->lat = lat; }
void Imovel::setLng(double lng) { this->lng = lng; }
void Imovel::setEndereco(std::string endereco) { this->endereco = endereco; }
void Imovel::setPreco(double preco) { this->preco = preco; }
void Imovel::setIdCorretorAvaliador(int id) {this->idCorretorAvaliador = id;}
