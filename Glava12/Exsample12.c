#include "string.h"
#include <Windows.h >
#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
#include <stdbool.h>
#include <ctype.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
/*
���������� �� ���������������� ����� 12.
*/
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
1. ���������� ��������� �� �������� 12.4 ���, ����� � ��� �� ��������������
���������� ����������.
*/
int global12(void);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 1. ���������� ��������� �� �������� 12.4 ���, ����� � ��� �� �������������� ���������� ����������.\033[0m\n");
    do
    {
        global12();
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
int critic12(void);
int global12(void)
{
    int units; /* �������������� ��������� ���������� */
    printf("������� ������ ����� ��������� ������� �����?^");
    scanf_s("%d", &units);
    while (units != 56)
        units=critic12();
    printf("�� ����� ���!\n");
    return 0;
}
int critic12(void)
{
    int units;
    printf("��� �� �������. ���������� ��� ���.\n");
    scanf_s("%d", &units);
    return units;
}
/*
2. ������ ������� ������ ���������� � ����� �� ���� ������ � C�� � � ������
�� 100 ���������� � ������. ���� ��������� ����� ���������, ������� ����������
������������ ������� ����� (����������� ��� ������������), � �����
��������� ���� ������ � ��������� ������ �������:
// ��12-2�.�
// ������������� ������ � ��12-2�.�
*/
int pe12_2b(void);

int Exsample2(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. ������ �������.\033[0m\n");
    do
    {
        pe12_2b();
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
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
#include <stdio.h>
#include "pe12-2a.h"
int pe12_2b(void)
{
    int mode;
    printf("������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������(-1 ��� ����������):"INPUT1);
    scanf_s("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������(-1 ��� ����������):"INPUT1);
        scanf_s("%d", &mode);
    }
    printf("��������� ���������.\n");
    return 0;
}

/*
3. ����������� ���������, ��������� � ���������� 2, ����� � ��� ��������������
������ �������������� ����������. ���������� � ��������� ��� �� �����
���������������� ���������, �.�. ��� ������ ���������� ������������ ������
����� � �.�. ������ � ��� ����� ������ ����� ������� �������.
*/
int pe12_3b(void);

int Exsample3(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. ������ �������.\033[0m\n");
    do
    {
        pe12_3b();
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c", &ch, 1);
        if (ch == '\n') continue;
        getchar();
        while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�' || ch == '\n');
    printf("\n����� ���������\n");
    return 0;
}
#include <stdio.h>
#include "pe12-3a.h"
int pe12_3b(void)
{
    int mode,oldmode=0;
    double info[2]; // [0]=leng, [1]=fuel;
    printf("������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������(-1 ��� ����������):"INPUT1);
    scanf_s("%d", &mode);
    while (mode >= 0)
    {
        oldmode=mode=set_mode1(mode, oldmode);
        get_info1(mode, info);
        show_info1(mode, info);
        printf("������� 0 ��� ������������ ������ ��� 1 ��� ������������� ������(-1 ��� ����������):"INPUT1);
        scanf_s("%d", &mode);
    }
    printf("��������� ���������.\n");
    return 0;
}
/*
4. ������� � � ������������� � ����� �������, ������� ���������� ����������
�� �������.
*/
int getcounts(void);
int Exsample4(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 4. ������� � � ������������� � ����� �������, ������� ���������� ���������� �� �������\033[0m\n");
    do
    {
        printf("������� ����� �������(0< � <%d):"INPUT3, INT_MAX);
        scanf_s("%d", &i);
        getchar();
        if (i > 0) {
            for (int k = 0; k < i - 1; k++) {
                getcounts();
            }
            printf("������� ������� %d ���.\n", getcounts());
        }
        else printf("\033[41;30m������!\033[0m ����� �������� �����.\n");
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
int getcounts(void) {
    static int counts=0;
    return ++counts;
}
/*
5. �������� ���������, ������� ���������� ������ �� 100 ��������� ����� �
��������� �� 1 �� 10, ��������������� �� ��������. (������ ������������
� ���� int �������� ���������� �� ����� 11, ������ � ���� ������ ����������
���� �����.)
*/
int randomarr(int* arr, int n, int min, int max);
int randomsrt(int* arr, int n, bool up);
void randomout(int* arr, int n, int max);
#define LINE_NUM 8              // ����� ��������� ��������� � ������
#define MAX_RAND 1000000        // �������� �����
#define MAX_ARR 1000            // �������� ����������� �����

int Exsample5(void)
{
    int status, randomsort[MAX_ARR]={1,2,3,4,5,6,7,8,9,10,11,123,2223334,1234}, min, max, n;
    char ch;
    bool up = true;             // ���������� �� �����������, false - �� ��������
    int iup;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 5. ������ �� �� ������ 999 ��������� ����� �� 1 �� %d.\033[0m\n", RAND_MAX-1);
    do
    {
        printf("������� n(>1 <%d)-����� ����� ��������� �����, ���, ����(<%d) � ����������� ����������(<=0 ��������,>0 �����������), ����� ������:"INPUT2, MAX_ARR, RAND_MAX);
        if ((status=scanf_s("%d %d %d %d", &n, &min, &max,&iup)) != 4 || n < 1 || n >= MAX_ARR || min >= max || max>= RAND_MAX) {
            printf("\033[41;30m������!\033[0m ����� �������� �����.");
            if (n < 1)              printf("n ������ ���� ������ 1.");
            if (n >= MAX_ARR)       printf("n ������ ���� ������ %d.", MAX_ARR);
            if (min >= max)         printf("min ������ ���� ������ max.");
            if (max >= RAND_MAX)    printf("max ������ ���� ������ %d.", RAND_MAX);
            if (status != 4)        printf("����� ������ 4 ����� n min max ������ ����� ������.");
            printf("\n");
        }
        else {
            up = iup > 0;
            randomarr(randomsort, n,min,max);
            randomsrt(randomsort, n, up);
            randomout(randomsort, n, max);
        }
        getchar();
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
int randomarr(int* arr, int n,int min,int max) {
    srand(time(0));
    for (int i=0; i < n; i++) {
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}
int compareup(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}
int comparedown(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}
int randomsrt(int* arr, int n, bool up) {
    if(up) qsort(arr, n, sizeof(int), compareup);
    else   qsort(arr, n, sizeof(int), comparedown);

}
void randomout(int* arr, int n, int max) {
    int ls=0,space=0;
    char str[100];
    for (int k = 0; k < n; k++) {
        if(n<10)
            ls=sprintf_s(str,100, "[%d]:%d" , k, arr[k]);
        else if(n<100)
            ls = sprintf_s(str,100, "[%2d]:%d", k, arr[k]);
        else if(n<1000)
            ls = sprintf_s(str, 100, "[%3d]:%d", k, arr[k]);
        else if(n<10000)
            ls = sprintf_s(str, 100, "[%4d]:%d", k, arr[k]);
        else if(n<100000)
            ls = sprintf_s(str, 100, "[%5d]:%d", k, arr[k]);
        else if(n<1000000)
            ls = sprintf_s(str, 100, "[%5d]:%d", k, arr[k]);
        space = 100 / LINE_NUM - ls;
        if (space < 1) space = 1;
        printf("%s", str);
        for (int i = 0; i < space; i++) printf(" ");
        if (!((k + 1) % LINE_NUM)) printf("\n");
    }
}
/*
6. �������� ���������, ������� ���������� 1000 ��������� ����� � ��������� ��
1 �� 10. �� ���������� � �� �������� ��� �����, � �������� ���� ��, ������� ���
�������������� ������ �����. ��������� ������ ������ ��� ��� 10 ������ ���������
��������. ���������� �� ����� � ���������� �����������? ������ ������������
������� �� ���� ����� ��� ������� rand() � srand() �� ANSI �, �������
������� ���� �� �������, ��� � ������������� �����. ��� ���� �� �������� ������������
��������������������� ����������� ���������� ��������� �����.
*/
int randcount(int* arr, int n, int min, int max);
void randout(int* arr, int n, int max);
int Exsample6(void)
{
    int n, min, max, status, rndcount[RAND_MAX] = { 0 };
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 6. ������� ���������� ��������� ����� � ��������� ������������������.\033[0m\n");
    do
    {
        printf("������� n(>1 <%d)-����� ����� ��������� �����, ���, ����(<%d), ����� ������:"INPUT2, MAX_ARR, RAND_MAX);
        if ((status = scanf_s("%d %d %d", &n, &min, &max)) != 3 || n < 1 || n >= MAX_ARR || min >= max || max >= RAND_MAX) {
            printf("\033[41;30m������!\033[0m ����� �������� �����.");
            if (n < 1)              printf("n ������ ���� ������ 1.");
            if (n >= MAX_ARR)       printf("n ������ ���� ������ %d.", MAX_ARR);
            if (min >= max)         printf("min ������ ���� ������ max.");
            if (max >= RAND_MAX)    printf("max ������ ���� ������ %d.", RAND_MAX);
            if (status != 3)        printf("����� ������ 4 ����� n min max ������ ����� ������.");
            printf("\n");
        }
        else {
            randcount(rndcount, n, min, max);
            randout(rndcount, n, max);
        }
        getchar();
        for (int i = 0; i < MAX_ARR; i++) rndcount[i] = 0;
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
int randcount(int* arr, int n, int min, int max) {
    int idx;
    srand(time(0));
    for (int i = 0; i < n; i++) {
        idx = (rand() % (max - min + 1)) + min;
        arr[idx]++;
    }
}
void randout(int* arr, int n, int max) {
    int ls = 0, space = 0,arrmax=0,nsero=0;
    char str[100];
    for (int i = 0; i < max; i++)
        arrmax=max(arrmax,arr[i]); 
    for (int k = 0; k < max; k++) {
        if (arr[k] != 0) {
            if (n < 10)
                ls = sprintf_s(str, 100, "[%d]:%d", k, arr[k]);
            else if (n < 100)
                ls = sprintf_s(str, 100, "[%2d]:%d", k, arr[k]);
            else if (n < 1000)
                ls = sprintf_s(str, 100, "[%3d]:%d", k, arr[k]);
            else if (n < 10000)
                ls = sprintf_s(str, 100, "[%4d]:%d", k, arr[k]);
            else if (n < 100000)
                ls = sprintf_s(str, 100, "[%5d]:%d", k, arr[k]);
            else if (n < 1000000)
                ls = sprintf_s(str, 100, "[%5d]:%d", k, arr[k]);
            space = 100 / LINE_NUM - ls;
            if (space < 1) space = 1;
            printf("%s", str);
            for (int i = 0; i < space; i++) printf(" ");
            if (!(++nsero % LINE_NUM)) printf("\n");
        }
    }
    printf("\n");
}
/*
7. �������� ���������, ������� ����� ���� ������� ����������� �������� 12.13,
������� ����������� ����� ������������� ������ �� ���������, ���������� �
�������� 12.13. �� ���� ��������� ������ ������ ����� ���������� ����:
������� ���������� �������� ��� q ��� ����������: 18
������� ������ � ������� ������? � 3
����� 18 �������� 3 ������ � 6 �������.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
������� ���������� �������� ��� q ��� ����������: q.
*/

int Exsample7(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 7. ���� � �����.\033[0m\n");
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
/*
8. ���� ��������� ����� ���������:
// ��12-8.�
��������� ���������, ����������� ����������� ������� make_array() �
show_array(). ������� make_array() ��������� ��� ���������. ������ ��������-
��� ���������� ��������� � ������� �������� int, � ������ �������� � ��������,
������� ������ ���� ��������� ������� �������� �������. ��� �������
���������� malloc() ��� �������� ������� ����������� �������, �����������
������� �������� �������� �������� � ���������� ��������� �� ������. �������
show_array() ���������� ���������� ������� �� ������ ��������� � ������.
*/
int ��12_8(void);
int Exsample8(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 8.��12-8.� ������� ��������� � ����� � ��������� ���������.\033[0m\n");
    do
    {
        ��12_8();
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
#include <stdio.h>
int* make_array(int size, int value);
void show_array(const int ar[], int n);
int ��12_8(void)
{
    int* pa;
    int size;
    int value;
    printf("������� ���������� ���������:");
    while (scanf_s("%d", &size) == 1 && size > 0) {
        printf("������� �������� ��� �������������:");
        scanf_s("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("B�e���e ���������� ��������� (<1 ��� ����������):");
    }
    printf("��������� ���������.\n");
    return 0;
}
int* make_array(int size, int value) {
    int* arr;
    arr = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = value++;
    return arr;
}
void show_array(const int ar[], int n) {
    randout(ar, n, n);
}
/*
9. �������� ��������� �� ��������� ����������. ������� ��� ����������� ����������
����, ������� ����� ������. ����� ��� ���������� ������ �����, ����� ���� �� ����������.
�������������� malloc() � ������� �� ������ ������ (���������� ����), 
����� ������� ������������ ������ � ���������� ����������� ���������� �� char. 
(�������� ��������, ��� ��������� ������ ������� � �������
�������� ���������� �� char, ������������ �������� ������� malloc()
������ ����������� � ��������� �� ��������� �� char.)
��� ������ ������ ��������� ������ ������ ����� �� ��������� ������ ��������� char, 
� ������� malloc() �������� ������������, ����������� ��� �������� �����, � ��������
����� � ������ ���������� �� char. ����� ��������� ������ ���������� �����
�� ���������� ������� � ���������� ������������ ������. ����� �������, �
����� ��������� ������ ���������� �� char, ������ �� ������� ��������� ��
������ � ��������, ����������� ��� �������� ����������� �����. ����������
�������� ������� ������ ��������� ��������� �������:
������� ���� �� ������ ������? 5
������ ������� 5 ����:
��� ����������� ��������� ��� ����������
��� ��������� ���� �����:
���
�����������
���������
���
����������
*/
void wodrsarray(void);
void wordsout(char** ppw, int n);
int Exsample9(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 9. ������ ���� � ���������� �� ���.\033[0m\n");
    do
    {
        wodrsarray();
        getchar();
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
#define MAXWRDS 100         // ���� ����� ����
#define MAXLWRD 20          // ���� ����� �����
void wodrsarray(void) {
    int nwords,l,status;
    char** pwords;
    char word[21];
    bool ok = false;
    do {
        ok = true;
        printf("����������� ����(<100):"INPUT3);
        scanf_s("%d", &nwords);
        if (nwords<1 || nwords>MAXWRDS) {
            printf("\033[41;30m������!\033[0m ����� ���� �.� <%d � >1.\n", MAXWRDS);
            ok = false;
        }
    } while (!ok);
    pwords = (char**)malloc(nwords * sizeof(char*));
    printf("������� %d ����(��� Enter �������� ����).\n:"INPUT3, nwords);
    for (int i = 0; i < nwords; i++) {
        word[0] = '\0';
        status = scanf_s("%s", word,20);
        l = strlen(word);
        if (status >0 &&  l> 0) {
            pwords[i] = (char*)malloc(l+20);
            strcpy_s(pwords[i],l+10, word);
        }
        else {
            nwords = i;
            break;
        }
    }
    wordsout(pwords, nwords);
    for (int i = 0; i < nwords; i++) free(pwords[i]);
    free(pwords);
}
void wordsout(char** ppw,int n) {
    printf("��� ��������� ���� �����:\n");
    for (int i = 0; i < n; i++)
        printf("%d:%s\n", i + 1, ppw[i]);
}
/*
Approach 2  (Recursive Solution):   
The idea is to traverse over the array recursively and find the maximum element.
Below is the code for the mentioned approach:
*/
int largestRecursive(int arr[], int n, int i);
int largestSimple(int arr[], int n);
int ExsampleSort(void)
{
    int i, beg, end;
    char ch;
    int arr[] = { 10, 324, 45, 90, 9808 };
    int n = sizeof(arr) / sizeof(arr[0]);
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� Sort. ����� � �������.\033[0m\n");
    do
    {
        printf("Recursive Solution. Largest in given array is %d.\n",largestRecursive(arr, n, 0));
        printf("One of the most simplest Solution. Largest in given array is %d.\n", largestSimple(arr, n));
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
One of the most simplest and basic approaches to solving this problem
is to simply traverse the whole list and find the maximum among them.
*/
int largestSimple(int arr[], int n){
    int i, max = arr[0];// Initialize maximum element
    for (i = 1; i < n; i++)// Traverse array elements from second and compare every element with current max
        if (arr[i] > max)  max = arr[i];
    return max;
}
/*
Approach 2  (Recursive Solution):   
The idea is to traverse over the array recursively and find the maximum element.
*/
int largestRecursive(int arr[], int n, int i){
    if (i == n - 1)  return arr[i];         // last index return the element
    int recMax = largestRecursive(arr, n, i + 1);    // find the maximum from rest of the array
    return max(recMax, arr[i]);             // compare with i-th element and return
}
