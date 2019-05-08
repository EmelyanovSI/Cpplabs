///Емельянов Сергей Вариант-3 Лаб-9
/*
Разработать шаблон класса-коллекции, функционально идентичной коллекции из лабораторной работы №8.
На основе шаблона создать коллекцию объектов базового класса и коллекцию объектов производного класса.
Продемонстрировать работоспособность всех методов и перегруженных операторов коллекции.
*/

#include <stdio.h>
#include <conio.h>
#include "List.h"

int main()
{
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
    staticDiscipline.save("staticDisciplineSave.txt");
    staticDiscipline.load("staticDisciplineLoad.txt");
    staticDiscipline.show();
    getch();
    staticDiscipline += staticDiscipline;
    staticDiscipline.show();
    getch();
    staticDiscipline += new Discipline("one", 2, 3);
    staticDiscipline.show();
    getch();
    staticDiscipline += *(new Discipline("ten", 11, 12)); //ошибка и в 6й лабе тоже
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
    staticGrade.save("staticGradeSave.txt");
    staticGrade.load("staticGradeLoad.txt");
    staticGrade.show();
    getch();
    staticGrade += staticGrade;
    staticGrade.show();
    getch();
    staticGrade += new Grade("one", 2, 3, "zero", 0);
    staticGrade.show();
    getch();
    staticGrade += *(new Grade("ten", 11, 12, "zero", 0)); //ошибка и в 6й лабе тоже
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
