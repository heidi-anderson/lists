#include "Part 2/class.h"
#include "Part 1/linkedLists.h"
#include "Part 3/stl.cpp"
#include <iostream>

int main()
{

/*     cout << "**********Linked Lists**********" << endl;
     nodePtr listA = nullptr;
     insertList(new nodeRec{10, nullptr}, listA);
     insertList(new nodeRec{34, nullptr}, listA);
     insertList(new nodeRec{4, nullptr}, listA);
     insertList(new nodeRec{7, nullptr}, listA);
     insertList(new nodeRec{8, nullptr}, listA);

     nodePtr listB = nullptr;
     insertList(new nodeRec{3, nullptr}, listB);
     insertList(new nodeRec{5, nullptr}, listB);
     insertList(new nodeRec{11, nullptr}, listB);
     insertList(new nodeRec{8, nullptr}, listB);
     cout << "A: ";
     printList(listA);
     cout << "B: ";
     printList(listB);

     nodePtr locA, locB;
     memberList(5, listB, locB);
     if(locB != nullptr)
         cout << "5 is a member of B" << endl;
     memberList(11, listA, locA);
     if(locA == nullptr)
         cout << "11 is not a member of A" << endl;
    cout << "The size of B is " << sizeList(listB) << endl;
    if(sizeList(listA) != sizeList(listB))
        cout << "List A and B are not the same size!" << endl;
    if(!subsetList(listB, listA, locA))
        cout << "B is not a subset of A!" << endl;
    if(!areEqualLists(listA, listB))
        cout << "A and B are not equal!" << endl;
    cout << "The Union of A and B (A ∪ B): ";
    printList(theUnionLists(listA, listB));
    cout << "The intersection of A and B (A ∩ B): ";
    printList(theIntersectionList(listA, listB));
    cout << "Difference of A and B (A-B): ";
    printList(theDifferenceList(listA,listB));
    cout << "Symmetric Difference of A and B (A Δ B): ";
    printList(symDifferenceList(listA, listB));

    nodePtr diffUnion = theUnionLists(theDifferenceList(listA, listB), listB);
    cout << "(A-B) ∪ B: ";
    printList(diffUnion);

    nodePtr aub = theUnionLists(listA, listB);
    nodePtr a_b = theDifferenceList(listA, listB);
    nodePtr a_bUB = theUnionLists(a_b, listB);

    if(areEqualLists(aub, a_bUB))
        cout << "(A ∪ B) and (A-B) ∪ B are equal!" << endl;

    nodePtr b_a = theDifferenceList(listB, listA);
    nodePtr difUdif = theUnionLists(a_b, b_a);
    cout << "(A-B) ∪ (B-A): ";
    printList(difUdif);

    nodePtr aNv = symDifferenceList(listA, listB);

    if(areEqualLists(aNv, difUdif))
        cout << "(AΔB) and (A-B) ∪ (B-A) are equal!" << endl;*/


/*    cout << "**********CLASS**********" << endl;
    sortedSingle listA;
    sortedSingle listB;

    listA.insert(10);
    listA.insert(34);
    listA.insert(4);
    listA.insert(7);
    listA.insert(8);

    listB.insert(3);
    listB.insert(11);
    listB.insert(5);
    listB.insert(8);

    cout << "A: ";
    listA.print(",");
    cout << endl;
    cout << "B: ";
    listB.print(",");
    cout << endl;

    if(member(listB, 5))
        cout << "5 is a member of B" << endl;
    if(!member(listA, 11))
        cout << "11 is not a member of A" << endl;
    cout << "The size of B is " << listB.size() << endl;
    if(!areEqual(listA, listB))
        cout << "A and B are not the same size!" << endl;
    if(!isSubset(listB, listA))
        cout << "B is not a subset of A" << endl;
    if(!areEqual(listA, listB))
        cout << "A and B are not equal!" << endl;


    sortedSingle aUb = theUnion(listA, listB);
    cout << "The union of A and B (A U B): ";
    aUb.print(",");
    cout << endl;
    sortedSingle aANDb = theIntersection(listA, listB);
    cout << "The intersection of A and B (A ∩ B): ";
    aANDb.print(",");
    cout << endl;
    sortedSingle a_b = theDifference(listA, listB);
    sortedSingle b_a = theDifference(listB, listA);
    cout << "Difference of A and B (A-B): ";
    a_b.print(",");
    cout << endl;
    sortedSingle aNb = symDifference(listA, listB);
    cout << "Symmetric Difference of A and B (AΔB):";
    aNb.print(",");
    cout << endl;
    sortedSingle a_bUb = theUnion(a_b, listB);
    cout << "(A-B) ∪ B: ";
    a_bUb.print(",");
    cout << endl;
    if(areEqual(aUb, a_bUb))
        cout << "(A ∪ B) and (A-B) ∪ B are equal!" << endl;

    sortedSingle a_bUb_a = theUnion(a_b, b_a);
    cout << "(A-B) ∪ (B-A): ";
    a_bUb_a.print(",");
    cout << endl;

    if(areEqual(aNb, a_bUb_a))
        cout << "(AΔB) and (A-B) ∪ (B-A) are equal!" << endl;*/


    cout << "**********TEMPLATE**********" << endl;
    std::list<int> listA = {10,34,4,7,8};
    std::list<int> listB = {3,5,11,8};
    cout << "A: ";
    stlPrint(listA);
    cout << "B: ";
    stlPrint(listB);

    if(stlMember(listB, 5))
        cout << "5 is a member of B" << endl;
    if(!stlMember(listA, 11))
        cout << "11 is not a member of A" << endl;

    int sizeA = stlSize(listA);
    int sizeB = stlSize(listB);
    cout << "The size of B is " << sizeB << endl;
    if(sizeA != sizeB)
        cout << "A and B are not the same size!" << endl;
    if(!stlSubset(listB, listA))
        cout << "B is not a subset of A" << endl;
    if(!stlEqual(listA, listB))
        cout << "A and B are not equal!" << endl;

    std::list<int> aUb = stlUnion(listA, listB);
    cout << "Union of A and B (A ∪ B): ";
    stlPrint(aUb);

    std::list<int> aANDb = stlIntersection(listA, listB);
    cout << "Intersection of A and B (A ∩ B): ";
    stlPrint(aANDb);

    std::list<int> a_b = stlDifference(listA, listB);
    std::list<int> b_a = stlDifference(listB, listA);
    cout << "Difference of A and B (A-B): ";
    stlPrint(a_b);

    std::list<int> aNb = stlSymmetricDifference(listA, listB);
    cout << "Symmetric Difference of A and B (AΔB): ";
    stlPrint(aNb);

    std::list<int> a_bUb = stlUnion(a_b, listB);
    cout << "(A-B) ∪ B: ";
    stlPrint(a_bUb);

    if(stlEqual(aUb, a_bUb))
        cout << "(A ∪ B) and (A-B) ∪ B are equal!" << endl;

    std::list<int> a_bUb_a = stlUnion(a_b, b_a);
    cout << "(A-B) ∪ (B-A): ";
    stlPrint(a_bUb_a);

    if(stlEqual(aNb, a_bUb_a))
        cout << "(AΔB) and (A-B) ∪ (B-A) are equal!" << endl;

    return 0;

}
