#ifndef Report_h
#define Report_h

#include <iostream>
#include <string>

struct Report
{
    int ref;
    std::string title;
    std::string description;
    std::string type;
};

typedef void (*CallbackType)(Report *, int);

class StackReports
{
    Report stack[100];
    int top;

public:
    Report *get_last();
    bool empty();
    void delete_last();
    void append(Report report);
    void print();
    void for_each(CallbackType callback);
    int get_top();
    int length();

    StackReports();
};

#endif
