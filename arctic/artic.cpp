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
int DP[101][101];

void print(vector<int> VL)
{
	printf("VL = ");
	for(vector<int>::iterator itr = VL.begin(); itr != VL.end(); itr++) printf("%d ", *itr);
	printf("\n");
}
double path(int src, int dst, vector<int> VL)
{
  if(dst == 0){
		DP[src][dst] = 0;
		return 0;
  }
  // i = next src indicies
  double min = 1500.0;
	char MARK[100];
	memset(MARK, '0', 100);
  for(vector<int>::iterator itr = VL.begin(); itr != VL.end(); itr++){
		MARK[*itr] = '1';
  }
	
  for(int i = 0; i < N; i++){
    if(i != dst && MARK[i] != '1'){
    	double tmp = sqrt(pow(NL[dst].first-NL[i].first, 2.0) + pow(NL[dst].second-NL[i].second, 2.0));
			if(tmp < min){
				VL.push_back(i); 
				tmp = max(tmp, path(0, i, VL));
				if(tmp < min) min = tmp;
				VL.pop_back(); 
			}
    }
  }
	DP[src][dst] = min;
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
		NL[N] = MP(1001.0, 1001.0);
    vector<int> VL; VL.push_back(N);
		double tmp = path(0, N, VL);

    double max = 0;
    for(int i = 1; i < N; i++){
      //vector<int> VL; VL.push_back(i);
			tmp = DP[0][i];
      //double tmp = path(0, i, VL);
      if(max < tmp) max = tmp; 
    }
    printf("%0.2f\n", (round(max*100.0)/100.0)); 
  }
}
