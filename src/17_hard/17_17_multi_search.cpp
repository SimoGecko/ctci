// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

class TN{
public:
	TN() : _c(26, nullptr) {};
	TN* child(char c){
		return _c[c-'a'];
	}
	void insert(const string& s, int idx = 0){
		if(idx==s.size()){
			_d.push_back(s);
			return;
		}
		char c = s[idx];
		if(child(c)==nullptr){
			child(c) = new TN();
		}
		child(c)->insert(s, idx+1);
	}
	void find()


private:
	vector<TN*> _c; // childs
	vector<string> _d; // data
}

vector<int> findAllIndexes(const string& b, const vector<string>& T){
	vector<int> ans; ans.reserve(T.size());
}



int main()
{
	
	return 0;
}