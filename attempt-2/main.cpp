#include "program.hpp"

int main(int argc, char const *argv[])
{
    Computer *pclist = exampleList();
    main_menu(pclist);
    
    return 0;
}
