// (c) Simone Guggiari 2019 - CTCI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char wc = '.';
const char bc = '#';

char ** c;
int w, h;

/*
 * draws pretty histograms such as 
 *
 *                    #     
 *                    #     
 *      #...........#.#     
 *     ##...........#.#     
 *  #..##.#........##.#     
 *  #..####........##.#..#  
 *  #..####........##.#..#  
 *  #..####......#.##.#..#  
 *  #..####....#.#.##.#..## 
 * -------------------------
 * 0500674500001020570900410
 */




void makeHistogram(const vector<int>& H, const vector<int>& d){
	//delete previous char array (no leak)
	for(int i=0; i<h; ++i) delete [] c[i];
	delete [] c;

	//compute new
	int w = H.size();
	h = *max_element(begin(H), end(H))+1;
	c = new char*[h];
	for(int i=0; i<h; ++i) c[i] = new char[w+1];

	for(int x=0; x<w; x++){
		for(int y=0; y<h-1; y++){
			c[y+1][x] = y<H[x]?bc : (y<(H[x]+d[x])?wc : ' ');
		}
		//c[0][x] = '0' + (char)H[x];
		c[0][x] = '_';
	}
	for(int i=0; i<h; ++i) c[i][w] = '\0';
}

void drawHistogram(const vector<int>& H, const vector<int>& d){
	makeHistogram(H, d);

	for(int i=0; i<h; i++){
		cout << c[h-1-i] << endl;
	}
}

int volumeOfHistogram(const vector<int>& H){
	//corner cases
	if(H.empty() || H.size()<3) return 0;


	const size_t N = H.size();
	vector<int> l(N), r(N), d(N); // left, right, diff

	//left->right pass
	l.front() = H.front();
	for(size_t i = 1; i<N; ++i){
		l[i] = max(H[i], l[i-1]);
	}

	//left<-right pass
	r.back() = H.back();
	for(int i = N-2; i>=0; --i){
		r[i] = max(H[i], r[i+1]);
	}

	for(size_t i=0; i<N; ++i){
		d[i] = min(l[i], r[i]) - H[i];
	}

	//draw
	drawHistogram(H, d);

	return accumulate(begin(d), end(d), 0);
}


int main()
{
	//vector<int> H = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	w = h = 0;
	cout << "Computes the volume in liters of water of a histogram: " << endl << endl;
	
	while(true){
		cout << "Insert histogram (-1 to stop): " << endl;
		vector<int> H;
		while(true){
			int x; cin >> x;
			if(x==-1) break;
			H.push_back(x);
		}
		cout << "volume = " << volumeOfHistogram(H) << endl << endl;
	}
	return 0;
}