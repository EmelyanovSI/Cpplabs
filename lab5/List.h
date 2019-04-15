#ifndef LIST_H
#define LIST_H

#include "Discipline.h"

class List
{
    public:
        List();
        ~List();

        void addToList(Discipline *discipline);
        void removeFromList(int index);
        int getLength();
        Discipline *getObject(int index);
        void swap(int n, int m);
        void sort();
        void show();
    protected:

    private:
        Discipline **list;
        int size;
        int maxSize;
};

#endif // LIST_H
