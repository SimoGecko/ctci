// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

char rule = '.';
string pattern = ".(.).";

set<string> parens(int n)
{
	set<string> ss;
	ss.insert(string(1,rule));
	
	for(int p=0; p<n; p++)
	{
		set<string> nss;
		for(auto e:ss)
		{
			for(size_t i=0; i<e.size(); i++)
			{
				if(e[i]==rule)
				{
					string ne(e);
					ne.replace(i, 1, pattern);
					nss.insert(ne); // avoid duplicates insertion, although it builds them
				}
			}
		}
		ss = nss;
	}

	set<string> res;
	for(auto e:ss)
	{
	    string ec(e);
	    ec.erase(remove(ec.begin(), ec.end(), rule), ec.end());
	    res.insert(ec);
	}
	
	return res;
}

int main()
{
	cout << "Insert number of parentheses n: " << endl;
	int n; cin >> n;
	cout << "All valid parentheses are " << endl;
	for(auto e : parens(n)) cout << e << " ,"; cout << endl;

	return 0;
}