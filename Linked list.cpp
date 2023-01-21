#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	Node* next_node = nullptr;
	T data;
	Node();
	Node(T data_c) : data(data_c){};
};

template<typename T>
struct List
{
	Node<T>* first = nullptr, * last = nullptr;
	unsigned int size = 0;
	void push_back(T data) {
		if (!first) {
			Node<T>* node = new Node<T>(data);
			first = node;
			last = first;
		}
		else {
			last->next_node = new Node<T>(data);
			last = last->next_node;
		}
		size++;
	}
	void pop_back() {
		Node<T>* node = first;
		if (!first->next_node) {
			first = nullptr;
			return ;
		}
		while (node) {
			if (node->next_node == last) {
				last = node->next_node;
				node->next_node = nullptr;
				break;
			}
			node = node->next_node;
		}
	}
	void show_list() {
		Node<T>* node = first;
		cout << '[';
		while (node) {
			cout << node->data;
			if (node->next_node) {
				cout << ", ";
			}
			
			node = node->next_node;
		}
		cout << ']' << endl;
	}
	bool empty() {
		if (first != nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main()
{
	List<int> list;
	cout << list.empty();
	list.push_back(1);
	cout << list.empty();
	list.pop_back();
	cout << list.empty();
}

