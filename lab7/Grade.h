#ifndef GRADE_H
#define GRADE_H

#include "Discipline.h"

class Grade: public Discipline
{
    public:
        Grade();
        Grade(char *n, int h, int c, char *s, int v);

        char *getStudent();
        void setStudent(char *s);
        int getValue();
        void setValue(int v);

        void input();
        void output();

        char getKey();
    private:
        char student[STR_LEN];
        int value;

        const char key = '1';
};

#endif // GRADE_H
