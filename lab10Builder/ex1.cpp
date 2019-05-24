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
#include <string>

using namespace std;

int main()
{
    //Дан массив слов.
    int len;
    cout << "Input kol words: ";
    cin >> len;
    string *str = new string[len];
    string sentence = "";
    string aoe = "aoe";
    int n, kol;

    //ввод массива слов
    for (int i = 0; i < len; i++)
        cin >> str[i];

    //вывод массива слов
    cout << endl << "All words:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    //Отсортировать массив слов по возрастанию длин слов, причем слова одной длины должны быть отсортированы по алфавиту.
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i].length() > str[j].length() || (str[i].length() == str[j].length() && str[i].compare(str[j]) > 0))
                str[i].swap(str[j]);

    //вывод массива слов после сортировки
    cout << endl << "All words after sorting:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    //Сформировать предложение из слов массива, преобразовав каждое слово длиной более 2 символов следующим образом:
    //буквы слова, стоящие до первой гласной (гласными считать латинские буквы ‘а’, ‘о’, ‘е’), перенести в конец слова.
    for (int i = 0; i < len; i++) {
        if (str[i].length() > 2) {
            kol = str[i].length();
            for (int j = 0; j < aoe.length(); j++) {
                n = str[i].find(aoe[j]);
                if (kol > n && n != -1)
                    kol = n;
            }
            if (kol >= 0 && kol <= str[i].length()) {
                for (int j = 0; j < kol; j++)
                    str[i].push_back(str[i][j]);
                str[i].erase(0, kol);
            }
        }
        sentence.append(str[i] + " ");
    }
    sentence.erase(sentence.length() - 1, 1);

    //вывод предложения
    cout << endl << "Sentence:" << endl;
    cout << sentence << endl;

    delete [] str;
    getch();
    return 0;
}
