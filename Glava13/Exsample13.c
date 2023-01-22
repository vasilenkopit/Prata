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
���������� �� ���������������� ����� 13.
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
1. ������������� ��������� � �������� 13.1, ����� ��� ���������� ������������ 
������ ��� ����� � ������ ��� ����� ������ ������������� ���������� ���������
������.
*/
#define MAX_NAME 20
int count13_1(char* name);
int Exsample1(int args, char* argv[])
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 1. ������������� ��������� � �������� 13.1, ����� ��� ���������� ������������ ������ ��� �����.\033[0m\n");
    do
    {
        count13_1(args>1?argv[1]:"");
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
// ������� 13.1. ��������� count. �
/* count.c � ������������� ������������ �����-������ */
#include <stdlib.h> // �������� exit()
#include <string.h>
#include <errno.h>
#define MAX_NAME 21 
#define MAX_BUF 201 
//char* strerror(int errnum);
int count13_1(char* str)
{
    int ch; // ����� ��� �������� ������� ������� �� ���� ������
    char buf[MAX_BUF],name[MAX_NAME],*pname;
    FILE* fp; // "��������� �����"
    unsigned long count = 0;
    int err;
    printf("\n\033[1;4;44m������� 13.1.��������� count.c � ������������� ������������ �����-������.\033[0m\n");
    if (strlen(str) == 0) {
        printf("������� ��� �����:");
        fscanf_s(stdin, "%20s", name, MAX_NAME);
        getchar();
        pname = name;
    }
    else 
        pname = str;
    if ((err = fopen_s(&fp, pname, "r")) > 0)
    {
        strerror_s(buf, 99, err);
        printf("�� ������� ������� ���� %s. ������=%d(%s)\n", pname, err, buf);
        exit(EXIT_FAILURE);
    }
    printf("���������� ����� %s:\n", pname);
    while ((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout); // �� ��, ��� � putchar (ch) ;
        count++;
    }
    printf("\n���� %s �������� %lu ��������\n", pname, count);
    if ((err = fclose(fp))) {
        strerror_s(buf, 99, err);
        printf("������ %d(%s) ��� �������� ����� %s.\n", err, buf, pname);
    }
    return 0;
}