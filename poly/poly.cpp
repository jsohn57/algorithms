#include <iostream>

using namespace std;

unsigned int DP[101][101];
unsigned int poly(unsigned int f, unsigned int r) //f = number of squares in the first row, r = remaining squares that can be used
{
	if(r == 0)
		return 1;
	unsigned int &ret = DP[f][r];
	if(ret == 0){
		for(unsigned int i = 1; i <= r; i++){
			if(f == 0)
				ret = (ret + poly(i, r-i))%10000000;
			else
				ret = (ret + (f+i-1)*poly(i, r-i))%10000000;
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
		cout << poly(0, n) << endl;
	}
}
