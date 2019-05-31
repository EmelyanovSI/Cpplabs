///Емельянов Сергей Вариант-21 Лаб-10 Задача-2
/*
Реализовать обработку одномерного массива данных с использованием шаблонного класса vector библиотеки STL,
стремясь к максимальному использованию методов класса vector и алгоритмов библиотеки STL.

Дан массив из N целых чисел.
Найти среднее арифметическое элементов массива, кратных числу k.
Поменять знак у всех элементов массива между первым максимальным и последним максимальным элементами.
Если первый отрицательный элемент имеет четный индекс,
то поменять местами части массива относительно этого элемента.
Удалить из массива нулевые элементы. Отсортировать первую половину массива по возрастанию.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

void Sum (int &el);
void Output (int &el);
void Max_begin (int &el);
void Max_end (int &el);
void Minus (int &el);
void Swap (int &el);
void Delete (int &el);

void output (vector<int> arr);

//Дан массив из N целых чисел
vector<int> arr;
int n, k, buf, sum, fl;
int maxEl, max_begin = -1, max_end = -1;

void Sum (int &el) {
    if (el % k == 0) {
        sum += el;
        n++;
    }
}

void Output (int &el) {
    cout << el << endl;
}

void Max_begin (int &el) {
    if (maxEl == el && max_begin < 0)
        max_begin = n;
    n++;
}

void Max_end (int &el) {
    if (maxEl <= el) {
        maxEl = el;
        max_end = n;
    }
    n++;
}

void Minus (int &el) {
    el = -el;
}

void Swap (int &el) { //error
    if (el < 0 && n % 2 == 0 && fl == 0) {
        vector<int> part1, part2;
        part1.insert(part1.begin(), arr.begin(), arr.begin() + n);
        part2.insert(part2.begin(), arr.begin() + n + 1, arr.end());
        buf = el;
        arr.insert(arr.begin(), part2.begin(), part2.end());
        arr.insert(arr.begin() + part2.size(), buf);
        arr.insert(arr.begin() + part2.size() + 1, part1.begin(), part1.end());
        arr.erase(arr.end() - arr.size() / 2, arr.end());
        fl = 1;
    }
    else
        fl = 1;
    n++;
}

void Delete (int &el) { //error
    if (el == 0)
        arr.erase(arr.begin());
    n++;
}

void output (vector<int> arr) {
    for_each(arr.begin(), arr.end(), Output);
}

int main()
{
    /// 1 2 3 10 4 5 6 10 8 7

    //Дан массив из N целых чисел
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    cout << endl;

    //Вводим элементы вектора
    cout << endl << "Input vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        arr.push_back(buf);
    }

    //Выводим элементы вектора
    cout << endl << "Output vector:" << endl;
    output(arr);

    //Найти среднее арифметическое элементов массива, кратных числу k
    n = 0;
    for_each(arr.begin(), arr.end(), Sum);
    cout << endl << "Sr arifm: " << sum / n << endl;

    //Поменять знак у всех элементов массива между первым максимальным и последним максимальным элементами
    maxEl = arr.front();
    n = 0;
    for_each(arr.begin(), arr.end(), Max_end);
    n = 0;
    for_each(arr.begin(), arr.end(), Max_begin);

    for_each(arr.begin() + max_begin + 1, arr.begin() + max_end, Minus);

    //Выводим элементы вектора
    cout << endl << "Output vector with -:" << endl;
    output(arr);

    //Если первый отрицательный элемент имеет четный индекс,
    //то поменять местами части массива относительно этого элемента.
    fl = 0;
    n = 0;
    for_each(arr.begin(), arr.end(), Swap);

    //Выводим элементы вектора
    cout << endl << "Output vector after swap:" << endl;
    output(arr);

    //Удалить из массива нулевые элементы
    n = 0;
    for_each(arr.begin(), arr.end(), Delete);

    //Выводим элементы вектора
    cout << endl << "Output vector without 0:" << endl;
    output(arr);

    //Отсортировать первую половину массива по возрастанию
    for (vector<int>::iterator i = arr.begin(); i != arr.begin() + arr.size() / 2 - 1; i++)
        for (vector<int>::iterator j = i; j != arr.begin() + arr.size() / 2; j++)
            if (*i > *j)
                swap(*i, *j);

    //Выводим элементы вектора
    cout << endl << "Output vector after sorting:" << endl;
    output(arr);

    getch();
    return 0;
}
