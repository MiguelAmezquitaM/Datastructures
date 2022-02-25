#include "Inmueble.hpp"

string Direction::to_string()
{
    return career + " " + street + " " + city;
}

void PropertiesList::insert(Property property)
{
    if(length > max_size)
        throw "Index out of range";

    list[length++] = property;
}

int PropertiesList::findById(string id)
{
    for(int i = 0; i < length; i++)
        if(id == list[i].id)
            return i;
    
    return -1;
}

void PropertiesList::removeById(string id) 
{
    int index = findById(id);

    if(index != -1)
        throw "Don't exist property";

    for(int i = index;  i < length; i++)
        list[i] = list[i + 1];
    
    length--;
}

Property PropertiesList::getByIndex(int index)
{
    if(index >= length || index < 0)
        throw "Index out of range";

    return list[index];
}

PropertiesList::PropertiesList()
{
    length = 0;
}