#include "discipline.h"
#include <stdio.h>
#include <string.h>

//����������� ��� ����������, ��������� ���������� ������� ������
discipline::discipline()
{
    strcpy(name, "\0");
    hours = 0;
    course = 0;
}

//�����������, ���������������� ��� ���������� ������ ����������, ��������� � �������� ����������
discipline::discipline(char *n, int h, int c)
{
    strcpy(name, n);
    hours = h;
    course = c;
}

//����������� �����������
discipline::discipline(discipline &d)
{
    strcpy(name, d.name);
    hours = d.hours;
    course = d.course;
}

//����������� ���������� �� ������ ��������, ���������� ������������ �������
discipline::discipline(char *n)
{
    strcpy(name, n);
    hours = 0;
    course = 0;
}

char *discipline::getName()
{
    return name;
}

void discipline::setName(char *n)
{
    strcpy(name, n);
}

int discipline::getHours()
{
    return hours;
}

void discipline::setHours(int n)
{
    hours = n;
}

int discipline::getCourse()
{
    return course;
}

void discipline::setCourse(int n)
{
    course = n;
}

void discipline::input()
{
    printf("\nobj data input:\n");
    printf("Name: ");
    gets(name);
    printf("Hours: ");
    scanf("%d", &hours);
    printf("Course: ");
    scanf("%d", &course);
    fflush(stdin);
}

void discipline::output()
{
    printf("\nobj data output:\n");
    printf("Name?: %s\n", name);
    printf("Hours?: %d\n", hours);
    printf("Course?: %d\n", course);
}
