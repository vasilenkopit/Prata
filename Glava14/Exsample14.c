//#include <filesystem>
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
void passnl(void) {
	while (getch() == '\n') {};		// ���������� ����� ������
}

/*
���������� �� ���������������� ����� 14.��������� � ������ ����� ������
*/
/*                // ������ ������ 2

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

	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}

*/

bool getYes(char* quest) {
	char ch, * s, * q = "yY��nN��";
	int n;
	printf("%s(��-\033[32myY��\033[0m, ���-\033[32mnN��\033[0m):"INPUT1, quest);
	do {
		ch = getche();
		s = strchr(q, (int)ch);
		if (s != NULL) {
			n = s - q;
			break;
		}
		printf("\n\033[31m������!\033[0m ��������� ���� �� ��������-\033[32m%s\033[0m:"INPUT1, q);
	} while (1);
	//getc(stdin);
	return (n < 4);
}
/*
1. ����������� ������� �� ������� 5 ����� �������, ����� �������� ��� �����������
��������� ������, � �� ��� �������. (�� ��������� � ������� strcmp().)
������������� ������� ������� � ������� ���������.
*/
struct month
{
	char name[10];
	char abr[4];
	int nDdays;
	int num;
};
struct month months1[12] = {
	{"������",	"���",31,1},
	{"�������",	"���",28,2},
	{"����",	"���",31,3},
	{"������",	"���",30,4},
	{"���",		"���",31,5},
	{"����",	"���",30,6},
	{"����",	"���",31,7},
	{"������",	"���",31,8},
	{"��������","���",30,9},
	{"�������",	"���",31,10},
	{"������",	"���",30,11},
	{"�������",	"���",31,12},
};
struct month monthsVisocos[12] = {
	{"������",	"���",31,1},
	{"�������",	"���",29,2},
	{"����",	"���",31,3},
	{"������",	"���",30,4},
	{"���",		"���",31,5},
	{"����",	"���",30,6},
	{"����",	"���",31,7},
	{"������",	"���",31,8},
	{"��������","���",30,9},
	{"�������",	"���",31,10},
	{"������",	"���",30,11},
	{"�������",	"���",31,12},
};
int days1(void);
#define MAX_NAME 20
int Exsample1(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 1. ������� ��������� � ����� � ��������� ���������.\033[0m\n");
	do
	{
		days1();
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
/*
5. �������� �������, ������� ����� ��������� ������ ������ ���������� �����
���������� ���� � ������ ���� �� ����� ���������� ������. ������������, ���
������ ���������, ��������� � ������� 3, � ���������� ������ ����� ��������
��������� ������.
*/
int getPassedDays1(int month) {
	int d = 0;
	if (month < 1 || month>12) return 0;
	for (int i = 1; i <= month; i++) d += months1[i - 1].nDdays;
	return d;
}
int getnumday(char* day) {
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(months1[i].name, day)==0) return i + 1;
	}
	return 0;
}
int getnumdayabr(char* abr) {
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(months1[i].abr, abr)==0) return i + 1;
	}
	return 0;
}
int days1(void) {
	char n[MAX_NAME+1];
	int m;
	printf("\033[1;4;32m�������� ������ 14.5. ���������  days145.c � ����� ������ ���������� ����� ���������� ���� � ������ ���� �� ����� ���������� ������\033[0m\n");
	printf("������� ������� ������(������ - ����� �� ���������):");
	while (scanf_s("%s", n, MAX_NAME) > 0 && n[0]!=' ') {
		m= getnumday(n);
		printf("�� ������ ���� �� ����� %s ������ %d ����.\n", months1[m - 1].name, getPassedDays1(m));
		puts("������� ������� ������(������ - ����� �� ���������):");
	}
	puts("��������� ���������.");
}
/*
2. �������� ���������, ������� ���������� ������������ ������ ����, ����� � ���.
����� ����� ���� ����������� ���������� �������, ��������� ��� �������������.
����� ��������� ������ ���������� ����� ���������� ����, �������� �
������ ���� �� ��������� ���� ������������. (���������� ���������� ����.)
*/
struct Sdate { int day; int month; int year; };
int getmonth(void);
void getdate(struct Sdate* date);
int getPassedDaysVisocos(struct Sdate* date);
int getPassedDaysRegul(struct Sdate* date);
bool isVisocos(int year);
int Exsample2(void)
{
	int passDeys;
	char ch;
	struct Sdate date;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 2. ���������� ����� ���������� ����, �������� � ������ ���� �� ��������� ���� ������������. (���������� ���������� ����.)\033[0m\n");
	do
	{
		puts("");
		getdate(&date);
		if (isVisocos(date.year))
			passDeys=getPassedDaysVisocos(&date);
		else
			passDeys = getPassedDaysRegul(&date);
		printf("");
		printf("������� ���� %d/%d/%d. �� ������ %d ���� �� %d ����� %s ������ %d ����.\n",date.day,date.month,date.year,date.year, date.day, months1[date.month-1], passDeys);
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
void getdate(struct Sdate* date){
	int maxdays;
	printf("������� ���(XXXX):");
	scanf_s("%d", &(date->year));
	date->month = getmonth();
	maxdays = (isVisocos(date->year)) ? monthsVisocos[date->month - 1].nDdays : months1[date->month - 1].nDdays;
	printf("������� ����(1-%d):",maxdays);
	scanf_s("%d", &(date->day));
}
int getmonth(void) {
	char inpt[MAX_NAME+1];
	int n;
	printf("������� �����(���(������), ����������(���) ��� �����(1-12)):");
	scanf_s("%s", inpt, MAX_NAME);
	if ((n = getnumday(inpt)) > 0) return n;
	if ((n = getnumdayabr(inpt)) > 0) return n;
	return atoi(inpt);
}
int getPassedDaysVisocos(struct Sdate* date) {
	int d = 0;
	for (int i = 1; i <= date->month -1; i++) d += monthsVisocos[i - 1].nDdays;
	d += date->day;
	return d;
}
bool isVisocos(int year) {
	return (
			(!(year % 4) && (year % 100)) || 
			(!(year % 400))
		);
}
int getPassedDaysRegul(struct Sdate* date) {
	int d = 0;
	for (int i = 1; i <= date->month - 1; i++) d += months1[i - 1].nDdays;
	d += date->day;
	return d;
}
/*
3. �������� ��������� �� �������� 14.2, ����� ��� ������� �������� ��������
���� � ��� �������, � ����� ��� ���������, ����� � ���������� ������� �� ���������
�, �������, � ������� ����������� ����.
*/
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* ������������ ���������� ���� */
struct book { /* ��������� ������� book */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

struct book library[MAXBKS]; /* ������ �������� ���� book */
enum sorttype{not,name,autor,prise};
void manybook143Sort(int typsort, int count);
int manybook143Input(void);
int cmpname(void* op1, void* op2);
int cmpprise(void* op1, void* op2);
int cmpautor(void* op1, void* op2);
int Exsample3(void)
{
	int i, beg, count;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 3.  �������� ��������� �� �������� 14.2,\n"
		"\t����� ��� ������� �������� �������� ���� � ��� �������, � ����� ��� ���������,\n"
		"\t����� � ���������� ������� �� ��������� �, �������, � ������� ����������� ����.\033[0m\n");
	do
	{
		count=manybook143Input();
		manybook143Sort(not,count);
		manybook143Sort(name,count);
		manybook143Sort(autor, count);
		manybook143Sort(prise, count);
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
int manybook143Input(void)
{
	//struct book library[MAXBKS]; /* ������ �������� ���� book */
	int count = 0;
	int index;
	printf("\033[1;4;32m������� 14.2. ��������� manybook.c -- ������� ��� ���������� ����\033[0m\n");
	printf("������� �������� �����.\n");
	printf("������� [enter] � ������ ������, ����� ��������� ����.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("������ ������� ��� ������.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("������ ������� ����.\n");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n') continue; /* �������� ������� ������ */
		if (count < MAXBKS) printf("������� �������� ��������� �����.\n");
	}
	return count;
}
void manybook143Sort(int type, int count) {
	struct book lib[MAXBKS];
	int i=0;
	if (count < 1) {
		printf("������ ��� ����? ����� �����.\n");
		return;
	}
	memcpy(lib, library, sizeof(library));
	printf("������� �����(%d) ����", count);
	switch (type) {
	case not:
		printf(" � ����������:\n");
		break;
	case name:
		printf(" � ������� ��������:\n");
		qsort(lib, count,sizeof( struct book), cmpname);
			break;
	case autor:
		printf(" � ������� �������:\n");
		qsort(lib, count, sizeof(struct book), cmpautor);
		break;
	case prise:
		printf(" � ������� ���:\n");
		qsort(lib, count, sizeof(struct book), cmpprise);
		break;
	default:
		break;
	}
	for (int index = 0; index < count; index++)
		printf("%3d:%s ��������� %s: $%.2f\n", index + 1, lib[index].title,	lib[index].author, lib[index].value);
}
int cmpname(void* op1,void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return strcmp(pb1->title, pb2->title);
}
int cmpprise(void* op1, void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return pb1->value>=pb2->value;
}
int cmpautor(void* op1, void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return strcmp(pb1->author, pb2->author);
}
/* 
4. �������� ���������, ������� ������� ������ ��������� � ����� ������� � ������������
   �� ���������� ����������.
�.	������ ������ �������� ����� �������� ����������� �����������. 
	������ ���� � ��� ���������, ��������� �� ���� ������. 
		�� ������ ���� �������� ���, 
		������ ���� � �������� � 
		������ ���� � �������. 
	�������� � ��������������� ������ �� ���� ����� ��������. 
	��������� ������ �������� ������ � ��������� �������:
Dribble, Flossie �. � 302039823
���������� ������ ������ ��������� ����� ��������, �� ������� ������� �����.
����������, ���� ���� ���� ����, �� ������ ���������� �� �������, �� �����.
�������� �������, ������� ��������� ����� �����, ��������� ��������������� ��������� ���� �������.
�. ������������� ����� �) ���, ����� ������ ������ ������������ ���� ���������.
*/
#define MAX1NAME 10
#define MAX2NAME 20
#define MAX3NAME 20
#define MAXCARDS 10
struct NAME { 
	char name1[MAX1NAME+1];
	char name2[MAX2NAME + 1];
	char name3[MAX3NAME + 1];
};
struct SICARD {					// social insurance card
	int sinum;
	struct NAME siname;
};
//struct SICARD* psicCard = NULL;
void sicOut1(struct SICARD sic);
void sicOut2(struct SICARD* sic);
int sicCreate(struct SICARD* sic, int max);
int Exsample4(void)
{
	int n, beg, end;
	char ch;
	struct SICARD* psicCard = NULL;

	//struct SICARD* psicCard=NULL;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 4. ������ ������ ����� ����������� �����������.\033[0m\n");
	do
	{
		n = sicCreate(&psicCard, MAXCARDS);
		for (int i = 0; i < n; i++)	{
			sicOut1(psicCard[i]);
		}
		for (int i = 0; i < n; i++)	{
			sicOut2(&psicCard[i]);
		}
		free(psicCard);
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
int sicCreate(struct SICARD** psic,int max) {
	int n, sinum;
	char siname1[MAX1NAME + 1], siname2[MAX2NAME + 1], siname3[MAX3NAME+1];
	printf("\n�������� ������� �������� ����������� �����������.\n");
loop:
	printf("������� �������� �������(�� ������ %d):", max);
	scanf_s("%d",&n);
	if (n == 0 | n > MAXCARDS) {
		printf("\033[31m������!\033[0m ������� %d. ��������� ����� >0 � < %d.\n",n,MAXCARDS);
		//passnl();
		goto loop;
	}
	if ((*psic = (struct SICARD*)calloc(n, sizeof(struct SICARD))) == NULL) {
		printf("\033[31m������!\033[0m ������������ ������(��������� %d����)./n",n* sizeof(struct SICARD));
		return 0;
	}
	//psicCard = psic;
	for (int i = 0; i < n; i++) {
		printf("�������� %d. ������� ����� ������� ��� ��������(����� ������):", i+1);
		if (scanf_s("%d %s %s %s", &sinum, siname1, MAX1NAME, siname2, MAX2NAME, siname3, MAX3NAME) == 4) {
			//passnl();
		}
		else {
			printf("\033[31m������!\033[0m ������� �� 4 ��������. ��������� ����.\n");
			i--;
			passnl();
			continue;
		}
		(*psic)[i].sinum = sinum;
		siname1[0] = toupper(siname1[0]);
		siname2[0] = toupper(siname2[0]);
		siname3[0] = toupper(siname3[0]);
		strcpy_s((*psic)[i].siname.name1,MAX1NAME, siname1);
		strcpy_s((*psic)[i].siname.name2,MAX1NAME, siname2);
		strcpy_s((*psic)[i].siname.name3,MAX1NAME, siname3);
	}
	return n;
}
void sicOut1(struct SICARD sic) {
	//char* s = "A.";
	//s[0] = sic.siname.name3[0];
	printf("%d \t%s \t%s \t%c.\n", sic.sinum, sic.siname.name1, sic.siname.name2, sic.siname.name3[0]);
}
void sicOut2(struct SICARD* sic) {
	//char* s = "A.";
	//s[0] = sic.siname.name3[0];
	printf("%d \t%s \t%s \t%c.\n", sic->sinum, sic->siname.name1, sic->siname.name2, sic->siname.name3[0]);
}
/*
5. �������� ���������, ������� ������������� ��������� �����������.
�. ��������� ������ ���������� ������ �������� name � ����� �������: 
	������� ��� �������� ����� � ������� ��� �������� �������.
�. ��������� ������ ���������� ������ ��������� student � ����� �������:
	���������� name, �������� grade ��� �������� ���� ������ � ���� ����� � ��������� 
	������� � ���������� ��� �������� �������� �������� ���� ���� ������.
�. ��������� �������� ������� main (), ��� ����������� ������ �� CSIZE(=4)
	�������� student, � ������� ���������������� ����� name ������� �� ������ ������. 
	��� ���������� �����, ��������� � ������ �), �),�) � �), ����������� �������.
�. ��������� ������������ ������ ������ ��� ������� ��������, ����������
	� ������������ ���� ����� �������� � ��� ������. ��������� ������ � ������
	grade ��������������� ���������. ��������� ���� ����� ����������� �
	main () ��� � ����������� ������� �� ������ ����������.
�. ��������� ��������� ������� ������ ��� ������ ��������� � �����������
	�� ���������������� �����.
�. ��������� ������� ���������� �� ������ ���������.
�. ��������� ������� ������� �������� �� ����� ��� ������� ��������� ����� ���������.
*/
#define MAXNAME 20
#define MAXSTUDENT 100
struct name {
	char name[MAXNAME];
	char fname[MAXNAME];
};
struct student {
	struct name;
	float grade[3];
	float average;
};
int studCreate(struct student** stdAr);
void studOut(struct student** stdAr, int n);
void studCount(struct student** stdAr, int n);
void studAverage(struct student** stdAr, int n);
int Exsample5(void)
{
	int i, beg, count;
	char ch;
	struct student (*studAr)[];
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� . ������ ���������.\033[0m\n");
	do
	{
		count = studCreate(&studAr);
		studCount(&studAr, count);
		studOut(&studAr, count);
		studAverage(&studAr, count);
		free(studAr);
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
int studCreate(struct student** stdAr) {
	struct name name[MAXSTUDENT];
	float grade[MAXSTUDENT][3];
	int count=0,status;
	printf("���� ������ ������������ ���������.\n�������: ������� ��� ������1 ������2 ������3(����� ������. 0-����� �����).\n");
	do {
		printf("������� %d:", count + 1);
		status=scanf_s("%s %s %f %f %f", name[count].fname, MAXNAME, name[count].name, MAXNAME, &grade[count][0], &grade[count][1], &grade[count][2]);
		if (status != 5) {
			printf("\033[31m������!\033[0m ������� �� 5 ��������. ��������� ����.\n");
			passnl();
			continue;
		}
		if (name[count].fname[0] == '0') break;
	} while (++count < MAXSTUDENT);
	if (count == 0) {
		printf("� ������ �� ������� �� ������ ��������.\n");
		return 0;
	}
	if ((*stdAr = (struct SICARD*)calloc(count, sizeof(struct student))) == NULL) {
		printf("\033[31m������!\033[0m ������������ ������(��������� %d ����)./n", count * sizeof(struct student));
		return 0;
	}
	for (int i = 0; i < count; i++)	{
		for (int j = 0; j < 3;j++ )(*stdAr)[i].grade[j] = grade[i][j];
		strcpy_s((*stdAr)[i].fname, MAXNAME, name[i].fname);
		strcpy_s((*stdAr)[i].name, MAXNAME, name[i].name);
	}
	return count;
}
void studOut(struct student** stdAr, int n) {
	printf("������ ������������ ���������:\n");
	printf("��� ������� \t��� \t\t\t\t������1 ������2 ������3 �������\n");
	for (int i = 0; i < n; i++)	{
		printf("%3d %s \t%s \t\t\t\t%7.1f %7.1f %7.1f %7.1f\n", 
			i + 1, (*stdAr)[i].fname, (*stdAr)[i].name, 
			(*stdAr)[i].grade[0], (*stdAr)[i].grade[1], 
			(*stdAr)[i].grade[2], (*stdAr)[i].average);
	}
}
void studCount(struct student** stdAr, int n) {
	float av=0.;
	for (int i = 0; i < n; i++) {
		av = 0.;
		for (int j = 0; j < 3; j++)	{
			av += (*stdAr)[i].grade[j];
		}
		(*stdAr)[i].average=av/3.;
	}
}
void studAverage(struct student** stdAr, int n) {
	float av1 = 0., av2 = 0., av3 = 0., av = 0.;
	printf("������� ������ �� ������ ���������:\n");
	for (int i = 0; i < n; i++) {
		av1 += (*stdAr)[i].grade[0];
		av2 += (*stdAr)[i].grade[1];
		av3 += (*stdAr)[i].grade[2];
		av += (*stdAr)[i].average;
	}
	printf("������1=%5.1f\n", av1 / (float)n);
	printf("������2=%5.1f\n", av2 / (float)n);
	printf("������3=%5.1f\n", av3 / (float)n);
	printf("�������=%5.1f\n", av / (float)n);
}
/*
6. ��������� ���� �������� ���������� � ������� �� �������� (������������� ��������). 
� ������ ������ ������ ����������� ��������� �������:
4 ������ ������� 5 2 1 1
������ ������ �������� ����� ������ (������ ��� ����� �� ��������� 0-18).
������ ���� � ��� ��� ������, � ������ � ��� �������. ������ ��� ������� ��
������ �����. ��������� ���� ����������, 
������� ��� ����� �������� ���, 
�� ������� ������� ���������� ���������� ������� ������, 
�������� � 
����������� ��������. 
���� ����� ��������� ���������� ����� ��� ����� ����, �������������,
��� ������ � ���� �� ������ ����� ���� ��������� �����. 
�������� ���������, ������� ��������� ��������������� ������ � ������� ��������.
��������� ������ �������� �� ������, � ������� ������������ ������� � ���,
���������� ��������� �����, �������� � ����������� ��������, � ����� �������
��������� (��� �������� ����������� �����). � �������� ������� �������
������ ������������ ����� ������. ��������� ������ ��������� ������ ��
����� �����, � ����������� �������� ���������� �� ������� ������.
��� ���������� �������� �������� ������. ��������, ������ ��� ������ ����
� ���������� ������ �� ������������� ��� �� ������, ��� ��� �� ����� ���������,
���������� �� ���� ������� �����, ������ �� ��������� �������� ����������
��������. �� ��� ��������� ������ ������ ������ � ������������ �����
������, ��� ������� ����, �� �������� � �������������� ������.
���������� ������ ��������������� ������������� ����������� ���������
������, ������ ������ �� ����� �� ��������� ���������� � ����� �� ����������
� ����������� ��������������� ���������. ����� ����, ��� ��������� ��������
������ �����, ��� ������ ��������� ������� ������� ���������� ���
������� ������ � ��������� ��� � ��������������� ����� ���������. �������
������� ���������� ����������� ����� ������� ������������ ����� ������, �����������
�������, �� ���������� ������� �� ������� �������; ����������
������ ���� � ��������� �������. ����� ��������� ������ ���������� �������������
������ �� ������� ������ ������ �� �������, � ������� ����������
��������� �������������� ������ �� ���� �������.
*/
#define MAXBALL 20
struct ball {
	int take;
	int hit;
	int pass;
	int jog;
};
struct softball {
	int numb;
	struct name;
	struct ball;
};
int softballCreate(struct softball* sb, int max, struct name* names, int N);
int NameListCreate(int max, char* filename, struct name* names, int N);
void NamesPrint(struct name* names, int n);
void FileNamesWrite(FILE* file, struct name* names, int n);

int Exsample6(void)
{
	int i, beg, count, countName;
	char ch;
	char FileName[MAX_NAME]="NameList.txt";
	struct name names[MAXSTUDENT];
	struct softball(* softballs)[]=NULL;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 6. ���������� ������� �� ��������.\033[0m\n");
	do
	{
		countName= NameListCreate(MAXSTUDENT, FileName, names, MAXSTUDENT);
		count = softballCreate(softballs, MAXBALL, names, countName);
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
int softballCreate(struct softball** sb, int max, struct name *names,int N) {
	//struct name name[MAXSTUDENT];
	struct ball balls[MAXSTUDENT];
	int numbs[MAXSTUDENT];
	int i = 0, status, count;
	printf("���� �������������� ������ ������� ���������.\n�������: ����� ������ �������� ��������(����� ������. 0-����� �����).\n");
	do {
		printf("����� %d: %s %s ", i + 1,names[i].fname, names[i].name);
		status = scanf_s("%d %d %d %d", &balls[i].take, &balls[i].hit, &balls[i].pass, &balls[i].jog);
		if (names[i].fname[0] == '0' || i+1>=N) break;
		if (status != 4) {
			printf("\033[31m������!\033[0m ������� �� 4 �����. ��������� ����.\n");
			passnl();
			continue;
		}
		i++;
	} while (i < MAXSTUDENT);
	if (i == 0) {
		printf("� ������ �� ������� �� ������ ����������.\n");
		return 0;
	}
	count = i+1;
	if ((sb = (struct SICARD*)calloc(count, sizeof(struct student))) == NULL) {
		printf("\033[31m������!\033[0m ������������ ������(��������� %d ����).\n", count * sizeof(struct student));
		return 0;
	}
	for (int i = 0; i < count; i++) {
		//for (int j = 0; j < 3; j++)
		//memcpy_s( (*sb)[i].take, sizeof(struct ball), &balls[i], sizeof(struct ball));
		/**/
		(*sb)[i].take = balls[i].take;
		(*sb)[i].hit  = balls[i].hit;
		(*sb)[i].pass = balls[i].pass;
		(*sb)[i].jog  = balls[i].jog;
		strcpy_s((*sb)[i].fname, MAXNAME, names[i].fname);
		strcpy_s((*sb)[i].name, MAXNAME, names[i].name);
		/**/
	}
}
int NameListCreate(int max,char* filename, struct name* names, int N) {
	//struct name names[MAXSTUDENT];
	int status,count = 0;
	FILE* file;
	status = fopen_s(&file, filename, "r");
	if (!status) {
		count = FileNamesRead(file, names, MAXSTUDENT);
		fclose(file);
		NamesPrint(names, count);
	}
	else {
		printf("���� ��� �������. �������: ������� ���.(0-����� �����).\n");
		do {
			printf("����� %d:", count + 1);
			status = scanf_s("%s %s", names[count].fname, MAXNAME, names[count].name, MAXNAME);
			if (names[count].fname[0] == '0') break;
			if (status != 2) {
				printf("\033[31m������!\033[0m ������� �� 2 ��������. ��������� ����.\n");
				passnl();
				continue;
			}
			count++;
		} while (count < max);
		status = fopen_s(&file, filename, "w");
		if (status) perror("������ �������� ����� ��� ������");
		else {
			FileNamesWrite(file, names, count);
			fclose(file);
		}
	}

	return count;
}
int FileNamesRead(FILE* file,struct name* names,int max) {
	int status,count=0;
	do
	{
		status = fread_s(&names[count], sizeof(struct name), sizeof(struct name), 1, file);
		if (status > 0) count++;
	} while (status > 0);
	return count;
}
void NamesPrint(struct name* names,int n) {
	printf("������ �������:\n");
	for (int i = 0; i < n; i++)	{
		printf("%2d %s \t%s\n",i+1,names[i].name,names[i].fname);
	}
}
void FileNamesWrite(FILE* file, struct name* names, int n) {
	int idx = 0;
	//while (idx<n) {
		fwrite(names,sizeof(struct name),n,file);
	//}
}
/*
7. ������������� ��� � �������� 14.14 ���, ����� ������ ������ �������� �� ����� � ������������,
����� ���� ����������� ������� ������, � ����� ���� �������� �� ����������. 
���� �� �������� ������, ����������� �������������� ������� ������� ��� ������ ��������� ������. 
����� ��������� ��������� ������������� �����������, ������ ������ "�+�" ���������� ��������� "r+b"
� ������� ������ �������� ��������� ��������� � �����, �� �������� ��������������� ������������ ������� ������������ ��������. 
����� ����� ������ ��� ��������� � ������, ���������� � ������, � ����� �������� ��� ���������
���������� � ����. ���� �� ��������� �������� � ������������ ���������
������������ ���������� � ��������� �������� �����, ������� ���������, ������ �� �� ���� ������.
*/
// ������� 14. 14. ��������� booksave.�
/* booksave.c � ���������� ����������� ��������� � ����� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10		/* ������������ ���������� ���� */
//char* s_gets(char* st, int n);
struct book14 { /* ����������� ������� book */

	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct Library {
	int booksCount;
	struct book14* books;
};
void inBook(int c);
void delBook();
void listBook(FILE* pbooks, char* filename, int *count, int size);
void editBook();
void createLib(char* filename);
int Exsample7(void)
{
	struct book14 library[MAXBKS];	/* ������ �������� */
	struct Library lib;
	lib.books = library;
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book14);
	char* filename = "books.dat";
	printf("\033[1;4;32m������� 14.14. ���������  booksave.c � ���������� ����������� ��������� � �����\033[0m\n");
	//createLib(filename);
	if ((fopen_s(&pbooks, filename, "a+b")) != NULL)
	{
		printf("\033[31m������!\033[0m �� ������� ������� ���� %s. ", filename);
		perror("");
		createLib(filename);
		//exit(1);
	}
	//listBook(pbooks, filename, &count, size);
	//rewind(pbooks); /* ������� � ������ ����� */
	//while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	//{
	//	if (count == 0)	printf("������� ���������� ����� %s:\n", filename);
	//	printf("%2d: %s ��������� %s: $ %.2f\n",
	//		count + 1, library[count].title, library[count].author, library[count].value);
	//	count++;
	//}
	filecount = count;
	if (count == MAXBKS)
	{
		printf("�a�� %s ��������.\n", filename);
		exit(2);
	}
	puts("0-������� ����������\n1-����� ������ ����\n2-�������� �����\n3-������� �����\n4-�������� �����\0-���������:");
	char code[2];
	s_gets(code, 2);
			switch (code[0]) {
	case '0':
		createLib(filename);
		break;
	case '1':
		listBook(pbooks, filename, &count, size);
		break;
	case '2':
		inBook(count);
		break;
	default:
		break;
	}
	if (count > 0)
	{
		puts("������� ����� ����:");
		for (index = 0; index < count; index++)
			printf("%2d: %s ��������� %s: $%.2f\n", index + 1, library[index].title, library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("������ ��� ����? ����� �����.\n");
	puts("��������� ���������.\n");
	fclose(pbooks);
	return 0;
}

//#include <string>
void inBook(int count) {
	puts("������� �������� ����� ����.");
	puts("������� [enter] � ������ ������, ����� ��������� ����.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("������ ������� ��� ������.");
		s_gets(library[count].author, MAXAUTL);
		puts("Te�ep� ������� ���� �����.");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n') 	continue; /* �������� ������� ������ */
		if (count < MAXBKS) 	puts("������� �������� ��������� �����.");
	}

}
void listBook(FILE* pbooks,char* filename,int *count,int size) {
	int c = *count;
	rewind(pbooks); /* ������� � ������ ����� */
	while (count < MAXBKS && fread(&library[c], size, 1, pbooks) == 1)
	{
		if (count == 0)	printf("������� ���������� ����� %s:\n", filename);
		printf("%2d: %s ��������� %s: $ %.2f\n",
			count + 1, library[c].title, library[c].author, library[c].value);
		c++;
	}
}
void createLib(char* filename) {
	char sfile[MAXNAME];// = "-------------------------------------------------------------------";
	char quest[100] = "������� ���� ���������� ";// +filename + ".������� ����� ?";
	strcpy_s(sfile, MAXNAME,filename);
	strcat_s(quest,100, sfile);
	strcat_s(quest, 100, ".������� ����� ?");
	int status;
	if (getYes(quest)) {
		printf("\n����� ��� �����:");
		status = scanf_s("%s", filename, MAXNAME);
	}
	//bool exist = std::filesystem::exists(filename);
}

