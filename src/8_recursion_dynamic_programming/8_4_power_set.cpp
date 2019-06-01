// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <set>
using namespace std;


template <typename T>
set<set<T>> powerSet(set<T> s)
{
	set<set<T>> res;
	for (int i = 0; i < 2<<s.size(); ++i)
	{
		set<T> subs;
		int j=0;
		for(auto e:s)
		{
			if(i&(1<<j++)) subs.insert(e);
		}
		res.insert(subs);
	}
	return res;
}


int main()
{
	set<char> s{'a','b','c','d'};
	auto res = powerSet(s);
	for(auto r:res){
	    for(auto e:r)
	        cout << e << ", ";
	    cout << endl;
	}
	
	return 0;
}