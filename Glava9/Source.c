// Листинг 8.1.Программа echo.с
/* echo.c -- повторяет ввод */
#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// Листинг 9.1 .Программа lethead.2. с
/* lethead2.c */
#include <stdio.h>
#define NAME		"GIGATHINK, INC."
#define ADDRESS		"101 Megabuck Plaza"
#define PLACE		"Megapolis, СА 94904"
#define WIDTH 40
void starbar(void); /* прототип функции */
int lethead1(void)
{
	printf("\n\033[1;4;44mЛистинг 9.1.Программа  lethead1.c -- обрамляет звёздочками\033[0m\n");
	starbar();
	printf("%s\n", NAME);
	printf("%s\n", ADDRESS);
	printf("%s\n", PLACE);
	starbar(); /* использование функции */
	return 0;
}
void starbar(void) /* определение функции */
{
		int count;
		for (count = 1; count <= WIDTH; count++)
			putchar('*');
			putchar('\n');
}
// Листинг 9.2. Программа lethead2. с
/* lethead2.c */
#include <stdio.h>
#include <string.h> /* для strlen() */
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolis, СА 94904"
#define WIDTH 40
#define SPACE ' '
void show_n_char(char ch, int nurn);
int lethead2(void)
{
	int spaces;
	printf("\n\033[1;4;44mЛистинг 9.1.Программа  lethead2.c -- печатает по центру и обрамляет звёздочками\033[0m\n");
	show_n_char('*', WIDTH);				/* использование констант в качестве аргументов */
	putchar('\n');
	show_n_char(SPACE, 12);					/* использование констант в качестве аргументов */
	printf("% s\n", NAME);
	spaces = (WIDTH - strlen(ADDRESS)) / 2;	/* позволить программе вычислить, сколько пробелов нужно вывести */
	show_n_char (SPACE, spaces);			/* использование переменной в качестве аргумента */
	printf("%s\n", ADDRESS);
	show_n_char(SPACE, (WIDTH - strlen(PLACE)) / 2);	/* использование выражения в качестве аргумента */
	printf("%s\n", PLACE);
	show_n_char('*', WIDTH);
	putchar('\n');
	return 0;
}
/* определение функции show_n_char () */
void show_n_char(char ch, int nurn)
{
	int count;
	for (count = 1; count <= nurn; count++)
		putchar(ch);
}
// Листинг 9.3. Программа lesser. с
/* lesser.c -- выбирает меньшее из двух зол */
#include <stdio.h>
int imin(int, int);
int lesser(void)
{
	int evill, evil2;
	printf("\n\033[1;4;44mЛистинг 9.2.Программа   lesser.c -- выбирает меньшее из двух зол.\033[0m\n");
	printf("Введите два целых числа (или q для завершения)"INPUT3);
	while (scanf_s("%d %d", &evill, &evil2) == 2)
	{
		printf("Меньшим из двух чисел %d и %d является %d.\n", evill, evil2, imin(evill, evil2));
		printf("Bвeдитe два целых числа (или q для завершения):"INPUT3);
	}
	printf("Программа завершена.\n");
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
// Листинг 9.4. Программа misuse. с
/* misuse.c -- неправильное использование функции */
#include <stdio.h>
int imax(); /* объявление в старом стиле */
int misuse(void)
{
	printf("\n\033[1;4;44mЛистинг 9.3.Программа   misuse.c -- неправильное использование функции int imax().\033[0m\n");
	printf("Наибольшим значением(imax(3))		 из %d и %d является %d.\n",3, 5, imax(3));
	printf("Наибольшим значением(imax(3.0, 5.0)) из %d и %d является %d.\n",3, 5, imax(3.0, 5.0));
return 0;
}
int imax(n, m)
int n, m;
{
	return (n > m ? n : m);
}
// Листинг 9.5. Программа proto. с
/* proto.c -- использует прототипы функции */
#include <stdio.h>
int imax5(int, int); /* прототип */
int proto(void)
{
	printf("\n\033[1;4;44mЛистинг 9.5.Программа   misuse.c -- неправильное использование функции int imax5(int, int).\033[0m\n");
	printf("Вызов imax(3) не компилируется.\n");
	printf("Вызов imax5(3.0, 5.0).Наибольшим значением из %d и %d является %d.\n", 3, 5, imax5(3.0, 5.0));
	return 0;
}
int imax5(int n, int m)
{
	return (n > m ? n : m);
}
// Листинг 9.6. Программа recur. с
/* recur.c — иллюстрация рекурсии */
#include <stdio.h>
void up_and_down(int);
int recur(void)
{
	printf("\n\033[1;4;44mЛистинг 9.6.Программа recur.c — иллюстрация рекурсии.\033[0m\n\n");
	up_and_down(1);
	printf("\033[0m\n");
	return 0;
}
void up_and_down(int n)
{
	switch(n) {
	case 1:		printf("\033[42m-->Уровень %d: ячейка n %p\n", n, &n); break;// 1
	case 2:		printf("\033[43m-->Уровень %d: ячейка n %p\n", n, &n); break;// 1
	case 3:		printf("\033[44m-->Уровень %d: ячейка n %p\n", n, &n); break;// 1
	case 4:		printf("\033[45m-->Уровень %d: ячейка n %p\n", n, &n); break;// 1
	}
	if (n < 4)
		up_and_down(n + 1);
	switch (n) {
	case 1:		printf("\033[42m<--УРОВЕНЬ %d: ячейка n %p\n", n, &n); break;// 2
	case 2:		printf("\033[43m<--УРОВЕНЬ %d: ячейка n %p\n", n, &n); break;// 2
	case 3:		printf("\033[44m<--УРОВЕНЬ %d: ячейка n %p\n", n, &n); break;// 2
	case 4:		printf("\033[45m<--УРОВЕНЬ %d: ячейка n %p\n", n, &n); break;// 2
	}
	return;
}
// Листинг 9.7.Программа factor.c
// factor.c -- использует циклы и рекурсию для вычисления факториалов
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

	printf("\n\033[1;4;44mЛистинг 9.7.Программа factor.c -- использует циклы и рекурсию для вычисления факториалов.\033[0m\n\n");
	printf("Эта программа вычисляет факториалы.\n");
	printf("Введите значение в диапазоне 0-12 (q для завершения):"INPUT2);
	while (scanf_s("%d", &num) == 1)
	{
		if(num < 0)
			printf("Отрицательные числа не подходят. \n");
		else if (num > 12)
			printf("Вводимое значение должно быть меньше 13. \n");
		else
		{
			printf("цикл:     %d! = %ld \t\tВремя:%g \tза %d повторений\n", num, fact(num), timeRunC(num, RUN_LOOP), RUN_LOOP);
			printf("рекурсия: %d! = %ld \t\tВремя:%g \tза %d повторений\n", num, rfact(num),timeRunR(num, RUN_LOOP), RUN_LOOP);
		}
		printf("Введите значение в диапазоне 0-12 (q для завершения):\n");
	}
	printf("Программа завершена.\n");
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
long fact(int n)		// функция, основанная на цикле
{
	long ans;
	for (ans = 1; n > 1; n--)
		ans *= n;
	return ans;
}
long rfact(int n)		// рекурсивная версия
{
	long ans;
	if (n > 0)
		ans = n * rfact(n - 1);
	else
		ans = 1;
	return ans;
}
// Листинг 9.8. Программа binary. с
/* binary.c — выводит целые числа в двоичной форме */
#include <stdio.h>
void to_binary(unsigned long n);
int binary(void)
{
	unsigned long number;
	printf("\n\033[1;4;44mЛистинг 9.7.Программа binary.c — выводит целые числа в двоичной форме.\033[0m\n\n");
	printf("Bвeдитe целое число(q для завершения) :\n");
	while (scanf_s("%lu", &number) == 1)
	{
		printf("Двоичный эквивалент: ");
		to_binary(number);
		putchar('\n');
		printf("Введите целое число (q для завершения):\n");
	}
	printf("nporpaмa завершена. \n");
	return 0;
}
void to_binary(unsigned long n) /* рекурсивная функция */
{
	int r;
	r = n % 2;
	if (n >= 2)
		to_binary(n / 2);
	putchar(r == 0 ? '0' : '1');
	return;
}
// Листинг 9.12. Программа loccheck. с
/* loccheck.c -- проверка для выяснения, где хранятся переменные */
#include <stdio.h>
void mikado(int); /* объявление функции */
int loccheck(void)
{
	int pooh = 2, bah = 5; /* локальные для main() */
	printf("\n\033[1;4;44mЛистинг 9.12.Программа loccheck.c -- проверка для выяснения, где хранятся переменные.\033[0m\n\n");
	printf("Bнyтpи main() \t\tpooh = %d и &pooh = %p\n", pooh, &pooh);
	printf("Внутри main() \t\tbah  = %d и &bah  = %p\n", bah, & bah);
	mikado(pooh);
	return 0;
}
void mikado(int bah) /* определение функции */
{
	int pooh = 8; /* локальная для mikado () */
	printf("Bнyтpи mikado() \tpooh = %d и &pooh = %p\n", pooh, &pooh);
	printf("Внутри mikado() \tbah  = %d и &bah  = %p\n", bah, &bah);
}
// Листинг 9.15. Программа swap3. с
/* swap3.c -- использование указателей для обмена значениями переменных */
#include <stdio.h>
#include <stdbool.h>
void interchange(int* и, int* v);
int swap3(void)
{
	int x = 5, y = 10;
	printf("\n\033[1;4;44mЛистинг 9.15.Программа swap3.c -- использование указателей для обмена значениями переменных.\033[0m\n\n");
	printf("Первоначально х = %d \tи у = %d.\n", x, y);
	interchange(&x, &y); // передача адресов в функцию
	printf("Теперь        х = %d \tи у = %d.\n", x, y);
	return 0;
}
void interchange(int* u, int* v)
{
	int temp;
	temp = *u; // temp получает значение, на которое указывает u
	*u = *v;
	*v = temp;
}
// 4. Напишите функцию, которая возвращает сумму двух целых чисел.
int summ2(int x, int y);
double summd(double x, double y);
void alter(int* x, int* y);
int max3(int x, int y, int z);
int test4(void) {
	printf("\n\033[1;4;44m4-5. Напишите функцию, которая возвращает\n "
		                   "   1. сумму двух целых\n"
		                   "   2. сумму двух действительных чисел\n"
		                   "   3. x+y x-y.\n"
		                   "   4. максимум из 3-х целых.\033[0m\n\n");
	int i1, i2,x,y,z;
	double e1, e2;
	while(1){
		printf("1.Введите 2 целых числа(не цифра - конец):"INPUT3);
		if (scanf_s("%d %d", &i1, &i2) != 2) break;
		printf("%d + %d = %d\n", i1, i2, summ2(i1, i2));
		printf("2.Введите 2 действительных числа:"INPUT3);
		if (scanf_s("%le %le", &e1, &e2) != 2) break;
		printf("%e + %e = %e\n", e1, e2, summd(e1, e2));
		printf("3.Введите 2 целых числа:"INPUT3);
		if (scanf_s("%d %d", &x, &y) != 2) break;
		i1 = x, i2 = y;
		alter(&x, &y);
		printf("%d + %d = %d   %d - %d = %d\n", i1, i2, x,i1,i2,y);
		printf("4.Введите 3 целых числа:"INPUT3);
		if (scanf_s("%d %d %d", &x, &y,&z) != 3) break;
		printf("Максимум(%d,%d,%d) = %d\n", x, y, z, max3(x, y, z));
	}
	return 0;
}
int summ2(int x, int y) {
	return x + y;
}
// 5. Что придется изменить, если вообще придется, чтобы функция из вопроса 4 взамен суммировала два числа типа double?
double summd(double x, double y) {
	return x + y;
}
// 6. Напишите функцию по имени alter (), которая принимает две переменные
//    int, х и у, и устанавливает их значения, соответственно, в сумму и разность х и у.
void alter(int* x, int* y) {
	*x += *y;
	*y = *x - 2**y;
	return;
}
// 8. Напишите функцию, которая возвращает наибольший из трех целочисленных аргументов.
int max3(int x, int y, int z) {
	if (x > y) {
		if (x > z) return x;
		else return z;
	}
	else if (y > z) return y;
	else return z;
}/*
 9. Задан следующий вывод:
Выберите один из следующих вариантов:
1) копировать файлы 2) переместить файлы
3) удалить файлы    4) выйти из программы
Введите номер выбранного варианта:
а. Напишите функцию, которая выводит на экран меню из четырех пронумерованных
вариантов и предлагает выбрать один из них. (Вывод должен иметь показанный выше вид.)
 */
int menu9(int n, int m);
void spaces(int n);
int test9(void) {
	int fun;
	fun=menu9(8, 4);
	printf("Выбрана функция %d.\n",fun);
}
int menu9(int n,int m) {
// Выводит меню n - число пунктов, m - число столбцов
	char* lmenu[] = {
		             "1) копировать файлы",
		             "2) переместить файлы",
		             "3) удалить файлы",
		             "4) выйти из программы",
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
	printf("Выберите один из следующих вариантов:\n");
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
			scanf_s("%*s");					// отбрасывание нецелочисленного ввода
		printf("Bвeдитe целое число от 1 до %d:"INPUT1, n);
	}
	return menu;
}
void spaces(int n) {
	int i;
	for (i = 0; i < n; i++) putch(' ');
}
bool checkMenu(int n) {

}