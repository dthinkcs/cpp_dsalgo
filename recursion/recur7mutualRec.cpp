#include <iostream>
using namespace std;
// NECESSARY BECAUSE one function calls the other and the other function calls the other so there is NO ordering POSSIBLE
bool isEven(int);
bool isOdd(int);

bool isEven(int n)
{
	if (n == 0) 
		return true;
	// return isEven(n - 2);  NEEDS 2 BASE CASESs
	return isOdd(n - 1); // n is one more than an odd number

}

bool isOdd(int n)
{
	if (n == 0)
		return false;
	return isEven(n - 1);
}

int main(void)
{
	// Test Cases
	cout << isEven(10) << endl;
	cout << isOdd(10) << endl;
}
