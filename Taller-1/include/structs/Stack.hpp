#ifndef Stack_hpp
#define Stack_hpp

#include "SimpleList.hpp"

template<typename type>
class Stack {
private:
    List<type> stack;
public:

    int length() {
        return stack.length();
    }

    void insert(type data) {
        stack.appbegin(data);
    }

    void remove() {
        stack.removeBegin();
    }

    type get() {
        return stack[0];
    }

    bool empty() {
        return stack.empty();
    }
};

#endif