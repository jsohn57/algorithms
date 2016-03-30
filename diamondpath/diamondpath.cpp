#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int DP[200][100];
int N = 0;
int main()
{
	int T = 0, LC = 0, depth = 0;
	cin >> T;
	for(int t = 0; t < T; t++){
		LC = 0; depth = 0; N = 0;
		memset(DP, 0, sizeof(int)*20000);
		cin >> N;

		// array initialization
		while(LC <= N){
			for(int k = 0; k < LC; k++){
				cin >> DP[depth][k];
			}
			LC++;
			depth++;
		}
		LC -= 2;
		while(LC > 0){
			for(int k = 0; k < LC; k++){
				cin >> DP[depth][k];
			}
			LC--;
			depth++;
		}

		// calculate the distance from the starting point : DP[1][0];
		for(int i = 2; i <= N; i++){
			for(int j = 0; j < i; j++){
				if(j == 0) DP[i][j] += DP[i-1][j];
				else if(j == i-1) DP[i][j] += DP[i-1][j-1];
				else DP[i][j] += max(DP[i-1][j-1], DP[i-1][j]);
			}
		}
		for(int i = N+1; i < 2*N; i++){
			for(int j = 0; j < 2*N-i; j++){
				DP[i][j] += max(DP[i-1][j], DP[i-1][j+1]);
			}
		}
		printf("%d\n", DP[2*N-1][0]);
	}
}