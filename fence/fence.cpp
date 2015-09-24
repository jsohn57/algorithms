#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int C, N;
long long I[20001];

int main()
{ 
  cin >> C;
  for(int c = 0; c < C; c++){
    cin >> N; 
    for(int i = 0; i < 20001; i++){
      I[i] = -1;
    }
   
    long long max = 0;
    priority_queue<long long> pq;
    int n = 0;
    for(n = 0; n <= N; n++){
      int tmp = 0;
      if(n < N)
        cin >> tmp;
      if(tmp > 0 && I[tmp] == -1){
        pq.push(tmp);
        I[tmp] = n;
      }
      while(!pq.empty() && pq.top() > tmp){
        if(tmp != 0 && (I[pq.top()] < I[tmp])){
          I[tmp] = I[pq.top()];
        }
        if(max < pq.top()*(n-I[pq.top()]))
          max = pq.top()*(n-I[pq.top()]);

        //printf("pq.size = %lu, pq.top = %lld, tmp = %d, max = %lld\n", pq.size(), pq.top(), tmp, max);
        I[pq.top()] = -1;
        pq.pop();
      }
      //printf("n = %d, tmp = %d, I[tmp] =%lld\n", n, tmp, I[tmp]);
    }

    printf("%lld\n", max);
  }
  return 0;
}
