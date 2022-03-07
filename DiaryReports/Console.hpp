#ifndef Console_h
#define Console_h

#include <iostream>

class Console {
public:
    void clear() const;
    void pause() const;
    void get_string(std::string&) const;
    void get_int(int&) const;
    void get_float(float&) const;
    void print(std::string) const;
    void separatew(int) const;
};

#define console Console()

#endif