#ifndef Menu_h
#define Menu_h

#include "Report.hpp"
#include "Console.hpp"
#include "DailyNews.hpp"

class Menu {
    DailyNews diaryReports;

    enum Options : int {
        agregar_noticia = 1,
        listar_noticias,
        modificar_noticia,
        exit_menu
    };

    // Methods
    void print_header() const;
    void print_menu_options() const;
    void get_option(int& opc) const;
    void handle_option(int& opc);

public:
    void run();
};



#endif
