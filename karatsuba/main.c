//
//  main.c
//  Karatsuba
//
//  Created by Security Lab on 4/12/16.
//  Copyright (c) 2016 Security Lab. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 200000

int X[MAX_N];
int Y[MAX_N];

void normalize(int *R, int r_len)
{
    
}

// x + y assuming x > y (x_len > y_len)
void add(int *R, int r_len, int *X, int x_len, int *Y, int y_len)
{
    for(int i = 0; i < x_len; i++){
        R[i] = X[i]+Y[i];
    }
    normalize(R, r_len);
}

// x - y assuming x > y (x_len > y_len)
void sub(int *R, int r_len, int *X, int x_len, int *Y, int y_len)
{
    for(int i = 0; i < y_len; i++){
        R[i] = X[i]-Y[i];
    }
    normalize(R, r_len);
}

// x - y assuming x > y (x_len > y_len)
void multiply(int *R, int r_len, int *X, int *Y, int x_len, int y_len)
{
    for(int i = 0; i < x_len; i++){
        for(int j = 0; j < y_len; j++){
            R[i+j] += X[i]*Y[j];
        }
    }
    normalize(R, r_len);
}

// x*y assuming y >= x
void karatsuba(int *result, int *res_len, int *X, int *Y, int x_len, int y_len)
{
    //B^m = 10^(x_len/2)
    int len = y_len/2;
    int *x1 = (int *)malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++)
        x1[i] = X[i];
    int *x0 = (int *)malloc(sizeof(int)*len);
    for(int i = len; i < x_len; i++)
        x0[i-len] = X[i];
    int *y1 = (int *)malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++)
        y1[i] = Y[i];
    int *y0 = (int *)malloc(sizeof(int)*len);
    for(int i = len; i < x_len; i++)
        y0[i-len] = Y[i];
    
    int *z2 = (int *)malloc(sizeof(int)*2*len);
    int *z1 = (int *)malloc(sizeof(int)*2*len+1);
    int *z0 = (int *)malloc(sizeof(int)*2*len);
    
    
    free(x0);
    free(x1);
    free(y0);
    free(y1);
}

int main(int argc, const char * argv[])
{
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        int x_len = 0;
        int y_len = 0;
        // mem reset
        for(int i = 0; i < MAX_N; i++){
            X[i] = 0;
            Y[i] = 0;
        }

        // read X
        char in;
        while(scanf("%c", &in)){
            if(in == 'F') X[x_len] = 0;
            else X[x_len] = 1;
            x_len++;
        }

        // read Y
        while(scanf("%c", &in)){
            if(in == 'F') Y[y_len] = 0;
            else Y[y_len] = 1;
            y_len++;
        }
        
        // put in backwards
        for(int i = 0; i < y_len/2; i++){
            int tmp = Y[i];
            Y[i] = Y[y_len-1-i];
            Y[y_len-1-i] = tmp;
        }
        
        // run karatsuba
    }
}
