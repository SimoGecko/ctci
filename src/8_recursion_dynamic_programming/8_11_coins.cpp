// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;
using vvi = vector<vector<int>>;


constexpr int coins[]{ 1,5,10,25 }; // [] right place!


vector<int> BackTrack(vvi& T, vvi& res, vector<int> current, int i, int j)
{


}

int countCoinWays(const int n) {
	const int c = sizeof(coins) / sizeof(*coins);

	vvi T(c + 1, vector<int>(n + 1, 0)); // table
	T[0][0] = 1;

	for (int j = 1; j <= c; ++j) {
		for (int i = 0; i <= n; ++i) {
			int pv = i - coins[j - 1]; // previous value
			T[j][i] = T[j - 1][i] + (pv >= 0 ? T[j][pv] : 0);
		}
	}

	vector<vector<int>> res;


	return T[c][n];
}


int main() {
	while (true) {
		cout << "Insert number of cents n: " << endl;
		int n; cin >> n;
		cout << "There are " << countCoinWays(n) << " ways to return " << n << " cents" << endl;
	}

	return 0;
}