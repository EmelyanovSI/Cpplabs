///Емельянов Сергей Вариант-21 Лаб-10 Задача-3
/*
Реализовать коллекцию объектов класса, функционально идентичную коллекции, разработанной в лабораторной работе №5,
с использованием шаблонного класса list библиотеки STL.
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
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

    (*(staticObject.getObject(1)))->output();

    //Builder
    int k = staticObject.find("OOP");
    printf("\nFined: %d\n", k);
    k = -1;
    int size = staticObject.getLength();
    for (int i = 0; i < size; i++)
        if (strcmp((*(staticObject.getObject(i)))->getName(), "OOP") == 0)
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

    (*(dynamicObject->getObject(1)))->output();

    dynamicObject->swap(0, 2);
    dynamicObject->show();

    dynamicObject->sort();
    dynamicObject->show();

    delete dynamicObject;

    getch();
    return 0;
}
