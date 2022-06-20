#pragma once
#include<iostream>

using namespace std;

template <class T>

class Queue
{
	T* arr;
	int front;
	int rear;
	int size;

public:
	Queue(int maxsize)
	{
		front = 0;
		rear = -1;
		size = maxsize;
		arr = new T[size];
	}

	bool isfull()
	{
		if (rear == size - 1)
		{

			return true;
		}

		return false;
	}

	bool isempty()
	{
		if (rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enque(T data)
	{
		
		 if (!isfull())
		{
			rear++;
			arr[rear] = data;
		}
		else
		{
			arr = regrow(arr, size, data);
		}
	}

	T* regrow(T* node, int &s,T d) {
		T* n = new T[size + 1];
		size++;
		for (int i = 0; i < size; i++)
		{
			n[i] = node[i];
		}
		n[size-1] = d;
		delete[] node;
		node = nullptr;
		return n;
	}
	T deque()
	{
		
			T temp = arr[front];
			
			
			for (int i = 0; i < rear; i++)
			{
				arr[i] = arr[i + 1];
			}
			rear--;
			return temp;

		
		
	}



	void showqueue()
	{
		cout << "Queue = ";
		for (int i = 0; i <= rear; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;

	}




};
