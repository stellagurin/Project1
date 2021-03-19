#include <iostream>
using namespace std;
#include "UnsortedList.h"

template <class ItemType>
UnsortedList<ItemType>::UnsortedList()
// No argument constructor
// Post: Max_Items initialized to 50 and Length have been initialized.
// The array to hold the list elements has been allocated.
{
    Max_Items = 50;
    length = 0;
    info = new ItemType[Max_Items];
}


template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int max)
// Constructor
// Post: Max_Items and Length have been initialized.
// The array to hold the list elements has been allocated.
{
    Max_Items = max;
    length = 0;
    info = new ItemType[Max_Items];
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList()
// Class destructor
{
    delete[] info;
}

template <class ItemType>
void UnsortedList<ItemType>::makeEmpty()
// Post: Length has been reset to the empty state.
{
    length = 0;
}

template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const
// Returns true if the List is empty; false otherwise.
{
    if (length == 0)
        return true;
    else
        return false;
}

// define the remaining functions

template <class ItemType>
bool UnsortedList<ItemType>::isFull() const
// Returns true if the List is full; false otherwise.
{
    if (length == Max_Items) {
        return true;
    } else {
        return false;
    }
}

template <class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem)
// Post: If List is full, FullList exception is thrown
//       If item is already in the list DuplicateItem exception is thrown
//       else newItem is at end of the list.
{
    if (isFull()) {
        throw FullList();
    } else if (findIndex(newItem) != -1) {
        throw DuplicateItem();
    } else {
        info[length] = newItem;
        length++;
    }
}

template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType item)
// Post: If List is empty EmptyList exception is thrown
//       If item is not in the list an exception is thrown
//       else item is not in the list.
{
    if (findIndex(item) == -1) {
        throw ItemNotFound();
    } else if (isEmpty()) {
        throw EmptyList();
    }
    for (int i = findIndex(item); i < length - 1; i++) {
        info[i] = info[i + 1];
    }
    info[length - 1] = {};
    length--;
}

template <class ItemType>
int UnsortedList<ItemType>::getLength() const
// Returns the number of items in the list.
// Pre: List is initialized.
// Post: function value = the number of list elements
{
    return length;
}

template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index) const
// Returns the item stored at index in the list.
// Pre: List is initialized
// Post: If length-1 < index < 0 the OutofBound exception is thrown
//       else function value = element stored at index index in the list.
{
    if (length - 1 < index || index < 0) {
        throw OutofBound();
    } else {
        return info[index];
    }
}

template <class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item)
// Returns the index of element item.
// Pre: List is initialized
// Post: If item is in the list then function value = index of item.
//       If item is not in the list then -1 is returned
{
    for (int i = 0; i < length; i++) {
        if (item == info[i]) {
            return i;
        }
    }
    return -1;
}
