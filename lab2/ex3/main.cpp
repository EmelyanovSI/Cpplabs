///Emelyanov Variant-3 Lab-2 Exercise-3
/*
    Описать на языке С++ класс, содержащий информацию об одном из понятий реального мира:

    Изучаемая дисциплина.

Доработать класс из лабораторной работы №2.2, добавив в класс следующие методы:
1)	конструкторы следующих видов:
-	конструктор без параметров, очищающий переменные объекта класса;
-	конструктор, инициализирующий все переменные класса значениями, заданными в качестве параметров;
-	конструктор копирования;
-	конструктор приведения из строки символов, содержащей наименование объекта.
    Остальные переменные должны быть очищены конструктором;
2)	деструктор (при необходимости).

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

    staticObject1.setName("Math");
    staticObject1.setHours(32);
    staticObject1.setCourse(2);

    printf("\nstaticObject.getName(): %s", staticObject1.getName());
    printf("\nstaticObject.getHours(): %d", staticObject1.getHours());
    printf("\nstaticObject.getCourse(): %d", staticObject1.getCourse());

    staticObject1.input();
    staticObject1.output();

    //dynamic

    discipline *dynamicObject1;
    dynamicObject1 = new discipline();
    discipline *dynamicObject2;
    dynamicObject2 = new discipline("Math", 32, 2);
    discipline *dynamicObject3;
    dynamicObject3 = new discipline(*dynamicObject2);
    discipline *dynamicObject4;
    dynamicObject4 = new discipline("Math");

    dynamicObject1->setName("Math");
    dynamicObject1->setHours(32);
    dynamicObject1->setCourse(2);

    printf("\ndynamicObject.getName(): %s", dynamicObject1->getName());
    printf("\ndynamicObject.getHours(): %d", dynamicObject1->getHours());
    printf("\ndynamicObject.getCourse(): %d", dynamicObject1->getCourse());

    dynamicObject1->input();
    dynamicObject1->output();

    delete dynamicObject1;
    delete dynamicObject2;
    delete dynamicObject3;
    delete dynamicObject4;

	getch();
	return 0;
}
