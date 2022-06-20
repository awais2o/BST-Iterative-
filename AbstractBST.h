#include"Node.h"
#include<iostream>
using namespace std;
template <class T>
class AbsBST {
protected:
	Node <T>* root;

public:
	AbsBST() {
		root = nullptr;
	
	}


	virtual void insert(T) = 0;
	
	virtual void inorder() = 0;
	
	virtual void preorder() = 0;

	virtual void postorder() = 0;
	
	virtual bool search(T key) = 0;

	virtual void levelorder() = 0;

	virtual bool  deletion(T data) = 0;

	virtual int MaxHeight() = 0;
};