#include <iostream>
#include <algorithm>

using namespace std;

int V[100][100] = {};
int DP[100][100] = {};
int CNTDP[100][100] = {};
int C = 0;
int n = 0;

int path(int i, int j){
	if(i == n-1)
		return V[i][j];
	int &ret = DP[i][j];
	if(ret == -1){
		ret = max(path(i+1, j), path(i+1, j+1)) + V[i][j];
	}
	return ret;
}

int cnt_path(int i, int j){
	if(i == n-1)
		return 1;
	int &ret = CNTDP[i][j];
	if(ret == -1){
		ret = 0;
		if(path(i+1, j) >= path(i+1, j+1)) ret += cnt_path(i+1, j);
		if(path(i+1, j) <= path(i+1, j+1)) ret += cnt_path(i+1, j+1);
	}
	return ret;
}

int main(){
	cin >> C;
	for(int c = 0; c < C; c++){
		cin >> n;
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				V[i][j] = 0;
				DP[i][j] = -1;
				CNTDP[i][j] = -1;
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= i; j++){
				cin >> V[i][j];
			}
		}
		
		printf("%d\n", cnt_path(0, 0)); 
	}
}
