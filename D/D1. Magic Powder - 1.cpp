/*
D1. Magic Powder - 1
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
This problem is given in two versions that differ only by constraints. If you can solve this problem in large constraints, then you can just write a single solution to the both versions. If you find the problem too difficult in large constraints, you can write solution to the simplified version only.

Waking up in the morning, Apollinaria decided to bake cookies. To bake one cookie, she needs n ingredients, and for each ingredient she knows the value ai — how many grams of this ingredient one needs to bake a cookie. To prepare one cookie Apollinaria needs to use all n ingredients.

Apollinaria has bi gram of the i-th ingredient. Also she has k grams of a magic powder. Each gram of magic powder can be turned to exactly 1 gram of any of the n ingredients and can be used for baking cookies.

Your task is to determine the maximum number of cookies, which Apollinaria is able to bake using the ingredients that she has and the magic powder.

Input
The first line of the input contains two positive integers n and k (1 ≤ n, k ≤ 1000) — the number of ingredients and the number of grams of the magic powder.

The second line contains the sequence a1, a2, ..., an (1 ≤ ai ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, needed to bake one cookie.

The third line contains the sequence b1, b2, ..., bn (1 ≤ bi ≤ 1000), where the i-th number is equal to the number of grams of the i-th ingredient, which Apollinaria has.

Output
Print the maximum number of cookies, which Apollinaria will be able to bake using the ingredients that she has and the magic powder.

Examples
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
Note
In the first sample it is profitably for Apollinaria to make the existing 1 gram of her magic powder to ingredient with the index 2, then Apollinaria will be able to bake 4 cookies.

In the second sample Apollinaria should turn 1 gram of magic powder to ingredient with the index 1 and 1 gram of magic powder to ingredient with the index 3. Then Apollinaria will be able to bake 3 cookies. The remaining 1 gram of the magic powder can be left, because it can't be used to increase the answer.
*/

//===========================================================================================================


#include <iostream>
#include <vector>
using namespace std;



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
	long long  right = 2000;
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
