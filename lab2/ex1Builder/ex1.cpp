///Emelyanov Option-3 Lab-2 Exercise-1
/*
    ������� �� ����� �++ �����, ���������� ���������� �� ����� �� ������� ��������� ����:

    ��������� ����������.

    � ������ �� ������ ���� �������. ��� ���������� � ����� ������ ������ ���� ��������� (public).
� ������ ������ ���� ��� ����������, ��� � �������� ����.
    � ������� main() ��������� ��������� ��������: ������� ������ ������, ������� ������ ������,
������� ������ �������� ������, ������� ������ �������� ������.
����� �������� ��� �������� �������� ��������� ���������� �� � ���������� � ����� �� �����.
*/

#include <stdio.h>
#include <conio.h>
#include "discipline.h"

using namespace std;

const int ARR_LEN = 2;

int main()
{
    discipline obj1;

    printf("\nInput obj1 data: \n");
    printf("Name?: ");
    scanf("%s", &obj1.name);
    printf("Hours?: ");
    scanf("%d", &obj1.hours);
    printf("Course?: ");
    scanf("%d", &obj1.course);
    fflush(stdin);

    printf("\nOutput obj1 data: ");
    printf("\nname: %s", obj1.name);
    printf("\nhours: %d", obj1.hours);
    printf("\nCourse: %d", obj1.course);
    printf("\n");

    discipline *obj2;
    obj2 = new discipline;

    printf("\nInput obj2 data: \n");
    printf("Name?: ");
    scanf("%s", &obj2->name);
    printf("Hours?: ");
    scanf("%d", &obj2->hours);
    printf("Course?: ");
    scanf("%d", &obj2->course);
    fflush(stdin);

    printf("\nOutput obj2 data: ");
    printf("\nname: %s", obj2->name);
    printf("\nhours: %d", obj2->hours);
    printf("\nCourse: %d", obj2->course);
    printf("\n");

    discipline arr1[ARR_LEN];

    printf("\nInput arr1 data: \n");
    for(int i=0;i<ARR_LEN;i++){
        printf("Name?: ");
        scanf("%s", &arr1[i].name);
        printf("Hours?: ");
        scanf("%d", &arr1[i].hours);
        printf("Course?: ");
        scanf("%d", &arr1[i].course);
        fflush(stdin);
    }

    printf("\nOutput arr1 data: ");
    for(int i=0;i<ARR_LEN;i++){
        printf("\n%d name: %s", i+1, arr1[i].name);
        printf("\n%d hours: %d", i+1, arr1[i].hours);
        printf("\n%d Course: %d", i+1, arr1[i].course);
        printf("\n");
    }
    printf("\n");

    int n;
    printf("\nInput n: ");
    scanf("%d", &n);
    discipline *arr2;
    arr2 = new discipline[n];

    printf("\nInput arr2 data: \n");
    for(int i=0;i<n;i++){
        printf("Name?: ");
        scanf("%s", &arr2[i].name);
        printf("Hours?: ");
        scanf("%d", &arr2[i].hours);
        printf("Course?: ");
        scanf("%d", &arr2[i].course);
        fflush(stdin);
    }

    int imax=0;
    for(int i=1;i<n;i++)
        if(arr2[i].course>arr2[imax].course)
            imax=i;
    printf("\n%s\n", arr2[imax].name);

    printf("\nOutput arr2 data: ");
    for(int i=0;i<ARR_LEN;i++){
        printf("\n%d name: %s", i+1, arr2[i].name);
        printf("\n%d hours: %d", i+1, arr2[i].hours);
        printf("\n%d Course: %d", i+1, arr2[i].course);
        printf("\n");
    }
    printf("\n");

    delete obj2;
    delete [] arr2;

    getch();
    return 0;
}

