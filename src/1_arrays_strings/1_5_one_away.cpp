// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>

using namespace std;


bool oneAway(const string& s1, const string& s2){
	int d = s1.size()-s2.size();
	if(abs(d)>1) return false;

	bool anomaly = false;
	size_t i = 0, j = 0;
	while(i<s1.size() && j<s2.size()){
		if(s1[i]==s2[j]) { ++i; ++j; }
		else{
			if(anomaly) return false;
			anomaly = true;
			if(d==0) { ++i; ++j; }
			else if(d==1) { ++i; }
			else { ++j; }
		}
	}
	return (i==s1.size() && j==s2.size()) || !anomaly;
}


int main()
{
	cout << "Checks if two string differ in at most one position (change, addition or removal of 1 char). " << endl << endl;

	while(true){
		cout << "Insert strings s1, s2: " << endl;
		string s1, s2; cin >> s1 >> s2;
		cout << "one away = " << (oneAway(s1, s2)? "true" : "false") << endl << endl;
	}
	return 0;
}