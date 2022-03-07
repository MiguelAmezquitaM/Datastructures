#include "DiaryReports.hpp"
#include <exception>
#include <iomanip>

Report DiaryReports::input_report() {
    Report report;

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

int DiaryReports::input_reference() {
    int ref;
    console.print("Referencia: ");
    console.get_int(ref);
    return ref;
}

void DiaryReports::insert_report() {
    Report report = input_report();
    stackReports.append(report);
}

Report* DiaryReports::get_report_by_ref(int ref) {
    Report* report = nullptr;

    stackReports.for_each([ref, &report](Report* r, int i) {
        if (r->ref == ref) {
            report = r;
        }
        });

    if (report == nullptr) {
        throw std::logic_error("No existe un reporte con esa referencia\n");
    }

    return report;
}

void DiaryReports::modify_report() {
    int ref = input_reference();
    Report* r;

    try {
        r = get_report_by_ref(ref);
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

void DiaryReports::print_reports() {
    using std::cout;
    using std::setw;

    auto sep = setw(30);

    cout << sep << "Title" << sep << "Description" << sep << "Type" << sep << "Ref" << "\n\n";
    stackReports.for_each([sep](Report* rep, int i) {
        cout << sep << rep->title << sep << rep->description << sep << rep->type << sep << rep->ref << "\n";
        });
    cout << "\n";
}
