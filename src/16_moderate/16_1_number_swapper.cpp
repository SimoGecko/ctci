// (c) Simone Guggiari 2019 - CTCI
#include <iostream>

using namespace std;

void swapNoTemp(int& a, int& b)
{
	b = a-b;
	a = a-b;
	b = a+b;
}


int main()
{
	while(true)
	{
		cout << "Insert a, b: " << endl;
		int a, b; cin >> a >> b;
		swapNoTemp(a,b);
		cout << "swapped: " << a << ", " << b << endl;
	}
	return 0;
}