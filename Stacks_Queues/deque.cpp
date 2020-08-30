#include <iostream>
using namespace std;

#define MAX_size 10     // Maximum size of array or Dequeue 

class Deque
{
	int array[MAX_size];
	int front;
	int rear;
	int size;


public:
	Deque(int s)
	{	
		front = -1;
		rear  = 0;
		size  = s;
	}
	
		    // Check if Deque is full
	bool  isFull(){
	return ((front == 0 && rear == size-1)||front == rear+1);    
	    } 
	    // Check if Deque is empty 
	bool  isEmpty(){
	return (front == -1);  
	    }

	void insertfront(int input)
	{
		if (isFull())
		{
			cout << "-1" << endl;
			return;
		}

		if (front == -1)
		{
			front = 0;
			rear  = 0;
		}

		else if (front == 0)
		{
			front = size-1;
		}

		else
		{
			front = front - 1;
		}

		array[front] = input;
	}


	void insertrear(int input)
	{
		if (isFull())
		{
			cout << "-1" << endl;
			return;
		}

		if (front == -1)
		{
			front = 0;
			rear  = 0;
		}

		else if (rear == size - 1)
		{
			rear = 0;
		}

		else
		{
			rear = rear + 1;
		}

		array[rear] = input;
	}


	void deletefront()
	{
		if (isEmpty())
		{
			cout << "-1" << endl;
			return;
		}

		if (front == rear)
		{
			front = -1;
			rear  = -1;
		}

		else
		{
			if (front == size-1)
			{
				front = 0;
			}

			else
			{
				front =  front + 1;
			}
		}
	}

	void deleterear()
	{
		if (isEmpty())
		{
			cout << "-1" << endl;
			return;
		}

		if (front == rear)
		{
			front = -1;
			rear  = -1;
		}

		else if (rear == 0)
		{
			rear = size - 1;
		}

		else
		{
			rear = rear - 1;
		}
	}

	int getFront()
	{
		if (isEmpty())
		{
			return -1;
		}

		return array[front];
	}

	int getRear()
	{
		if (isEmpty() || rear < 0)
		{
			return -1;
		}

		return array[rear];
	}	
	
};

int main()
 {
 Deque dq(10);
 int choice,input;
 while(true) {
 cin >> choice;
 switch (choice) {
 case 1:
 cin >> input;
 dq.insertfront(input);
 break;
 case 2:
 cin >> input;
 dq.insertrear(input);
 break;
 case 3:
 dq.deletefront();
 break;
 case 4:
 dq.deleterear();
 break;
 case 5:
 cout << dq.getFront() << "\n";
 break;
 case 6:
 cout << dq.getRear() << "\n";
 break;
 default:
 return 0;
 }
 }
 
 return 0;
 }
