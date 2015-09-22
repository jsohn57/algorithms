#include <iostream>
#include <algorithm>

using namespace std;

int C, N;
int S[20001];
int I[20001];

int main()
{ 
  cin >> C;
  for(int c = 0; c < C; c++){
    cin >> N; 
    for(int i = 0; i < 20001; i++){
      S[i] = -1;
      I[i] = -1;
    }
   
    int s_ptr = -1;
    int max = 0;
    int n = 0;
    for(n = 0; n < N; n++){
      int tmp = 0;
      int ctr = 1;
      cin >> tmp;
      if(s_ptr > 0){
        while(S[--s_ptr] > tmp){ // stack pop if needed
          //printf("max = %d, S[--s_ptr] = %d, tmp = %d, cur_ptr = %d, I[S[s_ptr]] = %d\n", max, S[s_ptr], tmp, n, I[S[s_ptr]]);
          if(I[S[s_ptr]] > -1){
            if(max < S[s_ptr]*(n - I[S[s_ptr]]))
              max = S[s_ptr]*(n - I[S[s_ptr]]);
            I[S[s_ptr]] = -1;
          }
        }
      }
      S[(++s_ptr)++] = tmp; // stack push
      if(I[S[s_ptr-1]] == -1)
        I[S[s_ptr-1]] = n;
    }
    if(s_ptr > 0){
      while(--s_ptr >= 0){ // stack pop if needed
        //printf("max = %d, S[--s_ptr] = %d, cur_ptr = %d, I[S[s_ptr]] = %d\n", max, S[s_ptr], n, I[S[s_ptr]]);
        if(max < S[s_ptr]*(n - I[S[s_ptr]]))
          max = S[s_ptr]*(n - I[S[s_ptr]]);
      }
    }
    printf("%d\n", max);
  }
  return 0;
}
