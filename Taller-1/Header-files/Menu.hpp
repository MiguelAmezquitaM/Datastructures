#ifndef Menu_hpp
#define Menu_hpp

#include <iostream>
#include <string>

void get_int(int& n);

void get_int_interval(int& n, int min, int max);

void get_line(std::string& str);

template <typename T>
struct Choice {
    T value;
    std::string message;

    Choice(T value, std::string message)
        : value(value), message(message) {
    };
};

template <typename T>
struct Choices {
    std::string message;
    int length;
    Choice<T>* opciones;
};

void clear_console();

template <typename T>
T promptChoices(Choices<T> options) {
    clear_console();
    int choosedOption = -1;

    std::cout << options.message << "\n";

    for (int i = 0; i < options.length; i++) {
        std::cout << i + 1 << ". " << options.opciones[i].message << "\n";
    }

    while (0 >= choosedOption || choosedOption > options.length) {
        std::cout << "\n-> ";
        get_int(choosedOption);
    }

    return options.opciones[choosedOption - 1].value;
};




#endif