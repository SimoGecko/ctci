// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress(const string& s) {
	if (s.empty()) return "";

	stringstream ans;

	char c = s[0];
	int x = 1;
	for (size_t i = 1; i<s.size(); ++i) {
		if (c == s[i]) x++;
		else {
			ans << c << x;
			c = s[i];
			x = 1;
		}
	}
	ans << c << x;
	string ansstr = ans.str();
	return ansstr.size()<s.size() ? ansstr : s;
}




int main() {
	cout << "Compresses string with repeated characters. " << endl << endl;
	while (true) {
		cout << "Insert string s: " << endl;
		string s; cin >> s;
		//s = "aabcccccaaa";
		cout << "compressed = " << compress(s) << endl << endl;
	}
	return 0;
}