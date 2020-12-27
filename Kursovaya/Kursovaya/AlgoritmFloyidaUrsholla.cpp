#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <locale.h>
//Глобальные переменные
using namespace std;
int** G;
//Объявление функций
void Menu(int rows, int** G);
void ManualInput(int rows, int** G);
void RandomInput(int rows, int** G);
void OutputMatrix(int rows, int** G);
void OutputMatrixFile(int rows, int** G,FILE *save);
int main()
	{
		//Подключение кириллицы
		setlocale(LC_ALL, "Rus");

	int rows; //размер матрицы
	FILE *save;
	char filename[16];

	printf("Укажите размер массива:");
	scanf("%d", &rows);
	printf("Укажите файл для сохранения:");//открытие файла сохранения 
		scanf("%s",&filename);
		save = fopen(filename,"a");
	 printf("\n");
	srand(time(NULL));
	 G = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++){
        G[i] = (int*)malloc(rows * sizeof(int));
			}

	Menu(rows, G);//меню выбора ввода
	OutputMatrix(rows, G);//Вывод матрицы
	fprintf(save ,"Матрица:\n");
	OutputMatrixFile(rows, G, save);

	 //Алгоритм Флойда-Уоршалла
	 for(int k = 0; k < rows; k++) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < rows; j++) {
                //Новое значение ребра равно минимальному между старым
                //и суммой ребер i <-> k + k <-> j (если через k пройти быстрее)
                if(G[i][j] > G[i][k] + G[k][j])
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	OutputMatrix(rows, G);// ВЫВОД МАТРИЦЫ после обработки алгоритмом 
	fprintf(save ,"Матрица после работы алгоритма:\n");
	OutputMatrixFile(rows, G, save);

	//Конец программы
	getch();
    return 0;
}
void ManualInput(int rows, int** G){
// Ручной ввод
	for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
				if (i == j) {
					G[i][j] = 0;
					break;
				}	//Растояние от элемента до самого себя

            printf("Введите растояние от %d до %d: ",i,j);
			scanf("%d",&G[i][j]);
			if(G[i][j] == G[j][i])
				break; 

            G[j][i] = G[i][j];// Растояние от A до B = от B до A
        }
    }
}
void RandomInput(int rows, int** G){
	 for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            G[i][j] = rand() % 200;
            if (i == j)
                G[i][j] = 0;
			if(G[i][j] > 100)
					G[i][j] = 1000;//очень большое число
            G[j][i] = G[i][j];
        }
	}
}
void Menu(int rows, int** G){
	int menu;
	int f = 0;

	while(f != 1){
	printf("Укажите как будет происходить заполнение:\n");
	printf("1.Случайное\n");
	printf("2.Ручное\n");

		scanf("%d", &menu);
			if(menu > 2 || menu < 1){
				f = 0;
				printf("Попробуйте ещё раз\n");
				}
			else
				f = 1;
		}
			switch(menu){
			case 1: 
				RandomInput(rows, G);//Случайное заполнение матрицы
				break;
			case 2: 
				ManualInput(rows, G);//Ручной ввод 
				break;
		}
	}
void OutputMatrix(int rows, int** G){
	//вывод матрицы
	for (int i = 0; i < rows; i++)
	 {
        for (int j = 0; j < rows; j++)
		   {
            printf("| %d\t", G[i][j]);
		    }
			    printf("\n");
	 }
	 printf("\n");
	 }
void OutputMatrixFile(int rows, int** G,FILE *save){
	//вывод матрицы
	for (int i = 0; i < rows; i++)
	 {
        for (int j = 0; j < rows; j++)
		   {
            fprintf(save ,"| %d\t", G[i][j]);
		    }
			    fprintf(save,"\n");
	 }
	 fprintf(save, "\n");
	 }