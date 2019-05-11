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
        virtual void save(FILE *file);
        void load(FILE *file);

        virtual Discipline *copy();
    protected:
        char keyWord[STR_LEN*2];

    private:
        static const char key = '0';
        char name[STR_LEN];
        int hours;
        int course;
};

#endif // DISCIPLINE_H
