#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

unsigned int KMAX = 2147483647;
unsigned int A[501];
int DP[501];
int C_DP[501][501]; // length can be ommitted

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


void reconstruct(int idx, int length, int order, vector<int> &v)
{
  //printf("reconstruct: idx = %d, length = %d, order = %d\n", idx, length, order);
	// if idx == -1, all items with lis == lis(-1) is sorted
	// else all items greater than A[idx] and lis(i) == lis(idx)+1 is sorted
  vector< pair<int, int> > pv;
  int tmp;
  (idx < 0)? tmp = 0 : tmp = A[idx];
  for(int i = idx+1; i < N; i++){
    if(tmp < A[i])
      pv.push_back(make_pair(A[i], i)); 
  }
  sort(pv.begin(), pv.end());

	// it can be simplified so that element is added when the method is called.
	// in that case we don't have to add remaining items because the method is recursively called to add all the items anyway
  if(length == 1 && order > 1){
    //printf("order when length = 1 : %d\n", order);
    vector< pair<int, int> >::iterator it = pv.begin();
    while(order-- > 1) it++;
    v.push_back(it->first);
    return; 
  }
  int k = 0;
  for(vector< pair<int, int> >::iterator it = pv.begin(); it != pv.end(); it++){
    k = order;
    order -= count(length-1, it->second);
    //printf("k = %d, order = %d, idx = %d, count = %d\n", k, order, it->second, count(length-1, it->second));
    if(order <= 0){
      v.push_back(it->first);
      reconstruct(it->second, length-1, k, v);
      break;
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
      for(int j = 0; j < 501; j++){
        C_DP[i][j] = -1;
      }
    }
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> A[i];
    }
    
    int length = lis(-1)-1;
    printf("%d\n", length);
		
    vector<int> v;
    reconstruct(-1, length+1, K, v);
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
