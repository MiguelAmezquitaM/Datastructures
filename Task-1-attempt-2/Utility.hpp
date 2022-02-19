#pragma once

#ifndef utility_hpp
#define utility_hpp

#include <iostream>

namespace utl
{
    // clear console duh
    void clearConsole();

    // pause the ejecution
    void pause();

    // exchange
    template<typename T>
    void exchange(T* e1, T* e2);
}

#include "Utility.cpp"

#endif