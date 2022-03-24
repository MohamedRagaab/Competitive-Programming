/*
A. Petya and Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
#include <tuple>
#include <stdio.h>
#include <sstream>
#include <iostream>

using namespace std;
#define	FOR(i, init, n) for(int i = init; i < n; i++)
#define	FORE(i, init, n) for(int i = init; i <= n; i++)
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main()
{
    IO;
    string st1,st2;
    cin >> st1 >> st2;

    for (int i = 0; i < st1.length();i++) {
        st1[i] = tolower(st1[i]);
        st2[i] = tolower(st2[i]);
    }

    if (st1 > st2) {
        cout << 1 << endl;
    }
    else if (st1 < st2) {

        cout << -1 << endl;
    }
    else if (st1 == st2)
    {
        cout << 0 << endl;
    }

    return 0;
}
