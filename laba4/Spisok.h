#pragma once

#include "univer.h"

template <typename T>
class node {
public:
    T data;
    node* sled;
    node* pred;

    node() {}
    node(T d) {
        data = d;
    }

    friend ostream& operator << (ostream& s, node<T>& d) {
        s << d.data;
        return s;
    }

    bool operator > (node<T>& rhs) {
        return data > rhs.data;
    }

    bool operator < (node<T>& rhs) {
        return data < rhs.data;
    }
};

template <typename T>
class Spisok
{
private:
    node<T>* first;
    int countElements;
public:

    class Iterator;

    Spisok() { first = NULL; countElements = 0; }
    
    void add(T data) {
        countElements++;
        if (first == NULL) {
            first = new node<T>(data);
            (*first).pred = first;
            (*first).sled = first;
            return;
        }

        auto itBegin = begin();
        auto itEnd = end();

        node<T>* n = new node<T>(data);
        (*itEnd).sled = n;
        n->pred = &*itEnd;
        n->sled = &*itBegin;
        (*itBegin).pred = n;
    }

    void print() {
        auto it = begin();
        do {
            cout << *it << endl;
            it++;
        } while (it != begin());
    }

    void printReverse() {
        auto it = end();
        do {
            cout << *it << endl;
            it--;
        } while (it != end());
    }

    void sort() {
        for (int i = 0; i < size() - 1; i++) {
            Spisok<T>::Iterator e = end();
            auto it2 = begin();
            do {
                auto kk = it2 + 1;
                if (it2 > kk) {
                    T d = (*it2).data;
                    (*it2).data = (*kk).data;
                    (*kk).data = d;
                }
                it2++;
            } while (it2 != e);
        }
    }

    int size() { return countElements; }

    Spisok<T>::Iterator begin() { return  Spisok<T>::Iterator(first); }
    Spisok<T>::Iterator end() { return  Spisok<T>::Iterator(first->pred); }

#pragma region Iterator
    class Iterator {
        node<T>* cur;
    public:
        Iterator(node<T>* first) : cur(first) {}

        node<T>& operator++(int) {
            cur = cur->sled;
            return *cur;
        }
        node<T>& operator--(int) {
            cur = cur->pred;
            return *cur;
        }

        node<T>& operator* () { return *cur; }

        bool operator!= (const Iterator& it) { return cur != it.cur; }

        node<T>& operator=(const T& data) {
            cur->data = data;
            return *cur;
        }

        Iterator& operator- (int n) {
            Iterator it(cur);
            for (int i = 0; i < n; i++)
                it--;
            return it;
        }

        Iterator& operator+ (int n) {
            Iterator it(cur);
            for (int i = 0; i < n; i++)
                it++;
            return it;
        }

        bool operator > (Iterator& rhs) {
            return cur->data > (*rhs).data;
        }

        bool operator < (Iterator& rhs) {
            return cur < &(*rhs);
        }
    };
#pragma endregion
};

