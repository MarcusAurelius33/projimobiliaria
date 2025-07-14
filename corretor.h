#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor {
    private:
    int id;
    static int nextId;
    double lat;  
    double lng;  

    std::string nome;
    std::string telefone;
    bool avaliador;

    public:
    Corretor(const std::string& nome, const std::string& telefone, bool avaliador, double lat, double lng);
    
    // Getters
    int getId() const;
    std::string getNome() const;
    std::string getTelefone() const;
    bool isAvaliador() const;

    // Setters
    void setId(int id);
    void setNome(const std::string& nome);
    void setTelefone(const std::string& telefone);
    void setAvaliador(bool avaliador);
};
#endif
