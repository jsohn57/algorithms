#include <iostream>

using namespace std;

char add_map[10][11] = {
	"0123456789", 
	"1234567890", 
	"2345678901",
	"3456789012",
	"4567890123",
	"5678901234",
	"6789012345",
	"7890123456",
	"8901234567",
	"9012345678"
};
char sub_map[10][11] = {
	"0987654321",
	"1098765432",
	"2109876543",
	"3210987654",
	"4321098765",
	"5432109876",
	"6543210987",
	"7654321098",
	"8765432109",
	"9876543210"	
};

char left_input[250];
char right_input[250];
char res_input[250];
char op[2];
char result[250];

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
		//cin >> left_input >> op >> right_input >> equal_op >> res_input;
		cin >> left_input >> op >> right_input;
		reverse(left_input);
		reverse(right_input);

		if(op[0] == '+'){
			add();
		}
		else{
			subtract();
		}
		reverse(result);
		printf("result = %s\n", result);
		//printf("left_input = %s\n op = %s\n right_input = %s\n equal_op = %s\n res_input = %s\n",
		//								left_input, op, right_input, equal_op, res_input);
	}
	
}