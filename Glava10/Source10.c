#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// ������� 10.1. ��������� day_monl. �
/* day_mon1.c � ������� ���������� ���� � ������ ������ */
#include <stdio.h>
#define MONTHS 12
int day_mon1(void)
{
	const int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char* names[MONTHS] = { "������","�������", "����", "������", "���", "����", "����", "������","��������", "�������", "������", "�������" };
	int index;
	printf("\n\033[1;4;44m������� 10.1.���������  day_mon1.c � ������� ���������� ���� � ������ ������.\033[0m\n");
	printf("\033[4m����� �����     ����\033[0m\n");
	for (index = 0; index < MONTHS; index++)
		printf("%02d    %s \t%2d\n", index + 1,names[index], days[index]);
	printf("\n");
	return 0;
}
// ������� 10.2-3. ��������� no_data.c
/* no_data.c -- �������������������� ������ */
#include <stdio.h>
#define SIZE 4
int no_data(void)
{
	int no_data[SIZE]; /* �������������������� ������ */
	int no_data1[SIZE] = { 1111, 2222 }; /* ���������� �������������������� ������ */
	const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
	int sizeD;
	int i;
	printf("\n\033[1;4;44m������� 10.2.���������  no_data.c -- �������������������� ������.\033[0m\n");
	printf("\n\033[4m%2s%14s\033[0m\n",	"i", "no_data[i]");
	for (i = 0; i < SIZE; i++)
		printf("%2d%14d\n", i, no_data[i]);
	printf("\n");

	printf("\n\033[1;4;44m������� 10.3.���������  some_data.c -- ���������� �������������������� ������.\033[0m\n");
	printf("\n\033[4m%2s%14s\033[0m\n", "i", "no_data1[i]");
	for (i = 0; i < SIZE; i++)
		printf("%2d%14d\n", i, no_data1[i]);
	printf("\n");

	sizeD = sizeof days / sizeof days[0];
	printf("\n\033[1;4;44m������� 10.4.���������  day_mon2.c -- ����� ������� days[] ������������ ������� �������������.\033[0m\n");
	printf("������ ������� =%zd ����  ������ ������ �������� =%zd ����   ����� ��������� � ������� =%d.\n\n",sizeof days, sizeof days[0], sizeD);
	for (i = 0; i < sizeD; i++)
		printf("����� %2d ����� %d ���� (����).\n", i + 1, days[i]);
	printf("\n");
	return 0;
}
// ������� 10.5.��������� designate.c
// designate.c -- ������������� ����������� ���������������
#include <stdio.h>
#define MONTHS105 12
int designate(void)
{
	int days[MONTHS105] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	int i;
	int staff[] = { 1,[6] = 23 };			// ��� ���������� ?
	int staff1[] = { 1,[6] = 4, 9, 10 };	// ��� ����������?
	int staff2[] = { [11] = 11 };			// ��� ����������?
	int sizeD;
	printf("\n\033[1;4;44m������� 10.5.���������  designate.c -- ������������� ����������� ���������������.\033[0m\n");
	printf("���������{ 31, 28,[4] = 31, 30, 31,[1] = 29 }\n");
	printf("\n");
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, days[i], days[i]>0?"�����������":"�� �����������");
	printf("\n");

	printf("���������{ 1,[6] = 23 }\n");
	sizeD = sizeof staff / sizeof staff[0];
	printf("������ ������� =%zd ����  ������ ������ �������� =%zd ����   ����� ��������� � ������� =%d.\n\n", sizeof staff, sizeof staff[0], sizeD);
	printf("\n");
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff[i], staff[i]>0 ? "�����������" : "�� �����������");
	printf("\n");

	printf("���������{ 1,[6] = 4, 9, 10 }\n");
	sizeD = sizeof staff1 / sizeof staff1[0];
	printf("������ ������� =%zd ����  ������ ������ �������� =%zd ����   ����� ��������� � ������� =%d.\n\n", sizeof staff1, sizeof staff1[0], sizeD);
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff1[i], staff1[i]>0 ? "�����������" : "�� �����������");
	printf("\n");

	printf("���������{ [11] = 11 }\n");
	sizeD = sizeof staff2 / sizeof staff2[0];
	printf("������ ������� =%zd ����  ������ ������ �������� =%zd ����   ����� ��������� � ������� =%d.\n\n", sizeof staff2, sizeof staff2[0], sizeD);
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff2[i], staff2[i]>0 ? "�����������" : "�� �����������");
	printf("\n");
	return 0;
}
// ������� 10.6. ��������� tounds. �
// bounds.c -- ����� �� ������� �������
#include <stdio.h>
#define SIZE106 4
int bounds(void)
{
	int value1 = 44;
	int arr[SIZE106];
	int value2 = 88;
	int i;
	printf("\n\033[1;4;44m������� 10.6.���������  bounds.c -- ����� �� ������� �������.\033[0m\n");
	printf("valuel = %d, value2 = %d\n", value1, value2);
	for (i = -1; i <= SIZE106; i++)
		arr[i] = 2 * i + 1;
	for (i = -1; i < 7; i++)
		printf("%2d %d\n", i, arr[i]);
	printf("valuel = %d, value2 = %d\n", value1, value2);
	printf("����� arr[-1]: %p\n", &arr[-1]);
	printf("a�pec arr[4]: %p\n", &arr[4]);
	printf("a�pec value1: %p\n", &value1);
	printf("a�pec value2: %p\n", &value2);
	printf("\n\033[31mRun-Time Check Failure #2 - Stack around the variable 'arr' was corrupted.\033[0m\n");
	return 0;
}
// ������� 10.7. ��������� rain.c
/* rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������
�������� �� ����� �� ������ �� ������� �� ��������� ��� */
#include <stdio.h>
#define MONTHS107 12	// ���������� ������� � ����
#define YEARS107 5		// ���������� ���, ��� ������� �������� ������
int rain(void)
{
	// ������������� ����^��� �� ������� �� ������ � 2010 �� 2014 ��.
	const float rain[YEARS107][MONTHS107] =
	{
		{ 4.3,4.3, 4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
		{8.5, 8.2, 1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
		{9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
		{7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
		{7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
	};
	int year, month;
	float subtot, total;
	printf("\n\033[1;4;44m������� 10.7.���������  rain.c -- ������� ��������� ������ �� �����, ������� �������� �� ��� � �������.\033[0m\n");
	printf("��� ���������� ������� (� ������)\n");
	for (year = 0, total = 0; year < YEARS107; year++)
	{ // ��� ������� ���� ����������� ���������� ������� �� ������ �����
		for (month = 0, subtot = 0; month < MONTHS107; month++)
			subtot += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;				// ����� ����� ��� ���� ���
	}
	printf("\n������������� ���������� ������� ���������� %.1f ������. \n\n", total / YEARS107);
	printf("�������������� ���������� �������:\n\n");
	printf(" ��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t��� \t���");
	printf(" \t��� \t���\n");
	for (month = 0; month < MONTHS107; month++)
	{ // ��� ������� ������ ����������� ���������� ������� �� ���������� �����
		for (year = 0, subtot = 0; year < YEARS107; year++)
			subtot += rain[year][month];
		printf("%4.1f\t", subtot / YEARS107);
	}
	printf("\n\n");
	return 0;
}
//������� 10.8. ��������� pnt_add.c
// pnt_add.c -- �������� ����������
#include <stdio.h>
#define SIZE108 4
int pnt_add(void)
{
	short dates[SIZE108];
	short* pti;
	short i;
	double bills[SIZE108];
	double* ptf;
	pti = dates;			// ������������ ��������� ������ �������
	ptf = bills;
	printf("\n\033[1;4;44m������� 10.8.���������  pnt_add.c -- �������� ����������.\033[0m\n");
	printf("%23s %15s\n", "short", "double");
	for (i = 0; i < SIZE108; i++)
		printf("��������� + %d: %10p %10p\n", i, pti + i, ptf + i);
	printf("\n\n");
return 0;
}
// ������� 10.9. ��������� day_mon3.c
/* day_mon3.c -- ������������� ����� ������ � ����������� */
#include <stdio.h>
#define MONTHS109 12
int day_mon3(void)
{
	int days[MONTHS109] = { 31, 28,31, 30, 31,30,31, 31, 30, 31, 30, 31 };
	int index;
	printf("\n\033[1;4;44m������� 10.9.��������� day_mon3.c -- ������������� ����� ������ � ����������� .\033[0m\n");
	for (index = 0; index < MONTHS109; index++)
	printf("Mec�� %2d ����� %d ���� (����).\n", index + 1, *(days + index)); // �� �� �����, ��� � days[index]
	printf("\n\n");
	return 0;
}
// ������� 10.10. ��������� sum_arr1.c
// sum_arr1.� -- ����� ��������� �������
// ����������� ������������� %� ��� %1�, ���� %zd �� ��������
#include <stdio.h>
#define SIZE1010 10
int sum1010(int ar[], int n);
int sump1011(int* start, int* end);
int sum_arr1(void)
{
	int marbles[SIZE1010] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	printf("\n\033[1;4;44m������� 10.10.��������� sum_arr1.� -- ����� ��������� �������.\033[0m\n");
	answer = sum1010(marbles, SIZE1010);
	printf("����� ����� ��������� ������� marbles ����� %ld.\n", answer);
	printf("����� ������, ���������� ��� ������ marbles, ���������� %zd ������ ������ ������� int %zd ����.\n", sizeof marbles, sizeof( int));
	
	printf("\n\033[1;4;44m������� 10.11.��������� sum_arr2.� -- ����� ��������� ������� �����������.\033[0m\n");
	answer = sump1011(marbles, marbles+SIZE1010);
	printf("����� ����� ��������� ������� marbles ����� %ld.\n", answer);
	printf("\n\n");
	return 0;
}
int sum1010(int ar[], int n) // ��������� ����� ������?
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++)
		total += ar[i];
	printf("Pa��ep ar ���������� %zd ������.\n", sizeof ar);
	return total;
}
/* ������������� ���������� ���������� */
int sump1011(int* start, int* end)
{
	int total = 0;
	while (start < end)
	{
		total += *start++;	// �������� �������� � total
		//start++;			// ����������� ��������� �� ��������� �������
	}
	return total;
}
// ������� 10.12. ��������� order.�
/* order.c � ���������� � ��������� � ����������� */
#include <stdio.h>
int data[2] = { 100, 200 };
int moredata[2] = {300, 400};
int order(void)
{
	int* p1, * �2, * ��;
	p1 = �2 = data;
	�� = moredata;
	int data1[2] = { 10, 20 };
	int moredata1[2] = {30, 40};
	printf("\n\033[1;4;44m������� 10.12.��������� order.c � ���������� � ��������� � �����������.\033[0m\n");
	printf(" *p1   = %d, *�2   = %d, *��     = %d\n", *p1,   *�2,   *��);
	printf(" *p1++ = %d, *++�2 = %d, (*��)++ = %d\n", *p1++, *++�2, (*��)++);
	printf(" *p1   = %d, *�2   = %d, *��     = %d\n", *p1,   *�2,   *��);
	
	p1 = �2 = data1;
	�� = moredata1;
	printf("\n� ������ ��� ��������� ��������\n");
	printf(" *p1   = %d, *�2   = %d, *��     = %d\n", *p1,   *�2,   *��);
	printf(" *p1++ = %d, *++�2 = %d, (*��)++ = %d\n", *p1++, *++�2, (*��)++);
	printf(" *p1   = %d, *�2   = %d, *��     = %d\n", *p1,   *�2,   *��);
	printf("\n\n");
	return 0;
}
// ������� 10.13. ��������� ptr_ops. �
// ptr_ops.� -- �������� ��� �����������
#include <stdio.h>
int ptr_ops(void)
{
	int urn[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, *ptr2, *ptr3=NULL;
	ptr1 = urn;		// ������������ ��������� ������
	ptr2 = &urn[2]; // �� �� �����
	ptr3 = urn + 4;
	printf("\n\033[1;4;44m������� 10.13.���������  ptr_ops.� -- �������� ��� �����������.\033[0m\n");
	// ������������� ��������� � ��������� ������ ���������
	printf("�������� ���������,      �������������� ���������, ����� ���������:\n");
	printf("ptr1 = %p,  *ptr1 = %d,             &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	printf("ptr2 = %p,  *ptr2 = %d,             &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	printf("ptr3 = %p,  *ptr3 = %d,             &ptr3 = %p\n", ptr3, *ptr3, &ptr3);
	// �������� ����������
	ptr3 = ptr1 + 4;
	printf("\n�������� �������� int � ����������: \n");
	printf("ptr1 + 4 = %p, *(ptr4+3) = %d, *ptr4+3 = %d\n", ptr1 + 4, *(ptr1 + 3), *ptr1 + 3);
	ptr1++;		// ����������������� ���������
	printf("\n�������� ����� ���������� �������� ptr1++ : \n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	ptr2--;		// ����������������� ���������
	printf("\n�������� ����� ���������� �������� --ptr2:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	-- ptr1;	// �������������� ��������� ��������
	++ptr2;		// �������������� ��������� ��������
	printf("\n�������������� �������� �������� ����������:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	// ��������� ������ ��������� �� �������
	printf("\n��������� ������ ��������� �� �������:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2-ptr1 = %td\n",	ptr2, ptr1, ptr2 - ptr1);
	// ��������� ������ �������� �� ���������
	printf("\n��������� �� ��������� �������� ���� int:\n");
	printf("ptr3 = %p, ptr3-2 = %p\n", ptr3, ptr3 - 2);
	return 0;
}
// ������� 1�.14. ��������� a r f . �
/* arf.c -- �������, �������������� ��������� */
#include <stdio.h>
#define SIZE1014 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
int arf(void)
{
	double dip[SIZE1014] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	printf("\n\033[1;4;44m������� 10.14.���������  arf.c -- �������, �������������� ���������.\033[0m\n");
	printf("�������� ������ dip:\n");
	show_array(dip, SIZE1014);
	mult_array(dip, SIZE1014, 100.);
	printf("������ dip ����� ������ ������� mult_array():\n");
	show_array(dip, SIZE1014);
	return 0;
}
/* ������� ���������� ������� */
void show_array(const double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%8.3f ", ar[i]);
	putchar('\n');
}
/* �������� ������ ������� ������� �� ���� � ��� �� ��������� */
void mult_array(double ar[], int n, double mult)
{
	int i;
	for (i = 0; i < n; i++)
		ar[i] *= mult;
}
// ������� 10.15. ��������� zippol.�
/* zippo1.c -- ���������� � ������� zippo */
#include <stdio.h>
int zippo1(void)
{
	int zippo[4][2] = { {100, 1}, {10, 11}, {20, 21}, {30, 31} },i,j;
	printf("\n\033[1;4;44m������� 10.15.��������� zippo1.c -- ���������� � ������� zippo.\033[0m\n");
	printf("zippo[4][2]:\n");
	for (i = 0; i < 4; i++) { for (j = 0; j < 2; j++) { printf("[%d,%d](%p):%d \t",i,j, &zippo[i][j],zippo[i][j]); } printf("\n"); }
	printf("&zippo           = %p, \t&zippo   + 1 = %p\n",  &zippo,   &zippo + 1);
	printf("zippo            = %p, \tzippo    + 1 = %p\n",	zippo,    zippo + 1);
	printf("zippo[0]         = %p, \tzippo[0] + 1 = %p\n",  zippo[0], zippo[0] + 1);
	printf("*zippo           = %p, \t*zippo   + 1 = %p\n",  *zippo,   *zippo + 1);
	printf("zippo [0][0]     = %d\n", zippo[0][0]);
	printf("*zippo[0]        = %d\n", *zippo[0]);
	printf("**zippo          = %d\n", **zippo);
	printf("zippo[2][1]      = %d\n", zippo[2][1]);
	printf("*(*(zippo+2)+1)  = %d\n", *(*(zippo+2)+1));
	putchar('\n');
	return 0;
}
// ������� 10.16. ��������� zipppo2. �
/* zippo2.c -- ��������� ���������� � ������� zippo � ������� ���������� ���� ��������� */
#include <stdio.h>
int zippo2(void)
{
	int zippo[4][2] = { {100, 1}, {10, 11}, {20, 21}, {30, 31} },i,j;
	int(*pz)[2];
	pz = zippo;
	printf("\n\033[1;4;44m������� 10.16.��������� zippo2.c -- ��������� ���������� � ������� zippo � ������� ���������� ���� ���������.\033[0m\n");
	printf("int(*pz)[2]=zippo.   zippo[4][2]:\n");
	for (i = 0; i < 4; i++) { for (j = 0; j < 2; j++) { printf("[%d,%d](%p):%d \t", i, j, &zippo[i][j], zippo[i][j]); } printf("\n"); }
	printf("pz           = %p, pz+1    = %p\n",	pz, pz + 1);
	printf("pz[0]        = %p, pz[0]+1 = %p\n",	pz[0], pz[0] + 1);
	printf("*pz          = %p, *pz+1   = %p\n",	*pz, *pz + 1);
	printf("pz[0][0]     = %d\n", pz[0][0]);
	printf("*pz[0]       = %d\n", *pz[0] ) ;
	printf("**pz         = %d\n", **pz);
	printf("pz[2][1]     = %d\n", pz[2][1]);
	printf("*(*(pz+2)+1) = %d\n", *(*(pz+2)+1));
	putchar('\n');
	const int** pp;
	int* p;
	const int n = 13;
	printf("��������; pp                &pp               p                 &p                &n                n\n");
	pp = &p;					// ���������, �� ������������ const ������������
	printf("pp = &p;  %p  %p  %p  %p  %p  %d\n",pp, &pp, p,&p,&n,n);
	*pp = &n;					// ���������, ��� const, �� pl ��������������� ����������� �� n
	printf("*pp = &n; %p  %p  %p  %p  %p  %d\n", pp, &pp, p, &p, &n, n);
	*p = 10;					// ���������, �� ������������ ������� �������� ��������� n
	printf("*p = 10;  %p  %p  %p  %p  %p  %d\n", pp, &pp, p, &p, &n, n);
	printf("**pp=%d\n\n",**pp);
	printf("������ ��������� ���������\n");
	const int y;
	const int* p2 = &y;
	int* p1;
	p1 = p2;					// ������ � C + + , ��������� �������������� � �
	*p1= 1234567890;
	//*p2 = 112345678;
	printf("y=%d\n", y);
	return 0;
}
// ������� 1�.17. ��������� array2d.c
// array2d.c -- ������� ��� ��������� ��������
#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int[][COLS], int);				// ����� ����� ��������
int sum2d(int(*ar)[COLS], int rows);			// ������ ���������
int array2d(void)
{
	int junk[ROWS][COLS] = {
		{1, 2, 3, 4},
		{10, 20, 30, 40},
		{100, 200, 300, 400}
	};
	printf("\n\033[1;4;44m������� 10.17.��������� array2d.c -- ������� ��� ��������� ��������.\033[0m\n");
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("����� ���� ��������� = %d\n", sum2d(junk, ROWS));
	return 0;
}
void sum_rows(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (r = 0; r < rows; r++)
	{
		tot = 0;
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	printf("������ %d: ����� = %d\n", r, tot);
	}
}
void sum_cols(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot;
	for (c = 0; c < COLS; c++)
	{
		tot = 0;
		for (r = 0; r < rows; r++)
			tot += ar[r][c];
		printf("������� %d: ����� = %d\n", c, tot);
	}
}
int sum2d(int ar[][COLS], int rows)
{
	int r;
	int c;
	int tot = 0;
	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			tot += ar[r][c];
	return tot;
}
/*	�� ������������� ������� ���������� ����� VLA * /
#define __STDC_VLA__
// ������� 10.18. ��������� vararr2d. �
//vararr2d.c -- �������, ������������ ������� ���������� �����
#include <stdio.h>
#define ROWS1018 3
#define COLS1018 4
int sum2d1018(int rows, int cols, int ar[rows][cols]);
int vararr2d(void)
{
	int i, j;
	int rs = 3;
	int cs = 10;
	int junk[ROWS1018][COLS1018] = {
		{2,4,6,8},
		{3,5,7,9},
		{12, 10, 8, 6}
	};
	int morejunk[ROWS1018 - 1][COLS1018 + 2] = {
		{ 20, 30, 40,50, 60, 70},
		{5,6,7,8,9,10 }
	};
	int varr[rs][cs]; // ������ ���������� �����
	printf("\n\033[1;4;44m������� 10.18.��������� vararr2d.c -- �������, ������������ ������� ���������� �����.\033[0m\n");
	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			varr[i][j] = i * j + j;
	printf("������������ ������ 3x5\n");
	printf("���� ���� ��������� = %d\n",
		sum2d1018(ROWS1018, COLS1018, junk));
	printf("������������ ������ 2x6\n");
	printf("���� ���� ��������� = %d\n",
		sum2d1018(ROWS1018 - 1, COLS1018 + 2, morejunk));
	printf("������ ���������� ����� 3x10\n");
	printf("��� ���� ��������� = %d\n",
		sum2d1018(rs, cs, varr));
	return 0;
}
// ������� � ���������� ���� ������� ���������� �����
int sum2d1018(int rows, int cols, int ar[rows][cols])
{
	int r;
	int i;
	int tot = 0;
	for (r = 0; r < rows; r++)
		for (i = 0; i < cols; i++)
			tot += ar[r][i];
	return tot;
}
*/
// ������� 10.19. ��������� flc.c
// flc.c -- ������� ���������� ���������
#include <stdio.h>
#define COLS19 4
int sum2d19(const int ar[][COLS19], int rows);
int sum19(const int ar[], int n);
int flc(void)
{
	int total1, total2, total3;
	int* pt1;
	int(*pt2)[COLS19];
	printf("\n\033[1;4;44m������� 10.19.��������� flc.c -- ������� ���������� ���������.\033[0m\n");
	pt1 = (int[2]){ 10, 20 };
	pt2 = (int[2][COLS19]){ {1, 2, 3, -9}, {4, 5, 6, -8} };
	total1 = sum19(pt1, 2);
	total2 = sum2d19(pt2, 2);
	total3 = sum19((int[]) { 4, 4, 4, 5, 5, 5 }, 6);
	printf("total1 = %d\n", total1);
	printf("total2 = %d\n", total2);
	printf("total3 = %d\n", total3);
	return 0;
}
int sum19(const int ar[], int n)
{
	int i;
int total = 0;
for (i = 0; i < n; i++)
	total += ar[i];
return total;
}
int sum2d19(const int ar[][COLS19], int rows)
{
	int r;
int c;
int tot = 0;
for (r = 0; r < rows; r++)
	for (c = 0; c < COLS19; c++)
		tot += ar[r][c];
return tot;
}