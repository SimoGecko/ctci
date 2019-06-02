// (c) Simone Guggiari 2019 - CTCI
#include <iostream>

using namespace std;

int multiplySmaller(int a, int b) //a,b>=0, a<=b
{
	if(a==0) return 0;
	if(a==1) return b;
	int m = multiplySmaller(a>>1,b<<1);
	if(a%2==0) return m;
	return b+m;
}

int multiply(int a, int b)
{
	//sorts them
	return multiplySmaller((a<b?a:b), (a>=b?a:b));
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