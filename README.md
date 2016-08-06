# libegg

	C++14 STD tools and data structures.

## eggList (eggList.hpp)

    LinkedList
        Simple Linked list (Single links) 
        Support for c++14's range based for looping
        Array style access syntax.

    template <typename T> class LinkedList
	
    *** Iterator ***

        Iter begin()                        // Return iterator to beginning
        Iter end()                          // Return iterator to end
        //rbegin()                          // Return reverse iterator to reverse beginning
        //rend()                            // Return reverse iterator to reverse end
        //cbegin()                          // Return const_iterator to beginning
        //cend()                            // Return const_iterator to end
        //crbegin()                         // Return const_reverse_iterator to reverse beginning
        //crend()                           // Return const_reverse_iterator to reverse end

    *** Capacity ***
        bool empty()                        // Test whether container is empty 
        int  size()                         // Return size 
        //int max_size();                   // Return maximum size

    *** Element access ***
        const value_type& front() const;    // Access first element
        value_type& front();                // Access first element

        const value_type& back() const;     // Access last element
        value_type& back();                 // Access last element

   *** Modifiers ***
        //assign                                 // Assign new content to container
        //emplace_front                          // Construct and insert element at beginning
        void push_front(const value_type& val);  // Insert element at beginning
        void pop_front();                        // Delete first element
        //emplace_back                           // Construct and insert element at the end
        void push_back(const value_type& val);   // Add element at the end
        void pop_back();                         // Delete last element
        //emplace                                // Construct and insert element
        //insert                                 // Insert elements
        //erase                                  // Erase elements
        //swap                                   // Swap content
        //resize                                 // Change size
        void clear()                             // Clear content

    *** Stack Factions ***
        void push(const value_type& val)            // Insert element at beginning
        void pop()                                  // Delete first element
        const value_type& peek() const              // Access top element

    *** Random Access Operators ***
        const value_type& at(int index) const;       // return const Ref to the Data at index
        value_type& at(int index);                   // return Ref to the Data at index

	*** Array Type [index] Operatiors ***
        const value_type& operator[] (int index) const   // return const Ref to the Data at index
        value_type& operator[] (int index)               // return Ref to the Data at index
        
    *** Expextions ***
		Will throw expections on out of index errors
	
    
## eggStack (eggStack.hpp)

    Stack
        Simple Stack Template 

    template <typename T> class Stack
    
    *** Capacity ***
        bool empty()                        // Check if stack is empty
        int size()                          // Return number of item in the stack

    *** Element access ***
        const T& top() const;               // Access top element
        T& top();                           // Access top element

    *** Modifiers ***
        // emplace_top()                    // Construct and insert element at top
        void clear()                        // Clear the stack

    *** Stack Factions ***
        void push(const T& val);            // Insert element at beginning
        void pop();                         // Delete first element
        const T& peek() const               // Access top element
        T& peek()                           // Access top element const

    *** Expextions ***
            Will throw expections on access of invalid top

    *** TODO ***
        Iters
            Support C++11/14's range based for
        emplace_top(*)

## eggList_Test (eggList_Test.cpp)
        Tests for LinkedList
        
## eggList_Stack (eggStack_Test.cpp)
        Tests for Stack
