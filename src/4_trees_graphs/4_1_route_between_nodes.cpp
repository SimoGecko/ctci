// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;


//------------------------ generic graph class used for various exercises

template <typename T>
class Graph {
public:
	Graph(int num = 5) {
		V.reserve(num);
		E.reserve(num);
	}

	Graph(const vector<T>& vertices, const vector<pair<int, int>>& edges, bool bidirectional = false) : Graph(vertices.size()) {
		for (auto& v : vertices) addV(v);
		E.resize(size());
		for (auto& e : edges) addEInt(e.first, e.second, bidirectional);
	}

	void addV(const T& v) {
		V.push_back(v);
	}

	void addE(const T& from, const T& to, bool bidirectional = false) {
		int idx1 = idx(from);
		int idx2 = idx(to);
		if (idx1 == -1 || idx2 == -1) return; // one of them is not found

		addEInt(idx1, idx2);
	}

	

	void addE(function<bool(const T&, const T&)> pred) {
		E.clear();
		E.resize(size());

		for (size_t i = 0; i<size(); ++i) {
			for (size_t j = 0; j<size(); ++j) {
				if (pred(V[i], V[j])) {
					E[i].push_back(j);
				}
			}
		}
	}

	bool connected(const T& from, const T& to, bool bidirectional = false) const {
		int idx1 = idx(from);
		int idx2 = idx(to);
		if (idx1 == -1 || idx2 == -1) return; // one of them is not found

		return conn(idx1, idx2) || (bidirectional && conn(idx2, idx1));
	}

	size_t size() const { return V.size(); }

	vector<T> neighbors(const T& vertex) const {
		vector<T> ans;
		int v = idx(vertex);
		if (v == -1) return ans; // not found

		for (auto& e : E[v]) ans.push_back(V[e]);

		return move(ans);
	}



private:
	vector<T> V;
	vector<vector<int>> E;

	int idx(const T& v) const {
		auto it = find(begin(V), end(V), v);
		if (it == end(V)) return -1;
		return it - begin(V);
	}

	bool conn(int a, int b) const {
		return find(begin(E[a]), end(E[a]), b) != end(E[a]);
	}

	void addEInt(int idx1, int idx2, bool bidirectional = false) {

		E[idx1].push_back(idx2);
		if (bidirectional) E[idx2].push_back(idx1);
	}
};

//------------------------

template<typename T>
bool existsPath(const Graph<T>& G, T v1, T v2) {
	//perform double BFS

	unordered_map<T, bool> vis1, vis2; // visited starting from node i
	queue<T> Q;

	vis1[v1] = true;
	vis2[v2] = true;
	Q.push(v1);
	Q.push(v2);

	while (!Q.empty()) {
		T v = Q.front(); Q.pop();

		if (vis1[v] && vis2[v]) return true; // found match

		unordered_map<T, bool>& vis = vis1[v] ? vis1 : vis2; // alias, which search

		for (T& w : G.neighbors(v)) {
			if (!vis[w]) {
				vis[w] = true;
				Q.push(w);
			}
		}
	}
	return false;
}



int main() {
	cout << "Finds if there is a path between two vertices: " << endl << endl;


	vector<string> graph = {
		{ "      2            " },
		{ "      |            " },
		{ "      |            " },
		{ "0-----1-----5     6" },
		{ "      |     |     |" },
		{ "      |     |     |" },
		{ "      3-----4     7" },
	};
	for (auto& s : graph) cout << "\t" << s << endl;
	cout << endl;

	//build graph
	Graph<int> G(
		//{ "0","1","2","3","4","5","6","7" },
		{ 0,1,2,3,4,5,6,7 },
		{ { 0,1 },{ 1,2 },{ 1,3 },{ 1,5 },{ 3,4 },{ 4,5 },{ 6,7 } },
		true
	);

	//find path
	while (true) {
		cout << "Insert ints v1, v2: " << endl;
		int v1, v2; cin >> v1 >> v2;
		cout << "path: " << (existsPath(G, v1, v2) ? "yes" : "no") << endl << endl;
	}

	return 0;
}