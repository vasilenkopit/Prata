#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// ������� 14.1. ��������� ���.�
/* book.c � ������� ��� ����� ����� */
#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // ����� ����� ������
		if (find) // ���� ����� �� ����� NULL,
			*find = '\0'; // ��������� ���� ������� ������
		else
			while (getchar() != '\n')
				continue; // ��������� ������� ������
	}
	return ret_val;
}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val) {
//		find = strchr(st, '\n'); // ����� ����� ������
//		if (find) // ���� ����� �� ����� NULL,
//			*find = '\0'; // ��������� ���� ������� ������
//		else
//			while (getchar() != '\n')
//				continue; // ��������� ������� ������
//	}
//	return ret_val;
//}
char* s_gets(char* st, int n);
#define MAXTITL 41	/* ������������ ����� �������� + 1 */
#define MAXAUTL 31	/* ������������ ����� ����� ������ + 1 */
struct book {		/* ������ ���������: ������������ �������� book */
char title[MAXTITL];
char author[MAXAUTL];
float value;
};					/*����� ������� ��������� */
int book(void)
{
	struct book library;				/* ���������� library � �������� ���������� ���� book */
	printf("\033[1;4;32m������� 14.1. ��������� ���.�  � ������� ��� ����� �����\033[0m\n");
	printf("������� �������� �����.\n");
	s_gets(library.title, MAXTITL);			/* ������ � ������� �������� ����� */
	printf("������ ������� ��� ������.\n");
	s_gets(library.author, MAXAUTL);
	printf("������ ������� ����.\n");
	scanf_s("%f", &library.value);
	printf("%s ��������� %s: $%.2f\n", library.title,library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
	printf("������.\n");
	return 0;
}
// ������� 14.2. ��������� manybook.c
/* manybook.c -- ������� ��� ���������� ���� */
#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* ������������ ���������� ���� */
//struct book { /* ��������� ������� book */
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//};
int manybook(void)
{
	struct book library[MAXBKS]; /* ������ �������� ���� book */
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
	if (count > 0){
		printf("������� �����(%d) ����:\n",count);
		for (index = 0; index < count; index ++)
			printf("%3d:%s ��������� %s: $%.2f\n",index+1, library[index].title,
				library[index].author, library[index].value);
	}
	else
		printf("������ ��� ����? ����� �����.\n");
	return 0;
}
// ������� 14.3. ��������� friend.c
// friend.c -- ������ ��������� ���������
#include <stdio.h>
#define LEN 20
const char* msgs[5] =
{
	" ��������� ��� �� ������� ����������� �����, ",
	"�� ���������� ������������������, ��� ",
	"������ ����� ������ ��� �������. �� ����������� ������ �����������",
	"�� �������������� ������ � ",
	" � ������ �������� �����."
};
struct names{				// ������ ���������
	char first[LEN];
char last[LEN];
};
struct guy{					// ������ ���������
	struct names handle;	// ��������� ���������
char favfood[LEN];
char job[LEN];
float income;
};
int friend13(void)
{
	struct guy fellow = {	// ������������� ����������
		{"�����", "����" },
			"����������� �������",
			"������������ ������",
			68112.00
	};
	printf("\033[1;4;32m������� 14.3. ��������� friend.c -- ������ ��������� ���������\033[0m\n");
	printf("������� %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s%s\n", " ", "�� ������ �������,");
	printf("%40s%s\n", " ", "�����");
	return 0;
}
// ������� 14.4. ��������� friends. �
/* friends.c -- ������������� ��������� �� ��������� */
#include <stdio.h>
#define LEN 20
//struct names {
//	char first[LEN];
//	char last[LEN];
//};
//struct guy{
//	struct names handle;
//	char favfood[LEN];
//	char job[LEN];
//	float income;
//};
int friends(void)
{
	struct guy fellow[2] = {
		{{"�����", "����" },
		"����������� �������",
			"������������ ������",
			68112.00
			},
		{{ "����", "������" },
			"������ �������",
			"�������� ��������",
			232400.00
		}
	};
	struct guy* him;			/* ��������� �� ��������� */
	printf("\033[1;4;32m������� 14.4. ��������� friends.c -- ������������� ��������� �� ���������\033[0m\n");
	printf("a�pec #1: \t%p #2: \t%p (#2-#1): \t%d\n", &fellow[0], &fellow[1], &fellow[1]- &fellow[0]);
	him = fellow;			/* �������� ���������, �� ��� ���������  him = &fellow[0];*/
	printf("��������� #1: \t%p #2: \t%p ������ ���������: %d\n", him, him + 1,sizeof(struct guy));
	printf("him->income �����: \t$%.2f \t(*him).income �����: \t$%.2f\n", him->income, (*him).income);
	him++;						/* ��������� �� ��������� ��������� */
	printf("him->favfood �����: \t%s \thim->handle.last �����: \t%s\n", him->favfood, him->handle.last);
	return 0;
}
// ������� 14.5. ��������� fundsl. �
/* funds1.c -- �������� ������ ��������� � �������� ���������� */
#include <stdio.h>
#define FUNDLEN 50
struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum(double, double);
double sumstruct(const struct funds);	/* �������� �������� ���������� */
double sumpointer(struct funds*);		/* �������� �������� ���������� �� ��������� */
int funds1(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	printf("\033[1;4;32m������� 14.5-6-7. ��������� funds1.c -- �������� ������ ��������� � �������� ����������\033[0m\n");
	printf("����� ����� �� ������ � ����� ���������� $ %.2f.\n",sum(stan.bankfund, stan.savefund));
	printf("�������� - ��������� �� ���������:\nO��a� ����� �� ������ � ����� ���������� $%.2f.\n", sumpointer(&stan));
	printf("�������� - ���������:\nO��a� ����� �� ������ � ����� ���������� $%.2f.\n", sumstruct(stan));
	return 0;
}
/* ������������ ���� ����� ���� double */
double sum(double �, double �)
{
	return(� + �);
}
double sumpointer(const struct funds* money)
{
	return(money->bankfund + money->savefund);
}
double sumstruct(const struct funds money)
{
	return(money.bankfund + money.savefund);
}
// ������� 14.8. ��������� nameesl. �
/* names1.c -- ���������� ��������� �� ��������� */
#include <stdio.h>
#include <string.h>
#define NLEN 30
struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};
void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
char* s_gets(char* st, int n);
struct namect getinfoStr(void);
struct namect makeinfoStr(struct namect);
void showinfoStr(struct namect);

int names1(void)
{
	struct namect person;
	printf("\033[1;4;32m������� 14.8. ��������� names1.c -- ���������� ��������� �� ���������\033[0m\n");
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	printf("����������� 14.9 ��� ��������� ������� � �����������-�����������.\n");
	person = getinfoStr(person);
	person = makeinfoStr(person);
	showinfoStr(person);

	return 0;
}
void getinfo(struct namect* pst)
{
	printf("������� ���� ���.\n");
	s_gets(pst->fname, NLEN);
	printf("������� ���� �������.\n");
	s_gets(pst->lname, NLEN);
}
void makeinfo(struct namect* pst)
{
	pst->letters = strlen(pst->fname) +	strlen(pst->lname);
}
void showinfo(const struct namect* pst)
{
	printf("%s %s, ���� ��� � ������� �������� %d ����.\n",	pst->fname, pst->lname, pst->letters);
}
//---------------�������� ������� � �����������-�����������--------------------------
struct namect getinfoStr(void)
{
	struct namect temp;
	printf("������� ���� ���.\n");
	s_gets(temp.fname, NLEN);
	printf("������� ���� �������.\n");
	s_gets(temp.lname, NLEN);
	return temp;
}
struct namect makeinfoStr(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}
void showinfoStr(struct namect info)
{
	printf("%s %s, ���� ��� � ������� �������� %d ����.\n", info.fname, info.lname, info.letters);
}
// ������� 14.10. ��������� names3.c
// names3.c -- ������������� ���������� � ������� malloc()
#include <stdio.h>
#include <string.h> // ��� strcpy (), strlen()
#include <stdlib.h> // ��� malloc (), free()
#define SLEN 81
struct namect1410 {
	char* fname; // ������������� ����������
	char* lname;
	int letters;
};
void getinfo1410(struct namect1410*); // ��������� ������
void makeinfo1410(struct namect1410*);
void showinfo1410(const struct namect1410*);
void cleanup1410(struct namect1410*); // ������������ ������, ����� ��� ������ �� �����
char* s_gets(char* st, int n);
int names3(void)
{
	struct namect1410 person;
	printf("\033[1;4;32m������� 14.10. ��������� names3.c -- ������������� ���������� � ������� malloc()\033[0m\n");
	getinfo1410(&person);
	makeinfo1410(&person);
	showinfo1410(&person);
	cleanup1410(&person);
	return 0;
}
void getinfo1410(struct namect1410* pst)
{
	char temp[SLEN];
	printf("������� ���� ���.\n");
	s_gets(temp, SLEN);
	// ��������� ������ ��� �������� �����
	pst->fname = (char*)malloc(strlen(temp) + 1);
	// ����������� ����� � ���������� ������
	strcpy_s(pst->fname, strlen(temp)+1, temp);
	printf("������� ���� �������.\n");
	s_gets(temp, SLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy_s(pst->lname, strlen(temp)+1, temp);
}
void makeinfo1410(struct namect1410* pst)
{
	pst->letters = strlen(pst->fname) +	strlen(pst->lname);
}
void showinfo1410(const struct namect1410* pst)
{
	printf("%s %s, ���� ��� � ������� �������� %d ����.\n",	pst->fname, pst->lname, pst->letters);
}
void cleanup1410(struct namect1410* pst)
{
	free(pst-> fname);
	free(pst-> lname);
}
// ������� 14. 11. ��������� complit.�
/* complit.c -- ��������� �������� */
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31
struct book1411 {			// ������ ���������: book - ����������
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct rect{ double x; double y; };
double rect_area(struct rect r) { return r.x * r.y; }
double rect_areap(struct rect* rp) { return rp->x * rp->y; }
int complit(void)
{
	struct book1411 readfirst;
	int score;
	printf("\033[1;4;32m������� 14.11. ��������� complit.c -- ��������� ��������\033[0m\n");
	printf("������� �������: ");
	scanf_s("%d", &score);
	if (score >= 84)
		readfirst = (struct book1411){ "������������ � ���������","����� �����������",11.25 };
	else
		readfirst = (struct book1411){ "�������� ����� ������� ������","���� ������",5.99 };
	printf("����������� ���� ��������:\n");
	printf("%s �� %s: $%.2f\n",readfirst.title,readfirst.author, readfirst.value);

	double area1,area2;
	area1 = rect_area((struct rect){ 10.1, 20.1 });
	area2 = rect_areap(&(struct rect) { 100.5, 200.5 });
	printf("����������� �������� ������� ��������� ������� � ����� ����.��������.\narea1=%lf \tarea2=%lf\n",area1,area2);
	return 0;
}
// ������� 14.12. ��������� flexmemb.�
// flexmemb.c --���� ���� ������� �������(�������� �99)
#include <stdio.h>
#include <stdlib.h>
struct flex
{
	size_t count;
	double average;
	double scores[]; // ���� � ����� ������� �������
};
void showFlex(const struct flex* �);
int flexmemb(void)
{
	struct flex* pf1, * pf2;
	int n = 5;
	int i;
	int tot = 0;
	printf("\033[1;4;32m������� 14.12. ���������  flexmemb.c --���� ���� ������� �������(�������� �99)\033[0m\n");
	// ��������� ������ ��� ��������� � �������
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf1->count = n;
	for (i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0 - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);
	n = 9;
	tot = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; i++)
	{
		pf2->scores[i] = 20.0 - i / 2.0;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
	return 0;
}
void showFlex(const struct flex* p)
{
	int i;
	printf("��������: ");
	for (i = 0; i < p->count; i++)
		printf("%g ", p->scores[i]);
	printf("\n������� ��������: %g\n", p->average);
}
// ������� 14.13. ��������� funds4.�
/* funds4.c � �������� ������� ������� �������� */
#include <stdio.h>
#define FUNDLEN 50
#define N 2
struct funds1413 {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum1413(const struct funds1413 money[], int n);
int funds4(void)
{
	struct funds1413 jones[N] = {
		{"Garlic-Melon Bank",  4032.27, "Lucky's Savings and Loan",	8543.94},
		{"Honest Jack's Bank", 3620.88, "Party Time Savings",		3802.91}
	};
	printf("\033[1;4;32m������� 14.13. ���������  funds4.c � �������� ������� ������� ��������\033[0m\n");
	printf("����� ����� �� ������ � ������� ���������� $%.2f.\n", sum1413(jones,N));
	return 0;
}
double sum1413(const struct funds1413 money[], int n)
{
	double total;
	int i;
	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;
	return(total);
}
// ������� 14. 14. ��������� booksave.�
/* booksave.c � ���������� ����������� ��������� � ����� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10		/* ������������ ���������� ���� */
char* s_gets(char* st, int n);
struct book14{ /* ����������� ������� book */
	
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int booksave(void)
{
	struct book14 library[MAXBKS];	/* ������ �������� */
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof (struct book14);
	char* filename = "books.dat";
	printf("\033[1;4;32m������� 14.14. ���������  booksave.c � ���������� ����������� ��������� � �����\033[0m\n");
	if ((fopen_s(&pbooks, filename, "a+b") ) != NULL)
	{
		printf ("\033[31m������!\033[0m �� ������� ������� ���� %s. " , filename);
		perror("");
		exit (1) ;
	}
	rewind(pbooks); /* ������� � ������ ����� */
	while (count < MAXBKS && fread(&library[count], size,1, pbooks) == 1)
	{
		if (count == 0)	printf("������� ���������� ����� %s:\n", filename);
		printf("%2d: %s ��������� %s: $ %.2f\n", 
			count+1,library[count].title,library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		printf("�a�� %s ��������.\n", filename);
		exit(2);
	}
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
	if (count > 0)
	{
		puts("������� ����� ����:");
		for (index = 0; index < count; index++)
			printf("%2d: %s ��������� %s: $%.2f\n",index+1, library[index].title,library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("������ ��� ����? ����� �����.\n");
	puts("��������� ���������.\n");
	fclose(pbooks);
	return 0;
}
// ������� 14.15. ��������� enwn.�
/* enum.c -- ������������� ������������ �������� */
#include <stdio.h>
#include <string.h> // ��� strcmp(), strchr()
#include <stdbool.h> // �������� �99
char* s_gets(char* st, int n);
enum spectrurn			{ red,   orange,   yellow,   green,   blue,   violet ,cyan};
const char* colors[] =	{"red", "orange", "yellow",	"green", "blue", "violet","cyan"};
const char* colorsRus[]={"�������", "���������", "�����",	"������", "�����", "����������","�������"};
#define LEN 30
int enum14(void)
{
	char choice[LEN];
	enum spectrurn color;
	bool color_is_found = false;
	printf("\033[1;4;32m������� 14.15. ���������  enum.c -- ������������� ������������ ��������\033[0m\n");
	puts("������� ���� (��� ������ ������ ��� ������):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0'){
		for (color = red; color <= cyan; color++) {
			if (strcmp(choice, colors[color]) == 0|| strcmp(choice, colorsRus[color]) == 0) {
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color) {
			case red: puts("���� �������.");
				break;
			case orange: puts("���� ���������.");
				break;
			case yellow: puts("���������� ������.");
				break;
			case green: puts("����� �������.");
				break;
			case blue: puts("������������ �����.");
				break;
			case violet: puts("������ ����������.");
				break;
			case cyan: puts("�������� �������.");
				break;
			}
		else
			printf("���� %s �� ��������.\n", choice);
		color_is_found = false;
		puts("������� ��������� ���� (��� ������ ������ ��� ������):");
	}
	puts("��������� ���������.");
	return 0;
}
// ������� 14.16. ��������� func_ytr.�
// func_ptr.c � ������������� ���������� �� �������
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
void eatline(void);				// ������ �� ����� ������
void show(void (*fp)(char*), char* str);
void ToUpper(char*);			// ����������� ������ � ������� �������
void ToLower(char*);			// ����������� ������ � ������ �������
void Transpose(char*);			// ������ ������� ��������
void Dummy(char*);				// ��������� ������ ������������
int func_ptr(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);			// ��������� �� �������, ������� ����� ��������
									// ���� char * � ������ �� ����������
	printf("\033[1;4;32m������� 14.16. ���������  func_ptr.c � ������������� ���������� �� �������\033[0m\n");
	puts("������� ������ (������ ������ - ����� �� ���������):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0') {
		while ((choice = showmenu()) != 'n') {
			switch (choice) {		// �������� switch ������������� ���������
			case 'u': pfun = ToUpper; break;
			case 'l': pfun = ToLower; break;
			case 't': pfun = Transpose; break;
			case 'o': pfun = Dummy; break;
			default: pfun = NULL;
			}
			strcpy_s(copy,LEN, line);		// ������� ����� ��� show()
			show(pfun, copy);		// ������������ ��������� �������
		}
		puts("������� ������ (������ ������ - ����� �� ���������):");
	}
	puts("��������� ���������.");
	return 0;
}
char showmenu(void){
	char ans;
	puts("������� ��������� ������� �� ����:");
	puts("u) ������ �������				l) ������� �������");
	puts("t) �������� ������� ��������	�) �������� �������");
	puts("n) ��������� ������");
	ans = getchar();				// �������� �����
	ans = tolower(ans);				// ������������� � ������ �������
	eatline();						// ���������� �� ���������� ����� ������
	while (strchr("ulton", ans) == NULL){
		puts("������� u, 1, t, � ��� n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}
void eatline(void) {
	while (getchar() != '\n') continue;
}
void ToUpper(char* str){
	while (*str){
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str){
	while (*str){
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}
void Dummy(char* str) {
	// ��������� ������ ������������
}
void show(void (*fp)(char*), char* str){
	(*fp)(str);			// ��������� ��������� ������� � str
	puts(str);			// ���������� ���������
}
//====================================
//	������� ��� ������������		||
//====================================
//1. ��� ����������� � ��������� ������� ?
struct myName {
	char itable;
	int num[20];
	char* togs;
};
//2. � � � � �������� �������� ���������.��� �� ������� ?
#include <stdio.h>
struct house {
	float sqft;
	int rooms;
	int stories;
	char address[40];
};
int quest2(void)
{
	struct house fruzt = { 1560.0, 6, 1, "22 Spiffo Road" };
	struct house* sign;
	sign = &fruzt;
	printf("%d %d\n", fruzt.rooms, sign->stories);
	printf("%s \n", fruzt.address);
	printf("%c %c\n", sign->address[3], fruzt.address[4]);
	return 0;
}
// 3. ������������ ������ ���������, ������� ����� ��������� �������� ������, ���
//		������������� ������������, ���������� ���� � ������ � ��� �����.
struct month
{
	char name[10];
	char abr[4];
	int nDdays;
	int num;
};
// 4. ���������� ������ �� 12 �������� ����, ���������� � ������� 3, � ���������������
//		�� ��� ����, ������� �� �������� ����������.
struct month months[12] = {
	{"������",	"���",31,1},
	{"�������",	"���",28,2},
	{"����",	"���",31,3},
	{"������",	"���",30,4},
	{"���",		"���",31,5},
	{"����",	"���",30,6},
	{"����",	"���",31,7},
	{"������",	"���",30,8},
	{"��������","���",31,9},
	{"�������",	"���",30,10},
	{"������",	"���",31,11},
	{"�������",	"���",30,12},
};
/*
5. �������� �������, ������� ����� ��������� ������ ������ ���������� �����
���������� ���� � ������ ���� �� ����� ���������� ������. ������������, ���
������ ���������, ��������� � ������� 3, � ���������� ������ ����� ��������
��������� ������.
*/
int getPassedDays(int month) {
	int d = 0;
	if (month < 1 || month>12) return 0;
	for (int i = 1; i <= month; i++) d += months[i-1].nDdays;
	return d;
}
int days145(void) {
	int m;
	printf("\033[1;4;32m�������� ������ 14.5. ���������  days145.c � �� ������ ������ ���������� ����� ���������� ���� � ������ ���� �� ����� ���������� ������\033[0m\n");
	printf("������� ����� ������(0 - ����� �� ���������):");
	while (scanf_s("%d",&m)>0  && m>0) {
		//getPassedDays(m);
		printf("�� ������ ���� �� ����� %s ������ %d ����.\n", months[m-1].name, getPassedDays(m));
		puts("������� ����� ������(0 - ����� �� ���������):");
	}
	puts("��������� ���������.");
}
/*
�.�. ���� ���������� ���� ����������� typedef, �������� 10-���������� ������
��������� ��������. ����� � ������� ������������ �������������� ������
�������� ���, ����� ������ ������� ����� ������� �������� �������� �����
Rernarkatar � �������� ����������� 500 �� � ���������� f/2.0.
*/
#define MAXBRAND 29
#define MAXLENS 100
typedef struct lens {
	float foclen;
	float fstop;
	char brand[MAXBRAND+1];
} LENS;
int photoLens(void) {
	int n;
	char name[MAXBRAND+1];
	float foc;
	float diaf;
	LENS lensarr[MAXLENS];
/*
�. ��������� ����� �), �� �������������� � ���������� ������� �������������
� ����������� ��������������� ������ ��������� ��������� ����������
������������ ��� ������� �����.
*/	
	LENS lensarr2[MAXLENS] = { [5]={.brand="Rkkkkk",.foclen=5000,.fstop=4.4}};
	printf("\033[1;4;32m�������� ������ 14.6a. ���������  photoLens.c � ������ �������� typedef LENS.\033[0m\n");
	printf("������� ����� ��������(1-MAXLENS), ��� ���������, �������� ���������� � ���������(����� ������)(0 - ����� �� ���������):", MAXLENS);
	while (scanf_s("%d %s %f %f", &n, name, MAXBRAND,&foc,&diaf) > 0 && n > 0 && !(n> MAXLENS)) {
		strcpy_s(lensarr[n-1].brand, MAXBRAND,name);
		lensarr[n - 1].foclen = foc;
		lensarr[n - 1].fstop = diaf;
		eatline();
		printf("%d-�� ������� ������� ����������- �����:%s \t �����:%f \t���������:%f.\n",n, lensarr[n - 1].brand, lensarr[n - 1].foclen,lensarr[n - 1].fstop);
		printf("������� ����� ��������(1-MAXLENS), ��� ���������, �������� ���������� � ���������(����� ������)(0 - ����� �� ���������):", MAXLENS);
	}
	puts("��������� ���������.");
}
// 7. ��������� �� ��������� �������� ���� :
struct name {
	char first[20];
	char last[20];
};
struct bem{
	int limbs;
struct name title;
char type[30];
};
/* �.��� ������� ����������� ���� ��������� ?
 
*/
void printbem(struct bem* str);
int ques7(void) {
	struct bem* pb;
	struct bem deb = {
		6,
		{"Berbnazel", .last = "Gwolkapwolk"},
		"Arcturan"
	};
	pb = &deb;

	printf("%d\n", deb.limbs);
	printf("%s\n", pb->type);
	printf("%s\n", pb->type + 2);
	//�.��� ����� ���� �� ����������� "Gwolkapwolk" � ����� ������ ��� �������� (����� ���������) ?
	/*
	{"Berbnazel", .last="Gwolkapwolk"},
	*/
	/*
�. �������� �������, ������� ��������� ����� ��������� bem � �������� ������
��������� � ������� ���������� ���� ��������� � ���������� ���� �����
(������������, ��� ������ ��������� ��������� � ������������ ����� starfolk. h):
Berbnazel Gwolkapwolk - ��� 6-�������� Arcturan.
*/
	printbem(&deb);
}
void printbem(struct bem* str) {
	printf("%s %s - ��� %d-�������� %s.\n",str->title.first, str->title.last, str->limbs,str->type);
}

// 8. ��������� �� ��������� ����������:
struct fullname {
char fname[20] ;
char lname[20];
} ;
struct bard {
struct fullname name;
int born;
int died;
} ;
int quest8(void) {
	struct bard willie;
	struct bard* pt = &willie;
	// �. ��������������� ���� born ��������� willie � ������� �������������� willie.
	int b = willie.born;
	//�. ��������������� ���� born ��������� willie � ������� �������������� pt.
	b = pt->born;
	//�. � ������� ������� scanf() ���������� �������� ��� ����� born, ��������� ������������� willie.
	printf("������� ���� ��������(���� ���������):");
	scanf_s("%d", &(willie.born));
	printf("������� %d.\n", willie.born);
	//�. � ������� ������� scanf() ���������� �������� ��� ����� born, ��������� �������� ����� pt.
	printf("������� ���� ��������(�������� �� ���� ���������):");
	scanf_s("%d", &(pt->born));
	printf("������� %d.\n", pt->born);
	eatline();
	//�. � ������� ������� scanf() ���������� �������� ��� ����� lname ��������� name, ��������� ������������� willie.
	printf("������� �������(���� ���������):");
	scanf_s("%s", willie.name.lname,20);
	printf("������� %s.\n", willie.name.lname);
	eatline();
	//�. � ������� ������� scanf() ���������� �������� ��� ����� lname ��������� name, ��������� ������������� pt.
	printf("������� �������(�������� �� ���� ���������):");
	scanf_s("%s", &(pt->name.lname),20);
	printf("������� %s.\n", pt->name.lname);
	eatline();
	//�. �������� ������������� ��� ������� ����� ������, ����, ��� ������ ���������� willie.
	//typedef willie.name.lname[2] Fam3;
	//�. �������� ���������, ������� ������������ ����� ���������� ���� � ����� � ������ � ����, ��� ������ ���������� willie.
	printf("������� ������� � ���(����� ������):");
	scanf_s("%s %s", willie.name.lname, 20, willie.name.fname, 20);
	char chId = willie.name.lname[2];
	int count = strlen(willie.name.lname) + strlen(willie.name.fname);
	printf("������� %s %s ����� ��������=%d 3-� ������ �������=%c.\n", willie.name.lname, willie.name.fname,count, chId);
	eatline();
}
/*
9. ���������� ������ ���������, ���������� ��� �������� ��������� ���������:
����� ����������, ��� �������� � ��������� �����, ������������� �������, ��������
���� � ��� ������. � �������� ����������� ������� ����������� car.
*/
struct car
{
	char marka[20];
	float power;
	float ekorait;
	int willbase;
	struct data{
		int day;
		int month;
		int year;
	};
};
int quest9(void) {
	struct car a = { "VOLWO 12EW",123.5,90.3,4,{11,4,2023} };
	printf("������\n����� \t\t����� �.�. \t���������� \t������� ���� \t���� ������\n%s \t%.1f \t\t%.1f \t\t%d \t\t%d/%d/%d\n",a.marka,a.power,a.ekorait,a.willbase,a.day,a.month,a.year);
	//auto1.
}
/*
10. �����������, ��� ������� ��������� ���������:
�. �������� �������, ������� ��������� �������� struct gas. ������������,
	��� ������������ ��������� �������� ���������� distance � gals. 
	��� ������� ������ ��������� ���������� �������� ��� ����� mpg � ���������� ��� ����������� ���������.
�. �������� �������, ������� ��������� � �������� ��������� ����� struct gas. 
	������������, ��� ������������ ��������� �������� ����������
	distance � gals. ��� ������� ������ ��������� ���������� �������� ��� ����� mpg � ����������� ���.
*/
struct gas {
float distance;
float gals;
float mpg;
} ;
void func1410(struct gas* g);
void func1410s(struct gas g);
int quest10(void) {
	struct gas a = { 100,222 };
	func1410s(a);
	printf("\n���������� gas.mpg � ����������-����������. distance=%.1f  gals=%.1f mpg=%.1f\n",a.distance,a.gals,a.mpg);
	a.distance = 333;
	a.gals = 444;
	func1410(&a);
	printf("\n���������� gas.mpg � ����������-����������. distance=%.1f  gals=%.1f mpg=%.1f\n",a.distance,a.gals,a.mpg);
	//auto1.
}
void func1410(struct gas* g) {
	g->mpg = g->distance * g->gals;
}
void func1410s(struct gas g) {
	g.mpg = g.distance * g.gals;
}
/*
11. �������� ������������ � ������������ choices, ������� ������������� ������������
��������� no, yes � maybe � 0, 1 � 2 ��������������.
*/
enum choices {	no, yes, maybe};
/*
12. �������� ��������� �� �������, ������� ���������� ��������� �� char � ���������
� �������� ���������� ��������� �� char � �������� char.
*/
char* funcpChar(char*,char);
/*13. �������� ������ ������� � ��������������� ������ ���������� �� ���.
������ ������� ������ ��������� ��� ��������� double � ���������� ��������
double. ����� ����, ����������������� ��� ������� ������������� �������
��� ������ ������ ������� � ����������� 10.0 � 2.5.*/
double f1(double, double);
double f2(double, double);
double f3(double, double);
double f4(double, double);
int quest12(void) {
	double (*pff[4])(double, double) = {f1,f2,f3,f4};
	for (int i = 0; i < 4; i++) printf("%lf \t\n", pff[i]((i+1)*11.1,(i+1)*22.2));
}
double f1(double p, double d) { printf("������� f1( %lf,%lf)\t",p,d); return 111.111; }
double f2(double p, double d){ printf("������� f2( %lf,%lf)\t", p, d); return 222.2222; }
double f3(double p, double d){ printf("������� f3( %lf,%lf)\t", p, d); return 333.333; }
double f4(double p, double d){ printf("������� f4( %lf,%lf)\t", p, d); return 444.444; }
