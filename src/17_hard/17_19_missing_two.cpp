// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>


using namespace std;


int findMissing1(const vector<int>& A, int N = 0){
	if(N==0) N = A.size() + 1; // assume it's missing 1
	long int sum = 0;
	for(auto a : A) sum += a;
	//return miss(sum, N);
	long int expected = N*(N+1)/2;
	return expected-sum;
}

pair<int, int> findMissing2(const vector<int>& A){
	int N = A.size() + 2;
	int sumBoth = findMissing1(A, N);
	int hsum = sumBoth/2;

	long int sum1 = 0, sum2 = 0;
	for(auto a : A) if (a<=hsum) sum1 += a; else sum2 += a;

	int exp1 = hsum*(hsum+1)/2;
	int miss1 = exp1-sum1;
	int exp2 = N*(N+1)/2-exp1;
	int miss2 = exp2-sum2;

	return {miss1, miss2};
}


//------------ helpers

void print(const vector<int>& A){
	cout << "[";
	for(auto a : A) cout << a << ", ";
	cout << "]";
}



vector<int> generateMissing(int N, int m){ // generates sequence [1..N] with m missing numbers (assume m<N)
	vector<int> ans(N);
	iota(begin(ans), end(ans), 1);
	random_shuffle(begin(ans), end(ans));

	//remove
	while(m--){
		int i = rand()%ans.size();
		ans.erase(begin(ans) + i);
	}

	return move(ans);
}

int main()
{
	cout << "Find missing element from array: " << endl << endl;

	while(true){
		cout << "Insert #missing numbers (1 or 2): " << endl;
		int d; cin >> d;
		if(d==1 || d == 2){
			cout << "Insert n: " << endl;
			int n; cin >> n;
			vector<int> A = generateMissing(n, d);
			cout << "A = "; print(A); cout << endl;

			//solve
			if(d==1){
				cout << "found one missing: " << findMissing1(A) << endl;
			}else{
				auto ans = findMissing2(A);
				cout << "found two missing: " << ans.first << ", " << ans.second << endl;
			}
		}
		cout << endl;
	}
	return 0;
}