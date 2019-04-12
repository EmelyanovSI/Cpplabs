///Emelyanov SI V21 L1 N1
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

void func(int n, int **A);

void func(int n, int **A) {
    int buf;
    for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        *(*(A+i)+j) *= -1;
    for(int i=0; i<n; i++){
        buf = *(*(A+i)+0);
        *(*(A+i)+0) = *(*(A+i)+n-1);
        *(*(A+i)+n-1) = buf;
    }
    return;
}

int main()
{
    int n;
    int **A;
    do{
        printf("\nInput n: ");
        scanf("%d", &n);
        if(n<2)
            printf("\nInput error. Try again.\n");
    }while(n<2);
    A = new int *[n];
    for(int i=0; i<n; i++)
        *(A+i) = new int [n];
    printf("\nInput matrix: \n");
    for(int i=0; i<n; i++){
        printf("%d. ", i+1);
        for(int j=0; j<n; j++)
            scanf("%d", *(A+i)+j);
    }
    func(n, A);
    printf("\nNew matrix: \n");
    for(int i=0; i<n; i++){
        printf("%d. ", i+1);
        for(int j=0; j<n; j++)
            printf("%d ", *(*(A+i)+j));
        printf("\n");
    }
    for(int i=0; i<n; i++)
		delete [] *(A+i);
	delete [] A;
	return 0;
}
