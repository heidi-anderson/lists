//
// Created by 101061875 on 2/12/2024.
//

#include "linkedLists.h"

void insertList(nodePtr temp, nodePtr &headptr) {
    nodePtr curr;
    nodePtr prev;

    if(headptr == nullptr) {
        headptr = temp;
        return;
    }
    if(temp-> num < headptr-> num) {
        temp -> next = headptr;
        headptr = temp;
        return;
    }

    prev = headptr;
    curr = headptr;

    while((curr != nullptr) && (curr->num < temp->num)) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = temp;
    temp->next = curr;
}

// Delete
void deleteNodeList(nodeType temp_num, nodePtr &headptr) {
    nodePtr curr;
    nodePtr prev;

    prev = headptr;
    curr = headptr;

    while((curr != nullptr) && (curr->num != temp_num)) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == nullptr){
        std::cout << "Number not in list" << std::endl;
        return;
    }
    if(curr == headptr)
        headptr = curr->next;
    else
        prev->next = curr->next;
    delete(curr);
}

// Find Node
bool memberList(nodeType num, nodePtr headptr, nodePtr &location) {
    nodePtr curr = headptr;
    location = nullptr; // Reset location

    while (curr != nullptr) {
        if (curr->num == num) {
            location = curr;
            return true;
        }
        curr = curr->next;
    }

    return false;
}

void printList(nodePtr headptr) {
    nodePtr tmp;

    tmp = headptr;
    cout << "{";
    while(tmp != nullptr) {
        std::cout << tmp->num;
        tmp = tmp->next;
        if(tmp != nullptr)
            cout << ",";
    }
    cout << "}";
    std::cout << std::endl;
    std::cout << std::endl;
}

int sizeList(nodePtr headptr)
{
    nodePtr tmp;
    tmp = headptr;
    int count = 0;

    while(tmp != nullptr)
    {
        count++;
        tmp = tmp->next;
    }

    return count;
}

bool subsetList(nodePtr head1, nodePtr head2, nodePtr &location)
{
    nodePtr curr = head1;
    while(curr != nullptr)
    {
        memberList(curr->num, head2, location);
        if(location == nullptr)
            return false;
        curr = curr->next;
    }
    return true;
}

bool areEqualLists(nodePtr head1, nodePtr head2)
{
    nodePtr curr1 = head1;
    nodePtr curr2 = head2;

    while(curr1 != nullptr && curr2 != nullptr)
    {
        if(curr1->num != curr2->num)
            return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    if(curr1 != nullptr || curr2 != nullptr)
        return false;
    return true;
}

nodePtr theUnionLists(nodePtr head1, nodePtr head2) {
    nodePtr newHead = nullptr;
    nodePtr curr1 = head1;
    nodePtr curr2 = head2;
    nodePtr location;
    while (curr1 != nullptr) {
        insertList(new nodeRec{curr1->num, nullptr}, newHead);
        curr1 = curr1->next;
    }

    while (curr2 != nullptr) {
        location = nullptr;
        memberList(curr2->num, newHead, location);
        if(location == nullptr)
            insertList(new nodeRec{curr2->num, nullptr}, newHead);
        curr2 = curr2->next;
    }

    return newHead;
}

nodePtr theIntersectionList(nodePtr head1, nodePtr head2)
{
    nodePtr newHead = nullptr;
    nodePtr curr1 = head1;
    nodePtr curr2 = head2;

    while(curr1 != nullptr && curr2 != nullptr)
    {
        if(curr1->num < curr2->num)
            curr1 = curr1->next;
        else if(curr1->num > curr2->num)
            curr2 = curr2->next;
        else
        {
            insertList(new nodeRec{curr1->num, nullptr}, newHead);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }

    return newHead;
}

nodePtr theDifferenceList(nodePtr head1, nodePtr head2)
{
    nodePtr newHead = nullptr;
    nodePtr curr = head1;
    nodePtr location = nullptr;
    while(curr != nullptr)
    {
        memberList(curr->num, head2, location);
        if(location == nullptr)
            insertList(new nodeRec{curr->num, nullptr}, newHead);
        curr = curr->next;

    }
    return newHead;
}

nodePtr symDifferenceList(nodePtr head1, nodePtr head2) {
    nodePtr newHead = nullptr;
    nodePtr curr1 = head1;
    nodePtr curr2 = head2;
    nodePtr location = nullptr;

    while (curr1 != nullptr) {
        memberList(curr1->num, head2, location);
        if (location == nullptr) // if it doesn't exist in head2, insert into new list
            insertList(new nodeRec{curr1->num, nullptr}, newHead);
        curr1 = curr1->next;
    }

    // add remaining elements from head2 to the new list
    while (curr2 != nullptr) {
        memberList(curr2->num, head1, location);
        if(location == nullptr)
            insertList(new nodeRec{curr2->num, nullptr}, newHead);
        curr2 = curr2->next;
    }

    return newHead;
}