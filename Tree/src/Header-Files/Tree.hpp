#ifndef Tree_hpp
#define Tree_hpp

#include "LinkedList.hpp"
#include <string>

namespace tree {

    class Sheet {
        std::string name;
    public:
        std::string get_name();
        void set_name(std::string);
    };

    class Branch {
        std::string name;
        List<Branch> child_branches;
        List<Sheet> sheets;

    public:
        std::string get_name();
        void set_name(std::string);
        void add_branch(Branch);
        Branch &get_brach(std::string name);
    };

    class Tree {
        Branch root;

    public:
        Branch *get_root();
    };

} // namespace tree


#endif

