#ifndef LIST_H
#define LIST_H

#include <list>
#include "Discipline.h"

using namespace std;

class List
{
    public:
        List();
        ~List();

        void addToList(Discipline *discipline);
        void removeFromList(int index);
        int getLength();
        list<Discipline*>::iterator getObject(int index);
        void swap(int n, int m);
        void sort();
        void show();

        int find(char *name);
    private:
        list<Discipline*> collection;
};

#endif // LIST_H
