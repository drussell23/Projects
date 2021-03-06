/**
    Derek J. Russell
    Professor Jonathan Traugott
    Anagram - (Assignment)
    CSCI 20 - Data Structures C++ - Spring 2018
    Chabot Community College
    Date: May 17th, 2018
    =================================================================================================
    Implement a Dictionary class to work with the attached tester program.

    Your Dictionary stores a map of key-value pairs where the key is a suitably stored bag of letters
    (e.g. a LetterBag object or a sorted string containing the letters) and the value is a set of words
    where each word contains exactly those letters.  The key-value pair is called an AnagramSet.

    For example: If the key is  "art"  then value might be {"art", "rat", "tar"}  i.e. a set of three
    words with the letter 'a', 'r' and 't'.  (Note "tart" wouldn't be in the set since it has a different key: "artt")

    The client can look up a string of letters in the dictionary and get back an AnagramSet object with that key.

    To make things easier, the client doesn't need to presort the lookup string since the Dictionary
    will automatically see it as a bag of letters, disregarding order (e.g. "rta" and "tra"
    would get back the same AnagramSet).

    To make this work, the dictionary will need a function makeKey that takes a string
    and generates the corresponding key (i.e. a LetterBag or sorted string depending
    on how you do it).

    You'll need to implement AnagramSet.  There is very little required by the tester in terms of
    public functions. Mainly you need to be able to output an AnagramSet object, test whether
    it's empty (i.e. no words found for a particular key). and get the size.

    One way to implement AnagramSet is a LetterBag object for the key and some data
    structure to hold a set of  strings (e.g. BST,  list,  array).

    For the Dictionary you should use a hash table as the underlying data structure.
    Use chaining rather than linear probing since our load factors will greatly
    exceed 1 in some of the tests.

    Write everything from scratch. That means you aren't allowed to use any
    STL container data structures, including map, multimap, hash_map, list, vector etc.

    Exception: you may use the built in string data type.

    Notice that we overload the stream insertion operator for both AnagramSet and Dictionary.

    For AnagramSet, you should output both the key and the set of associated words (e.g. aet: { eat, tea }).

    I output the Dictionary in a slightly odd format to manifest its underlying structure in the hash table.
    That means you will see more than one AnagramSet per line (exclosed in braces) whenever a collision
    occurred (i.e. both AnagramSets mapped to the same hash index). You don't need to duplicate this output
    format. Your output will look different in terms of the order of entries in the hash table since that
    depends on the particular hash function.

    I didn't provide header files for Dictionary or AnagramSet. You can deduce constructor and function
    prototypes from the calls in tester.cpp. Notice we can specify the "table size" for the Dictionary.
    That should correspond to the size of your underlying hash table. Big file sizes with small hash table
    size is a stress test for your implementation. Times are provided as an indicator of the efficiency
    you're shooting for.
**/
#ifndef OLIST_H
#define OLIST_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

template <class T>
class OList
{
    private:

        struct Node
        {
            T data;     // Holds the actual data
            Node *next; // Points to the address of next NODE
        };

        // Pointer head and tail are to help imitate an array;
        Node dummyhead; // Points to the head node
        Node* tail; // Points to the last node which is a NULL
        int size;

        // Traverse until the node before larger data
        Node *findInsertPoint(Node *iterator, const T &data)			      // Return a pointer to the Node that val should be inserted after.
        {																	  // Can also be used by remove() to look for an occurrence of val,
            while ((iterator->next != NULL) && (iterator->next->data < data)) // Also, consider using it for by operator+=.
            {                                                                 // pre represents a node where we start the search.
                iterator = iterator->next;
            }
            return iterator;
        }

        // Return the address of last node with the same value
        Node *findLastOccurrance(Node *iterator, const T &data)
        {
            while ((iterator->next != NULL) && (iterator->next->data == data))
            {
                iterator = iterator->next;
            }
            return iterator;
        }
        void sorted_insert(T temp, Node *current, Node *prev);

