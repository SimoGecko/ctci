// (c) Simone Guggiari 2019 - DAILY CODING

/* (Google)
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 * Bonus: Can you do this in one pass?
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


bool sumUpTo(const vector<int>& a, int k)
{
	unordered_set<int> seen;
	for(auto& e: a)
	{
		if(seen.count(k-e)>0) return true;
		seen.insert(e);
	}
	return false;
}


int main()
{
	vector<int> a = {10, 15, 3, 7};
	int k = 17;
	cout << "found pair that sums up to k? " << (sumUpTo(a, k)?"yes" : "no") << endl;;
	
	return 0;
}