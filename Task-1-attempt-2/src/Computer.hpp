#ifndef computer_hpp
#define computer_hpp

#include <iostream>

namespace pcp
{
    namespace pcf // Computer Fields
    {
        enum StringFields
        {
            trademark,
            model
        };

        enum FloatFields
        {
            clockSpeed
        };

        enum IntFields
        {
            memoryCapacity,
            storageCapacity,
            id
        };
    }

    struct Computer
    {
        std::string trademark;
        std::string model;
        float clockSpeed;
        int memoryCapacity;
        int storageCapacity;
        int id;

        std::string get(pcf::StringFields field);
        int get(pcf::IntFields field);
        float get(pcf::FloatFields field);
    };
}

#include "Computer.cpp"

#endif