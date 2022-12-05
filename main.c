#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10
#define SquareFree ' '
#define SquareOccupied 'X'

void displayGrid(int grid[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", grid[y][x] == 0 ? SquareFree : SquareOccupied);
        }
        printf("\n");
    }
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

void fillOneSquare(int grid[HEIGHT][WIDTH]) {
    // To do
}

int main() {
    int grid[HEIGHT][WIDTH];
    initializeGrid(grid);
    while (!isFull(grid)) {
        fillOneSquare(grid);
        displayGrid(grid);
    }
    return 0;
}
