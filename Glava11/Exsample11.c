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
Упражнения по программированию Глава 11.
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
1. Разработайте и протестируйте функцию, которая извлекает из ввода следующие
n символов (включая символы пробела, табуляции и новой строки), сохраняя
результаты в массиве, адрес которого передается в качестве аргумента.
*/
char inputn(char* arr, int n);
int Exsample1(void)
{
    int i,n, beg, end;
    char ch;
    char arr[201];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 1. функция извлекает из ввода следующие n символов.\033[0m\n");
    do
    {
        printf("Введите n - число символов, вводимых в программу(<200):"INPUT3);
        while (scanf_s("%d", &n), !(n > 0 && n < 200)) {
            printf("\033[31mОшибка!\033[0m Введите число <200:");
        }
        ch=getchar();
        printf("\nВведите строку или несколько, но только n символов будет введено в программу\n:"INPUT3);
        //inputn( arr,  n);
        printf("\nВведено(%d симв):%s\n", strlen(arr), arr);
        printf("\nЕщё разок?(y/n или д/н):");
        ch= getch();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
            ch = getch();
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
//char inputn(char* arr,int n) {
//    int i=0; 
//    char ch;
//    while ((ch = getc(stdin)) && i++<n) {
//        *arr++ = ch;
//    }
//    *arr = '\0';
//    return ch;
//}
/*
2. Модифицируйте и протестируйте функцию из упражнения 1, обеспечив в ней
прекращение ввода после n символов либо при достижении первого символа
пробела, табуляции или новой строки, в зависимости от того, что произойдет
раньше. (Не ограничивайтесь только использованием scanf().)
*/
char inputn2(char* arr, int n,char* d);
int Exsample2(void)
{
    int i, n,beg, end,status;
    char ch;
    char arr[201];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. Ввод n символов либо при достижении пробела, табуляции или новой строки.\033[0m\n");
    do
    {
        printf("Введите n - число символов, вводимых в программу(<200):"INPUT3);
        while ((status = scanf_s("%d", &n)) != 1 || n < 0 || n >= 200) {
            printf("\n\033[31mОшибка!\033[0m Введите число <200:");
        }
        ch = getchar();
        printf("\nВведите строку или несколько, но только %d символов до пробела, табуляции, нов.строки будет введено в программу\n:"INPUT3,n);
        inputn2(arr, n, " \n\t");
        printf("\nВведено(%d симв):%s\n", strlen(arr), arr);

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
char inputn2(char* arr, int n, char* d) {
    int i = 0;
    char ch;
    while ((ch = getc(stdin)) && i++ < n && !cmpdelim(ch,d)) {
        *arr++ = ch;
    }
    *arr = '\0';
    return arr;
}
int cmpdelim(char ch, char* delim) {
    int i=1;
    char* cd = delim;
    while (*cd) {
        if (*cd++ == ch) return i;
        i++;
    }
    return 0;
}
/* 
3. Разработайте и протестируйте функцию, которая читает первое слово из строки
ввода в массив и отбрасывает остальную часть строки. Функция должна пропускать
ведущие пробельные символы. Определите слово как последовательность
символов, не содержащую символов пробела, табуляции или новой строки.
Используйте функцию getchar(), а не scanf().
*/
int readWord(char* arr, int n, char* d);    // n-макс длина слова, word-введённое слово 0 в конце, возвращает длину слова, d-ограничители слова
int Exsample3(void)
{
    int i, len;
    char ch;
    char word[100];
    char* delim = " \n\t,.;:-+=!?(){}[]<>";
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 3. функция, читает первое слово из строки ввода в массив.\033[0m\n");
    do
    {
        printf("Введите строку, первое слово будет введено в программу\n:"INPUT3);
        len = readWord(word, 99,delim);
        printf("Введено слово:\"%s\" длиной:%d\n", word, len);
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
int readWord(char* arr,int n,char* d) {
    int i = 0;
    char ch;
    bool beg = true;
    while ((ch = getc(stdin))) {
        if(beg) 
            if(cmpdelim(ch, d)) continue;
            else  beg = false;
        else
        if (i++ >= n) break;
        if (cmpdelim(ch, d)) break;
        *arr++ = ch;
    }
    while (ch != '\n') ch=getc(stdin);
    *arr = '\0';
    return i;

}
/*
5. Разработайте и протестируйте функцию, которая ищет в переданной в первом
параметре строке первое вхождение символа, заданного во втором параметре.
Функция должна возвратить указатель на этот символ, если он найден, и ноль
в противном случае. (Поведение этой функции дублирует работу библиотечной
функции strchr().) Протестируйте функцию в завершенной программе, которая
использует цикл для передачи входных значений созданной функции.
*/
char* search(char* arr, char ch, int n);    // arr-исходная строка, ch-разыскиваемый символ,n-ограничение длины строки
int Exsample5(void)
{
    int i,  end;
    char ch,arr[100],* beg;

    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 5. поиск в строке первое вхождение символа, заданного во втором параметре.\033[0m\n");
    do
    {
        printf("Введите строку для поиска в ней символа:"INPUT3);
        fgets( arr, 99,stdin);
        printf("Введите символ для поиска в строке:"INPUT3);
        ch=getc(stdin);
        beg=search(arr, ch, 99);
        if (beg) printf("\nНашли символ '%c' в %d позиции.\n",ch, beg-arr + 1);
        else printf("\nСимвол '%c' не нашли в строке.\n", ch);

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
char* search(char* arr, char ch, int n) {
    int i = 0;
    char cc;
    while (((cc=*arr++) != ch) && (i++<n) && cc);
    if (cc == ch) return arr - 1;
    else return 0;
}
/*
6. Напишите функцию по имени is_within(), которая в качестве двух своих параметров
принимает символ и указатель на строку. Функция должна возвращать
ненулевое значение, если заданный символ содержится в строке, и ноль в противном
случае. Протестируйте функцию в завершенной программе, которая использует
цикл для передачи входных значений созданной функции.
*/
int is_within(char ch, char* arr, int n);
int Exsample6(void)
{
    int i, beg, end;
    char ch,arr[100];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 6. Функция возвращает ненулевое значение, если символ содержится в строке, иначе 0.\033[0m\n");
    do
    {
        printf("Введите строку для поиска в ней символа:"INPUT3);
        fgets(arr, 99, stdin);
        printf("Введите символ для поиска в строке:"INPUT3);
        ch = getc(stdin);
        if (is_within(ch, arr, 99)) printf("Символ '%c' найден\n", ch);
        else printf("Символ '%c' не найден\n", ch);
        printf("\nЕщё разок?(y/n или д/н):");
        ch=getch();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
            ch = getch();
            if(ch=='\n') ch = getch();
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
int is_within(char ch, char* arr,int n) {
    char cc;
    int i = n;
    while ((cc = *arr++) && cc != ch && i--);
    return cc == ch;
}
/*
7. Функция strncpy(s1,s2,n) копирует в точности n символов из строки s2 в
строку s1, при необходимости усекая s2 или дополняя ее нулевыми символами.
Целевая строка может не содержать завершающего нулевого символа, если
длина строки s2 равна или больше n. Функция возвращает строку s1. Напишите
свою версию этой функции и назовите ее mystrncpy(). Протестируйте функцию 
в завершенной программе, которая использует цикл для передачи входных
значений созданной функции.
*/
char* mystrncpy(char* s1,char* s2,int n);
int Exsample7(void)
{
    int i, beg, end;
    char ch,arr1[200], arr2[100];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 7. Реализация strncpy(s1,s2,n).\033[0m\n");
    do
    {
        printf("Введите исходную строку:"INPUT3);
        fgets(arr1, 99, stdin);
        printf("Введите добавляемую строку:"INPUT3);
        fgets(arr2, 99, stdin);
        printf("\n%s\n", mystrncpy(arr1, arr2, 199));
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
char* mystrncpy(char* s1, char* s2, int n) {
    char ch,*s=s1;
    int i = n;
    while ((ch=*s1++) && (ch!='\n')); 
    s1 -= 1;
    while ((ch = *s2++) && (i-- > 0))
        *(s1++) = ch;
    *s1 = '\0';
    return s;
}
/*
8. Напишите функцию string_in(), которая принимает в качестве аргументов
два указателя на строки. Если вторая строка содержится внутри первой, функция
должна возвратить адрес, с которого начинается вторая строка в первой строке.
Например, вызов string_in("данные","ан") возвратит адрес символа а в
строке данные. В противном случае функция должна возвратить нулевой указатель.
Протестируйте функцию в завершенной программе, которая использует
цикл для передачи входных значений созданной функции.
*/
char* string_in(char* s1,char* s2, int n1, int n2);
bool substr(char* s1, char* s2, int n1, int n2);
int Exsample8(void)
{
    int i, beg, end;
    char ch;
    char arr1[100], arr2[50],*ptr;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 8. Напишите функцию string_in() поиск подстроки\033[0m\n");
    do
    {
        printf("Введите строку:"INPUT3);
        fgets(arr1, 99, stdin);
        printf("Введите подстроку поиска в строке:"INPUT3);
        fgets(arr2, 49, stdin);
        if (ptr = string_in(arr1, arr2, 99, 49)) printf("Нашлась подстрока \"%s\"\n", ptr);
        else printf("Нет подстроки \"%s\" внутри исходной строки.\n");
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
char* string_in(char* s1, char* s2,int n1,int n2) {
    char* s,ch;
    int i1=n1, i2=n2;
    while ((ch=*s1)) {
        if (substr(s1, s2, i1, i2)) return s1;
        s1++;
        if(--i1 <= 0) break;
    }
    return NULL;
}
bool substr(char* s1, char* s2,int n1,int n2) {
    while (*s1 == *s2) {
        s1++;
        s2++;
        n1--;
        n2--;
        if (*s1 == '\n' || *s1=='\0' || * s2 == '\0' || *s2 == '\n' || n1 == 0 || n2 == 0) return true;
    }
    return false;
}
/*
9. Напишите функцию, которая заменяет содержимое указанной строки этой же
строкой, но с обратным порядком следования символов. Протестируйте функцию 
в завершенной программе, которая использует цикл для передачи входных
значений созданной функции.
*/
int reversestr(char* str, int n);
int Exsample9(void)
{
    int i, beg, end;
    char ch,str[100];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 9. заменяет содержимое указанной строки этой же строкой, но с обратным порядком следования символов.\033[0m\n");
    do
    {
        printf("введите строку для перевёртывания(<99 сим.)\n:"INPUT3);
        fgets(str, 99, stdin);
        reversestr(str, 99);
        printf("Перевёрнутая строка\n:%s\n", str);
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
int reversestr(char* str, int n) {
    char ch,* beg=str;
    int l=0;
    while ((ch=*str++)) {
        if (ch == '\n') { *(str - 1) = '\0'; break; }   // замена \n на \0 
        l++;
        if (l > n) { *str = '\0'; break; }
    };
    if (!*--str) --str;             // пропустить конец строки и возможный \0 от замены \n
   do {                             
        ch = *str;
        *str= *beg;
        *beg = ch;
    } while (--str > ++beg);
}
/*
10. Напишите функцию, которая принимает строку в качестве аргумента и удаляет
из нее все пробелы. Протестируйте эту функцию в программе, которая использует
цикл для чтения строк до тех пор, пока не будет введена пустая строка.
Программа должна применять эту функцию к каждой входной строке и отображать
результат.
*/
int delspc(char* str, int n, char* spc);
bool isin(char ch, char* in);
int Exsample10(void)
{
    int i, beg, end;
    char ch;
    char str[100],*spc=" \t\n";
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. Удаление пробелов.\033[0m\n");
    do
    {
        printf("Введите строку для удаления пробелов:");
        fgets(str, 99, stdin);
        delspc( str, 99,  spc);
        printf("Обработанная строка без пробелов \"%s\".\n", str);
        printf("\nЕщё разок?(y/n или д/н):");
        ch=getchar(); getchar();
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
            ch = getchar();
        }
    } while (ch == 'y' || ch == 'д'|| ch=='\n');
    printf("\nКонец программы\n");
    return 0;
}
int delspc(char* str, int n, char* spc) {
    char* ptr1 = str, * ptr2 = str,ch;
    int l = n;
    bool nspc = true;
    while ((ch=*ptr2) && l > 0) {
        if (isin(ch, spc)) { ptr2++; nspc = false; }
        else if (nspc) { ptr1++; ptr2++; }
        else { *ptr1++ = ch; ptr2++; }
        l--;
    }
    *ptr1 = '\0';
}
bool isin(char ch,char* in) {
    char cc;
    while ((cc=*in++)) 
        if (ch == cc) return true;
    return false;
}
/*
11. Напишите программу, которая читает до 10 строк и или до появления EOF, в
зависимости от того, что произойдет раньше. Функция должна предложить
пользователю меню с пятью вариантами: 
вывод исходного списка строк, 
вывод строк согласно последовательности сопоставления ASCII, 
вывод строк в порядке возрастания длины, 
вывод строк в порядке возрастания длины первого слова в строке и 
выход из программы. 
Меню должно отображаться до тех пор, пока пользователь не выберет вариант 
выхода из программы. Программа должна действительно выполнять запрошенные действия.
*/

#define MMENU 6
#define NSTR 10
#define LSTR 100
int menu1111(char* menu[], int m);
int func11110(char str[NSTR][LSTR], int n, int m);
int func11111(char* str[], int n,int m,int l);
int func11112(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // Сортировка по алфавиту
int func11113(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // Сортировка по длине строк
int func11114(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // Сортировка по длине 1-го слова
int delnl(char* str, int n);
int Exsample11(void)
{
    int i, beg, end,imenu;
    char ch;
    char* menu[] = {
                    "ввод массива строк",
                    "вывод исходного списка строк",
                    "вывод строк согласно последовательности сопоставления ASCII",
                    "вывод строк в порядке возрастания длины",
                    "вывод строк в порядке возрастания длины первого слова в строке",
                    "выход из программы"
    };
    char strings[NSTR][LSTR] = {"123456789","qwertyuio","asdfghjkl"};
    int idx[NSTR];              // Массив индексов сортировки
    int nstrings= NSTR;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 11.  читает до 10 строк и или до появления EOF и выводит меню\033[0m\n");
    do
    {
        do {
            imenu = menu1111(menu, MMENU);
            if (imenu<1 || imenu>MMENU) break;
            printf("Выполнение фукции %d-%s\n", imenu, menu[imenu - 1]);
            switch (imenu) {
            case 1:
                nstrings=func11110(strings, NSTR, LSTR);
                break;
            case 2:
                func11111(strings, NSTR, LSTR,nstrings);
                break;
            case 3:
                func11112(strings, idx, NSTR, LSTR, nstrings);
                for (int i = 0; i < nstrings; i++) printf("%s\n", strings[idx[i]]);
                break;
            case 4:
                func11113(strings, idx, NSTR, LSTR, nstrings);
                for (int i = 0; i < nstrings; i++) printf("%s\n", strings[idx[i]]);
                break;
            case 5:
                func11114(strings, idx, NSTR, LSTR, nstrings);
                for (int i = 0; i < nstrings; i++) printf("%s\n", strings[idx[i]]);
                break;
            case 6:
                break;
            default:;

            }
        } while (imenu != 6);
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
int menu1111(char* menu[],int m) {
    int i,n, status;
    char ch;
    bool err = false;
    printf("Выполняемые функции:\n");
    do {
        for(i=0;i<m;i++)
            printf("\033[32m%2d\033[0m.%s\n",i+1,menu[i]);
        printf("Введите номер функции(1-%d):",m);
        ch = getch();
        n = ch - '0';
        err = (n < 1 || n > m);
        if (err) printf(" \033[31m%d.Ошибка!\033[0m Нужно ввести цифру от 1 до %d.\n",n,m);
    } while (err);
    printf("\n");
    return n;
}
int func11110(char str[NSTR][LSTR], int n, int m) {     // Ввод строк, возврат число введённых строк
    int l=0;
    printf("Введите строки не больше %d штук и не длиннее %d(Пустая строка - конец):\n", n,m);
    for (int i = 0; i < n; i++) {
        printf("%2d:", i+1);
        fgets(str[i], m-1, stdin);
        if(!delnl(str[i], m - 1)) break;
        l++;
    }
    return l;
}
int func11111(char str[NSTR][LSTR], int n, int m,int l) {     // Вывод строк
    printf("Имеющиеся строки:\n", n,m);
    for (int i = 0; i < n; i++) {
        if (strlen(str[i]))
            printf("%d:%s\n", i + 1, str[i]);
        else break;
        if (i >= l) break;
    }

}
int delnl(char* str, int n) {   // Заменяет в строке первый '\n' на '\0', возвращает длину строки
    char ch;
    int i = 0;
    while ((ch = *str++) ) {
        if (ch == '\n') { *(str - 1) = '\0'; break; }
        if (i++ >= n) break;
    }
    return i;
}
int func11112(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // Сортировка по алфавиту
    int temp;
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < l-1;i++)
        for(int j=i+1;j<l;j++){
            if (strcmp(str[i], str[j])>0) {
                temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
    }
}
int func11113(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // Сортировка по длине строк
    int temp;
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++) {
            if (strlen(str[i])> strlen(str[j])) {
                temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
}
int func11114(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // Сортировка по длине 1-го слова
    int temp;
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < l - 1; i++)
        for (int j = i + 1; j < l; j++) {
            if (getword(str[i],m) > getword(str[j],m)) {
                temp = idx[i];
                idx[i] = idx[j];
                idx[j] = temp;
            }
        }
}
int getword(char* str, int n) {         // Возвращает длину 1-го слова строки
    char* del = " \t\n\0,.:;-+=!?";     // Разделители слов
    int l = 0;
    l=strcspn(str, del);
    return l;
}
/*
12. Напишите программу, которая читает входные данные до тех пор, пока не встретится
EOF, и выводит количество слов, количество прописных букв, количество
строчных букв, количество знаков препинания и количество-цифр. Используйте семейство функций ctype.h.
*/
#define MAX12 100
int countwords(char* str, int n);
int countbig(char* str, int n);        // Возвращает число больших букв в строке
int countlitl(char* str, int n);       // Возвращает число маленьких букв в строке
int countpunc(char* str, int n);       // Возвращает число знаков препинания в строке
int countdigit(char* str, int n);      // Возвращает число цыфр в строке

int Exsample12(void)
{
    int i, nbig=0, nwords=0,nlittles=0,nsemicoll=0,ndigits=0;
    char ch;
    char str[MAX12] = {'\0'};
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 12. выводит количество слов, прописных букв, строчных букв, знаков препинания и цифр.\033[0m\n");
    do
    {
        printf("Введите строку\n:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        nwords = countwords(str, MAX12);
        nbig= countbig( str, MAX12);
        nlittles= countlitl(str, MAX12);
        nsemicoll= countpunc(str, MAX12);
        ndigits = countdigit(str, MAX12);
        printf("Число слов:%d\nЧисло больших букв:%d\nЧисло маленьких букв:%d\nЧисло препинаний:%d\nЧисло цыфр:%d\n", nwords, nbig, nlittles, nsemicoll, ndigits);
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
int countwords(char* str, int n) {      // Возвращает число слов в строке
    int nword = 1;
    char* del = " \t\n,.:;-+=!?\0";     // Разделители слов
    char* pch = strpbrk(str, del);
    while (pch && *pch != '\n') {
        pch++;
        nword++;
        pch = strpbrk(pch, del);
    }
    return nword;
}
int countbig(char* str, int n) {                // Возвращает число больших букв в строке
    int nbig = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // пока не конец строки
    {
        ch = str[ix];
        if (isupper(ch))                        // если текущий символ - прописной
            nbig++;
        ix++;                                   // инкремент индекса символов в строке
    }
    return nbig;
}
int countlitl(char* str, int n) {                // Возвращает число маленьких букв в строке
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // пока не конец строки
    {
        ch = str[ix];
        if (islower(ch))                        // если текущий символ - прописной
            nlit++;
        ix++;                                   // инкремент индекса символов в строке
    }
    return nlit;
}
int countpunc(char* str, int n) {                // Возвращает число знаков препинания в строке
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // пока не конец строки
    {
        ch = str[ix];
        if (ispunct(ch))                        // если текущий символ - прописной
            nlit++;
        ix++;                                   // инкремент индекса символов в строке
    }
    return nlit;
}
int countdigit(char* str, int n) {                // Возвращает число цыфр в строке
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // пока не конец строки
    {
        ch = str[ix];
        if (isdigit(ch))                        // если текущий символ - прописной
            nlit++;
        ix++;                                   // инкремент индекса символов в строке
    }
    return nlit;
}
/*
13. Напишите программу, которая повторяет на экране аргументы командной строки
в обратном порядке. Другими словами, если аргументами командной строки
являются до скорого свидания, данная программа должна вывести на экран свидания скорого до.
*/
#define MAX13 100
int reverse(char* str);    // Печать слов строки в обратном порядке

int Exsample13(int argc, char* argv[])
{
    int i, nword, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 13. Реверс слов аргументов командной строки.\033[0m\n");
    do
    {
        printf("В командной строке %d параметров:\n",argc);
        for (int i = 0; i < argc; i++) printf("%s-", argv[i]);
        printf("\nПеревёрнутые:\n");
        for (int i = argc - 1; i > 0; i--) {
            if ((nword = countwords(argv[i], MAX13)) == 1)
                printf("%s-", argv[i]);
            else
                reverse(argv[i]);
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
int reverse(char* str) {    // Печать слов строки в обратном порядке
    char* del = " \t\n,.:;-+=!?\0";     // Разделители слов
    char ch, *chbeg,*chend;
    int ll=0,l = strlen(str);
    while (l >= 0) {
        if (chbeg=strchr(del, *(str + l))) {         // символ - разделитель
            for (int i = 0; i < ll; i++) printf("%c", *(str + l + i+1));
            printf("-");
            ll = 0;
        }
        else {
            ll++;
        }
        l--;
    }
    if (ll) {
        for (int i = 0; i < ll; i++) printf("%c", *(str + l + i + 1));
        printf("-");

    }
}
/*
14. Напишите программу реализации степенной зависимости, которая работает на
основе командной строки. Первым аргументом командной строки должно быть
число типа double , возводимое в определенную степень, а вторым аргументом -
целочисленный показатель степени.
*/
#include <math.h>
int Exsample14(int argc, char* argv[])      // парам1=double основание, парам2=int степень
{
    int i, beg, end;
    char ch;
    double d=atof(argv[1]),dpow;
    int powe=atoi(argv[2]);
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 14. Целочисленная степень.\033[0m\n");
    do
    {
        dpow = pow(d,powe);
        //for (int i = 0; i < pow; i++) dpow *= d;
        printf("Степень %d числа %lf равна %lf\n", powe, d, dpow);
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
15. Дня подготовки реализации функции atoi() используйте функции классификации
символов. Эта версия должна возвращать значение 0, если строка ввода не
является полностью числовой.
*/
int isalldigit(char* str, int n);     // Проверяет, что все символы в строке цифры

int Exsample15(void)
{
    int i, beg, end;
    char ch, * pch;
    char str[MAX12];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 15. Проверка строки на число.\033[0m\n");
    do
    {
        printf("Введите сроку:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        pch = strchr(str, '\n');    // поиск символа новой строки
        if (pch)                    // если адрес не является NULL,
            * pch = '\0';           // поместить туда нулевой символ
        if (i = isalldigit(str, MAX12 - 1)) printf("Введено число %d\n", i);
        else printf("Введено не число.\n");
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
int isalldigit(char* str, int n) {      // Проверяет, что все символы в строке цифры
    char ch;
    char* pch = str;
    while ((ch = *str++)) {
        if (!isdigit(ch)) return 0;
    }
    return atoi(pch);
}
/*
16. Напишите программу, которая читает входные данные до тех пор, пока не встретится
EOF, и выводит их на экран. Программа должна распознавать и реализовывать
следующие аргументы командной строки:
-р Вывод входных данных в том виде, как есть.
-u Преобразование входных данных в верхний регистр.
-l Преобразование входных данных в нижний регистр.
Кроме того, сели аргумент входной строки не указан, программа должна вести
себя так, как сели бы был задан аргумент -р.
*/
char getop(char* str);    // Определяет орерацию -p -u -l p,u,l
int tolower16(char* str, int n);     // Преобазует строку в нижний регистр
int toupper16(char* str, int n);     // Преобазует строку в верхний регистр

int Exsample16(void)
{
    int i, beg, end;
    char ch,op,*pch;
    char str[MAX12];
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 16. Ввод и преобразование строки в верхний и нижний регистры.\033[0m\n");
    do
    {
        printf("Введите сроку:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        pch = strchr(str, '\n');    // поиск символа новой строки
        if (pch)                    // если адрес не является NULL,
            *pch = '\0';           // поместить туда нулевой символ

        op = getop(str);
        switch (op)
        {
        case 'p':
            printf("%s\n", str + 2);
            break;
        case 'l':
            tolower16(str+2, MAX12);
            printf("%s\n", str + 2);
            break;
        case 'u':
            toupper16(str+2, MAX12);
            printf("%s\n", str + 2);
            break;
        case 'P':
            printf("%s\n", str );
            break;
        default:
            break;
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
char getop(char* str) {    // Определяет орерацию -p -u -l p,u,l
    char op='P';
    if(str[0]=='-')
        switch (str[1])
        {
        case 'p':
            op = 'p';
            break;
        case 'u':
            op = 'u';
            break;
        case 'l':
            op = 'l';
            break;

        default:
            break;
        }
    return op;
}
int tolower16(char* str, int n) {     // Преобазует строку в нижний регистр
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
int toupper16(char* str, int n) {     // Преобазует строку в верхний регистр
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}