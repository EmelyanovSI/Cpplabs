///��������� ������ �������-3 ���-8
/*
��� �������� ������ (������������ ������ �2.3),
������-���������� (������������ ������ �4) �
������-��������� (������������ ������ �7) ��� ������, ������������ �������� �����-������,
����������� � �������������� ���������� ������� ����� �++.
���������� � ����������:
1)	������ ��� ����� � ���������� � ������ �� ����� �������� �������� � ������������ ������
    ������ ���� ����������� � �������������� ���������������� ������� (cin, cout),
    � ����������� ������ �������������� � �������������;
2)	��� ����� � ���������� ������ �������������� �������� ������������ ���� ���������� ���������� ��������;
3)	������ ���������������� ������������ ���������� �������� �������� �������� �������;
4)	������ ���� ����������� �������� ������ � ������� ������ ��� ������� � �������� ������� (�������� � ����������).
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

istream &operator << (int &n, istream &in)
{
    do {
        cout << "Input: ";
        in >> n;
    } while(n < 0 || n > 100);
    return in;
}

ostream &operator >> (int &n, ostream &out)
{
    out << "Output: ";
    out << n;
    return out;
}

istream &operator >> (istream &in, List &l)
{
    int size = l.getSize();
    for (int i = 0; i < size; i++) {
         l.getObject(i)->input();
    }
    return in;
}

int main()
{
    int a;
    a << cin;
    a >> cout;
    getch();

    //static

    List staticList;

    staticList.load("staticList.txt");

    cin >> staticList;

    staticList.save("staticList.txt");
    staticList.show();
    getch();

    staticList.input(0);
    staticList.output(0);
    getch();

    //dynamic

    List *dynamicList;
    dynamicList = new List();

    dynamicList->load("dynamicList.txt");
    dynamicList->save("dynamicList.txt");
    dynamicList->show();
    getch();

    dynamicList->input(0);
    dynamicList->output(0);
    getch();

    delete dynamicList;

    getch();
    return 0;
}
