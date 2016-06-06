#include <stdio.h>

int c_board[200][200];
int board[100][100];
int visited[100 * 100];
int end_blocks[100 * 100];
int N, M;

void connected(int src, int i, int j)
{
	if (visited[i*100 + j] == 1 || c_board[i][j] == 'O') return;
	
	// right
	board[i][j] = src;
	if (c_board[i][j + 1] == '.') connected(src, i, j + 2);
	if (c_board[i + 1][j] == '.') connected(src, i + 2, j);
}

int main()
{
	double K;

	scanf("%d", &N);
	scanf("%d", &M);
	scanf("%f", &K);
	int dots[100];
	memset(c_board, 0, sizeof(int) * 202 * 202);
	memset(blocks, 0, sizeof(int) * 100 * 100);
	for (int m = 0; m < M; m++){
		for (int n = 0; n < N; n++){
			blocks[m * 100 + n] = m * 100 + n;
			end_blocks[m * 100 + n] = 0;
		}
	}

	// input
	for (int i = 1; i <= 2 * M + 1; i++){
		for (int j = 1; j <= 2 * N + 1; j++){
			scanf("%c", &c_board[i][j]);
		}
	}


}