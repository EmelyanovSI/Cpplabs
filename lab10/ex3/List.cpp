#include <stdio.h>
#include <string.h>
#include "List.h"

List::List()
{

}

List::~List()
{
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
    /*list<Discipline*>::iterator iter1 = collection.begin();
    advance(iter1, n);
    list<Discipline*>::iterator iter2 = collection.begin();
    advance(iter2, m);*/

    char name[STR_LEN];
    int hours;
    int course;

    strcpy(name, (*getObject(n))->getName());
    hours = (*getObject(n))->getHours();
    course = (*getObject(n))->getCourse();

    (*getObject(n))->setName((*getObject(m))->getName());
    (*getObject(n))->setHours((*getObject(m))->getHours());
    (*getObject(n))->setCourse((*getObject(m))->getCourse());

    (*getObject(m))->setName(name);
    (*getObject(m))->setHours(hours);
    (*getObject(m))->setCourse(course);
}

void List::sort()
{
    //collection.sort();

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
