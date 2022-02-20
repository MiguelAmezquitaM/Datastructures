#include <iostream>

#include "Menu.hpp"
#include "ComputerList.hpp"

using namespace menu;
using namespace pcl;
using namespace std;

int main(int argc, char const *argv[])
{
    ComputerList *listOfComputers = new ComputerList();

    // data
    Computer list[100] = {
        {"Lenovo" , "A2018", 2.3, 4 , 512 , 1},
        {"HP"     , "2019" , 3.2, 8 , 1024, 2},
        {"Apple"  , "B180" , 3.3, 16, 256 , 3},
        {"Compac" , "M230" , 4.3, 8 , 512 , 4},
        {"Asus"   , "2019" , 5  , 8 , 512 , 5},
        {"Lenovo" , "F645" , 3.8, 16, 1024, 6},
        {"DELL"   , "34F2" , 4.3, 32, 2048, 7},
        {"Lenovo" , "U300" , 5  , 4 , 1024, 8},
        {"HP"     , "4500F", 2.9, 4 , 512 , 9},
        {"Apple"  , "1800" , 3.4, 16, 256 , 10},
        {"Huaweii", "6541" , 3.9, 16, 128 , 11},
    };

    listOfComputers->list = list;
    listOfComputers->len = 11;

    main_menu(listOfComputers);

    delete listOfComputers;
    delete &list;

    return 0;
}
