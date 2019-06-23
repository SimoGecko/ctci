#include <vector>
#include <functional>
#include <algorithm>

//------------------------ generic graph class used for various exercises

template <typename T>
class Graph {
public:
	Graph(int num = 0) {
		V.reserve(n);
		E.reserve(n);
	}

	Graph(const vector<T>& vertices, const vector<pair<T, T>>& edges, bool bidirectional = false) : Graph(vertices.size()) {
		for(auto& v : vertices) addV(v);
		for(auto& e : edges) addE(e.first, e.second, bidirectional);
	}

	void addV(const T& v) {
		V.push_back(v);
	}

	void addE(const T& from, const T& to, bool bidirectional = false){
		int idx1 = idx(from);
		int idx2 = idx(to);
		if(idx1==-1 || idx2==-1) return; // one of them is not found

		E[idx1].push_back(idx2);
		if(bidirectional) E[idx2].push_back(idx1);
	}


	bool connected (const T& from, const T& to, bool bidirectional = false) const {
		int idx1 = idx(from);
		int idx2 = idx(to);
		if(idx1==-1 || idx2==-1) return; // one of them is not found
		
		return conn(idx1, idx2) || (bidirectional && conn(idx2, idx1));
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

	size_t size() const { return V.size(); }

private:
	vector<T> V;
	vector<vector<int>> E;

	int idx(const T& v) const {
		auto it = find(begin(V), end(V), v);
		if (it == end(V)) return -1;
		return it - begin(V);
	}

	bool conn (int a, int b) const {
		return find(begin(E[a]), end(E[a]), b) != end(E[a]);
	}
};