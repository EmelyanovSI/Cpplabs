///Емельянов Сергей Вариант-3 Лаб-4 В.А.
/*
Описать на языке С++ класс:
	оценка студента по изучаемой дисциплине;

Разработка класса должна быть выполнена с простым наследованием от класса из лабораторной работы №2.3.
Все переменные – члены разрабатываемого класса должны быть частными (private).
Класс-наследник должен содержать не менее двух полей и обязательно иметь собственное символьное поле.
Разработанный класс должен содержать следующие методы:
1)	конструкторы следующих видов:
-	конструктор без параметров, очищающий переменные объекта класса;
-	конструктор, инициализирующий все переменные класса значениями, заданными в качестве параметров,
        реализованный через список инициализации с вызовом конструктора базового класса;
2)	деструктор (при необходимости);
3)	установки значений отдельных переменных класса (отдельные методы для каждой переменной);
4)	получения значений отдельных переменных класса (отдельные методы для каждой переменной);
5)	отображения на экране содержимого объекта класса (обычный вывод с помощью функций printf, puts);
6)	заполнения объекта класса с клавиатуры (обычный ввод с помощью функций scanf, gets).
*/

#include <stdio.h>
#include <conio.h>
#include "grade.h"

int main()
{
    discipline *d = new discipline("Math", 32, 2);

    grade ggg(d, "Ivanov", 10);

    int k = ggg.setChar('a');
    printf("\nNumber: %d", k);
    printf("\nName: %s", ggg.getName());
    printf("\nName: %s", ggg.getStudent());
    printf("\n");

    //static

    grade staticObject1;

    staticObject1.setStudent("Emelyanov");
    staticObject1.setValue(10);
    printf("\nStudent: %s", staticObject1.getStudent());
    printf("\nValue: %d", staticObject1.getValue());


    staticObject1.input();
    staticObject1.output();

    grade staticObject2("Math", 32, 2, "Ivanov", 10);

    staticObject2.output();

    //dynamic

    grade *dynamicObject1;
    dynamicObject1 = new grade();

    dynamicObject1->setStudent("Lukashenko");
    dynamicObject1->setValue(5);
    printf("\nStudent: %s", dynamicObject1->getStudent());
    printf("\nValue: %d", dynamicObject1->getValue());

    dynamicObject1->input();
    dynamicObject1->output();

    grade *dynamicObject2;
    dynamicObject2 = new grade("Lang", 30, 1, "Putin", 5);

    dynamicObject2->output();

    delete dynamicObject1;
    delete dynamicObject2;

    getch();
    return 0;
}
