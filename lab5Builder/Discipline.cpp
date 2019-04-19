#include <stdio.h>
#include <string.h>
#include "Discipline.h"

//конструктор без параметров, очищающий переменные объекта класса
Discipline::Discipline()
{
    name[0] = '\0';
    hours = 0;
    course = 0;
}

//конструктор, инициализирующий все переменные класса значениями
Discipline::Discipline(char *n, int h, int c)
{
    strcpy(name, n);
    hours = h;
    course = c;
}

//конструктор копирования
Discipline::Discipline(Discipline &d)
{
    strcpy(name, d.name);
    hours = d.hours;
    course = d.course;
}

//конструктор приведения из строки символов, содержащей наименование объекта
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

char *Discipline::getName()
{
    return name;
}

void Discipline::setName(char *n)
{
    strcpy(name, n);
}

int Discipline::getHours()
{
    return hours;
}

void Discipline::setHours(int n)
{
    hours = n;
}

int Discipline::getCourse()
{
    return course;
}

void Discipline::setCourse(int n)
{
    course = n;
}

void Discipline::input()
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

void Discipline::output()
{
    printf("\nobj data output:\n");
    printf("Name?: %s\n", name);
    printf("Hours?: %d\n", hours);
    printf("Course?: %d\n", course);
}
