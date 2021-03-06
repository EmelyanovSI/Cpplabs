#ifndef DISCIPLINE_H
#define DISCIPLINE_H

const int STR_LEN = 64;

class discipline
{
    public:
        discipline();
        discipline(char *n, int h, int c);
        discipline(discipline &d);
        discipline(char *n);
        discipline(char *n, discipline *y, discipline x);

        char *getName();
        void setName(char *n);
        int getHours();
        void setHours(int n);
        int getCourse();
        void setCourse(int n);
        void input();
        void output();

        int setChar(char a);
    protected:

    private:
        char name[STR_LEN];
        int hours;
        int course;
};

#endif // DISCIPLINE_H
