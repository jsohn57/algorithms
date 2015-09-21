#include <iostream>

int C, N;
int F[20001];
int main()
{ 
  cin >> C;
  for(int c = 0; c < C; c++){
    cin >> N; 
    for(int i = 0; i < 20001; i++){
      F[i] = 0;
    }
   
    for(int n = 0; n < N; n++){
      cin >> F[n]; 
    }
    //sort
    sort(F, F+N); 

    
  }
}
