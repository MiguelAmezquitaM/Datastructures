#include <iostream>
#include "Tree.hpp"

using std::cout;
using namespace tree;

int main() {
    Tree myTree;

    Branch root = *myTree.get_root();

    Branch usr, bin, etc;

    usr.set_name("usr");
    bin.set_name("bin"); 
    etc.set_name("etc");

    root.add_branch(usr);
    root.add_branch(bin);
    root.add_branch(etc);

    cout << root.get_brach("usr").get_name() << "\n";

    return EXIT_SUCCESS;
}
