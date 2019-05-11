///��������� ������ �������-3 ���-6
/*
��� ������, �������������� � ���� ���������� ������������ ������ �5, ���������� (�����������) ��������� ���������:
������_��_��������� += ���������_��_������; // �������� ������ � ���������
������_��_��������� += ������_��_������;    // ������� ����� ������� � �������� ����� ������� � ���������
������_��_��������� -= int;                 // ������� ������ �� ��������� �� ������
������_��_��������� -= char *;              // ������� ������ �� ��������� �� ������������
������_��_���������[int]                    // �������� ��������� �� ������ �� ������
������_��_���������[char *]                 // �������� ��������� �� ������ �� ������������
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

int main()
{
    Discipline d("one", 2, 3);

    //static

    List staticList;

    staticList.addToList(new Discipline("Math", 32, 2));
    staticList.addToList(new Discipline("Lang", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("NET", 32, 2));

    staticList += new Discipline("Math", 32, 2);
    staticList += d;
    staticList -= 0;
    staticList -= "OOP";
    staticList.show();
    staticList[0]->output();
    staticList["NET"]->output();

    //dynamic

    List *dynamicList;
    dynamicList = new List();

    dynamicList->addToList(new Discipline("Math", 64, 4));
    dynamicList->addToList(new Discipline("Lang", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("NET", 64, 4));

    *dynamicList += (new Discipline("Math", 64, 4));
    *dynamicList += d;
    *dynamicList -= 0;
    *dynamicList -= "OOP";
    dynamicList->show();
    (*dynamicList)[0]->output();
    (*dynamicList)["NET"]->output();

    delete dynamicList;

    getch();
    return 0;
}
