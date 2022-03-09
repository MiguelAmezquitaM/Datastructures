#include "Bank.hpp"

auto main()-> int {
    Bank bank;

    Client c1 = {1, "nametest", normal, consignment, 10000};
    Client c2 = {2, "nametest2", normal, retirement, 10000};
    Client c3 = {3, "nametest3", normal, retirement, 10000};

    bank.input(c1);
    bank.input(c2);
    bank.input(c3);

    bank.attend();
    bank.attend();
    bank.attend();

    return 0;
}
