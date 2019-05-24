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
#include <string>

using namespace std;

int main()
{
    //��� ������ ����.
    int len;
    cout << "Input kol words: ";
    cin >> len;
    string *str = new string[len];
    string sentence = "";
    string aoe = "aoe";
    int n, kol;

    //���� ������� ����
    for (int i = 0; i < len; i++)
        cin >> str[i];

    //����� ������� ����
    cout << endl << "All words:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    //������������� ������ ���� �� ����������� ���� ����, ������ ����� ����� ����� ������ ���� ������������� �� ��������.
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i].length() > str[j].length() || (str[i].length() == str[j].length() && str[i].compare(str[j]) > 0))
                str[i].swap(str[j]);

    //����� ������� ���� ����� ����������
    cout << endl << "All words after sorting:" << endl;
    for (int i = 0; i < len; i++)
        cout << str[i] << endl;

    //������������ ����������� �� ���� �������, ������������ ������ ����� ������ ����� 2 �������� ��������� �������:
    //����� �����, ������� �� ������ ������� (�������� ������� ��������� ����� ���, ��, ��), ��������� � ����� �����.
    for (int i = 0; i < len; i++) {
        if (str[i].length() > 2) {
            kol = str[i].length();
            for (int j = 0; j < aoe.length(); j++) {
                n = str[i].find(aoe[j]);
                if (kol > n && n != -1)
                    kol = n;
            }
            if (kol >= 0 && kol <= str[i].length()) {
                for (int j = 0; j < kol; j++)
                    str[i].push_back(str[i][j]);
                str[i].erase(0, kol);
            }
        }
        sentence.append(str[i] + " ");
    }
    sentence.erase(sentence.length() - 1, 1);

    //����� �����������
    cout << endl << "Sentence:" << endl;
    cout << sentence << endl;

    delete [] str;
    getch();
    return 0;
}
