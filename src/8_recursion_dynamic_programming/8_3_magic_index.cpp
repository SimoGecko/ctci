#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMagicIndex(vector<int> a)
{
	int l=0, r = a.size();
	while(l<r)
	{
		int m = (l+r)/2;
		if(a[m]==m)return m;
		else if(a[m]>m) r = m;
		else l = m+1;
	}
	return -1;
}

int main()
{

	while(true)
	{
		cout << "Insert n: " << endl;
		int n; cin >> n;

		vector<int> a;
		for (int i = 0; i < n; ++i)
		{
			int x = rand()%(3*n)-n; // could use better sequences
			if(find(a.begin(), a.end(), x)==a.end()) // unique x
				a.push_back(x);
		}
		sort(a.begin(), a.end());
		for(auto x:a) cout << x << ", "; cout << endl;

		cout << "magic index = " << findMagicIndex(a) << endl;

	}


	return 0;
}