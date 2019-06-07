#include <stdio.h>
#include <string.h>
#include <algorithm>
#include "List.h"

List::List() { }

List::~List()
{
    for (list<Discipline*>::iterator i = collection.begin(); i != collection.end(); i++)
        delete *i;
    collection.clear();
}

int List::find(char *name)
{
    for (int i = 0; i < collection.size(); i++)
        if (strcmp((*getObject(i))->getName(), name) == 0)
            return i;
    return -1;
}

void List::addToList(Discipline *discipline)
{
    collection.push_back(discipline);
}

void List::removeFromList(int index)
{
    list<Discipline*>::iterator iter = collection.begin();
    advance(iter, index);
    delete *iter;
    collection.erase(iter);
}

int List::getLength()
{
    return collection.size();
}

list<Discipline*>::iterator List::getObject(int index)
{
    list<Discipline*>::iterator iter = collection.begin();
    advance(iter, index);
    return iter;
}

void List::swap(int n, int m)
{
    list<Discipline*>::iterator iter1 = collection.begin();
    advance(iter1, n);
    list<Discipline*>::iterator iter2 = collection.begin();
    advance(iter2, m);
    iter_swap(iter1, iter2);
}

void List::sort()
{
    for (int i = 0; i < collection.size() - 1; i++)
        for (int j = i; j < collection.size(); j++)
			if (strcmp((*getObject(i))->getName(), (*getObject(j))->getName()) < 0)
				swap(i, j);
}

void List::show()
{
    list<Discipline*>::iterator iter;
    for (int i = 0; i < collection.size(); i++) {
        iter = collection.begin();
        advance(iter, i);
    	printf("\nList[%d]:\n", i);
        (**iter).output();
        printf("\n");
    }
}
