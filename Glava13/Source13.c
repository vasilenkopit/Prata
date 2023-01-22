#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
// ������� 13.1. ��������� count. �
/* count.c � ������������� ������������ �����-������ */
#include <stdlib.h> // �������� exit()
#include <string.h>
#include <errno.h>
char* strerror(int errnum);
int count(int argc, char* argv[])
{
	int ch; // ����� ��� �������� ������� ������� �� ���� ������
	char buf[100];
	FILE* fp; // "��������� �����"
	unsigned long count = 0;
	int err;
	printf("\n\033[1;4;44m������� 13.1.��������� count.c � ������������� ������������ �����-������.\033[0m\n");
	if (argc != 2)
	{
		printf("�������������: %s ���_�����\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((err=fopen_s(&fp,argv[1], "r")) >0)
	{
		strerror_s(buf,99,err);
		printf("�� ������� ������� ���� %s. ������=%d(%s)\n", argv[1], err, buf);
		exit(EXIT_FAILURE);
	}
	printf("���������� ����� %s:\n", argv[1]);
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout); // �� ��, ��� � putchar (ch) ;
		count++;
	}
	printf("���� %s �������� %lu ��������\n", argv[1], count);
	if ((err = fclose(fp))) {
		strerror_s(buf, 99, err);
		printf("������ %d(%s) ��� �������� ����� %s.\n", err,buf, argv[1]);
	}
	return 0;
}
// ������� 13.2. ��������� reducto.c
// reducto.c -- ���������� ������ �� ��� �����!
#include <stdio.h>
#include <stdlib.h> // ��� exit ()
#include <string.h>
#define LEN 100
int reducto(int argc, char* argv[])
{
	FILE* in, *out; // ���������� ���� ���������� �� FILE
	int ch,err,l;
char name[LEN],*pch; // ��������� ��� ����� ��������� �����
int count =0;
printf("\n\033[1;4;44m������� 13.2.��������� reducto.c -- ���������� ������ �� ��� �����!\033[0m\n");
// �������� ���������� ��������� ������
if (argc < 2) {
	fprintf(stderr, "�������������: %s ���_�����\n", argv[0]);
	exit(EXIT_FAILURE);
}
// ��������� �����
if ((err = fopen_s(&in,argv[1], "r")) != 0) {
	fprintf(stderr, "�� ������� ������� ���� \"%s\"\n",	argv[1]);
	exit(EXIT_FAILURE);
}
	// ��������� ������
	 l=strrchr(argv[1], '.')- argv[1];
	strncpy_s(name,LEN-1, argv[1], l); // ����������� ����� �����
	//name[LEN - 5] = '\0';
	strcat_s( name,LEN-1, ".red"); // ���������� . red
	if ((err = fopen_s(&out,name, "w")) != 0) { // �������� ����� ��� ������
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
// ������� 1�.�. ��������� addaword. �
/* addaword.c -- ������������� fprintf(), fscanf() � rewind () */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
int addaword(void)
{
	FILE* fp;
	char words[MAX],name[MAX];
	printf("\n\033[1;4;44m������� 13.3.��������� addaword.c -- ������������� fprintf(), fscanf() � rewind().\033[0m\n");
	printf("������� ��� ����� � ����������� �������� �������� �����:");
	gets_s(name, MAX - 1);
	if ((fopen_s(&fp,name, "a+")) != 0)
	{
		fprintf(stdout, "�� ������� ������� ���� %s.\n",name) ;
		exit(EXIT_FAILURE);
	}
	puts("������� ����� ��� ���������� � ����; ��� ����������");
	puts("������� ������ # � ������ ������.");
	while ((fscanf_s(stdin, "%s", words,20) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	puts("���������� ����� ��� ������ fputs:");
	rewind(fp);					/* ������� � ������ ����� */
	while (fscanf_s(fp, "%s", words,20) == 1)
		fputs(words,stdout);
	puts("\n���������� �����  ��� ������ puts:\n");
	rewind(fp);					/* ������� � ������ ����� */
	while (fscanf_s(fp, "%s", words, 20) == 1)
		puts(words);
	puts("������!");
	if (fclose(fp) != 0)
		fprintf(stderr, "������ ��� �������� �����\n");
	return 0;
}
// ������� 13.4. ��������� reverse.c
/* reverse.c -- ����������� ����������� ����� � �������� ������� */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' /* ������ ����� ����� � ��������� ������ DOS */
#define SLEN 81
int reverse(void)
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count, last;
	printf("\n\033[1;4;44m������� 13.4.��������� reverse.c -- ����������� ����������� ����� � �������� �������.\033[0m\n");
	puts("������� ��� ����� ��� ���������:");
	scanf_s("%s", file,SLEN-1);
	if ((fopen_s(&fp,file, "rb")) != 0)		/* ����� ������ ��� ������ */
	{ 
		printf("reverse �� ������� ������� %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);				/* ������� � ����� ����� */
	last = ftell(fp);
	for (count = 1L; count <= last; count++)
	{
		fseek(fp, -count, SEEK_END);		/* ��������� � �������� ����������� */
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r')		/* ����� MS-DOS */
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}
// ������� 13.5. ��������� append.c
/* append.c -- ���������� ����������� ������ � ���� ���������� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE* source, FILE* dest);
char* s_gets(char* st, int n);
int appendmain(void)
{
	FILE* fa, * fs;				// fa ��� ����� ����������, fs ��� ��������� �����
	int files = 0;				// ���������� ����������� ������
	char file_app[SLEN];		// ��� ����� ����������
	char file_src[SLEN];		// ��� ��������� �����
	int ch;
	printf("\n\033[1;4;44m������� 13.5.��������� append.c -- ���������� ����������� ������ � ���� ����������.\033[0m\n");
	puts("������� ��� ����� ����������:");
	s_gets(file_app, SLEN);
	if ((fopen_s(&fa,file_app, "a+")) != 0)
	{
		fprintf(stderr, "�� ������� ������� %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("�� ������� ������� �������� �����.\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("������� ��� ������� ��������� ����� (��� ������ ������ ��� ����������):"INPUT3);
	while (s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if (strcmp(file_src, file_app) == 0)
			fputs("�������� ���� � ����� ������ ���� �����������", stderr);
		else if ((fopen_s(&fs,file_src, "r")) != 0)
			fprintf(stderr, "�� ������� ������� %s\n", file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("�� ������� ������� ������� �����\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "������ ��� ������ ����� %s.\n", file_src);
			if (ferror(fa) != 0)
				fprintf(stderr, "������ ��� ������ ����� %s.\n", file_app);
				fclose(fs);
			files++;
			printf("���������� ����� %s ���������.\n", file_src);
			puts("������� ��� ���������� ����� (��� ������ ������ ��� ����������):");
		}
	}
	printf("���������� ���������. ���������� ����������� ������: %d.\n", files);
	rewind(fa);
	printf("Co�ep���oe %s:\n", file_app);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("����������� ���������.");
	fclose(fa);
	return 0;
}
void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; // �������� ������ ���� ���
	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}
char* s_gets(char* st, int n){
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}
// ������� 13.6. ��������� randbin.c
/* randbin.c � ������������ ������, �������� ����-����� */
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000
int randbin()
{
	double numbers[ARSIZE];
	double value;
	const char * file = "numbers.dat";
	int i;
	long pos;
	FILE* iofile;
	printf("\n\033[1;4;44m������� 13.6.��������� randbin.c � ������������ ������, �������� ����-�����.\033[0m\n");
	// �������� ������ �������� double
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// ������� ������� ����
	if ((fopen_s(&iofile,file, "wb")) != 0)
	{
		fprintf(stderr, "�� ������� ������� ���� %s ��� ������.\n", file);
		exit(EXIT_FAILURE);
	}
	// ������ � ���� ������� � �������� �������
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((fopen_s(&iofile,file, "rb")) != 0)
	{
		fprintf(stderr,"�� ������� ������� ���� %s ��� ������������� �������.\n", file);
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
/* 2. ��� ������ ��������� ��������� ? (������������, ��� ��� ����������� � �����
��������� ������.)
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int quest2(int argc, char* argv[])
{
	int ch;
	FILE* fp;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if ((fopen_s(&fp,argv[1], "rb")) != 0)
		exit(EXIT_FAILURE);
	while ((ch = getc(fp)) != EOF)
		if(isdigit(ch))
			putchar(ch);
	fclose(fp);
	printf("\n");
	return 0;
}
/*
4. �������� ���������, ������� ��������� ���� ��� ���� �������� ���������
������. ���� ������� ���� ��������, �� ���������������� ��� ��� �����.
���� �������� �� ������, �� ������ �������������� ����������� ���� (stdin).
������������, ��� ���� ������� ������� �� ����� � ��������� �������.
��������� ������ ��������� � ���������� ������� �������������� ��������
��� ��������� �����.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM 1000
int quest4(int argc, char* argv[])
{
	char ch,name[21];
	int num=0,status;
	FILE* fp;
	float value,vals[NUM];
	long float summ=0.;
	if (argc < 2) {
		printf("������� ����� ����.��� ��� ���������� ������-�����:");
		while ((status=scanf_s("%f", &value))==1) { 
			vals[num++]=value; 
			summ += value;
		}
		getchar();
		printf("�������� �������� ����� � ����(y/n):");
		scanf_s("%c",&ch,1);
		getchar();
		if (ch == 'y') {
			printf("������� ��� ��������� ����� ��� ���������� ������� �����(<=20 ����):");
			scanf_s("%s", name, 20);
			if (fopen_s(&fp, name, "wb") != 0) {
				printf("������ �������� ����� %s.\n", name);
			}
			else {
				/*for (int i = 0; i<num; i++)*/ 
				fwrite(vals,sizeof(float),num,fp );
				fclose(fp);
			}
		}
	}
	else {
		if ((fopen_s(&fp, argv[1], "r")) != 0) exit(EXIT_FAILURE);
		while (fread(&value, sizeof(float), 1, fp)) {
			vals[num++] = value;
			summ += value;
		}
		fclose(fp);
	}
	printf("������� �������������� %d �����=%lf.\n",num, summ / num);
	return 0;
}
/*
5. �������� ���������, ������� ��������� ��� ��������� ��������� ������.
������ ���������� �������� ������, � ������ � ��� �����. ��������� ������
�������� �� ����� ������ �� ������, ������� �������� ��������� ������.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR 257
int quest5(int argc, char* argv[])
{
	char ch,str[MAX_STR];
	int num = 0, status;
	FILE* fp;
	long float summ = 0.;
	printf("\n\033[1;4;44m������� 13.6.��������� quest5.c � ������� ������ �����, ���������� ��������� ������.\033[0m\n");
	if (argc < 3) {
		printf("��������� � ����� �����������: \"quest5.exe c filename\" ��� � - ������, filename - ��� �����.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("\n\033[1;4;44m������� ������ ����� \"%s\", ���������� ������ \'%s\'.\033[0m\n",argv[2],argv[1]);
		if ((fopen_s(&fp, argv[2], "r")) != 0) exit(EXIT_FAILURE);
		ch = argv[1][0];
		while (fscanf_s(fp, "%s", str,MAX_STR) == 1) {
			if (strchr(str, ch)) {
				printf("%2d:%s\n",++num, str);
			}
		}
		fclose(fp);
	}
	return 0;
}
