#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define N 100
#define M 100
int grid [N][M];

int num_neighbours(int x, int y) {
    int count = 0;
    if (y > 0) {
        count += grid[x][y-1];
    }
    if (y < M-1) {
        count += grid[x][y+1];
    }
    if (x > 0) {
        count += grid[x-1][y];
        if (y > 0) {
            count += grid[x-1][y-1];
        }
        if (y < M-1) {
            count += grid[x-1][y+1];
        }
    }
    if (x < N-1) {
        count += grid[x+1][y];
        if (y > 0) {
            count += grid[x+1][y-1];
        }
        if (y < M-1) {
            count += grid[x+1][y+1];
        }
    }
    return count;
}

void step() {
    int i, j, neighbours;
    int temp[N][M];

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            neighbours = num_neighbours(i, j);
            if (grid[i][j] == 1) {
                if (neighbours == 2 || neighbours ==3) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            } else {
                if (neighbours == 3) {
                    temp[i][j] = 1;
                } else {
                    temp[i][j] = 0;
                }
            }
        }
    }
    //force corners always on
    temp[0][0] = 1;
    temp[0][M-1] = 1;
    temp[N-1][0] = 1;
    temp[N-1][M-1] = 1;
    for(i=0; i<N; i++) {
        memcpy(&(grid[i][0]), &(temp[i][0]), M * sizeof(int));
    }
}

int count_lights() {
    int i, j, count = 0;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            count += grid[i][j];
        }
    }
    return count;
}

void print_grid() {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            printf("%c", grid[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char** argv) {
    int count = atoi(argv[1]);
    int i, j, c;

    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            c = getchar();
            if (c == '\n') {
                c = getchar();
            }
            if (c=='#') {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    //force corners always on
    grid[0][0] = 1;
    grid[0][M-1] = 1;
    grid[N-1][0] = 1;
    grid[N-1][M-1] = 1;
    for (i=0; i<count; i++) {
        step();
    }
    printf("%d\n", count_lights());
}
