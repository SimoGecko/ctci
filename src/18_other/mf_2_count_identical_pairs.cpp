#include <algorithm>
#include <map>

// 2. CountIdenticalPairs
// Calculate the number of identical pairs.

int solution(vector<int> &A) {
	//count appearances (x)
	map<int, int> M;
	for(auto& a : A) M[a]++;
	//for each appearance, there are choose(x,2)=x(x-1)/2 pairs
	int sum=0;
	for(auto& m : M){
		int v = m.second;
		sum += v*(v-1)/2;
	}
	return sum;
}



/*
 * An array A consisting of N integers is given. We are looking for pairs of elements
 * of the array that are equal but that occupy different positions in the array.
 * 
 * More formally, a pair of indices (P, Q) is called identical if 0 ≤ P < Q < N and
 * A[P] = A[Q]. The goal is to calculate the number of identical pairs of indices.
 * 
 * For example, consider array A = [3, 5, 6, 3, 3, 5]:
 * There are four pairs of identical indices: (0, 3), (0, 4), (1, 5) and (3, 4).
 * Note that pairs (2, 2) and (5, 1) are not counted since their first indices are not
 * smaller than their second.
 * 
 * Write a function:
 * 	int solution(vector<int> &A);
 * that, given an array A of N integers, returns the number of identical pairs of
 * indices.
 * 
 * If the number of identical pairs of indices is greater than 1,000,000,000, the
 * function should return 1,000,000,000.
 * 
 * For example, given A = [3, 5, 6, 3, 3, 5], the function should return 4, as
 * explained above.
 * 
 * Write an efficient algorithm for the following assumptions:
 *  - N is an integer within the range [0..100,000];
 *  - each element of array A is an integer within the range
 *    [−1,000,000,000..1,000,000,000].
 */