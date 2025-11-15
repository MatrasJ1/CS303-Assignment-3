#include "Functions.h"
void insertion_sort(std::list <int>& num) {
    if (num.size() <= 1) { 
        return; 
    } // case of empty list or just one element

    std::list<int>::iterator it = num.begin();
    std::list<int>::iterator prev;
    for (++it; it != num.end(); ++it) { //start at second element
        int key = *it;
        prev = std::prev(it);

        bool insertionNeeded = false;

        // Move backward and find the correct position for key
        while (prev != num.begin() && key < *prev) {
            *it = *prev;  // Move the element one position ahead
            it = prev;    // Move the iterator back
            prev = std::prev(it);
            insertionNeeded = true;
        }

        // If necessary, insert key at the found position
        if (key < *prev) {
            *it = *prev;
            *prev = key;
        }
        else if (insertionNeeded) {
            *it = key;
        }
    }
}

int linear_search(std::vector<int>& items, int target, int pos_last) { //Start from the last position
    if (pos_last == 0 && target != items[pos_last]) //Base case change to position out of bounds
        return -1;
    if (target == items[pos_last])
        return pos_last;
    else
        return linear_search(items, target, pos_last - 1);
}
 
