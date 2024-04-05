//
// Created by 101061875 on 2/12/2024.
//

#ifndef PROGRAM1A_LINKEDLISTS_H
#define PROGRAM1A_LINKEDLISTS_H
#include <iostream>
using namespace std;

typedef int nodeType;
struct nodeRec {
    nodeType num;
    nodeRec *next;
};
typedef nodeRec *nodePtr;
void insertList(nodePtr temp, nodePtr &headptr);
void deleteNodeList(nodeType temp_num, nodePtr &headptr);
bool memberList(nodeType num, nodePtr headptr, nodePtr &location);
void printList(nodePtr headptr);
int sizeList(nodePtr headptr);
bool subsetList(nodePtr head1, nodePtr head2, nodePtr &location);
bool areEqualLists(nodePtr head1, nodePtr head2);
nodePtr theUnionLists(nodePtr head1, nodePtr head2);
nodePtr theIntersectionList(nodePtr head1, nodePtr head2);
nodePtr theDifferenceList(nodePtr head1, nodePtr head2);
nodePtr symDifferenceList(nodePtr head1, nodePtr head2);
#endif //PROGRAM1A_LINKEDLISTS_H
