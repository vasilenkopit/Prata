// ��������� - ������� ������������� ������������ ������� �� cppreference.com
#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
#define FILENAME "glava8.txt"		// ��� ����� ��� ��������. ���� � �������� �������
//
#include <stdio.h>
#include <stdlib.h>
extern "C" {
	int cppreference(void)
	{
		int i;
		int c; // note: int, not char, required to handle EOF
		int is_ok = EXIT_FAILURE;
		//const char* fname = "F:/�����/C/Pratta/x64/Debug/glava8.txt"; // or tmpnam(NULL);
		const char* fname = "glava8.txt"; // or tmpnam(NULL);
		FILE* fp;
		printf("\n\033[1;4;44m������� 8.3.���������  cppreference.c -- ������ ���� tmp/glava8.txt ��������� Hello, world! � ���������� ��� ���������� � ������� ����.\033[0m\n");
		printf("\n\033[1;4;44m�� ��������� ���� �������� � �������� �������.\033[0m\n");
		fopen_s(&fp, fname, "a+");
		if (!fp) {
			perror("File opening failed");
			return is_ok;
		}
		printf("���������� ����� ��:\n");
		printf("___________________________________________________________\n");
		while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
			putchar(c);
		}
		printf("___________________________________________________________\n");
		fputs("___________________________________________________________\n", fp);
		for (i = 1; i < 11; i++)fputs("{i}\tHello, world!\n", fp);
		fputs("___________________________________________________________\n", fp);
		rewind(fp);
		printf("���������� ����� �����:\n");
		printf("___________________________________________________________\n");
		while ((c = fgetc(fp)) != EOF) { // standard C I/O file reading loop
			putchar(c);
		}
		printf("___________________________________________________________\n");
		if (ferror(fp)) {
			puts("I/O error when reading");
		}
		else if (feof(fp)) {
			puts("End of file reached successfully");
			is_ok = EXIT_SUCCESS;
		}
		fclose(fp);
		//remove(fname);
		return is_ok;
	}
	// Example: How fseek() function works?
#include <cstdio>
int cppreferenceFseek()
{
	printf("\n\033[1;4;44m.���������  cppreferenceFseek.c -- ������ fseek.\033[0m\n");
	printf("\033[1;4;44m.������ example.txt, ����� \"Erica 25 Berlin\", ������ � �������.\033[0m\n");
	FILE* fp;
	fopen_s(&fp, "example.txt", "w+");
	char ch;
	fputs("Erica 25 Berlin", fp);
	rewind(fp);
	printf("Name: ");
	while ((ch = fgetc(fp)) != ' ')
		putchar(ch);
	putchar('\n');
	printf("Age: ");
	fseek(fp, 6, SEEK_SET);
	while ((ch = fgetc(fp)) != ' ' && !feof(fp))
		putchar(ch);
	putchar('\n');
	printf("City: ");
	fseek(fp, 9, SEEK_SET);
	while ((ch = fgetc(fp)) != EOF)
		putchar(ch);
	putchar('\n');
	fclose(fp);
	return 0;
}
// Example: How getc() function works
#include <cstdio>
int getcExample()
{
	int c,nlines=0,nsymbols=0;
	FILE* fp;
	const char* fname = "glava8.txt";
	printf("\n\033[1;4;44m.���������  getcExample.c -- How getc() function works.\033[0m\n");
	printf("\033[1;4;44m.������ example.txt, ����� \"Erica 25 Berlin\", ������ � �������.\033[0m\n");
	fopen_s(&fp, fname, "r");
	if (fp)
	{
		while (feof(fp) == 0)
		{
			c = getc(fp);
			putchar(c);
			nsymbols++;
			if (c == '\n') nlines++;
		}
	}
	else
		perror("File opening failed");
	printf("��������� �����: %d \t��������: %d.\n", nlines, nsymbols);
	fclose(fp);
	return 0;
}
// Example: How ungetc() function works?
#include <cstdio>
#include <cctype>
//#include <iostream>
using namespace std;
int ungetcCppreference()
{
	int c,status;
	long value = 0;
	char str[] = "101axc";
	char fileName[30] = FILENAME;
	FILE* fp;
	printf("\n\033[1;4;44m.���������  ungetcCppreference.c -- How ungetc() function works?\033[0m\n");
	printf("\033[1;4;44m.������ %s ��������� � ������ \"101axc\", ������ ����� � �������.\033[0m\n", fileName);
	fopen_s(&fp, fileName, "r+");
	if (fp)
	{
		fputs(str, fp);
		rewind(fp);
		while (1)
		{
			c = fgetc(fp);
			if (isdigit(c))
				value = value * 10 + c - '0';
			else
				break;
		}
		status=ungetc('+', fp);//ungetc(c, fp);
		printf("Value = %d\n", value);
		//cout << "Value = " << value << endl;
		fclose(fp);
		}
	else
		perror("File opening failed");
	return 0;
}
// demonstrates the original purpose of ungetc: implementation of scanf
#include <ctype.h>
#include <stdio.h>
void demo_scanf(const char* fmt, FILE* s)
{
	unsigned int num = 0;
	while (*fmt != '\0') {
		if (*fmt == '%') {
			int c;
			switch (*++fmt) {
			case 'u':
				while (isspace(c = getc(s))) {}
				num = 0;
				while (isdigit(c)) {
					num = num * 10 + c - '0';
					c = getc(s);
				}
				printf("%%u scanned %u\n", num);
				ungetc(c, s);
				break;
			case 'c':
				c = getc(s);
				printf("%%c scanned '%c'\n", c);
				break;
			}
		}
		else {
			++fmt;
		}
	}
}

