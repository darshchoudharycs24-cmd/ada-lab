#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define INF 9999999
#define V 15

// 15x15 adjacency matrix
int G[V][V] = {
    {0, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2},
    {4, 0, 8, 0, 0, 0, 0, 11, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2, 0, 0, 0, 0, 0, 0},
    {0, 0, 7, 0, 9, 14, 0, 0, 0, 3, 0, 0, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0, 0, 5, 0, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0, 0, 0, 6, 0, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6, 0, 0, 0, 7, 0, 0},
    {8, 11, 0, 0, 0, 0, 1, 0, 7, 0, 0, 0, 0, 3, 0},
    {0, 0, 2, 0, 0, 0, 6, 7, 0, 4, 0, 0, 0, 0, 9},
    {0, 0, 0, 3, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0},
    {0, 0, 0, 0, 5, 0, 0, 0, 0, 8, 0, 9, 0, 0, 0},
    {0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 9, 0, 11, 0, 0},
    {0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 11, 0, 10, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 10, 0, 12},
    {2, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 12, 0}
};

int main() {
    clock_t start, end;
    double cpu_time;

    int repeat = 1000;   // repeat for measurable time

    start = clock();

    for(int r = 0; r < repeat; r++) {

        int no_edge = 0;
        int selected[V];

        memset(selected, false, sizeof(selected));
        selected[0] = true;

        int x, y;

        if (r == 0)
            printf("Edge : Weight\n");

        while (no_edge < V - 1) {
            int min = INF;
            x = 0;
            y = 0;

            for (int i = 0; i < V; i++) {
                if (selected[i]) {
                    for (int j = 0; j < V; j++) {
                        if (!selected[j] && G[i][j]) {
                            if (min > G[i][j]) {
                                min = G[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            if (r == 0)
                printf("%d - %d : %d\n", x, y, G[x][y]);

            selected[y] = true;
            no_edge++;
        }
    }

    end = clock();

    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nExecution Time: %f seconds\n", cpu_time);

    return 0;
}