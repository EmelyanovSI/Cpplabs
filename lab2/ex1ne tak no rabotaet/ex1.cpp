///Emelyanov Option-3 Lab-2 Exercise-1
/*
    Описать на языке С++ класс, содержащий информацию об одном из понятий реального мира:

    Изучаемая дисциплина.

    В классе не должно быть методов. Все переменные – члены класса должны быть открытыми (public).
В классе должны быть как символьные, так и числовые поля.
    В функции main() выполнить следующие действия: описать объект класса, создать объект класса,
описать массив объектов класса, создать массив объектов класса.
После описания или создания объектов выполнить заполнение их с клавиатуры и вывод на экран.
*/

#include <iostream>
#include <conio.h>
#include "discipline.h"

using namespace std;

const int ARR_LEN = 2;

int main()
{
    discipline obj1;
    discipline *obj2;
    obj2 = new discipline;

    discipline arr1[2];
    discipline *arr2[2];
    for(int i=0;i<2;i++)
        arr2[i] = new discipline;

    cout << endl << "Input obj1 data: " << endl;
    cout << "Name?: ";
    cin >> obj1.name;
    cout << "Hours?: ";
    cin >> obj1.hours;
	cout << "Audience?: ";
    cin >> obj1.audience;

    cout << endl << "Input obj2 data: " << endl;
    cout << "Name?: ";
    cin >> obj2->name;
    cout << "Hours?: ";
    cin >> obj2->hours;
	cout << "Audience?: ";
    cin >> obj2->audience;

    cout << endl << "Input arr1 data: " << endl;
    for(int i=0;i<2;i++){
        cout << i+1 << " Name?: ";
        cin >> arr1[i].name;
        cout << i+1 << " Hours?: ";
        cin >> arr1[i].hours;
        cout << i+1 << " Audience?: ";
        cin >> arr1[i].audience;
    }
    cout << endl << "Input arr2 data: " << endl;
    for(int i=0;i<2;i++){
        cout << i+1 << " Name?: ";
        cin >> arr2[i]->name;
        cout << i+1 << " Hours?: ";
        cin >> arr2[i]->hours;
        cout << i+1 << " Audience?: ";
        cin >> arr2[i]->audience;
    }
    cout << endl << "******************" << endl;
    cout << endl << "Output obj1 data: ";
    cout << endl << "name: " << obj1.name;
    cout << endl << "hours: " << obj1.hours;
	cout << endl << "audience: " << obj1.audience;
	cout << endl;
	cout << endl << "Output obj2 data: ";
    cout << endl << "name: " << obj2->name;
    cout << endl << "hours: " << obj2->hours;
	cout << endl << "audience: " << obj2->audience;
    cout << endl;
	cout << endl << "Output arr1 data: ";
	for(int i=0;i<2;i++){
        cout << endl << i+1 << " name: " << arr1[i].name;
        cout << endl << i+1 << " hours: " << arr1[i].hours;
        cout << endl << i+1 << " audience: " << arr1[i].audience;
        cout << endl;
	}
	cout << endl << "Output arr2 data: ";
	for(int i=0;i<2;i++){
        cout << endl << i+1 << " name: " << arr2[i]->name;
        cout << endl << i+1 << " hours: " << arr2[i]->hours;
        cout << endl << i+1 << " audience: " << arr2[i]->audience;
        cout << endl;
	}

	delete obj2;
    for(int i=0;i<2;i++)
        delete [] arr2[i];

	getch();
	return 0;
}
