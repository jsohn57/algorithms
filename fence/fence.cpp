#include <iostream>
#include <algorithm>

using namespace std;

int C, N;
int U[20001]; //un-sorted array
int F[20001]; //sorted array

class Node{
  Node():_key(0), _left(NULL), _right(NULL){};
  Node(int key):_key(key), _left(NULL), _right(NULL){};

  void insert(Node *&root, int key){
    if(!root)
      root = new Node(key);
    else if(_key < key)
      insert(root->_right, key);
    else
      insert(root->_left, key);
  }



  int _key;
  Node *_left;
  Node *_right;
};

int main()
{ 
  cin >> C;
  for(int c = 0; c < C; c++){
    cin >> N; 
    for(int i = 0; i < 20001; i++){
      F[i] = 0;
      U[i] = 0;
    }
   
    for(int n = 0; n < N; n++){
      cin >> F[n]; 
      U[n] = F[n];
    }
    //sort
    sort(F, F+N); 

    int max = 0;
    for(int i = 0; i < N; i++){
      int max_area = 0, area = 0;
      bool conn = false;
      for(int j = 0; j < N; j++){
        if(U[j] >= F[i]){
          area += F[i];
          conn = true;
        }
        else{
          if(area > max_area)
            max_area = area;
          conn = false;
          area = 0;
        }
      }
      // end case
      if(area > max_area)
        max_area = area;
      if(max_area > max)
        max = max_area;
    }

    printf("%d\n", max);
  }
  return 0;
}
