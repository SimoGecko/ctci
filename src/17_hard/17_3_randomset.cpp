#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <typename T>
void shuffle(vector<T>& a)
{
	for (int i = 0; i <= a.size()-2; ++i)
	{
		int j = i + rand()%(a.size()-i);
		T temp = a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}

vector<int> randomset(const vector<int>& a, int m)
{
	assert(m<=a.size());

	vector<int> n(a.size()), res(m);
	for (int i = 0; i < a.size(); ++i)
		n[i]=i;

	shuffle(n);

	for (int i = 0; i < m; ++i)
		res[i]=a[n[i]];

	return res;
}


int main(){
	cout << "Insert n, m:" << endl;
	int n, m; cin >> n >> m;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) a[i]=i;
	shuffle(a);

	vector<int> set = randomset(a, m);
	for (int i = 0; i < m; ++i)
		cout << set[i] << ", ";
	cout << endl;
		
	return 0;
}