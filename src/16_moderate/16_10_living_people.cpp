#include <iostream>
#include <vector>

using namespace std;

constexpr int minyear = 1900;
constexpr int maxyear = 2000;
constexpr int maxlife = 50;
		   
vector<pair<int, int> > persons; // (birth, death)

void generatePop(const int n) {
	persons.reserve(n);

	for (int i = 0; i < n; ++i) {
		int birth = minyear + (rand() % (maxyear - minyear + 1));
		int death = birth + rand() % (maxlife + 1);
		if (death>maxyear) death = 0; // not dead yet

		persons.push_back(make_pair(birth, death));
		cout << i << ":\t(" << birth << ", " << death << ")\n";
	}
}

int yearWithMaxPop() {
	vector<int> births((maxyear - minyear + 1), 0);
	vector<int> deaths((maxyear - minyear + 1), 0);

	for (int i = 0; i < persons.size(); ++i) {
		births[persons[i].first - minyear]++;
		if (persons[i].second != 0) // dead
			deaths[persons[i].second - minyear]++;
	}
	int pop = 0, pmax = 0, imax = 0;
	for (int i = minyear; i <= maxyear; ++i) {
		pop += births[i - minyear];
		if (i>minyear) pop -= deaths[i - minyear - 1]; // no longer with us :(
		if (pop>pmax) { pmax = pop; imax = i; }
	}
	return imax;
}

int main() {

	cout << "Insert number of persons: ";
	int n; cin >> n;

	generatePop(n);

	cout << "Year with max pop: " << yearWithMaxPop() << endl;

	int z; cin >> z;
	return 0;
}