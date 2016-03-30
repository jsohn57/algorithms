#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

//#include <chrono>

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
    char possible_qpos[12] = {0};
    for(PLIST::iterator it = queens.begin(); it != queens.end(); it++){
      possible_qpos[it->first] = 1; 
      int diff = abs(depth-it->second);
      if((it->first - diff) > -1) possible_qpos[it->first-diff] = 1;
      if((it->first + diff) < N) possible_qpos[it->first+diff] = 1;
    }

    int sum = 0;
    for(int i = 0; i < N; i++){
      PAIR tmp(i, depth);
      if(possible_qpos[i] != 1){
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

    //high_resolution_clock::time_point t1 = high_resolution_clock::now();

    PLIST queens;
    int sum = 0;
    for(int j = 0; j < N; j++){
      queens.push_back(PAIR(j,0));
      int partial_sum = get_possible_qpos(queens, 1);
      sum += partial_sum;
      queens.pop_back();
    }

    //high_resolution_clock::time_point t2 = high_resolution_clock::now();
    //cout << "execution time = " << duration_cast<milliseconds>(t2-t1).count() << endl;

    printf("%d\n", sum);
  }
}
