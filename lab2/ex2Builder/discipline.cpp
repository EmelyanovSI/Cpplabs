#include "discipline.h"
#include <stdio.h>
#include <string.h>

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

int discipline::getCourse(){
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

int discipline::find(discipline *mas, int n)
{
   for(int i = 0; i < n; i++){
       if(strcmp(mas[i].getName(), name) == 0)
           return i;
   }
   return -1;
}