    public:
        friend ostream& operator<<(ostream & out, const OList<T> &n)
        {
            Node* temp = n.dummyhead.next;
            cout << "{ " << flush;
            while (temp != NULL)
            {
                out << temp->data << flush;
                temp = temp->next;
                if (temp != NULL)
                    cout << ", " << flush;
            }
            cout << " }" << flush;
            return out;
        }

        OList();                                     // Default Constructor
        OList(const T data[], const int &size);	     // Normal Constructor
        OList(const OList &copy);				     // Copy Constructor
        ~OList();                                    // Deconstructor
        OList &operator=(const OList<T> &rhs);	     // If self assignment ignore; do not copy
        OList operator+(const OList &rhs) const;
        OList operator+=(const OList &rhs);		     // To merge lists do not call += repeatedly
        T getSmallest() const;					     // Might be called on an empty list. In that case the
        T getBiggest() const;					     // function throws logic_error exception with a suitable message
        int find(const T &data) const;			     // Returns the head occurence of the object; If not found return -1
        int getSize() const;
        bool operator==(const OList &rhs) const;
        bool operator!=(const OList &rhs) const;
        bool isEmpty() const;
        void insert(const T &data);				     // Insert new node in order
        void print(ostream & out) const;
        void printBackwards() const;		         // Use recursion
        void printBHelper(Node* n) const;		     // Traverse to tail and print as unwined
        void clear();							     // Remove all nodes
        void remove(const T &data);	       		     // Default: Remove all occurences; If a second argument
        void remove(const T &data, const bool &arg);
        void removeSmallest();
};

