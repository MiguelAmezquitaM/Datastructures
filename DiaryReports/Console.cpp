#include "Console.hpp"
#include <limits>
#include <exception>

using std::cin;
using std::cout;
using std::getline;
using std::string;

void Console::clear() const
{
#if WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void Console::get_string(string &str) const
{
    getline(cin, str, '\n');
}

void Console::pause() const
{
    cout << "Presione una tecla para continuar...";
    cin.get();
}

void Console::print(string str) const
{
    cout << str;
}

void Console::get_int(int &n) const
{
    string str;
    int num;
    bool passed = false;

    while (!passed)
    {
        passed = true;
        getline(cin, str, '\n');

        try
        {
            num = std::stoi(str);
        }
        catch (std::exception)
        {
            passed = false;
            Console::print("Entrada invalida\n");
            Console::print("Intentalo de nuevo: ");
        }
    }

    n = num;
}

void Console::get_float(float &n) const
{
    cin >> n;
    cin.ignore(std::numeric_limits<int>::max(), '\n');
}
