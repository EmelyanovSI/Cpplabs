#ifndef DISCIPLINE_H
#define DISCIPLINE_H

const int STR_LEN = 64;

class discipline
{
    public:
        char *getName();
        void setName(char *n);
        int getHours();
        void setHours(int n);
        int getCourse();
        void setCourse(int n);
        void input();
        void output();

        int find(discipline *mas, int n);
    protected:

    private:
        char name[STR_LEN];
        int hours;
        int course;
};

#endif // DISCIPLINE_H

