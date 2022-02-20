#ifndef ComputerList_hpp
#define ComputerList_hpp

#include "Computer.hpp"

namespace pcl 
{
    struct ComputerList
    {
        // list
        pcp::Computer *list;

        // length of list (static)
        int len;

        // print list on console
        void print();

        // print item on console
        void print(int index);

        // sort list by differents properties
        void sortByTrademark(std::string mode);
        void sortByClockSpeed(std::string mode);
        void sortByMemoryCapacity(std::string mode);
        void sortByStorageCapacity(std::string mode);

        // get element by id (return index)
        int searchElementByID(int id);
    };
}

#include "ComputerList.cpp"
#endif