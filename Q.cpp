#include <iostream>
using namespace std;
#define SIZE 10

class queue
{
	int f;
	int r;
	int s[SIZE];

	public:
	queue()
	{
		f = r = -1;
	}
	void addq(int item);
	int delq();
	void disp();
};

void queue::disp()
{
	if (f == r)
	{
		cout << "Queue is empty" << endl;
		return;
	}

	for (int i = f+1; i <= r; i++)
	{
		cout << s[i] << " ";
	}
	cout << endl;
}

void queue::addq(int item)
{
	if (r == SIZE - 1)
		cout << "Queue is Full" << endl;
	else
		s[++r] = item;
}

int queue::delq()
{
	if (f == r)
	{
		cout << "Queue is Empty"  << endl;
		return -999;
	}
	else
		return s[++f];
}



int main()
{
	queue line = queue();
	line.delq();
	line.addq(1);
	line.disp();
	line.addq(2);
	line.disp();
	line.addq(3);
	line.disp();
	line.addq(4);

}
