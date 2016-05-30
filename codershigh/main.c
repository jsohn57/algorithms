//
//  main.c
//  codershigh
//
//

#include <stdio.h>

#define MAX_N 1000001
int MAX_ANS = 2000000001;
int A[MAX_N];
int CHOOSE[MAX_N];
int N = 0;
int apply()
{
    int jackpot = 1;
    for(int n = 1; n <= N; n++){
        A[n] = CHOOSE[A[n]];
        if(A[n] == n) jackpot = 0;
    }
    return jackpot;
}
int jackpot()
{
    for(int n = 1; n <= N; n++){
        if(A[n] == n) return 0;
    }
    return 1;
}
int main()
{
    int ans;
    for(int i = 1; i <= MAX_N; i++){
        A[i] = i;
        CHOOSE[i] = 0;
    }
    
    scanf("%d", &N);
    for(int n = 1; n <= N; n++){
        int val = 0;
        scanf("%d", &val);
        if(n == val){
            printf("%d\n", -1);
            return 0;
        }
        CHOOSE[n] = val;
    }
    
    // apply two times
    apply();
    apply();
    ans = 2;
    int jp = jackpot();
    
    while(!jp && ans < MAX_N){
        jp = apply();
        ans++;
    }
    
    ans = (ans < MAX_N) ? ans : -1;
    printf("%d\n", ans);
    return 0;
}