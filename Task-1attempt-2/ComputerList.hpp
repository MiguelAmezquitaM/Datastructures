#pragma once
#ifndef computerlist_hpp
#define computerlist_hpp

#include <iomanip>

#include "Computer.hpp"

#include "Services/Utility.hpp"
#include "Services/SortService.hpp"

namespace pcl 
{
    struct ComputerList
    {
        // list
        pcp::Computer list[100];

        // length of list (static)
        int len = 0;

        // print list on console
        void print();

        // print item on console
        void print(int index);

        // sort list by differents properties
        void sortByTrademark();
        void sortByClockSpeed();
        void sortByMemoryCapacity();
        void sortByStorageCapacity();

        // get element by id (return index)
        int searchElementByID(int id);
    };
}

#endif