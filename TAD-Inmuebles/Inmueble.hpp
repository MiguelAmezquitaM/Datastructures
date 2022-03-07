#ifndef Inmueble_hpp
#define Inmueble_hpp

#include <iostream>
using namespace std;

#define max_size 100

struct Direction
{
    string career;
    string street;
    string city;

    string to_string();
};

struct Property
{
    string id;
    Direction direction;
    string owner;
    int year;
    string type;
    float price;
};

class PropertiesList
{
private:

    Property list[max_size];

public:

    int length;

    void insert(Property property);

    void removeById(string id);

    int findById(string id);

    Property getByIndex(int index);

    PropertiesList();
};

#endif

