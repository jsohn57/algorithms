#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int avg[101][101];
int A[101];
long long DP[101][101];
int C, N, S;

long long quantize(int i, int s) // i = starting array index, s = number of usable numbers remaining
{
  if(s == 1){
    long long part_sum = 0;
    for(int j = i; j < N; j++){
      part_sum += (avg[i][N-1]-A[j])*(avg[i][N-1]-A[j]);
      printf("i = %d, j = %d, part_sum = %lld\n", i, j, part_sum);
    }
    return part_sum;
  }
 
  long long &ret = DP[i][s];
  if(ret == -1){
    long long min_val = 1000000;
    for(int j = i; j <= (N-s); j++){
      long long part_sum = 0;
      for(int k = i; k <= j; k++){
        part_sum += (avg[i][j]-A[k])*(avg[i][j]-A[k]);
      }
      if(i == 3)
        printf("part_sum = %lld, quantize_sum = %lld, j+1 = %d, s-1 = %d\n", part_sum, quantize(j+1, s-1), j+1, s-1);
      min_val = min(min_val, part_sum + quantize(j+1, s-1));
    }
    ret = min_val;
  }
  return ret;
}

int main()
{
  C = 0;
  cin >> C;
  for(int c = 0; c < C; c++){
    N = 0; S = 0;
    for(int i = 0; i < 101; i++){
      A[i] = 0;
      for(int j = 0; j < 101; j++){
        avg[i][j] = 0;
        DP[i][j] = -1;
      }
    }
    cin >> N >> S;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }

    // sort the array
    sort(A, A+N);
    for(int i = 0; i < N; i++){
      avg[i][i] = A[i];
      printf("%d ", A[i]);
    }
    printf("\n");
    
    // pre-calculate the averages
    for(int i = 0; i < N; i++){
      for(int j = i+1; j < N; j++){
        avg[i][j] = (int)round((double)(avg[i][j-1]*(j-i)+A[j])/(double)(j-i+1));
        //avg[i][j] = (avg[i][j-1]*(j-i)+A[j])/(j-i+1);
      }
    }

    printf("%lld\n", quantize(0, (S>N)?N:S));
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        printf("Avg[%d][%d] = %d\n", i, j, avg[i][j]);
      }
    }
  }
}
