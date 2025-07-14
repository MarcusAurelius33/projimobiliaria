#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
    private:
    int id;
    static int nextId;

    std::string nome;
    std::string telefone;

    public:
    Cliente(const std::string& nome, const std::string& telefone);
    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getTelefone() const;

    // Setters
    void setId(int id);
    void setNome(const std::string& nome);
    void setTelefone(const std::string& telefone);
};
#endif
