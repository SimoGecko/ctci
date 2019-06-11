// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const vector<int> m = {3, 5, 7}; // multiples
const int N = m.size();

int findKthMultiple(const size_t K){
	vector<int> res = {1};
	vector<int> idx(N, 0);

	while(res.size()<K){
		vector<int> mul;
		for(int i=0; i<N; ++i){
			mul.push_back(res[idx[i]]*m[i]);
		}
		int min = *min_element(begin(mul), end(mul));
		for(int i=0; i<N; ++i){
			if(res[idx[i]]*m[i] == min){
				++idx[i]; // this index was consumed
			}
		}
		res.push_back(min);
	}
	
	cout << "["; for(auto& e : res) cout << e << ", "; cout << "]" << endl;
	return res[K-1];
}


int main()
{
	cout << "Computes Kth smallest multiple of ";
	for(auto& e : m ) cout << e << ", ";
	cout << endl << endl;

	while(true){
		cout << "Insert k: " << endl;
		int k; cin >> k;
		cout << "result = " << findKthMultiple(k) << endl << endl;
	}
	return 0;
}