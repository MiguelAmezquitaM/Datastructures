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

    if (index < 0 or index >= len)
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