template <class T>
OList<T>::OList()
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;
}// Default Constructor
template <class T>
OList<T>::OList(const T data[], const int &arrSize) // Normal Constructor
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;

	for (int i = 0; i < arrSize; i++)
		insert(data[i]);
}
template <class T>
OList<T>::OList(const OList &copy) // Copy Constructor
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;
	*this = copy;
}
template <class T> // Deconstructor
OList<T>::~OList()
{clear();}
template <class T>
OList<T>& OList<T>::operator=(const OList<T> &rhs)
{
	// Do not copy if there is nothing to copy
	if (this == &rhs/* || rhs.isEmpty()*/)
	{
		//cout << "Self assignment/Empty assignment ignored " << endl;
		return (*this); // Returns list not the address bc of return type
	}
	if( rhs.isEmpty() )
	{
	    clear();
	    return (*this);
	}
	clear(); // Empty the lhs for easier copy; No NULL problems

	Node *rhsTemp = rhs.dummyhead.next;
	Node *temp = NULL;
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->data = rhsTemp->data;
	dummyhead.next = new_node;
	tail = new_node;
	rhsTemp = rhsTemp->next;
	size++;
	temp = dummyhead.next;
	// Copy to the end of the List not Tail
	if (rhs.getSize() > 2)
	{
		while (rhsTemp->next != NULL)
		{
			new_node = new Node;
			new_node->next = NULL;
			new_node->data = rhsTemp->data;

			temp->next = new_node;
			temp = new_node;

			rhsTemp = rhsTemp->next;
			size++;
		}
		new_node = new Node;
		new_node->next = NULL;
		new_node->data = rhsTemp->data;

		temp->next = new_node;
		tail = temp->next;
		size++;
	}
	return (*this);
}
template <class T>
OList<T> OList<T>::operator+(const OList &rhs) const
{
	OList temp = *this;
	temp += rhs;
	return (temp);
}
template <class T>
OList<T> OList<T>::operator+=(const OList &rhs)
{
	Node * ADD = rhs.dummyhead.next;
	while(ADD != NULL)
    {
        insert(ADD->data);
        ADD = ADD->next;
    }
    return (*this);
}
template <class T>
T OList<T>::getSmallest() const
{
   if(isEmpty())
   {
        throw logic_error("Empty Linked List.");
   }
        Node *p = dummyhead.next;
        T smallest = p->data;
        while(p != NULL)
        {
            if(p->data < smallest)
            smallest = p->data;
            p = p->next;
        }
            return (smallest);
}
template <class T>
T OList<T>::getBiggest() const
{
    if (isEmpty())
    {
        throw logic_error("Empty Linked List.");
    }
                Node *p = dummyhead.next;
                T biggest = p->data;
                while(p != NULL)
                {
                    if(p->data > biggest)
                        biggest = p->data;
                    p = p->next;
                }
                return (biggest);
}
template <class T>
bool OList<T>::operator==(const OList &rhs) const
{
	if (getSize() != rhs.getSize())
		return (0);
	Node *lhsTemp = dummyhead.next;
	Node *rhsTemp = rhs.dummyhead.next;
	while (lhsTemp != NULL && rhsTemp != NULL)
	{
		if (rhsTemp->data != lhsTemp->data)
			return (0);
		lhsTemp = lhsTemp->next;
		rhsTemp = rhsTemp->next;
	}
	return (1);
}
template <class T>
bool OList<T>::operator!=(const OList &rhs) const
{
	return (!(*this == rhs));
}
template <class T>
int OList<T>::find(const T &data) const
{
	int position = 0;
	Node* temp = dummyhead.next;
	while (temp != NULL && data != temp->data)
	{
		position++;
		temp = temp->next;
	}
	if (temp == NULL)
		return (-1);
	return (position);
}
template <class T>
int OList<T>::getSize() const
{
	return size;
}
template<class T>
bool OList<T>::isEmpty() const
{return size == 0;}
template <class T>
void OList<T>::insert(const T &data)
{
	Node* curr = dummyhead.next; // Lead Node address increments as per argument
	Node* temp = new Node; // New Node holds new data
	(temp->data) = data;

	if ((dummyhead.next == NULL) || (temp->data) <= (dummyhead.next)->data)
	{
		temp->next = dummyhead.next;
		dummyhead.next = temp;
		size++;
	}
	else
	{
		curr = findInsertPoint(curr, data);
		temp->next = curr->next;
		curr->next = temp;
		size++;
	}
	curr = dummyhead.next;
	while (curr->next != NULL)
		curr = curr->next;
	tail = curr;
}
template <class T>
void OList<T>::print(ostream & out) const
{
	Node* temp = dummyhead.next;
	out << "{ " << flush;
	while (temp != NULL)
	{
		out << temp->data << flush;
		temp = temp->next;
		if (temp != NULL)
			out << ", " << flush;
	}
	out << " }" << endl;
}
template <class T>
void OList<T>::removeSmallest()
{
    Node *deletion = dummyhead.next;
    deletion = dummyhead.next;
    dummyhead.next = deletion->next;
    delete deletion;
}
template <class T>
void OList<T>::printBackwards() const
{
	cout << "{ ";
	printBHelper(dummyhead.next);
	cout << " }" << endl;
}
template <class T>
void OList<T>::printBHelper(Node* n) const
{
	if (n != NULL)
	{
		printBHelper(n->next);
		cout << n->data << flush;
		if (n != dummyhead.next)
			cout << ", " << flush;
	}
}
template<class T>
void OList<T>::clear()
{
	Node *temp;
	while (dummyhead.next != NULL)
	{
		temp = dummyhead.next;
		dummyhead.next = (dummyhead.next)->next;
		delete temp;
	}
	dummyhead.next = NULL;
	tail = NULL;
	size = 0;
}
template<class T>
void OList<T>::remove(const T &data)
{
	int count = 0;
	Node *temp = dummyhead.next;
	while (temp != NULL)
	{
		if (temp->data == data)
			count++;
		temp = temp->next;
	}
	for (int i = 0; i < count; i++)
		remove(data, false);
}
template<class T>
void OList<T>::remove(const T &data, const bool &arg)
{
	if (dummyhead.next == NULL)
		return;
	if (arg == false)
	{
		int position = find(data);
		Node* temp = dummyhead.next;
		Node* curr;
		if (position == 0)
		{
			dummyhead.next = temp->next;
			delete temp;
			size--;
		}
		temp = findInsertPoint(temp, data);
		if (getSize() - 1 == position)
		{
			tail = temp;
			temp->next = NULL;
			size--;
		}
		curr = (temp->next->next);
		delete temp->next;
		temp->next = curr;
		size--;
	}
	if (arg == true)
		remove(data);
}
template <class T>
void OList<T>::sorted_insert(T temp, Node *current, Node *prev)
{
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->data = temp;

	if (current == dummyhead.next && current->next == NULL && temp <= current->data)
	{
		dummyhead.next = new_node;
		dummyhead.next = current;
		tail = current;
	}
	else if (current == dummyhead.next && temp <= current->data)
	{
		dummyhead.next = new_node;
		dummyhead.next = current;
	}
	else if (current->data <= temp && current->next == NULL)
	{
		current->next = new_node;
		new_node->next = NULL;
		tail = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}
	++size;
}
#endif // OLIST_H
#pragma once

