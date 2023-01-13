#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
// ������� 11.1. ��������� stringsl. �
// strings1.�
#include <stdio.h>
#define MSG "� - ���������� ��������� ���������."
#define MAXLENGTH 81
int strings1(void)
{
	char words[MAXLENGTH] = "� ������� �������, ���������� � �������.";
	const char* pt1 = "���-�� ��������� �� ����.";
	printf("\n\033[1;4;44m������� 11.1.���������  strings1.c -- ��������� �������� ������������� �����.\033[0m\n");
	puts("��� ��������� �����:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[14] = '�';
	puts(words);
	return 0;
}
// ������� 11.2. ��������� strptr. �
/* quotes.� -- ������ ��� ��������� */
int quotes(void)
{
	printf("\n\033[1;4;44m������� 11.2.���������  quotes.c -- ������ ��� ���������.\033[0m\n");
	printf("%s, %p, %c\n", "��", " - ", *"����������� �������");
	return 0;
}
// ������� 11 .�. ��������� a^ddresses. �
// addresses.c -- ������ �����
#define MSG "� ���������."
#include <stdio.h>
int addresses()
{
	char ar[] = MSG;
	const char* pt = MSG;
	printf("\n\033[1;4;44m������� 11.3.���������  quotes.c -- ������ ��� ���������.\033[0m\n");
	printf(" ����� \"� ���������.\": %p \n", "� ���������.");
	printf(" ����� ar:             %p\n", ar);
	printf(" ����� pt:             %p\n", pt);
	printf(" ����� MSG:            %p\n", MSG);
	printf(" ����� \"� ���������.\": %p \n", "� ���������.");
	return 0;
}
// ������� 11.4. ��������� arrchar. �
// arrchar.c - ������ ����������, ������ �����
#include <stdio.h>
#define SLEN 40
#define LIM 5
int arrchar(void)
{
	const char* mytalents[LIM] = {
	"���������� ����������� �����",
	"������ ���������", "������������ ������",
	"���������� ���������� � ��������� �� �����",
	"������ ����� ���������������� �"
	};
	char yourtalents[LIM][SLEN] = {
	"�������� �� ������",
	"�������� ���", "�������� �����������",
	"�������� �����", "������ ����������� �����"
	};
	int i;
	printf("\n\033[1;4;44m������� 11.4.���������  arrchar.c - ������ ����������, ������ �����.\033[0m\n");
	puts("������� ���� �������.");
	printf("%-52s %-25s\n", "��� �������", "���� �������");
	for (i = 0; i < LIM; i++)
	printf("%-52s %-25s\n", mytalents[i] , yourtalents[i]);
	printf("\npa��ep mytalents: %zd, ������ yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));
	return 0;
	}
// ������� 11.5. ��������� p _ a n d _ s . �
/* p_and_s.c -- ��������� � ������ */
int p_and_s(void)
{
	const char* mesg = "�� ���������� ���� ��������!";
	const char* ����;
	���� = mesg;
	printf("\n\033[1;4;44m������� 11.5.���������  p_and_s.c -- ��������� � ������.\033[0m\n");
	printf("%s\n", ����);
	printf("mesg = %s; &mesg = %p; value = %p\n",
		mesg, &mesg, mesg);
	printf("copy = %s; &���� = %p; value = %p\n",
		����, &����, ����);
	return 0;
}
// ������� 11.6. ��������� getsputs. �
/* getsputs.c -- ������������� ������� gets () � puts () */
#include <stdio.h>
#define STLEN 81
int getsputs(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44m������� 11.6.���������  getsputs.c -- ������������� ������� gets () � puts ().\033[0m\n");
	puts("������� ������.");
	gets(words);
	printf("���� ������, ���������� ������:\n");
	printf("%s\n", words);
	puts(words);
	puts("������.");
	return 0;
}
// ������� 11.7. ��������� fgetsl. �
/* fgets1.c -- ������������� ������� fgets() � fputs() */
#include <stdio.h>
#define STLEN 15
int fgets1(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44m������� 11.7.���������  fgets1.c -- ������������� ������� fgets() � fputs().\033[0m\n");
	puts("������� ������.");
	fgets(words, STLEN, stdin);
	printf("���� ������, ���������� ������ (� ������� puts(), � ����� fputs()) :\n");
	puts(words);
	fputs(words, stdout);
	puts("������� ��� ���� ������.");
	fgets(words, STLEN, stdin);
	printf("���� ������, ���������� ������ (� ������� puts(), � ����� fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("������.");
	return 0;
}
// ������� 11.8. ��������� fgets2. �
/* fgets2.c -- ������������� ������� fgets() � fputs() */
#include <stdio.h>
#define STLEN 10
int fgets2(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44m������� 11.8.���������  fgets2.c -- ������������� ������� fgets() � fputs().\033[0m\n");
	puts("������� ������ (��� ������ ������ ��� ������ �� ���������):");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs(words, stdout);
	puts("������.");
	return 0;
}
// ������� 11.9. ��������� fgets3. �
/* fgets3.c -- ������������� ������� fgets() */
#include <stdio.h>
#define STLEN 10
int fgets3(void)
{
	char words[STLEN];
	int i;
	printf("\n\033[1;4;44m������� 11.9.���������  fgets3.c -- ������������� ������� fgets().\033[0m\n");
	puts("������� ������ (��� ������ ������ ��� ������ �� ��������) : ");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else // ��������� ������� words [i] == '\0'
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("������.");
	return 0;
}
// ������� 11.10. ������� s_gets()
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
		ret_val = fgets(st, n, stdin);
		if (ret_val)			// �.�. ret_val != NULL
		{
			while (st[i] != '\n' && st[i] != '\0') i++; // ����� ����� �������� ������
			if (st[i] == '\n') st[i] = '\0';			// ������ ������ ����������� �����
			else										// ������ �������
				while (getchar() != '\n') continue;		// ��������� ��� �������������� ������� ������� ������
		}
		return ret_val;
}
// ������� 11.11. ��������� scan_str.�
/* scan_str.c -- ������������� ������� scanf() */
#include <stdio.h>
int scan_str(void)
{
	char name1[11], name2[11];
	int count;
	printf("\n\033[1;4;44m������� 11.11.��������� scan_str.c -- ������������� ������� scanf().\033[0m\n");
	printf("������� ��� ����� ����� ������.\n");
	count = scanf_s("%5s %10s", name1,10, name2,10);
	printf("��������� %d �����: %s � %s.\n", count, name1, name2);
	return 0;
}
// ������� 11.12. ��������� put_out.�
/* put_out.c -- ������������� ������� puts() */
#include <stdio.h>
#define DEF "� - ������, ������������ ���������� #define."
int put_out(void)
{
	char str1[80] = "������ ��� ��������������� ���� ���������.";
	const char* str2 = "��������� ��� ��������������� ���� ���������.";
	printf("\n\033[1;4;44m������� 11.12.��������� put_out.c -- ������������� ������� puts().\033[0m\n");
	puts("� - �������� ������� puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[6]);
	puts(str2 + 4);
	return 0;
}
// ������� 11.13. ��������� nono.�
/* ��������� nono.� -- �� ������� ���! */
int nono(void)
{
	char side_a[] = "������� �";
	char dont[] = {'�', '�', '�', '!'};
	char side_b[] = "������� �";
	printf("\n\033[1;4;44m������� 11.13.��������� nono.� -- �� ������� ���!\033[0m\n");
	puts(dont); /* dont �� �������� ������� */
	return 0;
}
// ������� 11.14.������� put1()
/* put1.� � ������� ������ ��� ���������� ������� \n */
#include <stdio.h>
void put1(const char* string) /* ������ �� ���������� */
{
	while (*string != '\0')
		putchar(*string++);
}
// ������� 11.15. ������� put2()
/* put2.c -- ������� ������ � ������������ ������� */
#include <stdio.h>
int put2(const char* string)
{
	int count = 0;
	while (*string) /* ������������ ������ */
	{
		putchar(*string++);
		count++;
	}
	putchar('\n'); /* ������ ����� ������ �� ����������� */
	return(count);
}
// ������� 11.16. ��������� putyut.c
// put_put.c -- ������� ������, ������������ �������������
#include <stdio.h>
void put1(const char*);
int put2(const char*);
int put_put(void)
{
	printf("\n\033[1;4;44m������� 11.16.��������� put_put.c -- ������� ������, ������������ �������������\033[0m\n");
	put1("���� �� � ���� ���� ������� �����,");
	put1(" ������� � ��� �� ���������,\n");
	printf("���������� %d ��������.\n",	put2("�� � ������� �� ��������� �� � ������� ������ ��������."));
	return 0;
}
//void put1(const char* string)
//{
//	while (*string) /* ������������ *string != '\0' */
//		putchar(*string++);
//}
//int put2(const char* string)
//{
//	int count = 0;
//	while (*string)
//	{
//		putchar(*string++);
//		count++;
//	}
//		putchar('\n');
//	return(count);
//}
// ������� 11.17. ��������� test_fit.c
/* test_fit.c -- ������������� ������� ������������ ����� */
#include <stdio.h>
#include <string.h> /* �������� ��������� ��������� ������� */
void fit(char*, unsigned int);
int test_fit(void)
{
	char mesg[] = "��� ������ ���� ����������� �������,"
		" �� �� �����. ";
	printf("\n\033[1;4;44m������� 11.17.��������� test_fit.c -- ������������� ������� ������������ �����\033[0m\n");
	puts(mesg);
	fit(mesg, 35);
	puts(mesg);
	puts("���������� ��� ��������� �����.");
	puts(mesg + 36);
	return 0;
}
void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		string[size] = '\0';
}
// ������� 11.18. ��������� str_cat.c
/* str_cat.c -- ���������� ��� ������ */
#include <stdio.h>
#include <string.h> /* ���������� strcat() */
#define SIZE 80
char* s_gets(char* st, int n);
int str_cat(void)
{
	char flower[SIZE];
	char addon[] = " ������ ��� ������ �������.";
	printf("\n\033[1;4;44m������� 11.18.��������� str_cat.c -- ���������� ��� ������\033[0m\n");
	puts("Ka�o� � ��� ������� ������?");
	if (s_gets(flower, SIZE))
	{
		strcat_s(flower, SIZE, addon);
		puts(flower);
		puts(addon);
	}
	else
		puts("��������� ����� �����!");
	puts("��������� ���������.");
	return 0;
}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	int i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//		st[i] = '\0 ';
//		else // ��������� ������� words[i] == '\0'
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}
// ������� 11.19. ��������� join_chk. �
/* join_chk.c -- ���������� ��� ������, �������������� �������� ������ */
#include <stdio.h>
#include <string.h>
#define SIZE 33
#define BUGSIZE 23
char* s_gets(char* st, int n);
int join_chk(void)
{
	char flower[SIZE];
	char addon[] = " ������ ��� ������ �������.";
	char bug[BUGSIZE];
	int available;
	printf("\n\033[1;4;44m������� 11.19.��������� join_chk.c -- ���������� ��� ������, �������������� �������� ������\033[0m\n");
	puts("����� � ��� ������� ������?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat_s(flower, SIZE, addon);
	puts(flower);
	puts("����� � ��� ������� ���������?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat_s(bug, BUGSIZE, addon, available);
	puts(bug);
	return 0;
}
// ������� 11.20. ��������� nogo.�
/* nogo.c � ����� �� ��� ��������? */
#include <stdio.h>
#define ANSWER "�����"
#define SIZE 40
char* s_gets(char* st, int n);
int nogo(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44m������� 11.20.��������� nogo.c � ����� �� ��� ��������?\033[0m\n");
	puts("��� ��������� � ������ ������?");
	s_gets(try, SIZE);
	while (try != ANSWER)
	{
		puts("�����������! ����������� ��� ���.");
		s_gets(try, SIZE); 
	}
	puts("������ ���������!");
	return 0;
}
// ������� 11.21. ��������� compare. �
/* compare.c -- ��� ��������� ����� �������� */
#include <stdio.h>
#include <string.h> // ���������� strcmp()
#define ANSWER "�����"
#define SIZE 40
char* s_gets(char* st, int n);
int compare(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44m������� 11.21.��������� compare.c -- ��� ��������� ����� ��������\033[0m\n");
	puts("��� ��������� � ������ ������?");
	s_gets(try, SIZE);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("�����������! ����������� ��� ���.");
		s_gets(try, SIZE);
	}
	puts("Tene�� ���������!");
	return 0;
}
// ������� 11.22. ��������� ��������. �
/* compback.c -- ��������, ������������ �������� strcmp() */
#include <stdio.h>
#include <string.h>
int compback(void)
{
	printf("\n\033[1;4;44m������� 11.22.��������� compback.c -- ��������, ������������ �������� strcmp()\033[0m\n");
	printf("strcmp(\"A\", \"A\") ���������� ");
	printf("% d\n", strcmp("A", "A"));
	printf("strcmp(\"A\", \"B\") ���������� ");
	printf("% d\n", strcmp("A", "�"));
	printf("strcmp(\"B\", \"A\") ���������� ");
	printf("% d\n", strcmp("B", "A"));
	printf("strcmp(\"C\", \"A\") ���������� ");
	printf("% d\n", strcmp("C", "A"));
	printf("strcmp(\"Z\", \"a\") ���������� ");
	printf("% d\n", strcmp("Z", "a"));
	printf("strcmp(\"apples\", \"apple\") ���������� ");
	printf("% d\n", strcmp("apples", "apple"));
	return 0;
}
// ������� 11.23. ��������� quit_chk. �
/* quit_chk.c -- ������ ��������� ��������� */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_gets(char* st, int n);
int quit_chk(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf("\n\033[1;4;44m������� 11.23.��������� quit_chk.c -- ������ ��������� ���������\033[0m\n");
	printf("������� �� %d ����� (��� quit ��� ����������):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)
	{
		ct++;
	}
	printf("������� %d ����� (�) \n", ct);
	return 0;
}
// ������� 11.23a. ��������� quit_chkNull. �
/* quit_chkNull.c -- ������ ��������� ��������� */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_gets(char* st, int n);
int quit_chkNull(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf("\n\033[1;4;44m������� 11.23a.��������� quit_chkNull.c -- ������ ��������� ���������, ����������-������ ������\033[0m\n");
	printf("������� �� %d ����� (Enter - ���������� �����):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ct++;
	}
	printf("������� %d ����� (�) \n", ct);
	return 0;
}
// ������� 11.24. ��������� starsrch. �
/* starsrch.c -- ������������� ������� strncmp() */
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
int starsrch()
{
	const char* list[LISTSIZE] =
	{
		"����������", "��������",
		"�����������", "���������",
		"��������", "����������"
	};
	int count = 0;
	int i;
	printf("\n\033[1;4;44m������� 11.24.��������� starsrch.c -- ������������� ������� strncmp()\033[0m\n");
	for (i = 0; i < LISTSIZE; i++)
		if (strncmp(list[i], "�����", 5) == 0)
		{
			printf("Ha��e�o: %s\n", list[i]);
			count++;
		}
	printf("���������� ���� � ������,"
		" ������������ � �����: %d\n", count);
	return 0;
}
// ������� 11.25. ��������� copy1.�
/* copy1.� � ������������ ������������� strcpy() */
#include <stdio.h>
#include <string.h> // ���������� strcpy()
#define SIZE 40
#define LIM 5
char* s_gets(char* st, int n);
int copy1(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	printf("\n\033[1;4;44m������� 11.25.��������� copy1.� � ������������ ������������� strcpy()\033[0m\n");
	printf("B�e���e % d ����, ������� ���������� � ����� �: \n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != '�')
			printf("%s �� ���������� � ����� �!\n ", temp);
		else
		{
			strcpy_s(qwords[i], SIZE, temp);
			i++;
		}
	}
	puts("������ �������� ����:");
	for(i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}
// ������� 11.26. ��������� copy2.�
/* copy2.� -- ������������ ������������� strcpy() */
#include <stdio.h>
#include <string.h> // ���������� strcpy ()
#define WORDS "���������"
#define SIZE 40
int copy2(void)
{
	const char* origin = WORDS;
	char copy[SIZE] = "������ ������, ��� ����� �� ����.";
	char* ps;
	printf("\n\033[1;4;44m������� 11.26.��������� copy2.� -- ������������ ������������� strcpy()\033[0m\n");
	puts(origin);
	puts(copy);
	strcpy_s(copy + 7,10, origin);
	puts(copy);
	//puts(ps);
	return 0;
}
// ������� 11.27. ��������� copy�. �
/* copy�.� -- ������������ ������������� strncpy() */
#include <stdio.h>
#include <string.h> /* ���������� strncpy () */
#define SIZE 40
#define TARGSIZE 15
#define LIM 5
char* s_gets(char* st, int n);
int copy�(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;
	printf("\n\033[1;4;44m������� 11.27.��������� copy�.� -- ������������ ������������� strncpy()\033[0m\n");
	printf("������� %d ����, ������� ���������� � ����� �:\n ", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != '�')
			printf("%s �� ���������� � ����� �!\n ", temp);
		else
		{
			strncpy_s(qwords[i], TARGSIZE, temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("������ �������� ����:");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}
// ������� 11.28. ��������� format.�
/* format.c � �������������� ������ */
#include <stdio.h>
#define MAX 20
char* s_gets(char* st, int n);
int format(void)
{
	char first[MAX];
	char last[MAX];
	char forma1[2* MAX +10];
	double prize;
	printf("\n\033[1;4;44m������� 11.28.��������� format.c � �������������� ������\033[0m\n");
	puts("������� ���� ���:");
	s_gets(first, MAX);
	puts("������� ���� �������:");
	s_gets(last, MAX);
	puts("������� ����� ��������� �����:");
	scanf_s("%lf", &prize);
	sprintf_s(forma1, 2* MAX +10, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(forma1);
	return 0;
}
// ������� 11.28a. ��������� strFunctions.�
/* strFunctions.� -- ������ ������ ��������� ������� */
#define MAX 80
int strFunctions(void) {
	char tok_sArr[20][20] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int n;
	char* pstr;
	char copy[MAX];
	char last[MAX];
	char buff[100];
	const char* source = "�������� ������ ��� �������.";
	printf("\n\033[1;4;44m������� 11.28a.��������� strFunctions.c � ������ ������ ��������� �������\033[0m\n");
	printf("������ strcpy_s(copy, source):\n");
	strcpy_s(copy,29, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n",copy,source);

	printf("\n������ strncpy_s(copy,29, source,10):\n");
	strncpy_s(copy,29, source,10);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n",copy,source);

	printf("\n������ strcat_s(copy,MAX, source):\n");
	strcat_s(copy,MAX, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n", copy, source);

	printf("\n������ strncat_s(copy,MAX, source,5):\n");
	strncat_s(copy, MAX, source,5);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n", copy, source);

	printf("\n������ n=strcmp(copy, source):\n");
	n=strcmp(copy, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\n������ n=strncmp(copy, source,8):\n");
	n=strncmp(copy, source,8);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\n������ n=strncmp(copy, source,12):\n");
	n=strncmp(copy, source,12);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\n������ pstr=strchr(copy, '�'):\n");
	pstr = strchr(copy, '�');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strchr(copy, '�'):\n");
	pstr = strchr(copy, '�');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strpbrk(copy, \"����\"):\n");
	pstr = strpbrk(copy, "����");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strpbrk(copy, \"�����\"):\n");
	pstr = strpbrk(copy, "�����");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strrchr(copy,'�'):\n");
	pstr = strrchr(copy, '�');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strstr(copy,\"���\"):\n");
	pstr = strstr(copy, "���");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ pstr=strstr(copy,\"���\"):\n");
	pstr = strstr(copy, "���");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\n������ n=strlen(copy):\n");
	n = strlen(copy);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%zd\n", copy, source, n);

	printf("\n������ n=strspn(copy, \"���������\"):\n");
	n = strspn(copy, "���������");
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%zd\n", copy, source, n);

	//printf("\n������ pstr=strtok(source, \". \"):\n");
	//pstr = strtok_s(source, ". ", tok_sArr);
	//printf("%s\n", pstr);
	////while (pstr=strtok(NULL, ". "))	{
	////	printf("%s\n", pstr);
	////}
	//printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%p\n", copy, source, pstr);
		printf("\n������ pstr=strtok(source, \". \"):\n");
		char data[] = " � ��������\t ����� #����� \n�������!";
		const char tokseps[] = " \t\n#";	/* ����������� */
		char context[10][10];
		char * pt;
		puts(data);
		pt = strtok_s(data,tokseps, context) ;		/* ������ ����� */
		while (pt)			/* ����� � ������ NULL */
		{
			puts (pt);		/* �������� ������� */
			pt = strtok_s(NULL, tokseps, context);	/* ��������� ������� */
		}

		//printf("1........01........01........01........01........01........01........01........01........01........01........0\n");
	printf("\n������ pstr = strerror_s(buff,100,i);\n");
	int len,k=2,l;
	for (int i = 0; i < 999; i++) {
		n = strerror_s(buff, 100, i);
		len = strlen(buff);
		printf("i=%3d-%s ",i, buff);
		k = (i < 140) ? 2 : 5;
		l = (i < 140) ? 50 : 15;
		if (i % k) { if (len < l) for (int j = 0; j < l - len;j++) printf(" "); }
		if (!(i % k)) printf("\n");
	}

return 0;
}
// ������� 11.29. ��������� sort_str.c
/* sort_str.c -- ��������� ������ � ��������� �� */
#include <stdio.h>
#include <string.h>
#define SIZE 81			/* ����� �� ����� ������, ������� \0 */
#define LIM 20			/* ������������ ���������� �������� ����� */
#define HALT			/* ������� ������ ��� ����������� ����� */
void stsrt(char* strings[], int num, int arr[]);/* ������� ���������� ����� */
char* s_gets(char* st, int n);
int sort_str(void)
{
	char input[LIM][SIZE];	/* ������ ��� ���������� ������� ������ */
	char* ptstr[LIM];		/* ������ ���������� ���� ��������� */
	int ct = 0;				/* ������� ����� */
	int k;					/* ������� ������ */
	int idx[LIM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};			/* ������ ����� */
	printf("\n\033[1;4;44m������� 11.29.��������� sort_str.c -- ��������� ������ � ��������� ��\033[0m\n");
	printf("������� �� %d �����, � ��� ����� �������������.\n", LIM);
	printf("����� ���������� ����, ������� ������� Enter � ������ ������.\n %d:",1);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct]; /* ��������� ���������� �� ������ */
		//idx[ct] = ++ct;
		printf("%2d:", ++ct + 1);
	}
	stsrt(ptstr, ct,idx);			/* ����������� ����� */
	puts("\n��������������� ������:\n");
	for (k = 0; k < ct; k++)
		printf("%2d(%2d): %s\n",k+1,idx[k], ptstr[k]);
		//puts(ptstr[k]);			/* ��������������� ��������� */
	printf("\n");
	return 0;
}
/* ������� ���������� ���������� �� ������ */
void stsrt(char* strings[], int num,int arr[])
{
char* temp;
int itemp;
int top, seek;
for (top = 0; top < num - 1; top++)
	for (seek = top + 1; seek < num; seek++)
		if (strcmp(strings[top], strings[seek]) > 0)
		{
			temp = strings[top];
			strings[top] = strings[seek];
			strings[seek] = temp;
			itemp = arr[top];
			arr[top] = arr[seek];
			arr[seek] = itemp;
		}
}
// ������� 11.30. ��������� mod_str.�
/* mod_str.c � ������������ ������ */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char*);
int PunctCount(const char*);
int mod_str(void)
{
	char line[LIMIT];
	char* find;
	printf("\n\033[1;4;44m������� 11.30.��������� mod_str.c � ������������ ������\033[0m\n");
	puts("������� ������:");
	fgets(line, LIMIT, stdin);
	find = strchr(line, '\n');	// ����� ������� ����� ������
	if (find)					// ���� ����� �� �������� NULL,
		*find = '\0';			// ��������� ���� ������� ������
	ToUpper(line);
	puts(line);
	printf("��� ������ �������� %d ������ ����������. \n", PunctCount(line));
	return 0;
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
int PunctCount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str++)) ct++;
		//str++;
	}
	return ct;
}
//������� 11.31.��������� r e ^ a t.c
/* repeat.c -- ������� rnain() � ����������� */
#include <stdio.h>
int repeat(int argc, char* argv[])
{
	int count;
	printf("\n\033[1;4;44m������� 11.31.��������� repeat.c -- ������� rnain() � �����������\033[0m\n");
	printf("���������� ����������, ��������� � ��������� ������: %d\n", argc - 1);
	for (count = 1; count < argc; count++)
		printf("%d: %s\n", count, argv[count]);
	printf("\n");
	return 0;
}
//������� 11.32.��������� hello.�
/* hello.c -- ����������� �������� ��������� ������ � ����� */
#include <stdio.h>
#include <stdlib.h>
int hello(int argc, char* argv[])
{
	int i, times;
	printf("\n\033[1;4;44m������� 11.32.��������� hello.c -- ����������� �������� ��������� ������ � �����\033[0m\n");
	if (argc < 2 || (times = atoi(argv[1])) < 1)
		printf("�������������: %s �������������-�����\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts("Xopo���� ���!");
	return 0;
}
// ������� 11.33. ��������� strcnvt. �
/* strcnvt.c -- ������������� ������� strtol() */
#include <stdio.h>
#include <stdlib.h>
#define LIM 30
char* s_gets(char* st, int �);
int strcnvt()
{
	char number[LIM];
	char* end;
	long lvalue10,lvalue16;
	int ivalue;
	double dvalue;
	float fvalue;
	printf("\n\033[1;4;44m������� 11.33.��������� strcnvt.c -- ������������� ������� strtol()\033[0m\n");
	puts("������� ����� (��� ������ ������ ��� ������ �� ���������):"INPUT3);
	while (s_gets(number, LIM) && number[0] != '\0')
	{
		lvalue10 = strtol(number, &end, 10);		/* �� ��������� 10 */
		printf("���������� ����, ���������� �����: %ld, ��������� �� %s (%d)\n", lvalue10, end, *end);
		ivalue = _strtoi64(number, &end, 16);
		dvalue = strtod(number, &end);
		fvalue = strtof(number, &end);
		lvalue16 =  strtol(number, &end, 16);		/* �� ��������� 16 */
		printf("����������������� ����, ����������������� �����: %ld, ��������� �� %s (%d)\n", lvalue16, end, *end);
		puts("��������� �����:"INPUT3);
	}
	puts("��������� ���������.\n");
	return 0;
}

// 1. B������ ��� ������������.
int quest1_4(void) {
	char name[] = { '�', '�', '�', '�',0 };
	char sname[] = { "����" };
	char cname[] =  "����";
	printf("\n\033[1;4;44mB������ ��� ������������. 1 - ����� ������ �������� � �������������� ���������� ���������� ������?\033[0m\n");
	printf("%s ------- %s ------- %s", name,sname,cname);

	printf("\n\033[1;4;44mB������ ��� ������������. 2. ��� ������� ��������� ���������?\033[0m\n");
	char note[] = "�������� ������ � ����.";
	char* ptr;
	ptr = note;
	puts(ptr);
	puts(++ptr);
	note[7] = '\0' ;
	puts(note);
	puts(++ptr);
	
	printf("\n\033[1;4;44mB������ ��� ������������. 3. ��� ������� ��������� ���������?\033[0m\n");
	char food[] = "������";
	char* qptr;
	qptr = food + strlen(food);
	while (--qptr >= food) puts(qptr);

	printf("\n\033[1;4;44mB������ ��� ������������. 4. ��� ������� ��������� ���������?\033[0m\n");
	char goldwyn[31] = "��� � ���� ";
	char samuel[41] = "�� ��� ���";
	const char* quote = "������� ���� �����.";
	strcat_s(goldwyn,31, quote);
	strcat_s(samuel,41, goldwyn);
	puts(samuel);
	return 0;
}
/*
5. ����������� ���� ������� �������� ���������������� �� ��������, �������,
����������� � �� ������������������. �����������, ��� ������� ����� ����������� �������:char *pr(char *str)
#include <stdio.h>

��������� �� ��������� ����� �������:
� = pr("�� �� �� !");
�. ��� �� �������?
�. ����� ��� ������ ����� ���������� �?
�. ����� �������� �������� ���������� �?
�. ��� �������� ��������� *--��, � ��� ��� ���������� �� --*�� ?
�. ��� ����� ��������, ���� *--�c �������� ���������� *�c-- ?
�. ��� ���� ������������� ��� ��������� �������� � ���������� while?
�. ��� ����������, ���� ������� pr() �������� � �������� ��������� ������ ������?
�. ��� �������� ������� � ���������� �������, ����� pr() ����� ���� ������������ ���, ��� �������� ����?
*/
char* pr(char* str)
{
	char* pc;
	pc = str;
	while (*pc) putchar(*pc++);
	while (pc > str) {
		putchar(*--pc);
	};
	return (pc);
}
char* pr1(char* str)
{
	char* pc;
	pc = str;
	while (*pc) putchar(*pc++);
	do {
		putchar(*pc--);
	} while (pc - str);
	return (pc);
}

int quest5(void) {
	char* x;
	printf("\n\033[1;4;44mB������ ��� ������������. 5. ������� ����� ����������� �������:char *pr(char *str)\033[0m\n");
	x = pr("�� �� �� !");			// �� �� �� !! �� �� ��
	printf("\n%s\n", x);			// �� �� �� !!
	x = pr1("�� �� �� !");			// �� �� �� !! �� �� �
	printf("\n%s\n", x);			// �� �� �� !
	x = pr("");						// �������� ������ ���� �� while (pc >= str){};
	printf("\n%s\n", x);			// ������� �������������� ����������: ��������� ������� ��� ������.	pc ���� 0x7FF6C130FFFF.

}
// 	7. ��� ������� ��������� ��������� ?
#include <stdio.h>
#include <string.h>
#define M1 "How are ��, sweetie?"
int quest6(void) {
	char M2[40] = "Beat the clock.";
	char* M3 = "chat";
	char words[80];
	printf("\n\033[1;4;44mB������ ��� ������������. 7. ��� ������� ��������� ��������� ?\033[0m\n");
	printf(M1);
	puts(M1);
	puts(M2);
	puts(M2 + 1);
	strcpy_s(words,80, M2);
	strcat_s(words,80, " Win � toy.");
	puts(words);
	words[4] = '\0';
	puts(words);
	while (*M3)
		puts(M3++);
	puts(--M3);
	puts(--M3);
	puts(--M3);
	puts(--M3);
	M3 = M1;
	puts(M3);
	return 0;
}
// 8. ��� ������� ��������� ���������?
#include <stdio.h>
char* s_getsPtr(char* st, int n);
int quest8(void)
{
	char str1[] = "gawsie";
	char str2[] = "bletonism";
	char* ps;
	int i = 0;
	printf("\n\033[1;4;44mB������ ��� ������������. 8. ��� ������� ��������� ���������?\033[0m\n");
	for (ps = str1; *ps != '\0'; ps++) {
		if (*ps == 'a' || * ps == 'e')
			putchar(*ps);
		else
			(*ps)--;
		putchar(*ps);
	}
	putchar('\n');
	while (str2[i] != '\0') {
		printf("%c", i % 3 ? str2[i] : '*');
		++i;
	}
	return 0;
}
// 9. ������� s_gets(), ������������ � ���� �����, ����� ���������� � ����� � ��������������
//����������, � �� ��������, ����� ��������� �� ��� ���������� i. �������� ���.
int quest9(void) {
	char* arr[80];
	char* sptr;
	printf("\n\033[1;4;44mB������ ��� ������������. 9. ���������� s_gets � �����������.\033[0m\n");
	printf("������� �����:"INPUT3);
	sptr = s_getsPtr(arr,80);
	printf("�������: %s",sptr);
	return 0;
}
//  ������� s_getsPtr() ������ s_gets � �����������
char* s_getsPtr(char* st, int n)
{
	char* ret_val;
	//int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)			// �.�. ret_val != NULL
	{
		while (*st != '\n' && *st != '\0') st++;	// ����� ����� �������� ������
		if (*st == '\n') *st = '\0';				// ������ ������ ����������� �����
		else										// ������ �������
			while (getchar() != '\n') continue;		// ��������� ��� �������������� ������� ������� ������
	}
	return ret_val;
}
/*
10. ������� strlen() ��������� ��������� �� ������ � �������� ��������� � ����������
����� ������. �������� ���� ������ ���� �������.
*/
int strlen10(char* in);
int quest10(void) {
	char* arr=  "1234567890123456789012345678901234567890123456789012345678901234567890" ;
	printf("\n\033[1;4;44mB������ ��� ������������. 10. �������� int strlen(cyar* in)\033[0m\n");
	printf("strlen(\"QWERTYUIOP\")=%d strlen(arr)=%d strlen(\"\")=%d", strlen10("QWERTYUIOP"), strlen10(arr), strlen(""));
	return 0;
}
int strlen10(char* in) {
	int l=0;
	while (*in++)l++;
	return l;
}
/*
11. ������� s_gets(), ������������ � ���� �����, ����� ���������� � ��������������
������� strchr() ������ ����� while ��� ����������� ������� ����� ������. �������� ���.
*/
char* s_gets11(char* st, int n);
int quest11(void) {
	char arr[100];
	char* ptr;
	printf("\n\033[1;4;44mB������ ��� ������������. 11. ���������� s_gets() � �������������� ������� strchr()\033[0m\n");
	printf("������� ������:"INPUT3);
	ptr = s_gets11(arr, 70);
	printf("����� ������:%s\n",ptr);
	return 0;
}
char* s_gets11(char* st, int n){
	char* ret_val;
	char* ptr;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)			// �.�. ret_val != NULL
	{
		ptr=strchr(st, '\n');
		if (ptr) *ptr = '\0';
		else
			while (getchar() != '\n') continue;		// ��������� ��� �������������� ������� ������� ������
	}
	return ret_val;
}
/*
12. ������������ �������, ������� ��������� ��������� �� ������ � �������� ���������
� ���������� ��������� �� ������ ������ �������, ������������� �
��������� ������� ������ ������ ��� ����� ���. ������� ������ ����������
������� ���������, ���� ������� �� �������.
*/
char* findspb(char* str);
int quest12(void) {
	char* test1 = "aaa sss";
	char* test2 = "ddddddddddd";
	char* ptr;
	printf("\n\033[1;4;44mB������ ��� ������������. 12. �������� ������� ������ ������� �������.\033[0m\n");
	ptr = findspb(test1);
	if(ptr)printf("������ ������:----%s\n", ptr);
	ptr = findspb(test2);
	if(!ptr)printf("�� ������ ������:----%s\n", ptr);

}
char* findspb(const char* str) {
	while (*str) {
		if (*str++ == ' ') return --str;
	}
	return NULL;
}
/*
13. ���������� ��������� �� �������� 11.21, ��������� ������� �� ctype.h ���
����, ����� ��������� ������������ ���������� ����� ���������� �� ����������
������������� ��������� ��� �������� ����.
*/
int compare13(void);
int quest13(void) {
	printf("\n\033[1;4;44mB������ ��� ������������. 13. ���������� ������� 11.21 ��� ��������� � ������� ����.\033[0m\n");
	return compare13();
}

// ������� 11.21. ��������� compare. �
/* compare.c -- ��� ��������� ����� �������� */
#include <stdio.h>
#include <string.h> // ���������� strcmp()
#define ANSWER "�����"
#define SIZE 40
char* s_gets(char* st, int n);
char* toUpperStr(char* str);
int compare13(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44m������� 11.21.��������� compare.c -- ��� ��������� ����� ��������\033[0m\n");
	puts("��� ��������� � ������ ������?");
	s_gets(try, SIZE);
	toUpperStr(try);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("�����������! ����������� ��� ���.");
		s_gets(try, SIZE);
	}
	puts("Tene�� ���������!");
	return 0;
}
char* toUpperStr(char* str) {
	int d1 = '�' - '�';
	char ch;
	char* ptr=str;
	while (ch=*str) {
		if (ch >= '�' && ch <= '�') *str = (ch - d1);
		str++;
	}
	return ptr;
}