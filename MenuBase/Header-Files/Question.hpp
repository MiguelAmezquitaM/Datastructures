
#ifndef Question_hpp
#define Question_hpp

#include <string>

namespace menu {

    template<typename T>
    struct Question {
        
        std::string message;

        T value;

    };

}


#endif

