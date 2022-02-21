#include "Computer.hpp"

std::string pcp::Computer::get(pcf::StringFields field)
{
    if (field == pcf::trademark)
        return this->trademark;
    else
        return this->model;
}

int pcp::Computer::get(pcf::IntFields field)
{
    if (field == pcf::memoryCapacity)
        return this->memoryCapacity;
    else if (field == pcf::storageCapacity)
        return this->storageCapacity;
    else
        return this->id;
}

float pcp::Computer::get(pcf::FloatFields field)
{
    return this->clockSpeed;
}
