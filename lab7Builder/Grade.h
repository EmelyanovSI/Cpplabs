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
        void save(FILE *file);
        void load(FILE *file);

        virtual Grade *copy();
    protected:

    private:
        static const char key = '1';
        char student[STR_LEN];
        int value;
};

#endif // GRADE_H
