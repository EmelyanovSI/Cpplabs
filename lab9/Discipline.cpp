#include "Discipline.h"

//конструктор без параметров, очищающий переменные объекта класса
Discipline::Discipline()
{
    name[0] = '\0';
    hours = 0;
    course = 0;
}

//конструктор, инициализирующий все переменные класса значениями
Discipline::Discipline(char *n, int h, int c)
{
    strcpy(name, n);
    hours = h;
    course = c;
}

//конструктор копирования
Discipline::Discipline(Discipline &d)
{
    strcpy(name, d.name);
    hours = d.hours;
    course = d.course;
}

//конструктор приведения из строки символов, содержащей наименование объекта
Discipline::Discipline(char *n)
{
    strcpy(name, n);
    hours = 0;
    course = 0;
}

Discipline::Discipline(char *n, Discipline *y, Discipline x)
{
    if (strcmp(x.name, n) == 0) {
        strcpy(name, x.name);
        hours = x.hours;
        course = x.course;
    }
    else if (strcmp(y->name, n) == 0) {
        strcpy(name, y->name);
        hours = y->hours;
        course = y->course;
    }
    else {
        strcpy(name, n);
        hours = 0;
        course = 0;
    }
}

void Discipline::operator += (Discipline &discipline)
{
    hours += discipline.getHours();
    course += discipline.getCourse();
}

void Discipline::setName(char *n)
{
    strcpy(name, n);
}

void Discipline::setHours(int n)
{
    hours = n;
}

void Discipline::setCourse(int n)
{
    course = n;
}

char *Discipline::getName()
{
    return name;
}

int Discipline::getHours()
{
    return hours;
}

int Discipline::getCourse()
{
    return course;
}

void Discipline::input()
{
    cin >> *this;
}

void Discipline::output()
{
    cout << *this;
}

char *Discipline::getKey()
{
    sprintf(keyWord, "%c%s", key, name);
    return keyWord;
}

void Discipline::save(ofstream &file)
{
	file << name << " " << hours << " " << course;
}

void Discipline::load(ifstream &file)
{
    file >> name >> hours >> course;
}

Discipline *Discipline::copy()
{
    return new Discipline(*this);
}

istream &operator >> (istream &in, Discipline &d)
{
    cout << endl << "obj data input:" << endl;

    cout << "Name?: ";
    in >> ws;
    in.get(d.name, STR_LEN);
    if (in.get() != '\n') {
        in.clear();
        in.ignore(INT_MAX, '\n');
    }

    cout << "Hours?: ";
    in >> ws >> d.hours;
    cout << "Course?: ";
    in >> ws >> d.course;
    return in;
}

ostream &operator << (ostream &out, Discipline &d)
{
    out << endl << "obj data output:" << endl;
    out << "Name:   " << right << setw(STR_LEN) << d.name << endl;
    out << "Hours:  " << right << setw(STR_LEN) << d.hours << endl;
    out << "Course: " << right << setw(STR_LEN) << d.course << endl;
    return out;
}
