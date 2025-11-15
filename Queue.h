#pragma once
#include "Single_Linked_List.h"

template <typename Item_Type>
class Queue{
private:
	Single_Linked_List<Item_Type> queue;
public:
	Queue(){
		queue = Single_Linked_List<Item_Type>();
	}
	void push(const Item_Type& d) {
		queue.push_back(d);
	}
	void pop() {
		try {
			queue.pop_front();
		}
		catch (std::out_of_range e) {
			std::cout << e.what() << std::endl;
		}
	}
	Item_Type front() {
		try {
			return queue.front();
		}
		catch(std::out_of_range e) {
			std::cout << e.what() << std::endl;
		}
	}
	size_t size() {
		return queue.size();
	}
	bool empty() {
		return queue.empty();
	}
	void print() {
		std::cout << std::endl;
		std::cout << "Queue: ";
		for (int i = 0; i < size(); i++) {
			std::cout << front() << " ";
			push(front());
			pop();
		}
		std::cout << std::endl;
	}
	void move_to_rear() {
		push(front());
		pop();
	}
};

