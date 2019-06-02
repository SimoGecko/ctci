// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>

using namespace std;


float calculate(const string& s)
{

}

int main()
{
	while(true)
	{
		cout << "Insert the expression to compute: " << endl;
		string s; cin >> s;
		cout << s << " = " << calculate(s);
	}
	return 0;
}