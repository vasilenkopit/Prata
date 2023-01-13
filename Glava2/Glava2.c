/* platinum, с -- ваш вес в платиновом эквиваленте */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdint>
#include <inttypes.h>
#include <string.h>		// для прототипа функции strlen()
//#include <complex.h>

#define DENSITY 62.4	// удельная масса человека в фунтах на кубический фут
#define PRAISE "Вы - выдающаяся личность."

using namespace std;
int test0(void);
int test1(void);
int test2(void);
int test3(void);
int test4(void);
int test5(void);
int test6(void);
int test7(void);
int test8(void);
int test9(void);
int test10(void);
int test11(void);
int test12(void);
int test13(void);
int test14(void);
int test15(void);
int test16(void);

int main(void)
{
	//SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	//SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	setlocale(LC_ALL, "Russian");
	goto test;
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
test:
	test16();
	//char ch = getchar();
}
int test0(void)
{
	float weight = 0;	/* вес пользователя */
	float value = 0;	/* платиновый эквивалент */
	printf("Хотите узнать свой вес в платиновом эквиваленте?\n");
	printf("Давайте подсчитаем.\n");
	weight = 100;
	printf("Пожалуйста, введите свой вес, выраженный в фунтах: %.2f:", weight);
	int result = scanf_s("%f", &weight);
	/* получить входные данные от пользователя */
	//scanf_s("%f", weight);
	/* считаем, что цена родия равна $1700 за тройскую унцию */
	/* 14.5833 коэффициент для перевода веса, выраженного в фунтах, в тройские унции */
	value = 1700.0 * weight * 14.5833;
	printf("Ваш вес %.2f, а в платиновом эквиваленте составляет $%.2f.\n", weight, value);
	printf("Вы легко можете стать достойным этого! Если цена платины падает,\n");
	printf("ешьте больше для поддержания своей стоимости.\n");
	return 0;
}
int test1(void)
{
		int ten = 10;
		int two = 2;
		printf("\ntest1:\n");
		printf("Выполняется правильно: ");
		printf("%d минус %d равно %d\n", ten, 2, ten - two);
		printf("Выполняется неправильно: ");
		printf("%d минус %d равно %d\n", ten/*, two, ten - two*/); // пропущены 2 аргумента
		return 0;
}
int test2(void)
{
	printf("\ntest2:\n");
		int х = 100;
		long int estine=0;
		long johns = 0;
		short int erns= -32768;
		short ribs= 32767;
		unsigned int s_count= 65535;
		unsigned players= 65535-1;
		unsigned long headcount = 0;
		unsigned short yesvotes = 0;
		long long ago = 0;
		unsigned long long agoll = 0;
		printf("десятичное = %d; восьмеричное = %o; шестнадцатеричное = %x; шестнадцатеричное = %X\n", х, х, х, х);
		printf("десятичное = %d; восьмеричное = %#o; шестнадцатеричное = %#x; шестнадцатеричное = %#X\n", х, х, х, х);
		printf("MIN short int = %d; MAX short int = %#o; шестнадцатеричное = %#x; шестнадцатеричное = %#X\n", s_count, ribs, ribs, ribs);
		return 0;
}
int test3(void)
{
	printf("\ntest3 сецификации unsigned, long, long long:\n");
	unsigned int un = 3000000000; /* система с 32-битным типом int */
	short end = 200; /* и 16-битным типом short */
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un = %u, но не %d\n", un, un);
	printf("end = %hd и %d\n", end, end);
	printf(" ig = % ld, но не% hd\n", big, big);
	printf("veryЬig = %lld, но не %ld\n", verybig, verybig);
	return 0;
}
int test4(void)
{
	printf("\ntest4 сиволы(конец работы ввод символа     z):\n");
	unsigned char ch;
	int numLoop = 0;
loop:	//scanf_s("%c", &ch); /* пользователь вводит символ */
	printf("%d.\tВведите какой-нибудь символ:",++numLoop);
	ch = _getch();
	printf("\tKoд символа %c равен %#uhx.\n", ch, ch);
	if (ch != 'z') goto loop;
	return 0;
}
int test5(void)
{
	printf("\ntest5 Переносимые типы целых leastNN_t fastNN_t intNN_t intmax_t uintmax_t\n");
	int_least8_t lint = 0;
	int_fast8_t fint = 0;
	int32_t i32 = 0;
	intmax_t intMax = 0;
	uintmax_t uintMax = 0;
	int32_t me32 = 0; // me32 -- это 32-битная переменная со знаком
	me32 = 45933945;
	printf("Сначала предположим, что int32_t является int: ");
	printf("me32 = %d\n", me32);
	printf("Далее не будем делать никаких предположений. \n");
	printf("Вместо этого воспользуемся \"макросом\" из файла inttypes.h: ");
	printf("me32 = %" PRId32 "\n", me32);
	return 0;
}
int test6(void)
{
	printf("\ntest6 Переносимые типы целых PRIdLEAST8-PRIdLEAST64 \n");
	/*
	printf("
	PRId8        "hhd"
	PRId16       "hd"
	PRId32       "d"
	PRId64       "lld"
	PRIdLEAST8   PRId8
	PRIdLEAST16  PRId16
	PRIdLEAST32  PRId32
	PRIdLEAST64  PRId64
	PRIdFAST8    PRId8
	PRIdFAST16   PRId32
	PRIdFAST32   PRId32
	PRIdFAST64   PRId64
	PRIdMAX      PRId64
	\n");
	*/
	return 0;
}
int test7(void)
{
	printf("\ntest7 типа float double long double \n");
	//float floHex = 0ха.1fp10;
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f может быть записано как %e\n", aboat, aboat);
	// для вывода следующей строки требуется компилятор,
	// поддерживающий С99 или более поздний стандарт
	printf("И его %a в шестнадцатеричной, представляющей степени 2, форме записи\n", aboat);
	printf("%f может быть записано как %e\n", abet, abet);
	printf("%Lf может быть записано как %Le\n", dip, dip);
	return 0;
}
int test8(void)
{
	printf("\ntest8 Переполнение float выводится inf, либо infinity\n");
	float toobig = 3.4E38;
	printf("Перемножить %e * %e = %e\n", toobig, 100.0f, toobig * 100.0f);
	return 0;

}
int test9(void)
{
	printf("\ntest9 Ошибки округления\n");
	float a, b;
	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf("%f \n", a);
	return 0;
}
int test10(void)
{
	//_Bool log = 1;
	printf("\ntest10 Комплексные числа\n");
	//_Fcomplex fcplx1 = _FCbuild(1, 2);
	//_Fcomplex fcplx2 = _FCbuild(3, 4);
	//double complex z1 = 1.0 + 3.0 * I;
	//double complex z2 = 1.0 - 4.0 * I;
	//_FCmulcc(fcplx1, fcplx2);
	return 0;
}
int test11(void)
{
	printf("\ntest11 размеры типов\n");
	/* В стандарте с99 для размеров предусмотрен спецификатор %zd */
	printf("Тип \t\tРазмер(байт):\n");
	printf("char \t\t%zd\n", sizeof(char));
	printf("int \t\t%zd\n", sizeof(int));
	printf("long \t\t%zd\n", sizeof(long));
	printf("long long \t%zd\n", sizeof(long long));
	printf("double \t\t%zd\n", sizeof(double));
	printf("long double \t%zd\n", sizeof(long double));
	printf("float \t\t%zd\n", sizeof(float));
	printf("long float \t%zd\n", sizeof(long float));
	return 0;
}
int test12(void)
{
	printf("\ntest12 Ошибки типов в printf\n");
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;
	printf("две переменных для одной спец формата. %d\n", n, m);	/*слишком много аргументов * /
	printf("3 формата, но одна переменная. \t%d %d %d\n", n);		/* аргументов недостаточно */
	printf("Формат целого, а переменные float. \t%d %d\n", f, g);	/* неправильные типы значений */
	printf("Формат float, а переменные целые. \t%f %f\n", n, m);	/* неправильные типы значений */
	return 0;
}
int test13(void)
{
	printf("\ntest13 использование управляющих последовательностей\n");
	float salary;
	printf("\aВведите желаемую сумму месячной зарплаты:");	/* 1 \a-звуковой сигнал */
	printf(" $_______\b\b\b\b\b\b\b");						/* 2 \b- возврат на 1 позицию */
	scanf_s("%f", &salary);
	printf("\n\t$%.2f в месяц соответствует $%.2f в год.", salary, 	salary *12.0);		/* 3 \t-табуляция */
	printf("\rOro!\n");			/* 4 \r- в начало строки */
	return 0;
}
int test14(void)
{
	printf("\ntest14 Задачка 1. Переполнения и потеря значимости\n");
	float fMax= 3.402823466e+38F, fMin= 1.175494351e-38F, fEps= 1.192092896e-07F;
	float hMin= SHRT_MIN, hMax= SHRT_MAX;
	short int iMin = SHRT_MIN, iMax = SHRT_MAX;
	printf("float min=%f \t max=%f.\n", fMin, fMax);
	printf("float потеря=%f \t переполнение=%f\n", fMin - fEps, fMax + 1+fEps);
	printf("float min=%f \t max=%f.\n",hMin,hMax);
	printf("float потеря=%f \t переполнение=%f\n", hMin-1, hMax+1);
	printf("int min=%d \t max=%d.\n", iMin, iMax);
	iMin--; iMax++;
	printf("int потеря=%d \t переполнение=%d\n", iMin, iMax);
	return 0;
}
int test15(void)
{
	printf("\ntest15 Задачка 2,3,4. Ввести код символа и распечатать символ\n");
	char c='1';
	int ic;
	float f=0.0;
	//2
	printf("Задачка 2\n");
	printf("Введи код символа:\n");
	scanf_s("%d", &ic);
	printf("Введён код(%d) символа   %c.\n", ic, ic);
	//3
	printf("Задачка 3\n");
	printf("\aНапуганная внезапным звуком, Вика вскрикнула :\n"
	"Во имя всех звезд, что это было!\n");
	//4
	/*Введите значение с плавающей запятой: 64.25
	Запись с фиксированной запятой: 64.250000
	Экспоненциальная форма записи: 6.425000e+Ol
	двоично-экспоненциальное представление: Oxl.Olp+6
	*/
	printf("Задачка 4\n");
	//_getch();
	printf("Введите значение с плавающей запятой:\t");
	scanf_s("%f", &f);
	printf("Запись с фиксированной запятой:\t%f\n", f);
	printf("Экспоненциальная форма записи:\t%e\n", f);
	printf("двоично-экспоненциальное представление:\t%0x.0p\n", f);
	//5
	/*5. В году содержится примерно 3.156х107 секунд. Напишите программу, которая
	нредлагает ввести возраст в годах, а затем выводит на экран эквивалентное значение
	в секундах.	*/
	int years=0;
	long float secInYear = 3.156E107,secs;
	printf("Задачка 5\n");
	printf("Сколько Вам лет:___\b\b\b");
	//_getch();
	scanf_s("%d",&years);
	secs = years * secInYear;
	printf("Вот сколько Вам секунд: \n%Le \n%Lf\n",secs,secs );
	//6
	/*6. Масса одной молекулы воды приблизительно составляет 3.О*10E23 грамм. Кварта
	воды весит примерно 950 грамм. Напишите программу, которая предлагает ввести
	значение объема воды в квартах и отображает количество молекул воды в
	этом объеме.*/
	printf("Задачка 6\n");
	printf("Ввести объём воды(кварт):___\b\b\b");
	float vol = 0.0, weigth= 950;
	long float weigthw = 3.0E-23;
	scanf_s("%f", &vol);
	printf("В этом объёме находится %Le молекул воды.\n", (vol * weigth) / weigthw);
	//7
	/*7. В дюйме имеется 2.54 сантиметра. Напишите программу, которая предлагает
	ввести рост в дюймах, после чего выводит на экран этот рост в сантиметрах.
	Либо, если вам так больше нравится, программа может запрашивать рост в сантиметрах
	и переводить его в дюймы.*/
	float high = 0., d=2.54;
	printf("Задачка 7\n");
	printf("Ввести рост(см):___\b\b\b");
	scanf_s("%f", &high);
	printf("дюймов:%.2f \tметров:%1.2f \tмиллиметров:%.3e\n", high / d, high / 100., high * 10.);
	//8
	/*8. В американской системе единиц измерений объема пинта равна 2 чашкам, чашка
	— 8 унциям, унция — 2 столовым ложкам, а столовая ложка — 3 чайным ложкам.
	Напишите программу, которая предлагает ввести объем в чашках и отображает
	эквивалентные значения в пинтах, унциях, столовых ложках и чайных ложках. 
	Почему для этой программы тип с плавающей запятой подходит больше, чем целочисленный?*/
	int pint_ch = 2, ch_u = 8, u_sl = 2, sl_cl = 3;
	float pint,unch,sl,cl;
	printf("Задачка 8. Единицы измерения объёма в Америке\n");
	printf("Ввести объём вещества(в чашках):");
	scanf_s("%f", &vol);
	pint = vol / pint_ch;
	unch = vol * ch_u;
	sl = unch * u_sl;
	cl = sl * sl_cl;
	printf("Пинты:%.1f \tУнции:%.2f \tСтоловых ложек:%.1f \tЧайных ложек:%.1f.\n", pint, unch, sl, cl);
	return 0;
}
int test16(void)
{
	float weight, volume;
	int size, letters;
	char name[40]; // name представляет собой массив из 40 символов
	//goto NEX;
	printf("Здравствуйте! Как вас зовут?:");
	scanf_s("%s", name);
	printf("Привет, %s, сколько вы весите в фунтах?:", name);
	scanf_s("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("Хорошо, %s, ваш объем составляет %2.2f кубических футов.\n", name, volume);
	printf("К тому же ваше имя состоит из %d букв,\n", letters);
	printf("^ мы располагаем 40 байтами для его сохранения.\n", size);
	//
NEX:
	char name16[40]="Вася";
	printf("Kaк вас зовут? ");
	scanf_s("%s", name16);
	printf("Здравствуйте, %s. %s\n", name16, PRAISE);
	return 0;
}