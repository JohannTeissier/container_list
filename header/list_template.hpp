#pragma once

#include <iostream>
#include <fstream>
#include <initializer_list>

namespace pw
{

template <typename T>
class Element
{
public:

    /*------------------ Constructor ------------------*/
    // Element() = default;
    Element(const T &val, Element<T>* next = nullptr, Element<T>* prev = nullptr);
    Element(const Element<T>& elem);
    Element(T* val);

    /*------------------ Destructor ------------------*/
    ~Element();


    /*------------------ Getter ------------------*/
    T &get_ref_val();
    T get_copy_val();
    T *ref_get_val();
    Element<T>* get_prev() const;
    Element<T>* get_next() const;
    Element<T>* data() const;

    /*------------------ Setter ------------------*/
    void set_value(const T val);
    void set_ref(T *val);
    void free_ref(T val);
    void free_ref(T *val);
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

    operator T();

    friend std::ostream& operator <<(std::ostream& os, Element<T>& elem)
    {
        os << *elem.__p_val;

        return os;
    }

private:

    T *__p_val = nullptr;
    Element* __pnext = nullptr;
    Element* __pprev = nullptr;

    bool __destroy = true;
    bool __is_ref = false;
};

template<typename U>
class List
{
public:

    void print_list();

    /*------------ Constructor ------------*/
    List() = default;
    List(const List<U>& l);
    List(std::initializer_list<U> list);

    /*------------ Destructor ------------*/
    ~List();

    /*------------ Getter ------------*/
    int get_cardinal() const;

    U *get_elem(size_t index);

    /*------------ Push functions ------------*/
    void push_front(const U &val);
    void push_back(const U &val);
    void push(size_t index, const U &val);

    void ref_push_front(U *val);
    void ref_push_back(U *val);
    void ref_push(size_t index, U *val);

    /*------------ Pop functions ------------*/
    void pop_front();
    void pop_back();
    void pop(size_t index);

    void clear();

    void operator =(const List<U>& other);
    void operator =(std::initializer_list<U> list);
    U& operator [](size_t index);

    friend std::ostream& operator <<(std::ostream& os, List<U>& elem)
    {
        Element<U> *temp = elem.__first;

        os << "-[";

        while(temp != nullptr)
        {
            os << temp->get_ref_val();
            temp = temp->get_next();

            if(temp != nullptr)
                os << " ";
        }

        os << "]-";

        return os;
    }

    class Iterator {
    private:
        Element<U>* current; // Pointeur sur l'élément actuel
    public:
        // Constructeur
        Iterator(Element<U>* ptr) : current(ptr) {}

        // Opérateur déréférencement
        U& operator*() { return current->get_ref_val(); }

        // Opérateur de comparaison
        bool operator!=(const Iterator& other) const { return current != other.current; }

        // Opérateur d'incrémentation
        Iterator& operator++() {
            this->current = this->current->get_next();
            return *this;
        }
    };

    // Méthodes begin() et end()
    Iterator begin() { return Iterator(this->__first); }
    Iterator end() { return Iterator(nullptr); }

private:

    Element<U>* __first = nullptr;
    Element<U>* __last = nullptr;
    int __cardinal = 0;
    bool __empty = true;
    bool __destroy = true;
};



} // namespace pw
