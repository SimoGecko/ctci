// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printPairsThatSumTo(const vector<int>& a, int s)
{
	unordered_set<int> hash;
	for(int e : a)
	{
		if(hash.find(s-e) != hash.end())
			cout << e << " + " << (s-e) << endl;
		hash.insert(e);
	}
}


int main()
{
    vector<int> a {17, 5, 29, 21, 2, 12, 16, 13, 15, 25, 27, 20, 7, 6, 28, 4, 25, 1, 18, 3, 23, 30, 22, 11, 10, 9, 14, 24, 8, 19};

    cout << "Please insert the target sum: " << endl;
    int sum; cin >> sum;
	cout << "Finding all pairs that sum to " << sum << endl;

	printPairsThatSumTo(a, sum);

	return 0;
}