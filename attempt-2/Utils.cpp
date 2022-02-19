#include <cstdlib>
#include "iostream"

using namespace std;

void clearConsole()
{
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void pause()
{
    cout << "\nPresione enter para continuar --";
    cin.ignore();
    cin.get();
}