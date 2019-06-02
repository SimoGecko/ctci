#include <iostream>

using namespace std;

int sum(int a, int b)
{
    while(a&b)
    {
        int sum = a^b;
        int carry = (a&b)<<1;
        a = sum;
        b = carry;
    }
    return (a|b);
	//if((a&b)==0) return (a|b);
	//return sum(a^b, (a&b)<<1);
}

int main(){
	while(true)
	{
		cout << "Insert a, b:" << endl;
		int a, b; cin >> a >> b;
		cout << a << "+" << b << " = " << sum(a,b) << endl;
	}
	return 0;
}