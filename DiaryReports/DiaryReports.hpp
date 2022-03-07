#ifndef DiaryReports_h
#define DiaryReports_h

#include "Report.hpp"
#include "Console.hpp"

class DiaryReports {
private:
    StackReports stackReports;

    Report input_report();
    int input_reference();
    Report* get_report_by_ref(int ref);
public:
    void insert_report();
    void modify_report();
    void print_reports();
};

#endif