///Емельянов Сергей Вариант-3 Лаб-6
/*
Для класса, разработанного в ходе выполнения лабораторной работы №5, определить (перегрузить) следующие операторы:
ссылка_на_коллекцию += указатель_на_объект; // добавить объект в коллекцию
ссылка_на_коллекцию += ссылка_на_объект;    // создать копию объекта и добавить копию объекта в коллекцию
ссылка_на_коллекцию -= int;                 // удалить объект из коллекции по номеру
ссылка_на_коллекцию -= char *;              // удалить объект из коллекции по наименованию
ссылка_на_коллекцию[int]                    // получить указатель на объект по номеру
ссылка_на_коллекцию[char *]                 // получить указатель на объект по наименованию
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

int main()
{
    //static

    // staticList
    List staticObject;

    staticObject.addToList(new Discipline("Math", 32, 2));
    staticObject.addToList(new Discipline("Lang", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("OOP", 32, 2));
    staticObject.addToList(new Discipline("NET", 32, 2));

    staticObject += new Discipline("Math", 32, 2);
    staticObject += *(new Discipline("Lang", 32, 2));
    staticObject -= 0;
    staticObject -= "OOP";
    staticObject.show();
    staticObject[0]->output();
    staticObject[1]->output();

    //dynamic

    // dynamicList
    List *dynamicObject;
    dynamicObject = new List();

    dynamicObject->addToList(new Discipline("Math", 64, 4));
    dynamicObject->addToList(new Discipline("Lang", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("OOP", 64, 4));
    dynamicObject->addToList(new Discipline("NET", 64, 4));

    *dynamicObject += (new Discipline("Math", 32, 2));
    *dynamicObject += *(new Discipline("Lang", 32, 2));
    *dynamicObject -= 0;
    *dynamicObject -= "OOP";
    dynamicObject->show();
    (*dynamicObject)[0]->output();
    (*dynamicObject)[1]->output();

    delete dynamicObject;

    getch();
    return 0;
}
