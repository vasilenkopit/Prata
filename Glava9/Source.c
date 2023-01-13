// ������� 8.1.��������� echo.�
/* echo.c -- ��������� ���� */
#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// ������� 9.1 .��������� lethead.2. �
/* lethead2.c */
#include <stdio.h>
#define NAME		"GIGATHINK, INC."
#define ADDRESS		"101 Megabuck Plaza"
#define PLACE		"Megapolis, �� 94904"
#define WIDTH 40
void starbar(void); /* �������� ������� */
int lethead1(void)
{
	printf("\n\033[1;4;44m������� 9.1.���������  lethead1.c -- ��������� ����������\033[0m\n");
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar(); /* ������������� ������� */
	return 0;
}
void starbar(void) /* ����������� ������� */
{
		int count;
		for (count = 1; count <= WIDTH; count++)
			putchar('*');
			putchar('\n');
}
// ������� 9.2. ��������� lethead2. �
/* lethead2.c */
#include <stdio.h>
#include <string.h> /* ��� strlen() */
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, �� 94904"
#define WIDTH 40
#define SPACE ' '
void show_n_char(char ch, int nurn);
int lethead2(void)
{
	int spaces;
	printf("\n\033[1;4;44m������� 9.1.���������  lethead2.c -- �������� �� ������ � ��������� ����������\033[0m\n");
	show_n_char('*', WIDTH);				/* ������������� �������� � �������� ���������� */
	putchar('\n');
	show_n_char(SPACE, 12);					/* ������������� �������� � �������� ���������� */
	printf("% s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;	/* ��������� ��������� ���������, ������� �������� ����� ������� */
	show_n_char (SPACE, spaces);			/* ������������� ���������� � �������� ��������� */
	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);	/* ������������� ��������� � �������� ��������� */
	printf("%s\n", PLACE);
	show_n_char('*', WIDTH);
	putchar('\n');
	return 0;
}
/* ����������� ������� show_n_char () */
void show_n_char(char ch, int nurn)
{
	int count;
	for (count = 1; count <= nurn; count++)
		putchar(ch);
}
// ������� 9.3. ��������� lesser. �
/* lesser.c -- �������� ������� �� ���� ��� */
#include <stdio.h>
int imin(int, int);
int lesser(void)
{
	int evill, evil2;
	printf("\n\033[1;4;44m������� 9.2.���������   lesser.c -- �������� ������� �� ���� ���.\033[0m\n");
	printf("������� ��� ����� ����� (��� q ��� ����������)"INPUT3);
	while (scanf_s("%d %d", &evill, &evil2) == 2)
	{
		printf("������� �� ���� ����� %d � %d �������� %d.\n", evill, evil2, imin(evill, evil2));
		printf("B�e���e ��� ����� ����� (��� q ��� ����������):"INPUT3);
	}
	printf("��������� ���������.\n");
	return 0;
}
int imin(int n, int m)
{
	int min;
	if (n < m)
		min = n;
	else
		min = m;
	return min;
}
// ������� 9.4. ��������� misuse. �
/* misuse.c -- ������������ ������������� ������� */
#include <stdio.h>
int imax(); /* ���������� � ������ ����� */
int misuse(void)
{
	printf("\n\033[1;4;44m������� 9.3.���������   misuse.c -- ������������ ������������� ������� int imax().\033[0m\n");
	printf("���������� ���������(imax(3))		 �� %d � %d �������� %d.\n",3, 5, imax(3));
	printf("���������� ���������(imax(3.0, 5.0)) �� %d � %d �������� %d.\n",3, 5, imax(3.0, 5.0));
return 0;
}
int imax(n, m)
int n, m;
{
	return (n > m ? n : m);
}
// ������� 9.5. ��������� proto. �
/* proto.c -- ���������� ��������� ������� */
#include <stdio.h>
int imax5(int, int); /* �������� */
int proto(void)
{
	printf("\n\033[1;4;44m������� 9.5.���������   misuse.c -- ������������ ������������� ������� int imax5(int, int).\033[0m\n");
	printf("����� imax(3) �� �������������.\n");
	printf("����� imax5(3.0, 5.0).���������� ��������� �� %d � %d �������� %d.\n", 3, 5, imax5(3.0, 5.0));
	return 0;
}
int imax5(int n, int m)
{
	return (n > m ? n : m);
}
// ������� 9.6. ��������� recur. �
/* recur.c � ����������� �������� */
#include <stdio.h>
void up_and_down(int);
int recur(void)
{
	printf("\n\033[1;4;44m������� 9.6.��������� recur.c � ����������� ��������.\033[0m\n\n");
	up_and_down(1);
	printf("\033[0m\n");
	return 0;
}
void up_and_down(int n)
{
	switch(n) {
	case 1:		printf("\033[42m-->������� %d: ������ n %p\n", n, &n); break;// 1
	case 2:		printf("\033[43m-->������� %d: ������ n %p\n", n, &n); break;// 1
	case 3:		printf("\033[44m-->������� %d: ������ n %p\n", n, &n); break;// 1
	case 4:		printf("\033[45m-->������� %d: ������ n %p\n", n, &n); break;// 1
	}
	if (n < 4)
		up_and_down(n + 1);
	switch (n) {
	case 1:		printf("\033[42m<--������� %d: ������ n %p\n", n, &n); break;// 2
	case 2:		printf("\033[43m<--������� %d: ������ n %p\n", n, &n); break;// 2
	case 3:		printf("\033[44m<--������� %d: ������ n %p\n", n, &n); break;// 2
	case 4:		printf("\033[45m<--������� %d: ������ n %p\n", n, &n); break;// 2
	}
	return;
}
// ������� 9.7.��������� factor.c
// factor.c -- ���������� ����� � �������� ��� ���������� �����������
#include <stdio.h>
#define RUN_LOOP 100000000
double getCPUTime(void);
double timeRunR(int n, int loop);
double timeRunC(int n, int loop);
long fact(int n);
long rfact(int n);
int factor(void)
{
	int num;

	printf("\n\033[1;4;44m������� 9.7.��������� factor.c -- ���������� ����� � �������� ��� ���������� �����������.\033[0m\n\n");
	printf("��� ��������� ��������� ����������.\n");
	printf("������� �������� � ��������� 0-12 (q ��� ����������):"INPUT2);
	while (scanf_s("%d", &num) == 1)
	{
		if(num < 0)
			printf("������������� ����� �� ��������. \n");
		else if (num > 12)
			printf("�������� �������� ������ ���� ������ 13. \n");
		else
		{
			printf("����:     %d! = %ld \t\t�����:%g \t�� %d ����������\n", num, fact(num), timeRunC(num, RUN_LOOP), RUN_LOOP);
			printf("��������: %d! = %ld \t\t�����:%g \t�� %d ����������\n", num, rfact(num),timeRunR(num, RUN_LOOP), RUN_LOOP);
		}
		printf("������� �������� � ��������� 0-12 (q ��� ����������):\n");
	}
	printf("��������� ���������.\n");
	return 0;
}
#include <time.h>
double timeRunR(int n, int loop) {
	int i=0;
	clock_t c1, c2, cdelta;
	c1 = clock();
	while (i++ < loop) rfact(n);
	c2 = clock();
	cdelta = c2 - c1;
	return cdelta;
}
double timeRunC(int n, int loop) {
	int i;
	i = 0;
	clock_t c1,c2,cdelta; 
	c1= clock();
	while (i++ < loop) fact(n);
	c2= clock();
	cdelta = c2 - c1;
	return cdelta;
}
long fact(int n)		// �������, ���������� �� �����
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}
long rfact(int n)		// ����������� ������
{
	long ans;
	if (n > 0)
		ans = n * rfact(n - 1);
	else
		ans = 1;
	return ans;
}
// ������� 9.8. ��������� binary. �
/* binary.c � ������� ����� ����� � �������� ����� */
#include <stdio.h>
void to_binary(unsigned long n);
int binary(void)
{
	unsigned long number;
	printf("\n\033[1;4;44m������� 9.7.��������� binary.c � ������� ����� ����� � �������� �����.\033[0m\n\n");
	printf("B�e���e ����� �����(q ��� ����������) :\n");
	while (scanf_s("%lu", &number) == 1)
	{
		printf("�������� ����������: ");
		to_binary(number);
		putchar('\n');
		printf("������� ����� ����� (q ��� ����������):\n");
	}
	printf("nporpa�a ���������. \n");
	return 0;
}
void to_binary(unsigned long n) /* ����������� ������� */
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
	return;
}
// ������� 9.12. ��������� loccheck. �
/* loccheck.c -- �������� ��� ���������, ��� �������� ���������� */
#include <stdio.h>
void mikado(int); /* ���������� ������� */
int loccheck(void)
{
	int pooh = 2, bah = 5; /* ��������� ��� main() */
	printf("\n\033[1;4;44m������� 9.12.��������� loccheck.c -- �������� ��� ���������, ��� �������� ����������.\033[0m\n\n");
	printf("B�y�p� main() \t\tpooh = %d � &pooh = %p\n", pooh, &pooh);
	printf("������ main() \t\tbah  = %d � &bah  = %p\n", bah, & bah);
	mikado(pooh);
	return 0;
}
void mikado(int bah) /* ����������� ������� */
{
	int pooh = 8; /* ��������� ��� mikado () */
	printf("B�y�p� mikado() \tpooh = %d � &pooh = %p\n", pooh, &pooh);
	printf("������ mikado() \tbah  = %d � &bah  = %p\n", bah, &bah);
}
// ������� 9.15. ��������� swap3. �
/* swap3.c -- ������������� ���������� ��� ������ ���������� ���������� */
#include <stdio.h>
#include <stdbool.h>
void interchange(int* �, int* v);
int swap3(void)
{
	int x = 5, y = 10;
	printf("\n\033[1;4;44m������� 9.15.��������� swap3.c -- ������������� ���������� ��� ������ ���������� ����������.\033[0m\n\n");
	printf("������������� � = %d \t� � = %d.\n", x, y);
	interchange(&x, &y); // �������� ������� � �������
	printf("������        � = %d \t� � = %d.\n", x, y);
	return 0;
}
void interchange(int* u, int* v)
{
	int temp;
	temp = *u; // temp �������� ��������, �� ������� ��������� u
	*u = *v;
	*v = temp;
}
// 4. �������� �������, ������� ���������� ����� ���� ����� �����.
int summ2(int x, int y);
double summd(double x, double y);
void alter(int* x, int* y);
int max3(int x, int y, int z);
int test4(void) {
	printf("\n\033[1;4;44m4-5. �������� �������, ������� ����������\n "
		                   "   1. ����� ���� �����\n"
		                   "   2. ����� ���� �������������� �����\n"
		                   "   3. x+y x-y.\n"
		                   "   4. �������� �� 3-� �����.\033[0m\n\n");
	int i1, i2,x,y,z;
	double e1, e2;
	while(1){
		printf("1.������� 2 ����� �����(�� ����� - �����):"INPUT3);
		if (scanf_s("%d %d", &i1, &i2) != 2) break;
		printf("%d + %d = %d\n", i1, i2, summ2(i1, i2));
		printf("2.������� 2 �������������� �����:"INPUT3);
		if (scanf_s("%le %le", &e1, &e2) != 2) break;
		printf("%e + %e = %e\n", e1, e2, summd(e1, e2));
		printf("3.������� 2 ����� �����:"INPUT3);
		if (scanf_s("%d %d", &x, &y) != 2) break;
		i1 = x, i2 = y;
		alter(&x, &y);
		printf("%d + %d = %d   %d - %d = %d\n", i1, i2, x,i1,i2,y);
		printf("4.������� 3 ����� �����:"INPUT3);
		if (scanf_s("%d %d %d", &x, &y,&z) != 3) break;
		printf("��������(%d,%d,%d) = %d\n", x, y, z, max3(x, y, z));
	}
	return 0;
}
int summ2(int x, int y) {
	return x + y;
}
// 5. ��� �������� ��������, ���� ������ ��������, ����� ������� �� ������� 4 ������ ����������� ��� ����� ���� double?
double summd(double x, double y) {
	return x + y;
}
// 6. �������� ������� �� ����� alter (), ������� ��������� ��� ����������
//    int, � � �, � ������������� �� ��������, ��������������, � ����� � �������� � � �.
void alter(int* x, int* y) {
	*x += *y;
	*y = *x - 2**y;
	return;
}
// 8. �������� �������, ������� ���������� ���������� �� ���� ������������� ����������.
int max3(int x, int y, int z) {
	if (x > y) {
		if (x > z) return x;
		else return z;
	}
	else if (y > z) return y;
	else return z;
}/*
 9. ����� ��������� �����:
�������� ���� �� ��������� ���������:
1) ���������� ����� 2) ����������� �����
3) ������� �����    4) ����� �� ���������
������� ����� ���������� ��������:
�. �������� �������, ������� ������� �� ����� ���� �� ������� ���������������
��������� � ���������� ������� ���� �� ���. (����� ������ ����� ���������� ���� ���.)
 */
