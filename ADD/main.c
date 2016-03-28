//
//  main.c
//  ADD
//
//  Created by 손 정훈 on 2016. 3. 27..
//  Copyright (c) 2016년 손 정훈. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define MAX_N 1000001

int N;
int Q;

unsigned long long int V[MAX_N];
int C[MAX_N];
long long int S[MAX_N];

int main() {
    memset(V, 0, sizeof(long long int)*MAX_N);
    memset(C, 0, sizeof(int)*MAX_N);
    memset(S, 0, sizeof(long long int)*MAX_N);
    scanf("%d %d", &N, &Q);
    for(int n = 1; n <= N; n++){
        scanf("%lld", &V[n]);
    }
    for(int q = 0; q < Q; q++){
        int i; int j;
        scanf("%d %d", &i, &j);
        C[i]++; // counter up
        C[i+j]--; // counter down
        S[i+j] -= j;
    }
    
    //calculate sum
    int ctr = 0;
    for(int i = 1; i <= N; i++){
        ctr += C[i];
        S[i] += ctr + S[i-1];
    }

    for(int i = 1; i <= N; i++) V[i] += S[i];
    for(int i = 1; i <= N; i++) printf("%lld ", V[i]);
    
    /*
    printf("V = ");
    for(int i = 0; i <= N; i++)printf("%lld ", V[i]);
    printf("\n");
    
    printf("C = ");
    for(int i = 0; i <= N; i++)printf("%d ", C[i]);
    printf("\n");
    
    printf("S = ");
    for(int i = 0; i <= N; i++)printf("%lld ", S[i]);
    printf("\n");
    return 0;
    */
}
