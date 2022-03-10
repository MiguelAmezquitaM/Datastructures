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
        void deleteById(int id);
        void print_queue();
        void print_balance();
        Client nextClient();

        Bank();
    };

}