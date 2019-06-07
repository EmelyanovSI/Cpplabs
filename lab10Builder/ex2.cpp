///��������� ������ �������-21 ���-10 ������-2
/*
����������� ��������� ����������� ������� ������ � �������������� ���������� ������ vector ���������� STL,
�������� � ������������� ������������� ������� ������ vector � ���������� ���������� STL.

��� ������ �� N ����� �����.
����� ������� �������������� ��������� �������, ������� ����� k.
�������� ���� � ���� ��������� ������� ����� ������ ������������ � ��������� ������������ ����������.
���� ������ ������������� ������� ����� ������ ������,
�� �������� ������� ����� ������� ������������ ����� ��������.
������� �� ������� ������� ��������. ������������� ������ �������� ������� �� �����������.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

void Sum (int &el);
void Output (int &el);
void Max_end (int &el);
int Minus (int el);
void Swap (int &el);
void Delete (int &el);

void output (vector<int> arr);

//��� ������ �� N ����� �����
vector<int> arr;
int n, k, buf, sum, fl;
int maxEl, max_end = -1;

void Sum (int &el) {
    if (el % k == 0) {
        sum += el;
        n++;
    }
}

void Output (int &el) {
    cout << el << endl;
}

void Max_end (int &el) {
    if (maxEl <= el) {
        maxEl = el;
        max_end = n;
    }
    n++;
}

int Minus (int el) {
    return -el;
}

void Swap (int &el) {
    if (el < 0 && fl == 0) {
        if (n % 2 == 0) {
            vector<int> part1, part2;
            int len = arr.size();
            part1.insert(part1.begin(), arr.begin(), arr.begin() + n);
            part2.insert(part2.begin(), arr.begin() + n + 1, arr.end());
            buf = el;
            arr.insert(arr.begin(), part2.begin(), part2.end());
            arr.insert(arr.begin() + part2.size(), buf);
            arr.insert(arr.begin() + part2.size() + 1, part1.begin(), part1.end());
            arr.erase(arr.begin() + len, arr.end());
            fl = 1;
        }
        else
            fl = 1;
    }
    n++;
}

void Delete (int &el) {
    if (el == 0)
        arr.erase(arr.begin() + n);
    n++;
}

void output (vector<int> arr) {
    for_each(arr.begin(), arr.end(), Output);
}

int main()
{
    /// 1 2 3 10 4 5 6 10 8 7

    //��� ������ �� N ����� �����
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    cout << endl;

    //������ �������� �������
    cout << endl << "Input vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        arr.push_back(buf);
    }

    //������� �������� �������
    cout << endl << "Output vector:" << endl;
    output(arr);

    //����� ������� �������������� ��������� �������, ������� ����� k
    n = 0;
    for_each(arr.begin(), arr.end(), Sum);
    cout << endl << "Sr arifm: " << sum / n << endl;

    //�������� ���� � ���� ��������� ������� ����� ������ ������������ � ��������� ������������ ����������
    maxEl = arr.front();
    n = 0;
    for_each(arr.begin(), arr.end(), Max_end);
    vector<int>::iterator iter1 = find(arr.begin(), arr.begin() + max_end, maxEl) + 1;
    vector<int>::iterator iter2 = arr.begin() + max_end;
    transform(iter1, iter2, iter1, Minus);

    //������� �������� �������
    cout << endl << "Output vector with -:" << endl;
    output(arr);

    //���� ������ ������������� ������� ����� ������ ������,
    //�� �������� ������� ����� ������� ������������ ����� ��������.
    fl = 0;
    n = 0;
    for_each(arr.begin(), arr.end(), Swap);

    //������� �������� �������
    cout << endl << "Output vector after swap:" << endl;
    output(arr);

    //������� �� ������� ������� ��������
    n = 0;
    for_each(arr.begin(), arr.end(), Delete);

    //������� �������� �������
    cout << endl << "Output vector without 0:" << endl;
    output(arr);

    //������������� ������ �������� ������� �� �����������
    for (vector<int>::iterator i = arr.begin(); i != arr.begin() + arr.size() / 2 - 1; i++)
        for (vector<int>::iterator j = i; j != arr.begin() + arr.size() / 2; j++)
            if (*i > *j)
                swap(*i, *j);

    //������� �������� �������
    cout << endl << "Output vector after sorting:" << endl;
    output(arr);

    getch();
    return 0;
}
