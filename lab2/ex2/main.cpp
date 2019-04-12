///Emelyanov Variant-3 Lab-2 Exercise-2
/*
    Описать на языке С++ класс, содержащий информацию об одном из понятий реального мира:

    Изучаемая дисциплина.

    Переработать класс из лабораторной работы №2.1,
сделав все переменные – члены класса частными (private) и добавив в класс следующие методы:
1)	установки значений отдельных переменных класса (отдельные методы для каждой переменной);
2)	получения значений отдельных переменных класса (отдельные методы для каждой переменной);
3)	отображения на экране содержимого объекта класса (обычный вывод с помощью функций printf, puts);
4)	заполнения объекта класса с клавиатуры (обычный ввод с помощью функций scanf, gets).
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
