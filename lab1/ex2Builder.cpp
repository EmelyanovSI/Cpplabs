///Emelyanov Variant-21 Lab-1 Exercise-2
/*
    Разработать программу на языке С, которая состоит из функции main(),
выполняющей ввод исходных данных и вывод результата,
и функции, реализующей заданные действия и вызываемой из функции main().
    Все строки (и только строки) должны быть размещены динамически с помощью оператора new.
Для посимвольного доступа к элементам строки нельзя использовать операцию [ ] (например, s[i]).
    Разделителем слов в предложении считать только пробел. Все остальные символы считать частью слов предложения.
    Можно использовать функции для работы со строками.

    Дано слово. Удалить из него все цифры.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void func(char *s);

void func(char *s){
    int k;
    for(int i=0; *(s+i)!='\0'; i++)
    for(char c='0'; c-1!='9'; c++)
        if(*(s+i)==c){
            for(k=i+1; *(s+k-1)!='\0'; k++)
                *(s+k-1)=*(s+k);
            i--;
            break;
        }
    return;
}

int main()
{
    char *s;
    s = new char[255];
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

