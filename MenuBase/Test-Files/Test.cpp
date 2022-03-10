#include "Menu.hpp"

using namespace menu;
using std::cout;
using std::string;

int main() {

    Choices<int> test_choices = {
        "Seleccione una opcion",
        {
            {1, "test_option_1"},
            {2, "test_option_2"},
            {3, "test_option_3"},
            {4, "test_option_4"},
            {5, "test_option_5"}
        }
    };

    int res = promptChoices(test_choices);

    cout << "se escogio: " << res << "\n\n\n";

    float f;
    prompt("Digite el numero pi: ", f);
    cout << "Pi: " << f << "\n\n";

    return 0;
}
