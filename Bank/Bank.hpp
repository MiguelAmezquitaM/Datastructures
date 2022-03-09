#pragma once
#include "Client.hpp"

class Bank
{
    ClientQueue clientQueue;
    int consignments;
    int retirements;

public:
    void input(Client);
    void attend();
    Client nextClient();
    void deleteById(int id);
    void print();

    Bank();
};
