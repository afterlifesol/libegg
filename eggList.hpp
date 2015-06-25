
//################################################ Header #######################################################
/**
 * @class LinkedList
 * @author afterlifesol
 * @date 05/06/15
 * @file EggCollection.cpp
 * @brief One way Dynamic Node based Linked List
 */
template <typename T>
class LinkedList
{

    private:

    // ### Internal Node struct ### // Implemented Inline
        struct Node {
            public:
                Node    *next = nullptr;
                T       data;
                Node(Node *next, T &data): next(next), data(data) {}
        };


    public:


    // ### Iterator ###  // Implemented Inline

        class Iter
        {
            protected:
                LinkedList *list;
                int index;

            public:
                Iter(LinkedList *list, int index): list(list), index(index) {}; 
                
                const T& operator*() const { return list->at(index); }
                
                T& operator*() { return list->at(index); }
                
                int operator++()
                    { if ( index < (list->Size()) ) index++; return index; }
                
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

    // ### Members ###

        Node *head = nullptr;
        int size = 0;

    public:

    // ### Constructors and Destructor ###

        ~LinkedList(); // Destructor (clean up all that dynamic memeory)

    // ### Method ###

        // # Stack Methods
            void Push(T data);              // Add data to the frount of List
            T    Pop();                     // Return data from front of list and removes from list (pop off)
            const T&   Peek() const;        // Return Ref to data ay the front of list (does NOT remove from list)
        
        void Push_Back(T data);             // Add data to the end of a List


        int Size() {return size;}           // Return how many modes are in the list

        const T& at(int index) const;       // return const Ref to the Data at index
        T& at(int index);                   // return Ref to the Data at index

        Iter begin() { return Iter(this,0); };
        Iter end()   { return Iter(this,size); };

    // ### Operators ###

        const T& operator[] (int index) const   // return const Ref to the Data at index
            { return at(index); }

        T& operator[] (int index)               // return Ref to the Data at index
            { return at(index); }
};


//################################################ Implementation #######################################################

/**
 * @brief Destructor
 */
template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * @brief Add new data to the front of List
 * @param data Data to store
 */
template <typename T>
void LinkedList<T>::Push(T data)
{
    head = new Node(head, data);
    size++;
}

/**
 * @brief Return data from front of list and removes from list (pop off)
 * @return Copy of the Data that was removed from front of list
 */
template <typename T>
T LinkedList<T>::Pop()
{
    if (head == nullptr) throw 0;
    Node *tp    = head;
    T data  = tp->data;
    head = head->next;
    size--;
    delete tp;
    return data;
}


/**
 * @brief Return data from front of list does NOT remove from list
 * @return Data at the top of the list
 */
template <typename T>
const T& LinkedList<T>::Peek() const
{
    if (head == nullptr) throw 0;
    return head->data;
}


template <typename T>
void LinkedList<T>::Push_Back(T data)
{
    if (head == nullptr)
    {
        head = new Node(head,data);
        size++;
        return;
    }
    Node *pTemp = head;
    while (pTemp->next != nullptr) pTemp = pTemp->next;
    pTemp->next = new Node(nullptr,data);
    size++;
}


/**
 * @brief return const Ref to the Data at index
 * @param index
 * @return const Reference to Data at index
 */
template <typename T>
const T& LinkedList<T>::at(int index) const
{
    if (index >= size) throw 0;

    Node *temp=head;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp->data;
}

/**
 * @brief return Ref to the Data at index
 * @param index
 * @return Reference to Data at index
 */
template <typename T>
T& LinkedList<T>::at(int index)
{
    if (index >= size) throw 0;

    Node *temp=head;
    for(int i=0;i<index;i++)
        temp=temp->next;
    return temp->data;
}
