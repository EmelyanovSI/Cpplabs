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

    // staticList
    List staticObject;

    staticObject.addToList(new Discipline("Math", 32, 2));
    staticObject.addToList(new Discipline("Lang", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("NET", 32, 2));

    staticObject += new Discipline("Math", 32, 2);
    staticObject += *(new Discipline("Lang", 32, 2));
    staticObject -= 0;
    staticObject -= "OOP";
    staticObject.show();
    staticObject[0]->output();
    staticObject[1]->output();

    //dynamic

    // dynamicList
    List *dynamicObject;
    dynamicObject = new List();

    dynamicObject->addToList(new Discipline("Math", 64, 4));
    dynamicObject->addToList(new Discipline("Lang", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("NET", 64, 4));

    *dynamicObject += (new Discipline("Math", 32, 2));
    *dynamicObject += *(new Discipline("Lang", 32, 2));
    *dynamicObject -= 0;
    *dynamicObject -= "OOP";
    dynamicObject->show();
    (*dynamicObject)[0]->output();
    (*dynamicObject)[1]->output();

    delete dynamicObject;

    getch();
    return 0;
}
