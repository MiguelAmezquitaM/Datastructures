#include "Tree.hpp"

using std::string;
using namespace tree;

Branch* Tree::get_root() {
    return &root;
}

void Branch::add_branch(Branch branch) {
    child_branches.append(branch);
}

string Branch::get_name() {
    return name;
}

void Branch::set_name(string _name) {
    name = _name;
}

string Sheet::get_name() {
    return name;
}

void Sheet::set_name(string _name) {
    name = _name;
}

Branch& Branch::get_brach(string _name) {
    Branch *temp;
    for (int i = 0; i < child_branches.length; i++) {
        temp = &child_branches[i];
        if (temp->get_name() == _name) {
            return *temp;
        }
    }
    throw std::logic_error("No existe la rama\n");
}
