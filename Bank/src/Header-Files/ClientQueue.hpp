
#pragma once

#include "Client.hpp"

namespace bank {
    static const int LIMIT_QUEUE_LENGTH = 100;

    class ClientQueue {
        Client queue[LIMIT_QUEUE_LENGTH];
        int start;
        int end;

    public:
        void pop();
        void insert(Client);
        bool empty();
        void print();
        Client get();

        ClientQueue();
    };
}