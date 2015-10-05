#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <pair>

using namespace std;

unsigned int A[501];
unsigned int IDX[501];
int DP[501];
int C_DP[501][501];

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

void reconstruct(int idx, int length, int order, vector<int> v)
{
  vector<int, int> pv;
  for(int i = idx+1; i < N; i++){
    pv.push_back(make_pair(A[idx], idx)); 
  }
  sort(pv.begin(), pv.end());
  int k = 0;
  for(Iterator it = pv.begin(); it != pv.end(); it++){
    k = order;
    order -= count(length-1, it->second);
    if(order <= 0){
      v.push_back(it->first);
      reconstruct(i, length-1, k, v);
      v.pop_back();
    }
  }
}

int count(int l, int idx)
{
  if(l == 1)
    return 1;
  int &ret = C_DP[l][idx];
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
  C = 0; N = 0; K = 0;
  cin >> C;
  for(int c = 0; c < C; c++){
    for(int i = 0; i < 501; i++){
      A[i] = -1;
      DP[i] = -1;
      IDX[i] = -1;
      for(int j = 0; j < 501; j++){
        C_DP[i][j] = -1;
      }
    }
    cin >> N >> K;
    for(int i = 0; i < N; i++){
      cin >> A[i];
      IDX[A[i]] = i;
    }
    
    int length = lis(-1)-1;
    printf("%d\n", length);
		int ctr = -1;
		int order = 0;
    unsigned int sorted_A[501];
    memcpy(sorted_A, A, sizeof(int)*N);
    sort(sorted_A, sorted_A+N);

		while(K > 0){
      order = K;
			K = K-count(length, IDX[sorted_A[++ctr]]);	
		}
		
    //printf("order = %d, val = %d, idx = %d\n", order, sorted_A[ctr], IDX[sorted_A[ctr]]);
    vector<int> v;
    vector< vector<int> > vv;
    reconstruct(IDX[sorted_A[ctr]], length, v, vv);
    sort(vv.begin(), vv.end());
    v = vv[order-1];
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
}
