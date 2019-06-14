// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxNoBookedMin(const vector<int>& x){

	vector<int> b(x); // copy
	//corner cases
	if(b.empty()) return 0;
	//erase-remove idiom
	b.erase(remove(begin(b), end(b), 0), end(b));


	int T[] = {0, b[0]};
	if(b.size()%2==0) b.push_back(0);
	for(size_t i=1; i<b.size()-1; i+=2){
		T[0] = max(T[1], b[i  ]+T[0]);
		T[1] = max(T[0], b[i+1]+T[1]);
	}
	return T[1];
}



int main()
{
	vector<int> b = {30, 15, 60, 75, 45, 15, 15, 45};
	cout << "max # minutes = " << maxNoBookedMin(b) << endl;
	return 0;
}