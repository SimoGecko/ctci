// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;




//method 1: sort & compare
//sort comes from previous exercise
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
	while (s[i] <= s[p] && i < r) i++;
	swapChars(s[i], s[p]);

	//recurse
	sortString(s, l, i - 1);
	sortString(s, i + 1, r);
}


bool isPermutation1(const string& s1, const string& s2){
	if(s1.size()!=s2.size())return false;

	string s1c(s1), s2c(s2);
	sortString(s1c, 0, s1c.size()-1);
	sortString(s2c, 0, s2c.size()-1);

	for(size_t i=0; i<s1c.size(); ++i){
		if(s1c[i]!=s2c[i]) return false;
	}
	return true;
}

//method 2: count characters
unordered_map<char, int> countChars(const string& s){
	unordered_map<char, int> m;
	for(size_t i=0; i<s.size(); ++i)
		m[s[i]]++;
	return move(m);
}

bool isPermutation2(const string& s1, const string& s2){
	if(s1.size()!=s2.size())return false;

	auto c1 = countChars(s1);
	auto c2 = countChars(s2);

	for(auto& e : c1){
		auto it = c2.find(e.first);
		if(it == end(c2) || it->second != e.second) // char not found or different count
			return false;
	}
	return true;
}




int main()
{
	cout << "Checks if two strings are the same permutation. " << endl << endl;
	while (true) {
		cout << "Insert string s1, s2: " << endl;
		string s1, s2; cin >> s1 >> s2;
		
		cout << "permutations: " << endl;

		cout << "\tmethod 1: " << (isPermutation1(s1, s2)? "yes" : "no") << endl;
		cout << "\tmethod 2: " << (isPermutation1(s1, s2)? "yes" : "no") << endl << endl;
	}
	return 0;
}