int ungetcCall(void)
{
	FILE* f;
	char fileName[30] = FILENAME;
	printf("\n\033[1;4;44m.���������  ungetcCall.c -- How ungetc() function works?\033[0m\n");
	printf("\033[1;4;44m.����� � %s \"123x\", ������ ����� � �������.\033[0m\n", fileName);
	fopen_s(&f, fileName, "w+");
	if (f != NULL) {
		fputs("123x", f);
		rewind(f);
		demo_scanf("%u%c", f);
		fclose(f);
	}
	return 0;
}
// Example: How vfscanf() function works?
#include <cstdio>
#include <cstdarg>

void read(FILE* fp, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	vfscanf(fp, format, args);
	va_end(args);
}

int vfscanfCall()
{
	char fileName[30] = FILENAME;
	char myFriends[6][20] = { "����", "Robert", "Syd", "Brian", "Eddie", "Ray" };
	char name[20];
	FILE* fp;
	printf("\n\033[1;4;44m.���������  vfscanfCall.c -- How vfscanf() function works?\033[0m\n");
	printf("\033[1;4;44m.����� � %s �����, ������ � �������.\033[0m\n", fileName);
	fopen_s(&fp, fileName, "w+");
	if(fp) {
		for (int i = 0; i < 6; i++)
			fprintf(fp, "%s ", myFriends[i]);
		rewind(fp);
		printf("Here are the list of my friends\n");
		for (int i = 0; i < 5; i++)
		{
			read(fp, "%s ", &name);
			printf("%s\n", name);
		}
		fclose(fp);
	}
	else
	{
		printf("���� %s. ", fileName);
		perror("File opening failed");
	}
	return 0;
}
// #include <iostream>
#include <cstdio>
//#include <cstdlib>

using namespace std;

int tmpfileCall()
{
	FILE* fp;
	char writeToFile[50] = "Creating a temporary file";
	char readFromFile[50];
	printf("\n\033[1;4;44m.���������  tmpfileCall.c -- �����1� ��������� ��� ����� � ��������� ���\033[0m\n");
	printf("\033[1;4;44m.����� � ���� � ������ � �������.\033[0m\n");
	tmpfile_s(&fp);
	if (fp == NULL)
	{
		perror("Error creating temporary file");
		exit(1);
	}
	fputs(writeToFile, fp);
	rewind(fp);
	fgets(readFromFile, sizeof(readFromFile), fp);
	//cout << readFromFile;
	printf("������� �� ���������� �����:\n%s\n", readFromFile);
	fclose(fp);
	return 0;
}
}		// extern "C" 