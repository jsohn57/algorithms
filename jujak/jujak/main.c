//
//  main.c
//  jujak
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_N 1000001
int C[MAX_N];
int N;

int main(int argc, const char * argv[]) {

	memset(C, 0, sizeof(int)*MAX_N);
	scanf("%d", &N);
	int ans = 0;
	srand(time(NULL));
	for (int i = 1; i <= N; i++){
		scanf("%d", &C[i]);
		if (C[i] == i) ans = -1;
	}
	
	/*
	while (1){
		int tmp = rand() + MAX_N;
		int found = 1;
		for (int i = 2; i <= MAX_N; i++){
			if (tmp % i == 0) found = 0;
		}
		if (found){
			printf("%d\n", tmp);
			return 0;
		}
	}
	*/
	
	if (ans == 0) ans = 1022123;
	printf("%d\n", ans);
	return 0;
}
