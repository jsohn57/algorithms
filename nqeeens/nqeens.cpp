#include <iostream>
#include <vector>
#include <utility>
#include <math>

#define PLIST vector<pair<int, int>> 
#define PAIR	pair<int int> 
using namespace std;
int N;
PLIST check_nth_qpos(PAIR qpos, int depth)
{
	PLIST qlist; 
	// depth = i in (i,j)
	for(int j = 0; j < len; j++){
		if((qpos.second == j) || abs((qpos.first-depth) != abs(qpos.second-j)))
			return false;
	}
}

int main()
{
	int testcase;
	cin >> testcase;

	for(int i = 0; i < testcase){

	}
}