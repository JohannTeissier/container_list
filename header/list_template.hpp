#pragma once

#include <iostream>
#include <fstream>

namespace pw
{

template <typename T>
class Element
{
public:

    void print_value() const;

    /*------------------ Constructor ------------------*/
    Element(T val, Element<T>* next = nullptr, Element<T>* prev = nullptr);
    Element(const Element<T>& elem);

    /*------------------ Destructor ------------------*/
    ~Element();


    /*------------------ Getter ------------------*/
    T &get_ref_val();
    T get_copy_val() const;
    Element<T>* get_prev() const;
    Element<T>* get_next() const;
    Element<T>* data() const;

    /*------------------ Setter ------------------*/
    void set_value(const T val);
    void set_prev(Element<T>* prev);
    void set_next(Element<T>* next);

    /*------------------ Define operator ------------------*/
    void operator =(const Element<T>& elem);
    void operator =(const T val);
    Element<T> operator *(const Element<T> &elem);
    Element<T> operator +(const Element<T> &elem);
    Element<T> operator -(const Element<T> &elem);
    Element<T> operator /(const Element<T> &elem);
    void operator +=(const Element<T> &elem);
    void operator +=(const T val);
    void operator -=(const Element<T> &elem);
    void operator -=(const T val);
    void operator *=(const Element<T> &elem);
    void operator *=(const T val);
    void operator /=(const Element<T> &elem);
    void operator /=(const T val);
    bool operator ==(const Element<T> &elem);
    bool operator ==(const T val);
    bool operator !=(const Element<T> &elem);
    bool operator !=(const T val);
    bool operator <=(const Element<T> &elem);
    bool operator <=(const T val);
    bool operator >=(const Element<T> &elem);
    bool operator >=(const T val);
    bool operator <(const Element<T> &elem);
    bool operator <(const T val);
    bool operator >(const Element<T> &elem);
    bool operator >(const T val);
    bool operator &&(const Element<T> &elem);
    bool operator &&(const T val);
    bool operator ||(const Element<T> &elem);
    bool operator ||(const T val);

    operator T() const;

    friend std::ostream& operator <<(std::ostream& os, Element<T>& elem)
    {
        os << elem.__value;
        return os;
    }

private:

    T __value;
    Element* __pnext = nullptr;
    Element* __pprev = nullptr;

    bool __destroy = true;
};

template<typename U>
class List
{
public:

    void print_list();

    /*------------ Constructor ------------*/
    List() = default;

    /*------------ Destructor ------------*/
    ~List();

    /*------------ Getter ------------*/
    int get_cardinal() const;

    /*------------ Push functions ------------*/
    void push_front(const U val);
    void push_back(const U val);
    void push(size_t index, U val);

    /*------------ Pop functions ------------*/
    void pop_front();
    void pop_back();
    void pop(size_t index);

private:

    Element<U>* __first = nullptr;
    Element<U>* __last = nullptr;
    int __cardinal = 0;
    bool __empty = true;
};



} // namespace pw
