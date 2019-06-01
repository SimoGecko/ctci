#include <iostream>

using namespace std;


int countbitswaps(int A, int B)
{
	int C = A^B;
	int l=0;
	for (int i = 0; i < 32; ++i)
	{
		if(C&(1<<i))l++;
	}
	return l;
}

int main()
{
	
	int A = 29;
	int B = 15;
	cout << countbitswaps(A, B); // 2

	return 0;
}