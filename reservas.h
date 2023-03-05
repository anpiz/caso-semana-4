#ifndef RESERVAS_H
#define RESERVAS_H

#include <iostream>

typedef struct nodo_reservas* ptrnodor;

struct nodo_reservas {
    std::string cedula, nombre;
    bool espera;
    ptrnodor siguiente, anterior;

    nodo_reservas(const std::string, const std::string, bool);
};

class Reservas {
public:
    // Reservas();
    // Reservas(Reservas&);
    // ~Reservas();
    void ingresar(const std::string, const std::string, bool);
    void eliminar(unsigned int&);
    void imprimir();
    ptrnodor primero = NULL, ultimo = NULL, nuevo;
};

#endif // !RESERVAS_H
