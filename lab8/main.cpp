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

int main()
{
    //static

    List staticList;

    staticList.load("staticList.txt");
    staticList.show();
    getch();

    staticList.sort();
    staticList.show();
    getch();

    staticList.save("staticListSort.txt");

    staticList.load("staticList.txt");
    staticList.show();
    getch();

    //dynamic

    List *dynamicList;
    dynamicList = new List();

    dynamicList->load("dynamicList.txt");
    dynamicList->show();
    getch();

    dynamicList->sort();
    dynamicList->show();
    getch();

    dynamicList->save("dynamicListSort.txt");

    dynamicList->load("dynamicList.txt");
    dynamicList->show();
    getch();

    delete dynamicList;

    getch();
    return 0;
}
