#ifndef Report_h
#define Report_h

#include <iostream>
#include <string>
#include <functional>



struct Report {
    int ref;
    std::string title;
    std::string description;
    std::string type;
};



class StackReports {
    Report stack[100];
    int top;

public:
    Report* get_last();
    bool empty() const;
    void delete_last();
    void append(Report report);
    void for_each(std::function<void(Report*, int)> callback);
    int get_top() const;
    int length() const;

    StackReports();
};

#endif
