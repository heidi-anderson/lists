#ifndef PROGRAM1A_STL_TPP
#define PROGRAM1A_STL_TPP

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template<typename T>
void stlPrint(const std::list<T>& list) {
    typename std::list<T>::const_iterator spot = list.begin();
    if (spot != list.end()) {
        std::cout << "{" << *spot;
        ++spot;
        while (spot != list.end()) {
            std::cout << "," << *spot;
            ++spot;
        }
        std::cout << "}" << std::endl;
    } else {
        std::cout << "{}" << std::endl;
    }
}

template<typename T>
bool stlMember(const std::list<T>& mylist, const T& elem) {
    return std::find(mylist.begin(), mylist.end(), elem) != mylist.end();
}

template<typename T>
void stlDelete(std::list<T>& mylist, const T& elem) {
    mylist.remove(elem);
}

template<typename T>
int stlSize(const std::list<T>& myList) {
    return myList.size();
}

template<typename T>
bool stlSubset(const std::list<T>& list1, const std::list<T>& list2) {
    return std::includes(list2.begin(), list2.end(), list1.begin(), list1.end());
}

template<typename T>
bool stlEqual(const std::list<T>& list1, const std::list<T>& list2) {
    return list1 == list2;
}

template<typename T>
void stlInsert(std::list<T>& mylist, int pos, const T& value) {
    auto it = mylist.begin();
    std::advance(it, pos);
    mylist.insert(it, value);
}

template<typename T>
list<T> stlUnion(const std::list<T>& list1, const std::list<T>& list2) {
    list<T> result = list1;
    result.insert(result.end(), list2.begin(), list2.end());
    result.sort();
    result.unique();
    return result;
}

template<typename T>
list<T> stlIntersection(const std::list<T>& list1, const std::list<T>& list2) {
    list<T> result;
    for (const auto& elem : list1) {
        if (stlMember(list2, elem)) {
            result.push_back(elem);
        }
    }
    return result;
}

template<typename T>
list<T> stlDifference(const std::list<T>& list1, const std::list<T>& list2) {
    list<T> result;
    for (const auto& elem : list1) {
        if (!stlMember(list2, elem)) {
            result.push_back(elem);
        }
    }
    return result;
}

template<typename T>
list<T> stlSymmetricDifference(const list<T>& list1, const list<T>& list2) {
    // put the two lists together
    list<T> combined = list1;
    combined.insert(combined.end(), list2.begin(), list2.end());

    combined.sort(); // sort her

    // bye bye duplicates
    combined.unique();

    // new list
    list<T> newList;

    // add elements that only appear once from combined
    for (const auto& elem : combined) {
        if (std::count(list1.begin(), list1.end(), elem) != std::count(list2.begin(), list2.end(), elem)) {
            newList.push_back(elem);
        }
    }

    return newList;
}

#endif