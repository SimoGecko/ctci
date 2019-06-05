// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>

using namespace std;

const vector<char> opchar{ '+', '-', '*', '/' };

float calculate(const string& s) {
	// 1. parse all doubles in the string
	string numbers(s);
	for (auto op : opchar)
		replace(numbers.begin(), numbers.end(), op, ' ');

	vector<float> nums;
	stringstream ss(numbers);
	float num;
	while (ss >> num) nums.push_back(num);

	// 2. parse all operators in the string
	vector<char> ops;
	for (auto c : s) {
		if (find(opchar.begin(), opchar.end(), c) != opchar.end()) {
			ops.push_back(c);
		}
	}


	// 3 create list pairs
	list<pair<char, float>> x;
	for (int i = 0; i<ops.size(); i++) {
		x.push_back(make_pair(ops[i], nums[i]));
	}
	x.push_back(make_pair(' ', nums[nums.size() - 1]));

	// 4. iterate over operators, carry out */
	auto it = x.begin();
	while (it != x.end()) {
		if (it->first == '*') {
			next(it)->second = it->second*next(it)->second;
			it = x.erase(it);
		}
		else if (it->first == '/') {
			next(it)->second = it->second/next(it)->second;
			it = x.erase(it);
		}
		else {
			++it;
		}
	}
	// 5. carry out +-
	it = x.begin();
	while (it != x.end()) {
		if (it->first == '+') {
			next(it)->second = it->second + next(it)->second;
			it = x.erase(it);
		}
		else if (it->first == '-') {
			next(it)->second = it->second - next(it)->second;
			it = x.erase(it);
		}
		else {
			++it;
		}
	}

	// 6. return result
	return x.begin()->second;
}

int main() {
	while (true) {
		cout << "Insert the expression to compute: " << endl;
		string s; cin >> s;
		cout << "= " << calculate(s) << endl;
	}
	return 0;
}
