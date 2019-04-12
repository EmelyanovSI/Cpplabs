#ifndef GRADE_H
#define GRADE_H

#include "discipline.h"

class grade: public discipline
{
    public:
        grade();
        grade(char *n, int h, int c, char *s, int v);
        grade(discipline *d, char *c, int n);

        char *getStudent();
        void setStudent(char *s);
        int getValue();
        void setValue(int v);

        int setChar(char a);

        void input();
        void output();
    private:
        char student[STR_LEN];
        int value;
};

#endif // GRADE_H
