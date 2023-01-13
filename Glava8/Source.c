// Листинг 8.1.Программа echo.с
/* echo.c -- повторяет ввод */
#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

int echo(void)
{
	char ch,str[1000];
	int i=0,j;
	printf("\n\033[1;4;44mЛистинг 8.1.Программа  echo.c -- повторяет ввод до #\033[0m\n");
	printf("Вводите:\n");
	while ((ch = getchar()) != '#')
		putchar(ch);
	printf("\nВводите небуфферизованный ввод с эхо:\n");
	while ((str[i] = getche()) != '#'&& ++i<1000);
	str[i] = '\n';	//putchar(ch);
	printf("\nВвелось:\n");
	for(j=0;j<i;j++) printf("%c", str[j]);
	printf("\nВводите небуфферизованный ввод без эхо:\n");
	while ((str[i] = getch()) != '#' && ++i < 1000);
	str[i] = '\n';	//putchar(ch);
	printf("\nВвелось:\n");
	for (j = 0; j < i; j++) printf("%c", str[j]);
	printf("\nКонец программы.");
return 0;
}
// Листинг 8.2. Программа echo_e o f . с
/* echo_eof.c - повторяет на экране ввод до достижения конца файла */
#include <stdio.h>
int echo_eof(void) {
	int ch;
	printf("\n\033[1;4;44mЛистинг 8.2.Программа  echo_eof.c - повторяет на экране ввод до достижения конца файла EOF.\033[0m\n");
	printf("Вводите:\n");
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
// Листинг8.3. Программа f ile _ e o f .с
// file_eof.c -- открывает файл и отображает его содержимое
#include <stdio.h>
#include <stdlib.h> // для функции exit О
int file_eof()
{
	int ch;
	FILE* fp;
	errno_t err;
	char fname[50];				// для хранения имени файла
	printf("\n\033[1;4;44mЛистинг 8.3.Программа  file_eof.c -- открывает файл и отображает его содержимое.\033[0m\n");
	printf("Введите имя файла:");
	scanf_s("%s", fname,49);
	//fname = "F:\\Учёба\\C\\Pratta\\x64\\Debug.glava8.txt";
	err=fopen_s(&fp,fname, "a");		// открыть файл для r-чтения a-доавления
	if (fp == NULL)				// попытка завершилась неудачей
	{
		printf("Не удается открыть файл. Программа завершена.\n");
		exit(1);				// выйти из программы
	}
	printf("Содержимое файла %s\n", fname);
	printf("============================================================\n");
	// функция getc(fp) получает символ из открытого файла
	while ((ch = getc(fp)) != EOF)
		putchar(ch);
	printf("============================================================\n");
	fclose(fp);					// закрыть файл
	return 0;
}
// Листинг 8.4. Программа g u e s s . с
/* guess.c — неэффективное и чреватое ошибками угадывание числа */
#include <stdio.h>
int guess(void)
{
	int guess = 1;
	printf("\n\033[1;4;44mЛистинг 8.4.Программа  — неэффективное и чреватое ошибками угадывание числа.\033[0m\n");
	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать ");
	printf("его. \nНажмите клавишу y, если моя догадка верна и ");
	printf("\nклавишу n в противном случае.\n");
	printf("Вашим числом является %d?\n", guess);
	while (getchar() != 'y')					/* получить ответ, сравнить с y */
		printf("Ладно, тогда это %d?\n", ++guess);
	printf("Я знал, что у меня получится!\n");
	return 0;
}
// Листинг 8.4. Программа g u e s s . с
/* guess.c — неэффективное и чреватое ошибками угадывание числа */
#include <stdio.h>
int guess1(void)
{
	int guess = 1;
	char response;
	printf("\n\033[1;4;44mЛистинг 8.4-1.Программа  — неэффективное и чреватое ошибками угадывание числа.\033[0m\n");
	printf("Выберите целое число в интервале от 1 до 100. Я попробую угадать ");
	printf("его. \nНажмите клавишу y, если моя догадка верна и ");
	printf("\nклавишу n в противном случае.\n");
	printf("Вашим числом является %d?\n", guess);
	while ((response = getchar()) != 'y')		/* получить ответ */
	{
		if (response == 'n')
			printf("Лaднo, тогда это % d ? \n", ++guess);
		else
			printf("Принимаются только варианты y или n.\n");
		while (getchar() != '\n')
			continue;							/* пропустить оставшуюся часть входной строки*/
	}	
	printf("Я знал, что у меня получится!\n");
	return 0;
}
// Листинг 8.5. Программа showcharl. с
/* showchar1.c -- программа с крупной проблемой ввода-вывода */
#include <stdio.h>
void display(char cr, int lines, int width);
int showchar1(void)
{
	int ch;					/*выводимый символ */
	int rows, cols;			/* количество строк и столбцов */
	printf("\n\033[1;4;44mЛистинг 8.5.Программа  showchar1.c -- программа с крупной проблемой ввода-вывода.\033[0m\n");
	printf("Bвeдитe символ и два целых числа : \n");
	while ((ch = getchar()) != '\n')
	{
		scanf_s("%d %d", &rows, &cols);
		display(ch, rows, cols);
		printf("Bвeдитe еще один символ и два целых числа; \n");
		printf("для завершения введите символ новой строки.\n");
	}
	printf("Пporpaммa завершена.\n");
	return 0;
}
// Листинг 8.6. Программа showchar2 . с
/* showchar2.c -- выводит символы в строках и столбцах */
#include <stdio.h>
void display(char cr, int lines, int width);
int showchar2(void)
{
	int ch; /* вывод1^имый символ */
	int rows, cols; /* количество строк и столбцов */
	printf("\n\033[1;4;44mЛистинг 8.6.Программа  showchar2.c -- исправлена проблема ввода-вывода.\033[0m\n");
	printf("Введите символ и два целых числа:\n");
	while ((ch = getchar()) != '\n')
	{
		if (scanf_s("%d %d", &rows, &cols) != 2)
			break;
		display(ch, rows, cols);
		while (getchar() != '\n')
			continue;
		printf("Введите еще один символ и два целых числа;\n");
		printf("для завершения введите символ новой строки.\n");
	}
	printf("Пpoгpaммa завершена.\n");
	return 0;
}
void display(char cr, int lines, int width)
{
	int row, col;
	for (row = 1; row <= lines; row++)
	{
		for (col = 1; col <= width; col++)
			putchar(cr);
		putchar('\n'); /* закончить строку и начать новую */
	}
}

// Листинг 8.7. Программа checking. с
// checking.c — проверка допустимости ввода
#include <stdio.h>
#include <stdbool.h>
// проверка, является ли ввод целочисленным
long get_long(void);
// проверка, допустимы ли границы диапазона
bool bad_limits(long begin, long end, long low, long high);
// вычисление суммы квадратов целых чисел от а до Ь
double sum_squares(long а, long Ь);
int checking(void)
{
	const long MIN = -10000000L;			// нижний предел диапазона
	const long МАХ = +10000000L;			// верхний предел диапазона
	long start;								// начало диапазона
	long stop;								// конец диапазона
	double answer;
	printf("Эта программа вычисляет сумму квадратов "
		"целых чисел в заданном диапазоне. \nНижняя граница не должна "
		"быть меньше -10000000, \na верхняя не должна быть "
		"больше + 10000000. \nвведите значения "
		"пределов (для завершения введите 0 для обоих пределов):\n"
		"нижний предел: "INPUT3);
	start = get_long();
	printf("верхний предел: "INPUT3);
	stop = get_long();
	while (start != 0 || stop != 0)
	{
		if (bad_limits(start, stop, MIN, МАХ))
			printf("Повторите попытку.\n");
		else
		{
			answer = sum_squares(start, stop);
			printf("Cумма квадратов целых чисел ") ;
			printf("oт %ld до %ld равна %g\n", start, stop, answer);
		}
		printf("Введите значения пределов (для завершения "
			"введите 0 для обоих пределов): \n");
		printf("нижний предел: "INPUT3);
		start = get_long();
		printf("вepxний предел: "INPUT3);
		stop = get_long();
	}
	printf("Пpoгpaммa завершена.\n");
	return 0;
}
long get_long(void)
{
	long input;
	char ch;
	while (scanf_s("%ld", &input) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);			// отбросить неправильный ввод
		printf(" не является целочисленным.\nВведите ");
		printf("цeлoe число, такое как 25, -178 или 3: ");
	}
	return input;
}
double sum_squares(long a, long Ь)
{
	double total = 0;
	long i;
	for (i = a; i <= Ь; i++)
		total += (double)i * (double)i;
	return total;
}
bool bad_limits(long begin, long end, long low, long high)
{
	bool not_good = false;
	if (begin > end)
	{
		printf("%ld не меньше чем %ld.\n", begin, end);
		not_good = true;
	}
	if (begin < low || end < low)
	{
		printf("Значения должны быть равны %d или больше.\n", low);
		not_good = true;
	}
	if (begin > high || end > high)
	{
		printf("Значения должны быть равны %d или меньше.\n", high);
		not_good = true;
	}
	return not_good;
}
// Листинг 8.8. Программа menuette. с
/* menuette.c — технология меню */
#include <stdio.h>
char get_choice(void);
char get_first(void);
int get_int(void);
void count(void);
int menuette(void)
{
	int choice;
	//void count(void);
	printf("\n\033[1;4;44mЛистинг 8.8.Программа  menuette.c -- меню исправлена проблема ввода-вывода.\033[0m\n");
	while ((choice = get_choice()) != 'в')
	{
		switch (choice)
		{
		case 'с': printf("Покупайте дешево, продавайте дорого.\n");
			break;
		case 'з': putchar('\a'); /* ANSI */
			break;
		case 'п': count();
			break;
		default: printf("Ошибка! \n");
			break;
		}
	}
	printf("nporpaммa завершена. \n");
	return 0;
}
void count(void)
{
	int n, i;
	printf("До какого предела вести подсчет? Введите целое число:\n");
	n = get_int();
	for (i = 1; i <= n; i++)
		printf("%d\n", i);
	while (getchar() != '\n')
		continue; 
}
char get_choice(void)
{
	int ch;
	printf("Bвeдитe букву, соответствующую выбранному варианту:\n");
	printf("с.совет		з.звонок \n");
	printf("п.подсчет	в.выход\n");
	ch = get_first();
	while (ch != 'с' && ch != 'з' && ch != 'п' && ch != 'в')
	{
		printf("Bыбepитe с, з, п или в.\n");
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
			putchar(ch); // отбросить неправильный ввод
		printf(" не является целочисленным.\nВведите ");
		printf("цeлoe число, такое как 25, -178 или 3: ");
	}
	return input;
}