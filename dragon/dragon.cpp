#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int CL[51];
int MAX_VAL = 1000000900;

void calc_length()
{
  CL[0] = 1;
  for(int i = 1; i < 51; i++){
    CL[i] = min(2*CL[i-1]+2, MAX_VAL);
  }
}

void curve(const string in, int gen, int& count, int& end)
{
  //printf("\ncurve : %s, %d, %d, %d\n", in.c_str(), gen, count, end);
	if(gen == 0){
    int len = (end > in.length()) ? in.length() : end;
    for(int i = 0; i < len; i++){
      cout << in[count-1+i];
      end--;
    }
		count = 1;
		return;
	}
	int len = in.length();
	for(int i = 0; i < len; i++){
    if(end > 0){
		  if(in[i] == 'X'){
        if(gen > 0 && CL[gen] >= count)
			    curve("X+YF", gen-1, count, end);
        else
          count -= CL[gen];
		  }
		  else if(in[i] == 'Y'){
        if(gen > 0 && CL[gen] >= count)
			    curve("FX-Y", gen-1, count, end);	
        else
          count -= CL[gen];
		  }
		  else{
        if(count > 1)
          count--;
        else{
			    cout << in[i];	
          end--;
        }
		  }
    }
    else{
      return;
    }
	}
}

int main()
{
	int C, N, P, L;
  cin >> C;
	for(int c = 0; c < C; c++){
    cin >> N >> P >> L;
    memset(CL, 0, sizeof(int)*51);
    calc_length();
		curve("FX", N, P, L);
    cout << endl;
	}
	cout << endl;
	return 0;
}
