///Emelyanov Variant-21 Lab-1 Exercise-2
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
#include <conio.h>

void func(char *s);

void func(char *s){
    int k=0;
    for(int i=0; *(s+i)!='\0'; i++)
        if(*(s+i)<'0' || *(s+i)>'9')
            *(s+k++) = *(s+i);
    *(s+k) = '\0';
    return;
}

int main()
{
    /* �������� ��� ����� �� ����� c */
    char m[11] = "0123456789";

    char *mm = m;
    while(*mm!='\0'){
        *mm = 'c';
        mm++;
    }
    printf("\n%s\n", m);

    char *s;
    s = new char[64];
    printf("\nInput word: ");
    gets(s);
    func(s);
    printf("\nNew word: ");
    puts(s);
    getch();
    return 0;
}

    /*char num[] = "0123456789";
    int len;
    for(len=0; *(s+len)!='\0'; len++){}
    for(int i=0; i<len; i++)
    for(int j=0; j<10; j++)
        if(*(s+i)==*(num+j)){
            for(int k=i+1; k<len+1; k++)
                *(s+k-1)=*(s+k);
            len--;
            i--;
            break;
        }
    delete [] num;
    return;*/

    /*int len;
    for(len=0; *(s+len)!='\0'; len++){}
    for(int i=0; i<len; i++)
    for(int j=0; j<10; j++)
        if(*(s+i)-'0'==j){
            for(int k=i+1; k<len+1; k++)
                *(s+k-1)=*(s+k);
            len--;
            i--;
            break;
        }
    return;*/

    /*int k;
    for(int i=0; *(s+i)!='\0'; i++)
    for(char c='0'; c-1!='9'; c++)
        if(*(s+i)==c){
            for(k=i+1; *(s+k)!='\0'; k++)
                *(s+k-1)=*(s+k);
            *(s+k-1)=*(s+k);
            i--;
            break;
        }
    return;*/

    /*int k;
    for(int i=0; *(s+i)!='\0'; i++)
    for(char c='0'; c-1!='9'; c++)
        if(*(s+i)==c){
            for(k=i+1; *(s+k - 1)!='\0'; k++)
                *(s+k-1)=*(s+k);
            i--;
            break;
        }
    return;*/

    /*int k;
    for(int i=0; *(s+i)!='\0'; i++){
        for(char c='0'; c-1!='9'; c++){
            if(*(s+i)==c){
                for(k=i+1; *(s+k-1)!='\0'; k++)
                    *(s+k-1)=*(s+k);
                i--;
                break;
            }
        }
    }
    return;*/
