#pragma once
template<class T>
class Node {
public:
	T data;
	Node* left;
	Node* right;

	Node() {
		this->data = NULL;

		left = nullptr;
		right = nullptr;
	}
	Node(int data) {
		this->data = data;

		left = nullptr;
		right = nullptr;
	}


};
