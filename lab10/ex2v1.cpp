///��������� ������ �������-21 ���-10 ������-2
/*
����������� ��������� ����������� ������� ������ � �������������� ���������� ������ vector ���������� STL,
�������� � ������������� ������������� ������� ������ vector � ���������� ���������� STL.

��� ������ �� N ����� �����.
����� ������� �������������� ��������� �������, ������� ����� k.
�������� ���� � ���� ��������� ������� ����� ������ ������������ � ��������� ������������ ����������.
���� ������ ������������� ������� ����� ������ ������,
�� �������� ������� ����� ������� ������������ ����� ��������.
������� �� ������� ������� ��������. ������������� ������ �������� ������� �� �����������.
*/

#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

int main()
{
    //��� ������ �� N ����� �����
    int n, k, buf;
    cout << "Input n: ";
    cin >> n;
    cout << "Input k: ";
    cin >> k;
    cout << endl;
    vector<int> arr;

    //������ �������� �������
    cout << endl << "Input vector:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        arr.push_back(buf);
    }
    //������� �������� �������
    cout << endl << "Output vector:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //����� ������� �������������� ��������� �������, ������� ����� k
    int sum = 0, m = 0, sr;
    for (int i = 0; i < n; i++)
        if (arr[i] % k == 0) {
            sum += arr[i];
            m++;
        }
    sr = sum / m;
    cout << endl << "Sr arifm: " << sr << endl;

    //�������� ���� � ���� ��������� ������� ����� ������ ������������ � ��������� ������������ ����������
    int max = arr.front(), max_i = 0, max_j = n - 1;
    for (int i = 0; i < n; i++)
        if (max < arr[i]) {
            max = arr[i];
            max_i = i;
        }
    for (int i = n - 1; i >= 0; i--)
        if (max == arr[i]) {
            max_j = i;
            break;
        }
    for (int i = max_i + 1; i < max_j; i++)
        arr[i] = -arr[i];

    //������� �������� �������
    cout << endl << "Output vector with -:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //���� ������ ������������� ������� ����� ������ ������,
    //�� �������� ������� ����� ������� ������������ ����� ��������.
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            if (i % 2 == 0) {
                vector<int> part1, part2;
                part1.insert(part1.begin(), arr.begin(), arr.begin() + i);
                part2.insert(part2.begin(), arr.begin() + i + 1, arr.end());
                buf = arr[i];
                arr.insert(arr.begin(), part2.begin(), part2.end());
                arr.insert(arr.begin() + part2.size(), buf);
                arr.insert(arr.begin() + part2.size() + 1, part1.begin(), part1.end());
                break;
            }
            else
                break;

    //������� �������� �������
    cout << endl << "Output vector after insert:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //������� �� ������� ������� ��������
    for (int i = 0; i < n; i++)
        if (arr.at(i) == 0) {
            arr.erase(arr.begin() + i);
            n--;
            i--;
        }

    //������� �������� �������
    cout << endl << "Output vector without 0:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    //������������� ������ �������� ������� �� �����������
    for (int i = 0; i < n / 2 - 1; i++)
        for (int j = i + 1; j < n / 2; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);

    //������� �������� �������
    cout << endl << "Output vector after sorting:" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;

    getch();
    return 0;
}
