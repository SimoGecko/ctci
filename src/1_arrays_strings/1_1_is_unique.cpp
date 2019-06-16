// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


//using additional DS (space)
// O(100) space
// O(n) time
const char minAscii = ' '; // 32
const char maxAscii = '~'; // 126
						   //assume allowed chars are a-z A-Z 0-9

bool isUnique1(const string& s) {
	bool seen[maxAscii - minAscii + 1];
	for (size_t i = minAscii; i <= maxAscii; ++i) seen[i - minAscii] = false;

	for (size_t i = 0; i<s.size(); ++i) {
		if (seen[s[i] - minAscii]) return false;
		seen[s[i] - minAscii] = true;
	}
	return true;
}


bool isUnique2(const string& s) { // using set
	unordered_set<char> charset;
	for (size_t i = 0; i<s.size(); ++i) {
		if (charset.count(s[i])>0) return false;
		charset.insert(s[i]);
	}
	return true;
}

bool isUnique3(const string& s) { // using bit vector
								  //assumes only lowercase a-z
	int bs = 0;
	for (size_t i = 0; i<s.size(); ++i) {
		int idx = s[i] - 'a';
		if (bs&(1 << idx)) return false;
		bs |= (1 << idx);
	}
	return true;
}


//without using any additional space
// O(1) space
// O(n logn) time
void swapChars(char& c1, char& c2) {
	char tmp = c1;
	c1 = c2;
	c2 = tmp;
}

//in-situ quicksort
void sortString(string& s, int l, int r) {
	if (l >= r) return;

	//partition
	int p = r;
	int i = l;
	int j = r - 1;

	while (i < j) {
		while (s[i] <= s[p] && i < r-1) i++;
		while (s[j] >  s[p] && j > l) j--;
		if (i < j) {
			swapChars(s[i++], s[j--]);
		}
	}
	while (s[i] <= s[p] && i < r) i++; // forgot this line
	swapChars(s[i], s[p]);

	//recurse
	sortString(s, l, i - 1);
	sortString(s, i + 1, r);
}


bool isUnique4(const string& s) { // sorting
	string s2(s); // copy
	sortString(s2, 0, s2.size() - 1);

	for (size_t i = 0; i<s2.size() - 1; ++i) {
		if (s2[i] == s2[i + 1]) return false;
	}
	return true;
}



//--------------

int main() {
	cout << "Computes if a string has all unique characters. " << endl << endl;
	while (true) {
		cout << "Insert string s: " << endl;
		string s; cin >> s;
		
		cout << "all unique characters: " << endl;

		cout << "\tmethod 1: " << (isUnique1(s)? "yes" : "no") << endl;
		cout << "\tmethod 2: " << (isUnique2(s)? "yes" : "no") << endl;
		cout << "\tmethod 3: " << (isUnique3(s)? "yes" : "no") << endl;
		cout << "\tmethod 4: " << (isUnique4(s)? "yes" : "no") << endl << endl;
	}
	return 0;
}