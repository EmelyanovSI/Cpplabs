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

    List staticList;

    // Builder
    Discipline obj1("one", 30, 3);
    Discipline obj2("two", 20, 2);
    obj1 += obj2;
    obj1.output();

    staticList.addToList(new Discipline("Math", 32, 2));
    staticList.addToList(new Discipline("Lang", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("OOP", 32, 2));
    staticList.addToList(new Discipline("NET", 32, 2));

    staticList += new Discipline("Math", 32, 2);
    staticList += obj1;
    staticList -= 0;
    staticList -= "OOP";
    staticList.show();
    staticList[0]->output();
    staticList["NET"]->output();

    // Builder collection += collection
    List obj3;
    obj3.addToList(new Discipline("NEW", 10, 1));
    staticList += obj3;
    obj3.removeFromList(0);
    staticList.show();

    //dynamic

    List *dynamicList;
    dynamicList = new List();

    dynamicList->addToList(new Discipline("Math", 64, 4));
    dynamicList->addToList(new Discipline("Lang", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("OOP", 64, 4));
    dynamicList->addToList(new Discipline("NET", 64, 4));

    *dynamicList += (new Discipline("Math", 64, 4));
    *dynamicList += obj2;
    *dynamicList -= 0;
    *dynamicList -= "OOP";
    dynamicList->show();
    (*dynamicList)[0]->output();
    (*dynamicList)["NET"]->output();

    delete dynamicList;

    getch();
    return 0;
}
