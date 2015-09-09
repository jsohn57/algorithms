#include <iostream>

using namespace std;

long long DP[101][101];
long long poly(long long f, long long r) //f = number of squares in the first row, r = remaining squares that can be used
{
	if(r == 0)
		return 1;
	long long &ret = DP[f][r];
	if(ret == 0){
		for(long long i = 1; i <= r; i++){
			if(f == 0)
				ret += poly(i, r-i);
			else
				ret += (f+i-1)*poly(i, r-i);
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
		cout << "ans = " << poly(0, n) << endl;
	}
}