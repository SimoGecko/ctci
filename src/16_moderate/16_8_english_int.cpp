#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

const string minu  = {"Minus"};
const string digs[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}; // 0123456789
const string tens[] = {"-", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; //10-90
const string spec[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; // 10-19
const string decs[] = {"Hundred", "Thousand", "Million", "Billion", "Trillion"}; // 100, 10^3, 10^6, 10^9, 10^12


string joinwithspaces(const vector<string>& v){
	if(v.empty()) return "";
	string res = v[0];
	for(size_t i = 1; i<v.size(); i++) res += " " + v[i];
	return res;
}


string English999(int n){
	n = abs(n)%1000;

	if(n==0) return digs[0];

	int h = n/100;
	int d = (n%100)/10;
	int u = (n%10);

	vector<string> rv;
	if(h>0) { rv.push_back(digs[h]); rv.push_back(decs[0]);} // Two Hundred
	if(d>0) { if(d==1) rv.push_back(spec[u]); else rv.push_back(tens[d]); } // Eleven | Twenty
	if(u>0) { if(d!=1) rv.push_back(digs[u]); } // One

	return joinwithspaces(rv);
	//return (h>0?(digs[h] + " " + decs[0] + " ") : "") + (d>0?(d==1?spec[u] : tens[d] + " ") : "") + ((d!=1 && u>0)?digs[u]:"");
}


string EnglishInt(int n){
	vector<string> rv;

	if(n==0) return digs[0];
	if(n<0){ rv.push_back(minu); n *= -1; }
	//n %= 1'000'000'000; //max: 999 Billions (int <=)

	int b = (n/1000'000'000) % 1000;
	int m = (n/1000'000) % 1000;
	int t = (n/1000) % 1000;
	int u = (n/1) % 1000;

	if(b>0){rv.push_back(English999(b)); rv.push_back(decs[3] + (b>1?"s":""));}
	if(m>0){rv.push_back(English999(m)); rv.push_back(decs[2] + (m>1?"s":""));}
	if(t>0){rv.push_back(English999(t)); rv.push_back(decs[1]);}
	if(u>0){rv.push_back(English999(u));}

	return joinwithspaces(rv);
}



int main(){
	while(true){
		cout << "Insert number: ";
		int n; cin >> n;
		cout << n << " is pronounced \"" << EnglishInt(n) << "\"" << endl;
	}

	return 0;
}