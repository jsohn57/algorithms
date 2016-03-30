#include <iostream>

using namespace std;

char left_input[250];
char right_input[250];
char res_input[250];
char op[2];
char result[250];

// remember the question mark indices
char li_idx[250];
char ri_idx[250];
int li_len = 0;
int ri_len = 0;
int res_len = 0;
int lq_len = 0;
int rq_len = 0;

int calc_error = 0;
int find_right_finished = 0;

int is_answer(){
  int idx = 0;

  while(res_input[idx] != '\0' && result[idx] != '\0'){
    if(res_input[idx] != result[idx]){
      if(res_input[idx] != '?'){
        return 0;
      }
    }
    idx++;
  }
  //printf("last indices : res_input = %c\tresult = %c", res_input[idx], result[idx]);
  if(res_input[idx] != '\0' || result[idx] != '\0') return 0;
  return 1;
}

// after reverse
void q_init()
{
	lq_len = 0;
	rq_len = 0;
	int l_len = 0;
	int r_len = 0;
	find_right_finished = 0;
  for(int i = 0; i < 250; i++){
		li_idx[i] = -1;
		ri_idx[i] = -1;
  }

  for(int i = 0; i < 250; i++){
    if(left_input[i] == '?'){
			if(li_len != 1 && i == li_len-1)
				left_input[i] = '1';
			else
				left_input[i] = '0';
      li_idx[lq_len] = i;
      lq_len++;
    }
    if(right_input[i] == '?'){
			if(ri_len != 1 && i == ri_len-1)
				right_input[i] = '1';
			else
      	right_input[i] = '0';
      ri_idx[rq_len] = i;
      rq_len++;
    }
  }
}

void find_next_val(int lorr){
	//left input case
	int carry = 1;
	int idx = 0;
	int sub_result = 0;
	if(lorr == 0){
		if(lq_len == 0){
			return;
		}
		while(carry == 1){
			sub_result = left_input[li_idx[idx]] - 48 + 1;
			//printf("idx = %d\tli_idx = %d\tsub_result = %d\n", idx, li_idx[idx], sub_result);
			(sub_result > 9 ? carry = 1 : carry = 0);
			left_input[li_idx[idx]] = 48 + ((sub_result)%10);
			idx++;
		}	
	}
	else{ //right input case
		if(rq_len == 0){
			find_right_finished = 1;
			return;
		}
		while(carry == 1){
			sub_result = right_input[ri_idx[idx]] - 48 + 1;
			(sub_result > 9 ? carry = 1 : carry = 0);
			right_input[ri_idx[idx]] = 48 + ((sub_result)%10);
			idx++;
		}	
		if(idx == rq_len+1 && sub_result == 9){
			find_right_finished = 1;
		}
	}
}
void add()
{
	int idx = 0;
	int carry = 0;
	while(left_input[idx] != '\0' || right_input[idx] != '\0'){
		int sub_result = 0;
		if(left_input[idx] == '\0'){
			sub_result = right_input[idx]-48 + carry;
		}
		else if(right_input[idx] == '\0'){
			sub_result = left_input[idx]-48 + carry;
		}
		else{
			sub_result = left_input[idx]-48 + right_input[idx]-48 + carry;
		}
		result[idx] = 48+((sub_result)%10);
		(sub_result > 9 ? carry = 1 : carry = 0);
		//printf("sub_result = %d\n carry = %d\n sub_result_remainder = %d\n result[idx] = %c\n", sub_result, carry, (sub_result)%10, result[idx]);
		idx++;
	}
	if(carry != 0){
		result[idx] = '1';
	}
}

void subtract()
{
	int idx = 0;
	int carry = 0;
	while(left_input[idx] != '\0'){
		int sub_result = 0;
		if(left_input[idx] == '\0'){
			sub_result = right_input[idx]-48 - carry;
		}
		else if(right_input[idx] == '\0'){
			sub_result = left_input[idx]-48 - carry;
		}
		else{
			sub_result = (left_input[idx]-48) - (right_input[idx]-48) - carry;
		}
		if(sub_result < 0){
      carry = 1;
      sub_result = 10 + sub_result;
		}
    else{
      carry = 0;
    }
		result[idx] = 48+sub_result;
		//printf("sub_result = %d\ncarry = %d\nresult[idx] = %c\n", sub_result, carry, result[idx]);
		idx++;
	}
	if(carry != 0 || right_input[idx] != '\0'){
		calc_error = 1;
	}

  if(result[idx-1] == '0'){
    for(int i=idx-1; i>0; i--){
      if(result[i] == '0'){
        result[i] = '\0';
      }
      else{
        break;
      }
    }
  }
	//printf("calculation error = %d\n", calc_error);
}

void reverse(char *input, int len)
{
	int half = len/2;
	for(int i = 0; i < half; i++){
		char tmp = input[i];
		input[i] = input[len-i-1];
		input[len-i-1] = tmp;
	}
}

int main()
{
	int testcase;
	char equal_op[2];
	freopen("B-large-practice.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	cin >> testcase;

	for(int i = 1; i <= testcase; i++){
		//cin >> left_input >> op >> right_input >> equal_op >> res_input;
		//cin >> left_input >> op >> right_input;
		memset(left_input, '\0', 250);
		memset(right_input, '\0', 250);
		memset(res_input, '\0', 250);
		memset(op, '\0', 2);
		memset(result, '\0', 250);
		li_len = 0;
		ri_len = 0;
		res_len = 0;
		calc_error = 0;
		find_right_finished = 0;

		cin >> left_input >> op >> right_input >> equal_op >> res_input;
		while(left_input[li_len] != '\0') li_len++;
		while(right_input[ri_len] != '\0') ri_len++;
		while(res_input[res_len] != '\0') res_len++;
		reverse(left_input, li_len);
		reverse(right_input, ri_len);
		reverse(res_input, res_len);
		q_init();

		int res = 0;
		while(res == 0){
			calc_error = 0;
			find_right_finished = 0;
			if(op[0] == '+'){
				add();
			}
			else{
				subtract();
			}
			res = is_answer();
			//printf("checking 1: %s %s %s %s %s calc_error = %d\n", left_input, op, right_input, equal_op, result, calc_error);
			while(find_right_finished == 0 && calc_error == 0 && res == 0){
				find_next_val(1);
				if(op[0] == '+'){
					add();
				}
				else{
					subtract();
				}

				//printf("checking 2: %s %s %s %s %s calc_error = %d\n", left_input, op, right_input, equal_op, result, calc_error);
				res = is_answer();
			}
			if(res != 1){
				for(int j = 0; j < rq_len; j++){
					if(ri_idx[j] == ri_len-1)
						right_input[ri_idx[j]] = '1';
					else
      			right_input[ri_idx[j]] = '0';
				}
				find_next_val(0);
			}
		}
		
		reverse(left_input, li_len);
		reverse(right_input, ri_len);
		reverse(result, res_len);	
		printf("Case #%d: %s %s %s %s %s\n", i, left_input, op, right_input, equal_op, result);

	}
	
}
