#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
//#include "clocale.h"
//#include <iostream>
#include "string.h"
//#include <consoleapi2.h>
//#include <conio.h >
#include <Windows.h >
//#include <string>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
/*                // ������ ������

* /

int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ������� ��������� � ����� � ��������� ���������.\033[0m\n");
    do
    {

        printf("\n��� �����?(y/n ��� �/�):");
        ch=getch();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("\033[31m������!\033[0m �����(y/n �/�):");
            ch = getch();
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}

*/
#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
//#include "clocale.h"
//#include <iostream>
#include "string.h"
//#include <consoleapi2.h>
//#include <conio.h >
#include <Windows.h >
//#include <string>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
/*                // ������ ������

* /

int Exsample10(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ������� ��������� � ����� � ��������� ���������.\033[0m\n");
    do
    {

        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}

*/
/*
1. ������������� ��������� rain. � �� �������� 10.7, ����� ��� ��������� ����������
� �������������� ���������� ������ ��������. 
(��� ��-�������� �������� ��������� � ���������������� ������.)
*/
int rain10(void);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ������� ��������� � ����� � ��������� ���������.\033[0m\n");
    do
    {
        rain10();
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}

// ������� 10.7. ��������� rain.c
/* rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������
�������� �� ����� �� ������ �� ������� �� ��������� ��� */
#include <stdio.h>
#include <stdbool.h>
#define MONTHS107 12	// ���������� ������� � ����
#define YEARS107 5		// ���������� ���, ��� ������� �������� ������
int rain10(void)
{
    // ������������� ������� �� ������� �� ������ � 2010 �� 2014 ��.
    const float rain[YEARS107][MONTHS107] =
    {
        { 4.3,4.3, 4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5, 8.2, 1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    //const float const (*prain)[MONTHS107];
    float(*prain)[12];
    int year, month;
    float subtot, total;
    prain = rain;
    printf("\n\033[1;4;44m������� 10.7.���������  rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������.\033[0m\n");
    printf("��� ���������� ������� (� ������)\n");
    for (year = 0, total = 0; year < YEARS107; year++)
    { // ��� ������� ���� ����������� ���������� ������� �� ������ �����
        //for (int i = 0; i < 12; i++) prain[year][i]= {  }
        for (month = 0, subtot = 0; month < MONTHS107; month++)
            subtot += *(*(prain+year)+month);              // subtot += prain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;				// ����� ����� ��� ���� ���
    }
    printf("\n������������� ���������� ������� ���������� %.1f ������. \n\n", total / YEARS107);
    printf("�������������� ���������� �������:\n\n");
    printf(" ��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t���");
    printf(" \t��� \t���\n");
    for (month = 0; month < MONTHS107; month++)
    { // ��� ������� ������ ����������� ���������� ������� �� ���������� �����
        for (year = 0, subtot = 0; year < YEARS107; year++)
            subtot +=*(*(prain+year)+month);
        printf("%4.1f\t", subtot / YEARS107);
    }
    printf("\n\n");
    return 0;
}
/*
    2. �������� ���������, ������� �������������� ������ �������� ���� double
        � ����� �������� ��� ���������� � ��� ������ �������. 
        (��� ������ ������� ������ ���� ��������� � ������� ���������.) 
        ��� �������� ������ ����� �������������� ��������, � ������� ����������� ����� ������ � ���������.
        ��� �������� ������ ����� ����������� �������, � ������� ����������� �����
        ������ � ����������� � ����������������� ����������. ������ ��� �������
        ������ ��������� � �������� ���������� ��� �������� �������, ��� ���������
        ������� � ���������� ���������, ���������� �����������. ������ �������
        ������ ��������� � �������� ���������� ��� �������� �������, ��� ���������
        ������� � ��������� �� �������, ��������� �� ��������� ��������� � ��������
        �������. � ������ ����������� ���� ���������� ������ ������� ������ ��������� ���:
        double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5);
        double targetl[5];
        double target2[5];
        double target3[5];
        copy_arr(targetl, source, 5);
        copy_ptr(target2, source, 5);
        copy_ptrs(target3, source, source + 5) ;
*/
void copy_arr102(double target[], const double  source[], int n);
void copy_ptr102(double* target, const double*  source, int n);
void copy_ptrs102(double target[], const double  source[], int* sourceEnd);
void prIntArr1(int* arr, int n, int k, char* title);
void prDblArr1(double arr[], int n, int k, char* title);

int Exsample2(void)
{
    int i, beg, end;
    char ch;
    double source[50] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    double target1[50];
    double target2[50];
    double target3[50];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. �������������� ������ �������� ���� double � �������� ��� � ��� �������.\033[0m\n");
    do
    {
        prDblArr1(source, 50, 5, "��������:");
        copy_arr102(target1, source, 50);
        prDblArr1(target1, 50,5, "����� 1:");
        copy_ptr102(target2, source, 50);
        prDblArr1(target2, 50, 5, "����� 2:");
        copy_ptrs102(target3, source, source + 50);
        prDblArr1(target3, 50,5, "����� 3:");

        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
void copy_arr102(double target[], const double source[], int n) {
    for (int i = 0; i <n; i++){
        target[i] = source[i];
    }
}
void copy_ptr102(double* target, const double * source, int n) {
    for (int i = 0; i <n; i++){
        *(target++) = *(source++);
    }
}
void copy_ptrs102(double* target, const double*  source, int* sourceEnd) {
    while (source < sourceEnd) *(target++) = *(source++);
}
void prIntArr1(int arr[], int n, int k, char* title) {
    if (strlen(title) > 0)printf("%s\n", title);
    for (int i = 0; i < n; i++) {
        (n < 100) ? printf("arr[%2d] = %d \t", i, arr[i]) :
                    printf("arr[%3d] = %d \t", i, arr[i]);
        if ((i + 1) % k == 0) printf("\n");
    }
    printf("\n");
}
void prDblArr1(double arr[], int n, int k, char* title) {
    if(strlen(title)>0)printf("%s\n", title);
    for (int i = 0; i < n; i++) {
        (n<100)?printf("arr[%2d] = %10.2lf \t", i, arr[i]): 
                printf("arr[%3d] = %10.2lf \t", i, arr[i]);
        if ((i + 1) % k == 0) printf("\n");
    }
    printf("\n");
}
/*
3. �������� �������, ������� ���������� ���������� �������� � ������� �������� ���� int. 
������������� ��� ������� � ������� ������� ���������.
*/
int min103( const int arr[], int n);
int Exsample3(void)
{
    int i, max, end,len;
    char ch;
    int testArr[] = {-1,-2,-3,-4,-5,6,-7,-8,-9,-10};
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 3. ���������� ���������� �������� � ������� �������� ���� int.\033[0m\n");
    do
    {
        len = sizeof(testArr) / sizeof( int);
        prIntArr1(testArr, len, 3, "����� max � �������:");
        max=max103(testArr,len);
        printf("�������� = %d\n", max);
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
int max103(const int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) max = arr[i];
    }return max;
}
/*
4. �������� �������, ������� ���������� ������ ����������� �������� � �������
�������� ���� double. ������������� ��� ������� � ������� ������� ���������.
*/
int imaxDblArr(int n, const double* test );
int Exsample4(void)
{
    int i, beg, imax;
    char ch;
    const double test[12] = {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6};

    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 4. ���������� ������ ����������� �������� � ������� ���� double.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "����� ������ ������������ �������� � �������:");
        imax = imaxDblArr(12,test);
        printf("������=%d\n", imax);
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
int imaxDblArr(int n, const double *test) {
    double max = test[0];
    int imax=0;
    for (int i = 1; i < n; i++)
        if (max < test[i]) {
            max = test[i];
            imax = i;
        }
    return imax;
}
/*
5. �������� �������, ������� ���������� �������� ����� ���������� � ���������� 
���������� � ������� �������� ���� double. ������������� ��� ������� � ������� ������� ���������.
*/
int iminDblArr(int n, const double* test);
int Exsample5(void)
{
    int i, imin, imax;
    char ch;
    const double test[12] = { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 };
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 5. �������� ����� max � min ���������� � ������� double.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "����� �������� ������������ � ������������ �������� � �������:");
        imax = imaxDblArr(12, test);
        imin = iminDblArr(12, test);
        printf("��������=[%d]-[%d]=%lf\n", imax,imin,test[imax]-test[imin]);

        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
int iminDblArr(int n, const double* test) {
    double min = test[0];
    int imin = 0;
    for (int i = 1; i < n; i++)
        if (min > test[i]) {
            min = test[i];
            imin = i;
        }
    return imin;
}
/*
6. �������� �������, ������� �������� ������� ���������� ����������� �������
�������� ���� double �� ��������������� � ������������� �� � ������� ���������.
*/
void revert6(double* arr,int n);
int Exsample6(void)
{
    int i, beg, end;
    char ch;
    const double test[12] = { 1.3, 2.3, 3.3, 4.0, 5.0, 6.2, 7.2, 8.2, 9.4,10.4,11.5, 12.6 };
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 6. �������� ������� ����������� ������� double �� ���������������.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "������ �� ���������:");
        revert6( test,  12);
        prDblArr1(test, 12, 5, "������ ����� ��������� �������:");
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
void revert6(double arr[], int n) {
    double tmp;
    for (int i = 0; i < n/2; i++) {
        tmp = arr[i];
        arr[i] = arr[n - i-1];
        arr[n - i-1] = tmp;
    }
}
/*
7. �������� ���������, ������� �������������� ��������� ������ ��������
���� double � ���������� ���� �� ������� ����������� �� ���������� 2 ���
��� ����������� �� ������ ��������� ������. (��������� ��������� ������ -
��� ������ ��������, ������� ��� ����������� ���������� �������� �����
���������� � ������ �����������.)
*/
void prDblArr2(double arr[][5], int n, int m, int k, char* title);
int Exsample7(void)
{
    int i, beg, end;
    char ch;
    double source[3][5] = { {1.,2.,3.,4.,5.},{10.,20.,30.,40.,50.},{100.,200.,300.,400.,500.} };
    double target[3][5] = {0};
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 7. �������������� ��������� ������ double � ���������� ���� �� ������� ����������� �� ���������� 2.\033[0m\n");
    do
    {
        for (int i = 0; i < 3; i++)prDblArr1(source[i], 3, 5, (i==0)?"�������� ������:":"");
        for (int i = 0; i < 3; i++)
        {
            copy_arr102(target[i], source[i], 5);
        }
        for (int i = 0; i < 3; i++)prDblArr1(target[i], 3, 5, (i==0)?"��������������:":"");
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
void prDblArr2(double arr[][5], int n, int m, int k, char* title) {
    bool end = false;
    if (strlen(title) > 0)printf("%s\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            end = false;
            (n < 10) ?      printf("arr[%d,%d] = % 5.2lf \t", i,j, arr[i][j]) :
                (n < 100) ? printf("arr[%2d,%2d] = % 5.2lf \t", i,j, arr[i][j]):
                            printf("arr[%3d,%3d] = % 5.2lf \t", i, j, arr[i][j]);
            if ((j + 1) % k == 0) {
                end = true;
                printf("\n");
            }
        }
        if (!end) printf("\n");
    }
    printf("\n");
}
/*
8. �������������� ����� �� ������� ����������� �� ���������� 2 ��� �����������
��������� � 3-�� �� 5-� ��������������� ������� � ������, ��������� ��
���� ���������. ���� ������� �������� �� �����; ������ ��������� ����������
����������� ���������. (������������ ����������� �� ����������� ������
���� ��� ������� � ��� ������. ��� ������ ������ ���� ����� ��������
������� � ���������� �������������� ���������.)
*/

int Exsample8(void)
{
    int i, beg, end;
    char ch;
    double source[7] = { 1.,2.,3.,4.,5.,6.,7. };
    double target[3];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 8. ����������� ��������� � 3-�� �� 5-� ��������������� ������� � ������, ��������� �� 3-�.\033[0m\n");
    do
    {
        prDblArr1(source, 7, 3, "�������� ������:");
        copy_arr102(target, source+2, 3);
        prDblArr1(target, 3, 3, "��������� �������� 3-5 ���������:");
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
/*
9. �������� ���������, ������� �������������� ��������� ������ 3�5 ��������
���� double � ���������� �������, ���������� �� �������� ����������
�����, ��� ����������� ����� ������� �� ������ ��������� ������. �����
����, �������� �������, ���������� �� �������� ���������� �����, ��� �����������
����������� ���� ���� ��������. � ����� ������ ��� ������� ������
���� �������� ������������ ������������ ������� N��. (���� �� �� ������
������� � �����������, ��������������� ������� ���������� �����, ���������
������������ ������ � � ���������, ������� ����� ������������ ������� Nx5).
*/

int Exsample9(void)
{
    int i, beg, end;
    char ch;
    double source[3][5] = { {1.,2.,3.,4.,5.},{10.,20.,30.,40.,50.},{1.1,2.2,3.3,4.4,5.5}};
    double target[3][5];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 9. ����������� ������� double[3][5].\033[0m\n");
    do
    {
        for (int i = 0; i < 3; i++)prDblArr1(source[i], 3, 5, (i == 0) ? "�������� ������:" : "");
        for (int i = 0; i < 3; i++)
        {
            copy_arr102(target[i], source[i], 5);
        }
        for (int i = 0; i < 3; i++)prDblArr1(target[i], 3, 5, (i == 0) ? "��������������:" : "");

        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
/*
10. �������� �������, ������� ������������� �������� ������� �������� �������
� ����� ��������������� ��������� � ���� ������ ��������. ������� �������,
���� ������ 1 ����� �������� 2, 4, 5 � 8, � ������ 2 � �������� 1, 0, 4 � 6, �� ���
������� ����������� ������� 3 �������� 3, 4, 9 � 14. ������� ������ ���������
� �������� ���������� ����� ���� �������� � �� �������. �������������
��� ������� � ������� ������� ���������.
*/
void sumArrArr(double ar1[], double ar2[], double ar3[],int n);
int Exsample10(void)
{
    int i, beg, end;
    char ch;
    double arr1[10] = {1.,2.,3.,4.,5.,6.,7.,8.,9.,10.};
    double arr2[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.99};
    double arrSum[10];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ����� ���� ��������.\033[0m\n");
    do
    {
        prDblArr1(arr1, 10, 5, "�������� ������1:");
        prDblArr1(arr2, 10, 5, "�������� ������2:");
        sumArrArr(arr1, arr2, arrSum, 10);
        prDblArr1(arrSum, 10, 5, "����� ���� ��������:");
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
void sumArrArr(double ar1[], double ar2[], double ar3[], int n) {
    for (int i = 0; i < n; i++)
    {
        ar3[i] = ar1[i] + ar2[i];
    }
}/*
 11. �������� ���������, ������� ��������� ������ 3�5 �������� ���� int � ��������������
��� ���������� �� ������ ������. ��������� ������ ������� ���
��������, ������� ��� ��������, ����� ���� ������� ����� ��������. ��������
���� ������� ��� ������ �������� � ��� ���� ��� ���������� ��������. � ��������
���������� ������� ������ ��������� ��� ������� � ����������
�����.
*/
void dubleArr2(int arr[][5], int n,int m);
void initArr2(int arr[][5], int n, int m);
void prIntArr2(int arr[][5], int n, int m, int k, char* title);

int Exsample11(void)
{
    int i, beg, end;
    char ch;
    int test[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 11. ������ 3�5 �������� ���� int ������� ��� ��������.\033[0m\n");
    do
    {
        initArr2(test, 3,5);
        prIntArr2(test,3,5,3,"�������� ������� 3*5:");
        dubleArr2( test, 3, 5);
        prIntArr2(test,3,5,3,"����������� ������� 3*5:");
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
void prIntArr2(int arr[][5], int n, int m, int k, char* title) {
    bool end=false;
    if (strlen(title) > 0)printf("%s\n", title);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            end = false;
            (n < 100) ? printf("arr[%2d,%2d] = %d \t", i,j, arr[i][j]) :
                printf("arr[%3d,%3d] = %d \t", i,j, arr[i][j]);
            if ((j + 1) % k == 0) {
                printf("\n");
                end=true;
            }
        }
        if(!end) printf("\n");
    }
    printf("\n");

}
void initArr2(int arr[][5], int n,int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i][j] = (i + 1)*100 + (j+1) * 10;
}
void dubleArr2(int arr[][5], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            arr[i][j] *= 2;
}
/*
12. ���������� ��������� rain.� �� �������� 10.7 ���, ����� �������� ������
�������� ������ �������, � �� � ���� main().
*/
int rainF(void);
int Exsample12(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 12. ���������� ��������� rain.� �� �������� 10.7.\033[0m\n");
    do
    {
        rainF();
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
// ������� 10.7. ��������� rain.c
/* rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������
�������� �� ����� �� ������ �� ������� �� ��������� ��� */
#include <stdio.h>
#define MONTHS107 12	// ���������� ������� � ����
#define YEARS107 5		// ���������� ���, ��� ������� �������� ������
void funcRain(float arr[][MONTHS107], int n, int m);
int rainF(void)
{
    // ������������� ������� �� ������� �� ������ � 2010 �� 2014 ��.
    const float rain[YEARS107][MONTHS107] =
    {
        { 4.3,4.3, 4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5, 8.2, 1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };
    funcRain(rain, YEARS107, MONTHS107);
    return 0;
}
void funcRain(float arr[][MONTHS107],int n,int m){
    int year, month;
    float subtot, total;
    printf("\n\033[1;4;44m������� 10.7.���������  rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������.\033[0m\n");
    printf("��� ���������� ������� (� ������)\n");
    for (year = 0, total = 0; year < n; year++)
    { // ��� ������� ���� ����������� ���������� ������� �� ������ �����
        for (month = 0, subtot = 0; month < n; month++)
            subtot += arr[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;				// ����� ����� ��� ���� ���
    }
    printf("\n������������� ���������� ������� ���������� %.1f ������. \n\n", total / n);
    printf("�������������� ���������� �������:\n\n");
    printf(" ��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t���");
    printf(" \t��� \t���\n");
    for (month = 0; month < m; month++)
    { // ��� ������� ������ ����������� ���������� ������� �� ���������� �����
        for (year = 0, subtot = 0; year < n; year++)
            subtot += arr[year][month];
        printf("%4.1f\t", subtot / n);
    }
    printf("\n\n");
}
/*
13. �������� ���������, ������� ���������� ������������ ������ ��� ������ ��
    ���� ����� double. (��� �������� ������ ��������, ��� ������������ ��������
    ��������� � �� ������ ���������� ������.) ��������� ������ ��������� ���
    ������������� ���� ��������.
    �. ������� ���������� � ������� 3�5.
    �. ��������� ������� ��� ������� ������ �� ���� ��������.
    �. ��������� ������� ��� ���� ��������.
    �. ���������� ���������� �� 15 ��������.
    �. �������� ���������� �� �����.
    ������ ������������ ������ ������ �������� ����������� ��������� �������
    � �������������� ������������� � ����� � ������� � ��������� ��������. �� �������
    ������ �) � ������� �������, ������� ��������� � ���������� �������
    �������� ����������� �������; �������������� ������ ��� ������ ���� �������
    ��� ����. �������, ����������� ��������� ������, ������ ��������� �
    �������� ��������� ������ �������, � �������, ����������� ������ �) � �),
    ������ ���������� ����� � ���������� ���������.
*/
void inputArr2(double arr[][5], int n, int m);
int menu1013(void);
int getNum(char* title, int min, int max);
double middleStl(double arr[][5], int n, int m, int idx);
double middleStr(double arr[][5], int n, int m, int idx);
double middle(double arr[][5], int n, int m);
maxArr(double arr[][5], int n, int m);
minArr(double arr[][5], int n, int m);
bool checkArr(bool yes);

int Exsample13(void)
{
    int i, beg, end,func;
    char ch;
    double calcArr[3][5] = { { [0] = 0 }, { [0] = 0}, { [0] = 0} };
    double midStlF,midStrF,midF,minF,maxF;
    bool arrYes = false;

    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 13. ���� � ��������� ������� 3*5.\033[0m\n");
    do
    {
        while ((func = menu1013()) < 8) {
            switch (func) {
            case 1:         // ���� �������
                inputArr2(calcArr, 3, 5);
                arrYes = true;
                break;
            case 2:         // ����� �������
                if (!checkArr( arrYes)) break;
                prDblArr2(calcArr, 3, 5, 5, "���������� �������:");
                break;
            case 3:         // ������� �������
                if (!checkArr( arrYes)) break;
                i = getNum("������� ����� �������(1-5):", 1, 5);
                midStlF=middleStl(calcArr,3,5,i-1);
                printf("������� �������� ������� %d = %lf\n", i, midStlF);
                break;
            case 4:         // ������� ������
                if (!checkArr(arrYes)) break;
                i = getNum("������� ����� ������(1-3):", 1, 3);
                midStrF=middleStr(calcArr,3,5,i-1);
                printf("������� �������� ������ %d = %lf\n", i, midStrF);
                    break;
            case 5:         // ������� �������
                if (!checkArr(arrYes)) break;
                midF = middle(calcArr, 3, 5);
                printf("������� �������� ������� = %lf\n", midF);
                break;
            case 6:         // ��������
                if (!checkArr(arrYes)) break;
                maxF = maxArr(calcArr, 3, 5);
                printf("������������ �������� ������� = %lf\n", maxF);
                break;
            case 7:         // �������
                minF = minArr(calcArr, 3, 5);
                printf("����������� �������� ������� = %lf\n", minF);
                if (!checkArr(arrYes)) break;
                    break;
            case 8:         // �����
                break;
            default:
                break;
            }
        }
        printf("\n��� �����?(y/n ��� �/�):");
        ch=getch();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("\033[31m������!\033[0m �����(y/n �/�):");
            ch = getch();
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
bool checkArr(bool yes) {
    if (!yes) {
        printf("\033[31m������!\033[0m ������ ��� �� �����.\n");
    }
    return yes;
}
maxArr(double arr[][5], int n, int m) {
    double max = arr[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(max< arr[i][j]) max = arr[i][j];
    return max;
}
minArr(double arr[][5], int n, int m) {
    double min = arr[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (min > arr[i][j]) min = arr[i][j];
    return min;
}
double middle(double arr[][5], int n, int m) {
    double sum = 0;
    for (int i = 0; i < n; i++) 
        for(int j=0;j<m;j++)
            sum += arr[i][j];
    return sum / (n * m);
}
double middleStr(double arr[][5], int n, int m, int idx) {
    double sum = 0;
    for (int i = 0; i <m; i++) sum += arr[idx][i];
    return sum / m;
}
double middleStl(double arr[][5], int n, int m, int idx) {
    double sum=0;
    for (int i = 0; i < n; i++) sum += arr[i][idx];
    return sum / n;
}

int getNum(char* title, int min, int max) {
    char ch;
    int num;
    if (strlen(title) > 0) printf("%s",title);
    in:
    if (max < 10) {
        ch = getch();
        num = ch - '0';
    }
    else scanf_s("%d", &num);
    if (num<min || num>max) {
        printf(" \033[31m������!\033[0m ����� ������ ����� �� %d �� %d.\n",min,max);
        goto in;
    }
    printf("\n");
    return num;
}
void inputArr2(double arr[][5], int n, int m) {
    int status;
    printf("���� ������� %d-����� � %d-��������.\n");
    for (int i = 0; i < n; i++) {
        printf("������� %d-�� ������ �� %d ����� double:\n"INPUT3,i+1, m);
        for (int j = 0; j < m; j++) {
            do {
                printf("(%d):", j + 1);
                status = scanf_s("%lf",&arr[i][j]);
            } while (status != 1);
        }
    }
    getchar();      // ������� '\n'
    printf("\n");
}
int menu1013(void) {
    int n,status;
    char ch;
    bool err=false;
    printf("����������� �������:\n");
    do {
        printf("\033[32m1\033[0m.���� ������� 3*5\n");
        printf("\033[32m2\033[0m.����� ������� 3*5\n");
        printf("\033[32m3\033[0m.������� �������\n");
        printf("\033[32m4\033[0m.������� ������\n");
        printf("\033[32m5\033[0m.������� �������\n");
        printf("\033[32m6\033[0m.��������\n");
        printf("\033[32m7\033[0m.�������\n");
        printf("\033[32m8\033[0m.�����\n");
        printf("������� ����� �������(1-7):");
        ch = getch();
        n = ch - '0';
        err = !(n > 0 && n < 9);
        if (err) printf(" \033[31m������!\033[0m ����� ������ ����� �� 1 �� 8.\n");
    } while (err);
    printf("\n");
    return n;
}