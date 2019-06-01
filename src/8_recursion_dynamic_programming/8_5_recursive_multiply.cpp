// (c) Simone Guggiari 2019 - CTCI
#include <iostream>

using namespace std;


int multiply(int a, int b) //a,b>=0
{
	if(b==0)return 0;
	if(b==1) return a;
	int m = multiply(a<<1,b>>1);
	if(b%2==0) return m;
	return a+m;
}

int main()
{
	while(true)
	{
		cout << "Insert a, b: " << endl;
		int a, b; cin >> a >> b;
		cout << a << "*" << b << " = " << multiply(a,b) << endl;
	}
	return 0;
}