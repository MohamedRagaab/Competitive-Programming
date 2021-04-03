/*
D2. Magic Powder - 2
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The term of this problem is the same as the previous one, the only exception — increased restrictions.

Input
The first line contains two positive integers n and k (1 ≤ n ≤ 100 000, 1 ≤ k ≤ 109) — the number of ingredients and the number of grams of the magic powder.

The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 109), where the i-th number is equal to the number of grams of the i-th ingredient, needed to bake one cookie.

The third line contains the sequence b1, b2, ..., bn (1 ≤ bi ≤ 109), where the i-th number is equal to the number of grams of the i-th ingredient, which Apollinaria has.

Output
Print the maximum number of cookies, which Apollinaria will be able to bake using the ingredients that she has and the magic powder.

Examples
inputCopy
1 1000000000
1
1000000000
outputCopy
2000000000
inputCopy
10 1
1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
1 1 1 1 1 1 1 1 1 1
outputCopy
0
inputCopy
3 1
2 1 4
11 3 16
outputCopy
4
inputCopy
4 3
4 3 5 6
11 12 14 20
outputCopy
3
*/

//===========================================================================================================


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


/*
1 1000000000
1
1000000000
*/
bool ok(long long max,long long magic,int ing,vector<int> needed, vector<int> havingGrams) {
	long long diff =0;
	for (int i = 0; i < ing; i ++) {

		if ((max*needed[i])>havingGrams[i]) {
			diff = max * needed[i]-havingGrams[i];
			magic = magic - diff;
			if (magic<0) {
				
				return false;
			}
			else {
				
			}
			
		}
	}
	return true;


}

int main() {
	//declaration
	int ingredients;
	int magicPowder;
	int i = 0;
	int x, y;
	vector<int> neededGrams;
	vector<int> myGrams;
	
	//inputs
	cin>>ingredients >> magicPowder;
	
	for (i = 0; i < ingredients; i++) {
		cin >> x;
		neededGrams.push_back(x);
	}

	for (i = 0; i < ingredients; i++) {
		cin >> y;
		myGrams.push_back(y);
		
	}
	long long left = 0;;
	long long  right = 2*pow(10, 9);
	long long res = 0;

	//process (Binary Search)=======================================================
	while (left <= right)
	{
		long long  mid = left + (right - left) / 2;
		if (ok(mid, magicPowder, ingredients, neededGrams, myGrams)) {
			left = mid + 1;
			res = mid;
		}
		else {

			right = mid - 1;

		}


	
	}

	//output =======================

	cout << res << endl;

	return 0;
}
