#include <stdio.h>

int main(){
	int testcase = 0, i = 0, j = 0, out_idx = 0, linesize = 81;
	char pre_prev;
	char prev;
	char buf[100][81];
	char out_buf[81];
	fgets(out_buf, 81, stdin);
	sscanf(out_buf, "%d\n", &testcase);

	for(i = 0; i < testcase; i++){
		for(j = 0; j < 81; j++){
			buf[i][j] = '\0';
		}
	}

	for(i = 0; i < testcase; i++){
		//scanf("%s", buf[i]);
		
		fgets(buf[i], 81, stdin);
	}
	for(i = 0; i < testcase; i++){
		out_idx = 0;
		for(j = 0; j < 81; j++){
			out_buf[j] = '\0';
		}

		for(j = 0; j < 81; j++){
			if(pre_prev == '%' && prev == '2'){
				if(buf[i][j] == '0'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = ' ';
				}
				else if(buf[i][j] == '1'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = '!';
				}
				else if(buf[i][j] == '4'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = '$';
				}
				else if(buf[i][j] == '5'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = '%';
				}
				else if(buf[i][j] == '8'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = '(';
				}
				else if(buf[i][j] == '9'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = ')';
				}
				else if(buf[i][j] == 'a'){
					out_idx = out_idx-2;	
					out_buf[out_idx] = '*';
				}
				else{
					out_buf[out_idx] = buf[i][j];
				}
			}	
			else{
				out_buf[out_idx] = buf[i][j];
			}

			pre_prev = prev;
			prev = buf[i][j];
			out_idx++;
		}
		printf("%s", out_buf);
	}
}