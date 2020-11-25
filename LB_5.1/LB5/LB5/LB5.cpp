#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <locale.h>

using namespace std;
int** G;
int* vis;
int ver;

void BFS(int s, int rows) {
    int v;
    queue <int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        v = q.front();
        printf(" %d", v);
        q.pop();
        for (int i = 0; i < rows; i++) {
            if (G[v][i] == 1 && vis[i] == 0) {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{setlocale(LC_ALL, "Rus");

    int rows;
    int n = 0;
    int k = 0;
    system("cls");
    printf("Укажите размер массива:");
    scanf("%d", &rows);
    srand(time(NULL));
    G = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        G[i] = (int*)malloc(rows * sizeof(int));
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            G[i][j] = rand() % 2;
            if (i == j) {
                G[i][j] = 0;
            }
            G[j][i] = G[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    vis = (int*)malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++) {
        vis[i] = 0;
    }
    printf("\n");
    printf("Вершина:");
    scanf("%d", &ver);
    printf("\n");
    BFS(ver, rows);
    for (int i = 0; i < rows; i++)
        free(G[i]);
    free(G);
    getch();
    return 0;
}
