#ifndef GRADE_H
#define GRADE_H

#include "Discipline.h"

class Grade: public Discipline
{
    public:
        Grade();
        Grade(char *n, int h, int c, char *s, int v);

        void setStudent(char *s);
        void setValue(int v);
        char *getStudent();
        int getValue();

        char *getKey();
        void input();
        void output();
        void save(ofstream &file);
        void load(ifstream &file);

        friend ostream &operator << (ostream &out, Grade &g);
        friend istream &operator >> (istream &in, Grade &g);

    protected:

    private:
        static const char key = '1';
        char student[STR_LEN];
        int value;
};

#endif // GRADE_H
