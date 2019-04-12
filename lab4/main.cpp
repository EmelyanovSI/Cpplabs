///Emelyanov Option-3 Lab-4
/*
������� �� ����� �++ �����:
	������ �������� �� ��������� ����������;

���������� ������ ������ ���� ��������� � ������� ������������� �� ������ �� ������������ ������ �2.3.
��� ���������� � ����� ���������������� ������ ������ ���� �������� (private).
�����-��������� ������ ��������� �� ����� ���� ����� � ����������� ����� ����������� ���������� ����.
������������� ����� ������ ��������� ��������� ������:
1)	������������ ��������� �����:
-	����������� ��� ����������, ��������� ���������� ������� ������;
-	�����������, ���������������� ��� ���������� ������ ����������, ��������� � �������� ����������,
        ������������� ����� ������ ������������� � ������� ������������ �������� ������;
2)	���������� (��� �������������);
3)	��������� �������� ��������� ���������� ������ (��������� ������ ��� ������ ����������);
4)	��������� �������� ��������� ���������� ������ (��������� ������ ��� ������ ����������);
5)	����������� �� ������ ����������� ������� ������ (������� ����� � ������� ������� printf, puts);
6)	���������� ������� ������ � ���������� (������� ���� � ������� ������� scanf, gets).
*/

#include <stdio.h>
#include <conio.h>
#include "grade.h"

int main()
{
    //static

    grade staticObject1;

    staticObject1.setStudent("Emelyanov");
    staticObject1.setValue(10);
    printf("\nStudent: %s", staticObject1.getStudent());
    printf("\nValue: %d", staticObject1.getValue());

    staticObject1.input();
    staticObject1.output();

    grade staticObject2("Math", 32, 2, "Ivanov", 10);

    staticObject2.output();

    //dynamic

    grade *dynamicObject1;
    dynamicObject1 = new grade();

    dynamicObject1->setStudent("Lukashenko");
    dynamicObject1->setValue(5);
    printf("\nStudent: %s", dynamicObject1->getStudent());
    printf("\nValue: %d", dynamicObject1->getValue());

    dynamicObject1->input();
    dynamicObject1->output();

    grade *dynamicObject2;
    dynamicObject2 = new grade("Lang", 30, 1, "Putin", 5);

    dynamicObject2->output();

    delete dynamicObject1;
    delete dynamicObject2;

    getch();
    return 0;
}
