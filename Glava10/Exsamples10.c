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
/*                // Шаблон задачи

* /

int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
    do
    {

        printf("\nЕщё разок?(y/n или д/н):");
        ch=getch();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
            ch = getch();
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
/*                // Шаблон задачи

* /

int Exsample10(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
    do
    {

        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}

*/
/*
1. Модифицируйте программу rain. с из листинга 10.7, чтобы она выполняла вычисления
с использованием указателей вместо индексов. 
(Вам по-прежнему придется объявлять и инициализировать массив.)
*/
int rain10(void);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
    do
    {
        rain10();
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}

// Листинг 10.7. Программа rain.c
/* rain.c -- находит суммарные данные по годам, средние значения за год и средние
значения за месяц по данным об осадках за несколько лет */
#include <stdio.h>
#include <stdbool.h>
#define MONTHS107 12	// количество месяцев в году
#define YEARS107 5		// количество лет, для которых доступны данные
int rain10(void)
{
    // инициализация данными об осадках за период с 2010 по 2014 гг.
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
    printf("\n\033[1;4;44mЛистинг 10.7.Программа  rain.c -- находит суммарные данные по годам, средние значения за год и средние.\033[0m\n");
    printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
    for (year = 0, total = 0; year < YEARS107; year++)
    { // для каждого года суммировать количество осадков за каждый месяц
        //for (int i = 0; i < 12; i++) prain[year][i]= {  }
        for (month = 0, subtot = 0; month < MONTHS107; month++)
            subtot += *(*(prain+year)+month);              // subtot += prain[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;				// общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов. \n\n", total / YEARS107);
    printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв \tФев \tМар \tАпр \tМай \tИюн \tИюл \tАвг \tСен \tОкт");
    printf(" \tНоя \tДек\n");
    for (month = 0; month < MONTHS107; month++)
    { // для каждого месяца суммировать количество осадков на протяжении годов
        for (year = 0, subtot = 0; year < YEARS107; year++)
            subtot +=*(*(prain+year)+month);
        printf("%4.1f\t", subtot / YEARS107);
    }
    printf("\n\n");
    return 0;
}
/*
    2. Напишите программу, которая инициализирует массив значений типа double
        и затем копирует его содержимое в три других массива. 
        (Все четыре массива должны быть объявлены в главной программе.) 
        Для создания первой копии воспользуйтесь функцией, в которой применяется форма записи с массивами.
        Для создания второй копии используйте функцию, в которой применяется форма
        записи с указателями и инкрементирование указателей. Первые две функции
        должны принимать в качестве аргументов имя целевого массива, имя исходного
        массива и количество элементов, подлежащих копированию. Третья функция
        должна принимать в качестве аргументов имя целевого массива, имя исходного
        массива и указатель на элемент, следующий за последним элементом в исходном
        массиве. С учетом приведенных ниже объявлений вызовы функций должны выглядеть так:
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
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. инициализирует массив значений типа double и копирует его в три массива.\033[0m\n");
    do
    {
        prDblArr1(source, 50, 5, "Оригинал:");
        copy_arr102(target1, source, 50);
        prDblArr1(target1, 50,5, "Копия 1:");
        copy_ptr102(target2, source, 50);
        prDblArr1(target2, 50, 5, "Копия 2:");
        copy_ptrs102(target3, source, source + 50);
        prDblArr1(target3, 50,5, "Копия 3:");

        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
3. Напишите функцию, которая возвращает наибольшее значение в массиве значений типа int. 
Протестируйте эту функцию с помощью простой программы.
*/
int min103( const int arr[], int n);
int Exsample3(void)
{
    int i, max, end,len;
    char ch;
    int testArr[] = {-1,-2,-3,-4,-5,6,-7,-8,-9,-10};
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 3. возвращает наибольшее значение в массиве значений типа int.\033[0m\n");
    do
    {
        len = sizeof(testArr) / sizeof( int);
        prIntArr1(testArr, len, 3, "Найти max в массиве:");
        max=max103(testArr,len);
        printf("Максимум = %d\n", max);
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
int max103(const int arr[], int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) max = arr[i];
    }return max;
}
/*
4. Напишите функцию, которая возвращает индекс наибольшего значения в массиве
значений типа double. Протестируйте эту функцию с помощью простой программы.
*/
int imaxDblArr(int n, const double* test );
int Exsample4(void)
{
    int i, beg, imax;
    char ch;
    const double test[12] = {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6};

    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 4. возвращает индекс наибольшего значения в массиве типа double.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "Найти индекс макимального элемента в массиве:");
        imax = imaxDblArr(12,test);
        printf("Индекс=%d\n", imax);
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
5. Напишите функцию, которая возвращает разность между наибольшим и наименьшим 
элементами в массиве значений типа double. Протестируйте эту функцию с помощью простой программы.
*/
int iminDblArr(int n, const double* test);
int Exsample5(void)
{
    int i, imin, imax;
    char ch;
    const double test[12] = { 4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6 };
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 5. разность между max и min элементами в массиве double.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "Найти разность макимального и минимального элемента в массиве:");
        imax = imaxDblArr(12, test);
        imin = iminDblArr(12, test);
        printf("Разность=[%d]-[%d]=%lf\n", imax,imin,test[imax]-test[imin]);

        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
6. Напишите функцию, которая изменяет порядок следования содержимого массива
значений типа double на противоположный и протестируйте ее в простой программе.
*/
void revert6(double* arr,int n);
int Exsample6(void)
{
    int i, beg, end;
    char ch;
    const double test[12] = { 1.3, 2.3, 3.3, 4.0, 5.0, 6.2, 7.2, 8.2, 9.4,10.4,11.5, 12.6 };
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 6. изменяет порядок содержимого массива double на противоположный.\033[0m\n");
    do
    {
        prDblArr1(test, 12, 5, "Массив до изменения:");
        revert6( test,  12);
        prDblArr1(test, 12, 5, "Массив после изменения порядка:");
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
7. Напишите программу, которая инициализирует двумерный массив значений
типа double и использует одну из функций копирования из упражнения 2 для
его копирования во второй двумерный массив. (Поскольку двумерный массив -
это массив массивов, функция для копирования одномерных массивов может
применятся с каждым подмассивом.)
*/
void prDblArr2(double arr[][5], int n, int m, int k, char* title);
int Exsample7(void)
{
    int i, beg, end;
    char ch;
    double source[3][5] = { {1.,2.,3.,4.,5.},{10.,20.,30.,40.,50.},{100.,200.,300.,400.,500.} };
    double target[3][5] = {0};
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 7. инициализирует двумерный массив double и использует одну из функций копирования из упражнения 2.\033[0m\n");
    do
    {
        for (int i = 0; i < 3; i++)prDblArr1(source[i], 3, 5, (i==0)?"Исходный массив:":"");
        for (int i = 0; i < 3; i++)
        {
            copy_arr102(target[i], source[i], 5);
        }
        for (int i = 0; i < 3; i++)prDblArr1(target[i], 3, 5, (i==0)?"Результирующий:":"");
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
8. Воспользуйтесь одной из функций копирования из упражнения 2 для копирования
элементов с 3-го по 5-й семиэлементного массива в массив, состоящий из
трех элементов. Саму функцию изменять не нужно; просто подберите правильные
фактические аргументы. (Фактическими аргументами не обязательно должны
быть имя массива и его размер. Ими только должны быть адрес элемента
массива и количество обрабатываемых элементов.)
*/

int Exsample8(void)
{
    int i, beg, end;
    char ch;
    double source[7] = { 1.,2.,3.,4.,5.,6.,7. };
    double target[3];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 8. копирование элементов с 3-го по 5-й семиэлементного массива в массив, состоящий из 3-х.\033[0m\n");
    do
    {
        prDblArr1(source, 7, 3, "Исходный массив:");
        copy_arr102(target, source+2, 3);
        prDblArr1(target, 3, 3, "Результат переписи 3-5 элементов:");
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
/*
9. Напишите программу, которая инициализирует двумерный массив 3х5 значений
типа double и использует функцию, основанную на массивах переменной
длины, для копирования этого массива во второй двумерный массив. Кроме
того, напишите функцию, основанную на массивах переменной длины, для отображения
содержимого этих двух массивов. В общем случае обе функции должны
быть способны обрабатывать произвольные массивы NхМ. (Если вы не имеете
доступа к компилятору, подлерживающему массивы переменной длины, примените
традиционный подход С с функциями, которые могут обрабатывать массивы Nx5).
*/

int Exsample9(void)
{
    int i, beg, end;
    char ch;
    double source[3][5] = { {1.,2.,3.,4.,5.},{10.,20.,30.,40.,50.},{1.1,2.2,3.3,4.4,5.5}};
    double target[3][5];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 9. Копирование массива double[3][5].\033[0m\n");
    do
    {
        for (int i = 0; i < 3; i++)prDblArr1(source[i], 3, 5, (i == 0) ? "Исходный массив:" : "");
        for (int i = 0; i < 3; i++)
        {
            copy_arr102(target[i], source[i], 5);
        }
        for (int i = 0; i < 3; i++)prDblArr1(target[i], 3, 5, (i == 0) ? "Результирующий:" : "");

        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
/*
10. Напишите функцию, которая устанавливает значение каждого элемента массива
в сумму соответствующих элементов в двух других массивах. Другими словами,
если массив 1 имеет значения 2, 4, 5 и 8, а массив 2 — значения 1, 0, 4 и 6, то эта
функция присваивает массиву 3 значения 3, 4, 9 и 14. Функция должна принимать
в качестве аргументов имена трех массивов и их размеры. Протестируйте
эту функцию с помощью простой программы.
*/
void sumArrArr(double ar1[], double ar2[], double ar3[],int n);
int Exsample10(void)
{
    int i, beg, end;
    char ch;
    double arr1[10] = {1.,2.,3.,4.,5.,6.,7.,8.,9.,10.};
    double arr2[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.99};
    double arrSum[10];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. Сумма двух массивов.\033[0m\n");
    do
    {
        prDblArr1(arr1, 10, 5, "Исходный массив1:");
        prDblArr1(arr2, 10, 5, "Исходный массив2:");
        sumArrArr(arr1, arr2, arrSum, 10);
        prDblArr1(arrSum, 10, 5, "Сумма двух массивов:");
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
void sumArrArr(double ar1[], double ar2[], double ar3[], int n) {
    for (int i = 0; i < n; i++)
    {
        ar3[i] = ar1[i] + ar2[i];
    }
}/*
 11. Напишите программу, которая объявляет массив 3х5 значений типа int и инициализирует
его значениями по вашему выбору. Программа должна вывести эти
значения, удвоить все значения, после чего вывести новые значения. Напишите
одну функцию для вывода значений и еще одну для удваивания значений. В качестве
аргументов функции должны принимать имя массива и количество
строк.
*/
void dubleArr2(int arr[][5], int n,int m);
void initArr2(int arr[][5], int n, int m);
void prIntArr2(int arr[][5], int n, int m, int k, char* title);

int Exsample11(void)
{
    int i, beg, end;
    char ch;
    int test[3][5] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15} };
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 11. массив 3х5 значений типа int удвоить все значения.\033[0m\n");
    do
    {
        initArr2(test, 3,5);
        prIntArr2(test,3,5,3,"Исходная матрица 3*5:");
        dubleArr2( test, 3, 5);
        prIntArr2(test,3,5,3,"Увеличенная матрица 3*5:");
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
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
12. Перепишите программу rain.с из листинга 10.7 так, чтобы основные задачи
решались внутри функций, а не в теле main().
*/
int rainF(void);
int Exsample12(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 12. Перепишите программу rain.с из листинга 10.7.\033[0m\n");
    do
    {
        rainF();
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
// Листинг 10.7. Программа rain.c
/* rain.c -- находит суммарные данные по годам, средние значения за год и средние
значения за месяц по данным об осадках за несколько лет */
#include <stdio.h>
#define MONTHS107 12	// количество месяцев в году
#define YEARS107 5		// количество лет, для которых доступны данные
void funcRain(float arr[][MONTHS107], int n, int m);
int rainF(void)
{
    // инициализация данными об осадках за период с 2010 по 2014 гг.
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
    printf("\n\033[1;4;44mЛистинг 10.7.Программа  rain.c -- находит суммарные данные по годам, средние значения за год и средние.\033[0m\n");
    printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
    for (year = 0, total = 0; year < n; year++)
    { // для каждого года суммировать количество осадков за каждый месяц
        for (month = 0, subtot = 0; month < n; month++)
            subtot += arr[year][month];
        printf("%5d %15.1f\n", 2010 + year, subtot);
        total += subtot;				// общая сумма для всех лет
    }
    printf("\nСреднегодовое количество осадков составляет %.1f дюймов. \n\n", total / n);
    printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
    printf(" Янв \tФев \tМар \tАпр \tМай \tИюн \tИюл \tАвг \tСен \tОкт");
    printf(" \tНоя \tДек\n");
    for (month = 0; month < m; month++)
    { // для каждого месяца суммировать количество осадков на протяжении годов
        for (year = 0, subtot = 0; year < n; year++)
            subtot += arr[year][month];
        printf("%4.1f\t", subtot / n);
    }
    printf("\n\n");
}
/*
13. Напишите программу, которая предлагает пользователю ввести три набора по
    пять чисел double. (Для простоты можете полагать, что пользователь отвечает
    корректно и не вводит нечисловые данные.) Программа должна выполнять все
    перечисленные ниже действия.
    а. Хранить информацию в массиве 3х5.
    б. Вычислять среднее для каждого набора из пяти значений.
    в. Вычислять среднее для всех значений.
    г. Определять наибольшее из 15 значений.
    д. Выводить результаты на экран.
    Каждая значительная задача должна решаться посредством отдельной функции
    с использованием традиционного в языке С подхода к обработке массивов. Вы полните
    задачу б) с помощью функции, которая вычисляет и возвращает среднее
    значение одномерного массива; воспользуйтесь циклом для вызова этой функции
    три раза. Функции, реализующие остальные задачи, должны принимать в
    качестве аргумента массив целиком, а функции, выполняющие задачи в) и г),
    должны возвращать ответ в вызывающую программу.
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

    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 13. Ввод и обработка массива 3*5.\033[0m\n");
    do
    {
        while ((func = menu1013()) < 8) {
            switch (func) {
            case 1:         // Ввод массива
                inputArr2(calcArr, 3, 5);
                arrYes = true;
                break;
            case 2:         // Вывод массива
                if (!checkArr( arrYes)) break;
                prDblArr2(calcArr, 3, 5, 5, "Содержимое массива:");
                break;
            case 3:         // Среднее столбца
                if (!checkArr( arrYes)) break;
                i = getNum("Введите номер столбца(1-5):", 1, 5);
                midStlF=middleStl(calcArr,3,5,i-1);
                printf("Среднее значение столбца %d = %lf\n", i, midStlF);
                break;
            case 4:         // Среднее строки
                if (!checkArr(arrYes)) break;
                i = getNum("Введите номер строки(1-3):", 1, 3);
                midStrF=middleStr(calcArr,3,5,i-1);
                printf("Среднее значение строки %d = %lf\n", i, midStrF);
                    break;
            case 5:         // Среднее массива
                if (!checkArr(arrYes)) break;
                midF = middle(calcArr, 3, 5);
                printf("Среднее значение массива = %lf\n", midF);
                break;
            case 6:         // Максимум
                if (!checkArr(arrYes)) break;
                maxF = maxArr(calcArr, 3, 5);
                printf("Максимальное значение массива = %lf\n", maxF);
                break;
            case 7:         // Минимум
                minF = minArr(calcArr, 3, 5);
                printf("Минимальное значение массива = %lf\n", minF);
                if (!checkArr(arrYes)) break;
                    break;
            case 8:         // Конец
                break;
            default:
                break;
            }
        }
        printf("\nЕщё разок?(y/n или д/н):");
        ch=getch();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
            ch = getch();
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
bool checkArr(bool yes) {
    if (!yes) {
        printf("\033[31mОшибка!\033[0m Массив ещё не введён.\n");
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
        printf(" \033[31mОшибка!\033[0m Нужно ввести цифру от %d до %d.\n",min,max);
        goto in;
    }
    printf("\n");
    return num;
}
void inputArr2(double arr[][5], int n, int m) {
    int status;
    printf("Ввод массива %d-строк и %d-столбцов.\n");
    for (int i = 0; i < n; i++) {
        printf("Введите %d-ую строку из %d чисел double:\n"INPUT3,i+1, m);
        for (int j = 0; j < m; j++) {
            do {
                printf("(%d):", j + 1);
                status = scanf_s("%lf",&arr[i][j]);
            } while (status != 1);
        }
    }
    getchar();      // пропуск '\n'
    printf("\n");
}
int menu1013(void) {
    int n,status;
    char ch;
    bool err=false;
    printf("Выполняемые функции:\n");
    do {
        printf("\033[32m1\033[0m.Ввод массива 3*5\n");
        printf("\033[32m2\033[0m.Вывод массива 3*5\n");
        printf("\033[32m3\033[0m.Среднее столбца\n");
        printf("\033[32m4\033[0m.Среднее строки\n");
        printf("\033[32m5\033[0m.Среднее массива\n");
        printf("\033[32m6\033[0m.Максимум\n");
        printf("\033[32m7\033[0m.Минимум\n");
        printf("\033[32m8\033[0m.Конец\n");
        printf("Введите номер функции(1-7):");
        ch = getch();
        n = ch - '0';
        err = !(n > 0 && n < 9);
        if (err) printf(" \033[31mОшибка!\033[0m Нужно ввести цифру от 1 до 8.\n");
    } while (err);
    printf("\n");
    return n;
}