#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// vector<int>* vp = new vector<int>();
	vector<int> v;

//	v.push_back(10);
//	v.push_back(20);
//	v.push_back(30);

	// USE [] only for getting value and updatng NOT INSERTING
//	v[1] = 100;
//	v[2] = 1002;
	//v[4] = 1234;

	for (int i = 0; i < 100; i++)
    {
         v.push_back(i + 1);
        cout << "SIZE: " <<   v.size() << endl;
        cout << "CAPACITY: " <<  v.capacity() << endl;
    }

	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	//cout << v[3] << endl;
	//
	//cout << v[4] << endl;
	//cout << v[5] << endl;
	//cout << v[6] << endl; // NO DIMAAG JUST ADD INTO ARR POINTER EVEN IF garbage OUTSIDE vector
	// SAFER .at
	//cout << v.at(6) << endl; // NO DIMAAG JUST ADD INTO ARR POINTER EVEN IF garbage OUTSIDE vector


}
