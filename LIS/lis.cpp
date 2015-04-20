#include <iostream>
#include <cstring>

using namespace std;

int DP[100000];
int main()
{
	int T = 0, N = 0;
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> N;	
		memset(DP, 0, sizeof(int)*100000);
		int max = 0;
		for(int i = 0; i < N; i++){
			int tmp = 0;
			cin >> tmp;
			max = 0;
			for(int j = 0; j < tmp; j++){
				if(DP[j] > max) max = DP[j];
			}
			DP[tmp] = max+1;
		}
		max = 0;
		for(int i = 0; i < 100000; i++){
			if(DP[i] > max) max = DP[i];
		}

		printf("%d\n", max);
	}
}
