#ifndef _eggList_hpp_INCLUDED_
#define _eggList_hpp_INCLUDED_

//#include <exception>
#include <stdexcept>

using std::out_of_range;
using std::invalid_argument;

//################################################ Header #######################################################
/**
 * @class LinkedList
 * @author afterlifesol
 * @date 05/06/15
 * @file EggCollection.cpp
 * @brief One way Dynamic Node based Linked List
 */
template <typename value_type>
class LinkedList
{
    private:
    // ### Internal Node class ### -- Implemented Inline
        struct node {
            public:
            node *next = nullptr;
            node *prev = nullptr;
            value_type val;
            node(const value_type& val, node *next, node *prev): val(val), next(next), prev(prev) {}
        };

    // ### Iterator ### -- Implemented Inline
    public: 
        class Iter
        {
            protected:
                LinkedList *list;
                int index;

            public:
                Iter(LinkedList *list, int index): list(list), index(index) {}; 
                
                const value_type& operator*() const { return list->at(index); }
                
                value_type& operator*() { return list->at(index); }
                
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

    private:
    // ### Private Member Values ###
        node *head = nullptr;  //poitner to first element
        node *tail = nullptr;  //pointer to last element
        int nodes = 0; //number of elements in list

    public:
    // ### Constructors and Destructor ###
        //(constructor) //Construct list
        ~LinkedList() { clear(); } //List destructor
        //operator= //Assign content

    // ### Iterators ###
        Iter begin() { return Iter(this,0); }       // Return iterator to beginning
        Iter end()   { return Iter(this,nodes); }    // Return iterator to end
        //rbegin()    // Return reverse iterator to reverse beginning
        //rend()      // Return reverse iterator to reverse end
        //cbegin()    // Return const_iterator to beginning
        //cend()      // Return const_iterator to end
        //crbegin()   // Return const_reverse_iterator to reverse beginning
        //crend()     // Return const_reverse_iterator to reverse end

    // ### Capacity ###
        bool empty()    { return (0 == nodes); }        // Test whether container is empty 
        int  size()     { return nodes; }           // Return size 
        //int max_size();     // Return maximum size

    // ### Element access ###
        const value_type& front() const; // Access first element
        value_type& front(); // Access first element

        const value_type& back() const; // Access last element
        value_type& back();  // Access last element

    // ### Modifiers ###
        //assign                                // Assign new content to container
        //emplace_front                         // Construct and insert element at beginning
        void push_front(const value_type& val);  // Insert element at beginning
        void pop_front();                       // Delete first element
        //emplace_back                          // Construct and insert element at the end
        void push_back(const value_type& val);   // Add element at the end
        void pop_back();                        // Delete last element
        //emplace                               // Construct and insert element
        //insert                                // Insert elements
        //erase                                 // Erase elements
        //swap                                  // Swap content
        //resize                                // Change size
        void clear() noexcept;                  // Clear content

    // ### Stack Factions ###
        void push(const value_type& val) { push_front(val); }      // Insert element at beginning
        void pop() { pop_front(); }                             // Delete first element
        const value_type& peek() const { return front(); }      // Access top element

    // ### Sort Style Operations ###
        //splice // Transfer elements from list to list
        //remove // Remove elements with specific value
        //remove_if // Remove elements fulfilling condition (public member function template )
        //unique // Remove duplicate values
        //merge // Merge sorted lists
        //sort // Sort elements in container
        //reverse // Reverse the order of elements

    // ### Operators and support ###
    
        const value_type& at(int index) const;       // return const Ref to the Data at index
        value_type& at(int index);                   // return Ref to the Data at index

        const value_type& operator[] (int index) const   // return const Ref to the Data at index
            { return at(index); }

        value_type& operator[] (int index)               // return Ref to the Data at index
            { return at(index); }

    // #### DEBUG 
        void consistency_test();
};


//################################################ Implementation #######################################################



/**
 * clear()
 * @brief clears the list and frees memory
 * @param void
 * @return void
 */
template <typename value_type>
void LinkedList<value_type>::clear() noexcept
{
    if (head == nullptr) return;
    node *temp = head;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
    nodes = 0;   
}



/**
 * push_front(*)
 * @brief Add a new value to front of list
 * @param val value to add to front of list
 * @return void
 */
template <typename value_type>
void LinkedList<value_type>::push_front(const value_type& val)
{
    if (head == nullptr) head = tail = new node(val, nullptr, nullptr);
        else head = head->prev = new node(val,head,nullptr);
    nodes++;
}



/**
 * push_back(*)
 * @brief Add a new value to back of list
 * @param val value to add to back of list
 * @return void
 */
template <typename value_type>
void LinkedList<value_type>::push_back(const value_type& val)
{
    if (tail == nullptr) tail = head = new node(val, nullptr, nullptr);
        else tail = tail->next = new node(val, nullptr, tail);
    nodes++;
}



/**
 * pop_front()
 * @brief remove element from front of list
 * @param void
 * @return void
 */
template <typename value_type>
void LinkedList<value_type>::pop_front()
{
    if (head == nullptr) return;
    
    
    node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    nodes--;
   
}



/**
 * pop_back()
 * @brief remove element from back of list
 * @param void
 * @return void
 */
template <typename value_type>
void LinkedList<value_type>::pop_back()
{
    if (tail == nullptr) return;
    node *temp = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
    nodes--;
}



/**
 * const front()
 * @brief Return a refence to the front of list
 * @return Refence to the element at front of the list
 */
template <typename value_type>
const value_type& LinkedList<value_type>::front() const
{
    if (head == nullptr) throw out_of_range("Attempted to peek() an empty list");
    return head->val;
}


/**
 * front()
 * @brief Return a refence to the front of list
 * @return Refence to the element at front of the list
 */
template <typename value_type>
value_type& LinkedList<value_type>::front()
{
    if (head == nullptr) throw out_of_range("Attempted to peek() an empty list");
    return head->val;
}



/**
 * const back()
 * @brief Return a refence to the back of list
 * @return Refence to the element at back of the list
 */
template <typename value_type>
const value_type& LinkedList<value_type>::back() const
{
    if (tail == nullptr) throw out_of_range("Attempted to peek() an empty list");
    return tail->val;
}



/**
 * back()
 * @brief Return a refence to the back of list
 * @return Refence to the element at back of the list
 */
template <typename value_type>
value_type& LinkedList<value_type>::back()
{
    if (tail == nullptr) throw out_of_range("Attempted to peek() an empty list");
    return tail->val;
}



/**
 * const at(index)
 * @brief returns const refence to the Value at index in list in list
 * @param index
 * @return const refence to the Value at index in list
 */
template <typename value_type>
const value_type& LinkedList<value_type>::at(int index) const
{
    //index is zero based if nodes = 1 it's index = 0;
    //      Therfor last_index = nodes -1; 
    if (index >= nodes) throw out_of_range("Attempted to access invalid index in list");

    node *temp=head;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp->val;
}



/**
 * at(index)
 * @brief returns refence to the Value at index in list in list
 * @param index
 * @return refence to the Value at index in list
 */
template <typename value_type>
value_type& LinkedList<value_type>::at(int index)
{
    //index is zero based if nodes = 1 it's index = 0;
    //      Therfor last_index = nodes -1; 
    if (index >= nodes) throw out_of_range("Attempted to access invalid index in list");

    node *temp=head;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp->val;
}

#endif // _eggList_hpp_INCLUDED_
