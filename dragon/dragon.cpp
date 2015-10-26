#include <iostream>
#include <string>

using namespace std;

int CL[51];

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
		curve("FX", N);
	}
	cout << endl;
	return 0;
}