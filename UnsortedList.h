#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H
#include<string>

class FullList {
};

class EmptyList
{};

class DuplicateItem
{};

class OutofBound
{};

class ItemNotFound
{};

template <class ItemType>
class UnsortedList
{
public:
	// Class constructors
	UnsortedList(); //initializes the array and initializes array size to 50
	UnsortedList(int);
	// Class destructor.
	~UnsortedList();
	// Function: makeEmpty initializes the list to an empty state.
	// Precondition: List is initialized.
	// Post: list is empty.
	void makeEmpty();
	// Function: isEmpty determines whether the list is empty.
	// Post: Function value = (list is empty)
	bool isEmpty() const;
	// Function: isFull determines whether the list is full.
	// Post: Function value = (list is full)
	bool isFull() const;
	// Function: Adds newItem to the end of the list.
	// Post: If (List is full) FullList exception is thrown
	//       If item is already in the list DuplicateItem exception is thrown
	//       else newItem is at end of the list.
	void putItem(ItemType newItem);
	// Function: deletes Item from the list.
	// Post: If List is empty EmptyList exception is thrown
	//       If item is not in the list an exception is thrown
	//       else newItem is not in the list.
	void deleteItem(ItemType Item);
	// Function: returns the number of items in the list
	// Pre: List is initialized
	// Post: function value = the number of list elements
	int getLength()const;
	// Function: returns the item stored at index in the list
	// Pre: List is inilialized
	// Post: if  length-1 < index < 0 the OutofBound exception is thrown
    	//	 else function value = element stored at index index in the list.

	ItemType getAt(int index) const;

private:
	ItemType* info;
	int Max_Items;
	int length;
	// Function: Returns the index of element item
  	// Pre: list is initialized
 	// Post: If item is in the list then function value =
	//       index of item.
	//       If item is not in the list -1 is returned
	int findIndex(ItemType item);
};


#endif
