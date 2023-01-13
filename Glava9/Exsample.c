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
1. �������� ������� �� ����� rmin (�, �), ������� ���������� ������� �� ����
�������� double. ������������� ��� ������� � ������� �������� ��������.
*/
double rmin(double x, double y);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    double x, y;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 1. rmin (�, �), ������� ���������� ������� �� ���� �������� double.\033[0m\n");
    do
    {
        printf("������� ��� �������������� �����:"INPUT3);
        if (scanf_s("%lf %lf", &x, &y) == 2) {
            printf("�������(%f,%f) = %f.\n",x,y,rmin(x,y));
        }
        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            //scanf_s("%*s");
            ch = getchar();
            if (ch == '\n') break;
            //getchar();          // ���������� \n �� ������
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
double rmin(double x, double y) {
    return (x > y) ? y : x;
}
/*
2. �������� ������� �� ����� chline (ch, i, j ), ������� ������� ���������
������ � �������� � i �� j. ������������� ��� ������� � ������� �������� ��������.
*/

int Exsample2(void)
{
    int i, beg, end, status;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. chline (ch, i, j ) ������� ��������� ������ � �������� � i �� j.\033[0m\n");
    do
    {
        printf("������� ������ � ������� ������ � �����:"INPUT3);
        status = scanf_s("%c %d %d", &ch, 1, &beg, &end);
        if (status == 3) {
            if (end < beg) { i = beg; beg = end; end = i; }
                for (i = 0; i < beg - 1; i++)
                    printf(" ");
                for (i = 0; i < end-beg+1; i++)
                    printf("%c", ch);
        }
        printf("\n");
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c",&ch,1); 
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
/*
3. �������� �������, ������� ��������� ��� ���������: ������ � ��� ����� �����.
������ ������������ ��� ������. ������ ����� �������� ������ ����������
��������� �������� � ������, � ������ ����� ����� ������������� ����������
����� �����. �������� ���������, � ������� ������������ ��� �������.
*/
void fill(char ch, int l, int n);
int Exsample3(void)
{
    int i, len, num;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 3. ������� ������� ������ m ����� ������� n.\033[0m\n");
    do
    {
        printf("������� ������, ����� ������, ����� �����:"INPUT3);
        if (scanf_s("%c %d %d",&ch,1,&len,&num)==3){
            fill(ch, len, num);
        }
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
void fill(char ch,int l,int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < l; j++)
            printf("%c", ch);
        printf("\n");
    }
}
/*
4. ������� ������������� �������� ���� ����� ���������� ����� ��������������
���� �����, ���������� �������� �������� �������� � ��������� �������� ����������.
�������� �������, ������� ��������� ��� ��������� double � ����������
������� ������������� �������� ���� ���� �����.{\displaystyle {\frac {n}{H}}={\frac {1}{x_{1}}}+\ldots +{\frac {1}{x_{n}}}}.
*/
double harm(int n, double* y);
#define MAX_NUM 100
int Exsample4(void)
{
    int i, n, status;
    char ch;
    double x, y,arr[100],h;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 4. ������� ������������� �������� n �����.\033[0m\n");
    do
    {
        printf("������� ����������� �����(�� ������ %d):"INPUT3, MAX_NUM);
        while (scanf_s("%d",&n)!=1 || n> MAX_NUM){        }
        for (i = 0; i < n; i++) {
            printf("%d �����:"INPUT3,i+1);
            do {
                status = scanf_s("%lf", &arr[i]);
            } while (status != 1);
        }
        h = harm(n, arr);
        printf("������� ������������� %d �������� �����=%lf", n, h);
        /*
        printf("������ ��� �������������� �����(������� ����� ���������� �������):"INPUT3);
        if (scanf_s("%lf %lf", &x, &y) == 2) {
            printf("������� �������������(%lf,%lf)=%lf", x, y, harm(x, y));
        }
        */
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
double harm(int n,double* x) {
    int i;
    double h=0;
    for (i = 0; i < n; i++) h += 1. / x[i];
    return n / h;
}
/*
5. �������� � ������������� ������� �� ����� larger_of () , ������� ��������
���������� ���� ���������� double ������� �� �� ��������. ��������, �����
larger_of (�, �) �������� ���������� � � � ������� �� �� ��������.
*/
double larger_of(double* x, double* y);
int Exsample5(void)
{
    int i, beg, status;
    char ch;
    double x, y,x0,y0;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 5. larger_of (�, �) �������� ���������� ���� ���������� double ������� �� �� ��������.\033[0m\n");
    do
    {
        printf("������� ��� �������������� �����:"INPUT3);
        while ((status = scanf_s("%lf %lf", &x, &y)) != 2) { printf("������!"); scanf_s("%*s"); }
        x0 = x;
        y0 = y;
        printf("������������( %lf,%lf)= %lf", x0, y0, larger_of(&x, &y));
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
double larger_of(double* x, double* y) {
    if (*x > *y) *y = *x;
    else *x = *y;
    return *x;
}
/*
6. �������� � ������������� �������, ������� ��������� � �������� ����������
������ ���� ���������� double � �������� ���������� �������� � ������ ����������,
������� �������� � �� ������, � ���������� �������� � � ������.
*/
void calcul6(double* x1,double* x2,double* x3);
int Exsample6(void)
{
    int i, beg, status;
    char ch;
    double x1, x2, x3,x01,x02,x03;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 6. ������� ��������� min max midl �� 3-� ����������,\n"
                         "           ��������� �������� � ��.����������.\033[0m\n");
    do
    {
        printf("������� 3 �������������� �����:"INPUT3);
        while((status=scanf_s("%lf %lf %lf",&x1,&x2,&x3))!=3){ printf("������!"); scanf_s("%*s"); }
        x01 = x1; x02 = x2; x03 = x3;
        calcul6(&x1, &x2, &x3);
        printf("MIN(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x1);
        printf("MINDL(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x2);
        printf("MAX(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x3);
        printf("\n��� �����?(y/n ��� �/�):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
void calcul6(double* x1, double* x2, double* x3) {
    double tMin,tMid,tMax;
    tMax = max(max(*x1, *x2), *x3);
    tMin = min(min(*x1, *x2), *x3);
    tMid = (*x1 + *x2 + *x3) / 3.;
    *x1 = tMin;
    *x2 = tMid;
    *x3 = tMax;
}
/*
7. �������� ���������, ������� ������ ������� �� ������������ ����� ������
�� ����� �����. ��� ������� ������� ��������� ������ ��������, ��������
�� �� ������. ���� ������ � �����, ��������� �������� ������ �������� ��
���������� ����� � ��������. ��������, ����� � � � ����� ����� ����� 3.
������������� � ��������� �������, ������� ��������� ������ � ��������
��������� � ���������� ��� ���������� ����� � ��������, ���� �� ��������
������, � -1 � ��������� ������.
*/
int numberCh(char ch);
int Exsample7(void)
{
    int i, beg, end,n;
    char ch,ch1;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 7.������ ������� �� ������������ ����� ������ �� ����� �����.\n"
                         "          ��� ������� ������� ��������� �����-������ ������-�����.\n"
                         "          ������� ���������� ����� ����� � ��� ������.\033[0m\n");
    do
    {
        printf("������� �����(����� - F6 ��� ^Z):"INPUT3);
        while ((ch = getchar()) != EOF) {
            if((n=numberCh(ch)) > 0)
                printf("\033[32m%c-%d \033[0m",ch, n);
            else if(n>-10)
                printf("\033[31m %d \033[0m",-n);
            else
                printf("\033[33;47;44m(%d)\033[0m",ch);
        }
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        ch1=getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("������! �����(y/n �/�):");
            ch = getchar();
            getchar();      // ������� '\n'
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
int numberCh(char ch) {
    if (isalpha(tolower(ch))) return ch - 'a'+1;
    if (isdigit(ch)) 
        return -(ch-'0'); // �����
    else return -100;
}
/*
8. � ����� 6 ���� �������� ������� power() (������� 6.20), ������� ����������
��������� ���������� ����� double � ������������� ����� �������.
���������������� ��� �������, ����� ��� ��������� ��������� ����� � �������������
�������. ����� ����, �������� � ������� ����������� ������ ��� 0
���������� ���������� 0 � ����� ������� ����� 0 � ������ ��� 1 ����������
���������� ������ ����� � ������� 0. (������� ������ ��������, ��� ���������
���������� 0 � ������� 0 �� ��������� � ��� ��� ���������� �������� 1.)
��������� ����. ������������� ������� � �����-������ ���������.
*/
/*
9. ��� ��� ��������� ���������� 8, �� �� ���� ��� ����������� ����������� �������.
*/
double power8(double n, int �);
double power9(double n, int p);
int Exsample8(void)
{
    double x, xpow;
    int exp, status;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 8. ������� power().\033[0m\n");
    do
    {
        printf("������� ����� � ������������� ����� �������,");
        printf(" � �������\n����� ����� ���������. ��� ���������� ���������");
        printf(" ������� q:___ __\b\b\b\b\b\b");
        while ((status=scanf_s("%lf %d", &x, &exp)) == 2)
        {
            if (x == 0 && exp == 0) { printf("0 � ������� 0 ������������!\n"); 
                printf("������� ��������� ���� ����� ��� q ��� ����������:___ __\b\b\b\b\b\b");
                continue; 
            }
            if (x == 0) {
                printf("0 � ����� ������� = 0!\n");
                printf("������� ��������� ���� ����� ��� q ��� ����������:___ __\b\b\b\b\b\b");
                continue;
            }
            if (exp == 0) {
                printf("����� �����>0 � ������� 0 = 1.\n");
                printf("������� ��������� ���� ����� ��� q ��� ����������:___ __\b\b\b\b\b\b");
                continue;
            }
            xpow = power8(x, exp);		// ����� �������
            printf("�������� � �����.    %.3g � ������� %d ����� %.5g\n", x, exp, xpow);
            xpow = power9(x, exp);		// ����� �������
            printf("�������� ����������. %.3g � ������� %d ����� %.5g\n", x, exp, xpow);
            printf("������� ��������� ���� ����� ��� q ��� ����������:___ __\b\b\b\b\b\b");
        }
        if (status == 0) break;
        printf("\n��� �����?(y/n ��� �/�):");
        //ch1=getchar();
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
double power8(double n, int p)	// ����������� �������
{
    double pow = 1;
    int i;
    if (p == 0) return 1.;
    if (n == 0) return 0.;
    for (i = 1; i <= p; i++)
        pow *= n;
    return pow;					// ���������� �������� pow
}
double power9(double x, int n)	// ����������� �������
{
    if (n == 1) return x;
    return x * power9(x, --n);
}
/*
10. �������� ������� to_binary() �� �������� 9.8 �� ������� to_base_n() , �������
��������� ������ �������� � ��������� �� 2 �� 10. ��� ������ ��������
�����, ���������� � ������ ���������, � ������� ��������� � ����������, �������
������� �� ������ ���������. ��������, ����� to_base_n(129,8) ������
���������� 201, �.�. ������������ ���������� ����� 129. ������������� �������
������� � �����-������ ���������.
*/
void to_base_n(unsigned long long n, int base);
int Exsample10(void)
{
    int i, base, status;
    unsigned long long num;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ����������� ������� ������ ����� � �������� ������� ���������.\033[0m\n");
    do
    {
        printf("������� ����� � ������� ���������(<17) � ������� ��� ����� �������:"INPUT3);
        while ((status = scanf_s("%llu %d",&num,&base))==2) {
            if (base > 16) {
                printf("������! ��������� ��������� ������� ������, ����� <17.\n");
            }
            else if (num >= ULLONG_MAX) {
                printf("������! ������� ������� �����. ����� <%llu.\n", ULLONG_MAX);
            }
            else {
                printf("%llu � %d-������� = ", num, base);
                to_base_n(num, base);
                printf("\n");
            }
            printf("������� ����� � ������� ���������(<17) � ������� ��� ����� �������:"INPUT3);
        }
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
void to_base_n(unsigned long long n,int base) /* ����������� ������� */
{
    unsigned long long r;
    r = n % base;
    if (n >= base)
        to_base_n(n / base,base);
    printf("%x",r);
    return;
}
/*
11. �������� � ������������� ������� Fibonacci(), � ������� ��� ����������
����� ��������� ������ �������� ����������� ����.
*/
unsigned long long Fibonacci11(unsigned long long n);
int Exsample11(void)
{
    int i, status, end;
    char ch;
    unsigned int n;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 11. ���������� ����� ���������  ������.\033[0m\n");
    do
    {
        printf("������� ����� ����� ���������(<94):"INPUT3);
        while ((status = scanf_s("%u", &n)) == 1) {
            if (n < 94) {
                printf("%llu-� ����� =%llu.\n", n, Fibonacci11(n));
            }
            else
                printf("\033[5;31m������!\033[0m ��������� �� ����� ��������� ����� ������� ����� ���������, �� ������ 93-���.\n");
            printf("������� ����� ����� ���������:"INPUT3);
        }
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
unsigned long long Fibonacci11(unsigned long long n) 
{
    unsigned long long fibn=1,fibn_1=1,i,temp;
    if (n < 3) return 1;
    for (i = 2; i < n; i++) {
        temp = fibn;
        fibn += fibn_1;
        fibn_1 = temp;
    }
    return fibn;
}