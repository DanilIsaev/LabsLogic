#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <locale.h>
//���������� ����������
using namespace std;
int** G;
//���������� �������
void Menu(int rows, int** G);
void ManualInput(int rows, int** G);
void RandomInput(int rows, int** G);
void OutputMatrix(int rows, int** G);
void OutputMatrixFile(int rows, int** G,FILE *save);
int main()
	{
		//����������� ���������
		setlocale(LC_ALL, "Rus");

	int rows; //������ �������
	FILE *save;
	char filename[16];

	printf("������� ������ �������:");
	scanf("%d", &rows);
	printf("������� ���� ��� ����������:");//�������� ����� ���������� 
		scanf("%s",&filename);
		save = fopen(filename,"a");
	 printf("\n");
	srand(time(NULL));
	 G = (int**)malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; i++){
        G[i] = (int*)malloc(rows * sizeof(int));
			}

	Menu(rows, G);//���� ������ �����
	OutputMatrix(rows, G);//����� �������
	fprintf(save ,"�������:\n");
	OutputMatrixFile(rows, G, save);

	 //�������� ������-��������
	 for(int k = 0; k < rows; k++) {
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < rows; j++) {
                //����� �������� ����� ����� ������������ ����� ������
                //� ������ ����� i <-> k + k <-> j (���� ����� k ������ �������)
                if(G[i][j] > G[i][k] + G[k][j])
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	OutputMatrix(rows, G);// ����� ������� ����� ��������� ���������� 
	fprintf(save ,"������� ����� ������ ���������:\n");
	OutputMatrixFile(rows, G, save);

	//����� ���������
	getch();
    return 0;
}
void ManualInput(int rows, int** G){
// ������ ����
	for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows; j++)
        {
				if (i == j) {
					G[i][j] = 0;
					break;
				}	//��������� �� �������� �� ������ ����

            printf("������� ��������� �� %d �� %d: ",i,j);
			scanf("%d",&G[i][j]);
			if(G[i][j] == G[j][i])
				break; 

            G[j][i] = G[i][j];// ��������� �� A �� B = �� B �� A
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
					G[i][j] = 1000;//����� ������� �����
            G[j][i] = G[i][j];
        }
	}
}
void Menu(int rows, int** G){
	int menu;
	int f = 0;

	while(f != 1){
	printf("������� ��� ����� ����������� ����������:\n");
	printf("1.���������\n");
	printf("2.������\n");

		scanf("%d", &menu);
			if(menu > 2 || menu < 1){
				f = 0;
				printf("���������� ��� ���\n");
				}
			else
				f = 1;
		}
			switch(menu){
			case 1: 
				RandomInput(rows, G);//��������� ���������� �������
				break;
			case 2: 
				ManualInput(rows, G);//������ ���� 
				break;
		}
	}
void OutputMatrix(int rows, int** G){
	//����� �������
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
	//����� �������
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