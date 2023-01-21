#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	Node* next_node = nullptr;
	T data;
	Node();
	Node(T data_c) : data(data_c){};
	Node(T data_c, Node* next_node_c) : data(data_c), next_node(next_node_c){};
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
	void resize(int new_size) {
		if (new_size > size) {
			while (new_size > size) {
				last->next_node = new Node<T>(NULL);
				last = last->next_node;
				size++;
			}
		}
		else if(new_size < size)
		{
			while (new_size < size)
			{
				Node<T>* node = first;
				while (node->next_node != last) {
					node = node->next_node;
				}
				node->next_node = nullptr;
				last = node;
				size--;
			}
		}
	}
	void emplace(int position, T val) {
		int s = 0;
		Node<T>* node = first;
		if (size < position || position < 0) {
			cout << "Error: Insertion position is not correct" << endl;
		}
		else {
			Node<T>* node = first;
			while (s != position - 1) {
				node = node->next_node;
				s++;
				if (s == position - 1) {

					node->next_node = new Node<T>(val, (node->next_node)->next_node);
					break;
				}
			}
		}
	}
	void insert(int position, T val) {
		int s = 0;
		Node<T>* node = first;
		if (size < position || position < 0) {
			cout << "Error: Insertion position is not correct" << endl;
		}
		else {
			Node<T>* node = first;
			while (s != position - 1) {
				node = node->next_node;
				s++;
				if (s == position - 1) {

					node->next_node = new Node<T>(val, node->next_node);
					break;
				}
			}
		}
		size++;
	}
};

int main()
{
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);
	list.insert(1, 50);
	list.show_list();
	//emplace and insert cant work with 1 and 2
}

