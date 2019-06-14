// Simone Guggiari 2019 - M&F Engineering
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
    ud.push_back({ 0,  d[0] * -1 }); // first entry
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


int main() {
    vector<int> A = { 0, 1, 3, -2, 0, 0, 0, -3, 2, 3 };
    solution(A);
    return 1;
}