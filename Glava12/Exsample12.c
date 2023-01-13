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
Упражнения по программированию Глава 12.
*/
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
1. Перепишите программу из листинга 12.4 так, чтобы в ней не использовались
глобальные переменные.
*/
int global12(void);
int Exsample1(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 1. Перепишите программу из листинга 12.4 так, чтобы в ней не использовались глобальные переменные.\033[0m\n");
    do
    {
        global12();
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
int critic12(void);
int global12(void)
{
    int units; /* необязательное повторное объявление */
    printf("Сколько фунтов весит маленький бочонок масла?^");
    scanf_s("%d", &units);
    while (units != 56)
        units=critic12();
    printf("Вы знали это!\n");
    return 0;
}
int critic12(void)
{
    int units;
    printf("Вам не повезло. Попробуйте еще раз.\n");
    scanf_s("%d", &units);
    return units;
}
/*
2. Расход бензина обычно измеряется в милях на один галлон в CША и в литрах
на 100 километров в Европе. Ниже приведена часть программы, которая предлагает
пользователю выбрать режим (метрический или американский), а затем
выполняет сбор данных и вычисляет расход топлива:
// ре12-2Ь.с
// компилировать вместе с ре12-2а.с
*/
int pe12_2b(void);

int Exsample2(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. Расход бензина.\033[0m\n");
    do
    {
        pe12_2b();
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
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
#include <stdio.h>
#include "pe12-2a.h"
int pe12_2b(void)
{
    int mode;
    printf("Введите 0 для метрического режима или 1 для американского режима(-1 для завершения):"INPUT1);
    scanf_s("%d", &mode);
    while (mode >= 0)
    {
        set_mode(mode);
        get_info();
        show_info();
        printf("Введите 0 для метрического режима или 1 для американского режима(-1 для завершения):"INPUT1);
        scanf_s("%d", &mode);
    }
    printf("Программа завершена.\n");
    return 0;
}

/*
3. Переделайте программу, описанную в упражнении 2, чтобы в ней использовались
только автоматические переменные. Обеспечьте в программе тот же самый
пользовательский интерфейс, т.е. она должна предлагать пользователю ввести
режим и т.д. Однако у вас будет другой набор вызовов функций.
*/
int pe12_3b(void);

int Exsample3(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. Расход бензина.\033[0m\n");
    do
    {
        pe12_3b();
        printf("\nЕщё разок?(y/n или д/н):");
        getchar();
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
#include <stdio.h>
#include "pe12-3a.h"
int pe12_3b(void)
{
    int mode,oldmode=0;
    double info[2]; // [0]=leng, [1]=fuel;
    printf("Введите 0 для метрического режима или 1 для американского режима(-1 для завершения):"INPUT1);
    scanf_s("%d", &mode);
    while (mode >= 0)
    {
        oldmode=mode=set_mode1(mode, oldmode);
        get_info1(mode, info);
        show_info1(mode, info);
        printf("Введите 0 для метрического режима или 1 для американского режима(-1 для завершения):"INPUT1);
        scanf_s("%d", &mode);
    }
    printf("Программа завершена.\n");
    return 0;
}
/*
4. Напишит е и протестируйте в цикле функцию, которая возвращает количество
ее вызовов.
*/
int getcounts(void);
int Exsample4(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 4. Напишит е и протестируйте в цикле функцию, которая возвращает количество ее вызовов\033[0m\n");
    do
    {
        printf("Введите число вызовов(0< и <%d):"INPUT3, INT_MAX);
        scanf_s("%d", &i);
        getchar();
        if (i > 0) {
            for (int k = 0; k < i - 1; k++) {
                getcounts();
            }
            printf("Функция вызвана %d раз.\n", getcounts());
        }
        else printf("\033[41;30mОшибка!\033[0m Ввели неверное число.\n");
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
int getcounts(void) {
    static int counts=0;
    return ++counts;
}
/*
5. Напишите программу, которая генерирует список из 100 случайных чисел в
диапазоне от 1 до 10, отсортированный по убыванию. (Можете приспособить
к типу int алгоритм сортировки из главы 11, только в этом случае сортируйте
сами числа.)
*/
int randomarr(int* arr, int n, int min, int max);
int randomsrt(int* arr, int n, bool up);
void randomout(int* arr, int n, int max);
#define LINE_NUM 8              // число выводимых элементов в строке
#define MAX_RAND 1000000        // максимум числа
#define MAX_ARR 1000            // максимум колличества чисел

int Exsample5(void)
{
    int status, randomsort[MAX_ARR]={1,2,3,4,5,6,7,8,9,10,11,123,2223334,1234}, min, max, n;
    char ch;
    bool up = true;             // сортировка по возрастанию, false - по убыванию
    int iup;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 5. список из не больше 999 случайных чисел от 1 до %d.\033[0m\n", RAND_MAX-1);
    do
    {
        printf("Введите n(>1 <%d)-число целых случайных чисел, мин, макс(<%d) и направление сортировки(<=0 убывание,>0 возрастание), через пробел:"INPUT2, MAX_ARR, RAND_MAX);
        if ((status=scanf_s("%d %d %d %d", &n, &min, &max,&iup)) != 4 || n < 1 || n >= MAX_ARR || min >= max || max>= RAND_MAX) {
            printf("\033[41;30mОшибка!\033[0m Ввели неверные числа.");
            if (n < 1)              printf("n должно быть больше 1.");
            if (n >= MAX_ARR)       printf("n должно быть меньше %d.", MAX_ARR);
            if (min >= max)         printf("min должен быть меньше max.");
            if (max >= RAND_MAX)    printf("max должен быть меньше %d.", RAND_MAX);
            if (status != 4)        printf("Нужно ввести 4 числа n min max сортир через пробел.");
            printf("\n");
        }
        else {
            up = iup > 0;
            randomarr(randomsort, n,min,max);
            randomsrt(randomsort, n, up);
            randomout(randomsort, n, max);
        }
        getchar();
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
6. Напишите программу, которая генерирует 1000 случайных чисел в диапазоне от
1 до 10. Не сохраняйте и не выводите эти числа, а выводите лишь то, сколько раз
генерировалось каждое число. Программа должна делать это для 10 разных начальных
значений. Появляются ли числа в одинаковых количествах? Можете использовать
функции из этой главы или функции rand() и srand() из ANSI С, которые
следуют тому же формату, что и рассмотренные здесь. Это один из способов исследования
недетерминированности конкретного генератора случайных чисел.
*/
int randcount(int* arr, int n, int min, int max);
void randout(int* arr, int n, int max);
int Exsample6(void)
{
    int n, min, max, status, rndcount[RAND_MAX] = { 0 };
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 6. Подсчёт количества появлений числа в случайной последовательности.\033[0m\n");
    do
    {
        printf("Введите n(>1 <%d)-число целых случайных чисел, мин, макс(<%d), через пробел:"INPUT2, MAX_ARR, RAND_MAX);
        if ((status = scanf_s("%d %d %d", &n, &min, &max)) != 3 || n < 1 || n >= MAX_ARR || min >= max || max >= RAND_MAX) {
            printf("\033[41;30mОшибка!\033[0m Ввели неверные числа.");
            if (n < 1)              printf("n должно быть больше 1.");
            if (n >= MAX_ARR)       printf("n должно быть меньше %d.", MAX_ARR);
            if (min >= max)         printf("min должен быть меньше max.");
            if (max >= RAND_MAX)    printf("max должен быть меньше %d.", RAND_MAX);
            if (status != 3)        printf("Нужно ввести 4 числа n min max сортир через пробел.");
            printf("\n");
        }
        else {
            randcount(rndcount, n, min, max);
            randout(rndcount, n, max);
        }
        getchar();
        for (int i = 0; i < MAX_ARR; i++) rndcount[i] = 0;
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
7. Напишите программу, которая ведет себя подобно модификации листинга 12.13,
которая обсуждалась после представления вывода из программы, показанной в
листинге 12.13. То есть программа должна давать вывод следующего вида:
Введите количество бросаний или q для завершения: 18
Сколько граней и сколько костей? б 3
Имеем 18 бросаний 3 костей с 6 гранями.
12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
Введите количество бросаний или q для завершения: q.
*/

int Exsample7(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 7. Игра в кости.\033[0m\n");
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
/*
8. Ниже приведена часть программы:
// ре12-8.с
Завершите программу, предоставив определения функций make_array() и
show_array(). Функция make_array() принимает два аргумента. Первый аргумент-
это количество элементов в массиве значений int, а второй аргумент — значение,
которое должно быть присвоено каждому элементу массива. Эта функция
использует malloc() для создания массива подходящего размера, присваивает
каждому элементу заданное значение и возвращает указатель на массив. Функция
show_array() отображает содержимое массива по восемь элементов в строке.
*/
int ре12_8(void);
int Exsample8(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 8.ре12-8.с таблица квадратов и кубов с введёнными границами.\033[0m\n");
    do
    {
        ре12_8();
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
#include <stdio.h>
int* make_array(int size, int value);
void show_array(const int ar[], int n);
int ре12_8(void)
{
    int* pa;
    int size;
    int value;
    printf("Введите количество элементов:");
    while (scanf_s("%d", &size) == 1 && size > 0) {
        printf("Введите значение для инициализации:");
        scanf_s("%d", &value);
        pa = make_array(size, value);
        if (pa) {
            show_array(pa, size);
            free(pa);
        }
        printf("Bвeдитe количество элементов (<1 для завершения):");
    }
    printf("Программа завершена.\n");
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
9. Напишите программу со следующим поведением. Сначала она запрашивает количество
слов, которые нужно ввести. Затем она предлагает ввести слова, после чего их отображает.
Воспользуйтесь malloc() и ответом на первый запрос (количество слов), 
чтобы создать динамический массив с подходящим количеством указателей на char. 
(Обратите внимание, что поскольку каждый элемент в массиве
является указателем на char, возвращаемое значение функции malloc()
должно сохраняться в указателе на указатель на char.)
При чтении строки программа должна читать слово во временный массив элементов char, 
с помощью malloc() выделять пространство, достаточное для хранения слова, и помещать
адрес в массив указателей на char. Далее программа должна копировать слово
из временного массива в выделенное пространство памяти. Таким образом, в
итоге создается массив указателей на char, каждый из которых ссылается на
объект с размером, необходимым для хранения конкретного слова. Результаты
пробного запуска должны выглядеть следующим образом:
Сколько слов вы хотите ввести? 5
Теперь введите 5 слов:
Мне понравилось выполнять это упражнение
Вот введенные вами слова:
Мне
понравилось
выполнять
это
упражнение
*/
void wodrsarray(void);
void wordsout(char** ppw, int n);
int Exsample9(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 9. Массив слов и указателей на них.\033[0m\n");
    do
    {
        wodrsarray();
        getchar();
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
#define MAXWRDS 100         // макс число слов
#define MAXLWRD 20          // МАКС длина слова
void wodrsarray(void) {
    int nwords,l,status;
    char** pwords;
    char word[21];
    bool ok = false;
    do {
        ok = true;
        printf("Колличество слов(<100):"INPUT3);
        scanf_s("%d", &nwords);
        if (nwords<1 || nwords>MAXWRDS) {
            printf("\033[41;30mОшибка!\033[0m Число слов д.б <%d и >1.\n", MAXWRDS);
            ok = false;
        }
    } while (!ok);
    pwords = (char**)malloc(nwords * sizeof(char*));
    printf("Введите %d слов(два Enter завершит ввод).\n:"INPUT3, nwords);
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
    printf("Вот введенные вами слова:\n");
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
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание Sort. Поиск в массиве.\033[0m\n");
    do
    {
        printf("Recursive Solution. Largest in given array is %d.\n",largestRecursive(arr, n, 0));
        printf("One of the most simplest Solution. Largest in given array is %d.\n", largestSimple(arr, n));
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
