#include <iostream>
#include <vector>

using namespace std;

vector<int> x;
int n;

vector<int> sequence(int n) // returns sequence [0..n]
{
	vector<int> res(n+1);
	for (int i = 0; i <= n; ++i)
		res[i]=i;
	return res;
}

template <typename T>
void shuffle(vector<T>& a)
{
	for (size_t i = 0; i <= a.size()-2; ++i)
	{
		int j = i + rand()%(a.size()-i);
		T temp = a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}


vector<int> generateSequenceWithMissingN(int n)
{
	vector<int> seq = sequence(n); // 0..n
	shuffle(seq);
	cout << "(erasing " << *seq.begin() << ")" << endl;
	seq.erase(seq.begin());
	return seq;
}


int q(int i, int j)
{
	return !!(x[i]&(1<<j));
}

typedef bool (*predicatefct)(vector<int>::iterator);
void removeAllMatchingPredicate(vector<int>& a, predicatefct)
{
	for (auto it = a.begin(); it != a.end();) {
	    if (predicatefct(it)) {
	        it = a.erase(it);
	    } else {
	        ++it;
	    }
	}
}


int findMissingNumber()
{
	vector<int> cand = sequence(n);
	vector<int> lines = sequence(n-1);
	int b = 0;

	while(cand.size()>1)
	{
		int c = 0, exp = 0;
		for(auto l:lines) c += q(l, b);
		for(auto c:cand) exp += (!!(c&(1<<(b-1))));
		int bitmis = exp - c;
		//[](vector<int>::iterator it){return q(*it,b)!=bitmis;}
		//[](vector<int>::iterator it){return (!!((*it)&(1<<(b-1))))!=bitmis;}
		//for(auto l:lines) if(q(l,b)!=bitmis) lines.erase(l);
		//for(auto c:cand)  if((!!(c&(1<<(b-1))))!=bitmis) cand.erase(c);
		b++;
	}
	return cand[0];
}



int main(){

	cout << "Insert n:" << endl;
	cin >> n;
	x = generateSequenceWithMissingN(n);

	//cout << "found missing " << findMissingNumber() << endl;


	return 0;
}