#include <stdio.h>
#include <string.h>
#include "List.h"

List::List()
{
    size = 0;
	maxSize = 2;
	list = new Discipline *[maxSize];
}

List::~List()
{
    for (int i = 0; i < size; i++) {
		delete list[i];
	}
	delete [] list;
}

List &List::operator += (Discipline *discipline)
{
    addToList(discipline);
    return *this;
}

List &List::operator += (Discipline &discipline)
{
    addToList(new Discipline(discipline));
    return *this;
}

List &operator -= (List &l, int index)
{
    l.removeFromList(index);
    return l;
}

List &List::operator -= (char *name)
{
    for (int i = 0; i < size; i++)
        if (strcmp(list[i]->getName(), name) == 0) {
            removeFromList(i);
            i--;
        }
    return *this;
}

Discipline *List::operator [] (int index)
{
    return getObject(index);
}

Discipline *List::operator [] (char *name)
{
    for (int i = 0; i < size; i++)
        if (strcmp(list[i]->getName(), name) == 0)
            return (*this)[i];
    return NULL;
}

void List::operator += (List &list)
{
    int size = list.getLength();
    for (int i = 0; i < size; i++)
        *this += *list.getObject(i);
}

int List::find(char *name)
{
    for (int i = 0; i < size; i++)
        if (strcmp(list[i]->getName(), name) == 0)
            return i;
    return -1;
}

void List::addToList(Discipline *discipline)
{
    if (size == maxSize) {
		maxSize *= 2;
		Discipline **temp;
		temp = new Discipline *[maxSize];
		for (int i = 0; i < size; i++)
			temp[i] = list[i];
		delete [] list;
		list = temp;
	}
	list[size] = discipline;
	size++;
}

void List::removeFromList(int index)
{
    delete list[index];
    for (int i = index; i < size - 1; i++)
        list[i] = list[i + 1];
    size--;
}

int List::getLength()
{
    return size;
}

Discipline *List::getObject(int index)
{
    return list[index];
}

void List::swap(int n, int m)
{
    Discipline *temp;
    temp = list[n];
	list[n] = list[m];
    list[m] = temp;
}

void List::sort()
{
    for (int i = 0; i < size - 1; i++)
		for (int j = i; j < size; j++) {
            if (strcmp(list[i]->getName(), list[j]->getName()) < 0)
                swap(i, j);
		}
}

void List::show()
{
    for (int i = 0; i < size; i++) {
		printf("\nList[%d]:\n", i);
		list[i]->output();
		printf("\n");
	}
}
