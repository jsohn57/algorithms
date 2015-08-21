#include <iostream>

using namespace std;

int main()
{
	int T = 0;
	cin >> T;
	for(int t = 0; t < T; t++){
		int N = 0, max = 0, sum = 0, p_sum = 0, n_sum = 0, P = 0, C = 0, bn = -1;
		cin >> N;
		for(int i = 0; i < N; i++){
			cin >> C;
			if(P < 0 && C >= 0){
				if(sum < 0) sum = 0;
			}
			sum += C;
			if(C < 0){
				if(sum < 0) sum = 0;
			}
			if(sum > max) max = sum;
			P = C;
		}
		printf("%d\n", max);
	}
}