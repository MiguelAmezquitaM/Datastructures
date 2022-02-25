#include "Inmueble.hpp"
#include <iomanip>

void print_property(Property p, _Setw sep)
{
    cout << setw(10) << p.id << sep << p.owner << sep << p.year << sep << p.type << sep << p.price << sep << sep
         << p.direction.to_string() << endl;
}

void print_property_list(PropertiesList list)
{
    Property temp;
    _Setw sep = std::setw(10);

    cout << setw(10) << "ID" << sep << "Owner" << sep << "Year" << sep << "Type" << sep << "Price" << sep << sep
         << "Direction" << endl << endl;

    for (int i = 0; i < list.length; i++)
    {
        temp = list.getByIndex(i);
        print_property(temp, sep);
    }
}

void insertByConsole(PropertiesList l, int howmany)
{
    for(int i = 0; i < howmany; i++)
    {
    
    }
}

int main(int argc, char const *argv[])
{
    PropertiesList list;

    Property p1 = {"4FS3", {"2a", "19", "Santa Marta"}, "Juan", 2018, "house", 2.4};
    Property p2 = {"4FS4", {"2a", "19", "Santa Marta"}, "Juan", 2018, "terrain", 3.4};
    Property p3 = {"4FS5", {"2a", "19", "Santa Marta"}, "Juan", 2018, "house", 2.4};
    Property p4 = {"4FS6", {"2a", "19", "Santa Marta"}, "Juan", 2018, "terrain", 2.4};

    list.insert(p1);
    list.insert(p2);
    list.insert(p3);
    list.insert(p4);

    print_property_list(list);

    return 0;
}
