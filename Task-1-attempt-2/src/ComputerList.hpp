#ifndef ComputerList_hpp
#define ComputerList_hpp

#include "Computer.hpp"

namespace pcl
{
    enum Mode { smallesto, biggesto };

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
        template<typename T>
        void sortByField(T field, Mode mode);

        // get element by id (return index)
        int searchElementByID(int id);
    };
}

#include "ComputerList.cpp"
#endif