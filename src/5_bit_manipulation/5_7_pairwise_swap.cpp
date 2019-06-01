#include <iostream>

using namespace std;

int swapbitsevenodd(int num){
	constexpr int m10 = 0xAAAAAAAA;
	constexpr int m01 = 0x55555555;
	return ( (num & m10 ) >> 1) | ( ( num & m01 ) << 1 );
}



int main()
{
	
	int num = 555; // 1000101011
	cout << swapbitsevenodd(num) << endl; // 279 = 100010111

	return 0;
}