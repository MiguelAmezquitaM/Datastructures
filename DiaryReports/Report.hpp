#ifndef Report_h
#define Report_h

#include <iostream>
#include <string>
#include <functional>

struct BaseNew {
    int ref;
    std::string title;
    std::string description;
    std::string type;
};

class NewsStack {
    BaseNew stack[100];
    int top;

public:
    BaseNew* get_last();
    bool empty() const;
    void delete_last();
    void append(BaseNew report);
    void for_each(std::function<void(BaseNew*, int)> callback);
    int get_top() const;
    int length() const;

    NewsStack();
};

#endif
