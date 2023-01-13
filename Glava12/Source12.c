#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
// Листинг 12.1. Программа hiding. с
// hiding.c -- переменные в блоках
#include <stdio.h>
int hiding()
{
	int x = 30; // исходная переменная х
	printf("\n\033[1;4;44mЛистинг 12.1.Программа  hiding.c -- переменные в блоках.\033[0m\n");
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	{
		int x = 77; // новая переменная х, скрывающая первую х
		printf("x во внутреннем блоке: %d по адресу %p\n", x, &x);
	}
	printf("x во внешнем блоке: %d по адресу %p\n", x, &x);
	while (x++ < 33) // исходная переменная х
	{
		int x = 100; // новая переменная х, скрывающая первую х
		x++;
		printf("x в цикле while: %d по адресу %p\n", x, &x);
	}
	printf("х во внешнем блоке : % d по адресу % p\n", x, &x);
	return 0;
}
// Листинг 12.2. Программа forc99.c
// forc99.c -- новые правила для блоков в С99
#include <stdio.h>
int forc99()
{
	int n = 8;
	printf("\n\033[1;4;44mЛистинг 12.2.Программа  forc99.c -- новые правила для блоков в С99.\033[0m\n");
	printf(" Первоначально n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
		printf(" цикл 1: n = %d по адресу %p\n", n, &n);
	printf(" После цикла 1 n = %d по адресу %p\n", n, &n);
	for (int n = 1; n < 3; n++)
	{
		printf(" индекс цикла 2 n = %d по адресу %p\n", n, &n);
		int n = 6;
		printf(" цикл 2: n = %d по адресу %p\n", n, &n);
		n++;
	}
	printf(" После цикла 2 n = %d по адресу %p\n", n, &n);
	return 0;
}
// Листинг 12.3. Программа loc_stat.с
/* loc_stat.c -- использование локальной статической переменной */
#include <stdio.h>
void trystat(void);
int loc_stat(void)
{
	int count;
	printf("\n\033[1;4;44mЛистинг 12.3.Программа  loc_stat.c -- использование локальной статической переменной.\033[0m\n");
	for (count = 1; count <= 3; count++)
	{
		printf("Начинается итерация %d:\n", count);
		trystat();
	}
		return 0;
}
void trystat(void)
{
	int fade = 1;
	static int stay = 1;
	printf("fade = %d и stay = %d\n", fade++, stay++);
}
// Листинг 12.4. Программа global.с
/* global.c -- использование внешней переменной */
#include <stdio.h>
int units = 0; /* внешняя переменная */
void critic(void);
int global(void)
{
	extern int units; /* необязательное повторное объявление */
	printf("\n\033[1;4;44mЛистинг 12.3.Программа  global.c -- использование внешней переменной.\033[0m\n");
	printf("Сколько фунтов весит маленький бочонок масла?^");
	scanf_s("%d", &units);
	while (units != 56)
		critic();
	printf("Вы знали это!\n");
	return 0;
}
void critic(void)
{
	/* необязательное повторное объявление опущено */
	printf("Вам не повезло. Попробуйте еще раз.\n");
	scanf_s("%d", &units);
}
// Листинг 12.5. Программа parta.c
// parta.c — разнообразные классы хранения
// компилировать вместе с partb.c
#include <stdio.h>
void report_count();
void accumulate(int k);
int count = 0;				// область видимости в пределах файла, внешнее связывание
int parta(void)
{
	int value;				// автоматическая переменная
	register int i;			// регистровая переменная
	printf("\n\033[1;4;44mЛистинг 12.5.Программа  parta.c — разнообразные классы хранения.\033[0m\n");
	printf("Введите положительное целое число (0 для завершения):"INPUT3);
	while (scanf_s("%d", &value) == 1 && value > 0)
	{
		++count;			// использование переменной с областью видимости в пределах файла
		for (i = value; i >= 0; i--)
			accumulate(i);
		printf("Введите положительное целое число (0 для завершения):"INPUT3);
	}
	report_count();
	return 0;
}
void report_count()
{
	printf("Цикл выполнен %d раз(а)\n", count);
}
// Листинг 12.8. Драйвер r_drive0.c
/* r_drive0.c -- тестирование функции rand0() */
/* компилировать вместе с rand0.c */
#include <stdio.h>
extern int rand0(void);
int r_drive0(void)
{
	int count;
	printf("\n\033[1;4;44mЛистинг 12.8.Программа  r_drive0.c -- тестирование функции rand0().\033[0m\n");
	for (count = 0; count < 50; count++)
		printf("%2d: %d\n",count, rand0());
	return 0;
}
// Листинг 12.10. Драйвер r_drive1.с
/* r_drive1.c — тестирование функций rand1() и srand1() */
/* компилировать вместе с s_and_r.c */
#include <stdio.h>
extern void srand1(unsigned int x);
extern int rand1(void);
int r_drive1(void)
{
	int count;
	unsigned seed;
	printf("\n\033[1;4;44mЛистинг 12.10.Программа  r_drive1.c — тестирование функций rand1() и srand1().\033[0m\n");
	printf("Введите желаемое начальное число:"INPUT3);
	while (scanf_s("%u", &seed) == 1)
	{
		srand1(seed); /* переустановка начального числа */
		for (count = 0; count < 10; count++)
			printf("%d\n", rand1());
		printf("Введите следующее начальное число (q для завершения):"INPUT3);
	}
	printf("Программа завершена.\n");
	return 0;
}
// Листинг 12.13. Файл manydice. с
/* manydice.c — бросание множества костей */
/* компилировать вместе с diceroll.c */
#include <stdio.h>
#include <stdlib.h>			/* для библиотечной функции srand() */
#include <time.h>			/* для функции time() */
#include "diceroll.h"		/* для функции roll_n_dice () */
							/* и для переменной roll_count */
int manydice(void)
{
	int dice, roll;
	int sides, status;
	printf("\n\033[1;4;44mЛистинг 12.13.Программа  manydice.c — бросание множества костей.\033[0m\n");
	srand((unsigned int)time(0)); /* рандомизация начального числа */
	printf("Введите количество граней кости или 0 для завершения программы:"INPUT3);
	while (scanf_s("%d", &sides) == 1 && sides > 0)
	{
		printf("Сколько костей?:"INPUT3);
		if ((status = scanf_s("%d", &dice)) != 1)
		{
			if (status == EOF)
				break;										/* выход из цикла */
			else
			{
				printf("\033[31mОшибка!\033[0mВы должны ввести целое число.");
				printf("Давайте начнем с начала.\n");
				while (getchar() != '\n') continue;			/* отбросить некорректный ввод */
				printf("Сколько граней? Для прекращения введите 0.\n");
				continue;									/* новая итерация цикла */
			}
		}
		roll = roll_n_dice(dice, sides);
		printf("Вы бросали %d раз(а), используя %d кости с %d гранями.\n", roll, dice, sides);
		printf("Сколько граней? Для прекращения введите 0:"INPUT3);
	}
	printf("Функция rollem() была вызвана %d раз(а).\n",roll_count); /* используется переменная extern */
	printf("Пусть удача не покидает вас!\n");
	return 0;
}
// Листинг 12.14. Программа dyn_arr.с
/* dyn_arr.c -- динамически выделяемый массив */
#include <stdio.h>
#include <stdlib.h> /* для malloc(), free() */
int dyn_arr(void)
{
	double* ptd;
	int max = 0;
	int number;
	int i = 0;
	printf("\n\033[1;4;44mЛистинг 12.14.Программа  dyn_arr.c -- динамически выделяемый массив.\033[0m\n");
	puts("Введите максимальное количество элементов типа double:"INPUT3);
	if (scanf_s("%d", &max) != 1)
	{
		puts("Количество введено некорректно -- программа завершена.");
		exit(EXIT_FAILURE);
	}
	ptd = (double*)malloc(max * sizeof(double));
	if (ptd == NULL)
	{
		puts("He удалось выделить память. Программа завершена.");
		exit(EXIT_FAILURE);
	}
	/* ptd теперь указывает на массив из max элементов */
	puts("Введите значения (q для выхода):");
	while (i < max && scanf_s("%lf", &ptd[i]) == 1)
		++i;
	printf("Bвeдeнo %d элементов:\n", number = i);
	for (i = 0; i < number; i++)
	{
		printf("%7.2f", ptd[i]);
		if (i % 7 == 6) putchar('\n');
	}
	if (i % 7 != 0) putchar('\n');
	puts("Программа завершена.");
	free(ptd);
	return 0;
}
// 
int test1(void) {
	int n = 5;
	int m = 6;
	//int ar2[n][m]; // массив переменной длины n х m
	int(*p2)[6]; // работает до выхода стандарта С99
	//int(*рЗ)[m]; // требуется поддержка массивов переменной длины
	p2 = (int(*)[6]) malloc(n * 6 * sizeof(int)); // массив n * 6
	//рЗ = (int(*)[m]) malloc(n * m * sizeof(int)); // массив n * m
	// предыдущее выражение также требует поддержки массивов переменной длины
	//ar2[1][2] = р2[1][2] = 12;
	p2[2][3] = 88;
}
// Листинг 12.15. Программа where. с
// where.c -- где что находится в памяти ?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int static_store = 30;
const char* pcg = "Строковый литерал";
int where()
{
	int auto_store = 40;
	char auto_string[] = "Автоматический массив char";
	int* pi;
	char* pcl;
	pi = (int*)malloc(sizeof(int));
	*pi = 35;
	pcl = (char*)malloc(strlen("Динамическая строка") + 1);
	strcpy_s(pcl, strlen("Динамическая строка") + 1, "Динамическая строка");
	printf("\n\033[1;4;44mЛистинг 12.15.Программа  where.c -- где что находится в памяти?\033[0m\n");
	printf("\033[42;30mСтатическая область памяти:-------------------------------\033[0m\n");
	printf("static_store: %d по адресу \t%p\n", static_store, &static_store) ;
	printf("%s по адресу \t%p\n", pcg, pcg);
	printf("%s по адресу \t%p\n", "Строка в кавычках", "Строка в кавычках");
	printf("\033[42;30mДинамическая область памяти:------------------------------\033[0m\n");
	printf("*pi: %d по адресу \t\t%p\n", *pi, pi);
	printf("%s по адресу \t%p\n", pcl, pcl);
	printf("\033[42;30mАвтоматическая область памяти:----------------------------\033[0m\n");
	printf("auto_store: %d по адресу \t\t%p\n", auto_store, &auto_store);
	printf("%s по адресу \t%p\n", auto_string, auto_string);
	free(pi);
	free(pcl);
	return 0;
}
/*
Weird Algorithm
TASK
Time limit: 1.00 s Memory limit: 512 MB
Consider an algorithm that takes as input a positive integer n. 
If n is even, the algorithm divides it by two, and if n is odd, 
the algorithm multiplies it by three and adds one. 
The algorithm repeats this, until n is one. 
For example, the sequence for n=3 is as follows:
3→10→5→16→8→4→2→1
*/
#define WIDTH 10		// число шагов на строке
int step(int n);
int WeirdAlgorithm(void) {
	int status,n,k=0,l=0;
	printf("Введите целое число(0-конец):"INPUT3);
	while (status = scanf_s("%d", &n) == 1&&n>0) {
		while (n > 1) {
			printf("%d->",n);
			n = step(n);
			k++; 
			if (++l >= WIDTH) {
				l = 0;
				printf("\n");
			}
		}
		printf("(%d шагов)\nВведите целое число(0-конец):"INPUT3,k);
		k =l= 0;
	}
	printf("Конец программы.\n");
}
int step(int n) {
	if (!(n % 2))
		return n / 2;
	else
		return n * 3 + 1;
}
//void ofmouth(int a1[const], int a2[restrict], int n) {	// разрешено стандартом С99
// Ошибка	C2143	синтаксическая ошибка : отсутствие "]" перед "const"
//	int i;
//	i = 111;
//	i = a1[0]+a2[0];
//	//return void;
//}
//
// вопросы для самоконтроля
// 
// 6. Взгляните на следующий фрагмент кода:
int test6(void) {
	int* p1 = (int*)malloc(100 * sizeof(int));
	// Чем от него отличается показанный ниже оператор в смысле конечного результата?
	int* p2 = (int*)calloc(100, sizeof(int));
	int test;
}
// 8. Что выведет следующая программа?
#include <stdio.h>
char color = 'В';
void first(void);
void second(void);
int test8(void)
{
	extern char color;
	printf("1 color в main() равно %c\n", color);
	first();
	printf("2 color в main() равно %c\n", color);
	second();
	printf("3 color в main() равно %c\n", color);
	return 0;
}
void first(void)
{
	char color;
	color = 'R';
	printf("color в first() равно %c\n", color);
}
void second(void)
{
	color = 'G';
	printf("color в second() равно %c\n", color);
}