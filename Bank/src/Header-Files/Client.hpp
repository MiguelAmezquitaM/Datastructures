
#pragma once

#include <string>

namespace bank {

    enum Action : int {
        retirement,
        consignment
    };

    enum Priority : int {
        normal,
        priviliged
    };

    struct Client {
        // datos del usuario
        int id;
        std::string name;
        Priority priority;
        Action action;
        int value;
    };

}