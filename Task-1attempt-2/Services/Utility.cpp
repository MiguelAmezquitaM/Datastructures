#include "Utility.hpp"

using namespace utl;

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
    std::cout << "\n\nPress any key to continue...\n";
    std::cin.ignore();
    std::cin.get();
}
