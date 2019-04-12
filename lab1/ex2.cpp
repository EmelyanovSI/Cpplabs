///Emelyanov SI V21 L1 N2
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
