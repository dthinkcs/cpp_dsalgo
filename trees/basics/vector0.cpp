#define MAX 20
template T
class Vector<T>
{

	T arr[MAX];


	int capacity;
	int size;

public:
	void push();
};

int main()
{
	Vector<int> v;                    // v.push();
	Vecotr<int>* vp = new Vector<int>;// vp->push();
}