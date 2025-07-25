#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

class Imovel {
    public:
    enum Tipo { Casa, Apartamento, Terreno };

    private:
    int id;
    static int nextId;
    
    Tipo tipo;
    int proprietarioId;
    double lat;
    double lng;
    std::string endereco;
    double preco;
    int idCorretorAvaliador;

    public:
    Imovel(Tipo tipo, int proprietarioId, double lat, double lng, std::string endereco, double preco);

    int getId() const;
    Tipo getTipo() const;
    int getProprietarioId() const;
    double getLat() const;
    double getLng() const;
    std::string getEndereco() const;
    double getPreco() const;
    int getIdCorretorAvaliador() const;

    // Setters
    void setId(int id);
    void setTipo(Tipo tipo);
    void setProprietarioId(int proprietarioId);
    void setLat(double lat);
    void setLng(double lng);
    void setEndereco(std::string endereco);
    void setPreco(double preco);
    void setIdCorretorAvaliador(int id);
};
#endif