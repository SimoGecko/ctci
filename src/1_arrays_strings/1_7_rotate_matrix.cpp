// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

// O(N^2 time)
// O(1) space (efficient, no temp)
void rotateMatrix(vector<vector<int>>& M){
	const size_t N = M.size();
	if(N==0 || M[0].size()!=N) return; // must be square non-empty

	size_t n = N-1;
    
	for(size_t i=0; i<(N+1)/2; ++i){
		for(size_t j=0; j<N/2; ++j){
			//perform 4-way rotation
			int tmp = M[i][j];

			M[i  ][j  ] = M[j  ][n-i];
			M[j  ][n-i] = M[n-i][n-j];
			M[n-i][n-j] = M[n-j][i  ];
			M[n-j][i  ] = tmp;
		}
	}
}

void printMatrix(const vector<vector<int>>& M){
	for(auto& r : M){
	    cout << "\t";
		for(auto& e : r) cout << e << " ";
		cout << endl;
	}
}


int main()
{
	vector<vector<int>> M = {
		{2, 7, 6, 7, 3},
		{8, 6, 9, 9, 5},
		{3, 1, 4, 1, 8},
		{2, 7, 9, 6, 2},
		{1, 7, 4, 5, 7}
	};

	cout << "Rotates a matrix 90 degrees counter-clockwise. " << endl << endl;

	cout << "before: " << endl;
	printMatrix(M);

	cout << endl << "after: " << endl;
	rotateMatrix(M);
	printMatrix(M);

	return 0;
}