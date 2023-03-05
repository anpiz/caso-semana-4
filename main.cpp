#include "vuelos.h"
#include <vector>

char opcion;
Vuelos vuelos;

void menu_opciones(std::vector<std::string>);
void menu_vuelos();
void menu_modificar_vuelos();
void menu_cupos();
void menu_reservas();
void menu_continuar();
void menu_ingresar_vuelos();
void menu_ingresar_reservas();

// Mostrar el título del menú y sus opciones más cómodamente.
void menu_opciones(std::vector<std::string> s)
{
    unsigned int i = 1;
    auto it = s.cbegin();
    std::cout << "\nMENÚ " << *(it++);
    for (; it != s.cend(); ++it, ++i)
        std::cout << "\n" << i << ". " << *it << ".";
    std::cout << "\n" << i << ". Cerrar."
              << "\nInserte opción: ";
    std::cin >> opcion;
}

void principal()
{
    do {
        menu_opciones({ "PRINCIPAL", "Vuelos", "Reservas" });

        switch (opcion) {
            case '1':
                menu_vuelos();
                break;
            case '2':
                menu_ingresar_reservas();
                break;
            case '3':
                std::cout << "\nCerrando." << std::endl;
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void menu_vuelos()
{
    do {
        menu_opciones({ "VUELOS", "Entrar vuelos", "Modificar existentes",
                "Listar vuelos" });

        switch (opcion) {
            case '1':
                menu_ingresar_vuelos();
                break;
            case '2':
                menu_modificar_vuelos();
                break;
            case '3':
                vuelos.listar_vuelos();
                break;
            case '4':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '4');
}

void menu_modificar_vuelos()
{
    do {
        menu_opciones({ "MODIFICAR VUELOS", "Cupo", "Estado del vuelo" });

        switch (opcion) {
            case '1':
                menu_cupos();
                break;
            case '2':
                vuelos.modificar_estado();
                break;
            case '3':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void menu_cupos()
{
    do {
        menu_opciones({ "CUPOS", "Quitar cupos", "Aumentar cupos" });

        switch (opcion) {
            case '1':
                vuelos.modificar_cupos('q');
                break;
            case '2':
                vuelos.modificar_cupos('a');
                break;
            case '3':
                std::cout << "\nVolviendo al menú anterior.";
                break;
            default:
                std::cout << "\nInserte una opción válida.";
        }
    } while (opcion != '3');
}

void menu_continuar()
{
    do {
        std::cout << "\n¿Desea continuar? (s/n): ";
        std::cin >> opcion;
    } while (opcion != 's' && opcion != 'n');
}

void menu_ingresar_vuelos()
{
    do {
        vuelos.ingresar_vuelo();
        menu_continuar();
    } while (opcion == 's');
}

void menu_ingresar_reservas()
{
    do {
        vuelos.ingresar_reserva();
        menu_continuar();
    } while (opcion == 's');
}

int main()
{
    principal();
    return 0;
}
