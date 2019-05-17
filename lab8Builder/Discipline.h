#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int STR_LEN = 16;

class Discipline
{
    public:
        Discipline();
        Discipline(char *n, int h, int c);
        Discipline(Discipline &d);
        Discipline(char *n);
        Discipline(char *n, Discipline *y, Discipline x);

        void operator += (Discipline &discipline);

        void setName(char *n);
        void setHours(int n);
        void setCourse(int n);
        char *getName();
        int getHours();
        int getCourse();

        virtual char *getKey();
        virtual void input();
        virtual void output();
        virtual void save(ofstream &file);
        virtual void load(ifstream &file);
        virtual Discipline *copy();

        friend ostream &operator << (ostream &out, Discipline &d);
        friend istream &operator >> (istream &in, Discipline &d);

    protected:
        char keyWord[2*STR_LEN];

    private:
        static const char key = '0';
        char name[STR_LEN];
        int hours;
        int course;
};

#endif // DISCIPLINE_H
