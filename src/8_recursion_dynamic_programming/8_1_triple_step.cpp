#include <iostream>

using namespace std;


long int countWays(int n)
{
	if(n<0) return 0;
	long int T[3] {1,1,2};
	if(n<3) return T[n];

	for (int i = 0; i <= n; ++i)
	{
		T[i%3] = T[0]+T[1]+T[2];
	}
	return T[n%3];
}


int main()
{
	while(true)
	{
		cout << "Insert n:" << endl;
		int n; cin >> n;
		cout << "Number of ways is " << countWays(n) << endl;
	}
	return 0;
}