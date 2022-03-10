#include "ClientQueue.hpp"
#include <iostream>

using std::cout;
using namespace bank;

ClientQueue::ClientQueue() : start(-1), end(-1) {
};

bool ClientQueue::empty() {
    return start == -1;
}

void ClientQueue::insert(Client cliente) {
    empty() && start++;

    queue[++end] = cliente;
}

void ClientQueue::pop() {
    if (!empty()) {
        if (start == end)
            start = end = -1;

        else
            start++;
    }
}

void ClientQueue::print() {
    if (!empty()) {
        for (int i = start; i <= end; i++) {
            cout << queue[i].name;
            i != end && cout << " <- ";
        }

        cout << "\n";
    }
}

Client ClientQueue::get() {
    if (!empty())
        return queue[start];

    throw std::logic_error("Error: la cola esta vacia.");
}


