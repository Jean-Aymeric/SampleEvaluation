#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 50
#define SquareFree ' '
#define SquareOccupied 'X'

void displayGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] == 0 ? SquareFree : SquareOccupied);
        }
        printf("\n");
    }
    system("CLS");
}

void initializeGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[y][x] = 0;
        }
    }
}

int isFull(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int isEmpty(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[y][x] != 0) {
                return 0;
            }
        }
    }
    return 1;
}

int isValid(int grid[HEIGHT][WIDTH], int x, int y) {
    if (grid[y][x] == 1) {
        return 0;
    }
    for (int stepY = -1; stepY <= 1; stepY++) {
        for (int stepX = -1; stepX <= 1; stepX++) {
            if ( ((y + stepY) >= 0) && ((y + stepY) < HEIGHT) &&
                    ((x + stepX) >= 0) && ((x + stepX) < WIDTH)) {
                if (grid[y + stepY][x + stepX] == 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void fillOneSquare(int grid[HEIGHT][WIDTH]) {
    // To do
    srand( time( NULL ));
    int y, x;
    if (isEmpty(grid)) {
        y = rand() % HEIGHT;
        x = rand() % WIDTH;
        grid[y][x] = 1;
    } else {
        do {
            y = rand() % HEIGHT;
            x = rand() % WIDTH;
        } while(!isValid(grid, x, y));
        grid[y][x] = 1;
    }
}

int main() {
    int grid[HEIGHT][WIDTH];
    initializeGrid(grid);
    while (!isFull(grid)) {
        fillOneSquare(grid);
        displayGrid(grid);

//        printf("Press Enter to continue\n");
//        while( getchar() != '\n' );
    }
    return 0;
}
