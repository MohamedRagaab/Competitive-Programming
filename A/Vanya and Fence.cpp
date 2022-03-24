/*
A. Vanya and Fence
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vanya and his friends are walking along the fence of height h and they do not want the guard to notice them. In order to achieve this the height of each of the friends should not exceed h. If the height of some person is greater than h he can bend down and then he surely won't be noticed by the guard. The height of the i-th person is equal to ai.

Consider the width of the person walking as usual to be equal to 1, while the width of the bent person is equal to 2. Friends want to talk to each other while walking, so they would like to walk in a single row. What is the minimum width of the road, such that friends can walk in a row and remain unattended by the guard?

Input
The first line of the input contains two integers n and h (1 ≤ n ≤ 1000, 1 ≤ h ≤ 1000) — the number of friends and the height of the fence, respectively.

The second line contains n integers ai (1 ≤ ai ≤ 2h), the i-th of them is equal to the height of the i-th person.

Output
Print a single integer — the minimum possible valid width of the road.
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
    int n, fence_h,a;
    int min_width = 0;
    cin >> n >> fence_h;
    for (int i = 0; i < n;i++) {
        cin >> a;
        if (a > fence_h) {
            min_width += 2;
        }
        else {
            min_width++;
        }
    }
    cout << min_width << endl;
    return 0;
}
