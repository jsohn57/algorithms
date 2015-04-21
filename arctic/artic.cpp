#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

#define PAIR pair<double, double>
#define MP(x,y) make_pair(x,y)

PAIR NL[100];
double DP[100][100];

double path(int src, int dst, vector<int> VL)
{
  if(dst == 0){
    DP[src][dst] = 0;
    return DP[src][dst];
  }
  // i = next src indicies
  int min = 1500;
  for(int i = 0; i < 100; i++){
    if(i != dst){
      bool contains = false;
      for(vector<int>::iterator itr = VL.begin(); itr != VL.end(); itr++){
        if(*itr == i){contains = true; break;}
      }
      if(!contains){
        VL.push_back(i); 
        double tmp = 0;
        if(DP[i][dst] == -1.0)
          tmp = max(sqrt(pow(NL[i].first-NL[dst].first, 2.0) + pow(NL[i].second-NL[dst].second, 2.0)), path(0, i, VL));
        else
          tmp = max(sqrt(pow(NL[i].first-NL[dst].first, 2.0) + pow(NL[i].second-NL[dst].second, 2.0)), DP[i][dst]);
        if(tmp < min) min = tmp;
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
    int N = 0;
    cin >> N;

    for(int i = 0; i < 100; i++){
      for(int j = 0; j < 100; j++){
        DP[i][j] = -1.0;
      }
    }
    for(int i = 0; i < N; i++){
      int x = 0, y = 0;
      cin >> x >> y;
      NL[i] = MP(x,y);
    }

    double max = 0;
    for(int i = 1; i < N; i++){
      vector<int> VL; VL.push_back(i);
      double tmp = path(0, i, VL);
      if(max < tmp) max = tmp; 
    }
    printf("%f\n", max); 
  }
}
