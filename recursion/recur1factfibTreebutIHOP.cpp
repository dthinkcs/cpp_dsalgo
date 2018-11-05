#include <iostream>
using namespace std;

int factorial(int n) {
	if (n == 0) {
		return 1;
	}
	int smallOutput = factorial(n - 1);
	int output = n * smallOutput;
	return output;
}

int fib(int n)
{
	if (n <= 1)
		return n;
	// smallOutput1 + smallOutput2
	return fib(n - 1) + fib(n - 2);
}

int main() {
	cout << factorial(4) << endl;
}
