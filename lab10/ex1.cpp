///Емельянов Сергей Вариант-21 Лаб-10 Задача-1
/*
Реализовать обработку символьной информации с использованием класса string библиотеки STL,
стремясь к максимальному использованию методов класса string и алгоритмов библиотеки STL.

Дан массив слов.
Отсортировать массив слов по возрастанию длин слов, причем слова одной длины должны быть отсортированы по алфавиту.
Сформировать предложение из слов массива, преобразовав каждое слово длиной более 2 символов следующим образом:
буквы слова, стоящие до первой гласной (гласными считать латинские буквы ‘а’, ‘о’, ‘е’), перенести в конец слова.
*/

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int STR_LEN = 64;
    string *str = new string[STR_LEN];
    int len, n = 0;

    ifstream file;
    file.open("string.txt");
    if (file.is_open())
        while (!file.eof() && n < STR_LEN)
            file >> str[n++];
    file.close();
    len = n;

    cout << endl << "All words:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i].compare(str[j]) > 0)
                str[i].swap(str[j]);

    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i].length() > str[j].length())
                str[i].swap(str[j]);

    cout << endl << "All words after sorting:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    for (int i = 0; i < len; i++) {
        if (str[i].length() > 2) {

        }
    }

    delete str;
    getch();
    return 0;
}
