///Емельянов Сергей Вариант-3 Лаб-8
/*
Для базового класса (лабораторная работа №2.3),
класса-наследника (лабораторная работа №4) и
класса-коллекции (лабораторная работа №7) все методы, использующие операции ввода-вывода,
реализовать с использованием библиотеки потоков языка С++.
Требования к реализации:
1)	методы для ввода с клавиатуры и вывода на экран объектов базового и порожденного класса
    должны быть реализованы с использованием предопределенных потоков (cin, cout),
    с применением флагов форматирования и манипуляторов;
2)	при вводе с клавиатуры должен обеспечиваться контроль правильности длин символьных переменных объектов;
3)	должна контролироваться правильность выполнения операций открытия файловых потоков;
4)	должны быть перегружены операции левого и правого сдвига для потоков и объектов классов (базового и наследника).
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

int main()
{
    //static

    List staticList;

    staticList.load("staticList.txt");
    staticList.save("staticList.txt");
    staticList.show();
    getch();

    staticList.input(0);
    staticList.output(0);
    getch();

    //dynamic

    List *dynamicList;
    dynamicList = new List();

    dynamicList->load("dynamicList.txt");
    dynamicList->save("dynamicList.txt");
    dynamicList->show();
    getch();

    dynamicList->input(0);
    dynamicList->output(0);
    getch();

    delete dynamicList;

    getch();
    return 0;
}
