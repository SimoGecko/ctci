// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

pair<int, int> shortestSupersequence(const vector<int>& A, const vector<int>& b){
	//{-1, -1} signifies no found sequence

	//corner cases
	if(A.size()<b.size()) return {-1, -1};
	if(b.empty()) return {0, 0}; // take no elements

	size_t N = A.size();

	//put elements to find in set (input set)
	unordered_set<int> is;
	for(auto& e : b) is.insert(e);

	//find all occurrences of elements
	unordered_map<int, vector<size_t>> occ;
	occ.reserve(is.size());
	for(size_t i=0; i<N; ++i){
		if(is.count(A[i])>0) occ[A[i]].push_back(i);
	}

	//if not all found, return not possible
	if(occ.size()<is.size()) return {-1, -1};

	//store index of current considered element and all possible positions
	vector<pair<size_t, vector<size_t>>> x;
	x.reserve(occ.size()); // not important which occurrence is which, just want to find one of each
	for(auto& o: occ) x.push_back({0, move(o.second)});

	//iterate, find solution
	pair<int, int> ans;
	size_t bestN = N+1;

	while(true){
		size_t mmin = N; // like INT_MAX; INT_MIN
	    size_t mmax = 0;

		for(auto& e : x){
			size_t p = e.second[e.first]; // index elem
			mmin = min(mmin, p);
			mmax = max(mmax, p);
		}

		if(mmax-mmin+1<bestN){
			ans = make_pair(mmin, mmax);
			bestN = mmax-mmin+1;
		}

		for(auto& e : x){
			size_t p = e.second[e.first]; // index elem
			if(p==mmin){ // it's the left-most
				e.first++;
				if(e.first>=e.second.size()) {
					// no more elements
					return ans;
				}
			}
		}
	}
	return {-1, -1}; 
}


int main()
{
	
	vector<int> A = {7, 5, 9, 0, 2, 1, 3, 5, 7, 9, 1, 1, 5, 8, 8, 9, 7};
	vector<int> b = {1, 5, 9};

	auto res = shortestSupersequence(A, b);
	cout << "found: " << res.first << ", " << res.second << endl;
	return 0;
}