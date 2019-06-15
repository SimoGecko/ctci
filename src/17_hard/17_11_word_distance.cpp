// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <fstream>

using namespace std;

unordered_map<string, vector<int>> dic;

void processText(const string& test){
	stringstream ss(text);
	int nums = count_if(cbegin(text), cend(text), [](char c){return c == ' ';});
	dic.clear();
	dic.reserve(nums + 1);

	string s; int i=0;
	while(ss>>s){
		if(dic.count(s)==0){
			dic.insert(s, {});
			dic[s].push_back(i++);
		}
	}
}

int wordDist(const string& w1, const string& w2){
	auto it1 = dic.find(w1);
	auto it2 = dic.find(w2);
	if(it1 == end(dic) || it2 == end(dic2)) return -2;
	if(w1==w2) return -1;
	vector<int>& v1 = it1->second;
	vector<int>& v2 = it2->second;

	size_t i = 0;
	int ans = INT_MAX;
	while(i<v1.size() && j<v2.size()){
		int d = v1[i]-v2[j];
		if(abs(d)<ans) ans = abs(d);
		if(d>0) ++j;
		else ++i;
	}
	return ans;
}



int main()
{
	const string fileName = "../0_data/machiavelli_the_prince.txt"
	ifstream inputFile = fopen(fileName);



	
	return 0;
}