// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vii = vector<pair<int, int>>;
using ii = pair<int, int>;

auto smaller = [](ii& lhs, ii& rhs) {
	return lhs.first < rhs.first && lhs.second < rhs.second;
};


// not working correctly yet

int longestTower(const vii& persons) {
	vii pp(persons); // modifiable
	pp.push_back({ 0,0 }); // ghost person

	sort(begin(pp), end(pp), smaller); // sort is incorrect. must do 2 passes
	vector<int> res(pp.size(), 0);
	for (size_t i = 1; i < pp.size(); ++i) {
		int max = -1;
		for (int j = i - 1; j >= 0; j--) {
			if (smaller(pp[j], pp[i])) {
				if (res[j] > max) {
					max = res[j];
				}
			}
		}
		res[i] = max + 1;
	}
	return *max_element(begin(res), end(res));
}

int main() {
	cout << "How many persons are stackable: " << endl;
	vii persons = {
		{65, 100},
		{70, 150},
		{560,  90},
		{75, 190},
		{60,  95},
		{68, 110}
	};

	cout << "longest tower = " << longestTower(persons) << endl;
	return 0;
}