#ifndef computer_hpp
#define computer_hpp

#include <iostream>

namespace pcp
{
    struct Computer
    {
        std::string trademark;
        std::string model;
        float clockSpeed;
        int memoryCapacity;
        int storageCapacity;
        int id;
    };
}

#endif