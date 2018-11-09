#include <iostream.h>
#include <conio.h>
#define SIZE 4

class queue
{
	int front;
	int rear;
	int s[SIZE];

	public:
	queue()
	{
		front = rear = 0;
	}
	void addq(int item);
	int delq();
	void disp();
};

void queue::disp()
{
	if (front == rear)
	{
		cout << "Queue is empty" << endl;
		return;
	}

	for (int i = front; i < rear; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void queue::addq(int item)
{
	if ((rear + 1) % SIZE == front)
		cout << "Queue is Full" << endl;
	else
	{
		s[rear] = item;
		rear = (rear + 1) % SIZE;
	}
}

int queue::delq()
{
	if (front == rear)
	{
		cout << "Queue is Empty"  << endl;
		return -999;
	}
	else
	{
		int ele = s[front];
		front = (front + 1) % SIZE;
		return ele;
	}
}



void main()
{
	clrscr();
	queue line = queue();
	line.delq();
	line.addq(1);
	line.disp();
	line.addq(2);
	line.disp();
	line.addq(3);
	line.disp();
	line.addq(4);
	getch();
}
