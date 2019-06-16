// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>

using namespace std;


//this function is given already
bool isSubstring(const string& small, const string& big) {
	if (small.size() > big.size()) return false;

	for (size_t i = 0; i <= big.size() - small.size(); ++i) {
		if (small == big.substr(i, small.size()))return true;
	}
	return false;
}


//check if s2 is rotation of s1
bool isRotation(const string& s1, const string& s2) {
	return isSubstring(s1, s2+s2);
}



int main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	bool ans = isRotation(s1, s2);
	cout << s1 << (ans ? " is " : " is not ") << "a rotation of " << s2 << endl;

	int c; cin >> c;
	return 0;
}