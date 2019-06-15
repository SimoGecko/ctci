// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>

using namespace std;

//O(N) additional space
void set0RowCol(vector<vector<int>>& X){
	if(X.empty() || X[0].empty()) return;

	size_t R = X.size();
	size_t C = X[0].size();

	vector<bool> is0Row(R, false);
	vector<bool> is0Col(C, false);

	//mark which must be set
	for(size_t r=0; r<R; ++r){
		for(size_t c=0; c<C; ++c){
			if(X[r][c]==0){
				is0Row[r]=true;
				is0Col[c]=true;
			}			
		}
	}
	//actually set them
	for(size_t r=0; r<R; ++r){
		for(size_t c=0; c<C; ++c){
			if( is0Row[r] || is0Col[c]){
				X[r][c]=0;
			}			
		}
	}
}



//O(1) additional space
void set0RowColEfficient(vector<vector<int>>& X){
	if(X.empty() || X[0].empty()) return;

	size_t R = X.size();
	size_t C = X[0].size();

	bool rowHas0 = false;
	bool colHas0 = false;
	for(size_t r=0; r<R; ++r) if (X[r][0]==0) {rowHas0 = true; break; }
	for(size_t c=0; c<C; ++c) if (X[0][c]==0) {colHas0 = true; break; }
	
	//cout << "col=" << colHas0 << ", row=" << rowHas0 << endl;

	//mark which must be set
	for(size_t r=1; r<R; ++r){
		for(size_t c=1; c<C; ++c){
			if(X[r][c]==0){
				X[r][0]=0;
				X[0][c]=0;
			}			
		}
	}
	//actually set them
	for(size_t r=1; r<R; ++r){
		for(size_t c=1; c<C; ++c){
			if( X[r][0]==0 || X[0][c]==0){
				X[r][c]=0;
			}			
		}
	}

	if(rowHas0) for(size_t r=0; r<R; ++r) X[r][0] = 0;
	if(colHas0) for(size_t c=0; c<C; ++c) X[0][c] = 0;
}




int main()
{

	vector<vector<int>> X = {
		{1, 0, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 0, 1},
		{1, 1, 1, 1, 1},
		{1, 0, 1, 0, 0},
	};

	set0RowColEfficient(X);


	for(auto& r : X){
		for(auto& e : r){
			cout << e << " ";
		}
		cout << endl;
	}
		
	return 0;
}