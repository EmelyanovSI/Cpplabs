///Emelyanov Option-3 Lab-2 Exercise-1
/*
    Описать на языке С++ класс, содержащий информацию об одном из понятий реального мира:

    Изучаемая дисциплина.

    В классе не должно быть методов. Все переменные – члены класса должны быть открытыми (public).
В классе должны быть как символьные, так и числовые поля.
    В функции main() выполнить следующие действия: описать объект класса, создать объект класса,
описать массив объектов класса, создать массив объектов класса.
После описания или создания объектов выполнить заполнение их с клавиатуры и вывод на экран.
*/

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "discipline.h"

using namespace std;

const int ARR_LEN = 2;

int main()
{
    discipline obj1;
    discipline *obj2;
    obj2 = new discipline;

    discipline arr1[ARR_LEN];
    discipline *arr2;
    arr2 = new discipline[ARR_LEN];

    printf("\nInput obj1 data: \n");
    printf("Name?: ");
    scanf("%s", &obj1.name);
    printf("Hours?: ");
    scanf("%d", &obj1.hours);
    printf("Audience?: ");
    scanf("%s", &obj1.audience);
    fflush(stdin);

    printf("\nInput obj2 data: \n");
    printf("Name?: ");
    scanf("%s", &obj2->name);
    printf("Hours?: ");
    scanf("%d", &obj2->hours);
    printf("Audience?: ");
    scanf("%s", &obj2->audience);
    fflush(stdin);

    printf("\nInput arr1 data: \n");
    for(int i=0;i<ARR_LEN;i++){
        printf("Name?: ");
        scanf("%s", &arr1[i].name);
        printf("Hours?: ");
        scanf("%d", &arr1[i].hours);
        printf("Audience?: ");
        scanf("%s", &arr1[i].audience);
        fflush(stdin);
    }
    printf("\nInput arr2 data: \n");
    for(int i=0;i<ARR_LEN;i++){
        printf("Name?: ");
        scanf("%s", &arr2[i].name);
        printf("Hours?: ");
        scanf("%d", &arr2[i].hours);
        printf("Audience?: ");
        scanf("%s", &arr2[i].audience);
        fflush(stdin);
    }

    printf("\n******************\n");

    printf("\nOutput obj1 data: ");
    printf("\nname: %s", obj1.name);
    printf("\nhours: %d", obj1.hours);
	printf("\naudience: %s", obj1.audience);
	printf("\n");
	printf("\nOutput obj1 data: ");
    printf("\nname: %s", obj2->name);
    printf("\nhours: %d", obj2->hours);
	printf("\naudience: %s", obj2->audience);
	printf("\n");
	printf("\nOutput arr1 data: ");
	for(int i=0;i<ARR_LEN;i++){
        printf("\n%d name: %s", i+1, arr1[i].name);
        printf("\n%d hours: %d", i+1, arr1[i].hours);
        printf("\n%d audience: %s", i+1, arr1[i].audience);
        printf("\n");
	}
	printf("\nOutput arr2 data: ");
	for(int i=0;i<ARR_LEN;i++){
        printf("\n%d name: %s", i+1, arr2[i].name);
        printf("\n%d hours: %d", i+1, arr2[i].hours);
        printf("\n%d audience: %s", i+1, arr2[i].audience);
        printf("\n");
	}

	delete obj2;
    delete [] arr2;

	getch();
	return 0;
}
