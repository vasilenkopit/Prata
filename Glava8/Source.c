// ������� 8.1.��������� echo.�
/* echo.c -- ��������� ���� */
#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

int echo(void)
{
	char ch,str[1000];
	int i=0,j;
	printf("\n\033[1;4;44m������� 8.1.���������  echo.c -- ��������� ���� �� #\033[0m\n");
	printf("�������:\n");
	while ((ch = getchar()) != '#')
		putchar(ch);
	printf("\n������� ����������������� ���� � ���:\n");
	while ((str[i] = getche()) != '#'&& ++i<1000);
	str[i] = '\n';	//putchar(ch);
	printf("\n�������:\n");
	for(j=0;j<i;j++) printf("%c", str[j]);
	printf("\n������� ����������������� ���� ��� ���:\n");
	while ((str[i] = getch()) != '#' && ++i < 1000);
	str[i] = '\n';	//putchar(ch);
	printf("\n�������:\n");
	for (j = 0; j < i; j++) printf("%c", str[j]);
	printf("\n����� ���������.");
return 0;
}
// ������� 8.2. ��������� echo_e o f . �
/* echo_eof.c - ��������� �� ������ ���� �� ���������� ����� ����� */
#include <stdio.h>
int echo_eof(void) {
	int ch;
	printf("\n\033[1;4;44m������� 8.2.���������  echo_eof.c - ��������� �� ������ ���� �� ���������� ����� ����� EOF.\033[0m\n");
	printf("�������:\n");
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
// �������8.3. ��������� f ile _ e o f .�
// file_eof.c -- ��������� ���� � ���������� ��� ����������
#include <stdio.h>
#include <stdlib.h> // ��� ������� exit �
int file_eof()
{
	int ch;
	FILE* fp;
	errno_t err;
	char fname[50];				// ��� �������� ����� �����
	printf("\n\033[1;4;44m������� 8.3.���������  file_eof.c -- ��������� ���� � ���������� ��� ����������.\033[0m\n");
	printf("������� ��� �����:");
	scanf_s("%s", fname,49);
	//fname = "F:\\�����\\C\\Pratta\\x64\\Debug.glava8.txt";
	err=fopen_s(&fp,fname, "a");		// ������� ���� ��� r-������ a-���������
	if (fp == NULL)				// ������� ����������� ��������
	{
		printf("�� ������� ������� ����. ��������� ���������.\n");
		exit(1);				// ����� �� ���������
	}
	printf("���������� ����� %s\n", fname);
	printf("============================================================\n");
	// ������� getc(fp) �������� ������ �� ��������� �����
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
	printf("============================================================\n");
	fclose(fp);					// ������� ����
	return 0;
}
// ������� 8.4. ��������� g u e s s . �
/* guess.c � ������������� � �������� �������� ���������� ����� */
#include <stdio.h>
int guess(void)
{
	int guess = 1;
	printf("\n\033[1;4;44m������� 8.4.���������  � ������������� � �������� �������� ���������� �����.\033[0m\n");
	printf("�������� ����� ����� � ��������� �� 1 �� 100. � �������� ������� ");
	printf("���. \n������� ������� y, ���� ��� ������� ����� � ");
	printf("\n������� n � ��������� ������.\n");
	printf("����� ������ �������� %d?\n", guess);
	while (getchar() != 'y')					/* �������� �����, �������� � y */
		printf("�����, ����� ��� %d?\n", ++guess);
	printf("� ����, ��� � ���� ���������!\n");
	return 0;
}
// ������� 8.4. ��������� g u e s s . �
/* guess.c � ������������� � �������� �������� ���������� ����� */
#include <stdio.h>
int guess1(void)
{
	int guess = 1;
	char response;
	printf("\n\033[1;4;44m������� 8.4-1.���������  � ������������� � �������� �������� ���������� �����.\033[0m\n");
	printf("�������� ����� ����� � ��������� �� 1 �� 100. � �������� ������� ");
	printf("���. \n������� ������� y, ���� ��� ������� ����� � ");
	printf("\n������� n � ��������� ������.\n");
	printf("����� ������ �������� %d?\n", guess);
	while ((response = getchar()) != 'y')		/* �������� ����� */
	{
		if (response == 'n')
			printf("�a��o, ����� ��� % d ? \n", ++guess);
		else
			printf("����������� ������ �������� y ��� n.\n");
		while (getchar() != '\n')
			continue;							/* ���������� ���������� ����� ������� ������*/
	}	
	printf("� ����, ��� � ���� ���������!\n");
	return 0;
}
// ������� 8.5. ��������� showcharl. �
/* showchar1.c -- ��������� � ������� ��������� �����-������ */
#include <stdio.h>
void display(char cr, int lines, int width);
int showchar1(void)
{
	int ch;					/*��������� ������ */
	int rows, cols;			/* ���������� ����� � �������� */
	printf("\n\033[1;4;44m������� 8.5.���������  showchar1.c -- ��������� � ������� ��������� �����-������.\033[0m\n");
	printf("B�e���e ������ � ��� ����� ����� : \n");
	while ((ch = getchar()) != '\n')
	{
		scanf_s("%d %d", &rows, &cols);
		display(ch, rows, cols);
		printf("B�e���e ��� ���� ������ � ��� ����� �����; \n");
		printf("��� ���������� ������� ������ ����� ������.\n");
	}
	printf("�porpa��a ���������.\n");
	return 0;
}
// ������� 8.6. ��������� showchar2 . �
/* showchar2.c -- ������� ������� � ������� � �������� */
#include <stdio.h>
void display(char cr, int lines, int width);
int showchar2(void)
{
	int ch; /* �����1^���� ������ */
	int rows, cols; /* ���������� ����� � �������� */
	printf("\n\033[1;4;44m������� 8.6.���������  showchar2.c -- ���������� �������� �����-������.\033[0m\n");
	printf("������� ������ � ��� ����� �����:\n");
	while ((ch = getchar()) != '\n')
	{
		if (scanf_s("%d %d", &rows, &cols) != 2)
			break;
		display(ch, rows, cols);
		while (getchar() != '\n')
			continue;
		printf("������� ��� ���� ������ � ��� ����� �����;\n");
		printf("��� ���������� ������� ������ ����� ������.\n");
	}
	printf("�po�pa��a ���������.\n");
	return 0;
}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n'); /* ��������� ������ � ������ ����� */
	}
}

