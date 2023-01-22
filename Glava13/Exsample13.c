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
Упражнения по программированию Глава 13.
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
1. Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю 
ввести имя файла и читала его ответ вместе использования аргументов командной
строки.
*/
#define MAX_NAME 20
int count13_1(char* name);
int Exsample1(int args, char* argv[])
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 1. Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю ввести имя файла.\033[0m\n");
    do
    {
        count13_1(args>1?argv[1]:"");
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
// Листинг 13.1. Программа count. с
/* count.c — использование стандартного ввода-вывода */
#include <stdlib.h> // прототип exit()
#include <string.h>
#include <errno.h>
#define MAX_NAME 21 
#define MAX_BUF 201 
//char* strerror(int errnum);
int count13_1(char* str)
{
    int ch; // место для хранения каждого символа по мере чтения
    char buf[MAX_BUF],name[MAX_NAME],*pname;
    FILE* fp; // "указатель файла"
    unsigned long count = 0;
    int err;
    printf("\n\033[1;4;44mЛистинг 13.1.Программа count.c — использование стандартного ввода-вывода.\033[0m\n");
    if (strlen(str) == 0) {
        printf("Введите имя файла:");
        fscanf_s(stdin, "%20s", name, MAX_NAME);
        getchar();
        pname = name;
    }
    else 
        pname = str;
    if ((err = fopen_s(&fp, pname, "r")) > 0)
    {
        strerror_s(buf, 99, err);
        printf("Не удается открыть файл %s. Ошибка=%d(%s)\n", pname, err, buf);
        exit(EXIT_FAILURE);
    }
    printf("Содержимое файла %s:\n", pname);
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // то же, что и putchar (ch) ;
        count++;
    }
    printf("\nФайл %s содержит %lu символов\n", pname, count);
    if ((err = fclose(fp))) {
        strerror_s(buf, 99, err);
        printf("Ошибка %d(%s) при закрытии файла %s.\n", err, buf, pname);
    }
    return 0;
}