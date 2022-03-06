#include "DiaryReports.hpp"
#include <exception>

Report DiaryReports::input_report()
{
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

int DiaryReports::input_reference()
{
    int ref;
    console.print("Referencia: ");
    console.get_int(ref);
    return ref;
}

void DiaryReports::insert_report()
{
    Report report = input_report();
    stackReports.append(report);
}

Report *DiaryReports::get_report_by_ref(int ref)
{
    StackReports temp;
    bool found = false;
    Report *r;

    while (!stackReports.empty())
    {
        r = stackReports.get_last();

        if (r->ref == ref)
        {
            found = true;
            break;
        }

        temp.append(*r);
        stackReports.delete_last();
    }

    while (!temp.empty())
    {
        stackReports.append(*temp.get_last());
        temp.delete_last();
    }

    if (!found)
        throw std::logic_error("No existe un reporte con esa referencia");

    return r;
}

void DiaryReports::modify_report()
{
    int ref = input_reference();
    Report *r;
    

    try
    {
        r = get_report_by_ref(ref);
    }
    catch (std::logic_error err)
    {
        console.print(err.what());
        console.print("\n");
        console.pause();
        return;
    }

    console.print("Nuevo titulo: ");
    console.get_string(r->title);

    console.print("Nueva descripcion: ");
    console.get_string(r->description);
}

void DiaryReports::print_reports()
{
    stackReports.for_each([](Report *rep, int i)
                          {
        std::cout << "Title: " << rep->title << "\n";
        std::cout << "Description: " << rep->description << "\n";
        std::cout << "Type: " << rep->type << "\n";
        std::cout << "Ref: " << rep->ref << "\n\n"; });
}
