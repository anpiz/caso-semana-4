#ifndef VUELOS_H
#define VUELOS_H

#include "reservas.h"

typedef struct nodo_vuelo* ptrnodov;

struct nodo_vuelo {
    std::string codigo, ciudad;
    int cupos;
    unsigned int estado;
    ptrnodov siguiente, anterior;
    Reservas reservas;

    nodo_vuelo(const std::string&, const std::string&, int, unsigned int);
};

class Vuelos {
public:
    // Vuelos();
    // Vuelos(Vuelos&);
    // ~Vuelos();
    void ingresar_vuelo();
    void ingresar_reserva();
    void listar_vuelos();
    void modificar_cupos(char);
    void modificar_estado();

private:
    unsigned int pedir_estado();
    ptrnodov pedir_vuelo();
    ptrnodov buscar_vuelo(const std::string& c);
    ptrnodov primero = NULL, ultimo = NULL, nuevo;
};

#endif // !VUELOS_H
