#include <stdio.h>

void reset(char *name, int len){
	for(int i = 0; i < len; i++){
		name[i] = '\0';
	}	
}
int main(){
	int testcase = 0, i = 0;
	char name[51];

	scanf("%d", &testcase);
	for(;i < testcase;i++){
		reset(name, 51);	
		scanf("%s", name); 
		printf("Hello, %s!\n", name);
	}
}
