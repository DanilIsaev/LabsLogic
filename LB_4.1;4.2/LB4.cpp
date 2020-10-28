#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

int** a;
int* vis;

void DFS(int s, int rows){
	vis[s] = 1; printf("%d", s);
		for(int i = 0; i < rows; i++  ){
			if(a[s][i] == 1 && vis[i] == 0){
			DFS(i, rows);
			}
		}
}

int main(){
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));

	int rows;
	int nomer;
	int n = 0;
	int k = 0;
	system("cls");
		printf("”кажите размер массива: ");
		scanf("%d", &rows);
		printf("¬ведите номер дл€ прохождени€: ");
		scanf("%d", &nomer);
		a = (int**)malloc(rows * sizeof(int*));

		for(int i = 0; i < rows; i++){
		a[i] = (int*)malloc(rows * sizeof(int));
		}

		for(int i = 0; i < rows; i++){
				for(int j = i; j< rows; j++){
				a[i][j] = rand()%2;
					if(i == j){
					a[i][j] = 0;
					}
				a[j][i] = a[i][j];
				}
		}
		for(int i = 0; i < rows; i++){
			for(int j = 0; j< rows; j++){
				printf("%d\t", a[i][j]);
				}
			printf("\n");
		}
		printf("\n");
		vis = (int*)malloc(rows * sizeof(int)); 

	for (int i = 0; i < rows; i++) { 
	vis[i] = 0; 
	printf("vis=%d\t", vis[i]); 
	} 

	printf("\n"); 
	DFS(nomer,rows); 

getch();
return 0;
}