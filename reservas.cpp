#include "reservas.h"

nodo_reservas::nodo_reservas(const std::string c, const std::string n, bool e)
{
    cedula = c;
    nombre = n;
    espera = e;
    siguiente = anterior = NULL;
}

void Reservas::ingresar(const std::string c, const std::string n, bool e)
{
    nuevo = (ptrnodor) new nodo_reservas(c, n, e);

    if (primero == NULL)
        primero = ultimo = nuevo;
    else {
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

void Reservas::imprimir()
{
    if (primero == NULL) {
        std::cout << "\nEl vuelo todavía no tiene reservas añadidas.";
    } else {
        std::cout << "\nLISTA DE RESERVAS DEL VUELO:";

        for (ptrnodor it = primero; it != NULL; it = it->siguiente) {
            std::cout << "\nCédula: " << it->cedula
                      << "\nNombre: " << it->nombre
                      << "\nLista de espera:" << (it->espera ? "sí" : "no")
                      << "\n";
        }
    }
}
