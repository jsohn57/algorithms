#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

#define PAIR pair<double, double>
#define MP(x,y) make_pair(x,y)

int C;
int N;
vector<PAIR> L;

bool is_reachable(int D)
{
	set<PAIR> visited;
	vector<PAIR> dest;
	dest.push_back(L[0]);
	while(!dest.empty()){
		PAIR node = dest.back();	
		dest.pop_back();
		visited.insert(node);
		for(vector<PAIR>::iterator it = L.begin(); it != L.end(); it++){
			if(visited.find(node) == visited.end() && 
				sqrt(pow(node.first-it->first, 2.0)+pow(node.second-it->second, 2.0)) > D)
					dest.push_back(node);
		}
	}
	if(L.size() == visited.size()) return true;
	else return false;
}
int main()
{
	cin >> C;
	for(int i = 0; i < C; i++){
		cin >> N;
		int x = 0, y = 0;
		for(int j = 0; j < N; j++){
			cin >> x >> y;
			L.push_back(MP(x,y));
		}

		double D = 750.0;
		for(int i = 0; i < 100; i++){
			if(is_reachable(D)){
				//find better answer
				D /= 2.0;
			}
			else{
				D *= 1.5;
			}
		}
		printf("%0.2f\n", (round(D*100.0)/100.0)); 
	}
}