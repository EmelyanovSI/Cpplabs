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
    //static

    List staticList;

    // Builder
    Discipline obj1("one", 30, 3);
    Discipline obj2("two", 20, 2);
    obj1 += obj2;
    obj1.output();

    staticList.addToList(new Discipline("Math", 32, 2));
    staticList.addToList(new Discipline("Lang", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("NET", 32, 2));

    staticList += new Discipline("Math", 32, 2);
    staticList += obj1;
    staticList -= 0;
    staticList -= "OOP";
    staticList.show();
    staticList[0]->output();
    staticList["NET"]->output();

    // Builder collection += collection
    List obj3;
    obj3.addToList(new Discipline("NEW", 10, 1));
    staticList += obj3;
    obj3.removeFromList(0);
    staticList.show();

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
    *dynamicList += obj2;
    *dynamicList -= 0;
    *dynamicList -= "OOP";
    dynamicList->show();
    (*dynamicList)[0]->output();
    (*dynamicList)["NET"]->output();

    delete dynamicList;

    getch();
    return 0;
}
