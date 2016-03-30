#include <iostream>

using namespace std;

bool is_null(char *ca){
	int idx = 0;
	while(idx < 10000){
		if(ca[idx] != '\0')
			return false;
		idx++;
	}
	return true;
}
void ca_init(char *ca){
	int idx = 0;
	while(idx < 10000){
		ca[idx] = '\0';
		idx++;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int testcase = 0;
	cin >> testcase;
	char buf[10000];
	char stack[10000];
	bool answer = true;

	for(int i = 0; i < testcase; i++){
		int buf_idx = 0;
		int stack_idx = 0;
		ca_init(buf);
		ca_init(stack);
		answer = true;
		cin >> buf;
		while(buf[buf_idx] != '\0'){
			char c = buf[buf_idx];
			if(c == '[' || c == '{' || c == '('){
				stack[stack_idx] = c;
				stack_idx++;
			}
			else{
				char cmp_c;
				if(c == ']') cmp_c = '[';
				else if(c == '}') cmp_c = '{';
				else cmp_c = '(';
				if(stack_idx < 1 || stack[--stack_idx] != cmp_c){
					answer = false;
					break;
				}
				else{
					stack[stack_idx] = '\0';
				}
			}
			//printf("stack = %s\n", stack);
			buf_idx++;
		}

		//printf("buf = %s\nstack at the end = %s\n", buf, stack);
		if(answer && is_null(stack))
			printf("%s\n", "YES");
		else
			printf("%s\n", "NO");
	}
}