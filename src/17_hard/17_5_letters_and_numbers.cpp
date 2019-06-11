// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

bool isLetter(const string& s){
	return s.size()==1 && (('a'<=s[0] && s[0]<='z') || ('A'<=s[0] && s[0]<='Z'));
}

pair<int, int> longestSubarraySameNoNumLett(const vector<string>& a){
	const int N = a.size();
	vector<bool> x(N, false);
	for(int i=0; i<N; ++i)
		x[i] = isLetter(a[i]);

	vector<int> delta(2*N+1, -2); // -2 = not seen, -1 = seen at position -1 (pair 0,0 seen before start)
	delta[0+N]=-1;
	int maxL = 0;
	int bestIdx = -1;
	int n0 = 0, n1 = 0;

	for(int i=0; i<N; ++i){
		if(x[i]) n1++; else n0++;
		int d = n0-n1;
		if(delta[d+N]!=-2){ // this delta was seen previously, for the first time at this idx
			int L = i-delta[d+N];
			if(L>maxL){
				maxL = L; bestIdx = i;
			}
		}else{
			delta[d+N]=i; // first time I see this particular delta
		}
	}
	if(bestIdx==-1)return make_pair(-1, -1);
	return make_pair(bestIdx-maxL+1, bestIdx); // both inclusive
}


int main()
{
	while(true){
		cout << "Insert sequence of numbers of single letters: (- to finish inserting)" << endl;
		vector<string> a;
		while(true){
			string s; cin >> s;
			if(s=="-") break;
			a.push_back(s);
		}
		//vector<string> a = {"1", "A", "1", "A", "A", "1", "1", "1", "1", "A", "A"}; // 01011000011
		auto res = longestSubarraySameNoNumLett(a);
		cout << "found subarray of length " << (res.second-res.first+1);
		cout << " ([" << res.first << ", " << res.second << "])" << endl;
	}

	return 0;
}