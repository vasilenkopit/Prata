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
			printf("\033[31m������!\033[0m �����(y/n �/�):");
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
		count13_1(args > 1 ? argv[1] : "");
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
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
	char buf[MAX_BUF], name[MAX_NAME], * pname;
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
/*
2. �������� ��������� ����������� ������, ������� �������� ��� ���������
����� � ��� ����� �� ��������� ������. ����������� ����������� ����-�����
� �������� �����, ���� ��� ��������.
*/
int copyFile(char* filenameSource, char* filenameTarget);
int Exsample2(int args, char* argv[])
{
	int i, beg, end;
	char ch, ** pname;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 2. ����������� ������, ������� �������� ��� ��������� ����� � ��� ����� �� ��������� ������.\033[0m\n");
	do
	{
		//printf("�������")
		if (args == 3) {
			copyFile(argv[1], argv[2]);
		}
		else {
			printf("\033[31m������!\033[0m � ��������� ������ ������� ��������� ����� ��� �����: �������� �����.\n");
			printf("���������(%d ����) ��������� ������: ", args);
			for (int i = 0; i < args; i++)
				printf("%s(%d),", argv[i], i);
			printf("\n");
		}
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
bool checkOpen(FILE** pf, char* nameF, char* opt);
int copyFile(char* filenameSource, char* filenameTarget) {
	FILE* pfs, * pft;
	char* buf;
	int num, lSize;
	printf("�������� ����������� ����� \033[32m%s\033[0m � ���� \033[32m%s\033[0m.\n", filenameSource, filenameTarget);
	if (checkOpen(&pfs, filenameSource, "rb") && checkOpen(&pft, filenameTarget, "wb")) {
		// obtain file size:
		fseek(pfs, 0, SEEK_END);
		lSize = ftell(pfs);
		rewind(pfs);
		// allocate memory to contain the whole file:
		buf = (char*)malloc(sizeof(char) * lSize);
		fread(buf, sizeof(char), lSize, pfs);
		fwrite(buf, sizeof(char), lSize, pft);
		fclose(pfs);
		fclose(pft);
		free(buf);
	}
}
bool checkOpen(FILE** pf, char* nameF, char* opt) {
	int err;
	char buf[100];
	bool ret = false;
	if ((err = fopen_s(pf, nameF, opt)) > 0)
	{
		strerror_s(buf, 99, err);
		printf("�� ������� ������� ���� \033[32m%s\033[0m ��� ������ \033[32m%s\033[0m. ������=%d(%s)\n", nameF, opt, err, buf);
	}
	else ret = true;
	return ret;
}
/*
3. �������� ��������� ����������� ������, ������� ���������� ������������
������ ��� ���������� �����, ������������ � ���� ���������, � ��� ���������
�����. ��������� ������ ������������ ������� toupper() �� ctype.h
��� �������� ������ � ������� ������� �� ����� ��� ������ � �������� ����.
���������� ����������� ����-����� � ��������� �����.
*/
#define MAX_FILE 100
int Exsample3(void)
{
	int i, beg, end;
	char ch;
	char* fName1[MAX_FILE], fName2[MAX_FILE];
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 3. ����������� ������, ����� ������ ������������� � �������.\033[0m\n");
	do
	{
		printf("������� ��� ��������� ����� � ��� ��������������� ����� ����� ������:"INPUT3);
		scanf_s("%s %s", fName1, MAX_FILE - 1, fName2, MAX_FILE - 1);
		getchar();
		copyFile(fName1, fName2);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
/*
4. �������� ���������, ������� ��������������� ���������� �� ������ ����������
���� ������, ������������� � ��������� ������. ��� ���������� ������
����������� argc.
*/
void printFile(char* name);
int Exsample4(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 4. ���������� �� ������ ���������� ���� ������, ������������� � ��������� ������.\033[0m\n");
	do
	{
		for (int i = 1; i < args; i++)
			printFile(argv[i]);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
void printFile(char* name) {
	FILE* fp;
	char ch;
	if ((fopen_s(&fp, name, "r")) != 0) exit(EXIT_FAILURE);
	printf("\n-----------------���������� ����� \033[32m%s\033[0m\n", name);
	while (fscanf_s(fp, "%c", &ch, 1) == 1) {
		printf("%c", ch);
	}
	fclose(fp);
}
/*
5. ������������� ��������� � �������� 13.6, ����� ������ �������������� ����������
��� ������������ ��������� ��������� ������.
*/
int randbin5(char* name);
int Exsample5(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 5. ������������� ��������� 13.6, ����� ��� ������������ ��������� ������.\033[0m\n");
	do
	{
		randbin5(argv[1]);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
// ������� 13.6. ��������� randbin.c
/* randbin.c � ������������ ������, �������� ����-����� */
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000
int randbin5(char* name)
{
	double numbers[ARSIZE];
	double value;
	const char* file = "numbers.dat";
	int i;
	long pos;
	FILE* iofile;
	printf("\n\033[1;4;44m������� 13.6.��������� randbin.c � ������������ ������, �������� ����-�����.\033[0m\n");
	printf("\n\033[1;4;44m���������� � ���� %s ����� � ������ ��.\033[0m\n", name);
	// �������� ������ �������� double
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// ������� ������� ����
	if ((fopen_s(&iofile, file, "wb")) != 0)
	{
		fprintf(stderr, "�� ������� ������� ���� %s ��� ������.\n", file);
		exit(EXIT_FAILURE);
	}
	// ������ � ���� ������� � �������� �������
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((fopen_s(&iofile, file, "rb")) != 0)
	{
		fprintf(stderr, "�� ������� ������� ���� %s ��� ������������� �������.\n", file);
		exit(EXIT_FAILURE);
	}
	// ������ ��������� ��������� �� �����
	printf("������� ������ � ��������� 0-%d.\n", ARSIZE - 1);
	while (scanf_s("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double); // ���������� ��������
		fseek(iofile, pos, SEEK_SET); // ������� � ������ �������
		fread(&value, sizeof(double), 1, iofile);
		printf("�� ����� ������� ��������� �������� %f.\n", value);
		printf("������� ��������� ������ (��� �������� �� ��������� ��������� ��� ����������):\n");
	}
	// ����������
	fclose(iofile);
	puts("��������� ���������.");
	return 0;
}
/*
6. ���������, ���������� � ����������� ��������� ������, ���������� �� ��,
��� ������������ ������, ��� �� ��������� ���������. ���������� ���������
�� �������� 13.2 ���, ����� ������ ������������� ���������� ��������� ��������
��� ���������� ������������ ������ ����������� ����������.
*/
int reducto6(char* name);
int Exsample6(void)
{
	int i, beg, end;
	char ch;
	char name[MAX_NAME];
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 6. ���������� ��������� 13.2. ��� ����� ��������� � �������.\033[0m\n");
	do
	{
		printf("������� ��� ����� ��� ����������:"INPUT3);
		scanf_s("%s", name, MAX_NAME - 1);
		getchar();
		reducto6(name);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("������! �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
// ������� 13.2. ��������� reducto.c
// reducto.c -- ���������� ������ �� ��� �����!
#include <stdio.h>
#include <stdlib.h> // ��� exit ()
#include <string.h>
#define LEN 100
int reducto6(char* name)
{
	FILE* in, * out; // ���������� ���� ���������� �� FILE
	int ch, err, l;
	char* nameOut[LEN], * pch; // ��������� ��� ����� ��������� �����
	int count = 0;
	printf("\n\033[1;4;44m������� 13.2.��������� reducto.c -- ���������� ������ �� ��� �����!\033[0m\n");
	// ��������� �����
	if ((err = fopen_s(&in, name, "r")) != 0) {
		fprintf(stderr, "�� ������� ������� ���� \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}
	// ��������� ������
	l = strrchr(name, '.') - name;
	strncpy_s(nameOut, LEN - 1, name, l); // ����������� ����� �����
	//name[LEN - 5] = '\0';
	strcat_s(nameOut, LEN - 1, ".red"); // ���������� . red
	if ((err = fopen_s(&out, nameOut, "w")) != 0) { // �������� ����� ��� ������
		fprintf(stderr, "�� ������� ������� �������� ����.\n");
		exit(3);
	}
	// ����������� ������
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out); // �������� ������ ������ ������
	// �������
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "������ ��� �������� ������.\n");
	return 0;
}
/*
7. �������� ���������, ������� ��������� ��� �����. �������� ����� ������
����� ���� ����� ��������� ������, ���� ��������� ������������ ������ ��.
�. �������� ���, ����� ��� ��������� �������� ������ 1 ������� �����, ������ 1
	������� �����, ������ 2 ������� �����, ������ 2 ������� ����� � �.�., ���� ��
	����� �������� ��������� ������ ����� �������� (�� ���������� �����) �����.
�. ������������� ��������� ���, ����� ������ � ����� � ��� �� ������� �� ��������
	� ����� �������� ������.
*/
void file2Print(char* name1, char* name2);
int Exsample7(int args, char* argv[])
{
	int i, beg, end, status;
	char ch;
	char name1[MAX_NAME], name2[MAX_NAME];
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 7. ������������ ����� ����������� ���� ������.\n"
		"           ���� ����� �� ������ � ��������� ������ ��� �������������.\033[0m\n");
	do
	{
		if (args < 3) {
			printf("������� ��� ����� ��������� ������(����� ������):"INPUT3);
			do {
				status = scanf_s("%s %s", name1, MAX_NAME - 1, name2, MAX_NAME - 1);
				if (status != 2) printf("\033[31m������!\033[0m ����� ������ ��� ����� ������ ����� ������.\n");
			} while (status != 2);
			getchar();
		}
		else {
			strncpy_s(name1, MAX_NAME, argv[1], strlen(argv[1]));
			strncpy_s(name2, MAX_NAME, argv[2], strlen(argv[2]));
		}
		file2Print(name1, name2);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("\033[31m������!\033[0m �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
#define LINE_LN 100 // ����� ������ ��� ������
bool buildStr(FILE* fp1, FILE* fp2, char* buf, int n);
void file2Print(char* name1, char* name2) {
	int i;
	FILE* fp1, * fp2;
	char ch1, ch2, buf[LINE_LN + 1], filTitle[20] = { "" };
	bool endf = false;
	if (!checkOpen(&fp1, name1, "r")) return;
	if (!checkOpen(&fp2, name2, "r")) return;
	i = max(0, 20 - strlen(name1) - 1);
	for (int j = 0; j < i; j++) filTitle[j] = '-';
	filTitle[i] = '\0';
	printf("\n-------------���������� ����� \033[32m%s\033[0m%s|----------------���������� ����� \033[32m%s\033[0m-------------\n", name1, filTitle, name2);
	printf("1........2.........3.........4.........5.........|1.........2.........3.........4.........5.........\n");
	do {
		endf = buildStr(fp1, fp2, buf, LINE_LN - 1);
		printf("%s\n", buf);
	} while (!endf);
	//while (fscanf_s(fp, "%c", &ch1, 1) == 1) {
	//	printf("%c", ch);
	//}
	fclose(fp1);
	fclose(fp2);
}
bool buildStr(FILE* fp1, FILE* fp2, char* buf, int n) {
	int i = 0, l = (n - 1) / 2;
	char ch = '\0';
	if (!feof(fp1)) {
		while (fscanf_s(fp1, "%c", &ch, 1) != EOF && ch != '\n' && i < l)
			buf[i++] = ch;
	}
	for (; i < l;) buf[i++] = ' ';
	if (ch == '\n') buf[i++] = '|'; else buf[i++] = '*';
	if (!feof(fp2)) {
		while (fscanf_s(fp2, "%c", &ch, 1) != EOF && ch != '\n' && i < n)
			buf[i++] = ch;
	}
	if (ch != '\n') {
		for (; i < n - 1;) buf[i++] = ' ';
		buf[i++] = '*';
	}
	buf[i] = '\0';
	return feof(fp1) && feof(fp2);
}
/*
8. �������� ���������, ������� ��������� � �������� ���������� ���������
������ ������ � ���� ��� ����� ���� ������. ���� �� �������� �� ������� ���������,
��������� ������ ������ ����������� ����. � ��������� ������ ���
������ ��������� ������ ���� �� ������� � ��������, ������� ��� � ��� �����������
��������� ������. ������ � ����������� ������� �������� ������ ����
������� ��� ����� � ��� ������. ������������� �������� �������� ������,
����������� �������� ������������ ���������� ���������� � ����������� ��������
������. ���� ���� �� ����� ���� ������, ��������� ������ ��������
�� ���� ����� � ���������� � ��������� ���������� �����.
*/
#define MAX_NAME 10
#define MAX_LNAME 20
#define MAX_STR 100 // ����� ������ ��� ������ �����
static char staticnames[MAX_NAME][MAX_LNAME + 1];
char getSymbol(char str);
int getwords(int n, int len);
bool getword(int n, int len);
void OutTable(char ch, int n);
int countSymb(char ch, char* name);
int Exsample8(int args, char* argv[])
{
	int i, beg, end, n = 0;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 8. ������� ����������� ��������� ������� � �����.\033[0m");
	printf("\n\033[1;4;44m           ������ � ����� ����� ������ � ��������� ������ ��� � �������.\033[0m\n");
	do
	{
		switch (args) {
		case 1:
			printf("������� ������ � ����� ������ ��� ������(����� ������):\n");
			ch = getche();
			i = n = 0;
			n = getwords(MAX_NAME, MAX_LNAME);
			break;
		case 2:
			ch = argv[1][0];
			printf("������� ����� ������ ��� ������(����� ������):\n");
			i = n = 0;
			n = getwords(MAX_NAME, MAX_LNAME);
			break;
		default:
			ch = argv[1][0];
			n = 0;
			for (i = 2; i < args && i < MAX_NAME; i++, n++)
				strcpy_s(staticnames[i - 2], MAX_LNAME, argv[i]);
		}
		OutTable(ch, n);
		printf("\n��� �����?(y/n ��� �/�):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
			printf("\033[31m������!\033[0m �����(y/n �/�):");
			ch = getchar();
			getchar();      // ������� '\n'
		}
	} while (ch == 'y' || ch == '�' || ch == '\n');
	printf("\n����� ���������\n");
	return 0;
}
char getSymbol(char str) {
	char ch;
	printf("%s:"INPUT3, str);
	scanf_s("%c", &ch, 1);
	return ch;
}
bool getword(int n, int len) {
	// ��������� ����� - �������(�� ������ len) �� ������� � word, ��������� ����� '\0'
	// ���������� true, ���� ��������� ����� ������. ����� word>len
	char ch;
	int i = 0;
	bool start = true;
	while ((ch = getche()) != '\n' && ch && ch != '\r') {
		if (ch == ' ' && start) continue;
		if (ch == ' ' && !start) break;
		staticnames[n][i++] = ch;
		if (i >= len) break;
		start = false;
	}
	staticnames[n][i] = '\0';
	return ch == '\n' || ch == '\r';
}
int getwords(int n, int len) {
	// ��������� <=n ����, �� ������� len
	// ���������� ����� ��������� ����
	int nwords = 0;
	while (!getword(nwords++, len) && nwords < n);
	return nwords;
}
void OutTable(char ch, int n) {
	char name[MAX_LNAME + 1];
	int count;
	printf("������� �c����������� ������� \033[32;1;4m%c\033[0m � ������.\n", ch);
	printf("���� \t\t�����\n");
	for (int i = 0; i < n; i++) {
		strncpy_s(name, MAX_LNAME, staticnames[i], MAX_LNAME);
		count = countSymb(ch, name);
		if (count >= 0)printf("%s \t\t%d\n", name, count);
	}

}
int countSymb(char ch, char* name) {
	FILE* fp;
	char* p0, * p1, str[MAX_STR + 1];
	int n = 0;
	if ((fopen_s(&fp, name, "r")) == 0) {
		while (fscanf_s(fp, "%s", str, MAX_STR) == 1) {
			p0 = str;
			while (p1 = strchr(p0, ch)) {
				n++;
				p0 = ++p1;
			}
		}
		fclose(fp);
	}
	else
	{
		printf("\033[31m������!\033[0m �� ����������� ���� %s.\n", name);
		n = -1;
	}
	return n;
}
/*
9. ������������� ��������� � �������� 13.3, ����� ������ ����� ���� �������������
� ������������ � �������� ��� ���������� � ������, ������� � 1.
������������ � ���, ����� ��� ������ ������� ��������� ����� ���������
���� ���������� � ���� �����, ��� ���� ��������� ��������� ��� ���������� �������.
*/
int addaword13_3(void);
bool getYes(char* quest);
int Exsample9(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 9. ����������� ��������� 13.3.\033[0m\n");
	do{
		addaword13_3();
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
// ������� 1�.�. ��������� addaword. �
/* addaword.c -- ������������� fprintf(), fscanf() � rewind () */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
int countNwords(FILE* pf);
int addaword13_3(void)
{
	FILE* fp;
	char words[MAX], name[MAX];
	errno_t status;
	int nwords,i;
	printf("\n\033[1;4;44m������� 13.3.��������� addaword.c -- ������������� fprintf(), fscanf() � rewind().\033[0m\n");
	printf("������� ��� ����� � ����������� �������� �������� �����:"INPUT3);
	gets_s(name, MAX - 1);
	if ((fopen_s(&fp, name, "r")) != 0){
		fprintf(stdout, "\033[31m������!\033[0m �� ������� ������� ���� \033[32m%s\033[0m.", name);
		if (getYes(" ������� ����?")) {
			status = fopen_s(&fp, name, "w");
			if (status != 0) {
				fprintf(stdout, "\033[31m������!\033[0m �� ������� ������� ���� \033[32m%s\033[0m.", name);
				return 0;
			}
		}
		else return 0;
	}
	nwords = countNwords(fp);
	freopen_s(&fp,name, "a+", fp);
	printf("\n� ����� %d ����. ������� ��� ����� ��� ����������;\n", nwords);
	puts("��� ���������� ������� ������ # � ������ ������.");
	printf(":");
	while ((fscanf_s(stdin, "%s", words, 20) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	nwords = countNwords(fp);
	printf("\n������ � ����� %d ����. ���������� �����:\n", nwords);
	rewind(fp);					/* ������� � ������ ����� */
	i = 1;
	while (fscanf_s(fp, "%s", words, 20) == 1)
		printf("%3d \t%s\n",i++,words);
	puts("������!");
	if (fclose(fp) != 0)
		fprintf(stderr, "������ ��� �������� �����\n");
	return 0;
}
bool getYes(char* quest) {
	char ch,* s, * q = "yY��nN��";
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
int countNwords(FILE* pf) {
	char* buf[MAX_BUF+1],*ps,space[]=" \t\n";
	int len,count=0,i;
	if (pf != NULL) {
		rewind(pf);
		while((len = fread(buf, sizeof(char), MAX_BUF, pf)) > 0) {
			ps=buf;
			*(ps + len) = '\0';
			while ((i = strcspn(ps, space)) > 0) {
				count++;
				ps += i+1;
				while (isspace(*ps)) ps++; // ���������� �������
			}
		}
	}
	return count;
}
/*
10. �������� ���������, ����������� ��������� ����, ��� �������� ����������
������������. ����������� ����, ������� ���������� ������������ ������ 
�������� �����. ����� ��������� ������ ������� ����� �����, ������� � ����
������� � ���������� ��������� �������� ����� ������. ���� ����� ������
����������� ��� ����� �������������� ��� ����������� ��������.
*/
void outFromIdx(FILE* pf, long idx);
int Exsample10(void)
{
	int i, beg, end;
	long idx;
	char ch, name[MAX_LNAME+1];
	FILE* pf;
	errno_t err;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 10. ������� ���������� ���������� ����� � ��������� ������� �� ����� ������.\033[0m\n");
	do
	{
		printf("������� ��� ���������� �����:"INPUT3);
		scanf_s("%s",name,MAX_LNAME);
		if ((err=fopen_s(&pf, name, "rt"))!=0) {
			printf("\033[31m������!\033[0m ���� %s �� �����������.\n",name);
		}
		else {
			do {
				printf("������� ��������(����� ��������) � �����:");
				scanf_s("%ld", &idx);
				if (idx < 0) break;
				//printf("��������=%d\n",idx);
				outFromIdx(pf, idx);
			} while (true);
		}
	} while (getYes("\n��������� ��������� ��� �����?"));
	fclose(pf);
	printf("\n����� ���������\n");
	return 0;
}
void outFromIdx(FILE* pf, long idx) {
	char buf[MAX_BUF + 1];
	rewind(pf);
	if (fseek(pf, idx, SEEK_SET) != 0) {
		printf("\033[31m������!\033[0m �������� ��������.\n");
	}
	else {
		fgets( buf, MAX_BUF,pf);
		printf("%3ld: \t%s\n", idx, buf);
	}

}
/*
11. �������� ���������, ������� ��������� ��� ��������� ��������� ������.
������ �������� - ��� ������, � ������ - ��� �����. ��������� ������ ������
� ����� � �������� ��� ������, ���������� ���������. ��������� ������
������������� �� ������, � �� �� �������, ����������� ������� fgets()
������ getc(). ��� ������ ������, ���������� ��������, ���������� �������
strstr() (������ ��������� � ���������� 7 �� ����� 11) �� ����������� ���������� �.
*/
int FindString(FILE* pf, char* str);

int Exsample11(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	FILE* pf;
	errno_t err;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 11. ����� ������ � ����� � �������� ��� ������, ���������� ���������.\033[0m\n");
	do
	{
		if (args < 3) {
			printf("\n\033[31m������!\033[0m � ��������� ������ ����� ������ ������ ������ � ��� �����.\n");
			break;
		}
		else {
			if ((err=fopen_s(&pf, argv[2], "rt")) != 0) {
				printf("\n\033[31m������!\033[0m �� ����������� ���� %s:", argv[2]);
				perror("");
				break;
			}
			else {
				printf("� ����� %s ������� %d ����� \"%s\".",argv[2], FindString(pf, argv[1]),argv[1]);
			}
		}
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
int FindString(FILE* pf, char* str) {
	char buf[MAX_BUF],* pch;
	long idx=0;
	int count=0;
	printf("��������� ������:\n");
	while (!feof(pf)) {
		if (pch = fgets(buf, MAX_BUF, pf)) {
			if(strstr(buf,str)) 
				printf("%3d: \t%s", ++count,buf);
		}
	}
	return count;
}
/*
12. �������� ��������� ����, ��������� �� 20 ����� �� 30 ����� �����. ����� ��������
������ ������� � �������� �� 0 �� 9 � ���������� ���� �� ����� ���������.
���� �������� �������� �������������� �����������, ��� ���� ��������
�� 0 �� 9 ������������� ������������ ������ �������. �������� ���������,
������� ������ ���������� ����� ����� � ������ ��������� int arr[20][30].
��� ������ ������� � �������������� ������ ��������� �������������
� ����������� ��������� ������ ������������ �������� �� ����� ������� ���
������������� ������� ��������� char � �������� 20 �� 31. ��� ���� 0 �������������
������� �������, 1 - ������� ����� � �.�.; ������� �������� ��������������
��������, ���������� ������� �������. ��������, ������ # �����
�������������� ��� ������������� �������� 9. ��������� ������ (31-�) � ������
������ ������ ���� �������, ������� � ����� ������ �� 20 �����. ���������
������ ���������� �������������� ����������� (�.�. ������� ������) � �����
��������� ��������� � ��������� �����. ��������, �����������, ��� ���������
������ �������� ���:
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
...
*/
#define RASTR_X 20
#define RASTR_Y 30
static int ar[RASTR_X][RASTR_Y];
char rastr[RASTR_X][RASTR_Y + 1] = {'\0'};
void printRastr(void);
void replExtr(char* fileName, char* extr);
void createRastr(FILE* pf, FILE* pfRastr);
void inputIn(FILE* pf);
void inputOut( FILE* pf);
int Exsample12(int args, char* argv[])
{
	int i, beg, end;
	char ch,nameIn[MAX_LNAME+1], nameOut[MAX_LNAME+1];
	FILE* pf,*pfR;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 12. ��������� �������.\033[0m\n");
	strcpy_s(nameIn, MAX_LNAME, argv[1]);
	strcpy_s(nameOut, MAX_LNAME, argv[1]);
	do
	{
		if (args < 2) {
			printf("\n\033[31m������!\033[0m ����� ������ � ��������� ������ ��� �����.\n");
		}
		else {
			if ((fopen_s(&pf, argv[1], "rt")) != 0) {
				printf("\n\033[31m������!\033[0m �� ����������� ���� %s:", argv[1]);
				perror("");
				break;
			}
			else {
				//printf("��������� ����� %s.\n", nameIn);
				replExtr(nameOut, "ras");
				if (fopen_s(&pfR, nameOut, "w")!=0) {
					printf("\n\033[31m������!\033[0m �� ������� ���� %s:", nameOut);
					perror("");
					break;
				}
				else {
					//printf("��������� ����� %s.\n", nameOut);
					createRastr(pf, pfR);
					printRastr();
				}
				fclose(pf);
			}
		}
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
void printRastr(void) {
	for (int i = 0; i < RASTR_X; i++){
		printf("%s\n", rastr[i]);
	}
}
void createRastr(FILE* pf,FILE *pfRastr) {
	//int  arr[RASTR_X][RASTR_Y+1];
	//char rastr[RASTR_X][RASTR_Y+1];
	inputIn(pf);
	inputOut(pfRastr);
	//printRastr();
}
void inputIn( FILE* pf) {
	// ������ ������ ����� ������ �� �������� �����
	char buf[MAX_BUF + 1], * ch,*chnex, * sep=" ";
	int i = 0, j = 0,k=0,d=0;
	while (fgets(buf, MAX_BUF, pf)) {
		ch = strtok_s(buf, sep,&chnex );
		j = 0;
		while (ch != NULL)
		{
			sscanf_s(ch, "%d", &d);
			ar[i][j] = d;
			//*(arr + i * RASTR_X + j) = d;
			ch = strtok_s(NULL, sep, &chnex);
			j++;
		}
		i++;
	}
}
void inputOut(FILE* pf) {
	// ������ ���������� ����� �� ������� ����� ������
	char* rsymb = " .,-+*#HDWQRSZMO";	// ������� ������
	int k;
	for (int i = 0; i < RASTR_X; i++){
		for (int j = 0; j < RASTR_Y; j++) {
			k = ar[i][j];
			rastr[i][j] = rsymb[k];
		}
	}
}
void replExtr(char* fileName, char* extr) {
	// �������� � ����� ����� fileName ���������� �� ��������� � extr
	char* s;
	s = strchr(fileName, '.');
	if (s == NULL) {
		s = fileName + strlen(fileName);
		*s++ = '.';
		*s = '\0';
	}
	else *++s = '\0';
	strcat_s(fileName,MAX_LNAME, extr);
}
/*
14. �������� �����������, �������� ������������ �� ����������� �����������
���������, ����� ��������� ������. �������� � ��������� �� ���������� 12
������� ���������� �����. ��� ������ ���������� ������ �������� � ���������
����������, �������������� ����� � ������, ����� � ������. ���� ��������
���������� ����� ��� �� 1 �� ����� �������, ��� ������ ���� �������� �������
��������� ���� �������� �������. ������� �������� ������ ���� ��������� ��
���������� ������. �������� ��������, ��� �����, ����������� �� ��������,
����� ������ ������� �������, ������� ��� ������� ����������� ���������.
*/
void interfer(void);
int Exsample14(int args, char* argv[])
{
	int i, beg, end;
	char ch, nameIn[MAX_LNAME + 1], nameOut[MAX_LNAME + 1];
	FILE* pf, * pfR;
	SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	printf("\n\033[1;4;44m������� 14. ���������� ����� � ������.\033[0m\n");
	strcpy_s(nameIn, MAX_LNAME, argv[1]);
	strcpy_s(nameOut, MAX_LNAME, argv[1]);
	do
	{
		if (args < 2) {
			printf("\n\033[31m������!\033[0m ����� ������ � ��������� ������ ��� �����.\n");
		}
		else {
			if ((fopen_s(&pf, argv[1], "rt")) != 0) {
				printf("\n\033[31m������!\033[0m �� ����������� ���� %s:", argv[1]);
				perror("");
				break;
			}
			else {
				//printf("��������� ����� %s.\n", nameIn);
				replExtr(nameOut, "ras");
				if (fopen_s(&pfR, nameOut, "w") != 0) {
					printf("\n\033[31m������!\033[0m �� ������� ���� %s:", nameOut);
					perror("");
					break;
				}
				else {
					//printf("��������� ����� %s.\n", nameOut);
					inputIn(pf);
					interfer();
					inputOut(pfR);
					printRastr();
				}
				fclose(pf);
				fclose(pfR);
			}
		}
	} while (getYes("\n��������� ��������� ��� �����?"));
	printf("\n����� ���������\n");
	return 0;
}
void interfer(void) {
	// ���������� �������� � ar[RASTR_X][RASTR_Y];
	int v,vl,vr,vh,vu;
	for (int i = 0; i < RASTR_X; i++) {
		for (int j = 0; j < RASTR_Y; j++)
		{
			v = ar[i][j];
			vl = (i==0)?v:ar[i - 1][j];
			vr = (i==RASTR_X-1)? v : ar[i + 1][j];
			vh = (j == 0) ? v : ar[i][j-1];
			vu = (j==RASTR_Y - 1) ? v : ar[i][j+1];
			if (abs(v - vl) > 1 ||
				abs(v - vr) > 1 ||
				abs(v - vh) > 1 ||
				abs(v - vu) > 1
				) {
				v = (v + vl + vr + vh + vu) / 5;
				ar[i][j]=v;
			}
		}
	}
}
