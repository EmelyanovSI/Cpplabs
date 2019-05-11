#include <stdio.h>
#include <string.h>
#include "Grade.h"

Grade::Grade():Discipline()
{
    student[0] = '\0';
    value = 0;
}

Grade::Grade(char *n, int h, int c, char *s, int v):Discipline(n, h, c)
{
    strcpy(student, s);
    value = v;
}

void Grade::setStudent(char *s)
{
    strcpy(student, s);
}

void Grade::setValue(int v)
{
    value = v;
}

char *Grade::getStudent()
{
    return student;
}

int Grade::getValue()
{
    return value;
}

void Grade::input()
{
    Discipline::input();
    printf("Student?: ");
    gets(student);
    printf("Value?: ");
    scanf("%d", &value);
    fflush(stdin);
}

void Grade::output()
{
    Discipline::output();
    printf("Student: %s\n", student);
    printf("Value: %d\n", value);
}

char *Grade::getKey()
{
    sprintf(keyWord, "%c%s", key, student);
    return keyWord;
}

void Grade::save(FILE *file)
{
    Discipline::save(file);
    fprintf(file, "%s %d ", student, value);
}

void Grade::load(FILE *file)
{
    Discipline::load(file);
    fscanf(file, "%s %d ", student, &value);
}

Grade *Grade::copy()
{
    return new Grade(*this);
}
