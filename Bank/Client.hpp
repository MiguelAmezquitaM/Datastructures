#pragma once

#include <string>

enum Action : int
{
    retirement,
    consignment
};

enum Priority : int
{
    normal,
    priviliged
};

struct Client
{
    // datos del usuario
    int id;
    std::string name;
    Priority priority;
    Action type;
    int value;
};

class ClientQueue
{
    Client queue[100];
    int start = -1;
    int end = -1;

public:
    void pop();
    void insert(Client);
    bool empty();
    void print();
    Client get();
};
