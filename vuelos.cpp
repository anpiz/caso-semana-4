#include "vuelos.h"

nodo_vuelo::nodo_vuelo(const std::string& c, const std::string& ciu, int cup, unsigned int e) {
    codigo = c;
    ciudad = ciu;
    cupos = cup;
    estado = e;
    siguiente = anterior = NULL;
}

void Vuelos::ingresar_vuelo() {
    std::string codigo, ciudad;
    int cupos;

    std::cout << "\nInserte el código del vuelo: ";
    std::cin >> codigo;

    while (buscar_vuelo(codigo) != NULL) {
        std::cout << "\nEl vuelo ya existe, inserte un código válido: ";
        std::cin >> codigo;
    }

    std::cout << "\nInserte la ciudad destino: ";
    std::cin >> ciudad;

    std::cout << "\nInserte el número de cupos: ";
    std::cin >> cupos;

    while (cupos < 0) {
        std::cout << "\nInserte un número de cupos válido: ";
        std::cin >> cupos;
    }

    unsigned int estado = pedir_estado();

    nuevo = (ptrnodov) new nodo_vuelo(codigo, ciudad, cupos, estado);

    if (primero == NULL)
        primero = ultimo = nuevo;
    else {
        nuevo->anterior = ultimo;
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
}

ptrnodov Vuelos::buscar_vuelo(const std::string& c) {
    ptrnodov it = primero;
    for (; it != NULL && it->codigo != c; it = it->siguiente);
    return it;
}

void Vuelos::listar_vuelos() {
    std::cout << "\n*** LISTA DE VUELOS ***";
    for (ptrnodov it = primero; it != NULL; it = it->siguiente) {
        std::cout << "\n\nCódigo: " << it->codigo
            << "\nCiudad destino: " << it->ciudad
            << "\nCupos disponibles: " << it->cupos
            << "\nEstado del vuelo: " << (it->estado == true ? 1 : 0)
            << "\n";
        it->reservas.imprimir();
    }
}

void Vuelos::ingresar_reserva() {
    std::string cedula, nombre;

    std::cout << "\nIngrese la cédula del pasajero: ";
    std::cin >> cedula;

    std::cout << "\nIngrese el nombre del pasajero: ";
    std::cin >> nombre;

    ptrnodov it = pedir_vuelo();
    bool espera = (it->cupos > 0 && it->estado == 1 ? false : true);

    it->reservas.ingresar(cedula, nombre, espera);
    
    if (!espera)
        --it->cupos;

    std::cout << (espera ? "En lista de espera." : "Cupo reservado.");
}

ptrnodov Vuelos::pedir_vuelo() {
    std::string codigo;

    std::cout << "\nInserte el código del vuelo: ";
    std::cin >> codigo;

    ptrnodov it = buscar_vuelo(codigo);

    while (it == NULL) {
        std::cout << "\nVuelo no encontrado, vuelva a intentar.";
        std::cin >> codigo;
        it = buscar_vuelo(codigo);
    }

    return it;
}

void Vuelos::modificar_cupos(char o) {
    unsigned int count;
    ptrnodov ptr = pedir_vuelo();

    std::cout << "\nInserte la cantidad de cupos " << (o == 'a' ? "adicionales" : "a restar") << ".";
    std::cin >> count;

    while (count < 0) {
        std::cout << "\nInserte una cantidad válida: ";
        std::cin >> count;
    }

    if (count == 0) {
        std::cout << "\nNo se modificó la cantidad de cupos.";
        return;
    }
    
    if (o == 'a') {
        ptr->cupos += count;
        ptrnodor it = ptr->reservas.primero;

        if (it != NULL && ptr->estado == 1 && ptr->reservas.ultimo->espera)
            for (; ptr->cupos != 0 && it != NULL; it = it->siguiente)
                if (it->espera) {
                    it->espera = false;
                    --(ptr->cupos);
                }
    } else if (o == 'q') {
        ptr->cupos -= count;
        ptrnodor it = ptr->reservas.ultimo;

        if (it != NULL && ptr->estado == 1)
            for (; ptr->cupos != 0; it = it->anterior)
                if (!(it->espera)) {
                    it->espera = true;
                    ++(ptr->cupos);
                }
    }

    std::cout << "\nCupos modificados y lista de espera actualizada.";
}

unsigned int Vuelos::pedir_estado() {
    unsigned int estado;

    std::cout << "\nInserte el estado del vuelo (1 Activo/0 Cancelado): ";
    std::cin >> estado;

    while (estado != 1 && estado != 0) {
        std::cout << "\nInserte un estado válido (1 Activo/0 Cancelado): ";
        std::cin >> estado;
    }

    return estado;
}

void Vuelos::modificar_estado() {
    ptrnodov ptr = pedir_vuelo();
    unsigned int estado = pedir_estado();

    if (ptr->estado == estado) {
        std::cout << "\nEl estado del vuelo sigue siendo el mismo.";
        return;
    }
    
    ptrnodor it = ptr->reservas.primero;

    if (it != NULL) {
        if (ptr->estado == 1) {
            for (; it != NULL && !(it->espera); it = it->siguiente) {
                it->espera = true;
                ++(ptr->cupos);
            }
        } else {
            for (; it != NULL && ptr->cupos != 0; it = it->siguiente) {
                it->espera = false;
                --(ptr->cupos);
            }
        }
    }

    ptr->estado = estado;
}
