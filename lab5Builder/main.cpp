///Емельянов Сергей Вариант-3 Лаб-5
/*
Описать на языке С++ класс, являющийся коллекцией объектов класса,
разработанного в ходе выполнения лабораторной работы №2.3.
Реализация коллекции должна вестись с использованием массива указателей на объекты класса,
разработанного в ходе выполнения лабораторной работы №2.3.

Разработанный класс должен содержать следующие методы:
1)	конструктор;
2)	деструктор, уничтожающий объекты коллекции;
3)	добавления объектов в коллекцию (параметр – указатель на объект);
4)	удаления объектов из коллекции по номеру;
5)	получения количества элементов в коллекции;
6)	получения указателя на объект коллекции по номеру объекта;
7)	перестановки местами двух объектов коллекции (параметры – номера объектов);
8)	сортировки объектов коллекции по наименованию;
9)	отображения на экране всех элементов коллекции.
*/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "List.h"

int main()
{
    //static

    List staticObject;

    staticObject.addToList(new Discipline("Math", 32, 2));
    staticObject.addToList(new Discipline("Lang", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("NET", 32, 2));
    staticObject.show();

    staticObject.removeFromList(1);
    staticObject.show();

    printf("\nKOL: %d\n", staticObject.getLength());

    staticObject.getObject(1)->output();

    //Builder
    int k = staticObject.find("OOP");
    printf("\nFined: %d\n", k);
    k = -1;
    int size = staticObject.getLength();
    for (int i = 0; i < size; i++)
        if (strcmp(staticObject.getObject(i)->getName(), "OOP") == 0)
            k = i;
    printf("\nFined: %d\n", k);

    staticObject.swap(0, 2);
    staticObject.show();

    staticObject.sort();
    staticObject.show();

    //dynamic

    List *dynamicObject;
    dynamicObject = new List();

    dynamicObject->addToList(new Discipline("Math", 64, 4));
    dynamicObject->addToList(new Discipline("Lang", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("NET", 64, 4));
    dynamicObject->show();

    dynamicObject->removeFromList(1);
    dynamicObject->show();

    printf("\nKOL: %d\n", dynamicObject->getLength());

    dynamicObject->getObject(1)->output();

    dynamicObject->swap(0, 2);
    dynamicObject->show();

    dynamicObject->sort();
    dynamicObject->show();

    delete dynamicObject;

    getch();
    return 0;
}
