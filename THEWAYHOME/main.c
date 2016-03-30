#include <stdio.h>
#include <string.h>

#define MAX_T 10001
#define MAX_N 1001
#define MAX_D 101

int T;
int N;

int E[MAX_N][MAX_N];
int D[MAX_N];
int visited[MAX_N];

int Dijkstra()
{
    int cur = N;
    int next = 0;
    int cur_dist = 0;
    int min_dist = MAX_D;
    int v_ctr = 1;

    while(v_ctr <= N){
        visited[cur] = 1;
        min_dist = MAX_D;
        for(int i = 1; i <= N; i++){
            if(i != cur){
                if(E[cur][i] < min_dist && !visited[i]){
                    min_dist = E[cur][i];
                    next = i;
                }
                if(D[i] > cur_dist + E[cur][i]){
                    D[i] = cur_dist + E[cur][i];
                }
            }
        }
        cur_dist += min_dist;
        cur = next;
        v_ctr++;
    }
    
    return D[1];
}

int main()
{
    memset(visited, 0, sizeof(int)*MAX_N);
    memset(E, MAX_D, sizeof(int)*MAX_N*MAX_N);
    //memset(D, MAX_D, sizeof(int)*MAX_N);
    
    scanf("%d %d", &T, &N);
    int s, e, d;
    
    
    for(int i = 1; i < MAX_N; i++){
        D[i] = MAX_N*MAX_D;
    }
 
    D[N] = 0;
    for(int t = 0; t < T; t++){
        scanf("%d %d %d", &s, &e, &d);
        if(E[s][e] > d){
            E[s][e] = d;
            E[e][s] = d;
        }
    }
    
    int ans = Dijkstra();
    printf("%d\n", ans);
    
    return 0;
}