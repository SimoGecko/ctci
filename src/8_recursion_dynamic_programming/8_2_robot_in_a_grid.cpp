#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using vvb = vector<vector<bool>>;
using v2i = vector<pair<int, int>>;

v2i RobotPath(vvb map)
{
	v2i res; // result path, empty
	if(map.size()==0 || map[0].size()==0) return res;
	int w = map.size();
	int h = map[0].size();

	vvb reach(w, vector<bool>(h)); // which cells are reachable

	for (int i = 0; i < w; ++i)
	{
		for (int j = 0; j < h; ++j)
		{
			reach[i][j] = map[i][j] && ((i>0 && reach[i-1][j]) || (j>0 && reach[i][j-1]) || (i==0 && j==0)); // cell free and up/left is reachable
		}
	}
	if(!reach[w-1][h-1]) return res; // unreachable

	int i = w-1, j = h-1;
	while(i>0 || j>0) // backtrack
	{
		res.push_back(make_pair(i,j));
		if     (i>0&&reach[i-1][j]) i--;
		else if(j>0&&reach[i][j-1]) j--;
	}
	res.push_back(make_pair(0, 0));
	reverse(res.begin(), res.end());
	return res;
}


int main()
{
	vvb map {
		{true, true, true, true, true},
		{true, false, false, false, true},
		{true, true, true, true, false},
		{true, true, false, true, true},
		{true, false, true, true, true},
	};
	/*
	╔═════╗
	║     ║
	║ ### ║
	║    #║
	║  #  ║
	║ #   ║
	╚═════╝
	*/

	v2i path = RobotPath(map);

	if(path.size()==0)
		cout << "target unreachable";
	else
	{
		cout << "The path of the robot is:"<<endl;
		for(auto p : path) cout << "(" << p.first << "," << p.second << "), ";
		cout << endl;
	}



	return 0;
}