#include <iomanip>

#include "ComputerList.hpp"
#include "Utility.hpp"

using namespace std;

using namespace pcp; // Computer namespace
using namespace pcl; // Computer list namespace
using namespace utl; // Utils namespace

// row spacing
#define spc setw(20)

// helpers function related to print()
static void print_header_computer();
static void print_row_computer(Computer pc); // static: isn't avaible outside of module

void ComputerList::print()
{
    clearConsole();

    if (len == 0)
        cout << "List is empty!\n";
    else
    {
        print_header_computer();

        for (int i = 0; i < len; i++)
            print_row_computer(list[i]);
    }
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

static void print_header_computer()
{
    cout << setw(10) << "ID" << spc << "Trademarker" << spc << "Model" << spc
         << "Memory Capacity" << spc << "Storage Capacity" << spc
         << "Clock speed" << endl
         << endl;
}

static void print_row_computer(Computer pc)
{
    cout << setw(10) << pc.id << spc << pc.trademark << spc << pc.model << spc
         << pc.memoryCapacity << spc << pc.storageCapacity << spc
         << pc.clockSpeed << endl;
}

// _____________________________________________ print functions

int ComputerList::searchElementByID(int id)
{
    for (int i = 0; i < len; i++)
        if (list[i].id == id)
            return i;

    return -1;
}

template <typename T>
void ComputerList::sortByField(T field, Mode mode)
{
    int i = 0, j = 0;

    for (i = 0; i < len - 1; i++)
    {
        j = i + 1;
        while (i >= 0 && (mode == smallesto
                    ? list[i].get(field) > list[j].get(field)
                    : list[j].get(field) > list[i].get(field)))

            exchange(&list[i--], &list[j--]);
    }
}
