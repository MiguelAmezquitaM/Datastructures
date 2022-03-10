
#ifndef Menu_hpp
#define Menu_hpp

#include "Question.hpp"
#include "Choices.hpp"
#include <iostream>

namespace menu {

    void get_int(int&);

    void get_float(float&);

    void get_string(std::string& str);

    void prompt(std::string, std::string&);
    void prompt(std::string, int&);
    void prompt(std::string, float&);

    template<typename T>
    T promptChoices(Choices<T> c);

    void clear_console();

    void pause();
}

template<typename T>
T menu::promptChoices(Choices<T> c) {
    int opc;

    std::cout << c.message << "\n\n";

    for (int i = 0; i < c.choices.size(); i++) {
        std::cout << i + 1 << ". " << c.choices[i].message << "\n";
    }

    std::cout << "\nTu opcion: ";
    get_int(opc);

    return c.choices[opc - 1].value;
}




#endif


