#ifndef Node_hpp
#define Node_hpp

template<typename type> struct
Node {
    type data;
    Node<type>* next;

    Node(type data) : data(data), next(nullptr) {}
};


#endif