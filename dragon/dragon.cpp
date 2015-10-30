#include <iostream>
#include <string>

using namespace std;

int XL[51];
int YL[51];
void calc_length(int gen)
{
	XL[0] = 1; XL[1] = 4;
	YL[0] = 0; YL[1] = 1;  
	for(int i = 2; i < gen; i++){
		XL[i] = XL[i-1]*2+2
		YL[i] = YL[i-1]*2+2
	}
}

void curve(const string in, int gen)
{
	if(gen == 0){
		cout << in;	
		return;
	}
	int len = in.length();
	for(int i = 0; i < len; i++){
		if(in[i] == 'X'){
			curve("X+YF", gen-1);
		}
		else if(in[i] == 'Y'){
			curve("FX-Y", gen-1);	
		}
		else{
			cout << in[i];	
		}
	}
}

int main()
{
	int C, N, P, L;
	C << cin;
	N << P << L << cin;
	for(int c = 0; c < C; c++){
		memset(CL, 0, sizeof(int)*51);
		calc_length(N);
		curve("FX", N);
	}
	cout << endl;
	return 0;
}