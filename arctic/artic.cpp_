#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define PAIR pair<double, double>
#define MP(x,y) make_pair(x,y)

int N = 0;
PAIR NL[101];
double result[100];
double DP[100][100];

void print(vector<int> VL)
{
	printf("VL = ");
	for(vector<int>::iterator itr = VL.begin(); itr != VL.end(); itr++) printf("%d ", *itr);
	//printf("\n");
}
double path(int src, int dst, vector<int> VL)
{
  if(dst == 0){
		return 0;
  }
  // i = next src indicies
  double min = 1500.0;
	char MARK[102];
	memset(MARK, '0', 101);
  for(vector<int>::iterator itr = VL.begin(); itr != VL.end(); itr++){
		MARK[*itr] = '1';
  }
	
  for(int i = 0; i < N; i++){
    if(i != dst && MARK[i] != '1'){
			VL.push_back(i); 
			double tmp = 0.0;
			if(DP[dst][i] == 0.0 &&  DP[i][dst] == 0.0)
    		tmp = sqrt(pow(NL[dst].first-NL[i].first, 2.0) + pow(NL[dst].second-NL[i].second, 2.0));
			else{
				if(DP[dst][i] == 0.0)
					tmp = DP[i][dst];
				else
					tmp = DP[dst][i];
			}
			DP[dst][i] = tmp; DP[i][dst] = tmp;
			double prev = path(0, i, VL);
			tmp = max(tmp, prev);
			if(tmp < min) min = tmp;
			VL.pop_back(); 
			if(dst == N) result[i] = prev;
    }
  }
  return min;
}
int main()
{
  int C = 0;
  cin >> C;
  for(int t = 0; t < C; t++){
    N = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
      double x = 0, y = 0;
      cin >> x >> y;
      NL[i] = MP(x,y);
    }
		for(int i = 0; i < 100; i++){
			for(int j = 0; j < 100; j++){
				DP[i][j] = 0.0;
			}
		}
		NL[N] = MP(1001.0, 1001.0);
    vector<int> VL; VL.push_back(N);
		double tmp = path(0, N, VL);
    double max = 0;
    for(int i = 1; i < N; i++){
			tmp = result[i];
      if(max < tmp) max = tmp; 
    }
    printf("%0.2f\n", (round(max*100.0)/100.0)); 
  }
}
