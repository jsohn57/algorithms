#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long bino[201][201];
long BINO_MAX;

void morse(int n, int m, long k, string &ans)
{
 if(n == 0){
  //printf("n = %d, m = %d, k = %ld, ans = %s\n", n, m, k, ans.c_str());
  for(int i = 0; i < m; i++) ans += "o";
  return;
 }
 if(m == 0){
  //printf("n = %d, m = %d, k = %ld, ans = %s\n", n, m, k, ans.c_str());
  for(int i = 0; i < n; i++) ans += "-";
  return;
 }

 // there are (m+n) choose (n-1) number of morse codes with leading '-'
 if(bino[n+m-1][n-1] >= k){
  //printf("n = %d, m = %d, k = %ld, bino[%d][%d]=%ld, ans = %s\n", n, m, k, n+m, n-1, bino[n+m-1][n-1], ans.c_str());
  morse(n-1, m, k, ans+="-");
 }
 else{
  //printf("n = %d, m = %d, k = %ld, bino[%d][%d]=%ld, ans = %s\n", n, m, k, n+m, n-1, bino[n+m][n-1], ans.c_str());
  morse(n, m-1, k-bino[n+m-1][n-1], ans+="o"); 
 }
}

int main()
{
  int C = 0, n = 0, m = 0, k = 0;
  BINO_MAX = 1000000000;
  cin >> C;

  for(int i = 0; i <= 200; i++){
    bino[i][0] = 1;
    bino[i][i] = 1;
    for(int j = 1; j < i; j++){
      bino[i][j] = min(bino[i-1][j-1]+bino[i-1][j], BINO_MAX);
    }
  }

  for(int c = 0; c < C; c++){
    cin >> n >> m >> k;
    string ans;
    morse(n, m, k, ans);
    printf("%s\n", ans.c_str());
  }
}
