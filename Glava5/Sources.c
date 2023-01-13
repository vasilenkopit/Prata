/* shoesl.c -- преобразует размер обуви в дюймы */
#include <stdio.h>
#define ADJUST 7.31 // один из видов символической константы
int shoes1(void)
{
	const double SCALE = 0.333; // еще один вид символической константы
	double shoe, foot;
	printf("\n\033[41;1;4mПрограмма shoes1.\033[0m\n");
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("Размер обуви(мужской) длина ступни\n" ) ;
	printf("%10.1f %20.2f дюймов\n", shoe, foot);
	return 0;
}
/* shoes2.c -- вычисляет длину стопы для нескольких размеров обуви */
int shoes2(void)
{
	const double SCALE = 0.333; // еще один вид символической константы
	double shoe, foot;
	printf("\n\033[41;1;4mПрограмма shoes2.\033[0m\n");
	printf("\nРазмер обуви(мужской) длина ступни\n");
	shoe = 3.0;
	while (shoe < 18.5) /* начало цикла while */
	{ /* начало блока */
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %20.2f даймов\n", shoe, foot);
		shoe = shoe + 1.0;
	} /* конец блока */
	printf("Если обувь подходит, носите ее.\n");
	return 0;
}

/* wheat.c — экспоненциальный рост */
#define SQUARES 64 // количество клеток шахматной доски
int wheat(void)
{
	const double CROP = 2E16; // мировой урожай пшеницы в зернах
	double current, total;
	int count = 1;
	printf("\n\033[41;1;4mПрограмма о мудреце и шахматах с пшеницей wheat.\033[0m\n");
	printf("квадрат      добавлено    итого       пpoцeнт от \n");
	printf("             зерен        зерен       мирового урожая\n");
	total = current = 1.0;		/* начинаем с одного зернышка */
	printf("%7d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;
		/* удвоить количество зерен на следующей клетке */
		total = total + current; /* обновить итоговую сумму */
		printf("%7d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	}
	printf("Вот и все.\n");
return 0;
}
int divide(void)
/* divide.c -- деление, каким мы его знаем */
{
	printf("\n\033[41;1;4mПрограмма деления чисел divide.\033[0m\n");
	printf("Целочисленное деление: 5/4 равно %d \n", 5 / 4);
	printf("Целочисленное деление: 6/3 равно %d \n", 6 / 3);
	printf("Целочисленное деление: 7/4 равно %d \n", 7 / 4);
	printf("Дeлeниe с плавающей запятой: 7./4. равно %1.2f \n", 7. / 4.);
	printf("Cмeшaннoe деление: 7./4 равно %1.2f \n", 7. / 4);
	return 0;
}
/* rules.c - - проверка приоритетов */
int rules(void)
{
	int top, score;
	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("\033[7mtop = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3))\033[0m top = %d, score = %d\n", top, score);
	return 0;
}
// sizeof.c — использование операции sizeof
// в примере применяется определенный в стандарте с99 модификатор %z; если в вашей
// системе модификатор %zd не поддерживается, попробуйте вместо него %и или %lu
int psizeof(void)
{
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n = %d, n состоит из %zd байтов; все значения int имеют %zd байтов.\n",	n, sizeof n, intsize);
	return 0;
}
// min_sec.с -- переводит секунды в минуты и секунды
#define SEC_PER_MIN 60 // количество секунд в минуте
int min_sec(void)
{
	int sec, min, left;
	printf("Пepeвoд секунд в минуты и секунды!\n");
	printf("Введите количество секунд (<=О для выхода):\n");
	scanf_s("%d", &sec); // чтение количества секунд
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN; // усеченное количество минут
		left = sec % SEC_PER_MIN; // количество секунд в остатке
		printf("%d секунд - это %d минут(ы) %d секунд.", sec,	min, left);
		printf("Введите следующее значение (<=О для выхода):\n");
		scanf_s("%d", &sec);
	}
printf("Готово!\n");
return 0;
}

/* post_pre.c — постфиксная и префиксная формы */
int post_pre(void)
{
	int а = 1, Ь = 1;
	int a_post, pre_a;
	printf("\033[41;1;4mpost_pre.c Постфиксная и префиксная формы\033[0m\n");
	a_post = а++; // значение а++ во время этапа присваивания
	pre_a = ++а; // значение ++Ь во время этапа присваивания
	printf("a\t a_post\t pre_a \n");
	printf("%ld\t %5d\t %5d\n", а, a_post, pre_a);
	return 0;
}
/* Проблеммы инкремента */
int incProblem(void)
{
	int num = 0;
	printf("\033[41;1;4Проблемы инкремента\033[0m\n");
	printf("\033[1;• Не применяйте операцию инкремента или декремента к переменной, которая является частью более чем одного аргумента функции.\n");
	printf("• Не используйте операцию инкремента или декремента с переменной, которая появляется в выражении более одного раза.\033[0m\n");
	printf("1. Компилятор языка С может самостоятельно решать, какой аргумент функции printf вычислять первым.\n");
	while (num < 21)
	{
		printf("\t%10d\t %10d\n", num, num * num++);
	}
	printf("2. компилятор может выполнять действия не в том порядке, который вы имели в виду.\n");
	int ans;
	ans = num / 2 + 5 * (1 + num++);
	printf("\t%10d\t %10d\n", num, ans);
	printf("3. стандарт С не регламентирует, каким должен быть результат у = n++ + n++;.\n");
	int n=3, y;
	y = n++ + n++;
	printf("\t%10d\t %10d\n", n, y);
}
/* addemup.c — пять видов операторов */
int addemup(void) /* находит суму первых 20 целых чисел */
{
	int count, sum; /* оператор объявления */
	printf("\033[41;1;4mОператоры. находит суму первых 20 целых чисел\033[0m\n");
	count = 0; /* оператор присваивания */
	sum = 0; /* оператор присваивания */
	while (count++ < 20) /* оператор */
		sum = sum + count; /* while */
	printf("sum = %d\n", sum); /* оператор вызова функции */
	return 0; /* оператор возврата */
}
/* convert.c -- автоматическое преобразование типов */
int convert(void)
{
	char ch;
	int i;
	float fl;
	printf("\033[41;1;4mconvert.c -- автоматическое преобразование типов\033[0m\n");
	fl = i = ch = 'C';
	printf("ch = %c(%#x), i = %d, fl = %.2f\n", ch, ch, i, fl);
	ch = ch + 1;
	i = fl + 2 * ch;
	fl = 2.0 * ch + i;
	printf("ch = %с(%#x), i = %d, fl = %.2f\n", ch, ch, i, fl);
	ch = 1107;
	printf("Теперь ch = %c(%#x)\n", ch, ch);
	ch = 80.89;
	printf("Теперь ch = %c(%#x)\n", ch, ch);
	return 0;
}
/* pound.с -- определяет функцию с аргументом */
void pound(int n); // объявление прототипа функции согласно стандарту ANSI
int call_pound(void)
{
int times = 5;
char ch = ' ! ';
float f = 6.0f;
// ASCII-код равен 33
printf("\033[41;1;4mpound.с -- определяет функцию с аргументом.\033[0m\n");
printf("Стандарт С99:\tАргумент - это фактический параметр\n\t\tПараметр - это формальный параметр\n");
printf("\t\tПрототип — это объявление функции, c описанием возвращаемого значения функции и всех ее аргументов.\n");
for (int k = 0; k < 5; k++)for (int i = 0; i < 10; i++) if (i == 0) printf("%1d", k); else printf("."); printf("\n");
pound(times); // аргумент типа int
pound(ch); // эквивалентно pound((int)ch);
pound(f);
return 0;
}
// эквивалентно pound((int) f) ;
void pound(int n) // заголовок функции в стиле ANSI, который указывает,
{ // что функция принимает один аргумент int
	while (n-- > 0)
		printf("#");
printf("\n");
}
/* running.с */
const int	 S_PER_M = 60;		// количество секунд в минуте
const int	 S_PER_H = 3600;	// количество секунд в часе
const double M_PER_K = 0.62137; // количество миль в километре
int running(void)
{
	double distk, distm;
	double rate;
	int min, sec;
	int time;
	double mtime;
	int mmin, msec;
	// дистанция пробега в километрах и милях
	// средняя скорость в милях в час
	// время пробега в минутах и секундах
	// время пробега только в секундах
	// время пробега одной мили в секундах
	// время пробега одной мили в минутах и секундах
	printf("\033[41;1;4mrunning.с -- преобразует время пробега дистанции.\033[0m\n");
	printf("Эта програма преобразует время пробега дистанции в метрической системе\n");
	printf("во время пробега одной мили и вычисляет вашу среднюю");
	printf(" cкоpocть в милях в час\n");
	printf("Введите дистанцию пробега в километрах:___\b\b\b");
	scanf_s("%lf", &distk);			// %lf для типа double
	printf("Bвeдитe время в минутах и секундах(через пробел):___ ___\b\b\b\b\b\b\b");
	//printf("Haчнитe с ввода минут.\n");
	scanf_s("%d %d", &min, &sec);
	//printf("Теперь введите секунды.\n");
	//scanf("%d", &sec);
	// переводит время в секунды
	time = S_PER_M * min + sec;
	// переводит километры в мили
	distm = M_PER_K * distk;
	// умножение миль в секунду на количество секунд в часе дает количество миль в час
	rate = distm / time * S_PER_H;
	// деление времени на расстояние дает время пробега одной мили
	mtime = (double)time / distm;
	mmin = (int)mtime / S_PER_M; // вычисление полного количества минут
	msec = (int)mtime % S_PER_M; // вычисление остатка в секундах
	printf("Вы пробежали %1.2fкм(%1.2fмили) за %dмин,%dсек\n", distk, distm, min, sec);
	printf("Такая скорость соответствует пробегу одной мили за %dмин,", mmin);
	printf("%dсек.\nВаша средняя скорость составила %1.2fмиль/сек(%1.2fкм/час).\n", msec, rate, distk /(time/ (double)S_PER_H));
	return 0;
}