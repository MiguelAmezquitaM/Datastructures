#include "Report.h"

void modifyReport(StackReports *stack, int red, std::string title, std::string desc);
void inputString(std::string message, std::string &s);
void inputReport(Report &r);
void clearConsole();
void pause();

int main()
{
    StackReports stackReports;
    Report tempReport;
    int opc;
    int ref;

    std::string newtitle;
    std::string newdesc;

    do
    {
        clearConsole();
        std::cout << "================================\n";
        std::cout << "      Seleccione una opcion\n";
        std::cout << "================================\n\n";

        std::cout << "1. Agregar noticia\n";
        std::cout << "2. Listar noticias\n";
        std::cout << "3. Modificar\n";
        std::cout << "4. Salir\n";

        std::cout << "\nSeleccion: ";
        std::cin >> opc;

        switch (opc)
        {
        case 1:
            clearConsole();
            inputReport(tempReport);
            stackReports.append(tempReport);
            break;

        case 2:
            clearConsole();
            stackReports.print();
            pause();
            break;

        case 3:
            clearConsole();
            std::cout << "Ingrese la referencia de la noticia: ";
            std::cin >> ref;
            std::cout << &stackReports << std::endl;
            inputString("Nuevo titulo: ", newtitle);
            inputString("Nueva descripcion: ", newdesc);
            modifyReport(&stackReports, ref, newtitle, newdesc);
            pause();
            break;

        case 4:
            std::cout << "Bye!\n";
            break;
        default:
            break;
        }

    } while (opc != 4);

    std::cin.get();
    return 0;
}

void clearConsole()
{

#ifdef __WIN64
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
    std::cout << "Pulse una tecla para continuar... ";
    std::cin.ignore();
    std::cin.get();
}

void inputString(std::string message, std::string &s)
{
    std::cout << message;
    std::cin.ignore();
    std::getline(std::cin, s, '\n');
}

void inputReport(Report &r)
{
    std::cout << "Referencia: ";
    std::cin >> r.ref;
    inputString("Titulo: ", r.title);
    inputString("Descripcion: ", r.description);
    inputString("Tipo: ", r.type);
}

void modifyReport(StackReports *stack, int ref, std::string title, std::string desc)
{
    StackReports aux;

    while (stack->get_last_report().ref != ref)
    {
        aux.append(stack->get_last_report());
        stack->delete_last();
    }

    std::cout << &stack << std::endl;
    stack->get_last_report().title = title;
    stack->get_last_report().description = desc;

    while (!aux.empty())
    {
        stack->append(aux.get_last_report());
        aux.delete_last();
    }
}
