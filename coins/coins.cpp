#include <iostream>

using namespace std;

unsigned long long int DP[101][5001]; //[depth(coin types)][possible goal value]
int CT[101]; //coin types

void init()
{
	for(int i = 0; i < 101; i++){
		CT[i] = -1;
		for(int j = 0; j < 5001; j++){
			DP[i][j] = -1;
		}
	}
}
unsigned long long int calc_change(int goal, int num_var)
{
	unsigned long long int sum = 0;
	int mult_counter = 0;
	int idx = num_var-1;

	if(CT[idx] > goal){
		DP[idx][goal] = calc_change(goal, idx);
		return DP[idx][goal];
	}
	int val = 0;
	while(goal >= val){
		//base case
		if(idx == 0){
			if((goal % CT[idx]) == 0)
					sum = 1;
			else
					sum = 0;
			break;
		}
		if(val == 0){
			if(DP[idx-1][goal] == -1){
				DP[idx-1][goal] = calc_change(goal, idx);
			}
			sum += DP[idx-1][goal];
		}
		else if(val == goal){
			//DP[idx-1][0] = 1;
			sum += 1;
		}
		else{
			if(DP[idx-1][goal-val] == -1){
				DP[idx-1][goal-val] = calc_change(goal-val, idx);
			}
			sum += DP[idx-1][goal-val];
		}
		mult_counter++;
		val = CT[idx]*mult_counter;
	}
	DP[idx][goal] = sum;
	return sum;
}

int main()
{
	// should consider when the input or result is greater than size of int type(unsigned long maybe)
	int T = 0, M = 0, C = 0; // T = testcase, M = money, C = # of coin types > 1, <= 100
	cin >> T;
	for(int i = 0; i < T; i++){
		// initialize DP array
		init();

		// get M, C
		cin >> M >> C;  

		// get Coin Types
		for(int j = 0; j < C; j++){
			cin >> CT[j];
		}

		unsigned long long int result = calc_change(M, C);
		(result > 1000000007)?result=result%1000000007:result;
		printf("%llu\n", result);
	}
}