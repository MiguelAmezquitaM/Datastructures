#include "Menu.cpp"

Computer *exampleList()
{
    Computer *listOfComputers = new Computer[10];

    listOfComputers[0] = {"Lenovo", "2017", 3.2, 8, 512, 10};
    listOfComputers[1] = {"HP", "2014", 2.2, 4, 256, 20};
    listOfComputers[2] = {"Compac", "2020", 2.6, 16, 256, 30};
    listOfComputers[3] = {"Lenovo", "2022", 3.8, 32, 1024, 40};
    listOfComputers[4] = {"Compac", "2013", 2.3, 4, 128, 50};
    listOfComputers[5] = {"HP", "2012", 2.1, 2, 128, 60};
    listOfComputers[6] = {"Compac", "2010", 1.8, 2, 128, 70};
    listOfComputers[7] = {"Lenovo", "2018", 3.1, 8, 512, 80};
    listOfComputers[8] = {"HP", "2020", 3.9, 16, 1024, 90};
    listOfComputers[9] = {"Lenovo", "2020", 3.9, 16, 1024, 90};

    return listOfComputers;
}