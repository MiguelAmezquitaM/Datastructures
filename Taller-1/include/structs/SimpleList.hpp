#ifndef SimpleList_hpp
#define SimpleList_hpp

#include <functional>
#include <exception>
#include "Node.hpp"

template<typename type>
class List {
private:
    Node<type>* begin;

    Node<type>* end;

public:

    List() : begin(nullptr), end(nullptr) {}

    int length() {
        auto p = begin;
        int c = 0;

        while (p != nullptr) {
            p = p->next;
            c++;
        }
        
        return c;
    }

    bool empty() {
        return begin == nullptr;
    }

    void append(type _data) {
        auto newNode = new Node<type>(_data);

        if (empty()) { begin = end = newNode; return; }

        end->next = newNode;
        end = newNode;
    }

    void appbegin(type _data) {
        auto newNode = new Node<type>(_data);

        if (empty()) { begin = end = newNode; return; }

        newNode->next = begin;
        begin = newNode;
    }

    void removeEnd() {
        auto p = begin;

        if (empty()) return;

        if (begin == end) {
            delete begin;
            begin = nullptr;
            end = nullptr;
            return;
        }

        while (p->next != end)
            p = p->next;

        p->next = nullptr;
        delete end;
        end = p;
    }

    void removeBegin() {
        auto p = begin;

        if (empty()) return;

        if (begin == end) {
            delete begin;
            begin = nullptr;
            end = nullptr;
            return;
        }

        begin = p->next;
        p->next = nullptr;
        delete p;
    }

    void remove(int index) {
        auto p = begin;
        int c = 0;

        if (empty()) return;
        if (index == 0) { removeBegin(); return; }

        begin = p->next;
        p->next = nullptr;
        delete p;
    }

    void forEach(std::function<void(type&, int)> callback) {
        auto p = begin;
        int c = 0;

        if (empty()) return;

        while (p != nullptr) {
            callback(p->data, c++);
            p = p->next;
        }
    }

    List<type> filter(std::function<bool(type&, int)> callback) {
        auto p = begin;
        int c = 0;
        List<type> filtered;

        if (empty()) return filtered;

        while (p != nullptr) {
            if(callback(p->data, c++))
                filtered.append(p->data);
    
            p = p->next;
        }

        return filtered;
    }

    type& operator[](int index) {
        type* response;
        bool founded = false;

        forEach([&response, &founded, index](type& data, int i) {
            if (i == index) {
                founded = true;
                response = &data;
            }
        });

        if (!founded) throw std::logic_error("Index of range ERROR");

        return *response;
    }
};


#endif