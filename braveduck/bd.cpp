#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

#define MP make_pair 
#define PAIR pair<int, int>
#define LIST vector< pair<int, int> >
#define ITER vector< pair<int, int> >::iterator

LIST queue;
LIST unvisited;
LIST stones;
int main()
{
	int T = 0;
	cin >> T;
	for(int t = 0; t < T; t++){
		int J = 0, SX = 0, SY = 0, EX = 0, EY = 0, N = 0;
		queue.clear(); unvisited.clear(); stones.clear();
		cin >> J >> SX >> SY >> EX >> EY >> N;
		for(int i = 0; i < N; i++){
			int X = 0, Y = 0;
			cin >> X >> Y;
			PAIR p = MP(X,Y);
			stones.push_back(p);
			unvisited.push_back(p);
		}

		PAIR SP = MP(SX, SY); PAIR EP = MP(EX, EY);
		queue.push_back(SP);
		stones.push_back(EP);
		unvisited.push_back(SP);
		unvisited.push_back(EP);
		bool ans = false;
		while(!queue.empty()){
			PAIR p = queue.back();
			queue.pop_back();

			// if p is the end point, finish it
			if(p.first == EX && p.second == EY){
					ans = true;
					break;
			}

			ITER u_it;
			bool contains = false;
			for(u_it = unvisited.begin(); u_it != unvisited.end(); u_it++){
				if((u_it->first == p.first) && (u_it->second == p.second)){
					contains = true;
					break;
				}
			}
			if(contains)
				unvisited.erase(u_it);
			
			//find next movable points and insert it into the queue
			for(ITER it = unvisited.begin(); it != unvisited.end(); it++){
				if(sqrt(pow((it->first-p.first),2.0) + pow((it->second-p.second),2.0)) <= J) queue.push_back(*it);
			}
		}
		if(ans)
			printf("YES\n");
		else
			printf("NO\n");
	}
}