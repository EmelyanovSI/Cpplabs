///Emelyanov SI V21 L1 N2
/*
    ����������� ��������� �� ����� �, ������� ������� �� ������� main(),
����������� ���� �������� ������ � ����� ����������,
� �������, ����������� �������� �������� � ���������� �� ������� main().
    ��� ������ (� ������ ������) ������ ���� ��������� ����������� � ������� ��������� new.
��� ������������� ������� � ��������� ������ ������ ������������ �������� [ ] (��������, s[i]).
    ������������ ���� � ����������� ������� ������ ������. ��� ��������� ������� ������� ������ ���� �����������.
    ����� ������������ ������� ��� ������ �� ��������.

    ���� �����. ������� �� ���� ��� �����.
*/

#include <stdio.h>
#include <stdlib.h>

int func(char *s);

int func(char *s) {
    char num[] = "0123456789";
    int len, number;
    for(len=0; *(s+len)!='\0'; len++)
        if(*(s+len)==' ')
            return 1;
    if(len==0)
        return 2;
    for(int i=0; i<len; i++)
    for(int j=0; j<10; j++)
        if(*(s+i)==*(num+j)){
            for(int k=i+1; k<len+1; k++)
                *(s+k-1)=*(s+k);
            len--;
            i--;
            break;
        }
    if(len==0)
        return 3;
    return 0;
}

int main()
{
    int err;
    char *s;
    s = new char[255];
    printf("\nInput word: ");
    gets(s);
    err = func(s);
    if(err==1) ///switch
        printf("\nSpace found.\n");
    else if(err==2)
        printf("\nEnter found.\n");
    else if(err==3)
        printf("\nJust numbers found.\n");
    else{
        printf("\nNew word: ");
        puts(s);
    }
	return 0;
}
