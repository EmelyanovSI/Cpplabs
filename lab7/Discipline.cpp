#include <stdio.h>
#include <string.h>
#include "Discipline.h"

//����������� ��� ����������, ��������� ���������� ������� ������
Discipline::Discipline()
{
    name[0] = '\0';
    hours = 0;
    course = 0;
}

//�����������, ���������������� ��� ���������� ������ ����������
Discipline::Discipline(char *n, int h, int c)
{
    strcpy(name, n);
    hours = h;
    course = c;
}

//����������� �����������
Discipline::Discipline(Discipline &d)
{
    strcpy(name, d.name);
    hours = d.hours;
    course = d.course;
}

//����������� ���������� �� ������ ��������, ���������� ������������ �������
Discipline::Discipline(char *n)
{
    strcpy(name, n);
    hours = 0;
    course = 0;
}

Discipline::Discipline(char *n, Discipline *y, Discipline x)
{
    if (strcmp(x.name, n) == 0) {
        strcpy(name, x.name);
        hours = x.hours;
        course = x.course;
    }
    else if (strcmp(y->name, n) == 0) {
        strcpy(name, y->name);
        hours = y->hours;
        course = y->course;
    }
    else {
        strcpy(name, n);
        hours = 0;
        course = 0;
    }
}

void Discipline::operator += (Discipline &discipline)
{
    hours += discipline.getHours();
    course += discipline.getCourse();
}

void Discipline::setName(char *n)
{
    strcpy(name, n);
}

void Discipline::setHours(int n)
{
    hours = n;
}

void Discipline::setCourse(int n)
{
    course = n;
}

char *Discipline::getName()
{
    return name;
}

int Discipline::getHours()
{
    return hours;
}

int Discipline::getCourse()
{
    return course;
}

void Discipline::input()
{
    printf("\nobj data input:\n");
    printf("Name?: ");
    gets(name);
    printf("Hours?: ");
    scanf("%d", &hours);
    printf("Course?: ");
    scanf("%d", &course);
    fflush(stdin);
}

void Discipline::output()
{
    printf("\nobj data output:\n");
    printf("Name: %s\n", name);
    printf("Hours: %d\n", hours);
    printf("Course: %d\n", course);
}

char *Discipline::getKey()
{
    sprintf(keyWord, "%c%s", key, name);
    return keyWord;
}

Discipline *Discipline::save(FILE *file)
{
	fprintf(file, "%s %d %d ", name, hours, course);
	return this;
}

Discipline *Discipline::load(FILE *file)
{
    fscanf(file, "%s %d %d ", name, &hours, &course);
    return this;
}
