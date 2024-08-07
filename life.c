#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <stdio.h>


struct winsize w;
int BUFFER_HEIGHT;
int BUFFER_WIDTH;

int countNeighbors(int board[BUFFER_HEIGHT][BUFFER_WIDTH], int row, int col) {
    int count = 0;

    int rowOffsets[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colOffsets[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowOffsets[i];
        int newCol = col + colOffsets[i];

        if (newRow >= 0 && newRow < BUFFER_HEIGHT && newCol >= 0 && newCol < BUFFER_WIDTH) {
            if (board[newRow][newCol] == 1) {
                count++;
            }
        }
    }

    return count;
}

void print_board(int board[BUFFER_HEIGHT][BUFFER_WIDTH]){
    int count = 0;
    for(int i = 0; i < BUFFER_HEIGHT; ++i){
        for(int j = 0; j < BUFFER_WIDTH; ++j){
            char * cell = board[i][j] == 1 ? "@": " ";
            if (strcmp(cell, "@") == 0)
                ++count;
            printf("%s", cell);
        }
        printf("\n");
    }
    printf("Population Size: %d\n", count);
}

void init_board(int board[BUFFER_HEIGHT][BUFFER_WIDTH]){
    for(int i = 0; i < BUFFER_HEIGHT; ++i)
        for(int j = 0; j < BUFFER_WIDTH; ++j)
            board[i][j] = rand() % 2;
}

void update_board(int board[BUFFER_HEIGHT][BUFFER_WIDTH]){
    int new_board[BUFFER_HEIGHT][BUFFER_WIDTH];
    memset(new_board, 0, sizeof(new_board[0][0]) * BUFFER_HEIGHT * BUFFER_WIDTH);

    for(int i = 0; i < BUFFER_HEIGHT; ++i){
        for(int j = 0; j < BUFFER_WIDTH; ++j){
            int num_neighbors = countNeighbors(board, i,j);
            int cell = board[i][j];

            if (cell && num_neighbors < 2)
                new_board[i][j] = 0;
            if (cell && (num_neighbors == 2 || num_neighbors == 3))
                new_board[i][j] = 1;
            if (cell && num_neighbors > 3)
                new_board[i][j] = 0;
            if (!cell && num_neighbors == 3)
                new_board[i][j] = 1;
        }
    }
    memcpy(board, new_board, sizeof(board[0][0]) * BUFFER_HEIGHT * BUFFER_WIDTH);
}

void clearScreen() {
    printf("\033[H\033[J");
}

void animate(int board[BUFFER_HEIGHT][BUFFER_WIDTH]) {
    while(1){
        clearScreen();
        print_board(board);
        update_board(board);
        usleep(100000);
    }
}

void main(){
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    BUFFER_HEIGHT = w.ws_row - 5;
    BUFFER_WIDTH = w.ws_col - 5;

    int board[BUFFER_HEIGHT][BUFFER_WIDTH];
    memset(board, 0, sizeof(board[0][0]) * BUFFER_HEIGHT * BUFFER_WIDTH);

    init_board(board);
    animate(board);
}