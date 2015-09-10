#include <iostream>

using namespace std;
unsigned int mod = 20090711

unsigned int DP[101][101];
unsigned int poly(unsigned int f, unsigned int r) //f = number of squares in the first row, r = remaining squares that can be used
{
	if(r == 0)
		return 1;
	unsigned int &ret = DP[f][r];
	if(ret == 0){
		for(unsigned int i = 1; i <= r; i++){
			if(f == 0)
				ret = (ret + poly(i, r-i))%mod;
			else
				ret = (ret + (f+i-1)*poly(i, r-i))%mod;
		}
	}
	return ret;
}

int main()
{
	int C = 0, n = 0;
	cin >> C;
	for(int i = 0; i < C; i++){
		for(int m = 0; m <= 100; m++){
			for(int n = 0; n <= 100; n++){
				DP[m][n] = 0;
			}
		}
		cin >> n;

		// total number of polyminos
		unsigned int tot = poly(0, n);

		// 2 cases that makes the polymino symmetric
		// case 1: if n is even, poly(0, n/2) polyminos are symmetric
		unsigned int symm = 0;
		if(n%2 == 0)
			symm = poly(0, n/2);

		// case 2: if we remove the last line of each polyminos and flip, then it is symmetric
		for(int j = 1; j < n; j++){
			symm += poly(j, n-j);
		}

	}
}
