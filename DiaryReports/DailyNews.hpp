#ifndef DiaryReports_h
#define DiaryReports_h

#include "Report.hpp"
#include "Console.hpp"

class DailyNews {
private:
    NewsStack newsStack;

    BaseNew input_news();
    int input_ref();
    BaseNew* get_new_by_ref(int ref);
public:
    void insert_new();
    void modify_new();
    void print_new();
};

#endif