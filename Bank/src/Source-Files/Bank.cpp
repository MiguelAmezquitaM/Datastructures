#include "Bank.hpp"
#include <exception>
#include <iostream>

using std::cout;
using namespace bank;

Bank::Bank() : consignments(0), retirements(0) {
}

void Bank::insertByPriority(Client client) {
    Client lastClient;
    ClientQueue temp;
    bool inserted = false;

    while (!clientQueue.empty()) {
        temp.insert(clientQueue.get());
        clientQueue.pop();
    }

    while (!temp.empty()) {
        lastClient = temp.get();

        if (client.priority > lastClient.priority && !inserted) {
            clientQueue.insert(client);
            inserted = true;
        }

        clientQueue.insert(lastClient);
        temp.pop();
    }

    if (!inserted)
        clientQueue.insert(client);
}

void Bank::input(Client client) {
    insertByPriority(client);
}

void Bank::attend() {
    Client client;

    try {
        client = clientQueue.get();
    }
    catch (std::logic_error err) {
        cout << err.what() << "\n";
    }

    if (client.action == consignment)
        consignments += client.value;

    else if (client.action == retirement)
        retirements += client.value;

    clientQueue.pop();
}

Client Bank::nextClient() {
    return clientQueue.get();
}

void Bank::deleteById(int id) {
    ClientQueue temp;
    bool deleted = false;

    while (!clientQueue.empty() && clientQueue.get().id != id) {
        temp.insert(clientQueue.get());
        clientQueue.pop();
    }

    if(!clientQueue.empty()) {
        clientQueue.pop();
        deleted = true;
    }

    while (!temp.empty()) {
        clientQueue.insert(temp.get());
        temp.pop();
    }

    if(deleted) cout << "Eliminado correctamente\n";
    else cout << "NO existe un cliente con el id: " << id << "\n";
}

void Bank::print_queue() {
    clientQueue.print();
}

void Bank::print_balance() {
    cout << "Retiros: " << retirements << "\n";
    cout << "Consignaciones: " << consignments << "\n\n";
}