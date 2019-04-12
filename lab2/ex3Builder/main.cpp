///Emelyanov Variant-3 Lab-2 Exercise-3
/*
    ������� �� ����� �++ �����, ���������� ���������� �� ����� �� ������� ��������� ����:

    ��������� ����������.

���������� ����� �� ������������ ������ �2.2, ������� � ����� ��������� ������:
1)  ������������ ��������� �����:
-   ����������� ��� ����������, ��������� ���������� ������� ������;
-   �����������, ���������������� ��� ���������� ������ ����������, ��������� � �������� ����������;
-   ����������� �����������;
-   ����������� ���������� �� ������ ��������, ���������� ������������ �������.
    ��������� ���������� ������ ���� ������� �������������;
2)  ���������� (��� �������������).

*/

#include <stdio.h>
#include <conio.h>
#include "discipline.h"

int main()
{
    //static

    discipline staticObject1;
    discipline staticObject2("Math", 32, 2);
    discipline staticObject3(staticObject2);
    discipline staticObject4("Math");

    staticObject1.output();
    staticObject2.output();
    staticObject3.output();
    staticObject4.output();

    //dynamic

    discipline *dynamicObject1;
    dynamicObject1 = new discipline();
    discipline *dynamicObject2;
    dynamicObject2 = new discipline("Lang", 30, 1);
    discipline *dynamicObject3;
    dynamicObject3 = new discipline(*dynamicObject2);
    discipline *dynamicObject4;
    dynamicObject4 = new discipline("Lang");

    dynamicObject1->output();
    dynamicObject2->output();
    dynamicObject3->output();
    dynamicObject4->output();

    discipline a("OOP", dynamicObject2, staticObject2);

    a.output();

    delete dynamicObject1;
    delete dynamicObject2;
    delete dynamicObject3;
    delete dynamicObject4;

    getch();
    return 0;
}
