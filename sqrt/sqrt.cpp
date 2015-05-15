#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long N;
int main()
{
  cin >> N;
  unsigned long long i = 2;
  unsigned long long max = i;
  unsigned long long prev = 0;
  if(N > 1){
    for(i = 2; i < 10000; i++){
      unsigned long long tmp = i;
      while(true){
        if((tmp*tmp/tmp == tmp) && (tmp*tmp < N)){
          prev = tmp;
          tmp *= tmp;
        }
        else{
          break;
        }
      }
      if(max < prev) max = prev;
    }
    for(i = max; i < N; i++){
      if(i*i > N) break;   
    }
  }
  printf("%llu\n", i-1);
  return 1;
}