// ������� 8.7. ��������� checking. �
// checking.c � �������� ������������ �����
#include <stdio.h>
#include <stdbool.h>
// ��������, �������� �� ���� �������������
long get_long(void);
// ��������, ��������� �� ������� ���������
bool bad_limits(long begin, long end, long low, long high);
// ���������� ����� ��������� ����� ����� �� � �� �
double sum_squares(long �, long �);
int checking(void)
{
	const long MIN = -10000000L;			// ������ ������ ���������
	const long ��� = +10000000L;			// ������� ������ ���������
	long start;								// ������ ���������
	long stop;								// ����� ���������
	double answer;
	printf("��� ��������� ��������� ����� ��������� "
		"����� ����� � �������� ���������. \n������ ������� �� ������ "
		"���� ������ -10000000, \na ������� �� ������ ���� "
		"������ + 10000000. \n������� �������� "
		"�������� (��� ���������� ������� 0 ��� ����� ��������):\n"
		"������ ������: "INPUT3);
	start = get_long();
	printf("������� ������: "INPUT3);
	stop = get_long();
	while (start != 0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, ���))
			printf("��������� �������.\n");
		else
		{
			answer = sum_squares(start, stop);
			printf("C���� ��������� ����� ����� ") ;
			printf("o� %ld �� %ld ����� %g\n", start, stop, answer);
		}
		printf("������� �������� �������� (��� ���������� "
			"������� 0 ��� ����� ��������): \n");
		printf("������ ������: "INPUT3);
		start = get_long();
		printf("�epx��� ������: "INPUT3);
		stop = get_long();
	}
	printf("�po�pa��a ���������.\n");
	return 0;
}
long get_long(void)
{
	long input;
	char ch;
	while (scanf_s("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);			// ��������� ������������ ����
		printf(" �� �������� �������������.\n������� ");
		printf("�e�oe �����, ����� ��� 25, -178 ��� 3: ");
	}
	return input;
}
double sum_squares(long a, long �)
{
	double total = 0;
	long i;
	for (i = a; i <= �; i++)
		total += (double)i * (double)i;
	return total;
}
bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%ld �� ������ ��� %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("�������� ������ ���� ����� %d ��� ������.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("�������� ������ ���� ����� %d ��� ������.\n", high);
		not_good = true;
	}
	return not_good;
}
// ������� 8.8. ��������� menuette. �
/* menuette.c � ���������� ���� */
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int menuette(void)
{
	int choice;
	//void count(void);
	printf("\n\033[1;4;44m������� 8.8.���������  menuette.c -- ���� ���������� �������� �����-������.\033[0m\n");
	while ((choice = get_choice()) != '�')
	{
		switch (choice)
		{
		case '�': printf("��������� ������, ���������� ������.\n");
			break;
		case '�': putchar('\a'); /* ANSI */
			break;
		case '�': count();
			break;
		default: printf("������! \n");
			break;
		}
	}
	printf("nporpa��a ���������. \n");
	return 0;
}
void count(void)
{
	int n, i;
	printf("�� ������ ������� ����� �������? ������� ����� �����:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	while (getchar() != '\n')
		continue; 
}
char get_choice(void)
{
	int ch;
	printf("B�e���e �����, ��������������� ���������� ��������:\n");
	printf("�.�����		�.������ \n");
	printf("�.�������	�.�����\n");
	ch = get_first();
	while (ch != '�' && ch != '�' && ch != '�' && ch != '�')
	{
		printf("B��ep��e �, �, � ��� �.\n");
		ch = get_first();
	}
	return ch;
}
char get_first(void)
{
		int ch;
		ch = getchar();
		while (getchar() != '\n')
			continue;
		return ch; 
}
int get_int(void)
{
	int input;
	char ch;
	while (scanf_s("%d", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch); // ��������� ������������ ����
		printf(" �� �������� �������������.\n������� ");
		printf("�e�oe �����, ����� ��� 25, -178 ��� 3: ");
	}
	return input;
}