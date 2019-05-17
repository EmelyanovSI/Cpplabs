///Емельянов Сергей Вариант-3 Лаб-9
/*
Разработать шаблон класса-коллекции, функционально идентичной коллекции из лабораторной работы №8.
На основе шаблона создать коллекцию объектов базового класса и коллекцию объектов производного класса.
Продемонстрировать работоспособность всех методов и перегруженных операторов коллекции.
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

template<typename Type>
Type mod(Type t) {
    return t >= 0 ? t : -t;
}

template<typename Type>
Type Max(Type *arr, int n) {
    Type max = arr[0];
    int m = 0;
    for (int i = 0; i < n; i++)
        if (mod(arr[i]) > max) {
            max = mod(arr[i]);
            m = i;
        }
    return arr[m];
}

int main()
{
    int arr[] = {-5, 1, 2, 7, -10};
    int k = Max(arr, 5);
    cout << "Max: " << k;
    getch();


    Discipline d("ten", 11, 12);
    Grade g("ten", 11, 12, "zero", 0);

    //static

    List<Discipline> staticDiscipline;
    List<Grade> staticGrade;

    ///staticDiscipline
    staticDiscipline.addToList(new Discipline("one", 2, 3));
    staticDiscipline.addToList(new Discipline("four", 5, 6));
    staticDiscipline.addToList(new Discipline("seven", 8, 9));
    staticDiscipline.show();
    getch();
    staticDiscipline.removeFromList(0);
    staticDiscipline.show();
    getch();
    cout << "Size: " << staticDiscipline.getSize() << endl;
    getch();
    staticDiscipline.getObject(0)->output();
    getch();
    staticDiscipline.swap(0, 1);
    staticDiscipline.show();
    getch();
    staticDiscipline.sort();
    staticDiscipline.show();
    getch();
    cout << "Number: " << staticDiscipline.find("seven") << endl;
    getch();
    staticDiscipline.input(0);
    staticDiscipline.output(0);
    getch();
    staticDiscipline.save("staticDiscipline.txt");
    staticDiscipline.load("staticDiscipline.txt");
    staticDiscipline.show();
    getch();
    staticDiscipline += staticDiscipline;
    staticDiscipline.show();
    getch();
    staticDiscipline += new Discipline("one", 2, 3);
    staticDiscipline.show();
    getch();
    staticDiscipline += d;
    staticDiscipline.show();
    getch();
    staticDiscipline -= "one";
    staticDiscipline.show();
    getch();
    staticDiscipline[0]->output();
    getch();
    staticDiscipline["ten"]->output();
    getch();
    staticDiscipline -= 0;
    staticDiscipline.show();
    getch();

    ///staticGrade
    staticGrade.addToList(new Grade("one", 2, 3, "zero", 0));
    staticGrade.addToList(new Grade("four", 5, 6, "zero", 0));
    staticGrade.addToList(new Grade("seven", 8, 9, "zero", 0));
    staticGrade.show();
    getch();
    staticGrade.removeFromList(0);
    staticGrade.show();
    getch();
    cout << "Size: " << staticGrade.getSize() << endl;
    getch();
    staticGrade.getObject(0)->output();
    getch();
    staticGrade.swap(0, 1);
    staticGrade.show();
    getch();
    staticGrade.sort();
    staticGrade.show();
    getch();
    cout << "Number: " << staticGrade.find("seven") << endl;
    getch();
    staticGrade.input(0);
    staticGrade.output(0);
    getch();
    staticGrade.save("staticGrade.txt");
    staticGrade.load("staticGrade.txt");
    staticGrade.show();
    getch();
    staticGrade += staticGrade;
    staticGrade.show();
    getch();
    staticGrade += new Grade("one", 2, 3, "zero", 0);
    staticGrade.show();
    getch();
    staticGrade += g;
    staticGrade.show();
    getch();
    staticGrade -= "one";
    staticGrade.show();
    getch();
    staticGrade[0]->output();
    getch();
    staticGrade["ten"]->output();
    getch();
    staticGrade -= 0;
    staticGrade.show();
    getch();

    //dynamic

    List<Discipline> *dynamicDiscipline;
    dynamicDiscipline = new List<Discipline>();
    List<Grade> *dynamicGrade;
    dynamicGrade = new List<Grade>();



    delete dynamicDiscipline;
    delete dynamicGrade;

    getch();
    return 0;
}
