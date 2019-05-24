#ifndef LIST_H
#define LIST_H

#include "Discipline.h"
#include "Grade.h"

template <typename Type>
class List
{
    public:
        List() {
            size = 0;
            maxSize = 2;
            list = new Type *[maxSize];
        }
        ~List() {
            for (int i = 0; i < size; i++)
                delete list[i];
            delete [] list;
        }

        void operator += (List &list) {
            int size = list.getSize();
            for (int i = 0; i < size; i++)
                *this += *list.getObject(i);
        }
        List &operator += (Type *type) {
            addToList(type);
            return *this;
        }
        List &operator += (Type &type) {
            addToList(type.copy());
            return *this;
        }
        List &operator -= (char *name) {
            for (int i = 0; i < size; i++)
                if (strcmp(list[i]->getName(), name) == 0) {
                    removeFromList(i);
                    i--;
                }
            return *this;
        }
        Type *operator [] (int index) {
            return getObject(index);
        }
        Type *operator [] (char *name) {
            for (int i = 0; i < size; i++)
                if (strcmp(list[i]->getName(), name) == 0)
                    return (*this)[i];
            return NULL;
        }

        void addToList(Type *type) {
            if (size == maxSize) {
                maxSize *= 2;
                Type **temp;
                temp = new Type *[maxSize];
                for (int i = 0; i < size; i++)
                    temp[i] = list[i];
                delete [] list;
                list = temp;
            }
            list[size] = type;
            size++;
        }
        void removeFromList(int index) {
            delete list[index];
            for (int i = index; i < size - 1; i++)
                list[i] = list[i + 1];
            size--;
        }
        int getSize() {
            return size;
        }
        Type *getObject(int index) {
            return list[index];
        }
        void swap(int n, int m) {
            Type *temp;
            temp = list[n];
            list[n] = list[m];
            list[m] = temp;
        }
        void sort() {
            for (int i = 0; i < size - 1; i++)
                for (int j = i; j < size; j++)
                    if (strcmp(list[i]->getKey(), list[j]->getKey()) > 0)
                        swap(i, j);
        }
        void show() {
            for (int i = 0; i < size; i++) {
                cout << endl << "List[" << i << "]:" << endl;
                list[i]->output();
                cout << endl;
            }
        }
        int find(char *name) {
            for (int i = 0; i < size; i++)
                if (strcmp(list[i]->getName(), name) == 0)
                    return i;
            return -1;
        }

        void input(int index) {
            list[index]->input();
        }

        //method
        void output(int index);

        void save(char *filename) {
            ofstream file;
            file.open(filename);
            for (int i = 0; i < size; i++) {
                list[i]->save(file);
                file << endl;
            }
            file.close();
        }
        void load(char *filename) {
            ifstream file;
            file.open(filename);
            if (!file.is_open())
                return;
            while (!file.eof()) {
                addToList(new Type());
                list[size - 1]->load(file);
            }
            file.close();
        }

        friend List &operator -= (List &l, int index) {
            l.removeFromList(index);
            return l;
        }

    protected:

    private:
        Type **list;
        int size;
        int maxSize;
};

#endif // LIST_H

template<typename Type>
void List<Type>::output(int index) {
    list[index]->output();
}
