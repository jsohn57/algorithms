
#include <stdio.h>
#include <string.h>
#define MAX_N 20

int A[MAX_N];
int A_ctr;
int B[MAX_N];
int B_ctr;
int C[MAX_N];
int C_ctr;

int moves;
int N;

void go(char src, char dest){
    int cur = 0;
    switch(src){
        case 'A' : cur = A[--A_ctr]; break;
        case 'B' : cur = B[--B_ctr]; break;
        case 'C' : cur = C[--C_ctr]; break;
    }
    switch(dest){
        case 'A' : A[A_ctr++] = cur; break;
        case 'B' : B[B_ctr++] = cur; break;
        case 'C' : C[C_ctr++] = cur; break;
    }
    printf("%d : %c -> %c\n", cur, src, dest);
    return;
}

void solve(int n, char src, char aux, char dest, int p){
    if(n == 1){
        moves++;
        if(p) go(src, dest);
        return;
    }
    solve(n-1, src, dest, aux, p);
    solve(1, src, aux, dest, p);
    solve(n-1, aux, src, dest, p);
}

int main() {
    moves = 0; A_ctr = 0; B_ctr = 0; C_ctr = 0;
    memset(A, 0, sizeof(int)*MAX_N);
    memset(B, 0, sizeof(int)*MAX_N);
    memset(C, 0, sizeof(int)*MAX_N);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        A[i] = N-i;
        A_ctr++;
    }
    solve(N, 'A', 'B', 'C', 0);
    printf("%d\n", moves);
    solve(N, 'A', 'B', 'C', 1);
    
    return 0;
}
