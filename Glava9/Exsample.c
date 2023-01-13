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
1. Напишите функцию по имени rmin (х, у), которая возвращает меньшее из двух
значений double. Протестируйте эту функцию с помощью простого драйвера.
*/
double rmin(double x, double y);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    double x, y;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 1. rmin (х, у), которая возвращает меньшее из двух значений double.\033[0m\n");
    do
    {
        printf("Введите два действительных числа:"INPUT3);
        if (scanf_s("%lf %lf", &x, &y) == 2) {
            printf("Минимум(%f,%f) = %f.\n",x,y,rmin(x,y));
        }
        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            //scanf_s("%*s");
            ch = getchar();
            if (ch == '\n') break;
            //getchar();          // Пропустить \n от ответа
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
double rmin(double x, double y) {
    return (x > y) ? y : x;
}
/*
2. Напишите функцию по имени chline (ch, i, j ), которая выводит требуемый
символ в столбцах с i по j. Протестируйте эту функцию с помощью простого драйвера.
*/

int Exsample2(void)
{
    int i, beg, end, status;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. chline (ch, i, j ) выводит требуемый символ в столбцах с i по j.\033[0m\n");
    do
    {
        printf("Введите символ и позиции начала и конца:"INPUT3);
        status = scanf_s("%c %d %d", &ch, 1, &beg, &end);
        if (status == 3) {
            if (end < beg) { i = beg; beg = end; end = i; }
                for (i = 0; i < beg - 1; i++)
                    printf(" ");
                for (i = 0; i < end-beg+1; i++)
                    printf("%c", ch);
        }
        printf("\n");
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
        scanf_s("%c",&ch,1); 
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
/*
3. Напишите функцию, которая принимает три аргумента: символ и два целых числа.
Символ предназначен для вывода. Первое целое значение задает количество
указанных символов в строке, а второе целое число устанавливает количество
таких строк. Напишите программу, в которой используется эта функция.
*/
void fill(char ch, int l, int n);
int Exsample3(void)
{
    int i, len, num;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 3. Функция выводит символ m строк длинной n.\033[0m\n");
    do
    {
        printf("Введите символ, длину строки, число строк:"INPUT3);
        if (scanf_s("%c %d %d",&ch,1,&len,&num)==3){
            fill(ch, len, num);
        }
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
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
4. Среднее гармоническое значение двух чисел получается путем инвертирования
этих чисел, вычисления среднего значения инверсий и получения инверсии результата.
Напишите функцию, которая принимает два аргумента double и возвращает
среднее гармоническое значение этих двух чисел.{\displaystyle {\frac {n}{H}}={\frac {1}{x_{1}}}+\ldots +{\frac {1}{x_{n}}}}.
*/
double harm(int n, double* y);
#define MAX_NUM 100
int Exsample4(void)
{
    int i, n, status;
    char ch;
    double x, y,arr[100],h;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 4. Среднее гармоническое значение n чисел.\033[0m\n");
    do
    {
        printf("Введите колличество чисел(не больше %d):"INPUT3, MAX_NUM);
        while (scanf_s("%d",&n)!=1 || n> MAX_NUM){        }
        for (i = 0; i < n; i++) {
            printf("%d число:"INPUT3,i+1);
            do {
                status = scanf_s("%lf", &arr[i]);
            } while (status != 1);
        }
        h = harm(n, arr);
        printf("Среднее гармоническое %d введённых чисел=%lf", n, h);
        /*
        printf("Ведите два действительных числа(дробная часть отделяется запятой):"INPUT3);
        if (scanf_s("%lf %lf", &x, &y) == 2) {
            printf("Среднее гармоническое(%lf,%lf)=%lf", x, y, harm(x, y));
        }
        */
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
double harm(int n,double* x) {
    int i;
    double h=0;
    for (i = 0; i < n; i++) h += 1. / x[i];
    return n / h;
}
/*
5. Напишите и протестируйте функцию по имени larger_of () , которая заменяет
содержимое двух переменных double большим из их значений. Например, вызов
larger_of (х, у) присвоит переменным х и у большее из их значений.
*/
double larger_of(double* x, double* y);
int Exsample5(void)
{
    int i, beg, status;
    char ch;
    double x, y,x0,y0;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 5. larger_of (х, у) заменяет содержимое двух переменных double большим из их значений.\033[0m\n");
    do
    {
        printf("Введите два действительных числа:"INPUT3);
        while ((status = scanf_s("%lf %lf", &x, &y)) != 2) { printf("Ошибка!"); scanf_s("%*s"); }
        x0 = x;
        y0 = y;
        printf("Максимальное( %lf,%lf)= %lf", x0, y0, larger_of(&x, &y));
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
double larger_of(double* x, double* y) {
    if (*x > *y) *y = *x;
    else *x = *y;
    return *x;
}
/*
6. Напишите и протестируйте функцию, которая принимает в качестве аргументов
адреса трех переменных double и помещает наименьшее значение в первую переменную,
среднее значение — во вторую, а наибольшее значение — в третью.
*/
void calcul6(double* x1,double* x2,double* x3);
int Exsample6(void)
{
    int i, beg, status;
    char ch;
    double x1, x2, x3,x01,x02,x03;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 6. Функция вычисляет min max midl от 3-х переменных,\n"
                         "           результат помещает в вх.переменные.\033[0m\n");
    do
    {
        printf("Введите 3 действительных числа:"INPUT3);
        while((status=scanf_s("%lf %lf %lf",&x1,&x2,&x3))!=3){ printf("Ошибка!"); scanf_s("%*s"); }
        x01 = x1; x02 = x2; x03 = x3;
        calcul6(&x1, &x2, &x3);
        printf("MIN(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x1);
        printf("MINDL(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x2);
        printf("MAX(%lf,%lf,%lf)=%lf\n", x01, x02, x03, x3);
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
        scanf_s("%c",&ch,1);
        getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            if (ch == '\n') break;
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
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
7. Напишите программу, которая читает символы из стандартного ввода вплоть
до конца файла. Для каждого символа программа должна сообщать, является
ли он буквой. Если символ — буква, программа вдобавок должна сообщать ее
порядковый номер в алфавите. Например, буквы с и С будут иметь номер 3.
Предусмотрите в программе функцию, которая принимает символ в качестве
аргумента и возвращает его порядковый номер в алфавите, если он является
буквой, и -1 в противном случае.
*/
int numberCh(char ch);
int Exsample7(void)
{
    int i, beg, end,n;
    char ch,ch1;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 7.читает символы из стандартного ввода вплоть до конца файла.\n"
                         "          Для каждого символа программа буквы-зелёные прочие-синие.\n"
                         "          выводит порядковый номер буквы и код прочих.\033[0m\n");
    do
    {
        printf("Введите текст(конец - F6 или ^Z):"INPUT3);
        while ((ch = getchar()) != EOF) {
            if((n=numberCh(ch)) > 0)
                printf("\033[32m%c-%d \033[0m",ch, n);
            else if(n>-10)
                printf("\033[31m %d \033[0m",-n);
            else
                printf("\033[33;47;44m(%d)\033[0m",ch);
        }
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c",&ch,1);
        if (ch == '\n') continue;
        ch1=getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
int numberCh(char ch) {
    if (isalpha(tolower(ch))) return ch - 'a'+1;
    if (isdigit(ch)) 
        return -(ch-'0'); // цифра
    else return -100;
}
/*
8. В главе 6 была показана функция power() (листинг 6.20), которая возвращает
результат возведения числа double в положительную целую степень.
Усовершенствуйте эту функцию, чтобы она корректно возводила числа в отрицательные
степени. Кроме того, добавьте в функцию возможность оценки как 0
результата возведения 0 в любую степень кроме 0 и оценки как 1 результата
возведения любого числа в степень 0. (Функция должна сообщать, что результат
возведения 0 в степень 0 не определен и что она использует значение 1.)
Примените цикл. Протестируйте функцию в какой-нибудь программе.
*/
/*
9. Еще раз выполните упражнение 8, но на этот раз используйте рекурсивную функцию.
*/
double power8(double n, int р);
double power9(double n, int p);
int Exsample8(void)
{
    double x, xpow;
    int exp, status;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 8. функция power().\033[0m\n");
    do
    {
        printf("Введите число и положительную целую степень,");
        printf(" в которую\nчисло будет возведено. Для завершения программы");
        printf(" введите q:___ __\b\b\b\b\b\b");
        while ((status=scanf_s("%lf %d", &x, &exp)) == 2)
        {
            if (x == 0 && exp == 0) { printf("0 в степени 0 неопределено!\n"); 
                printf("Введите следующую пару чисел или q для завершения:___ __\b\b\b\b\b\b");
                continue; 
            }
            if (x == 0) {
                printf("0 в любой степени = 0!\n");
                printf("Введите следующую пару чисел или q для завершения:___ __\b\b\b\b\b\b");
                continue;
            }
            if (exp == 0) {
                printf("любое число>0 в степени 0 = 1.\n");
                printf("Введите следующую пару чисел или q для завершения:___ __\b\b\b\b\b\b");
                continue;
            }
            xpow = power8(x, exp);		// вызов функции
            printf("Вычисляя в цикле.    %.3g в степени %d равно %.5g\n", x, exp, xpow);
            xpow = power9(x, exp);		// вызов функции
            printf("Вычисляя рекурсивно. %.3g в степени %d равно %.5g\n", x, exp, xpow);
            printf("Введите следующую пару чисел или q для завершения:___ __\b\b\b\b\b\b");
        }
        if (status == 0) break;
        printf("\nЕщё разок?(y/n или д/н):");
        //ch1=getchar();
        scanf_s("%c", &ch, 1);
        if (ch == '\n') continue;
        getchar();
        while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("Ошибка! Нужно(y/n д/н):");
            ch = getchar();
            getchar();      // пропуск '\n'
        }
    } while (ch == 'y' || ch == 'д' || ch == '\n');
    printf("\nКонец программы\n");
    return 0;
}
double power8(double n, int p)	// определение функции
{
    double pow = 1;
    int i;
    if (p == 0) return 1.;
    if (n == 0) return 0.;
    for (i = 1; i <= p; i++)
        pow *= n;
    return pow;					// возвратить значение pow
}
double power9(double x, int n)	// определение функции
{
    if (n == 1) return x;
    return x * power9(x, --n);
}
/*
10. Обобщите функцию to_binary() из листинга 9.8 до функции to_base_n() , которая
принимает второй аргумент в диапазоне от 2 до 10. Она должна выводить
число, переданное в первом аргументе, в системе счисления с основанием, которое
указано во втором аргументе. Например, вызов to_base_n(129,8) должен
отобразить 201, т.е. восьмеричный эквивалент числа 129. Протестируйте готовую
функцию в какой-нибудь программе.
*/
void to_base_n(unsigned long long n, int base);
int Exsample10(void)
{
    int i, base, status;
    unsigned long long num;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. Рекурсивная функция вывода числа в заданной системе счисления.\033[0m\n");
    do
    {
        printf("Введите число и систему счисления(<17) в которой его нужно вывести:"INPUT3);
        while ((status = scanf_s("%llu %d",&num,&base))==2) {
            if (base > 16) {
                printf("Ошибка! Основание счисления слишком велико, нужно <17.\n");
            }
            else if (num >= ULLONG_MAX) {
                printf("Ошибка! Слишком большое число. Нужно <%llu.\n", ULLONG_MAX);
            }
            else {
                printf("%llu в %d-системе = ", num, base);
                to_base_n(num, base);
                printf("\n");
            }
            printf("Введите число и систему счисления(<17) в которой его нужно вывести:"INPUT3);
        }
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
void to_base_n(unsigned long long n,int base) /* рекурсивная функция */
{
    unsigned long long r;
    r = n % base;
    if (n >= base)
        to_base_n(n / base,base);
    printf("%x",r);
    return;
}
/*
11. Напишите и протестируйте функцию Fibonacci(), в которой для вычисления
чисел Фибоначчи вместо рекурсии применяется цикл.
*/
unsigned long long Fibonacci11(unsigned long long n);
int Exsample11(void)
{
    int i, status, end;
    char ch;
    unsigned int n;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 11. Вычисление чисел Фибоначчи  циклом.\033[0m\n");
    do
    {
        printf("Введите номер числа Фибоначчи(<94):"INPUT3);
        while ((status = scanf_s("%u", &n)) == 1) {
            if (n < 94) {
                printf("%llu-е число =%llu.\n", n, Fibonacci11(n));
            }
            else
                printf("\033[5;31mОшибка!\033[0m Программа не может вычислить такое большое число Фибоначчи, не больше 93-его.\n");
            printf("Введите номер числа Фибоначчи:"INPUT3);
        }
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