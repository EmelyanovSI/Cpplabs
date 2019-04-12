#include <stdio.h>
#include <string.h>
#include "grade.h"

grade::grade():discipline()
{
    student[0] = '\0';
    value = 0;
}

grade::grade(char *n, int h, int c, char *s, int v):discipline(n, h, c)
{
    strcpy(student, s);
    value = v;
}

grade::grade(discipline *d, char *c, int n):discipline(*d)
{
    strcpy(student, c);
    value = n;
}

int grade::setChar(char a)
{

    int number = discipline::setChar(a);
    int studentLen = strlen(student);
    student[studentLen] = a;
    student[++studentLen] = '\0';
    for(int i = 0; i < studentLen; i++)
        if(student[i] == a)
            number++;
    return number;
}

char *grade::getStudent()
{
    return student;
}

void grade::setStudent(char *s)
{
    strcpy(student, s);
}

int grade::getValue()
{
    return value;
}

void grade::setValue(int v)
{
    value = v;
}

void grade::input()
{
    discipline::input();
    printf("Student: ");
    gets(student);
    printf("Value: ");
    scanf("%d", &value);
    fflush(stdin);
}

void grade::output()
{
    discipline::output();
    printf("Student?: %s\n", student);
    printf("Value?: %d\n", value);
}
