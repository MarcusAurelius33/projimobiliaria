#include "cliente.h"

int Cliente::nextId = 1;

//Construtor
Cliente::Cliente(const std::string& nome, const std::string& telefone): id(nextId++), nome(nome), telefone(telefone) {}
// Getters
int Cliente::getId() const {
    return id;
}

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getTelefone() const {
    return telefone;
}

// Setters
void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setNome(const std::string& nome) {
    this->nome = nome;
}

void Cliente::setTelefone(const std::string& telefone) {
    this->telefone = telefone;
}