#ifndef GRADE_H
#define GRADE_H

#include "discipline.h"

class grade: public discipline
{
    public:
        grade();
        grade(char *n, int h, int c, char *s, int v);

        char *getStudent();
        void setStudent(char *s);
        int getValue();
        void setValue(int v);

        void input();
        void output();
    private:
        char student[STR_LEN];
        int value;
};

#endif // GRADE_H