#ifndef OLIST_H
#define OLIST_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

template <class T>
class OList
{
    private:

        struct Node
        {
            T data;     // Holds the actual data
            Node *next; // Points to the address of next NODE
        };

        // Pointer head and tail are to help imitate an array;
        Node dummyhead; // Points to the head node
        Node* tail; // Points to the last node which is a NULL
        int size;

        // Traverse until the node before larger data
        Node *findInsertPoint(Node *iterator, const T &data)			      // Return a pointer to the Node that val should be inserted after.
        {																	  // Can also be used by remove() to look for an occurrence of val,
            while ((iterator->next != NULL) && (iterator->next->data < data)) // Also, consider using it for by operator+=.
            {                                                                 // pre represents a node where we start the search.
                iterator = iterator->next;
            }
            return iterator;
        }

        // Return the address of last node with the same value
        Node *findLastOccurrance(Node *iterator, const T &data)
        {
            while ((iterator->next != NULL) && (iterator->next->data == data))
            {
                iterator = iterator->next;
            }
            return iterator;
        }
        void sorted_insert(T temp, Node *current, Node *prev);

    public:
        friend ostream& operator<<(ostream & out, const OList<T> &n)
        {
            Node* temp = n.dummyhead.next;
            cout << "{ " << flush;
            while (temp != NULL)
            {
                out << temp->data << flush;
                temp = temp->next;
                if (temp != NULL)
                    cout << ", " << flush;
            }
            cout << " }" << flush;
            return out;
        }

        OList();                                     // Default Constructor
        OList(const T data[], const int &size);	     // Normal Constructor
        OList(const OList &copy);				     // Copy Constructor
        ~OList();                                    // Deconstructor
        OList &operator=(const OList<T> &rhs);	     // If self assignment ignore; do not copy
        OList operator+(const OList &rhs) const;
        OList operator+=(const OList &rhs);		     // To merge lists do not call += repeatedly
        T getSmallest() const;					     // Might be called on an empty list. In that case the
        T getBiggest() const;					     // function throws logic_error exception with a suitable message
        int find(const T &data) const;			     // Returns the head occurence of the object; If not found return -1
        int getSize() const;
        bool operator==(const OList &rhs) const;
        bool operator!=(const OList &rhs) const;
        bool isEmpty() const;
        void insert(const T &data);				     // Insert new node in order
        void print(ostream & out) const;
        void printBackwards() const;		         // Use recursion
        void printBHelper(Node* n) const;		     // Traverse to tail and print as unwined
        void clear();							     // Remove all nodes
        void remove(const T &data);	       		     // Default: Remove all occurences; If a second argument
        void remove(const T &data, const bool &arg);
        void removeSmallest();
};

