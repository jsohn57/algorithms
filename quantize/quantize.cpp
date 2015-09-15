#include <iostream>
#include <algorithm>

using namespace std;

double avg[101][101];
int A[101];

int main()
{
  int C = 0, N = 0, S = 0;
  cin >> C;
  for(int c = 0; c < C; c++){
    memset(A, 0, 101);
    for(int i = 0; i < 101; i++){
      for(int j = 0; j < 101; j++){
        avg[i][j] = 0;
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
        avg[i][j] = (avg[i][j-1]*double(j-i)+A[j])/double(j-i+1);
      }
    }

    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        printf("avg[%d][%d] = %.3f\n", i, j, avg[i][j]);
      }
    }
  }
}
