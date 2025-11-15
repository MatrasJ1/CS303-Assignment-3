// CS303 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include "Queue.h"
#include "Functions.h"

int main()
{
    Queue<int> myQueue;;
    for (int i = 0; i < 10; i++) {
        int random = i + 3;
        std::cout << "Pushing " << random << " to the queue.\n" << std::endl;
        myQueue.push(random);
    }
    myQueue.print();
    std::cout << "\nMoving front element to rear" << std::endl;
    myQueue.move_to_rear();
    myQueue.print();

    std::vector<int> vect;
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(3);
    vect.push_back(2);
    vect.push_back(1);
    std::cout << "\nVector: ";
    for (int i = 0; i < vect.size(); i++) {
        std::cout << vect.at(i) << " ";
    }
    std::cout << std::endl;
    int pos = linear_search(vect, 3, vect.size() - 1);
    std::cout << "Last index of 3 is: " << pos << std::endl;

    std::list<int> myList;
    myList.push_back(6);
    myList.push_back(3);
    myList.push_back(76);
    myList.push_back(7);
    myList.push_back(1);
    myList.push_back(43);
    std::cout << "\nUnsorted List: ";
    std::list<int>:: iterator iter = myList.begin();
    for (iter; iter != myList.end(); ++iter) {
        std::cout << *iter << " ";
    }
    insertion_sort(myList);

    std::cout << "\nSorted List: ";
    iter = myList.begin();
    for (iter; iter != myList.end(); ++iter) {
        std::cout << *iter << " ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
