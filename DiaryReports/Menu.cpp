#include "Menu.hpp"

using std::cin;
using std::cout;

void Menu::get_option(int &opc) const
{
    console.get_int(opc);
}

void Menu::print_header() const
{
    cout << "================================\n";
    cout << "      Seleccione una opcion\n";
    cout << "================================\n";
}

void Menu::print_menu_options() const
{
    cout << "1. Agregar noticia\n";
    cout << "2. Listar noticias\n";
    cout << "3. Modificar\n";
    cout << "4. Salir\n";
}

void Menu::handle_option(int &opc)
{
    switch (opc)
    {
    case agregar_noticia:
        console.clear();
        diaryReports.insert_report();
        break;
    case listar_noticias:
        console.clear();
        diaryReports.print_reports();
        console.pause();
        break;
    case modificar_noticia:
        console.clear();
        diaryReports.modify_report();
        break;
    default:
        break;
    }
}

void Menu::run()
{
    int opc;
    do
    {
        console.clear();

        print_header();

        print_menu_options();

        console.print("\nSeleccion: ");
        get_option(opc);

        handle_option(opc);

    } while (opc != exit_menu);
}
