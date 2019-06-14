// Simone Guggiari 2019 - M&F Engineering

// 3. DeepestPit
// Given an array of integers, and a bitonic sequence with maximal difference between the middle term and the first and the last terms.


#include <algorithm>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

int msign(int x) { // sign function
	return x < 0 ? -1 : (x > 0 ? 1 : 0);
}

int solution(vector<int>& A) {
	//corner cases for too short lengths
	if (A.size() < 3) return -1;
	//compute delta
	vector<int> d(A.size() - 1); // delta
	for (size_t i = 0; i < A.size() - 1; ++i) {
		d[i] = msign(A[i + 1] - A[i]);
	}
	//compute up/down
	vector<pair<int, int>> ud; // up/down
	ud.push_back({ 0, d[0] * -1 }); // first entry
	for (size_t i = 1; i < d.size() - 1; ++i) {
		int s1 = d[i - 1];
		int s2 = d[i];
		if (s1 != s2) {
			ud.push_back({ i, msign(s1 - s2) });
		}
	}
	ud.push_back({ d.size(), d[d.size() - 1] }); // last entry
	//iterate to find valid
	//tuple<int, int, int> pqr;
	int best = -1;
	for (size_t i = 0; i < ud.size() - 2; ++i) {
		int p = ud[i].second; // U=1
		int q = ud[i + 1].second; // D=-1
		int r = ud[i + 2].second; // U=1
		if (p == 1 && q == -1 && r == 1) {//pattern match UDU
			int P = ud[i].first;
			int Q = ud[i + 1].first;
			int R = ud[i + 2].first;
			int depth = min(A[P] - A[Q], A[R] - A[Q]);
			if (depth > best) {
				best = depth;
				//pqr = make_tuple(P, Q, R);
			}
		}
	}
	//cout << "(P, Q, R) = " << get<0>(pqr) << ", " << get<1>(pqr) << ", " << get<2>(pqr) << endl;
	return best;
}


/*
 * A non-empty array A consisting of N integers is given.
 * A pit in this array is any triplet of integers (P, Q, R) such that:
 *  - 0 ≤ P < Q < R < N;
 *  - sequence [A[P], A[P+1], ..., A[Q]] is strictly decreasing,
 *    i.e. A[P] > A[P+1] > ... > A[Q];
 *  - sequence A[Q], A[Q+1], ..., A[R] is strictly increasing,
 *    i.e. A[Q] < A[Q+1] < ... < A[R].
 * 
 * The depth of a pit (P, Q, R) is the number min{A[P] − A[Q], A[R] − A[Q]}.
 * 
 * For example, consider array A = [0, 1, 3, -2, 0, 1, 0, -3, 2, 3] consisting of 10 elements:
 * triplet (2, 3, 4) is one of pits in this array, because sequence [A[2], A[3]] is
 * strictly decreasing (3 > −2) and sequence [A[3], A[4]] is strictly increasing
 * (−2 < 0). Its depth is min{A[2] − A[3], A[4] − A[3]} = 2.
 * Triplet (2, 3, 5) is another pit with depth 3.
 * Triplet (5, 7, 8) is yet another pit with depth 4.
 * There is no pit in this array deeper (i.e. having depth greater) than 4.
 * 
 * Write a function:
 * 	int solution(vector<int> &A);
 * that, given a non-empty array A consisting of N integers, returns the depth of the deepest pit in array A. The function should return −1 if there are no pits in array A.
 * 
 * For example, consider array A = [0, 1, 3, -2, 0, 1, 0, -3, 2, 3] consisting of 10 elements:
 * the function should return 4, as explained above.
 * 
 * Write an efficient algorithm for the following assumptions:
 *  - N is an integer within the range [1..1,000,000];
 *  - each element of array A is an integer within the range
 *    [−100,000,000..100,000,000].
 */