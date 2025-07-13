#include "Corretor.h"
int Corretor::nextId = 1;
 
// Construtor
Corretor::Corretor(const std::string& nome, const std::string& telefone, bool avaliador)
    : id(nextId++), nome(nome), telefone(telefone), avaliador(avaliador) {}
// Getters
int Corretor::getId() const {
    return id;
}

std::string Corretor::getNome() const {
    return nome;
}

std::string Corretor::getTelefone() const {
    return telefone;
}

bool Corretor::isAvaliador() const {
    return avaliador;
}

// Setters
void Corretor::setId(int id) {
    this->id = id;
}

void Corretor::setNome(const std::string& nome) {
    this->nome = nome;
}

void Corretor::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}

void Corretor::setAvaliador(bool avaliador) {
    this->avaliador = avaliador;
}