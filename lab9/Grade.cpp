#include "Grade.h"

Grade::Grade():Discipline()
{
    student[0] = '\0';
    value = 0;
}

Grade::Grade(char *n, int h, int c, char *s, int v):Discipline(n, h, c)
{
    strcpy(student, s);
    value = v;
}

void Grade::setStudent(char *s)
{
    strcpy(student, s);
}

void Grade::setValue(int v)
{
    value = v;
}

char *Grade::getStudent()
{
    return student;
}

int Grade::getValue()
{
    return value;
}

void Grade::input()
{
    Discipline::input();
    cin >> *this;
}

void Grade::output()
{
    Discipline::output();
    cout << *this;
}

char *Grade::getKey()
{
    sprintf(keyWord, "%c%s", key, student);
    return keyWord;
}

void Grade::save(ofstream &file)
{
    Discipline::save(file);
	file << " " << student << " " << value;
}

void Grade::load(ifstream &file)
{
    Discipline::load(file);
    file >> student >> value;
}

istream &operator >> (istream &in, Grade &g)
{
    cout << "Student?: ";
    in >> ws;
    in.getline(g.student, STR_LEN);
    in.clear();
    fflush(stdin);

    cout << "Value?: ";
    in >> g.value;
    return in;
}

ostream &operator << (ostream &out, Grade &g)
{
    out << "Student:" << right << setw(STR_LEN) << g.student << endl;
    out << "Value:  " << right << setw(STR_LEN) << g.value << endl;
    return out;
}
