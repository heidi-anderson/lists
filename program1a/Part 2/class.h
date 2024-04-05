//
// Created by 101061875 on 2/7/2024.
//
#ifndef PROGRAM_1_H
#define PROGRAM_1_H
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

class sortedSingle
{
public:
    sortedSingle( ); // constructor
    ~sortedSingle( ); // destructor
    bool insert (int item);
    bool remove (int item);
    void print(string seperator);
    int size();

    /**
     * @brief  the storage container for each item in the list
     */
    struct node
    {
        int theItem;    /*!< the item */
        node *next;     /*!< pointer to the remaining nodes in list */
    };
    node *headptr;      /*!< The location of the first node in the list */
};
bool isSubset(sortedSingle &list1, sortedSingle &list2);
bool member(sortedSingle& list, int data);
bool areEqual(sortedSingle& list1, sortedSingle& list2);
sortedSingle theUnion(sortedSingle &list1, sortedSingle &list2);
sortedSingle theIntersection(sortedSingle &list1, sortedSingle &list2);
sortedSingle theDifference(sortedSingle &list1, sortedSingle &list2);
sortedSingle symDifference(sortedSingle &list1, sortedSingle &list2);
#endif