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
