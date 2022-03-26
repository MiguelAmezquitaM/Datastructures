#ifndef Queue_hpp
#define Queue_hpp

#include "SimpleList.hpp"
#include <exception>

template<typename type>
class Queue {
private:
    List<type> queue;

public:
    int length() {
        return queue.length();
    }

    void append(type data) {
        queue.append(data);
    }

    void remove() {
        queue.removeBegin();
    }

    type get() {
        return queue[0];
    }

    bool empty() {
        return queue.empty();
    }
};

#endif