#include <iostream>

using namespace std;

char left_input[250];
char right_input[250];
char res_input[250];
char op[2];
char result[250];

// remember the current value for question mark position
char li_q_position[250];
char ri_q_position[250];

// remember the question mark indices
char li_idx[250];
char ri_idx[250];

int calc_error = 0;

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
  printf("last indices : res_input = %c\tresult = %c", res_input[idx], result[idx]);
  if(res_input[idx] != '\0' || result[idx] != '\0') return 0;
  return 1;
}

void init()
{
  for(int i = 0; i < 250; i++){
    li_q_position[i] = '\0';
    ri_q_position[i] = '\0';
  }

  int l_idx = 0;
  int r_idx = 0;
  for(int i = 0; i < 250; i++){
    if(left_input[i] == '?'){
      li_q_position[i] = '0';
      li_idx[l_idx] = i;
      l_idx++;
    }
    if(right_input[i] == '?'){
      ri_q_position[i] = '0';
      ri_idx[r_idx] = i;
      r_idx++;
    }
  }
}

int find_next_val(int lorr){
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
		printf("sub_result = %d\n carry = %d\n sub_result_remainder = %d\n result[idx] = %c\n", sub_result, carry, (sub_result)%10, result[idx]);
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
		printf("sub_result = %d\ncarry = %d\nresult[idx] = %c\n", sub_result, carry, result[idx]);
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
	printf("calculation error = %d\n", calc_error);
}

void reverse(char *input)
{
	int idx = 0;
	while(input[idx] != '\0') idx++;

	int half = idx/2;
	for(int i = 0; i < half; i++){
		char tmp = input[i];
		input[i] = input[idx-i-1];
		input[idx-i-1] = tmp;
	}
}

int main()
{
	int testcase;
	char equal_op[2];
	cin >> testcase;

	for(int i = 0; i < testcase; i++){
		memset(left_input, 250, '\0');
		memset(right_input, 250, '\0');
		memset(res_input, 250, '\0');
		memset(op, 2, '\0');
		memset(result, 250, '\0');
		calc_error = 0;
		cin >> left_input >> op >> right_input >> equal_op >> res_input;
		//cin >> left_input >> op >> right_input;
		reverse(left_input);
		reverse(right_input);

		if(op[0] == '+'){
			add();
		}
		else{
			subtract();
		}
		reverse(result);
    if(is_answer())
		  printf("answer = %s\n", result);
		//printf("left_input = %s\n op = %s\n right_input = %s\n equal_op = %s\n res_input = %s\n",
		//								left_input, op, right_input, equal_op, res_input);
	}
	
}
