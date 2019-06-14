// (c) Simone Guggiari 2019 - DAILY CODING

/* (Uber)
 * Given an array of integers, return a new array such that each element at index i of the new array
 * is the product of all the numbers in the original array except the one at i.
 *
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24].
 * If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 *
 * Follow-up: what if you can't use division?
 */

#include <iostream>
#include <vector>

using namespace std;

int divide(int a, int b) // return a/b
{
	if(a>b){int temp = a; a=b; b=temp;}
	if(a==0 || b==0) return 0;
	if(b==1) return a;
}

vector<int> productArray(const vector<int>& a)
{
	long int prod = 1;
	for(auto e : a) prod *= e;
	vector<int> result(a.size());
	for(int i=0; i<a.size(); ++i) result[i] = prod/a[i];
	return move(result);
}

void printArray(const vector<int>& a)
{
	cout << "[";
	for(auto e : a) cout << e << ", ";
	cout << "]" << endl;
}



int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	cout << "Input:  "; printArray(a);
	cout << "Output: "; printArray(productArray(a));
	
	return 0;
}