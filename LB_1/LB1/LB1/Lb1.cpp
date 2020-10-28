#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
void zadanie1(){
	printf("Задание 1\n");
	int x[10] = {1,2,3,4,5,6,7,8,9,10};
	int min = 10;
	int max = 0;

	for(int i = 0; i < 10; i++){
		printf("%d  ",x[i]);
	if(x[i]<min)
		min = x[i];
	if(x[i]>max)
		max = x[i];
	}

	printf("\n Разница между минимальным и максимальным = %d\n\n", max-min);

}
void zadanie2and4(){
	printf("Задание 2 и 4\n");
int mass[5][5];
int sum = 0;
for(int i = 0; i < 5; i++){
	for(int j = 0; j < 5; j++){
	mass[i][j] = rand()%100;
	}
}
for(int i = 0; i < 5; i++){
	sum = 0;
	for(int j = 0; j < 5; j++){
	printf("%d\t", mass[i][j]);
	sum+=mass[i][j];
	}
	printf("Сумма строки = %d \n",sum);
	}
printf("\n");
}
void zadanie3(){
	int *p;
	int n;

	printf("Задание 3\n");
	printf("Введите размер массива: ");
	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));

	for(int i  = 0; i < n; i++){
		printf("Введите %d элемент массива:", i);
		scanf_s("%d", &p[i]);
	}
	printf("\n Ваш массив - ");
	for(int i  = 0; i < n; i++){
		printf("%d  ", p[i]);
	}
}
void zadanie5(){

	char s[20];
	struct{
		char famil[20];
		char name [20];
		char facult[20];
		char nomer[5];
	}stud[3];

	printf("\nЗадание 5\n");

	for(int i = 0; i < 3; i++){
		printf("Введите фамилию:");
			scanf("%20s",stud[i].famil);
		printf("Введите имя:");
			scanf("%20s",stud[i].name);
		printf("Введите факультет:");
			scanf("%20s",stud[i].facult);
		printf("Введите номер зачет.книжки:");
			scanf("%s",stud[i].nomer);
		}
		printf("\n Список студентов:\n");
	for(int j = 0; j < 3; j++){
		printf("%s %s\t %s %s\n",stud[j].famil, stud[j].name, stud[j].facult, stud[j].nomer);
	}

	int check = 0;
	printf("Поиск/");
		scanf("%s", &s);
		for(int i = 0; i < 3; i++){
			if(strcmp(stud[i].famil, s) == 0 || strcmp(stud[i].name, s) == 0 || strcmp(stud[i].facult, s) == 0 || strcmp(stud[i].nomer, s) == 0){
				printf("НАЙДЕНО: %s %s %s %s\n", stud[i].famil, stud[i].name, stud[i].facult, stud[i].nomer);
				check++;
			}
		}
		if(check == 0)
			printf("Ничего не найдено");
}

int main(){
	setlocale(LC_ALL, "Rus");

	zadanie1();
	zadanie2and4();
	zadanie3();
	zadanie5();

	getch();
	return 0;
}