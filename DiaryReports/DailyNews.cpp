#include "DailyNews.hpp"
#include <exception>
#include <iomanip>

BaseNew DailyNews::input_news() {
    BaseNew report;

    console.print("Title: ");
    console.get_string(report.title);

    console.print("Description: ");
    console.get_string(report.description);

    console.print("Type: ");
    console.get_string(report.type);

    console.print("Ref: ");
    console.get_int(report.ref);

    return report;
}

int DailyNews::input_ref() {
    int ref;
    console.print("Referencia: ");
    console.get_int(ref);
    return ref;
}

void DailyNews::insert_new() {
    BaseNew report = input_news();
    newsStack.append(report);
}

BaseNew* DailyNews::get_new_by_ref(int ref) {
    BaseNew* report = nullptr;

    newsStack.for_each([ref, &report](BaseNew* r, int i) {
        if (r->ref == ref) {
            report = r;
        }
        });

    if (report == nullptr) {
        throw std::logic_error("No existe un reporte con esa referencia\n");
    }

    return report;
}

void DailyNews::modify_new() {
    int ref = input_ref();
    BaseNew* r;

    try {
        r = get_new_by_ref(ref);
    }
    catch (std::logic_error err) {
        console.print(err.what());
        console.pause();
        return;
    }

    console.print("Nuevo titulo: ");
    console.get_string(r->title);

    console.print("Nueva descripcion: ");
    console.get_string(r->description);
}

void DailyNews::print_new() {
    using std::cout;
    using std::setw;

    auto sep = setw(30);

    cout << sep << "Title" << sep << "Description" << sep << "Type" << sep << "Ref" << "\n\n";
    newsStack.for_each([sep](BaseNew* rep, int i) {
        cout << sep << rep->title << sep << rep->description << sep << rep->type << sep << rep->ref << "\n";
        });
    cout << "\n";
}
