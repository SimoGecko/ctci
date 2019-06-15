// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;




template <typename T>
class Graph {

public:
	Graph(int num = 0) : n(num) {
		V.reserve(n);
		E.reserve(n);
	}

	void AddV(const T& v) {
		V.push_back(v);
		n = V.size();
	}

	//void AddE(const T& from, const T& to){ }

	void AddAllE(function<bool(const T&, const T&)> pred) {
		E.clear();
		E.resize(n);

		for (size_t i = 0; i<n; ++i) {
			for (size_t j = 0; j<n; ++j) {
				if (pred(V[i], V[j])) {
					E[i].push_back(j);
				}
			}
		}
	}


	int BFS(const T& start, const T& target) const {

		int s = idx(start);
		int t = idx(target);
		if (s == -1 || t == -1) return 0; // s or t not found

		queue<pair<int, int>> Q;
		vector<bool> vis(n, false);

		Q.push({ s, 1 });
		vis[s] = true;

		while (!Q.empty()) {
			auto p = Q.front(); Q.pop();
			int v = p.first;
			if (v == t) return p.second;

			for (int w : E[v]) {
				if (!vis[w]) {
					vis[w] = true;
					Q.push({ w, p.second + 1 });
				}
			}
		}
		return 0;
	}

private:
	int n;
	vector<T> V;
	vector<vector<int>> E;

	int idx(const T& v) const {
		auto it = find(begin(V), end(V), v);
		if (it == end(V)) return -1;
		return it - begin(V);
	}
};



bool differOneLetter(const string& a, const string& b) {
	if (a.size() != b.size()) return false;
	bool set = false;
	for (size_t i = 0; i<a.size(); ++i) {
		if (a[i] != b[i]) {
			if (set) return false;
			set = true;
		}
	}
	return true;
}




int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	//add begin if not present
	if (find(begin(wordList), end(wordList), beginWord) == end(wordList)) wordList.push_back(beginWord);

	int ws = beginWord.size();
	if (endWord.size() != ws) return 0;

	//add vertices
	Graph<string> G(wordList.size());
	for (auto& w : wordList) if (w.size() == ws) G.AddV(w);

	//create edges
	G.AddAllE(differOneLetter);


	//find shortest path between two nodes
	return G.BFS(beginWord, endWord);

}








int main() {

	vector<string> words = { "hot", "dot", "dog", "lot", "log", "cog" };
	string beginWord = "hit";
	string endWord = "cog";
	cout << ladderLength(beginWord, endWord, words) << endl;

	int c; cin >> c;
	return 0;
}