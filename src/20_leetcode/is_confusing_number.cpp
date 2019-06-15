// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

const bool conf[10] = { true, true, false, false, false, false, true, false, true, true };
const int  inv[10] = { 0, 1, -1, -1, -1, -1, 9, -1, 8, 6 };

const int N = 1000'000'000;
const int step = 1000'000;
vector<pair<int, int>> res;

bool isConfusing(const int a) {
	int x = a;
	int res = 0;
	while (x>0) {
		int d = x % 10;
		if (!conf[d]) return false;
		x /= 10;
		res = res * 10 + inv[d];
	}
	return a != res;
}

int confusingNumberII(int N) {
	int sum = 0;

	for (int i = 1; i <= N; ++i) {
		if (isConfusing(i)) sum++;

		if (i%step == 0) {
			if(res.empty() || res.back().second!=sum)
				res.push_back({i/step, sum });
		}
	}
	return sum;
}

int main() {
	/*
	while (true) {
		cout << "Insert n: " << endl;
		int n; cin >> n;
		clock_t begin = clock();
		int ans = confusingNumberII(n);
		clock_t end = clock();
		double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

		cout << "ans = " << ans << endl;
		cout << "time = " << elapsed_secs << endl;
	}*/

	confusingNumberII(N);

	ofstream outFile("my_file.txt");
	// the important part
	for (const auto &e : res) outFile << "{"<<e.first << "," << e.second << "},";

	return 0;
}

