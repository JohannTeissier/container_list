#pragma once

#include "list_template.hpp"

namespace pw
{
    template <typename T>
    inline void Element<T>::print_value() const
    {
        std::cout << this->__value << std::endl;
    }

template <typename T>
inline Element<T>::Element(const T &val, Element<T> *next, Element<T> *prev)
{
    this->__value = val;
    this->__pprev = prev;
    this->__pnext = next;
}

template <typename T>
inline Element<T>::Element(const Element<T> &elem)
{
    this->__value = T{elem.__value};
    this->__pprev = nullptr;
    this->__pnext = nullptr;
}

template <typename T>
inline Element<T>::~Element()
{
    // if(this->__destroy)
        // std::cout << "Object deleted." << std::endl;
}

template <typename T>
inline T &Element<T>::get_ref_val()
{
    return this->__value;
}

template <typename T>
inline T Element<T>::get_copy_val() const
{
    return this->__value;
}

template <typename T>
inline Element<T> *Element<T>::get_prev() const
{
    return this->__pprev;
}

template <typename T>
inline Element<T> *Element<T>::get_next() const
{
    return this->__pnext;
}

template <typename T>
inline Element<T> *Element<T>::data() const
{
    return this;
}

template <typename T>
inline void Element<T>::set_value(const T val)
{
    this->__value = val;
}

template <typename T>
inline void Element<T>::set_prev(Element<T> *prev)
{
    this->__pprev = prev;
}

template <typename T>
inline void Element<T>::set_next(Element<T> *next)
{
    this->__pnext = next;
}

template <typename T>
inline void Element<T>::operator=(const Element<T> &elem)
{
    this->__value = elem.__value;
}

template <typename T>
inline void Element<T>::operator=(const T val)
{
    this->__value = val;
}

template <typename T>
inline Element<T> Element<T>::operator*(const Element<T> &elem)
{
    Element<T> temp = Element<T>{this->__value * elem.__value};
    temp.__destroy = false;

    return temp;
}

template <typename T>
inline Element<T> Element<T>::operator+(const Element<T> &elem)
{
    Element<T> temp = Element<T>{this->__value + elem.__value};
    temp.__destroy = false;

    return temp;
}

template <typename T>
inline Element<T> Element<T>::operator-(const Element<T> &elem)
{
    Element<T> temp = Element<T>{this->__value - elem.__value};
    temp.__destroy = false;

    return temp;
}

template <typename T>
inline Element<T> Element<T>::operator/(const Element<T> &elem)
{
    Element<T> temp = Element<T>{this->__value / elem.__value};
    temp.__destroy = false;

    return temp;
}

template <typename T>
inline void Element<T>::operator+=(const Element<T> &elem)
{
    this->__value += elem.__value;
}

template <typename T>
inline void Element<T>::operator+=(const T val)
{
    this->__value += val;
}

template <typename T>
inline void Element<T>::operator-=(const Element<T> &elem)
{
    this->__value -= elem.__value;
}

template <typename T>
inline void Element<T>::operator-=(const T val)
{
    this->__value -= val;
}

template <typename T>
inline void Element<T>::operator*=(const Element<T> &elem)
{
    this->__value *= elem.__value;
}

template <typename T>
inline void Element<T>::operator*=(const T val)
{
    this->__value *= val;
}

template <typename T>
inline void Element<T>::operator/=(const Element<T> &elem)
{
    this->__value /= elem.__value;
}

template <typename T>
inline void Element<T>::operator/=(const T val)
{
    this->__value /= val;
}

template <typename T>
inline bool Element<T>::operator==(const Element<T> &elem)
{
    if(this->__value == elem.__value)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator==(const T val)
{
    if(this->__value == val)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator!=(const Element<T> &elem)
{
    return !(*this == elem);
}

template <typename T>
inline bool Element<T>::operator!=(const T val)
{
    return !(*this == val);
}

template <typename T>
inline bool Element<T>::operator<=(const Element<T> &elem)
{
    if(this->__value <= elem.__value)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator<=(const T val)
{
    if(this->__value <= val)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator>=(const Element<T> &elem)
{
    if(this->__value >= elem.__value)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator>=(const T val)
{
    if(this->__value >= val)
        return true;

    return false;
}

template <typename T>
inline bool Element<T>::operator<(const Element<T> &elem)
{
    return ((*this <= elem) && !(*this == elem));
}

template <typename T>
inline bool Element<T>::operator<(const T val)
{
    return ((*this <= val) && !(*this == val));
}

template <typename T>
inline bool Element<T>::operator>(const Element<T> &elem)
{
    return ((*this >= elem) && !(*this == elem));
}

template <typename T>
inline bool Element<T>::operator>(const T val)
{
    return ((*this >= val) && !(*this == val));
}

template <typename T>
inline bool Element<T>::operator&&(const Element<T> &elem)
{
    return (this->__value && elem.__value);
}

template <typename T>
inline bool Element<T>::operator&&(const T val)
{
    return (this->__value && val);
}

template <typename T>
inline bool Element<T>::operator||(const Element<T> &elem)
{
    return (this->__value || elem.__value);
}

template <typename T>
inline bool Element<T>::operator||(const T val)
{
    return (this->__value || val);
}

template <typename T>
inline Element<T>::operator T() const
{
    return this->__value;
}

/*----------------------------------------------------------------------------*/
/*----------------------------------- List -----------------------------------*/
/*----------------------------------------------------------------------------*/

template <typename U>
inline void List<U>::print_list()
{
    Element<U>* temp = this->__first;

    while(temp != nullptr)
    {
        std::cout << *temp << std::endl;
        temp = temp->get_next();
    }
}

template <typename U>
inline List<U>::List(const List<U> &l)
{
    if(this->__last != nullptr && this->__first != nullptr)
        this->clear();

    Element<U> *temp = l.__last;

    while(temp != nullptr)
    {
        this->push_front(temp->get_copy_val());
        temp = temp->get_prev();
    }

    //this->__destroy = false;
}

template <typename U>
inline List<U>::~List()
{
    if(!this->__empty && this->__destroy)
    {
        // std::cout << "List : \n[\n";
        // this->print_list();
        // std::cout << "]" << std::endl;
        // std::cout << "List deleted." << std::endl;
        while(!this->__empty)
            this->pop_back();
    }
    else
        // std::cout << "Nothing to delete." << std::endl;

    if(this->__destroy == false)
        this->__destroy = true;
}

template <typename U>
inline int List<U>::get_cardinal() const
{
    return this->__cardinal;
}

template <typename U>
inline void List<U>::push_front(const U &val)
{
    Element<U> *temp = new Element<U>{val};

    if(this->__empty)
    {
        this->__empty = false;

        this->__first = temp;
        this->__last = temp;

        this->__cardinal++;

        return;
    }

    temp->set_next(this->__first);
    this->__first->set_prev(temp);
    this->__first = temp;

    this->__cardinal++;
}

template <typename U>
inline void List<U>::push_back(const U &val)
{
    Element<U> *temp = new Element<U>{val};

    if(this->__empty)
    {
        this->__empty = false;

        this->__first = temp;
        this->__last = temp;

        this->__cardinal++;

        return;
    }

    temp->set_prev(this->__last);
    this->__last->set_next(temp);
    this->__last = temp;

    this->__cardinal++;
}

template <typename U>
inline void List<U>::push(size_t index, const U &val)
{
    if(index < 0 || index > this->__cardinal)
    {
        std::cout << "ERROR:: The index is out of the range." << std::endl;
        return;
    }

    if(index == 0)
    {
        this->push_front(val);
        return;
    }
    if(index == this->__cardinal)
    {
        this->push_back(val);
        return;
    }

    Element<U> *temp;
    Element<U> *elem = new Element<U>{val};

    if(index < this->__cardinal / 2)
    {
        temp = this->__first;
        for(int  i = 0; i < index; i++)
            temp = temp->get_next();
    }
    else
    {
        temp = this->__last;
        for(int i = 0; i < this->__cardinal - index - 1; i++)
            temp = temp->get_prev();
    }

    elem->set_next(temp);
    elem->set_prev(temp->get_prev());
    (temp->get_prev())->set_next(elem);
    temp->set_prev(elem);

    this->__cardinal++;
}

template <typename U>
inline void List<U>::pop_front()
{
    if(this->__empty)
        return;

    Element<U> *temp = this->__first;

    this->__first = this->__first->get_next();

    if(this->__first != nullptr)
        this->__first->set_prev(nullptr);

    temp->set_next(nullptr);

    this->__cardinal--;

    if(this->__cardinal == 0)
    {
        this->__empty = true;
        this->__last = nullptr;
    }

    delete temp;
}

template <typename U>
inline void List<U>::pop_back()
{
    if(this->__empty)
        return;

    Element<U> *temp = this->__last;

    this->__last = this->__last->get_prev();

    if(this->__last != nullptr)
        this->__last->set_next(nullptr);

    temp->set_prev(nullptr);

    this->__cardinal--;

    if(this->__cardinal == 0)
    {
        this->__empty = true;
        this->__first = nullptr;
    }

    delete temp;
}

template <typename U>
inline void List<U>::pop(size_t index)
{
    if(index < 0 || index > this->__cardinal - 1)
    {
        std::cout << "ERROR:: Index is out of range." << std::endl;
        return;
    }

    if(index == 0)
    {
        this->pop_front();
        return;
    }
    if(index == this->__cardinal - 1)
    {
        this->pop_back();
        return;
    }

    Element<U> *temp;

    if(index < this->__cardinal / 2)
    {
        temp = this->__first;
        for(int  i = 0; i < index; i++)
            temp = temp->get_next();
    }
    else
    {
        temp = this->__last;
        for(int i = 0; i < this->__cardinal - index - 1; i++)
            temp = temp->get_prev();
    }

    (temp->get_prev())->set_next(temp->get_next());
    (temp->get_next())->set_prev(temp->get_prev());

    delete temp;

    this->__cardinal--;
}

template <typename U>
inline void List<U>::clear()
{
    while(!this->__empty)
        this->pop_back();
}

template <typename U>
inline void List<U>::operator=(const List<U> &other)
{
    if(this->__last != nullptr && this->__first != nullptr)
        this->clear();

    Element<U> *temp = other.__last;

    while(temp != nullptr)
    {
        this->push_front(temp->get_copy_val());
        temp = temp->get_prev();
    }
}

template <typename U>
inline U &List<U>::operator[](size_t index)
{
    if(index < 0 || index > this->__cardinal)
    {
        std::cout << "ERROR:: The index is out of the range." << std::endl;
        return this->__first->get_ref_val();
    }

    if(index == 0)
    {
        return this->__first->get_ref_val();
    }
    if(index == this->__cardinal - 1)
    {
        return this->__last->get_ref_val();
    }

    Element<U> *temp;

    if(index < this->__cardinal / 2)
    {
        temp = this->__first;
        for(int  i = 0; i < index; i++)
            temp = temp->get_next();
    }
    else
    {
        temp = this->__last;
        for(int i = 0; i < this->__cardinal - index - 1; i++)
            temp = temp->get_prev();
    }

    return temp->get_ref_val();
}

} // namespace pw

