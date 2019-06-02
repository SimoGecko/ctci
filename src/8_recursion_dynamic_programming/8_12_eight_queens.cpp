// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

constexpr int N = 6;

#define EMPTY 0
#define QUEEN 1
#define THREAT 2

//string box = "┌─┐│ │└─┘";
string box = "+-+| |+-+";
int sum = 0;

int dx[]{ 1,-1,1,-1 };
int dy[]{ 1,-1,-1,1 };

class Table {
public:
	Table() {
		for (int i = 0; i<N*N; i++) t[i] = EMPTY;
	}
	Table(Table& src) {
		for (int i = 0; i<N*N; i++) t[i] = src[i];
	}

	void mark(int r, int c) {
		//cout << "place " << r << " " << c << endl;
		for (int i = 0; i<N; i++) {
			set(r, i, THREAT); // horizontal
			set(i, c, THREAT); // vertical
			//set((r + i) % N, (c + i) % N, THREAT); // diagonal
			//set((r + i) % N, (c - i + N) % N, THREAT);
		}
		for (int i = 0; i < 4; i++) {
			int r1 = r; int c1 = c;
			while (0 <= r1 && r1 < N && 0 <= c1 && c1 < N) {
				set(r1, c1, THREAT); // diagonal
				r1 += dx[i];
				c1 += dy[i];
			}
		}
		set(r, c, QUEEN);
	}

	bool free(int r, int c) { return get(r, c) == EMPTY; }

	void print() {
		cout << box[0]; for (int i = 0; i<N; i++) cout << box[1]; cout << box[2] << endl;
		for (int r = 0; r<N; r++) {
			cout << box[3];
			for (int c = 0; c<N; c++) {
				cout << (get(r, c) == QUEEN ? 'O' : ' ');
			}
			cout << box[5] << endl;

		}
		cout << box[6]; for (int i = 0; i<N; i++) cout << box[7]; cout << box[8] << endl;
	}

	void set(int r, int c, char v) { t[r*N + c] = v; }
	const char get(int r, int c) const { return t[r*N + c]; }
	const char operator[](int i) const { return t[i]; }

private:
	char t[N*N];
};

void Iterate(Table& t, int r) {
	if (r == N) {
		t.print();
		sum++;
		return;
	}
	for (int c = 0; c<N; c++) {
		if (t.free(r, c)) {
			Table tc(t);
			tc.mark(r, c);
			Iterate(tc, r + 1);
		}
	}
}

void printAllValidTables() {
	Table t;
	Iterate(t, 0);
}


int main() {

	cout << "All valid tables: " << endl;
	printAllValidTables();
	cout << "Done. There are " << sum << " boards." << endl;
	int z; cin >> z;

	return 0;
}