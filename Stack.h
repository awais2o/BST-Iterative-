#include"Queue.h"
#include"Stack.h"
#include"AbstractBST.h"
#include"Node.h"
template<class T>
class BST:  public AbsBST<T> {

public:
	BST() {
		this->root = nullptr;
	}
	
	
	void insert(T data)
	{
		Node<T>* N = new Node<T>(data);
		if (this->root == NULL)
		{
			this->root = N;
		}
		else
		{
			Node<T>* temp = this->root;
			while (true)
			{
				if (data > temp->data)
				{
					if (temp->right == NULL)
					{
						temp->right = N;
						break;
					}
					else
					{
						temp = temp->right;
					}
				}
				else
				{
					if (temp->left == NULL)
					{
						temp->left = N;
						break;
					}
					else
					{
						temp = temp->left;
					}
				}
			}
		}

	}

	    void inorder()
    {
			Stack<Node<T>*>stk;
			Node<T>* current_Node = this->root;
		in:
			while (current_Node != nullptr) {
				
				stk.push(current_Node);
				current_Node = current_Node->left;
			}
			if (!stk.isEmpty())
			{
				Node<T>*temp= stk.pop();
				cout << temp->data <<"    ";
				current_Node = temp->right;
				goto in;
			}

		}


		void preorder()
		{
			Stack<Node<T>*>stk;
			Node<T>* current_Node = this->root;
		in:
			while (current_Node != nullptr) {

				cout << current_Node->data<<"    ";
				stk.push(current_Node);
				current_Node = current_Node->left;
			}
			if (!stk.isEmpty())
			{
				Node<T>* temp = stk.pop();
				current_Node = temp->right;
				goto in;
			}

		}

		void postorder()
		{
			


			Stack<Node<T>*> stk1;
			Stack<Node<T>*> stk2;
			stk1.push(this->root);
			Node<T>* temp;
			while (!stk1.isEmpty()) {
				temp=	stk1.pop();
				stk2.push(temp);
				if (temp->left!=nullptr)
					stk1.push(temp->left);
				if (temp->right != nullptr)
					stk1.push(temp->right);
				}
				while (!stk2.isEmpty()) {
				temp = stk2.top();
				stk2.pop();
				cout << temp->data << "    ";
				}
			
		}

		bool search(T key){


			if (this->root == NULL)
			{
				return 0;
			}
			else
			{
				Node<T>* temp = this->root;
				while (true)
				{
					if (key > temp->data)
					{
						temp = temp->right;
						if (temp==nullptr)
						{
							return 0;
						}
					}
					else if(key<temp->data)
					{
						temp = temp->left;
						if (temp == nullptr)
						{
							return 0;
						}
					}
					else {
						return 1;
					}
				}
			}

		}





	void levelorder() {
			Node<T>* itr = this->root;
			if (itr==nullptr)
			{
				return;
			}
			Queue<Node<T>*> store(5);
			store.enque(this->root);
			Node<T>* current = nullptr;
			while (!store.isempty()) {
				current = store.deque();
				cout << current->data<<"    ";

				if (current->left) {
					store.enque(current->left);
				}
				if (current->right) {
					store.enque(current->right);
				}
				
			}

	}


	bool  deletion(T data) {
		if (this->root==nullptr)
		{
			return 0;
		}
		else
		{
			Node<T>* itr = this->root;
			Node<T>* pre = nullptr;
			while (itr->data!=data&&itr!=nullptr)
			{
				pre = itr;
				if (data>itr->data)
				{
					itr = itr->right;
				}
				else
				{
					itr = itr->left;
				}
			}
			if (itr!=nullptr)
			{
				if (itr->data == data)
				{
					if (itr->left == nullptr && itr->right == nullptr)
					{
						if (itr==pre->right)
						{
							pre->right = nullptr;
						}
						else
						{
							pre->left = nullptr;
						}
						return 1;
					}
					else if (itr->left == nullptr && itr->right != nullptr || itr->left != nullptr && itr->right == nullptr)
					{
						if (itr->left != nullptr)
						{
							if (pre == nullptr)
							{
								pre = new Node<T>;
							}
							if (itr==pre->left)
							{

								pre->left = itr->left;
							}
							else
							{
								pre->right = itr->left;
							}
						
						}
						else
						{
							if (pre == nullptr)
							{
								pre = new Node<T>;
							}
							if (itr == pre->left)
							{
								pre->left = itr->right;
							}
							else
							{
								pre->right = itr->right;
							}



						}
						return 1;
					}

					else if (itr->left != nullptr && itr->right != nullptr)
					{
 						Node<T>* temp = itr->left;
						Node<T>* p = nullptr;
						while (temp->right != nullptr)
						{
							p = temp;
							temp = temp->right;
						}
						if (temp=p->right)
						{
							p->right = nullptr;
						}
						else {
							p->left = nullptr;
						}
						return 1;
					}



				}
			}
			

			else {
				return  0;
			}
		}

	}

	

	int MaxHeight()
	{
		int counter = 0;
		int counter2 = 0;
		Node<T>* current = this->root;

		if (current != nullptr)
		{
			while (current->left != nullptr)
			{
				counter++;
				current = current->left;
			}
			while (current->right != nullptr)
			{
				counter2++;
				current = current->right;
			}
		}

		int res = 0;
		if (counter > counter2)
		{
			res = counter + 1;
		}
		else
			res = counter2 + 1;
		return res;
	}
};

int main() {  
	
	BST<int> tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(75);
	tree.insert(4);
	tree.insert(9);
	tree.insert(1);
	tree.insert(54);
	cout <<  "\ninorder:\n";
	tree.inorder();
	cout << "\npreorder:\n";
	tree.preorder();
	cout << "\npostorder:\n";
	tree.postorder();
	cout << "\nlevelorder:\n";
	tree.levelorder();
	cout<<"\n max height:\n"<<tree.MaxHeight()<<"\n";
	int n = 75;
	if(tree.search(n)) {

		cout << n << " found\n";

	}
	else{
		cout << n << " not found\n";
	}

	if (tree.deletion(n)) {
		cout << n << " deleted\n";
	}
	else {
		cout << n << " not found\n";
	}
	
	system("pause");
	return 0;
}