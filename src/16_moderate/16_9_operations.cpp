#include <iostream>
#include <climits>

using namespace std;


//don't work if negative

int myneg(int a){
	int r = 0;
	int i = a<0?1:-1;
	while(a!=0){a+=i; r+=i;}
	return r;
}

int mysub(int a, int b) // a-b
{
	int s = INT_MIN; // better: INT_MIN
	while(s+b < a) s++;
	return s;
	//alternatively, return a+myneg(b);
}

int mymul(int a, int b){ // a*b // what if one negative?
	int s = 0;
	for (int i = 0; i < a; ++i) s+=b;
	return s;
}

int mydiv(int a, int b) // a/b // check for b=0
{
	if(b==0) return 0;
	int s=0, c=0;
	while(s+b<=a) { s+=b; c++; }
	if((a<0 && b<0) || (a>0 && b>0)) return c;
	return c;
}

int main(){
	while(true){
		cout << "Insert a, b: ";
		int a, b; cin >> a >> b;
		cout << a << "-" << b << " = " << mysub(a, b) << endl;
		cout << a << "*" << b << " = " << mymul(a, b) << endl;
		cout << a << "/" << b << " = " << mydiv(a, b) << endl;
	}

	return 0;
}