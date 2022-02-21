#pragma once

#include "Utility.hpp"

#include <iostream>

void utl::clearConsole()
{
#ifdef WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void utl::pause()
{
    std::cout << "\n\nPress any key to continue...\n";
    std::cin.ignore();
    std::cin.get();
}

template <typename T>
void utl::exchange(T *e1, T *e2)
{
    try
    {
        T temp = *e1;
        *e1 = *e2;
        *e2 = temp;
    }
    catch(std::exception err)
    {
        std::cout << err.what() << std::endl;
    }
}
