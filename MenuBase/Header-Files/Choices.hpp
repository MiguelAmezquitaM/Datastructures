
#ifndef Choices_hpp
#define Choices_hpp

#include <string>
#include <vector>

using std::vector;

namespace menu {

    template<typename T>
    struct Choice {
        T value;
        std::string message;
    };

    template<typename T>
    struct Choices {
        std::string message;
        vector<Choice<T>> choices;
    };

}


#endif
