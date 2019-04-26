#ifndef LIST_H
#define LIST_H

#include "Discipline.h"

class List
{
    public:
        List();
        ~List();

        List &operator += (Discipline *discipline);
        List &operator += (Discipline &discipline);
        List &operator -= (char *name);
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

        friend List &operator -= (List &l, int index);
        void operator += (List &list);
    protected:

    private:
        Discipline **list;
        int size;
        int maxSize;
};

#endif // LIST_H
