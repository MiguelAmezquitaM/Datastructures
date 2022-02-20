#ifndef Menu_hpp
#define Menu_hpp

#include "ComputerList.hpp"

namespace menu
{
    void main_menu(pcl::ComputerList *listOfComputers);
    int main_menu_body();
    int fillComputerList(pcl::ComputerList *list);
    void searchComputerById(pcl::ComputerList *list);
    void print_header();
    
} // namespace menu

#include "Menu.cpp"
#endif