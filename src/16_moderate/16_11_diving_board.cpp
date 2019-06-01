#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

		   
vector<float> allBoardLengths(int k, float s, float l){
	vector<float> result;

	for (int i = 0; i <= k; ++i)
	{
		float tot = l*i+(k-i)*s;
		if(find(result.begin(), result.end(), tot)==result.end()){
			result.push_back(tot); // unique
		}
	}
	return result;
}


int main() {

	cout << "Insert k, s, l: " << endl;
	int k, s, l;
	cin >> k >> s >> l;

	vector<float> res = allBoardLengths(k, s, l);
	for (auto t : res) cout << t << ", ";
	cout << endl;

	int z; cin >> z;
	return 0;
}