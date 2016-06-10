#include <stdio.h>
#include <string.h>

char c_board[201][201];
int board[201][201];
int visited[201 * 201];
int end_blocks[100 * 100];
int N, M;

void connected(int src, int i, int j)
{
    if(i%2 == 0 || j%2 == 0) return;
	if (visited[i*100 + j] == 1 || c_board[i][j] == 'O') return;
	
	// right and lower
	board[i][j] = src;
    visited[i*100+j] = 1;
	if (j < 2*N-2 && c_board[i][j + 1] == '.') connected(src, i, j + 2);
	if (i < 2*M-2 && c_board[i + 1][j] == '.') connected(src, i + 2, j);
    if (i > 2 && c_board[i-1][j] == '.') connected(src, i-2, j);
    if (j > 2 && c_board[i][j - 1] == '.') connected(src, i, j - 2);

}

int main()
{
	double K;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%lf", &K);

	memset(c_board, 0, sizeof(char) * 201 * 201);
    memset(visited, 0, sizeof(int) * 201 * 201);

	// input
	for (int i = 0; i <= 2 * M; i++){
		for (int j = 0; j <= 2 * N; j++){
            
			scanf("%c", &c_board[i][j]);
		}
	}

    for(int i = 0; i <= 2*M; i++){
        for(int j = 0; j <= 2*N; j++){
            if(i%2 == 1 && j%2 == 1) connected(i*100+j, i, j);
        }
    }

    printf("\n");
    for(int i = 0; i <= 2*M; i++){
        for(int j = 0; j <= 2*N; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}