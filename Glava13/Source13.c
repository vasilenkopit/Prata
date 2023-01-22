#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
// Листинг 13.1. Программа count. с
/* count.c — использование стандартного ввода-вывода */
#include <stdlib.h> // прототип exit()
#include <string.h>
#include <errno.h>
char* strerror(int errnum);
int count(int argc, char* argv[])
{
	int ch; // место для хранения каждого символа по мере чтения
	char buf[100];
	FILE* fp; // "указатель файла"
	unsigned long count = 0;
	int err;
	printf("\n\033[1;4;44mЛистинг 13.1.Программа count.c — использование стандартного ввода-вывода.\033[0m\n");
	if (argc != 2)
	{
		printf("Использование: %s имя_файла\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((err=fopen_s(&fp,argv[1], "r")) >0)
	{
		strerror_s(buf,99,err);
		printf("Не удается открыть файл %s. Ошибка=%d(%s)\n", argv[1], err, buf);
		exit(EXIT_FAILURE);
	}
	printf("Содержимое файла %s:\n", argv[1]);
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout); // то же, что и putchar (ch) ;
		count++;
	}
	printf("Файл %s содержит %lu символов\n", argv[1], count);
	if ((err = fclose(fp))) {
		strerror_s(buf, 99, err);
		printf("Ошибка %d(%s) при закрытии файла %s.\n", err,buf, argv[1]);
	}
	return 0;
}
// Листинг 13.2. Программа reducto.c
// reducto.c -- сокращение файлов на две трети!
#include <stdio.h>
#include <stdlib.h> // для exit ()
#include <string.h>
#define LEN 100
int reducto(int argc, char* argv[])
{
	FILE* in, *out; // объявление двух указателей на FILE
	int ch,err,l;
char name[LEN],*pch; // хранилище для имени выходного файла
int count =0;
printf("\n\033[1;4;44mЛистинг 13.2.Программа reducto.c -- сокращение файлов на две трети!\033[0m\n");
// проверка аргументов командной строки
if (argc < 2) {
	fprintf(stderr, "Использование: %s имя_файла\n", argv[0]);
	exit(EXIT_FAILURE);
}
// настройка ввода
if ((err = fopen_s(&in,argv[1], "r")) != 0) {
	fprintf(stderr, "Не удается открыть файл \"%s\"\n",	argv[1]);
	exit(EXIT_FAILURE);
}
	// настройка вывода
	 l=strrchr(argv[1], '.')- argv[1];
	strncpy_s(name,LEN-1, argv[1], l); // копирование имени файла
	//name[LEN - 5] = '\0';
	strcat_s( name,LEN-1, ".red"); // добавление . red
	if ((err = fopen_s(&out,name, "w")) != 0) { // открытие файла для записи
		fprintf(stderr, "Не удается создать выходной файл.\n");
		exit(3);
	}
		// копирование данных
		while ((ch = getc(in)) != EOF)
			if (count++ % 3 == 0)
				putc(ch, out); // выводить каждый третий символ
	// очистка
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Ошибка при закрытии файлов.\n");
	return 0;
}
// Листинг 1З.З. Программа addaword. с
/* addaword.c -- использование fprintf(), fscanf() и rewind () */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101
int addaword(void)
{
	FILE* fp;
	char words[MAX],name[MAX];
	printf("\n\033[1;4;44mЛистинг 13.3.Программа addaword.c -- использование fprintf(), fscanf() и rewind().\033[0m\n");
	printf("Введите имя файла к содержимому которого прибавим слова:");
	gets_s(name, MAX - 1);
	if ((fopen_s(&fp,name, "a+")) != 0)
	{
		fprintf(stdout, "Не удается открыть файл %s.\n",name) ;
		exit(EXIT_FAILURE);
	}
	puts("Введите слова для добавления в файл; для завершения");
	puts("введите символ # в начале строки.");
	while ((fscanf_s(stdin, "%s", words,20) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	puts("Содержимое файла при помощи fputs:");
	rewind(fp);					/* возврат в начало файла */
	while (fscanf_s(fp, "%s", words,20) == 1)
		fputs(words,stdout);
	puts("\nСодержимое файла  при помощи puts:\n");
	rewind(fp);					/* возврат в начало файла */
	while (fscanf_s(fp, "%s", words, 20) == 1)
		puts(words);
	puts("Готово!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Ошибка при закрытии файла\n");
	return 0;
}
// Листинг 13.4. Программа reverse.c
/* reverse.c -- отображение содержимого файла в обратном порядке */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' /* маркер конца файла в текстовых файлах DOS */
#define SLEN 81
int reverse(void)
{
	char file[SLEN];
	char ch;
	FILE* fp;
	long count, last;
	printf("\n\033[1;4;44mЛистинг 13.4.Программа reverse.c -- отображение содержимого файла в обратном порядке.\033[0m\n");
	puts("Введите имя файла для обработки:");
	scanf_s("%s", file,SLEN-1);
	if ((fopen_s(&fp,file, "rb")) != 0)		/* режим только для чтения */
	{ 
		printf("reverse не удается открыть %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);				/* перейти в конец файла */
	last = ftell(fp);
	for (count = 1L; count <= last; count++)
	{
		fseek(fp, -count, SEEK_END);		/* двигаться в обратном направлении */
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r')		/* файлы MS-DOS */
		putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}
// Листинг 13.5. Программа append.c
/* append.c -- добавление содержимого файлов в файл назначения */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE* source, FILE* dest);
char* s_gets(char* st, int n);
int appendmain(void)
{
	FILE* fa, * fs;				// fa для файла назначения, fs для исходного файла
	int files = 0;				// количество добавляемых файлов
	char file_app[SLEN];		// имя файла назначения
	char file_src[SLEN];		// имя исходного файла
	int ch;
	printf("\n\033[1;4;44mЛистинг 13.5.Программа append.c -- добавление содержимого файлов в файл назначения.\033[0m\n");
	puts("Введите имя файла назначения:");
	s_gets(file_app, SLEN);
	if ((fopen_s(&fa,file_app, "a+")) != 0)
	{
		fprintf(stderr, "Не удается открыть %s\n", file_app);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Не удается создать выходной буфер.\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Введите имя первого исходного файла (или пустую строку для завершения):"INPUT3);
	while (s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if (strcmp(file_src, file_app) == 0)
			fputs("Добавить файл в конец самого себя невозможной", stderr);
		else if ((fopen_s(&fs,file_src, "r")) != 0)
			fprintf(stderr, "Не удается открыть %s\n", file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Не удается создать входной буфер\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Ошибка при чтении файла %s.\n", file_src);
			if (ferror(fa) != 0)
				fprintf(stderr, "Ошибка при записи файла %s.\n", file_app);
				fclose(fs);
			files++;
			printf("Содержимое файла %s добавлено.\n", file_src);
			puts("Введите имя следующего файла (или пустую строку для завершения):");
		}
	}
	printf("Добавление завершено. Количество добавленных файлов: %d.\n", files);
	rewind(fa);
	printf("Coдepжимoe %s:\n", file_app);
	while ((ch = getc(fa)) != EOF)
		putchar(ch);
	puts("Отображение завершено.");
	fclose(fa);
	return 0;
}
void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFSIZE]; // выделить память один раз
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
// Листинг 13.6. Программа randbin.c
/* randbin.c — произвольный доступ, двоичный ввод-вывод */
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
	printf("\n\033[1;4;44mЛистинг 13.6.Программа randbin.c — произвольный доступ, двоичный ввод-вывод.\033[0m\n");
	// создание набора значений double
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// попытка открыть файл
	if ((fopen_s(&iofile,file, "wb")) != 0)
	{
		fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
		exit(EXIT_FAILURE);
	}
	// запись в файл массива в двоичном формате
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((fopen_s(&iofile,file, "rb")) != 0)
	{
		fprintf(stderr,"Не удается открыть файл %s для произвольного доступа.\n", file);
		exit(EXIT_FAILURE);
	}
	// чтение избранных элементов из файла
	printf("Введите индекс в диапазоне 0-%d.\n", ARSIZE - 1);
	while (scanf_s("%d", &i) == 1 && i >= 0 && i < ARSIZE)
	{
		pos = (long)i * sizeof(double); // вычисление смещения
		fseek(iofile, pos, SEEK_SET); // переход в нужную позицию
		fread(&value, sizeof(double), 1, iofile);
		printf("По этому индексу находится значение %f.\n", value);
		printf("Введите следующий индекс (или значение за пределами диапазона для завершения):\n");
	}
	// завершение
	fclose(iofile);
	puts("Программа завершена.");
	return 0;
}
/* 2. Что делает следующая программа ? (Предположите, что она запускается в среде
командной строки.)
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
4. Напишите программу, которая принимает ноль или один аргумент командной
строки. Если имеется один аргумент, он интерпретируется как имя файла.
Если аргумент не указан, то должен использоваться стандартный ввод (stdin).
Предположите, что ввод состоит целиком из чисел с плавающей запятой.
Программа должна вычислять и отображать среднее арифметическое значение
для введенных чисел.
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
		printf("Введите числа плав.зпт для вычисления средне-арифм:");
		while ((status=scanf_s("%f", &value))==1) { 
			vals[num++]=value; 
			summ += value;
		}
		getchar();
		printf("Записать введённые числа в файл(y/n):");
		scanf_s("%c",&ch,1);
		getchar();
		if (ch == 'y') {
			printf("Введите имя двоичного файла для сохранения массива чисел(<=20 симв):");
			scanf_s("%s", name, 20);
			if (fopen_s(&fp, name, "wb") != 0) {
				printf("Ошибка открытия файла %s.\n", name);
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
	printf("Среднее арифметическое %d чисел=%lf.\n",num, summ / num);
	return 0;
}
/*
5. Напишите программу, которая принимает два аргумента командной строки.
Первым аргументом является символ, а вторым — имя файла. Программа должна
выводить из файла только те строки, которые содержат указанный символ.
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
	printf("\n\033[1;4;44mЛистинг 13.6.Программа quest5.c — Выводит строки файла, содержащие указанный символ.\033[0m\n");
	if (argc < 3) {
		printf("Запустить с двумя параметрами: \"quest5.exe c filename\" где с - символ, filename - имя файла.\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("\n\033[1;4;44mВыводит строки файла \"%s\", содержащие символ \'%s\'.\033[0m\n",argv[2],argv[1]);
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
