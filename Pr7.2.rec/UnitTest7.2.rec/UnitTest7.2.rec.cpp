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
            const int N = 3; // ��������� ������� �������
            const int Low = -9, High = 9;

            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // ������ ������� ��������� �������
            CreateRows(a, N, Low, High, 0);

            // ��������, �� �������� � ����� [Low, High]
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            // ��������� ���'��
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
        }

        TEST_METHOD(TestSwapMaxEvenRows)
        {
            const int N = 4; // ��������� �������
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            // ����������� ������� �������
            a[0][0] = 1;  a[0][1] = 5;  a[0][2] = 3;  a[0][3] = 4;
            a[1][0] = -7; a[1][1] = -15; a[1][2] = 6;  a[1][3] = 2;
            a[2][0] = 8;  a[2][1] = 7;  a[2][2] = 10; a[2][3] = -5;
            a[3][0] = 3;  a[3][1] = 9;  a[3][2] = 12; a[3][3] = -1;

            // ������ ������� ��� ������������ ������������ �������� ������ �����
            SwapMaxEvenRows(a, N);

            // �������� ���������� ������������
            Assert::AreEqual(5, a[0][0]);   // ������������ ������� � ����� 0 ��������� �� ������� ��������
            Assert::AreEqual(10, a[2][2]);  // ������������ ������� � ����� 2 ��������� �� ������� ��������

            // ��������� ���'��
            for (int i = 0; i < N; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}

