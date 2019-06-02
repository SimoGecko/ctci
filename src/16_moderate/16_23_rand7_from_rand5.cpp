// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
using namespace std;

int rand5(){ return rand()%5; }

int rand7(){
	int r1, r2;
	do{ r1=rand5(); } while (r1==4); // 2 random bits
	do{ r2=rand5(); } while (r2==4);
	int combined = (r1|(r2<<2));
	if(combined>13) return rand7(); // try again
	return combined%7;
}


int main()
{
	cout << "Insert number of tries of rand7(): "<< endl;
	int n; cin >> n;
	vector<int> sum(7,0);
	for (int i = 0; i < n; ++i) sum[rand7()]++;
	for(int i=0; i<7; i++) cout << i << ": " << sum[i] << endl;
	
	int z; cin >> z;
	return 0;
}