#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int arr1[10] = {3, 24, 34, 25, 2, 9, 5, 99, 75, 89};
	int arr2[10] = {3, 24, 34, 25, 2, 9, 5, 99, 75, 99};
	int arr3[5] = {95, 46, 35, 57, 79};

	vector<int> v1(arr1, arr1+10);
	vector<int> v2(arr2, arr2+10);
	vector<int> v3(arr3, arr3+5);

	vector< vector<int> > va;
	va.push_back(v1);
	va.push_back(v2);
	va.push_back(v3);
	for(int i = 0; i < va.size(); i++){
		for(int j = 0; j < va[i].size(); j++){
			printf("v[%d] = %d ", j, va[i][j]);
		}
		printf("\n\n");
	}

}