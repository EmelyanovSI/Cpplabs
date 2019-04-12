// class  самолет, номер самолета, количество мест
// конструктор копирования и инициализации
// вывод на экран
// метод установки значения для номера
// для количества мест - метод получения

#include <stdio.h>
#include <conio.h>
#include <string.h>

const int STR_LEN = 64;

class plane
{
    public:
        plane() {
            number[0] = '\0';
            kol = 0;
        }
        plane(plane &p) {
            strcpy(number, p.number);
            kol = p.kol;
        }
        void output() {
            printf("\nNumber: %s\n", number);
            printf("\nKol: %d\n", kol);
        }
        void setNumber(char *n) {
            strcpy(number, n);
        }
        int getKol() {
            return kol;
        }
    private:
        char number[64];
        int kol;
};

int main()
{
    //static

    plane staticObject1;

    staticObject1.setNumber("One");
    printf("\nKOL: %d\n", staticObject1.getKol());
    staticObject1.output();

    plane staticObject2(staticObject1);

    printf("\nKOL: %d\n", staticObject2.getKol());
    staticObject2.output();

    //dynamic

    plane *dynamicObject1;
    dynamicObject1 = new plane;

    dynamicObject1->setNumber("Two");
    printf("\nKOL: %d\n", dynamicObject1->getKol());
    staticObject1.output();

    plane *dynamicObject2;
    dynamicObject2 = new plane(*dynamicObject1);

    printf("\nKOL: %d\n", dynamicObject2->getKol());
    dynamicObject2->output();

    delete dynamicObject1;
    delete dynamicObject2;

    getch();
    return 0;
}
