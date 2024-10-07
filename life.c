#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 5
#define COL 5

void InitBoard(int a[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            while (1) {
                printf("Enter value for cell (%d, %d) (0 or 1): ", i, j);
                scanf("%d", &a[i][j]);
                if (a[i][j] == 0 || a[i][j] == 1) {
                    break;
                }
                printf("Error: Please enter 0 or 1.\n");
            }
        }
    }
}

void PrintBoard(int a[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", a[i][j] == 1 ? '*' : ' ');
        }
        printf("\n");
    }
}


int CountLiveNeighbors(int a[ROW][COL], int r, int c) {
    int liveCount = 0;
    for (int i = r - 1; i <= r + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if ((i == r && j == c) || (i < 0 || j < 0) || (i >= ROW || j >= COL)) {
                continue;
            }
            if (a[i][j] == 1) {
                liveCount++;
            }
        }
    }
    return liveCount;
}

 /*
int CountLiveNeighbors(int a[ROW][COL], int r, int c) {
    int liveCount = 0;
    
    if ((r - 1 >= 0) && (a[r-1][c] == 1)) {
        liveCount++;
    }

    if ((r + 1 < ROW) && (a[r+1][c] == 1)) {
        liveCount++;
    }

    if ((c - 1 >= 0) && (a[r][c-1] == 1)) {
        liveCount++;
    }

    if ((c+1 < COL) && (a[r][c+1] == 1)) {
        liveCount++;
    }

    if ((r-1 >= 0) && (c-1 >= 0) && (a[r-1][c-1] == 1)) {
        liveCount++;
    }

    if (((r+1 < ROW) && (c+1 < COL) && a[r+1][c+1] == 1)) {
        liveCount++;
    }

    if (((r+1 < ROW) && (c-1 >= 0) && a[r+1][c-1] == 1)) {
        liveCount++;
    }

    if (((r-1 >= 0) && (c+1<COL) && a[r-1][c+1] == 1)) {
        liveCount++;
    }

    return liveCount;
}
*/
void UpdateBoard(int a[ROW][COL], int newBoard[ROW][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            int liveNeighbors = CountLiveNeighbors(a, i, j);
            if (a[i][j] == 1) {
                if (liveNeighbors < 2 || liveNeighbors > 3) {
                    newBoard[i][j] = 0;
                } else {
                    newBoard[i][j] = 1;
                }
            } else {
                if (liveNeighbors == 3) {
                    newBoard[i][j] = 1;
                } else {
                    newBoard[i][j] = 0;
                }
            }
        }
    }
}

void Generations(int generations) {
    int a[ROW][COL];
    int newBoard[ROW][COL];
    srand(time(NULL));

    InitBoard(a);

    for (int g = 0; g < generations; g++) {
        printf("Generation: %d\n", g);
        PrintBoard(a);
        UpdateBoard(a, newBoard);
        
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                a[i][j] = newBoard[i][j];
            }
        }
        printf("\n");
    }
}

void EndMessage() {
    char c;
    printf("Good life!\nPress 'q' to quit or any other key to continue: ");
    scanf(" %c", &c);
    if (c != 'q') {
        printf("\nRestarting...\n");
        Generations(7);
    } else {
        printf("Bye Bye!\n");
    }
}

int main() {
    while (1) {
        Generations(7);
        EndMessage();
    }
    return 0;
}