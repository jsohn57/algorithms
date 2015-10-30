#include <iostream>
#include <string>

using namespace std;

int XL[51];
int YL[51];

void calc_length()
{
  XL[0] = 1; XL[1] = 4; YL[0] = 0; YL[1] = 1;
  for(int i = 2; i < 51; i++){
    XL[i] = 2*XL[i-1]+2;
    YL[i] = 2*YL[i-1]+2;
  }
}

void curve(const string in, int gen, int count)
{
	if(count == 0 && gen == 0){
		cout << in;	
		return;
	}
	int len = in.length();
	for(int i = 0; i < len; i++){
		if(in[i] == 'X'){
      if(XL[gen] >= count)
			  curve("X+YF", gen-1, count);
      else
        count -= XL[gen];
		}
		else if(in[i] == 'Y'){
      if(YL[gen] >= count)
			  curve("FX-Y", gen-1, count);	
      else
        count -= YL[gen];
		}
		else{
      if(count > 0)
        count--;
      else
			  cout << in[i];	
		}
	}
}

int main()
{
	int C, N, P, L;
  cin >> C;
  cin >> N >> P >> L;
	for(int c = 0; c < C; c++){
    memset(XL, 0, sizeof(int)*51);
    memset(YL, 0, sizeof(int)*51);
    calc_length();
		curve("FX", N, P);
	}
	cout << endl;
	return 0;
}
