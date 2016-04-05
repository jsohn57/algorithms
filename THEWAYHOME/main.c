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

int find_min()
{
    int next = 0;
    int min_dist = MAX_N*MAX_D;
    for(int i = 1; i <= N; i++){
        if(!visited[i] && D[i] < min_dist){
            min_dist = D[i];
            next = i;
        }
    }
    return next;
}

int Dijkstra()
{
    int next = 0;
    int cur_dist = 0;
    int v_ctr = 1;

    while(v_ctr <= N){
        next = find_min();
        visited[next] = 1;
        v_ctr++;
        
        if(next == 1) break;
        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                cur_dist = D[next] + E[next][i];
                if(cur_dist < D[i]) D[i] = cur_dist;
            }
        }
    }
    return D[1];
}

int main()
{
    memset(visited, 0, sizeof(int)*MAX_N);
    memset(E, MAX_D, sizeof(int)*MAX_N*MAX_N);
    //memset(D, MAX_N*MAX_D, sizeof(int)*MAX_N);
    for(int i = 0; i < MAX_N; i++){
        D[i] = MAX_N*MAX_D;
    }
    scanf("%d %d", &T, &N);
    int s, e, d;
    
    for(int t = 0; t < T; t++){
        scanf("%d %d %d", &s, &e, &d);
        if(E[s][e] > d){
            E[s][e] = d;
            E[e][s] = d;
        }
    }
    
    D[N] = 0;
    int ans = Dijkstra();
    printf("%d\n", ans);
    
    return 0;
}