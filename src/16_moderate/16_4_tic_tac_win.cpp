#include <iostream>
#include <vector>

using namespace std;

const int N = 3;

vector<vector<pair<int, int> > > pairs;


void makePairs() {
	pairs.reserve(N * 2 + 2);
	//forgot to initialize
	for (size_t i = 0; i < N*2+2; i++) {
		pairs.push_back(vector<pair<int, int > >());
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			pairs[i    ].push_back(make_pair(i, j)); // horiz
			pairs[i + N].push_back(make_pair(j, i)); // vertical
		}
		pairs[2 * N    ].push_back(make_pair(i, i)); // diagonal
		pairs[2 * N + 1].push_back(make_pair(i, N - 1 - i));
	}
}

bool allSame(const vector<int>& v) {
	if (v.empty()) return false;
	for (size_t i = 1; i < v.size(); ++i) {
		if (v[0] != v[i])return false;
	}
	return true;
}

int won(const int board[N][N]) {
	int won = 0;
	for (auto l : pairs) //test this line
	{
		vector<int> val; // save values from table
		for (auto c : l) {
			val.push_back(board[c.first][c.second]);
		}
		if (allSame(val) && val[0] != 0) { // 1 or 2
										   //we have a winner
			if (won != 0 && val[0] != won) {
				return -1; // error, multiple winners
			}
			else {
				won = val[0];
			}
		}
	}
	return won;
}

int main() {
	makePairs();

	int board[N][N] = {
		{ 1, 1, 2 },
		{ 0, 0, 2 },
		{ 2, 0, 2 }
	};

	cout << "won: " << won(board) << endl;


	int z; cin >> z;
	return 0;
}

//corrections:
	// initialize array sizes (board[N][N])
	// no need to specify make_pair<template>
	// forgot to initialize vector!