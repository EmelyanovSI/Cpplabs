#ifndef LIST_H
#define LIST_H

#include "Discipline.h"
#include "Grade.h"

class List
{
    public:
        List();
        ~List();

        void operator += (List &list);
        List &operator += (Discipline *discipline);
        List &operator += (Discipline &discipline);
        List &operator -= (char *name);
        Discipline *operator [] (int index);
        Discipline *operator [] (char *name);

        void addToList(Discipline *discipline);
        void removeFromList(int index);
        int getSize();
        Discipline *getObject(int index);
        void swap(int n, int m);
        void sort();
        void show();
        int find(char *name);

        void input(int index);
        void output(int index);
        void save(char *filename);
        void load(char *filename);

        friend List &operator -= (List &l, int index);

    protected:

    private:
        Discipline **list;
        int size;
        int maxSize;
};

#endif // LIST_H
