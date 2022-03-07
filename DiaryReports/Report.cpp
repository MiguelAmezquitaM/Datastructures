#include <exception>
#include "Report.hpp"

// Constructor
NewsStack::NewsStack() : top(-1) {
}

void NewsStack::append(BaseNew report) {
    stack[++top] = report;
}

void NewsStack::delete_last() {
    if (!empty())
        top--;
}

bool NewsStack::empty() const {
    return top == -1;
}

BaseNew* NewsStack::get_last() {
    if (!empty())
        return &stack[top];

    throw "Stack empty";
}

int NewsStack::get_top() const {
    return top;
}

int NewsStack::length() const {
    return top + 1;
}

void NewsStack::for_each(std::function<void(BaseNew*, int)> callback) {
    NewsStack temp;
    int i = 0;

    while (!empty()) {
        callback(get_last(), i);
        temp.append(*get_last());
        delete_last();
    }
    while (!temp.empty()) {
        append(*temp.get_last());
        temp.delete_last();
    }
}
