#include "Menu.cpp"

Computer *exampleList()
{
    Computer listOfComputers[10] = {{"Lenovo", "2017", 3.2, 8, 512, 10},
                                    {"HP", "2014", 2.2, 4, 256, 20},
                                    {"Compac", "2020", 2.6, 16, 256, 30},
                                    {"Lenovo", "2022", 3.8, 32, 1024, 40},
                                    {"Compac", "2013", 2.3, 4, 128, 50},
                                    {"HP", "2012", 2.1, 2, 128, 60},
                                    {"Compac", "2010", 1.8, 2, 128, 70},
                                    {"Lenovo", "2018", 3.1, 8, 512, 80},
                                    {"HP", "2020", 3.9, 16, 1024, 90},
                                    {"Lenovo", "2020", 3.9, 16, 1024, 90}};
    return listOfComputers;
}