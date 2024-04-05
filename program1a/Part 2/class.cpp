//
// Created by 101061875 on 2/7/2024.
//

#include "class.h"

using namespace std;

sortedSingle symDifference(sortedSingle &list1, sortedSingle &list2)
{
    sortedSingle newList;
    sortedSingle::node* curr1 = list1.headptr;
    sortedSingle::node* curr2 = list2.headptr;

    while(curr1 != nullptr)
    {
        if(!member(list2, curr1->theItem))
            newList.insert(curr1->theItem);
        curr1 = curr1->next;
    }

    while(curr2 != nullptr)
    {
        if(!member(list1, curr2->theItem))
            newList.insert(curr2->theItem);
        curr2 = curr2->next;
    }

    return newList;
}

sortedSingle theDifference(sortedSingle &list1, sortedSingle &list2) {
    sortedSingle newList;
    sortedSingle::node* curr1 = list1.headptr;

    while (curr1 != nullptr) {
        if (!member(list2, curr1->theItem))
            newList.insert(curr1->theItem);
        curr1 = curr1->next;
    }

    return newList;
}
sortedSingle theIntersection(sortedSingle &list1, sortedSingle &list2) {
    sortedSingle newList;
    sortedSingle::node* curr1 = list1.headptr;
    sortedSingle::node* curr2 = list2.headptr;

    // Traverse both lists and find common elements
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->theItem < curr2->theItem) { // traverse curr1
            curr1 = curr1->next;
        } else if (curr1->theItem > curr2->theItem) { // traverse curr 2
            curr2 = curr2->next;
        } else { // the elements are equal so insert that bad boy in
            newList.insert(curr1->theItem);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    return newList;
}

sortedSingle theUnion(sortedSingle &list1, sortedSingle &list2) {
    sortedSingle newList;

    sortedSingle::node *curr1 = list1.headptr;
    sortedSingle::node *curr2 = list2.headptr;

    // Traverse both lists and insert unique elements into the new list
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->theItem < curr2->theItem) {
            newList.insert(curr1->theItem);
            curr1 = curr1->next;
        } else if (curr1->theItem > curr2->theItem) {
            newList.insert(curr2->theItem);
            curr2 = curr2->next;
        } else { // If current elements are equal, insert one and advance both pointers
            newList.insert(curr1->theItem);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    // If there are remaining elements in either list, insert them into the new list
    while (curr1 != nullptr) {
        newList.insert(curr1->theItem);
        curr1 = curr1->next;
    }

    while (curr2 != nullptr) {
        newList.insert(curr2->theItem);
        curr2 = curr2->next;
    }

    return newList;
}

bool member(sortedSingle& list, int data) {
    sortedSingle::node* current = list.headptr;
    while (current != nullptr) {
        if (current->theItem == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool isSubset(sortedSingle &list1, sortedSingle &list2){

    sortedSingle::node* curr = list1.headptr;
    while(curr != nullptr)
    {
        if(!member(list2, curr->theItem))
        {
            return false;
        }
        curr = curr->next;
    }

    return true;

}

bool areEqual(sortedSingle& list1, sortedSingle& list2) {

    sortedSingle::node* curr1 = list1.headptr;
    sortedSingle::node* curr2 = list2.headptr;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->theItem != curr2->theItem) { // compare nodes
            return false;
        }
        curr1 = curr1->next; // traverse
        curr2 = curr2->next;
    }

    if(curr1 != nullptr || curr2 != nullptr) // lists are not the same size
        return false;

    return true;
}


sortedSingle::sortedSingle() {
    headptr = nullptr;
}
sortedSingle::~sortedSingle() {
    node* ptr;
    for (ptr = headptr; headptr; ptr = headptr)
    {
        headptr = headptr->next;
        delete ptr;
    }
}



int sortedSingle::size()
{
    node* ptr = headptr;
    int count = 0;

    while (ptr != nullptr) {
        count++;
        ptr = ptr->next;
    }

    return count;
}

bool sortedSingle::insert(int item)
{
    node* temp = new (nothrow) node();
    node* current = headptr;
    node* prev = nullptr;

    if (temp == nullptr)
        return false;

    temp->theItem = item;

    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }

    current = headptr;

    if (item <= current->theItem)    // insert if empty and to replace first node
    {
        temp->next = headptr;
        headptr = temp;
        return true;
    }

    while (current != nullptr && current->theItem < item) // find the right location to insert
    {
        prev = current;
        current = current->next;
    }

    if (prev != nullptr)
    {
        prev->next = temp;
        if (current != nullptr)
            temp->next = current;
    }

    return true;
}

bool sortedSingle::remove(int item)
{
    node* ptr = headptr;
    node* prev = nullptr;

    while (ptr != nullptr)
    {
        if (ptr->theItem == item)
        {
            if (prev == nullptr)
                headptr = ptr->next;
            else
                prev->next = ptr->next;

            delete(ptr);
            return true;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    return false;
}

void sortedSingle::print(string seperator)
{
    node* ptr = headptr;
    std::cout << "{";
    while (ptr != nullptr)
    {
        std::cout << ptr->theItem;
        ptr = ptr->next;

        if (ptr != nullptr)
            std::cout << seperator;
    }
    std::cout << "}";
}



