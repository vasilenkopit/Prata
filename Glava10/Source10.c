#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// Листинг 10.1. Программа day_monl. с
/* day_mon1.c — выводит количество дней в каждом месяце */
#include <stdio.h>
#define MONTHS 12
int day_mon1(void)
{
	const int days[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	const char* names[MONTHS] = { "январь","февраль", "март", "апрель", "май", "июнь", "июль", "август","сентябрь", "октябрь", "ноябрь", "декабрь" };
	int index;
	printf("\n\033[1;4;44mЛистинг 10.1.Программа  day_mon1.c — выводит количество дней в каждом месяце.\033[0m\n");
	printf("\033[4mНомер Месяц     дней\033[0m\n");
	for (index = 0; index < MONTHS; index++)
		printf("%02d    %s \t%2d\n", index + 1,names[index], days[index]);
	printf("\n");
	return 0;
}
// Листинг 10.2-3. Программа no_data.c
/* no_data.c -- неинициализированный массив */
#include <stdio.h>
#define SIZE 4
int no_data(void)
{
	int no_data[SIZE]; /* неинициализированный массив */
	int no_data1[SIZE] = { 1111, 2222 }; /* наполовину неинициализированный массив */
	const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31};
	int sizeD;
	int i;
	printf("\n\033[1;4;44mЛистинг 10.2.Программа  no_data.c -- неинициализированный массив.\033[0m\n");
	printf("\n\033[4m%2s%14s\033[0m\n",	"i", "no_data[i]");
	for (i = 0; i < SIZE; i++)
		printf("%2d%14d\n", i, no_data[i]);
	printf("\n");

	printf("\n\033[1;4;44mЛистинг 10.3.Программа  some_data.c -- наполовину неинициализированный массив.\033[0m\n");
	printf("\n\033[4m%2s%14s\033[0m\n", "i", "no_data1[i]");
	for (i = 0; i < SIZE; i++)
		printf("%2d%14d\n", i, no_data1[i]);
	printf("\n");

	sizeD = sizeof days / sizeof days[0];
	printf("\n\033[1;4;44mЛистинг 10.4.Программа  day_mon2.c -- Длина массива days[] определяется списком инициализации.\033[0m\n");
	printf("Размер массива =%zd байт  Размер одного элемента =%zd байт   Число элементов в массиве =%d.\n\n",sizeof days, sizeof days[0], sizeD);
	for (i = 0; i < sizeD; i++)
		printf("Месяц %2d имеет %d день (дней).\n", i + 1, days[i]);
	printf("\n");
	return 0;
}
// Листинг 10.5.Программа designate.c
// designate.c -- использование назначенных инициализаторов
#include <stdio.h>
#define MONTHS105 12
int designate(void)
{
	int days[MONTHS105] = { 31, 28,[4] = 31, 30, 31,[1] = 29 };
	int i;
	int staff[] = { 1,[6] = 23 };			// что происходит ?
	int staff1[] = { 1,[6] = 4, 9, 10 };	// что происходит?
	int staff2[] = { [11] = 11 };			// что происходит?
	int sizeD;
	printf("\n\033[1;4;44mЛистинг 10.5.Программа  designate.c -- использование назначенных инициализаторов.\033[0m\n");
	printf("инициатор{ 31, 28,[4] = 31, 30, 31,[1] = 29 }\n");
	printf("\n");
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, days[i], days[i]>0?"инициирован":"не инициирован");
	printf("\n");

	printf("инициатор{ 1,[6] = 23 }\n");
	sizeD = sizeof staff / sizeof staff[0];
	printf("Размер массива =%zd байт  Размер одного элемента =%zd байт   Число элементов в массиве =%d.\n\n", sizeof staff, sizeof staff[0], sizeD);
	printf("\n");
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff[i], staff[i]>0 ? "инициирован" : "не инициирован");
	printf("\n");

	printf("инициатор{ 1,[6] = 4, 9, 10 }\n");
	sizeD = sizeof staff1 / sizeof staff1[0];
	printf("Размер массива =%zd байт  Размер одного элемента =%zd байт   Число элементов в массиве =%d.\n\n", sizeof staff1, sizeof staff1[0], sizeD);
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff1[i], staff1[i]>0 ? "инициирован" : "не инициирован");
	printf("\n");

	printf("инициатор{ [11] = 11 }\n");
	sizeD = sizeof staff2 / sizeof staff2[0];
	printf("Размер массива =%zd байт  Размер одного элемента =%zd байт   Число элементов в массиве =%d.\n\n", sizeof staff2, sizeof staff2[0], sizeD);
	for (i = 0; i < MONTHS105; i++)
		printf("%2d %d \t%s\n", i + 1, staff2[i], staff2[i]>0 ? "инициирован" : "не инициирован");
	printf("\n");
	return 0;
}
// Листинг 10.6. Программа tounds. с
// bounds.c -- выход за границы массива
#include <stdio.h>
#define SIZE106 4
int bounds(void)
{
	int value1 = 44;
	int arr[SIZE106];
	int value2 = 88;
	int i;
	printf("\n\033[1;4;44mЛистинг 10.6.Программа  bounds.c -- выход за границы массива.\033[0m\n");
	printf("valuel = %d, value2 = %d\n", value1, value2);
	for (i = -1; i <= SIZE106; i++)
		arr[i] = 2 * i + 1;
	for (i = -1; i < 7; i++)
		printf("%2d %d\n", i, arr[i]);
	printf("valuel = %d, value2 = %d\n", value1, value2);
	printf("адрес arr[-1]: %p\n", &arr[-1]);
	printf("aдpec arr[4]: %p\n", &arr[4]);
	printf("aдpec value1: %p\n", &value1);
	printf("aдpec value2: %p\n", &value2);
	printf("\n\033[31mRun-Time Check Failure #2 - Stack around the variable 'arr' was corrupted.\033[0m\n");
	return 0;
}
// Листинг 10.7. Программа rain.c
/* rain.c -- находит суммарные данные по годам, средние значения за год и средние
значения за месяц по данным об осадках за несколько лет */
#include <stdio.h>
#define MONTHS107 12	// количество месяцев в году
#define YEARS107 5		// количество лет, для которых доступны данные
int rain(void)
{
	// инициализация данн^ыми об осадках за период с 2010 по 2014 гг.
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
	printf("\n\033[1;4;44mЛистинг 10.7.Программа  rain.c -- находит суммарные данные по годам, средние значения за год и средние.\033[0m\n");
	printf("ГОД КОЛИЧЕСТВО ОСАДКОВ (в дюймах)\n");
	for (year = 0, total = 0; year < YEARS107; year++)
	{ // для каждого года суммировать количество осадков за каждый месяц
		for (month = 0, subtot = 0; month < MONTHS107; month++)
			subtot += rain[year][month];
		printf("%5d %15.1f\n", 2010 + year, subtot);
		total += subtot;				// общая сумма для всех лет
	}
	printf("\nСреднегодовое количество осадков составляет %.1f дюймов. \n\n", total / YEARS107);
	printf("СРЕДНЕМЕСЯЧНОЕ КОЛИЧЕСТВО ОСАДКОВ:\n\n");
	printf(" Янв \tФев \tМар \tАпр \tМай \tИюн \tИюл \tАвг \tСен \tОкт");
	printf(" \tНоя \tДек\n");
	for (month = 0; month < MONTHS107; month++)
	{ // для каждого месяца суммировать количество осадков на протяжении годов
		for (year = 0, subtot = 0; year < YEARS107; year++)
			subtot += rain[year][month];
		printf("%4.1f\t", subtot / YEARS107);
	}
	printf("\n\n");
	return 0;
}
//Листинг 10.8. Программа pnt_add.c
// pnt_add.c -- сложение указателей
#include <stdio.h>
#define SIZE108 4
int pnt_add(void)
{
	short dates[SIZE108];
	short* pti;
	short i;
	double bills[SIZE108];
	double* ptf;
	pti = dates;			// присваивание указателю адреса массива
	ptf = bills;
	printf("\n\033[1;4;44mЛистинг 10.8.Программа  pnt_add.c -- сложение указателей.\033[0m\n");
	printf("%23s %15s\n", "short", "double");
	for (i = 0; i < SIZE108; i++)
		printf("указатели + %d: %10p %10p\n", i, pti + i, ptf + i);
	printf("\n\n");
return 0;
}
// Листинг 10.9. Программа day_mon3.c
/* day_mon3.c -- использование формы записи с указателями */
#include <stdio.h>
#define MONTHS109 12
int day_mon3(void)
{
	int days[MONTHS109] = { 31, 28,31, 30, 31,30,31, 31, 30, 31, 30, 31 };
	int index;
	printf("\n\033[1;4;44mЛистинг 10.9.Программа day_mon3.c -- использование формы записи с указателями .\033[0m\n");
	for (index = 0; index < MONTHS109; index++)
	printf("Mecяц %2d имеет %d день (дней).\n", index + 1, *(days + index)); // то же самое, что и days[index]
	printf("\n\n");
	return 0;
}
// Листинг 10.10. Программа sum_arr1.c
// sum_arr1.с -- сумма элементов массива
// используйте спецификаторы %и или %1и, если %zd не работает
#include <stdio.h>
#define SIZE1010 10
int sum1010(int ar[], int n);
int sump1011(int* start, int* end);
int sum_arr1(void)
{
	int marbles[SIZE1010] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
	long answer;
	printf("\n\033[1;4;44mЛистинг 10.10.Программа sum_arr1.с -- сумма элементов массива.\033[0m\n");
	answer = sum1010(marbles, SIZE1010);
	printf("Общая сумма элементов массива marbles равна %ld.\n", answer);
	printf("Объем памяти, отведенной под массив marbles, составляет %zd байтов размер объекта int %zd байт.\n", sizeof marbles, sizeof( int));
	
	printf("\n\033[1;4;44mЛистинг 10.11.Программа sum_arr2.с -- сумма элементов массива указателями.\033[0m\n");
	answer = sump1011(marbles, marbles+SIZE1010);
	printf("Общая сумма элементов массива marbles равна %ld.\n", answer);
	printf("\n\n");
	return 0;
}
int sum1010(int ar[], int n) // насколько велик массив?
{
	int i;
	int total = 0;
	for (i = 0; i < n; i++)
		total += ar[i];
	printf("Paзмep ar составляет %zd байтов.\n", sizeof ar);
	return total;
}
/* использование арифметики указателей */
int sump1011(int* start, int* end)
{
	int total = 0;
	while (start < end)
	{
		total += *start++;	// добавить значение к total
		//start++;			// переместить указатель на следующий элемент
	}
	return total;
}
// Листинг 10.12. Программа order.с
/* order.c — приоритеты в операциях с указателями */
#include <stdio.h>
int data[2] = { 100, 200 };
int moredata[2] = {300, 400};
int order(void)
{
	int* p1, * р2, * рЗ;
	p1 = р2 = data;
	рЗ = moredata;
	int data1[2] = { 10, 20 };
	int moredata1[2] = {30, 40};
	printf("\n\033[1;4;44mЛистинг 10.12.Программа order.c — приоритеты в операциях с указателями.\033[0m\n");
	printf(" *p1   = %d, *р2   = %d, *рЗ     = %d\n", *p1,   *р2,   *рЗ);
	printf(" *p1++ = %d, *++р2 = %d, (*рЗ)++ = %d\n", *p1++, *++р2, (*рЗ)++);
	printf(" *p1   = %d, *р2   = %d, *рЗ     = %d\n", *p1,   *р2,   *рЗ);
	
	p1 = р2 = data1;
	рЗ = moredata1;
	printf("\nА теперь для локальных массивов\n");
	printf(" *p1   = %d, *р2   = %d, *рЗ     = %d\n", *p1,   *р2,   *рЗ);
	printf(" *p1++ = %d, *++р2 = %d, (*рЗ)++ = %d\n", *p1++, *++р2, (*рЗ)++);
	printf(" *p1   = %d, *р2   = %d, *рЗ     = %d\n", *p1,   *р2,   *рЗ);
	printf("\n\n");
	return 0;
}
// Листинг 10.13. Программа ptr_ops. с
// ptr_ops.с -- операции над указателями
#include <stdio.h>
int ptr_ops(void)
{
	int urn[5] = { 100, 200, 300, 400, 500 };
	int* ptr1, *ptr2, *ptr3=NULL;
	ptr1 = urn;		// присваивание указателю адреса
	ptr2 = &urn[2]; // то же самое
	ptr3 = urn + 4;
	printf("\n\033[1;4;44mЛистинг 10.13.Программа  ptr_ops.с -- операции над указателями.\033[0m\n");
	// разыменование указателя и получение адреса указателя
	printf("значение указателя,      разыменованный указатель, адрес указателя:\n");
	printf("ptr1 = %p,  *ptr1 = %d,             &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	printf("ptr2 = %p,  *ptr2 = %d,             &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	printf("ptr3 = %p,  *ptr3 = %d,             &ptr3 = %p\n", ptr3, *ptr3, &ptr3);
	// сложение указателей
	ptr3 = ptr1 + 4;
	printf("\nсложение значения int с указателем: \n");
	printf("ptr1 + 4 = %p, *(ptr4+3) = %d, *ptr4+3 = %d\n", ptr1 + 4, *(ptr1 + 3), *ptr1 + 3);
	ptr1++;		// инкрементирование указателя
	printf("\nзначения после выполнения операции ptr1++ : \n");
	printf("ptr1 = %p, *ptr1 = %d, &ptr1 = %p\n", ptr1, *ptr1, &ptr1);
	ptr2--;		// декрементирование указателя
	printf("\nзначения после выполнения операции --ptr2:\n");
	printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n", ptr2, *ptr2, &ptr2);
	-- ptr1;	// восстановление исходного значения
	++ptr2;		// восстановление исходного значения
	printf("\nвосстановление исходных значений указателей:\n");
	printf("ptr1 = %p, ptr2 = %p\n", ptr1, ptr2);
	// вычитание одного указателя из другого
	printf("\nвычитание одного указателя из другого:\n");
	printf("ptr2 = %p, ptr1 = %p, ptr2-ptr1 = %td\n",	ptr2, ptr1, ptr2 - ptr1);
	// вычитание целого значения из указателя
	printf("\nвычитание из указателя значения типа int:\n");
	printf("ptr3 = %p, ptr3-2 = %p\n", ptr3, ptr3 - 2);
	return 0;
}
// Листинг 1О.14. Программа a r f . с
/* arf.c -- функции, манипулирующие массивами */
#include <stdio.h>
#define SIZE1014 5
void show_array(const double ar[], int n);
void mult_array(double ar[], int n, double mult);
int arf(void)
{
	double dip[SIZE1014] = { 20.0, 17.66, 8.2, 15.3, 22.22 };
	printf("\n\033[1;4;44mЛистинг 10.14.Программа  arf.c -- функции, манипулирующие массивами.\033[0m\n");
	printf("Исходный массив dip:\n");
	show_array(dip, SIZE1014);
	mult_array(dip, SIZE1014, 100.);
	printf("Массив dip после вызова функции mult_array():\n");
	show_array(dip, SIZE1014);
	return 0;
}
/* выводит содержимое массива */
void show_array(const double ar[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%8.3f ", ar[i]);
	putchar('\n');
}
/* умножает каждый элемент массива на один и тот же множитель */
void mult_array(double ar[], int n, double mult)
{
	int i;
	for (i = 0; i < n; i++)
		ar[i] *= mult;
}
// Листинг 10.15. Программа zippol.с
/* zippo1.c -- информация о массиве zippo */
#include <stdio.h>
int zippo1(void)
{
	int zippo[4][2] = { {100, 1}, {10, 11}, {20, 21}, {30, 31} },i,j;
	printf("\n\033[1;4;44mЛистинг 10.15.Программа zippo1.c -- информация о массиве zippo.\033[0m\n");
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
// Листинг 10.16. Программа zipppo2. с
/* zippo2.c -- получение информации о массиве zippo с помощью переменной типа указателя */
#include <stdio.h>
int zippo2(void)
{
	int zippo[4][2] = { {100, 1}, {10, 11}, {20, 21}, {30, 31} },i,j;
	int(*pz)[2];
	pz = zippo;
	printf("\n\033[1;4;44mЛистинг 10.16.Программа zippo2.c -- получение информации о массиве zippo с помощью переменной типа указателя.\033[0m\n");
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
	printf("Оператор; pp                &pp               p                 &p                &n                n\n");
	pp = &p;					// разрешено, но квалификатор const игнорируется
	printf("pp = &p;  %p  %p  %p  %p  %p  %d\n",pp, &pp, p,&p,&n,n);
	*pp = &n;					// допустимо, оба const, но pl устанавливается указывающим на n
	printf("*pp = &n; %p  %p  %p  %p  %p  %d\n", pp, &pp, p, &p, &n, n);
	*p = 10;					// допустимо, но производится попытка изменить константу n
	printf("*p = 10;  %p  %p  %p  %p  %p  %d\n", pp, &pp, p, &p, &n, n);
	printf("**pp=%d\n\n",**pp);
	printf("Пример изменения константы\n");
	const int y;
	const int* p2 = &y;
	int* p1;
	p1 = p2;					// ошибка в C + + , возможное предупреждение в С
	*p1= 1234567890;
	//*p2 = 112345678;
	printf("y=%d\n", y);
	return 0;
}
// Листинг 1О.17. Программа array2d.c
// array2d.c -- функции для двумерных массивов
#include <stdio.h>
#define ROWS 3
#define COLS 4
void sum_rows(int ar[][COLS], int rows);
void sum_cols(int[][COLS], int);				// имена можно опустить
int sum2d(int(*ar)[COLS], int rows);			// другой синтаксис
int array2d(void)
{
	int junk[ROWS][COLS] = {
		{1, 2, 3, 4},
		{10, 20, 30, 40},
		{100, 200, 300, 400}
	};
	printf("\n\033[1;4;44mЛистинг 10.17.Программа array2d.c -- функции для двумерных массивов.\033[0m\n");
	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Сумма всех элементов = %d\n", sum2d(junk, ROWS));
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
	printf("строка %d: сумма = %d\n", r, tot);
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
		printf("столбец %d: сумма = %d\n", c, tot);
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
/*	Не компилируются массивы переменной длины VLA * /
#define __STDC_VLA__
// Листинг 10.18. Программа vararr2d. с
//vararr2d.c -- функции, использующие массивы переменной длины
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
	int varr[rs][cs]; // массив переменной длины
	printf("\n\033[1;4;44mЛистинг 10.18.Программа vararr2d.c -- функции, использующие массивы переменной длины.\033[0m\n");
	for (i = 0; i < rs; i++)
		for (j = 0; j < cs; j++)
			varr[i][j] = i * j + j;
	printf("Традиционный массив 3x5\n");
	printf("Сума всех элементов = %d\n",
		sum2d1018(ROWS1018, COLS1018, junk));
	printf("Традиционный массив 2x6\n");
	printf("Сума всех элементов = %d\n",
		sum2d1018(ROWS1018 - 1, COLS1018 + 2, morejunk));
	printf("Массив переменной длины 3x10\n");
	printf("Сма всех элементов = %d\n",
		sum2d1018(rs, cs, varr));
	return 0;
}
// функция с параметром типа массива переменной длины
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
// Листинг 10.19. Программа flc.c
// flc.c -- забавно выглядящие константы
#include <stdio.h>
#define COLS19 4
int sum2d19(const int ar[][COLS19], int rows);
int sum19(const int ar[], int n);
int flc(void)
{
	int total1, total2, total3;
	int* pt1;
	int(*pt2)[COLS19];
	printf("\n\033[1;4;44mЛистинг 10.19.Программа flc.c -- забавно выглядящие константы.\033[0m\n");
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