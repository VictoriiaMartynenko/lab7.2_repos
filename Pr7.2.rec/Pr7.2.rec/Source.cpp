#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, N, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, int rowNo)
{
    PrintRow(a, rowNo, N, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, rowNo + 1);
    else
        cout << endl;
}

void SwapMaxEvenRows(int** a, const int N)
{
    for (int i = 0; i < N; i += 2) 
    {
        int maxIndex = 0;
        for (int j = 1; j < N; j++) // максимальний елемент в рядку
        {
            if (a[i][j] > a[i][maxIndex])
                maxIndex = j;
        }
        // Міняємо місцями максимальний елемент рядка та елемент на головній діагоналі
        if (i < N) {
            int temp = a[i][i];
            a[i][i] = a[i][maxIndex];
            a[i][maxIndex] = temp;
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int N;
    cout << "N = ";
    cin >> N;
    cout << endl;

    int** a = new int* [N];
    for (int i = 0; i < N; i++)
        a[i] = new int[N];

    int Low = -9, High = 9;

  
    CreateRows(a, N, Low, High, 0);
    PrintRows(a, N, 0);

    // Перестановка максимальних елементів парних рядків на головну діагональ
    SwapMaxEvenRows(a, N);

    cout << "Result:" << endl;
    PrintRows(a, N, 0);

    for (int i = 0; i < N; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
