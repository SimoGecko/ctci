#include <iostream>

using namespace std;

int max(int a, int b){
	int k = ((b-a)>>(sizeof(int)*8-1))&1;
	return a*k+(1-k)*b;
}


int main(){

	while(true)
	{
		cout << "Insert a, b:"<<endl;
		int a; cin >> a;
		int b; cin >> b;
		cout << "max(" << a << " , " << b << ") = " << max(a,b) << endl;
	}

	return 0;
}