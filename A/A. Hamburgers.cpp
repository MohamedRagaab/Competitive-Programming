/*
	A. Hamburgers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarpus loves hamburgers very much. He especially adores the hamburgers he makes with his own hands. Polycarpus thinks that there are only three decent ingredients to make hamburgers from: a bread, sausage and cheese. He writes down the recipe of his favorite "Le Hamburger de Polycarpus" as a string of letters 'B' (bread), 'S' (sausage) и 'C' (cheese). The ingredients in the recipe go from bottom to top, for example, recipe "ВSCBS" represents the hamburger where the ingredients go from bottom to top as bread, sausage, cheese, bread and sausage again.

Polycarpus has nb pieces of bread, ns pieces of sausage and nc pieces of cheese in the kitchen. Besides, the shop nearby has all three ingredients, the prices are pb rubles for a piece of bread, ps for a piece of sausage and pc for a piece of cheese.

Polycarpus has r rubles and he is ready to shop on them. What maximum number of hamburgers can he cook? You can assume that Polycarpus cannot break or slice any of the pieces of bread, sausage or cheese. Besides, the shop has an unlimited number of pieces of each ingredient.

Input
The first line of the input contains a non-empty string that describes the recipe of "Le Hamburger de Polycarpus". The length of the string doesn't exceed 100, the string contains only letters 'B' (uppercase English B), 'S' (uppercase English S) and 'C' (uppercase English C).

The second line contains three integers nb, ns, nc (1 ≤ nb, ns, nc ≤ 100) — the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen. The third line contains three integers pb, ps, pc (1 ≤ pb, ps, pc ≤ 100) — the price of one piece of bread, sausage and cheese in the shop. Finally, the fourth line contains integer r (1 ≤ r ≤ 1012) — the number of rubles Polycarpus has.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the maximum number of hamburgers Polycarpus can make. If he can't make any hamburger, print 0.

Examples
inputCopy
BBBSSC
6 4 1
1 2 3
4
outputCopy
2
inputCopy
BBC
1 10 1
1 10 1
21
outputCopy
7
inputCopy
BSC
1 1 1
1 1 3
1000000000000
outputCopy
200000000001

*/

//===========================================================================================================


#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

bool ok(long long max,int burgerF[3],int inKitchenF[3],int priceF[3],long long moneyF) {
	long long need;
	long long needMoney;
	int i = 0;
	for (i = 0; i < 3;i++) {
		if (max*burgerF[i]>inKitchenF[i]) {
			need = max * burgerF[i] - inKitchenF[i];
			needMoney = need * priceF[i];
			moneyF = moneyF - needMoney;
			if (moneyF<0) {
				return false;
			}
		}
		
	}
	return true;
	
}


int main() {
	//declaration
	int i;
	int bread = 0;
	int saus = 0;
	int cheese = 0;
	string recpie;
	long long money;
	int inKitchen[3];
	int price[3];
	int burger[3];
	//inputs
	cin >> recpie;
	for (i = 0; i < 3;i++) {
		cin >> inKitchen[i];
	}
	for (i = 0; i < 3; i++) {
		cin >> price[i];
	}
	cin >> money;
	//process
	for (i = 0; i < recpie.length();i++) {
		
		if (recpie[i]=='B') {
			bread++;
		}
		else if (recpie[i] == 'S') {
			saus++;
		}
		else if (recpie[i] == 'C') {
			cheese++;
		}

	}
	burger[0] = bread;
	burger[1] = saus;
	burger[2] = cheese;
	long long left = 0;
	long long res = 0;
	long long mid;
	long long right = 3*pow(10, 12);
	while (left<=right) {
		mid = left + (right - left) / 2;

		if (ok(mid,burger,inKitchen,price,money)) {
			left = mid + 1;
			res = mid;
		}
		else {
			right = mid - 1;
		}
	}

	//output
	cout << res;


	return 0;
}
