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
    cin >> *this;
}

void Grade::output()
{
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

Grade *Grade::copy()
{
    return new Grade(*this);
}

istream &operator >> (istream &in, Grade &g)
{
    in >> (Discipline&)g;

    cout << "Student?: ";
    in >> ws;
    in.get(g.student, STR_LEN);
    in.clear();
    in.ignore(INT_MAX, '\n');

    cout << "Value?: ";
    in >> ws >> g.value;
    return in;
}

ostream &operator << (ostream &out, Grade &g)
{
    out << (Discipline&)g;

    out << "Student:" << right << setw(STR_LEN) << g.student << endl;
    out << "Value:  " << right << setw(STR_LEN) << g.value << endl;
    return out;
}
