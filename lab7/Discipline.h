#ifndef DISCIPLINE_H
#define DISCIPLINE_H

const int STR_LEN = 64;

class Discipline
{
    public:
        Discipline();
        Discipline(char *n, int h, int c);
        Discipline(Discipline &d);
        Discipline(char *n);
        Discipline(char *n, Discipline *y, Discipline x);

        char *getName();
        void setName(char *n);
        int getHours();
        void setHours(int n);
        int getCourse();
        void setCourse(int n);

        virtual void input();
        virtual void output();

        void operator += (Discipline &discipline);

        virtual char getKey();
    protected:

    private:
        char name[STR_LEN];
        int hours;
        int course;

        const char key = '0';
};

#endif // DISCIPLINE_H
