///Emelyanov Variant-3 Lab-2 Exercise-2
/*
    ������� �� ����� �++ �����, ���������� ���������� �� ����� �� ������� ��������� ����:

    ��������� ����������.

    ������������ ����� �� ������������ ������ �2.1,
������ ��� ���������� � ����� ������ �������� (private) � ������� � ����� ��������� ������:
1)	��������� �������� ��������� ���������� ������ (��������� ������ ��� ������ ����������);
2)	��������� �������� ��������� ���������� ������ (��������� ������ ��� ������ ����������);
3)	����������� �� ������ ����������� ������� ������ (������� ����� � ������� ������� printf, puts);
4)	���������� ������� ������ � ���������� (������� ���� � ������� ������� scanf, gets).
*/

#include <stdio.h>
#include <conio.h>
#include "discipline.h"

int main()
{
    discipline staticObject;

    staticObject.setName("Math");
    staticObject.setHours(32);
    staticObject.setCourse(2);

    printf("\nstaticObject.getName(): %s", staticObject.getName());
    printf("\nstaticObject.getHours(): %d", staticObject.getHours());
    printf("\nstaticObject.getCourse(): %d", staticObject.getCourse());

    staticObject.input();
    staticObject.output();

    discipline *dynamicObject;
    dynamicObject = new discipline();

    dynamicObject->setName("Math");
    dynamicObject->setHours(32);
    dynamicObject->setCourse(2);

    printf("\ndynamicObject.getName(): %s", dynamicObject->getName());
    printf("\ndynamicObject.getHours(): %d", dynamicObject->getHours());
    printf("\ndynamicObject.getCourse(): %d", dynamicObject->getCourse());

    dynamicObject->input();
    dynamicObject->output();

	getch();
	return 0;
}
