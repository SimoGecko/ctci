#include <iostream>
#include <math.h>

using namespace std;

int flipbittowin(int num)
{
	int m=0; // max
	int c[2]={0,0}; // counting buffers
	int j=0; // buffer index
	bool saw0 = false;

	for (int i = 0; i < 32; ++i)
	{
		int d = (num&(1<<i))!=0; // ith digit
		if(d==1)
		{
			c[j%2]++;
			c[(j+1)%2]++;
		}
		else
		{
			m = max(m, c[j%2]+1);
			c[j%2] = 0;
			j++;
			saw0 = true;
		}
	}

	m = max(m, c[j%2]+(int)saw0); // +1 only if saw a 0 sometimes

	return m;
}

int main()
{
	int num = 1775; // 11011101111 -> 8
	//int num = 99773; // 11000010110111101 -> 7
	//int num = 4294967295; // 1s->32
	
	cout << flipbittowin(num) << endl;
}