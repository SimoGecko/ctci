#include <iostream>
#include <cmath>

using namespace std;

int numTrailZerosNFac(const int n){
	constexpr int d = 3; // how many digits to keep
	const int cut = pow(10, d);

	int f = 1;
	int c = 0;
	for (int i = 2; i <= n; ++i)
	{
		f*=i;
		while(f%10==0)
		{
			f/=10;
			c++;
		}
		if(f>=cut) f %= cut; // crop to max d digits
	}
	return c;
}


int main(){

	while(true){
		cout << "Insert n: ";
		int n; cin >> n;
		if(n==0) break;
		cout << "num trailing zeros of " << n << "! is " << numTrailZerosNFac(n) << endl;
	}

	return 0;
}