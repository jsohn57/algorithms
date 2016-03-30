#include <iostream>
#include <algorithm>

using namespace std;

unsigned int A[501];
int DP[501];

int C, N;
int lis(int idx)
{
  int &ret = DP[idx+1];
  if(ret == -1){
    ret = 1;
    for(int i = idx+1; i < N; i++){
      if(idx == -1 || A[i] > A[idx]){
        ret = max(ret, lis(i)+1);
      }
    }
  }
  return ret;
}

int main()
{
  C = 0; N = 0;
  cin >> C;
  for(int c = 0; c < C; c++){
    for(int i = 0; i < 501; i++){
      A[i] = -1;
      DP[i] = -1;
    }
    cin >> N;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }
    
    printf("%d\n", lis(-1)-1);
  }
}
