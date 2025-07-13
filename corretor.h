#include <string>

class Corretor {
    private:
    int id;
    static int nextId;

    std::string nome;
    std::string telefone;
    bool avaliador;

    public:
    Corretor(const std::string& nome, const std::string& telefone, bool avaliador);
    
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