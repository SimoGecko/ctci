#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int mindiff(vector<int>& a, vector<int>& b)
{
	if(a.empty() || b.empty()) return -1;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int mi = INT_MAX;
	size_t i = 0, j = 0;
	while(i<a.size() && j<b.size())
	{
		if(abs(a[i]-b[j])<mi) mi = abs(a[i]-b[j]);
		if(a[i]<=b[j]) i++;
		else j++;
	}
	return mi;
}


int main(){

	vector<int> a = {1,3,15,11,12};
	vector<int> b = {23, 127, 235, 19, 8};

	cout << "mindiff = " << mindiff(a, b) << endl;

	return 0;
}

// errors:
// syntax i = j = 0; not allowed
// not const (since sort changes it)