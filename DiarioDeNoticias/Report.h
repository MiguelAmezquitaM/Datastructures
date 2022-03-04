#include <string>
#include <iostream>


struct Report
{ 
    int ref;
    std::string title;
    std::string description;
    std::string type;
};


class StackReports
{

    Report stack[100];
    int top;

public:

    Report &get_last_report();
    int get_top();
    void delete_last();
    void append(Report report);
    bool empty();
    int length();
    void print();
    
    StackReports() : top(-1)
	{
	}
};

