#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define PAIR pair<double, double>
#define MP(x,y) make_pair(x,y)

int C;
int N;
vector<PAIR> L;

bool is_reachable(double D)
{
	set<PAIR> visited;
	vector<PAIR> dest;
	dest.push_back(L[0]);
	while(!dest.empty()){
    //printf("dest size = %lu\n", dest.size());
		PAIR node = dest.back();	
		dest.pop_back();
    if(visited.find(node) == visited.end()){
		  visited.insert(node);
		  for(vector<PAIR>::iterator it = L.begin(); it != L.end(); it++){
		    //printf("sqrt = %f\n", sqrt(pow(node.first-it->first, 2.0)+pow(node.second-it->second, 2.0)));
        if(sqrt(pow(node.first-it->first, 2.0)+pow(node.second-it->second, 2.0)) < D){
            //printf("push_back!\n");
            dest.push_back(*it);
        }
		  }
    }
	}
	//printf("L size = %lu, visited list size = %lu\n", L.size(), visited.size());
	if(L.size() == visited.size()) return true;
	else return false;
}
int main()
{
	cin >> C;
	for(int i = 0; i < C; i++){
    L.clear();
		cin >> N;
    //printf("N = %d\n", N);
		double x = 0.0, y = 0.0;
		for(int j = 0; j < N; j++){
			cin >> x >> y;
			L.push_back(MP(x,y));
		}

		double D = 0.0, min = 0.0, max = 1500;
		for(int j = 0; j < 100; j++){
			D = (min + max)/2;
		  //printf("min = %f, max = %f, D = %f\n", min, max, D);
			if(is_reachable(D)){
				//find better answer
				max = D;
			}
			else{
				min = D;
			}
		}
		printf("%0.2f\n", (round(D*100.0)/100.0)); 
	}
}
