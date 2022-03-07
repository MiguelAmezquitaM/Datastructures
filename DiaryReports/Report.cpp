#include <exception>
#include "Report.hpp"

// Constructor
StackReports::StackReports() : top(-1) {
}

void StackReports::append(Report report) {
    stack[++top] = report;
}

void StackReports::delete_last() {
    if (!empty())
        top--;
}

bool StackReports::empty() const {
    return top == -1;
}

Report* StackReports::get_last() {
    if (!empty())
        return &stack[top];

    throw "Stack empty";
}

int StackReports::get_top() const {
    return top;
}

int StackReports::length() const {
    return top + 1;
}

void StackReports::for_each(std::function<void(Report*, int)> callback) {
    StackReports temp;
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
