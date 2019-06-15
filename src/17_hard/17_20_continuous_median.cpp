// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>
#include <string> // forgot this, caused crashing

using namespace std;

vector<int> minH, maxH; // min/max heap


double findMedian() {
	if (maxH.empty()) return -1;
	if (maxH.size() > minH.size()) return maxH.front();
	double ans = maxH.front() - minH.front();
	return ans / 2;
}


void add(int x) {
	//double dm = findMedian();
	//int m = static_cast<int>(round(dm));

	bool gol = (maxH.empty() || x < maxH.front() || (minH.size() == maxH.size() && x <= -minH.front()));

	if (gol && maxH.size() > minH.size()) {
		//move one elem left
		int e = maxH.front();
		pop_heap(begin(maxH), end(maxH));
		maxH.pop_back();

		//insert in other
		minH.push_back(-e);
		push_heap(begin(minH), end(minH));

	}
	else if (!gol && maxH.size() == minH.size()) {
		//move one elem right
		int e = -minH.front();
		pop_heap(begin(minH), end(minH));
		minH.pop_back();

		//insert in other
		maxH.push_back(e);
		push_heap(begin(maxH), end(maxH));
	}

	if (gol) {
		//add to maxH
		maxH.push_back(x);
		push_heap(begin(maxH), end(maxH));

	}
	else {
		//add to minH, inverting
		minH.push_back(-x);
		push_heap(begin(minH), end(minH));
	}
}




//-------- helper

vector<int> t; // to test & make sure


void printMedian(const vector<int>& A) {
	cout << "[";
	for (size_t i = 0; i < A.size(); ++i) {
		if (i == (A.size() - 1) / 2) cout << "|" << A[i] << "|, ";
		else cout << A[i] << ", ";
	}
	cout << "]" << endl;
}


int main() {
	cout << "Add elements and get running median" << endl << endl;
	cout << "Insert number to add, write 'm' to get median" << endl;
	while (true) {
		string s; cin >> s;
		if (s == "M" || s == "m") {
			//test
			sort(begin(t), end(t));
			printMedian(t);

			//actual
			cout << "median = " << findMedian() << endl;
		}
		else {
			int x = stoi(s);
			add(x);
			t.push_back(x);
		}
	}
	return 0;
}