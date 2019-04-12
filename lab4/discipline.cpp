#include <stdio.h>
#include <string.h>
#include "discipline.h"

//конструктор без параметров, очищающий переменные объекта класса
discipline::discipline()
{
    name[0] = '\0';
    hours = 0;
    course = 0;
}

//конструктор, инициализирующий все переменные класса значениями
discipline::discipline(char *n, int h, int c)
{
    strcpy(name, n);
    hours = h;
    course = c;
}

//конструктор копирования
discipline::discipline(discipline &d)
{
    strcpy(name, d.name);
    hours = d.hours;
    course = d.course;
}

//конструктор приведения из строки символов, содержащей наименование объекта
discipline::discipline(char *n)
{
    strcpy(name, n);
    hours = 0;
    course = 0;
}

discipline::discipline(char *n, discipline *y, discipline x)
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
