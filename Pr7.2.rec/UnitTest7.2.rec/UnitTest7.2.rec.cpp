#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr7.2.rec/Source.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForMatrixFunctions
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:

        TEST_METHOD(TestCreateRows)
        {
            const int N = 3; // Розмірність тестової матриці
            const int Low = -9, High = 9;

            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // Виклик функції створення матриці
            CreateRows(a, N, Low, High, 0);

            // Перевірка, чи значення в межах [Low, High]
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            // Звільнення пам'яті
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
        }

        TEST_METHOD(TestSwapMaxEvenRows)
        {
            const int N = 4; // Розмірність матриці
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // Ініціалізація тестової матриці
            a[0][0] = 1;  a[0][1] = 5;  a[0][2] = 3;  a[0][3] = 4;
            a[1][0] = -7; a[1][1] = -15; a[1][2] = 6;  a[1][3] = 2;
            a[2][0] = 8;  a[2][1] = 7;  a[2][2] = 10; a[2][3] = -5;
            a[3][0] = 3;  a[3][1] = 9;  a[3][2] = 12; a[3][3] = -1;

            // Виклик функції для перестановки максимальних елементів парних рядків
            SwapMaxEvenRows(a, N);

            // Перевірка результатів перестановки
            Assert::AreEqual(5, a[0][0]);   // Максимальний елемент у рядку 0 переміщено на головну діагональ
            Assert::AreEqual(10, a[2][2]);  // Максимальний елемент у рядку 2 переміщено на головну діагональ

            // Звільнення пам'яті
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}

