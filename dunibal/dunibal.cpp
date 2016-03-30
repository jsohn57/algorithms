#include <iostream>

using namespace std;

int T, N, D, P, t;
int A[51][51] = {};
int q[51] = {};
double DP[100][51] = {};
int deg[51] = {};

double path(int d, int n)
{
	if(d == 0 && n != P)
		return 0.0;
	if(d == 0 && n == P)
		return 1.0;

	double &ret = DP[d][n];
	if(d > 0){
		if(ret == -1){
			ret = 0;
			for(int i = 0; i < N; i++){
				if(i != n && A[n][i] > 0){
					ret += path(d-1, i)/deg[i];
				}
			}
		}
	}
	
	return ret;
}

int main()
{
	cin >> T;
	for(int c = 0; c < T; c++){
		cin >> N >> D >> P;

		// reset A
		for(int m = 0; m < 51; m++)
			for(int n = 0; n < 51; n++)
				A[m][n] = 0;

		// reset q and deg
		for(int m = 0; m < 51; m++){
			q[m] = 0;
			deg[m] = 0;
		}

		// reset DP
		for(int m = 0; m < 100; m++)
			for(int n = 0; n < 51; n++)
				DP[m][n] = -1.0;

		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> A[i][j];
				if(A[i][j] > 0){
					deg[i]++;
				}
			}
		}
		cin >> t;
		for(int i = 0; i < t; i++){
			cin >> q[i];
			printf("%.8f ", path(D, q[i]));
		}
		printf("\n");
	}
}