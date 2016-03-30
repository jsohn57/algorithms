#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

unsigned int KMAX = 2147483647; //INT_MAX
unsigned int A[501];
int DP[501];
int C_DP[501];
//int C_DP[501][501];

int C, N;
long K;

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

/*
unsigned int count(int l, int idx)
{
  if(l == 1)
    return 1;
  int &ret = C_DP[l][idx];
  if(ret == -1){
    ret = 0;
    for(int i = idx+1; i < N; i++){
      if(A[i] > A[idx] && (l-1) == lis(i)){
        ret = min(KMAX, ret+count(l-1, i));
        //ret += count(l-1, i); 
      }
    }
  }
  return ret;
}
*/

unsigned int count(int idx)
{
  if(lis(idx) == 1)
    return 1;
  int &ret = C_DP[idx];
  if(ret == -1){
    ret = 0;
    for(int i = idx+1; i < N; i++){
      if(A[i] > A[idx] && lis(idx)-1 == lis(i)){
        ret = min<long long>(KMAX, (long long)ret+count(i));
        //ret += count(l-1, i); 
      }
    }
  }
  return ret;
}


void reconstruct(int idx, int order, vector<int> &v)
{
  //printf("reconstruct: idx = %d, order = %d\n", idx, order);
	
	if(idx != -1)
		v.push_back(A[idx]);

  vector< pair<int, int> > pv;
  for(int i = idx+1; i < N; i++){
    if((idx == -1 || A[idx] < A[i]) && (lis(idx) == lis(i)+1))
      pv.push_back(make_pair(A[i], i)); 
  }
  sort(pv.begin(), pv.end());

  //int k = 0;
  for(vector< pair<int, int> >::iterator it = pv.begin(); it != pv.end(); it++){
    //printf("k = %d, order = %d, idx = %d, count = %d\n", k, order, it->second, count(it->second));
    if(order < count(it->second)){
      //v.push_back(it->first);
      reconstruct(it->second, order, v);
      break;
    }
    else{
      order -= count(it->second);
    }
  }
}

int main()
{
  C = 0; N = 0; K = 0;
  cin >> C;
  for(int c = 0; c < C; c++){
    for(int i = 0; i < 501; i++){
      A[i] = -1;
      DP[i] = -1;
      C_DP[i] = -1;
      /*
      for(int j = 0; j < 501; j++){
        C_DP[i][j] = -1;
      }
      */
    }
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }
    
    int length = lis(-1)-1;
    printf("%d\n", length);
		
    vector<int> v;
    reconstruct(-1, K-1, v);
    for(int i = 0; i < v.size(); i++){
      printf("%d ", v[i]);
    }
    printf("\n");
    /*
    for(int i = 0; i < vv.size(); i++){
      for(int j = 0; j < vv[i].size(); j++){
        printf("%d ", vv[i][j]);
      }
      printf("\n\n");
    }
    */
  }
  return 0;
}
