#include <exception>
#include <iostream>
#include "Report.hpp"

StackReports::StackReports() : top(-1)
{
}

void StackReports::append(Report report)
{
    stack[++top] = report;
}

void StackReports::delete_last()
{
    if (!empty())
        top--;
}

bool StackReports::empty()
{
    return top == -1;
}

Report *StackReports::get_last()
{
    if (!empty())
        return &stack[top];

    throw "Stack empty";
}

int StackReports::get_top()
{
    return top;
}

int StackReports::length()
{
    return top + 1;
}

void StackReports::print()
{
    for (int i = top; i >= 0; i--)
    {
        std::cout << "titulo: " << stack[i].title << "  descripcion: " << stack[i].description << std::endl;
    }
}

void StackReports::for_each(CallbackType callback)
{
    StackReports temp;
    int i = 0;
    
    while(!empty()) {
        callback(get_last(), i);
        temp.append(*get_last());
        delete_last();
    }
    while(!empty()) {
        append(*temp.get_last());
        temp.delete_last();
    }
}
