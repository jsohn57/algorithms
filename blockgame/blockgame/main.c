#include <stdio.h>
#include <string.h>

char c_board[201][201];
int board[201][201];
int f_board[100][100];
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
	scanf("%lf\n", &K);
    //scanf("%c", &newline);  // scanf("%c") does not remove the leading whitespace or new line

	memset(c_board, 0, sizeof(char) * 201 * 201);
    memset(visited, 0, sizeof(int) * 201 * 201);

	// input
	for (int i = 0; i <= 2 * M; i++){
        char tmp;
		for (int j = 0; j <= 2 * N; j++){
            scanf("%c", &tmp);
            c_board[i][j] = tmp;
		}
        scanf("%c", &tmp); // for new line
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
    
    int i_ctr = M-1, j_ctr = 0;
    for(int i = 0; i <= 2*M; i++){
        if(i%2 == 0) continue;
        for(int j = 0; j <= 2*N; j++){
            if(j%2 == 1) f_board[i_ctr][j_ctr++] = board[i][j];
        }
        if(i%2 == 1){
            i_ctr--;
            j_ctr = 0;
        }
    }
    
    printf("\n");
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", f_board[i][j]);
        }
        printf("\n");
    }
    
    double dst_x = 0, dst_y = 0;
    double src_x = K, src_y = 0;
    double b;
    
    // first arrow
    b = src_x/2.0;
    dst_x = 0; dst_y = K/2.0;
    for(int i = src_y; i < dst_y; i++){
        printf("x = %lf, y = %d\n", 2*i+K, i);
    }
    src_x = dst_x; src_y = dst_y;
    
    // second arrow
    dst_x = 2*dst_y-K; dst_y = M-1;
    for(int i = src_y; i < dst_y; i++){
        printf("x = %lf, y = %d\n", 2*i-K, i);
    }
    src_x = dst_x; src_y = dst_y;
    
    // third arrow
    dst_x = N-1; dst_y =
    for(int i = src_y; i < dst_y; i++){
        printf("x = %lf, y = %d\n", 2*i-K, i);
    }
    src_x = dst_x; src_y = dst_y;
    
    
    return 0;
}