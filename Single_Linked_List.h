#pragma once

template <typename Item_Type>
struct Node {
	Item_Type data;
	Node* next;

	Node(const Item_Type& data_item, Node* next_ptr = nullptr) {
		data = data_item;
		next = next_ptr;
	}
};
template<typename Item_Type>
class Single_Linked_List {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	int num_items;
public:
	Single_Linked_List() {
		head = nullptr;
		tail = nullptr;
		num_items = 0;
	}
	Single_Linked_List(Item_Type d) {
		Node<Item_Type>* elem = new Node<Item_Type>(d);
		head = elem;
		tail = head;
		num_items = 1;
	}
	~Single_Linked_List() {
		Node<Item_Type>* curr = head;
		Node<Item_Type>* next;
		while (curr != nullptr) {
			next = curr->next;
			delete curr;
			curr = next;
		}
		head = nullptr;
		tail = nullptr;
	}
	int size() {
		return num_items;
	}
	void push_front(const Item_Type& item) {
		//Check if list is empty
		if (empty()) {
			Node<Item_Type>* node = new Node<Item_Type>(item);
			head = node;
			tail = head;
		}
		else { //update head to be the new element
			head = new Node<Item_Type>(item, head);
		}
		num_items++;
	}
	void push_back(const Item_Type& item) {
		if (empty()) {
			push_front(item);
		}
		else {
			//Add new node to the end of list
			tail->next = new Node<Item_Type>(item);
			//set new node to tail
			tail = tail->next;
			num_items++;
		}
	}
	void pop_front() {
		if (empty()) {
			throw std::out_of_range("List is empty");
		}
		Node<Item_Type>* current = head;
		head = head->next;
		delete current;
		if (head == nullptr) {
			tail = nullptr;
		}
		num_items--;
	}
	void pop_back() {
		if (empty()) {
			throw std::out_of_range("List is empty");
		}
		Node<Item_Type>* current = head;
		if (head == tail) { //If only one element
			pop_front();
		}
		else {
			while (current->next != tail) { //Loop through list until the second to last element
				current = current->next;
			}
			delete tail;
			current->next = nullptr;
			tail = current;
			num_items--;
		}
	}
	Item_Type front() {
		if (empty()) {
			throw std::out_of_range("List is empty");
		}
		return head->data;
	}
	Item_Type back() {
		if (empty()) {
			throw std::out_of_range("List is empty");
		}
		return tail->data;
	}
	bool empty() {
		return head == nullptr;
	}
	void insert(int index, const Item_Type& item) {
		if (index > num_items - 1) { //if index is outside range of list
			push_back(item);
		}
		else if (index == 0) { //If inserting to the front
			push_front(item);
		}
		else {
			Node<Item_Type>* curr = head;
			for (int i = 0; i < index - 1; i++) { //Loop to element before index to insert
				curr = curr->next;
			}
			curr->next = new Node<Item_Type>(item, curr->next);
			num_items++;
		}
	}
	bool remove(int index) {
		if (index > num_items - 1) { //if index is out of range
			return false;
		}
		Node<Item_Type>* curr = head;
		if (curr->next == nullptr) { //if only one element
			pop_front();
		}
		else if (index == num_items - 1) { //if removing the last element
			pop_back();
		}
		else {
			for (int i = 0; i < index - 1; i++) {//Loop to element before index to remove
				curr = curr->next;
			}
			Node<Item_Type>* temp = curr->next;
			curr->next = temp->next;
			delete temp;
			num_items--;
		}
		return true;
	}
	int find(const Item_Type& item) {
		Node<Item_Type>* curr = head;
		for (int i = 0; i < num_items; i++) {
			if (curr->data == item) {
				return i;
			}
			curr = curr->next;
		}
		return num_items;
	}
	void printList() {
		std::cout << "List: ";
		Node<Item_Type>* curr = head;
		while (curr != nullptr) {
			std::cout << curr->data << " ";
			curr = curr->next;
		}
		std::cout << "\n" << std::endl;
	}
};