int menu9(int n, int m);
void spaces(int n);
int test9(void) {
	int fun;
	fun=menu9(8, 4);
	printf("������� ������� %d.\n",fun);
}
int menu9(int n,int m) {
// ������� ���� n - ����� �������, m - ����� ��������
	char* lmenu[] = {
		             "1) ���������� �����",
		             "2) ����������� �����",
		             "3) ������� �����",
		             "4) ����� �� ���������",
					 "5) ",
					 "6) ",
					 "7) ",
					 "8) "
	                };
	int i, j, k = 0,fun=0,lens[20],maxs=0;
	int status, menu;
	//char* spasecc = "                    ";
	for (i = 0; i < n; i++) {
		if((lens[i] = strlen(lmenu[i]))>maxs) maxs = lens[i];
	}
	printf("�������� ���� �� ��������� ���������:\n");
	for (i = 0; i < n;) {
		for (j = 0; j < m; j++, i++) {
			if (k >= n) break;
			printf("%s", lmenu[k++]);
			spaces(maxs + 1 - lens[i]);			//_strset_s(spasecc, maxs + 1 - lens[i], ' ');
		}
		printf("\n");
	}
	printf(":"INPUT1);
	while ((status = scanf_s("%d", &menu)) != 1 || (menu < 1 || menu > 5))
	{
		if (status != 1)
			scanf_s("%*s");					// ������������ ���������������� �����
		printf("B�e���e ����� ����� �� 1 �� %d:"INPUT1, n);
	}
	return menu;
}
void spaces(int n) {
	int i;
	for (i = 0; i < n; i++) putch(' ');
}
bool checkMenu(int n) {

}