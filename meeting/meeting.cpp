#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> NML;
vector<int> NWL;
//int NML[10000];
//int NWL[10000]; 

int main()
{
  int T = 0;
  cin >> T;
  for(int t = 0; t < T; t++){
    int N = 0, tmp = 0, sum = 0;; 
    cin >> N;
    NML.clear(); NWL.clear();
    
    for(int i = 0; i < N; i++){cin >> tmp; NML.push_back(tmp);}
    for(int i = 0; i < N; i++){cin >> tmp; NWL.push_back(tmp);}
     
    sort(NML.begin(), NML.end());
    sort(NWL.begin(), NWL.end());

    for(int i = 0; i < N; i++){sum += abs(NML[i]-NWL[i]);}
    printf("%d\n", sum);
  }
}
