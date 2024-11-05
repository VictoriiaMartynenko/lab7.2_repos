// Lab_7_2_1.cpp
// ���������� ³�����
// ����������� ������ � 7.2.1)
// ������� ������������� ������ ������������ ���������.
// ������ 21

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SwapMaxEvenRows(int** a, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 7;
    int High = 65;
    int n;
    cout << "n = "; cin >> n;

    int** a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[n];

    Create(a, n, Low, High);
    Print(a, n);

    // ������������ ������������ �������� ������ ����� �� ������� ��������
    SwapMaxEvenRows(a, n);

    Print(a, n);
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

// �������� ����� ����������� ����������
void Create(int** a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// �������� ����� �� �����
void Print(int** a, const int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

// ����������� ���������� �������� ������ ����� �� ������� ��������
void SwapMaxEvenRows(int** a, const int n)
{
    for (int i = 0; i < n; i += 2) 
    {
        int maxIndex = 0;
        for (int j = 1; j < n; j++) 
        {
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
        }
        // ���� ������ ������������ ������� ����� � ������� �� ������� �������
        if (i < n) {
            int temp = a[i][i];
            a[i][i] = a[i][maxIndex];
            a[i][maxIndex] = temp;
        }
    }
}
