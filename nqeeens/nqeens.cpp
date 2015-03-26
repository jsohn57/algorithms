#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

#define PLIST vector< pair<int, int> > 
#define PAIR	pair<int, int> 

using namespace std;
int N = 1;

bool is_qpos(PLIST queens, PAIR qpos)
{
	// depth = i in (i,j)
  for(PLIST::iterator it = queens.begin(); it != queens.end(); it++){
    //printf("inspecting : (%d, %d) vs (%d, %d)\n", qpos.first, qpos.second, it->first, it->second);
		if((qpos.first == it->first) || (abs(qpos.first-it->first) == abs(qpos.second-it->second)))
			return false;
  }
  return true;
}

int get_possible_qpos(PLIST queens, int depth)
{
  // basecase
  if(depth > N)
    return 0;
  else if((depth == N) && (queens.size() == N))
    return 1;
  else{
    int sum = 0;
    for(int i = 0; i < N; i++){
      PAIR tmp(i, depth);
      if(is_qpos(queens, tmp)){
        queens.push_back(tmp);
        sum += get_possible_qpos(queens, depth+1);
        queens.pop_back();
      }
    }
    return sum;
  }
}

int main()
{
	int testcase;
	cin >> testcase;

	for(int i = 0; i < testcase; i++){
    cin >> N;
    PLIST queens;
    int sum = 0;
    for(int j = 0; j < N; j++){
      queens.push_back(PAIR(j,0));
      int partial_sum = get_possible_qpos(queens, 1);
      sum += partial_sum;
      queens.pop_back();
    }
    printf("%d\n", sum);
  }
}
