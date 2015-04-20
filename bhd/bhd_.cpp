#include <iostream>

using namespace std;

unsigned int C[80000];
unsigned int DP[80000];

int main()
{
  int N = 0, CTR = 0, D = 1, S = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> C[i];
    if(i > 0){
      if(C[i] < C[i-1]) DP[CTR++] = i-1;
    }
  }
  while(CTR > 0){
    int p_CTR = 0;
    D++;
    for(int i = 0; i < CTR; i++){
      bool T = true;
      int CUR = DP[i]+1;
      while(CUR-DP[i] <= D){
        if((CUR >= N) || C[DP[i]] < C[CUR]){
          T = false;
          break;
        }
        CUR++;
      }
      if(T)DP[p_CTR++] = DP[i];
      else S += D-1;
    }
    CTR = p_CTR;
    printf("Depth = %d\n", D);
    for(int i = 0; i < CTR; i++){
      printf("%d ", DP[i]);
      printf("\n");
    }
  }

  printf("\n%d\n", S);
}
