#pragma once

#include "ComputerList.hpp"

using namespace std;

using namespace pcp; // Computer namespace
using namespace pcl; // Computer list namespace
using namespace utl; // Utils namespace

// row spacing
#define spc setw(20)

// helpers function related to print()
void print_header_computer();
void print_row_computer(Computer pc);

void ComputerList::print()
{
    clearConsole();
    print_header_computer();

    for (int i = 0; i < len; i++)
        print_row_computer(list[i]);

    pause();
}

void ComputerList::print(int index)
{
    clearConsole();

    if (index < 0 || index >= len)
        cout << "Index out of range\n";
    else
    {
        print_header_computer();
        print_row_computer(list[index]);
    }

    pause();
}

void print_header_computer()
{
    cout << "ID" << spc << "Trademarker" << spc << "Model" << spc
         << "Memory Capacity" << spc << "Storage Capacity" << spc
         << "Clock speed" << endl
         << endl;
}

void print_row_computer(Computer pc)
{
    cout << pc.id << spc << pc.trademark << spc << pc.model << spc
         << pc.memoryCapacity << spc << pc.storageCapacity << spc
         << pc.clockSpeed << endl;
}

// _____________________________________________ print functions

int ComputerList::searchElementByID(int id)
{
    for(int i = 0; i < len; i++)
        if(list[i].id == id)
            return i;
    
    return -1;
}

void ComputerList::sortByClockSpeed(string mode)
{
    int i, j;
    float p1, p2;

    for (i = 0; i < len - 1; i++)
    {
        j = i + 1;
        p1 = list[i].clockSpeed;
        p2 = list[j].clockSpeed;

        while(mode == "a" ? p1 > p2 : p2 > p1)
        {
            exchange(&list[i--], &list[j--]);
            p1 = list[i].clockSpeed;
            p2 = list[j].clockSpeed;
        }
    }
}

void ComputerList::sortByMemoryCapacity(string mode)
{
    int i, j;
    int p1, p2;

    for (i = 0; i < len - 1; i++)
    {
        j = i + 1;
        p1 = list[i].memoryCapacity;
        p2 = list[j].memoryCapacity;

        while(mode == "a" ? p1 > p2 : p2 > p1)
        {
            exchange(&list[i--], &list[j--]);
            p1 = list[i].memoryCapacity;
            p2 = list[j].memoryCapacity;
        }
    }
}

void ComputerList::sortByStorageCapacity(string mode)
{
    int i, j;
    int p1, p2;

    for (i = 0; i < len - 1; i++)
    {
        j = i + 1;
        p1 = list[i].storageCapacity;
        p2 = list[j].storageCapacity;

        while(mode == "a" ? p1 > p2 : p2 > p1)
        {
            exchange(&list[i--], &list[j--]);
            p1 = list[i].storageCapacity;
            p2 = list[j].storageCapacity;
        }
    }
}

void ComputerList::sortByTrademark(string mode)
{
    int i, j;
    string p1, p2;

    for (i = 0; i < len - 1; i++)
    {
        j = i + 1;
        p1 = list[i].trademark;
        p2 = list[j].trademark;

        while(mode == "a" ? p1 > p2 : p2 > p1)
        {
            exchange(&list[i--], &list[j--]);
            p1 = list[i].trademark;
            p2 = list[j].trademark;
        }
    }
}

