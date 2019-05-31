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
#include <conio.h>

using namespace std;

int main()
{
    //Дан массив из N целых чисел
    int n, k, buf;
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    cout << endl;
    vector<int> arr;

    //Вводим элементы вектора
    cout << endl << "Input vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        arr.push_back(buf);
    }
    //Выводим элементы вектора
    cout << endl << "Output vector:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //Найти среднее арифметическое элементов массива, кратных числу k
    int sum = 0, m = 0, sr;
    for (int i = 0; i < n; i++)
        if (arr[i] % k == 0) {
            sum += arr[i];
            m++;
        }
    sr = sum / m;
    cout << endl << "Sr arifm: " << sr << endl;

    //Поменять знак у всех элементов массива между первым максимальным и последним максимальным элементами
    int max = arr.front(), max_i = 0, max_j = n - 1;
    for (int i = 0; i < n; i++)
        if (max < arr[i]) {
            max = arr[i];
            max_i = i;
        }
    for (int i = n - 1; i >= 0; i--)
        if (max == arr[i]) {
            max_j = i;
            break;
        }
    for (int i = max_i + 1; i < max_j; i++)
        arr[i] = -arr[i];

    //Выводим элементы вектора
    cout << endl << "Output vector with -:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //Если первый отрицательный элемент имеет четный индекс,
    //то поменять местами части массива относительно этого элемента.
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            if (i % 2 == 0) {
                vector<int> part1, part2;
                part1.insert(part1.begin(), arr.begin(), arr.begin() + i);
                part2.insert(part2.begin(), arr.begin() + i + 1, arr.end());
                buf = arr[i];
                arr.insert(arr.begin(), part2.begin(), part2.end());
                arr.insert(arr.begin() + part2.size(), buf);
                arr.insert(arr.begin() + part2.size() + 1, part1.begin(), part1.end());
                break;
            }
            else
                break;

    //Выводим элементы вектора
    cout << endl << "Output vector after insert:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //Удалить из массива нулевые элементы
    for (int i = 0; i < n; i++)
        if (arr.at(i) == 0) {
            arr.erase(arr.begin() + i);
            n--;
            i--;
        }

    //Выводим элементы вектора
    cout << endl << "Output vector without 0:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //Отсортировать первую половину массива по возрастанию
    for (int i = 0; i < n / 2 - 1; i++)
        for (int j = i + 1; j < n / 2; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);

    //Выводим элементы вектора
    cout << endl << "Output vector after sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    getch();
    return 0;
}
