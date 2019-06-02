// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> allPermutations(const string& s) {
	set<string> res;
	res.insert("");

	for (size_t i = 0; i < s.size(); ++i) {
		set<string> addset;
		for (auto e : res) {
			for (size_t j = 0; j <= e.size(); j++) {
				string as(e); // added string
				as.insert(j, 1, s[i]);
				addset.insert(as);
			}
		}
		for (auto e : addset) res.insert(e);
	}
	return res;
}


int main() {
	cout << "Insert string of unique chars (short pls): " << endl;
	string s; cin >> s;
	cout << "All the permutations of '" << s << "' are " << endl;
	for (auto str : allPermutations(s))
		cout << str << endl;

	int z; cin >> z;
	return 0;
}