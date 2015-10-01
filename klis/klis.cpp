#include <iostream>
#include <algorithm>

using namespace std;

unsigned int A[501];
int DP[501];
int C_DP[501];

int C, N, K;

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

int count(int l, int idx)
{
  if(l == 1)
    return 1;
  int &ret = C_DP[idx];
  if(ret == -1){
    ret = 0;
    for(int i = idx+1; i < N; i++){
      if(A[i] > A[idx] && (l-1) == lis(i))
        ret += count(l-1, i); 
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
      C_DP[i] = -1;
    }
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }
    
    int length = lis(-1)-1;
    printf("%d\n", length);
    for(int i = 0; i < N; i++){
      printf("idx = %d, count = %d\n", i, count(length, i));
    }
  }
}
