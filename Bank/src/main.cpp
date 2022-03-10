#include "Bank.hpp"

using namespace bank;

auto main() -> int {
    Bank bank;

    Client c1 = {1, "nametest", normal, consignment, 10000};
    Client c2 = {2, "nametest2", normal, retirement, 10000};
    Client c3 = {3, "nametest3", priviliged, consignment, 10000};
    Client c4 = {4, "nametest4", normal, retirement, 10000};
    Client c5 = {5, "nametest5", priviliged, retirement, 10000};

    bank.input(c1);
    bank.input(c2);
    bank.input(c3);
    bank.input(c4);
    bank.input(c5);

    bank.deleteById(1);
    bank.deleteById(2);

    bank.print();

    bank.attend();
    bank.attend();
    bank.attend();

    bank.print();

    return EXIT_SUCCESS;
}
