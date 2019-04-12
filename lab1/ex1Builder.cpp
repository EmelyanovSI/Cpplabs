///Emelyanov Variant-21 Lab-1 Exercise-1
/*
    ����������� ��������� �� ����� �, ������� ������� �� ������� main(),
����������� ���� �������� ������ � ����� ����������, � �������, ����������� �������� �������� � ���������� �� ������� main().
    ��� ������� (� ������ �������) ������ ���� ��������� ����������� � ������� ��������� new.
��� ������� � ��������� ������� ������ ������������ �������� [ ] (��������, m[i]).

    ���� ����� ������� �[n][n].
�������� ��� �������� ������� �� ��������������� �� �����, � ����� �������� ������� ������ � ��������� ������� �������.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void func(int n, int **A, int *a);

void func(int n, int **A, int *a) {
    int buf;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        *(*(A+i)+j) = -*(*(A+i)+j);
    for(int i=0; i<n; i++){
        buf = *(*(A+i)+0);
        *(*(A+i)+0) = *(*(A+i)+n-1);
        *(*(A+i)+n-1) = buf;
    }
    *a = *(*(A+0)+0) + *(*(A+n-1)+0) + *(*(A+n-1)+n-1) + *(*(A+0)+n-1);
    return;
}

int main()
{
    int n, a;
    int **A;
    printf("\nInput n: ");
    scanf("%d", &n);
    A = new int *[n];
    for(int i=0; i<n; i++)
        *(A+i) = new int [n];

    printf("\nInput matrix: \n\n");
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        scanf("%d", *(A+i)+j);
    func(n, A, &a);
    printf("\nNew matrix: \n\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            printf("%d ", *(*(A+i)+j));
        printf("\n");
    }
    printf("\nSum: %d\n", a);

    for(int i=0; i<n; i++)
        delete [] *(A+i);
    delete [] A;
    getch();
    return 0;
}

