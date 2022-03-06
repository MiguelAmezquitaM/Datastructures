#ifndef Console_h
#define Console_h

#include <iostream>

class Console
{
public:
    void clear() const;
    void get_string(std::string &) const;
    void get_int(int &) const;
    void get_float(float &) const;
    void pause() const;
    void print(std::string) const;
};

#endif