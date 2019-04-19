#ifndef LIST_H
#define LIST_H

#include "Discipline.h"

class List
{
    public:
        List();
        ~List();

        void operator += (Discipline *discipline);
        void operator += (Discipline &discipline);
        void operator -= (int index);
        void operator -= (char *name);
        Discipline *operator [] (int index);
        Discipline *operator [] (char *name);

        void addToList(Discipline *discipline);
        void removeFromList(int index);
        int getLength();
        Discipline *getObject(int index);
        void swap(int n, int m);
        void sort();
        void show();

        int find(char *name);
    protected:

    private:
        Discipline **list;
        int size;
        int maxSize;
};

#endif // LIST_H
