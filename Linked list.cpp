#include <iostream>
#include <list>

using namespace std;

struct Node
{
	Node* next_node = nullptr;
	int data = 0;
	Node();
	Node(int data_c) : data(data_c){};
};

struct List
{
	Node* first = nullptr, * last = nullptr;
	unsigned int size = 0;
	void push_back(int data) {
		if (!first) {
			cout << "list created" << endl;
			Node* node = new Node(data);
			first = node;
			last = first;
		}
		else {
			last->next_node = new Node(data);
			last = last->next_node;
		}
		size++;
	}
	void pop_back() {
		Node* node = first;
		while (node) {
			node = node->next_node;
			if (node->next_node == last) {
				last = node->next_node;
				node->next_node = nullptr;
				break;
			}
		}
	}
	void show_list() {
		Node* node = first;
		cout << '[';
		while (node) {
			node = node->next_node;
			cout << node->data;
			if (node->next_node) {
				cout << ", ";
			}
			else {
				cout << ']';

			}
		}
		cout << ']' << endl;
	}
};

int main()
{
	List list;
	list.show_list();
	for (int i = 0; i < 100; i++)
	{
		list.push_back(i);
	}
	list.pop_back();
	list.show_list();

}

