// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <algorithm>

using namespace std;

constexpr int N = 4;

const int char2idx(const char c) {
	if (c == 'R') return 0;
	if (c == 'Y') return 1;
	if (c == 'G') return 2;
	if (c == 'B') return 3;
	return -1;
}

pair<int, int> computeHits(char s[N], char g[N]) // solution, guess
{
	int k = 0, w = 0; // black and white

	for (int i = 0; i<N; i++) {
		if (s[i] == g[i]) {
			k++;
			s[i] = g[i] = ' ';
		}
	}

	int ss[N], gs[N]; // guess and sol sum
	for (int i = 0; i<N; i++) { ss[i] = gs[i] = 0; }
	for (int i = 0; i<N; i++) {
		if (s[i] != ' ') ss[char2idx(s[i])]++;
		if (g[i] != ' ') gs[char2idx(g[i])]++;
	}
	for (int i = 0; i<N; i++) {
		w += min(ss[i], gs[i]);
	}

	return make_pair(k, w);
}

int main() {
	while (true) {
		cout << "Insert solution sequence and guess (e.g. RYGB): " << endl;
		char s[N], g[N];
		cin >> s >> g;
		auto sol = computeHits(s, g);
		cout << "K=" << sol.first << " W=" << sol.second << endl;
	}
	return 0;
}