#include <iostream>
#include <vector>

using namespace std;

int rand(int a, int b)
{
	return a + rand()%(b-a+1);
}

template <typename T>
void swap(vector<T>& a, int i, int j)
{
	T temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

template <typename T>
void shuffle(vector<T>& a)
{
	for (int i = 0; i <= a.size()-2; ++i)
	{
		int j = rand(i, a.size()-1);
		swap(a, i, j);
	}
}


int main(){
	const int N = 52;
	vector<int> deck(N);
	for (int i = 0; i < N; ++i) deck[i]=i+1;
		
	shuffle(deck);

	for (int i = 0; i < N; ++i)
		cout << deck[i]=i << ", ";
	cout << endl;
	
	return 0;
}