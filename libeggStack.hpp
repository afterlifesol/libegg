#ifndef _libeggStack_hpp_INCLUDED_
#define _libeggStack_hpp_INCLUDED_

#include <stdexcept>
using std::out_of_range;
using std::invalid_argument;

#define TOP_ERROR "Attempted to access top of empty stack"

namespace egg
{

/*
    // ### Iterator ### -- Implemented Inline
    // TODO: see about cleaning this up.
    public:
        class Iter
        {
            protected:
                Stack *list;
                int index;

            public:
                Iter(Stack *list, int index): list(list), index(index) {};

                const T& operator*() const { return list->at(index); }

                T& operator*() { return list->at(index); }

                int operator++()
                    { if ( index < (list->size()) ) index++; return index; }

                bool operator==( const Iter &rhs)
                    { return ! operator!=(rhs); }

                bool operator!=( const Iter &rhs)
                {
                    if ( list != rhs.list ) return true;
                    if (index != rhs.index) return true;
                    return false;
                }
        };

 */

//############################  Stack Header  ############################
/**
 * @class Stack
 * @author afterlifesol
 * @date 07/05/16
 * @file eggStack.cpp
 * @brief One way Dynamic Alloc Node based Stack
 */

template <typename T> class Stack
{
private:
    struct node
    {
        T data;
        node* next = nullptr;
        node(const T& Data, node* pnode)
            : data(Data)
            , next(pnode)
        {
        }
        ~node()
        {
            if(next != nullptr)
                delete next;
        }
    };

    node* _head = nullptr;
    int _size = 0;

    // ### Constructors and Destructor ###000
public:
    ~Stack()
    {
        if(_head != nullptr)
            delete _head;
    }

    // ### Capacity ###

    bool empty() // Check if stack is empty
    {
        return (_head == nullptr);
    }

    int size() // Return number of item in the stack
    {
        return _size;
    }

    // ### Element access ###
    const T& top() const; // Access top element
    T& top();             // Access top element

    // ### Modifiers ###
    // emplace_top()                    // Construct and insert element at top
    void clear() // Clear the stack
    {
        if(_head != nullptr)
            delete _head;
        _head = nullptr;
        _size = 0;
    }

    // ### Stack Factions ###
    void push(const T& val); // Insert element at beginning
    void pop();              // Delete first element
    const T& peek() const    // Access top element
    {
        return top();
    }
    T& peek() // Access top element const
    {
        return top();
    }
};

//######################  Stack Implementation  ##########################

/**
 * push(...)
 * @brief Add a new value to front of list
 * @param val value to add to front of list
 * @return void
 */
template <typename T> void Stack<T>::push(const T& data)
{
    _head = new node(data, _head);
    _size++;
}

/**
 * pop()
 * @brief remove element from front of list
 * @param void
 * @return void
 */
template <typename T> void Stack<T>::pop()
{
    if(_head == nullptr)
        return;
    auto oldhead = _head;
    _head = oldhead->next;
    oldhead->next = nullptr;
    delete oldhead;
    _size--;
}

/**
 * top()
 * @brief return refrence to the top element of the stack
 * @param void
 * @return void
 */
template <typename T> T& Stack<T>::top()
{
    if(_head == nullptr)
        throw out_of_range(TOP_ERROR);
    else
        return _head->data;
}

} // endnamespace

#endif // _libeggStack_hpp_INCLUDED_