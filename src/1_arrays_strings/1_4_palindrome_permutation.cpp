// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


//count characters, from previous example
unordered_map<char, int> countChars(const string& s){
	unordered_map<char, int> m;
	for(size_t i=0; i<s.size(); ++i)
		m[s[i]]++;
	return move(m);
}

//must have max 1 character appearing odd number of times
bool isPermutationOfPalindrome(const string& s){
	//spaces are irrelevant

	int maxOdd = 1; //s.size()%2;
	auto m = countChars(s);

	for(auto& e : m){
		if(e.first != ' ' && e.second%2==1) {
			maxOdd--;
			if(maxOdd<0) return false; // exceeded
		}
	}
	return true;
}


int main()
{
	cout << "Computes if a string is a premutation of a palindrome. " << endl;

	while(true){
		cout << "Insert string s: " << endl;
		string s;
		getline(cin, s);// cin >> s;
		cout << (isPermutationOfPalindrome(s)? "yes" : "no") << endl << endl;
	}
	return 0;
}