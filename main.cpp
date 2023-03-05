#include "vuelos.h"
#include <vector>

char opcion;
Vuelos lista_vuelos;

void opciones(std::vector<std::string>);
void vuelos();
void modificar_vuelos();
void cupos();
void reservas();
void continuar();
void ingresar_vuelos();
void ingresar_reservas();

// Mostrar el título del menú y sus opciones más cómodamente.
void opciones(std::vector<std::string> s)
{
    unsigned int i = 1;
    auto it = s.cbegin();

    std::cout << "\nMENÚ " << *(it++);

    for (; it != s.cend(); ++it, ++i) {
        std::cout << "\n" << i << ". " << *it << ".";
    }

    std::cout << "\n"
              << i << ". Cerrar."
              << "\nInserte opción: ";
    std::cin >> opcion;
}

void principal()
{
    do {
        opciones({ "PRINCIPAL", "Vuelos", "Reservas" });

        switch (opcion) {
            case '1':
                vuelos();
                break;
            case '2':
                ingresar_reservas();
                break;
            case '3':
                std::cout << "\nCerrando." << std::endl;
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void vuelos()
{
    do {
        opciones({ "VUELOS", "Entrar vuelos", "Modificar existentes",
                "Listar vuelos" });

        switch (opcion) {
            case '1':
                ingresar_vuelos();
                break;
            case '2':
                modificar_vuelos();
                break;
            case '3':
                lista_vuelos.listar_vuelos();
                break;
            case '4':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '4');
}

void modificar_vuelos()
{
    do {
        opciones({ "MODIFICAR VUELOS", "Cupo", "Estado del vuelo" });

        switch (opcion) {
            case '1':
                cupos();
                break;
            case '2':
                lista_vuelos.modificar_estado();
                break;
            case '3':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void cupos()
{
    do {
        opciones({ "CUPOS", "Quitar cupos", "Aumentar cupos" });

        switch (opcion) {
            case '1':
                lista_vuelos.modificar_cupos('q');
                break;
            case '2':
                lista_vuelos.modificar_cupos('a');
                break;
            case '3':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void continuar()
{
    do {
        std::cout << "\n¿Desea continuar? (s/n): ";
        std::cin >> opcion;
    } while (opcion != 's' && opcion != 'n');
}

void ingresar_vuelos()
{
    do {
        lista_vuelos.ingresar_vuelo();
        continuar();
    } while (opcion == 's');
}

void ingresar_reservas()
{
    do {
        lista_vuelos.ingresar_reserva();
        continuar();
    } while (opcion == 's');
}

int main()
{
    principal();

    return 0;
}
