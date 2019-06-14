// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

constexpr int d = 2;


int clamp(int v, int lo, int hi) {
	return max(lo, min(hi, v));
}

int countNumDigitsD(const int N) {
	int sum = 0;
	int K = floor(log10(N) + 1);

	for (int i = 0; i < K; ++i) {
		int p10i = pow(10, i);
		sum += p10i * (N / (p10i * 10)); // how many full groups
		int base = d * p10i - 1; // the number d99...
		sum += clamp(N % (p10i * 10) - base, 0, p10i);
	}
	return sum;
}

int countNumDigitsDBruteForce(const int N){ // used to check only
	int sum=0;
	for(int i=0; i<=N; ++i){
		string s = to_string(i);
		for(size_t j=0; j<s.size(); j++)
			if(s[j]==('0'+d)) sum++;
	}
	return sum;
}


int main() {

	cout << "Computes the number of digits " << d << " in range  [0, n]." << endl;

	while (true) {
		cout << "Insert n: " << endl;
		int n; cin >> n;
		cout << "result = " << countNumDigitsD(n) << endl << endl;
		//cout << "bruteforce = " << countNumDigitsDBruteForce(n) << endl << endl;
	}
	return 0;
}