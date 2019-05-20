///��������� ������ �������-21 ���-10 ������-1
/*
����������� ��������� ���������� ���������� � �������������� ������ string ���������� STL,
�������� � ������������� ������������� ������� ������ string � ���������� ���������� STL.

��� ������ ����.
������������� ������ ���� �� ����������� ���� ����, ������ ����� ����� ����� ������ ���� ������������� �� ��������.
������������ ����������� �� ���� �������, ������������ ������ ����� ������ ����� 2 �������� ��������� �������:
����� �����, ������� �� ������ ������� (�������� ������� ��������� ����� ���, ��, ��), ��������� � ����� �����.
*/

#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    const int STR_LEN = 64;
    string *str = new string[STR_LEN];
    string sentence = "";
    string aoe = "aoe";
    int len, n = 0, kol;

    ifstream file;
    file.open("string.txt");
    if (file.is_open())
        while (!file.eof() && n < STR_LEN)
            file >> str[n++];
    file.close();
    len = n;

    cout << endl << "All words:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i].length() > str[j].length() || (str[i].length() == str[j].length() && str[i].compare(str[j]) > 0))
                str[i].swap(str[j]);

    cout << endl << "All words after sorting:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    for (int i = 0; i < len; i++)
        if ((kol = str[i].length()) > 2) {
            for (int j = 0; j < aoe.length(); j++)
                if (kol > str[i].find(aoe[j]))
                    kol = str[i].find(aoe[j]);
            if (kol != str[i].length()) {
                for (int j = 0; j < kol; j++)
                    str[i].push_back(str[i][j]);
                str[i].erase(0, kol);
            }
            sentence.append(str[i] + " ");
        }

    cout << endl << "Sentence:" << endl;
    cout << sentence << endl;

    delete str;
    getch();
    return 0;
}


    /*
    for (int i = 0; i < len - 1; i++) {
        int len_i, len_j;
        for (int j = i + 1; j < len; j++) {
            len_i = str[i].length();
            len_j = str[j].length();
            if (len_i > len_j || (len_i == len_j && str[i].compare(str[j]) > 0))
                str[i].swap(str[j]);
        }
    }
    */

    /*
    for (int i = 0; i < len - 1; i++) {
        int len_i, len_j;
        for (int j = i + 1; j < len; j++) {
            len_i = str[i].length();
            len_j = str[j].length();
            if (len_i > len_j)
                str[i].swap(str[j]);
            else if (len_i == len_j && str[i].compare(str[j]) > 0)
                str[i].swap(str[j]);
        }
    }
    */

    /*
    cout << endl << "All words after creating the sentence:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;
    */
