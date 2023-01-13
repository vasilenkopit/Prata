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
���������� �� ���������������� ����� 11.
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
1. ������������ � ������������� �������, ������� ��������� �� ����� ���������
n �������� (������� ������� �������, ��������� � ����� ������), ��������
���������� � �������, ����� �������� ���������� � �������� ���������.
*/
char inputn(char* arr, int n);
int Exsample1(void)
{
    int i,n, beg, end;
    char ch;
    char arr[201];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 1. ������� ��������� �� ����� ��������� n ��������.\033[0m\n");
    do
    {
        printf("������� n - ����� ��������, �������� � ���������(<200):"INPUT3);
        while (scanf_s("%d", &n), !(n > 0 && n < 200)) {
            printf("\033[31m������!\033[0m ������� ����� <200:");
        }
        ch=getchar();
        printf("\n������� ������ ��� ���������, �� ������ n �������� ����� ������� � ���������\n:"INPUT3);
        //inputn( arr,  n);
        printf("\n�������(%d ����):%s\n", strlen(arr), arr);
        printf("\n��� �����?(y/n ��� �/�):");
        ch= getch();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("\033[31m������!\033[0m �����(y/n �/�):");
            ch = getch();
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
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
2. ������������� � ������������� ������� �� ���������� 1, ��������� � ���
����������� ����� ����� n �������� ���� ��� ���������� ������� �������
�������, ��������� ��� ����� ������, � ����������� �� ����, ��� ����������
������. (�� ��������������� ������ �������������� scanf().)
*/
char inputn2(char* arr, int n,char* d);
int Exsample2(void)
{
    int i, n,beg, end,status;
    char ch;
    char arr[201];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. ���� n �������� ���� ��� ���������� �������, ��������� ��� ����� ������.\033[0m\n");
    do
    {
        printf("������� n - ����� ��������, �������� � ���������(<200):"INPUT3);
        while ((status = scanf_s("%d", &n)) != 1 || n < 0 || n >= 200) {
            printf("\n\033[31m������!\033[0m ������� ����� <200:");
        }
        ch = getchar();
        printf("\n������� ������ ��� ���������, �� ������ %d �������� �� �������, ���������, ���.������ ����� ������� � ���������\n:"INPUT3,n);
        inputn2(arr, n, " \n\t");
        printf("\n�������(%d ����):%s\n", strlen(arr), arr);

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
3. ������������ � ������������� �������, ������� ������ ������ ����� �� ������
����� � ������ � ����������� ��������� ����� ������. ������� ������ ����������
������� ���������� �������. ���������� ����� ��� ������������������
��������, �� ���������� �������� �������, ��������� ��� ����� ������.
����������� ������� getchar(), � �� scanf().
*/
int readWord(char* arr, int n, char* d);    // n-���� ����� �����, word-�������� ����� 0 � �����, ���������� ����� �����, d-������������ �����
int Exsample3(void)
{
    int i, len;
    char ch;
    char word[100];
    char* delim = " \n\t,.;:-+=!?(){}[]<>";
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 3. �������, ������ ������ ����� �� ������ ����� � ������.\033[0m\n");
    do
    {
        printf("������� ������, ������ ����� ����� ������� � ���������\n:"INPUT3);
        len = readWord(word, 99,delim);
        printf("������� �����:\"%s\" ������:%d\n", word, len);
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
5. ������������ � ������������� �������, ������� ���� � ���������� � ������
��������� ������ ������ ��������� �������, ��������� �� ������ ���������.
������� ������ ���������� ��������� �� ���� ������, ���� �� ������, � ����
� ��������� ������. (��������� ���� ������� ��������� ������ ������������
������� strchr().) ������������� ������� � ����������� ���������, �������
���������� ���� ��� �������� ������� �������� ��������� �������.
*/
char* search(char* arr, char ch, int n);    // arr-�������� ������, ch-������������� ������,n-����������� ����� ������
int Exsample5(void)
{
    int i,  end;
    char ch,arr[100],* beg;

    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 5. ����� � ������ ������ ��������� �������, ��������� �� ������ ���������.\033[0m\n");
    do
    {
        printf("������� ������ ��� ������ � ��� �������:"INPUT3);
        fgets( arr, 99,stdin);
        printf("������� ������ ��� ������ � ������:"INPUT3);
        ch=getc(stdin);
        beg=search(arr, ch, 99);
        if (beg) printf("\n����� ������ '%c' � %d �������.\n",ch, beg-arr + 1);
        else printf("\n������ '%c' �� ����� � ������.\n", ch);

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
char* search(char* arr, char ch, int n) {
    int i = 0;
    char cc;
    while (((cc=*arr++) != ch) && (i++<n) && cc);
    if (cc == ch) return arr - 1;
    else return 0;
}
/*
6. �������� ������� �� ����� is_within(), ������� � �������� ���� ����� ����������
��������� ������ � ��������� �� ������. ������� ������ ����������
��������� ��������, ���� �������� ������ ���������� � ������, � ���� � ���������
������. ������������� ������� � ����������� ���������, ������� ����������
���� ��� �������� ������� �������� ��������� �������.
*/
int is_within(char ch, char* arr, int n);
int Exsample6(void)
{
    int i, beg, end;
    char ch,arr[100];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 6. ������� ���������� ��������� ��������, ���� ������ ���������� � ������, ����� 0.\033[0m\n");
    do
    {
        printf("������� ������ ��� ������ � ��� �������:"INPUT3);
        fgets(arr, 99, stdin);
        printf("������� ������ ��� ������ � ������:"INPUT3);
        ch = getc(stdin);
        if (is_within(ch, arr, 99)) printf("������ '%c' ������\n", ch);
        else printf("������ '%c' �� ������\n", ch);
        printf("\n��� �����?(y/n ��� �/�):");
        ch=getch();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("\033[31m������!\033[0m �����(y/n �/�):");
            ch = getch();
            if(ch=='\n') ch = getch();
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
    return 0;
}
int is_within(char ch, char* arr,int n) {
    char cc;
    int i = n;
    while ((cc = *arr++) && cc != ch && i--);
    return cc == ch;
}
/*
7. ������� strncpy(s1,s2,n) �������� � �������� n �������� �� ������ s2 �
������ s1, ��� ������������� ������ s2 ��� �������� �� �������� ���������.
������� ������ ����� �� ��������� ������������ �������� �������, ����
����� ������ s2 ����� ��� ������ n. ������� ���������� ������ s1. ��������
���� ������ ���� ������� � �������� �� mystrncpy(). ������������� ������� 
� ����������� ���������, ������� ���������� ���� ��� �������� �������
�������� ��������� �������.
*/
char* mystrncpy(char* s1,char* s2,int n);
int Exsample7(void)
{
    int i, beg, end;
    char ch,arr1[200], arr2[100];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 7. ���������� strncpy(s1,s2,n).\033[0m\n");
    do
    {
        printf("������� �������� ������:"INPUT3);
        fgets(arr1, 99, stdin);
        printf("������� ����������� ������:"INPUT3);
        fgets(arr2, 99, stdin);
        printf("\n%s\n", mystrncpy(arr1, arr2, 199));
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
8. �������� ������� string_in(), ������� ��������� � �������� ����������
��� ��������� �� ������. ���� ������ ������ ���������� ������ ������, �������
������ ���������� �����, � �������� ���������� ������ ������ � ������ ������.
��������, ����� string_in("������","��") ��������� ����� ������� � �
������ ������. � ��������� ������ ������� ������ ���������� ������� ���������.
������������� ������� � ����������� ���������, ������� ����������
���� ��� �������� ������� �������� ��������� �������.
*/
char* string_in(char* s1,char* s2, int n1, int n2);
bool substr(char* s1, char* s2, int n1, int n2);
int Exsample8(void)
{
    int i, beg, end;
    char ch;
    char arr1[100], arr2[50],*ptr;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 8. �������� ������� string_in() ����� ���������\033[0m\n");
    do
    {
        printf("������� ������:"INPUT3);
        fgets(arr1, 99, stdin);
        printf("������� ��������� ������ � ������:"INPUT3);
        fgets(arr2, 49, stdin);
        if (ptr = string_in(arr1, arr2, 99, 49)) printf("������� ��������� \"%s\"\n", ptr);
        else printf("��� ��������� \"%s\" ������ �������� ������.\n");
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
9. �������� �������, ������� �������� ���������� ��������� ������ ���� ��
�������, �� � �������� �������� ���������� ��������. ������������� ������� 
� ����������� ���������, ������� ���������� ���� ��� �������� �������
�������� ��������� �������.
*/
int reversestr(char* str, int n);
int Exsample9(void)
{
    int i, beg, end;
    char ch,str[100];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 9. �������� ���������� ��������� ������ ���� �� �������, �� � �������� �������� ���������� ��������.\033[0m\n");
    do
    {
        printf("������� ������ ��� �������������(<99 ���.)\n:"INPUT3);
        fgets(str, 99, stdin);
        reversestr(str, 99);
        printf("����������� ������\n:%s\n", str);
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
int reversestr(char* str, int n) {
    char ch,* beg=str;
    int l=0;
    while ((ch=*str++)) {
        if (ch == '\n') { *(str - 1) = '\0'; break; }   // ������ \n �� \0 
        l++;
        if (l > n) { *str = '\0'; break; }
    };
    if (!*--str) --str;             // ���������� ����� ������ � ��������� \0 �� ������ \n
   do {                             
        ch = *str;
        *str= *beg;
        *beg = ch;
    } while (--str > ++beg);
}
/*
10. �������� �������, ������� ��������� ������ � �������� ��������� � �������
�� ��� ��� �������. ������������� ��� ������� � ���������, ������� ����������
���� ��� ������ ����� �� ��� ���, ���� �� ����� ������� ������ ������.
��������� ������ ��������� ��� ������� � ������ ������� ������ � ����������
���������.
*/
int delspc(char* str, int n, char* spc);
bool isin(char ch, char* in);
int Exsample10(void)
{
    int i, beg, end;
    char ch;
    char str[100],*spc=" \t\n";
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. �������� ��������.\033[0m\n");
    do
    {
        printf("������� ������ ��� �������� ��������:");
        fgets(str, 99, stdin);
        delspc( str, 99,  spc);
        printf("������������ ������ ��� �������� \"%s\".\n", str);
        printf("\n��� �����?(y/n ��� �/�):");
        ch=getchar(); getchar();
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            printf("\033[31m������!\033[0m �����(y/n �/�):");
            ch = getchar();
        }
    } while (ch == 'y' || ch == '�'|| ch=='\n');
    printf("\n����� ���������\n");
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
11. �������� ���������, ������� ������ �� 10 ����� � ��� �� ��������� EOF, �
����������� �� ����, ��� ���������� ������. ������� ������ ����������
������������ ���� � ����� ����������: 
����� ��������� ������ �����, 
����� ����� �������� ������������������ ������������� ASCII, 
����� ����� � ������� ����������� �����, 
����� ����� � ������� ����������� ����� ������� ����� � ������ � 
����� �� ���������. 
���� ������ ������������ �� ��� ���, ���� ������������ �� ������� ������� 
������ �� ���������. ��������� ������ ������������� ��������� ����������� ��������.
*/

#define MMENU 6
#define NSTR 10
#define LSTR 100
int menu1111(char* menu[], int m);
int func11110(char str[NSTR][LSTR], int n, int m);
int func11111(char* str[], int n,int m,int l);
int func11112(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // ���������� �� ��������
int func11113(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // ���������� �� ����� �����
int func11114(char str[NSTR][LSTR], int idx[], int n, int m, int l);      // ���������� �� ����� 1-�� �����
int delnl(char* str, int n);
int Exsample11(void)
{
    int i, beg, end,imenu;
    char ch;
    char* menu[] = {
                    "���� ������� �����",
                    "����� ��������� ������ �����",
                    "����� ����� �������� ������������������ ������������� ASCII",
                    "����� ����� � ������� ����������� �����",
                    "����� ����� � ������� ����������� ����� ������� ����� � ������",
                    "����� �� ���������"
    };
    char strings[NSTR][LSTR] = {"123456789","qwertyuio","asdfghjkl"};
    int idx[NSTR];              // ������ �������� ����������
    int nstrings= NSTR;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 11.  ������ �� 10 ����� � ��� �� ��������� EOF � ������� ����\033[0m\n");
    do
    {
        do {
            imenu = menu1111(menu, MMENU);
            if (imenu<1 || imenu>MMENU) break;
            printf("���������� ������ %d-%s\n", imenu, menu[imenu - 1]);
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
int menu1111(char* menu[],int m) {
    int i,n, status;
    char ch;
    bool err = false;
    printf("����������� �������:\n");
    do {
        for(i=0;i<m;i++)
            printf("\033[32m%2d\033[0m.%s\n",i+1,menu[i]);
        printf("������� ����� �������(1-%d):",m);
        ch = getch();
        n = ch - '0';
        err = (n < 1 || n > m);
        if (err) printf(" \033[31m%d.������!\033[0m ����� ������ ����� �� 1 �� %d.\n",n,m);
    } while (err);
    printf("\n");
    return n;
}
int func11110(char str[NSTR][LSTR], int n, int m) {     // ���� �����, ������� ����� �������� �����
    int l=0;
    printf("������� ������ �� ������ %d ���� � �� ������� %d(������ ������ - �����):\n", n,m);
    for (int i = 0; i < n; i++) {
        printf("%2d:", i+1);
        fgets(str[i], m-1, stdin);
        if(!delnl(str[i], m - 1)) break;
        l++;
    }
    return l;
}
int func11111(char str[NSTR][LSTR], int n, int m,int l) {     // ����� �����
    printf("��������� ������:\n", n,m);
    for (int i = 0; i < n; i++) {
        if (strlen(str[i]))
            printf("%d:%s\n", i + 1, str[i]);
        else break;
        if (i >= l) break;
    }

}
int delnl(char* str, int n) {   // �������� � ������ ������ '\n' �� '\0', ���������� ����� ������
    char ch;
    int i = 0;
    while ((ch = *str++) ) {
        if (ch == '\n') { *(str - 1) = '\0'; break; }
        if (i++ >= n) break;
    }
    return i;
}
int func11112(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // ���������� �� ��������
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
int func11113(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // ���������� �� ����� �����
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
int func11114(char str[NSTR][LSTR], int idx[], int n, int m, int l) {      // ���������� �� ����� 1-�� �����
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
int getword(char* str, int n) {         // ���������� ����� 1-�� ����� ������
    char* del = " \t\n\0,.:;-+=!?";     // ����������� ����
    int l = 0;
    l=strcspn(str, del);
    return l;
}
/*
12. �������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� ����������
EOF, � ������� ���������� ����, ���������� ��������� ����, ����������
�������� ����, ���������� ������ ���������� � ����������-����. ����������� ��������� ������� ctype.h.
*/
#define MAX12 100
int countwords(char* str, int n);
int countbig(char* str, int n);        // ���������� ����� ������� ���� � ������
int countlitl(char* str, int n);       // ���������� ����� ��������� ���� � ������
int countpunc(char* str, int n);       // ���������� ����� ������ ���������� � ������
int countdigit(char* str, int n);      // ���������� ����� ���� � ������

int Exsample12(void)
{
    int i, nbig=0, nwords=0,nlittles=0,nsemicoll=0,ndigits=0;
    char ch;
    char str[MAX12] = {'\0'};
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 12. ������� ���������� ����, ��������� ����, �������� ����, ������ ���������� � ����.\033[0m\n");
    do
    {
        printf("������� ������\n:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        nwords = countwords(str, MAX12);
        nbig= countbig( str, MAX12);
        nlittles= countlitl(str, MAX12);
        nsemicoll= countpunc(str, MAX12);
        ndigits = countdigit(str, MAX12);
        printf("����� ����:%d\n����� ������� ����:%d\n����� ��������� ����:%d\n����� ����������:%d\n����� ����:%d\n", nwords, nbig, nlittles, nsemicoll, ndigits);
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
int countwords(char* str, int n) {      // ���������� ����� ���� � ������
    int nword = 1;
    char* del = " \t\n,.:;-+=!?\0";     // ����������� ����
    char* pch = strpbrk(str, del);
    while (pch && *pch != '\n') {
        pch++;
        nword++;
        pch = strpbrk(pch, del);
    }
    return nword;
}
int countbig(char* str, int n) {                // ���������� ����� ������� ���� � ������
    int nbig = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // ���� �� ����� ������
    {
        ch = str[ix];
        if (isupper(ch))                        // ���� ������� ������ - ���������
            nbig++;
        ix++;                                   // ��������� ������� �������� � ������
    }
    return nbig;
}
int countlitl(char* str, int n) {                // ���������� ����� ��������� ���� � ������
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // ���� �� ����� ������
    {
        ch = str[ix];
        if (islower(ch))                        // ���� ������� ������ - ���������
            nlit++;
        ix++;                                   // ��������� ������� �������� � ������
    }
    return nlit;
}
int countpunc(char* str, int n) {                // ���������� ����� ������ ���������� � ������
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // ���� �� ����� ������
    {
        ch = str[ix];
        if (ispunct(ch))                        // ���� ������� ������ - ���������
            nlit++;
        ix++;                                   // ��������� ������� �������� � ������
    }
    return nlit;
}
int countdigit(char* str, int n) {                // ���������� ����� ���� � ������
    int nlit = 0;
    char ch;
    int ix = 0;
    while (str[ix])                             // ���� �� ����� ������
    {
        ch = str[ix];
        if (isdigit(ch))                        // ���� ������� ������ - ���������
            nlit++;
        ix++;                                   // ��������� ������� �������� � ������
    }
    return nlit;
}
/*
13. �������� ���������, ������� ��������� �� ������ ��������� ��������� ������
� �������� �������. ������� �������, ���� ����������� ��������� ������
�������� �� ������� ��������, ������ ��������� ������ ������� �� ����� �������� ������� ��.
*/
#define MAX13 100
int reverse(char* str);    // ������ ���� ������ � �������� �������

int Exsample13(int argc, char* argv[])
{
    int i, nword, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 13. ������ ���� ���������� ��������� ������.\033[0m\n");
    do
    {
        printf("� ��������� ������ %d ����������:\n",argc);
        for (int i = 0; i < argc; i++) printf("%s-", argv[i]);
        printf("\n�����������:\n");
        for (int i = argc - 1; i > 0; i--) {
            if ((nword = countwords(argv[i], MAX13)) == 1)
                printf("%s-", argv[i]);
            else
                reverse(argv[i]);
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
int reverse(char* str) {    // ������ ���� ������ � �������� �������
    char* del = " \t\n,.:;-+=!?\0";     // ����������� ����
    char ch, *chbeg,*chend;
    int ll=0,l = strlen(str);
    while (l >= 0) {
        if (chbeg=strchr(del, *(str + l))) {         // ������ - �����������
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
14. �������� ��������� ���������� ��������� �����������, ������� �������� ��
������ ��������� ������. ������ ���������� ��������� ������ ������ ����
����� ���� double , ���������� � ������������ �������, � ������ ���������� -
������������� ���������� �������.
*/
#include <math.h>
int Exsample14(int argc, char* argv[])      // �����1=double ���������, �����2=int �������
{
    int i, beg, end;
    char ch;
    double d=atof(argv[1]),dpow;
    int powe=atoi(argv[2]);
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 14. ������������� �������.\033[0m\n");
    do
    {
        dpow = pow(d,powe);
        //for (int i = 0; i < pow; i++) dpow *= d;
        printf("������� %d ����� %lf ����� %lf\n", powe, d, dpow);
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
15. ��� ���������� ���������� ������� atoi() ����������� ������� �������������
��������. ��� ������ ������ ���������� �������� 0, ���� ������ ����� ��
�������� ��������� ��������.
*/
int isalldigit(char* str, int n);     // ���������, ��� ��� ������� � ������ �����

int Exsample15(void)
{
    int i, beg, end;
    char ch, * pch;
    char str[MAX12];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 15. �������� ������ �� �����.\033[0m\n");
    do
    {
        printf("������� �����:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        pch = strchr(str, '\n');    // ����� ������� ����� ������
        if (pch)                    // ���� ����� �� �������� NULL,
            * pch = '\0';           // ��������� ���� ������� ������
        if (i = isalldigit(str, MAX12 - 1)) printf("������� ����� %d\n", i);
        else printf("������� �� �����.\n");
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
int isalldigit(char* str, int n) {      // ���������, ��� ��� ������� � ������ �����
    char ch;
    char* pch = str;
    while ((ch = *str++)) {
        if (!isdigit(ch)) return 0;
    }
    return atoi(pch);
}
/*
16. �������� ���������, ������� ������ ������� ������ �� ��� ���, ���� �� ����������
EOF, � ������� �� �� �����. ��������� ������ ������������ � �������������
��������� ��������� ��������� ������:
-� ����� ������� ������ � ��� ����, ��� ����.
-u �������������� ������� ������ � ������� �������.
-l �������������� ������� ������ � ������ �������.
����� ����, ���� �������� ������� ������ �� ������, ��������� ������ �����
���� ���, ��� ���� �� ��� ����� �������� -�.
*/
char getop(char* str);    // ���������� �������� -p -u -l p,u,l
int tolower16(char* str, int n);     // ���������� ������ � ������ �������
int toupper16(char* str, int n);     // ���������� ������ � ������� �������

int Exsample16(void)
{
    int i, beg, end;
    char ch,op,*pch;
    char str[MAX12];
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 16. ���� � �������������� ������ � ������� � ������ ��������.\033[0m\n");
    do
    {
        printf("������� �����:"INPUT3);
        fgets(str, MAX12 - 1, stdin);
        pch = strchr(str, '\n');    // ����� ������� ����� ������
        if (pch)                    // ���� ����� �� �������� NULL,
            *pch = '\0';           // ��������� ���� ������� ������

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
char getop(char* str) {    // ���������� �������� -p -u -l p,u,l
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
int tolower16(char* str, int n) {     // ���������� ������ � ������ �������
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}
int toupper16(char* str, int n) {     // ���������� ������ � ������� �������
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}