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
Упражнения по программированию Глава 13.
*/
/*                // Шаблон задачи 2

* /

int Exsample10(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
	do
	{

	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}

*/
/*                // Шаблон задачи

* /

int Exsample10(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
	do
	{

		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c",&ch,1);
		if (ch == '\n') continue;
		getchar();
		while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д'|| ch=='\n');
	printf("\nКонец программы\n");
	return 0;
}

*/
/*
1. Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю
ввести имя файла и читала его ответ вместе использования аргументов командной
строки.
*/
#define MAX_NAME 20
int count13_1(char* name);
int Exsample1(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 1. Модифицируйте программу в листинге 13.1, чтобы она предлагала пользователю ввести имя файла.\033[0m\n");
	do
	{
		count13_1(args > 1 ? argv[1] : "");
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
// Листинг 13.1. Программа count. с
/* count.c — использование стандартного ввода-вывода */
#include <stdlib.h> // прототип exit()
#include <string.h>
#include <errno.h>
#define MAX_NAME 21 
#define MAX_BUF 201 
//char* strerror(int errnum);
int count13_1(char* str)
{
	int ch; // место для хранения каждого символа по мере чтения
	char buf[MAX_BUF], name[MAX_NAME], * pname;
	FILE* fp; // "указатель файла"
	unsigned long count = 0;
	int err;
	printf("\n\033[1;4;44mЛистинг 13.1.Программа count.c — использование стандартного ввода-вывода.\033[0m\n");
	if (strlen(str) == 0) {
		printf("Введите имя файла:");
		fscanf_s(stdin, "%20s", name, MAX_NAME);
		getchar();
		pname = name;
	}
	else
		pname = str;
	if ((err = fopen_s(&fp, pname, "r")) > 0)
	{
		strerror_s(buf, 99, err);
		printf("Не удается открыть файл %s. Ошибка=%d(%s)\n", pname, err, buf);
		exit(EXIT_FAILURE);
	}
	printf("Содержимое файла %s:\n", pname);
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout); // то же, что и putchar (ch) ;
		count++;
	}
	printf("\nФайл %s содержит %lu символов\n", pname, count);
	if ((err = fclose(fp))) {
		strerror_s(buf, 99, err);
		printf("Ошибка %d(%s) при закрытии файла %s.\n", err, buf, pname);
	}
	return 0;
}
/*
2. Напишите программу копирования файлов, которая получает имя исходного
файла и имя копии из командной строки. Используйте стандартный ввод-вывод
и двоичный режим, если это возможно.
*/
int copyFile(char* filenameSource, char* filenameTarget);
int Exsample2(int args, char* argv[])
{
	int i, beg, end;
	char ch, ** pname;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 2. копирования файлов, которая получает имя исходного файла и имя копии из командной строки.\033[0m\n");
	do
	{
		//printf("Введите")
		if (args == 3) {
			copyFile(argv[1], argv[2]);
		}
		else {
			printf("\033[31mОшибка!\033[0m В командной строке запуска программы нужно два файла: исходный копия.\n");
			printf("Параметры(%d штук) командной строки: ", args);
			for (int i = 0; i < args; i++)
				printf("%s(%d),", argv[i], i);
			printf("\n");
		}
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
bool checkOpen(FILE** pf, char* nameF, char* opt);
int copyFile(char* filenameSource, char* filenameTarget) {
	FILE* pfs, * pft;
	char* buf;
	int num, lSize;
	printf("Перепись содержимого файла \033[32m%s\033[0m в файл \033[32m%s\033[0m.\n", filenameSource, filenameTarget);
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
		printf("Не удается открыть файл \033[32m%s\033[0m для режима \033[32m%s\033[0m. Ошибка=%d(%s)\n", nameF, opt, err, buf);
	}
	else ret = true;
	return ret;
}
/*
3. Напишите программу копирования файлов, которая предлагает пользователю
ввести имя текстового файла, выступающего в роли исходного, и имя выходного
файла. Программа должна использовать функцию toupper() из ctype.h
для перевода текста в верхний регистр во время его записи в выходной файл.
Применяйте стандартный ввод-вывод и текстовый режим.
*/
#define MAX_FILE 100
int Exsample3(void)
{
	int i, beg, end;
	char ch;
	char* fName1[MAX_FILE], fName2[MAX_FILE];
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 3. копирования файлов, имена файлов запрашиваются в диалоге.\033[0m\n");
	do
	{
		printf("Введите имя исходного файла и имя результирующего файла через пробел:"INPUT3);
		scanf_s("%s %s", fName1, MAX_FILE - 1, fName2, MAX_FILE - 1);
		getchar();
		copyFile(fName1, fName2);
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
/*
4. Напишите программу, которая последовательно отображает на экране содержимое
всех файлов, перечисленных в командной строке. Для управления циклом
используйте argc.
*/
void printFile(char* name);
int Exsample4(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 4. отображает на экране содержимое всех файлов, перечисленных в командной строке.\033[0m\n");
	do
	{
		for (int i = 1; i < args; i++)
			printFile(argv[i]);
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
void printFile(char* name) {
	FILE* fp;
	char ch;
	if ((fopen_s(&fp, name, "r")) != 0) exit(EXIT_FAILURE);
	printf("\n-----------------Содержимое файла \033[32m%s\033[0m\n", name);
	while (fscanf_s(fp, "%c", &ch, 1) == 1) {
		printf("%c", ch);
	}
	fclose(fp);
}
/*
5. Модифицируйте программу в листинге 13.6, чтобы вместо интерактивного интерфейса
она использовала интерфейс командной строки.
*/
int randbin5(char* name);
int Exsample5(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 5. Модифицируйте программу 13.6, чтобы она использовала командную строку.\033[0m\n");
	do
	{
		randbin5(argv[1]);
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
// Листинг 13.6. Программа randbin.c
/* randbin.c — произвольный доступ, двоичный ввод-вывод */
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
	printf("\n\033[1;4;44mЛистинг 13.6.Программа randbin.c — произвольный доступ, двоичный ввод-вывод.\033[0m\n");
	printf("\n\033[1;4;44mЗаписывает в файл %s числа и читает их.\033[0m\n", name);
	// создание набора значений double
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// попытка открыть файл
	if ((fopen_s(&iofile, file, "wb")) != 0)
	{
		fprintf(stderr, "Не удается открыть файл %s для вывода.\n", file);
		exit(EXIT_FAILURE);
	}
	// запись в файл массива в двоичном формате
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((fopen_s(&iofile, file, "rb")) != 0)
	{
		fprintf(stderr, "Не удается открыть файл %s для произвольного доступа.\n", file);
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
/*
6. Программы, работающие с аргументами командной строки, полагаются на то,
что пользователь помнит, как их правильно запускать. Перепишите программу
из листинга 13.2 так, чтобы вместо использования аргументов командной строкики
она предлагала пользователю ввести необходимую информацию.
*/
int reducto6(char* name);
int Exsample6(void)
{
	int i, beg, end;
	char ch;
	char name[MAX_NAME];
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 6. Перепишите программу 13.2. для ввода парметров в диалоге.\033[0m\n");
	do
	{
		printf("Введите имя файла для сокращения:"INPUT3);
		scanf_s("%s", name, MAX_NAME - 1);
		getchar();
		reducto6(name);
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("Ошибка! Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
// Листинг 13.2. Программа reducto.c
// reducto.c -- сокращение файлов на две трети!
#include <stdio.h>
#include <stdlib.h> // для exit ()
#include <string.h>
#define LEN 100
int reducto6(char* name)
{
	FILE* in, * out; // объявление двух указателей на FILE
	int ch, err, l;
	char* nameOut[LEN], * pch; // хранилище для имени выходного файла
	int count = 0;
	printf("\n\033[1;4;44mЛистинг 13.2.Программа reducto.c -- сокращение файлов на две трети!\033[0m\n");
	// настройка ввода
	if ((err = fopen_s(&in, name, "r")) != 0) {
		fprintf(stderr, "Не удается открыть файл \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}
	// настройка вывода
	l = strrchr(name, '.') - name;
	strncpy_s(nameOut, LEN - 1, name, l); // копирование имени файла
	//name[LEN - 5] = '\0';
	strcat_s(nameOut, LEN - 1, ".red"); // добавление . red
	if ((err = fopen_s(&out, nameOut, "w")) != 0) { // открытие файла для записи
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
/*
7. Напишите программу, которая открывает два файла. Получать имена файлов
можно либо через командную строку, либо предложив пользователю ввести их.
а. Сделайте так, чтобы эта программа выводила строку 1 первого файла, строку 1
	второго файла, строку 2 первого файла, строку 2 второго файла и т.д., пока нс
	будет выведена последняя строка более длинного (по количеству строк) файла.
б. Модифицируйте программу так, чтобы строки с одним и тем же номером вы водились
	в одной экранной строке.
*/
void file2Print(char* name1, char* name2);
int Exsample7(int args, char* argv[])
{
	int i, beg, end, status;
	char ch;
	char name1[MAX_NAME], name2[MAX_NAME];
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 7. Параллельный вывод содержимого двух файлов.\n"
		"           Если имена не заданы в командной строке они запрашиваются.\033[0m\n");
	do
	{
		if (args < 3) {
			printf("Введите два имени выводимых файлов(через пробел):"INPUT3);
			do {
				status = scanf_s("%s %s", name1, MAX_NAME - 1, name2, MAX_NAME - 1);
				if (status != 2) printf("\033[31mОшибка!\033[0m Нужно ввести два имени файлов через пробел.\n");
			} while (status != 2);
			getchar();
		}
		else {
			strncpy_s(name1, MAX_NAME, argv[1], strlen(argv[1]));
			strncpy_s(name2, MAX_NAME, argv[2], strlen(argv[2]));
		}
		file2Print(name1, name2);
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
#define LINE_LN 100 // длина строки для печати
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
	printf("\n-------------Содержимое файла \033[32m%s\033[0m%s|----------------Содержимое файла \033[32m%s\033[0m-------------\n", name1, filTitle, name2);
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
8. Напишите программу, которая принимает в качестве аргументов командной
строки символ и ноль или более имен файлов. Если за символом не следуют аргументы,
программа должна читать стандартный ввод. В противном случае она
должна открывать каждый файл по очереди и сообщать, сколько раз в нем встречается
указанный символ. Вместе с результатом каждого подсчета должны быть
указаны имя файла и сам символ. Предусмотрите средства проверки ошибок,
позволяющие выяснить корректность количества аргументов и возможность открытия
файлов. Если файл не может быть открыт, программа должна сообщать
об этом факте и переходить к обработке следующего файла.
*/
#define MAX_NAME 10
#define MAX_LNAME 20
#define MAX_STR 100 // длина буфера для чтения файла
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
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 8. Подсчёт колличества появлений символа в файлы.\033[0m");
	printf("\n\033[1;4;44m           символ и файлы можно задать в командной строке или в диалоге.\033[0m\n");
	do
	{
		switch (args) {
		case 1:
			printf("Введите символ и имена файлов для поиска(через пробел):\n");
			ch = getche();
			i = n = 0;
			n = getwords(MAX_NAME, MAX_LNAME);
			break;
		case 2:
			ch = argv[1][0];
			printf("Введите имена файлов для поиска(через пробел):\n");
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
		printf("\nЕщё разок?(y/n или д/н):");
		//ch1=getchar();
		scanf_s("%c", &ch, 1);
		if (ch == '\n') continue;
		getchar();
		while (!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
			printf("\033[31mОшибка!\033[0m Нужно(y/n д/н):");
			ch = getchar();
			getchar();      // пропуск '\n'
		}
	} while (ch == 'y' || ch == 'д' || ch == '\n');
	printf("\nКонец программы\n");
	return 0;
}
char getSymbol(char str) {
	char ch;
	printf("%s:"INPUT3, str);
	scanf_s("%c", &ch, 1);
	return ch;
}
bool getword(int n, int len) {
	// считывает слово - символы(не больше len) до пробела в word, завершает слово '\0'
	// возвращает true, если считывает конец строки. длина word>len
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
	// считывает <=n слов, не длиннее len
	// возвращает число считанных слов
	int nwords = 0;
	while (!getword(nwords++, len) && nwords < n);
	return nwords;
}
void OutTable(char ch, int n) {
	char name[MAX_LNAME + 1];
	int count;
	printf("Таблица вcтречаимости символа \033[32;1;4m%c\033[0m в файлах.\n", ch);
	printf("Файл \t\tчисло\n");
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
		printf("\033[31mОшибка!\033[0m Не открывается файл %s.\n", name);
		n = -1;
	}
	return n;
}
/*
9. Модифицируйте программу в листинге 13.3, чтобы каждое слово было пронумеровано
в соответствии с порядком его добавления в список, начиная с 1.
Позаботьтесь о том, чтобы при втором запуске программы новая нумерация
слов начиналась с того места, где была закончена нумерация при предыдущем запуске.
*/
int addaword13_3(void);
bool getYes(char* quest);
int Exsample9(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 9. Модификация программы 13.3.\033[0m\n");
	do{
		addaword13_3();
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
// Листинг 1З.З. Программа addaword. с
/* addaword.c -- использование fprintf(), fscanf() и rewind () */
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
	printf("\n\033[1;4;44mЛистинг 13.3.Программа addaword.c -- использование fprintf(), fscanf() и rewind().\033[0m\n");
	printf("Введите имя файла к содержимому которого прибавим слова:"INPUT3);
	gets_s(name, MAX - 1);
	if ((fopen_s(&fp, name, "r")) != 0){
		fprintf(stdout, "\033[31mОшибка!\033[0m Не удается открыть файл \033[32m%s\033[0m.", name);
		if (getYes(" Создать файл?")) {
			status = fopen_s(&fp, name, "w");
			if (status != 0) {
				fprintf(stdout, "\033[31mОшибка!\033[0m Не удается создать файл \033[32m%s\033[0m.", name);
				return 0;
			}
		}
		else return 0;
	}
	nwords = countNwords(fp);
	freopen_s(&fp,name, "a+", fp);
	printf("\nВ файле %d слов. Введите ещё слова для добавления;\n", nwords);
	puts("для завершения введите символ # в начале строки.");
	printf(":");
	while ((fscanf_s(stdin, "%s", words, 20) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	nwords = countNwords(fp);
	printf("\nТеперь в файле %d слов. Содержимое файла:\n", nwords);
	rewind(fp);					/* возврат в начало файла */
	i = 1;
	while (fscanf_s(fp, "%s", words, 20) == 1)
		printf("%3d \t%s\n",i++,words);
	puts("Готово!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Ошибка при закрытии файла\n");
	return 0;
}
bool getYes(char* quest) {
	char ch,* s, * q = "yYдДnNнН";
	int n;
	printf("%s(Да-\033[32myYдД\033[0m, Нет-\033[32mnNнН\033[0m):"INPUT1, quest);
	do {
		ch = getche();
		s = strchr(q, (int)ch);
		if (s != NULL) {
			n = s - q;
			break;
		}
		printf("\n\033[31mОшибка!\033[0m Требуется один из символов-\033[32m%s\033[0m:"INPUT1, q);
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
				while (isspace(*ps)) ps++; // пропустить пробелы
			}
		}
	}
	return count;
}
/*
10. Напишите программу, открывающую текстовый файл, имя которого получается
интерактивно. Организуйте цикл, который предлагает пользователю ввести 
позициюв файле. Затем программа должна вывести часть файла, начиная с этой
позиции и заканчивая следующим символом новой строки. Цикл ввода должен
завершаться при вводе отрицательного или нечислового значения.
*/
void outFromIdx(FILE* pf, long idx);
int Exsample10(void)
{
	int i, beg, end;
	long idx;
	char ch, name[MAX_LNAME+1];
	FILE* pf;
	errno_t err;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 10. Вывести содержимое текстового файла с указанной позиции до конца строки.\033[0m\n");
	do
	{
		printf("Введите имя текстового файла:"INPUT3);
		scanf_s("%s",name,MAX_LNAME);
		if ((err=fopen_s(&pf, name, "rt"))!=0) {
			printf("\033[31mОшибка!\033[0m Файл %s не открывается.\n",name);
		}
		else {
			do {
				printf("Введите смещение(число символов) в файле:");
				scanf_s("%ld", &idx);
				if (idx < 0) break;
				//printf("Смещение=%d\n",idx);
				outFromIdx(pf, idx);
			} while (true);
		}
	} while (getYes("\nЗапустить программу ещё разок?"));
	fclose(pf);
	printf("\nКонец программы\n");
	return 0;
}
void outFromIdx(FILE* pf, long idx) {
	char buf[MAX_BUF + 1];
	rewind(pf);
	if (fseek(pf, idx, SEEK_SET) != 0) {
		printf("\033[31mОшибка!\033[0m Неверное смещение.\n");
	}
	else {
		fgets( buf, MAX_BUF,pf);
		printf("%3ld: \t%s\n", idx, buf);
	}

}
/*
11. Напишите программу, которая принимает два аргумента командной строки.
Первый аргумент - это строка, а второй - имя файла. Программа должна искать
в файле и выводить все строки, содержащие указанную. Поскольку задача
ориентирована на строки, а не на символы, используйте функцию fgets()
вместо getc(). Для поиска строки, содержащей заданную, применяйте функцию
strstr() (кратко описанную в упражнении 7 из главы 11) из стандартной библиотеки С.
*/
int FindString(FILE* pf, char* str);

int Exsample11(int args, char* argv[])
{
	int i, beg, end;
	char ch;
	FILE* pf;
	errno_t err;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 11. Поиск строки в файле и выводить все строки, содержащие указанную.\033[0m\n");
	do
	{
		if (args < 3) {
			printf("\n\033[31mОшибка!\033[0m В командной строке нужно задать строку поиска и имя файла.\n");
			break;
		}
		else {
			if ((err=fopen_s(&pf, argv[2], "rt")) != 0) {
				printf("\n\033[31mОшибка!\033[0m Не открывается файл %s:", argv[2]);
				perror("");
				break;
			}
			else {
				printf("В файле %s найдено %d строк \"%s\".",argv[2], FindString(pf, argv[1]),argv[1]);
			}
		}
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
int FindString(FILE* pf, char* str) {
	char buf[MAX_BUF],* pch;
	long idx=0;
	int count=0;
	printf("Найденные строки:\n");
	while (!feof(pf)) {
		if (pch = fgets(buf, MAX_BUF, pf)) {
			if(strstr(buf,str)) 
				printf("%3d: \t%s", ++count,buf);
		}
	}
	return count;
}
/*
12. Создайте текстовый файл, состоящий из 20 строк по 30 целых чисел. Целые значения
должны входить в диапазон от 0 до 9 и отделяться друг от друга пробелами.
Файл является цифровым представлением изображения, при этом значения
от 0 до 9 воспроизводят возрастающие уровни темноты. Напишите программу,
которая читает содержимое этого файла в массив элементов int arr[20][30].
При грубом подходе к преобразованию такого цифрового представления
в изображение программа должна использовать значения из этого массива для
инициализации массива элементов char с размером 20 на 31. При этом 0 соответствует
символу пробела, 1 - символу точки и т.д.; большее значение представляется
символом, занимающим большую площадь. Например, символ # может
использоваться для представления значения 9. Последний символ (31-й) в каждой
строке должен быть нулевым, образуя в итоге массив из 20 строк. Программа
должна отобразить результирующее изображение (т.е. вывести строки) и также
сохранить результат в текстовом файле. Например, предположим, что начальные
данные выглядят так:
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
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 12. Растровая картина.\033[0m\n");
	strcpy_s(nameIn, MAX_LNAME, argv[1]);
	strcpy_s(nameOut, MAX_LNAME, argv[1]);
	do
	{
		if (args < 2) {
			printf("\n\033[31mОшибка!\033[0m Нужно задать в командной строке имя файла.\n");
		}
		else {
			if ((fopen_s(&pf, argv[1], "rt")) != 0) {
				printf("\n\033[31mОшибка!\033[0m Не открывается файл %s:", argv[1]);
				perror("");
				break;
			}
			else {
				//printf("Обработка файла %s.\n", nameIn);
				replExtr(nameOut, "ras");
				if (fopen_s(&pfR, nameOut, "w")!=0) {
					printf("\n\033[31mОшибка!\033[0m Не созаётся файл %s:", nameOut);
					perror("");
					break;
				}
				else {
					//printf("Обработка файла %s.\n", nameOut);
					createRastr(pf, pfR);
					printRastr();
				}
				fclose(pf);
			}
		}
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
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
	// Саздаёт массив кодов растра из входного файла
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
	// Создаёт символьный растр из массива кодов растра
	char* rsymb = " .,-+*#HDWQRSZMO";	// Символы растра
	int k;
	for (int i = 0; i < RASTR_X; i++){
		for (int j = 0; j < RASTR_Y; j++) {
			k = ar[i][j];
			rastr[i][j] = rsymb[k];
		}
	}
}
void replExtr(char* fileName, char* extr) {
	// Заменяет в имени файла fileName расширение на указанное в extr
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
14. Цифровые изображения, особенно передаваемые по радиоканалу космическим
аппаратом, могут содержать помехи. Добавьте в программу из упражнения 12
функцию подавления помех. Она должна сравнивать каждое значение с соседними
значениями, расположенными слева и справа, снизу и сверху. Если значение
отличается более чем на 1 от своих соседей, оно должно быть заменено средним
значением всех соседних величин. Среднее значение должно быть округлено до
ближайшего целого. Обратите внимание, что точки, находящиеся на границах,
имеют меньше четырех соседей, поэтому они требуют специальной обработки.
*/
void interfer(void);
int Exsample14(int args, char* argv[])
{
	int i, beg, end;
	char ch, nameIn[MAX_LNAME + 1], nameOut[MAX_LNAME + 1];
	FILE* pf, * pfR;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 14. подавления помех в растре.\033[0m\n");
	strcpy_s(nameIn, MAX_LNAME, argv[1]);
	strcpy_s(nameOut, MAX_LNAME, argv[1]);
	do
	{
		if (args < 2) {
			printf("\n\033[31mОшибка!\033[0m Нужно задать в командной строке имя файла.\n");
		}
		else {
			if ((fopen_s(&pf, argv[1], "rt")) != 0) {
				printf("\n\033[31mОшибка!\033[0m Не открывается файл %s:", argv[1]);
				perror("");
				break;
			}
			else {
				//printf("Обработка файла %s.\n", nameIn);
				replExtr(nameOut, "ras");
				if (fopen_s(&pfR, nameOut, "w") != 0) {
					printf("\n\033[31mОшибка!\033[0m Не созаётся файл %s:", nameOut);
					perror("");
					break;
				}
				else {
					//printf("Обработка файла %s.\n", nameOut);
					inputIn(pf);
					interfer();
					inputOut(pfR);
					printRastr();
				}
				fclose(pf);
				fclose(pfR);
			}
		}
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
void interfer(void) {
	// усреднение значений в ar[RASTR_X][RASTR_Y];
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
