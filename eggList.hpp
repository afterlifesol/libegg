
//############################## NOTES ################################

/*
*#ifndef __cplusplus
*#error A C++ compiler is required!
*#endif 
*/

/*
 * Predefined macro names
 * __LINE__	Integer value representing the current line in the source code file being compiled.
 * __FILE__	A string literal containing the presumed name of the source file being compiled.
 * __DATE__	A string literal in the form "Mmm dd yyyy" containing the date in which the compilation process began.
 * __TIME__	A string literal in the form "hh:mm:ss" containing the time at which the compilation process began.

 * #pragma message string
 * 		Prints string as a compiler message on compilation. The message is informational only, and is neither a compilation warning nor an error.

 */




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
	public:
		
	// ### Internal Node class ###
		struct Node {
				Node 	*next = nullptr;
				T		data;
				Node(Node *next, T &data): next(next), data(data) {}
		};
		
		
	// ### Iterator ###
		
		class Iter
		{
			protected:
				LinkedList *list;
				int index;
				
			public:
				Iter(LinkedList *list, int index): list(list), index(index) {};
				
				const T& operator*() const
				{ return list->at(index); }

				T& operator*()
				{ return list->at(index); }
				
				int operator++()
				{ if ( index < (list->getSize()) ) index++; return index; }
				
				bool operator==( const Iter &rhs)
				{ return ! operator!=(rhs);	}
				
				bool operator!=( const Iter &rhs)
				{
					if ( list != rhs.list ) return true;
					if (index != rhs.index) return true;
					return false;
				}
		};

	
	protected:

	// ### Members ###

		Node *head = nullptr;
		int size = 0;
	
	public:
	
	// ### Constructors and Destructor ###

		~LinkedList(); // Destructor (clean up all that dynamic memeory)
		
	// ### Methods ###

		void Push(T data); 	// Add new data to the frount of List
		T 	 Pop();			// Return data from front of list and removes from list (pop off)
		T& 	 Peek();		// Return Ref to data ay the front of list (does NOT remove from list)
		
		int getSize() {return size;} // Return how many modes are in the list
		
		const T& at(int index) const; // return const Ref to the Data at index
		T& at(int index); // return Ref to the Data at index

		Iter begin() { return Iter(this,0); };
		Iter end() 	 { return Iter(this,size); };

	// ### Operators ###

		const T& operator[] (int index) const // return const Ref to the Data at index
		{ return at(index); }

		T& operator[] (int index) // return Ref to the Data at index
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
	Node *tp	= head;
	T data	= tp->data;
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
T& LinkedList<T>::Peek()
{
	if (head == nullptr) throw 0;
	return head->data;
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
