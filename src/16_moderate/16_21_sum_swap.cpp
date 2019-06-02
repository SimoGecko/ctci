// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool findSwapEqualSum(vector<int>& a, vector<int>& b, pair<int, int>& sol)
{
	int sa = 0, sb = 0;
	for(auto e : a) sa += e;
	for(auto e : b) sb += e;
	
	int d = sa-sb;
	if(abs(sa-sb)%2==1) return false;
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	size_t i = 0, j = 0;
	while(i<a.size() && j<b.size())
	{
		if(a[i]-b[j]==d/2){
			sol = make_pair(a[i],b[j]);
			return true;
		}
		else if(a[i]-b[j]>d/2) j++;
		else i++;
	}
	return false;
}


int main()
{
	vector<int> as{20, 14, 5, 15, 2, 7, 10, 16, 11};//{4,1,2,1,1,2};
	vector<int> bs{19, 12, 8, 4, 15, 9, 3, 18, 6, 1, 13};//{3,6,3,3};
	pair<int, int> sol;
	
	if(findSwapEqualSum(as, bs, sol)){
		cout << "found items: " << sol.first << ", " << sol.second << endl;
	}else{
		cout << "swap pair not found" << endl;
	}
	return 0;
}