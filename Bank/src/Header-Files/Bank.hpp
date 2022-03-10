#pragma once

#include "ClientQueue.hpp"

namespace bank {

    class Bank {
    private:
        ClientQueue clientQueue;
        int consignments;
        int retirements;

        void insertByPriority(Client);
        
    public:
        void input(Client);
        void attend();
        Client nextClient();
        void deleteById(int id);
        void print();

        Bank();
    };

}