template <class T>
OList<T>::OList()
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;
}// Default Constructor
template <class T>
OList<T>::OList(const T data[], const int &arrSize) // Normal Constructor
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;

	for (int i = 0; i < arrSize; i++)
		insert(data[i]);
}
template <class T>
OList<T>::OList(const OList &copy) // Copy Constructor
{
    size = 0;
    tail = &dummyhead;
    dummyhead.next = NULL;
	*this = copy;
}
template <class T> // Deconstructor
OList<T>::~OList()
{clear();}
template <class T>
OList<T>& OList<T>::operator=(const OList<T> &rhs)
{
	// Do not copy if there is nothing to copy
	if (this == &rhs/* || rhs.isEmpty()*/)
	{
		//cout << "Self assignment/Empty assignment ignored " << endl;
		return (*this); // Returns list not the address bc of return type
	}
	if( rhs.isEmpty() )
	{
	    clear();
	    return (*this);
	}
	clear(); // Empty the lhs for easier copy; No NULL problems

	Node *rhsTemp = rhs.dummyhead.next;
	Node *temp = NULL;
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->data = rhsTemp->data;
	dummyhead.next = new_node;
	tail = new_node;
	rhsTemp = rhsTemp->next;
	size++;
	temp = dummyhead.next;
	// Copy to the end of the List not Tail
	if (rhs.getSize() > 2)
	{
		while (rhsTemp->next != NULL)
		{
			new_node = new Node;
			new_node->next = NULL;
			new_node->data = rhsTemp->data;

			temp->next = new_node;
			temp = new_node;

			rhsTemp = rhsTemp->next;
			size++;
		}
		new_node = new Node;
		new_node->next = NULL;
		new_node->data = rhsTemp->data;

		temp->next = new_node;
		tail = temp->next;
		size++;
	}
	return (*this);
}
template <class T>
OList<T> OList<T>::operator+(const OList &rhs) const
{
	OList temp = *this;
	temp += rhs;
	return (temp);
}
template <class T>
OList<T> OList<T>::operator+=(const OList &rhs)
{
	Node * ADD = rhs.dummyhead.next;
	while(ADD != NULL)
    {
        insert(ADD->data);
        ADD = ADD->next;
    }
    return (*this);
}
template <class T>
T OList<T>::getSmallest() const
{
   if(isEmpty())
   {
        throw logic_error("Empty Linked List.");
   }
        Node *p = dummyhead.next;
        T smallest = p->data;
        while(p != NULL)
        {
            if(p->data < smallest)
            smallest = p->data;
            p = p->next;
        }
            return (smallest);
}
template <class T>
T OList<T>::getBiggest() const
{
    if (isEmpty())
    {
        throw logic_error("Empty Linked List.");
    }
                Node *p = dummyhead.next;
                T biggest = p->data;
                while(p != NULL)
                {
                    if(p->data > biggest)
                        biggest = p->data;
                    p = p->next;
                }
                return (biggest);
}
template <class T>
bool OList<T>::operator==(const OList &rhs) const
{
	if (getSize() != rhs.getSize())
		return (0);
	Node *lhsTemp = dummyhead.next;
	Node *rhsTemp = rhs.dummyhead.next;
	while (lhsTemp != NULL && rhsTemp != NULL)
	{
		if (rhsTemp->data != lhsTemp->data)
			return (0);
		lhsTemp = lhsTemp->next;
		rhsTemp = rhsTemp->next;
	}
	return (1);
}
template <class T>
bool OList<T>::operator!=(const OList &rhs) const
{
	return (!(*this == rhs));
}
template <class T>
int OList<T>::find(const T &data) const
{
	int position = 0;
	Node* temp = dummyhead.next;
	while (temp != NULL && data != temp->data)
	{
		position++;
		temp = temp->next;
	}
	if (temp == NULL)
		return (-1);
	return (position);
}
template <class T>
int OList<T>::getSize() const
{
	return size;
}
template<class T>
bool OList<T>::isEmpty() const
{return size == 0;}
template <class T>
void OList<T>::insert(const T &data)
{
	Node* curr = dummyhead.next; // Lead Node address increments as per argument
	Node* temp = new Node; // New Node holds new data
	(temp->data) = data;

	if ((dummyhead.next == NULL) || (temp->data) <= (dummyhead.next)->data)
	{
		temp->next = dummyhead.next;
		dummyhead.next = temp;
		size++;
	}
	else
	{
		curr = findInsertPoint(curr, data);
		temp->next = curr->next;
		curr->next = temp;
		size++;
	}
	curr = dummyhead.next;
	while (curr->next != NULL)
		curr = curr->next;
	tail = curr;
}
template <class T>
void OList<T>::print(ostream & out) const
{
	Node* temp = dummyhead.next;
	out << "{ " << flush;
	while (temp != NULL)
	{
		out << temp->data << flush;
		temp = temp->next;
		if (temp != NULL)
			out << ", " << flush;
	}
	out << " }" << endl;
}
template <class T>
void OList<T>::removeSmallest()
{
    Node *deletion = dummyhead.next;
    deletion = dummyhead.next;
    dummyhead.next = deletion->next;
    delete deletion;
}
template <class T>
void OList<T>::printBackwards() const
{
	cout << "{ ";
	printBHelper(dummyhead.next);
	cout << " }" << endl;
}
template <class T>
void OList<T>::printBHelper(Node* n) const
{
	if (n != NULL)
	{
		printBHelper(n->next);
		cout << n->data << flush;
		if (n != dummyhead.next)
			cout << ", " << flush;
	}
}
template<class T>
void OList<T>::clear()
{
	Node *temp;
	while (dummyhead.next != NULL)
	{
		temp = dummyhead.next;
		dummyhead.next = (dummyhead.next)->next;
		delete temp;
	}
	dummyhead.next = NULL;
	tail = NULL;
	size = 0;
}
template<class T>
void OList<T>::remove(const T &data)
{
	int count = 0;
	Node *temp = dummyhead.next;
	while (temp != NULL)
	{
		if (temp->data == data)
			count++;
		temp = temp->next;
	}
	for (int i = 0; i < count; i++)
		remove(data, false);
}
template<class T>
void OList<T>::remove(const T &data, const bool &arg)
{
	if (dummyhead.next == NULL)
		return;
	if (arg == false)
	{
		int position = find(data);
		Node* temp = dummyhead.next;
		Node* curr;
		if (position == 0)
		{
			dummyhead.next = temp->next;
			delete temp;
			size--;
		}
		temp = findInsertPoint(temp, data);
		if (getSize() - 1 == position)
		{
			tail = temp;
			temp->next = NULL;
			size--;
		}
		curr = (temp->next->next);
		delete temp->next;
		temp->next = curr;
		size--;
	}
	if (arg == true)
		remove(data);
}
template <class T>
void OList<T>::sorted_insert(T temp, Node *current, Node *prev)
{
	Node *new_node = new Node;
	new_node->next = NULL;
	new_node->data = temp;

	if (current == dummyhead.next && current->next == NULL && temp <= current->data)
	{
		dummyhead.next = new_node;
		dummyhead.next = current;
		tail = current;
	}
	else if (current == dummyhead.next && temp <= current->data)
	{
		dummyhead.next = new_node;
		dummyhead.next = current;
	}
	else if (current->data <= temp && current->next == NULL)
	{
		current->next = new_node;
		new_node->next = NULL;
		tail = new_node;
	}
	else
	{
		prev->next = new_node;
		new_node->next = current;
	}
	++size;
}
#endif
#pragma once
