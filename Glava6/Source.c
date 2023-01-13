/* Листинг 6.1. summing.c -- суммирует целые числа, вводима в интерактивном режиме */
#include <stdio.h>
int summing(void)
{
	long num;
	long sum = 0L; /* инициализация переменной surn нулем */
	int status;
	printf("\n\033[41;1;4mПрограмма summing.\033[0m\n");
	printf("Введите целое число для последующего суммирования ");
	printf("(или q для завершения программы):___\b\b\b");
	status = scanf_s("%ld", &num);
	while (status == 1)				/* == обозначает равенство */
	{
		sum = sum + num;
		printf("Введите следующее целое число (или q для завершения программы):___\b\b\b");
		status = scanf_s("%ld", &num);
	}
	printf("Сумма введенных целых чисел равна %ld.\n", sum);
	return sum;
}
// Листинг 6.2.Программа when.с
// when.c -- когда цикл завершается?
int when(void)
{
	int n = 5,loop=10,i=0;
	printf("\n\033[41;1;4mПрограмма when.c -- когда цикл завершается?.\033[0m\n");
	while (n++ < loop)					// строка 7
	{
		printf("Выполнение тела цикла %d раз. \nn = %d\n",++i, n);
		n++;							// строка 10
		printf("Теперь n = %d\n", n);	// строка 11
	}
	printf("Цикл завершен.\n");
	return 0;
}
// Листинг 6.3.Программа whilel.с
/* while1.c -- следите за фигурными скобками */
/* неправильное кодирование может приводить к бесконечному циклу */
int while1(void)
{
	int n = 0,i=0;
	printf("\n\033[41;1;4mПрограмма while1.c -- следите за фигурными скобками. зациклилась.\033[0m\n");
	while (n < 3)
		{printf("n равно %d\n", n); if (i++ > 20) break;}
		n++;
	printf("Это все, что делает данная программа.\n");
	return 0;
}
// Листинг 6.4.Программа while2.с
/* while2.c -- правильно расставляйте точки с запятой */
int while2(void)
{
	int n = 0;
	printf("\n\033[41;1;4mПрограмма while2.c -- правильно расставляйте точки с запятой. нет тела цикла.\033[0m\n");
	while (n++ < 3);				/* строка 7 */
	printf("n равно %d\n", n);		/* строка 8 */
	printf("Это все, что делает данная программа.\n");
	return 0;
}
// Листинг 6.5.Программа cmpflt.c
// cmpflt.c -- сравнение чисел с плавающей запятой
#include <math.h>
int cmpflt(void)
{
	const double ANSWER = 3.141592653589793;
	double response;
	int status,i=1;
	printf("\n\033[41;1;4mПрограмма cmpflt.c -- сравнение чисел с плавающей запятой.\033[0m\n");
	printf("Каково значение числа pi(q - конец)?:______\b\b\b\b\b\b");
	status = scanf_s("%lf", &response); if (status != 1) return 0;
	while (fabs(response - ANSWER) > 0.0001)
	{
		printf("Bвeдитe значение %d-й раз(q - конец):______\b\b\b\b\b\b",++i);
		status = scanf_s("%lf", &response); if (status != 1) break;
	}
	printf("pi=%lf, вы ввели %lf, ошибка=%lf. Вы сделали %d попыток!\n", ANSWER, response, fabs(response - ANSWER),i);
	return 0;
}
// Листинг 6.6.Программа t_and_f.c
/* t_and_f.c — истинные и ложные значения в языке С */
int t_and_f(void)
{
	int true_val, false_val;
	printf("\n\033[41;1;4mПрограмма t_and_f.c — истинные и ложные значения в языке С.\033[0m\n");
	true_val = (10 > 2);		// значение истинного отношения
	false_val = (10 == 2);		// значения ложного отношения
	printf("true = %d; false = %d \n", true_val, false_val);
	return 0;
}
// Листинг 6.7.Программа truth.с
// truth.c — какие значения являются истинными?
int truth(void)
{
	int n = 3;
	printf("\n\033[41;1;4mПрограмма truth.c — какие значения являются истинными?\033[0m\n");
	while (n)
	printf("%2d является истинным\n", n--);
	printf("%2d является ложным\n", n);
	n = -3;
	while (n)
	printf("%2d является истинным\n", n++);
	printf("%2d является ложным\n", n);
	return 0;
}
// Листинг 6.8.Программа t r o ^ l e.с
// trouble.c -- неправильное применение операции =
// приводит к возникновению бесконечного цикла
int trouble(void)
{
	long num;
	long sum = 0L;
	int status,i=0;
	printf("\n\033[41;1;4mПрограмма  trouble.c -- неправильное применение операции =\033[0m\n");
	printf("Введите целое число для последующего суммирования");
	printf("(или q для завершения програмы):___\b\b\b");
	status = scanf_s("%ld", &num);
	while(status = 1)
	{
		sum = sum + num;
		printf("Введите следующее целое число (или q для завершения программы):___\b\b\b");
		status = scanf_s("%ld", &num);	if (i++ > 20) { printf("\n\033[41;30mАварийный выход из зацикливания!\033[0m\n"); break; }
	}
	printf("Cyммa введенных целых чисел равна %ld.\n", sum);
	return 0;
}
// Листинг 6.9.Программа toolean.с
// boolean.c — использование переменной типа _Bool
#include <stdio.h>
int boolean(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;
	printf("\n\033[41;1;4mПрограмма  boolean.c — использование переменной типа _Bool\033[0m\n");
	printf("Введите целое число для последующего суммирования");
	printf("(или q для завершения програмы):___\b\b\b");
	input_is_good = (scanf_s("%ld", &num) == 1);
	while(input_is_good)
	{
		sum = sum + num;
		printf("Введите следующее целое число(или q для завершения программы):___\b\b\b");
		input_is_good = (scanf_s("%ld", &num) == 1);
	}
	printf("Сумма введенных целых чисел равна %ld.\n", sum);
	return 0;
}
//Листинг 6 .1 0.Программа sweetiel.c
// sweetiel.c -- цикл со счетчиком
int sweetiel(void)
{
	const int NUMBER = 22;
	int count = 1;				// инициализация
	printf("\n\033[41;1;4mПрограмма  sweetiel.c -- цикл со счетчиком\033[0m\n");
	while(count <= NUMBER)		// проверка
	{
		printf("Будь моим другом! %d раз.\n",count); // действие
		count++;				// обновление значения count
	}
	return 0;
}
// Листинг 6.11.Программа sweetie2.с
// sweetie2.c — цикл for со счетчиком
int sweetie2(void)
{
	const int NUMBER = 22;
	int count;
	printf("\n\033[41;1;4mПрограмма  sweetie2.c — цикл for со счетчиком\033[0m\n");
	for(count = 1; count <= NUMBER; count++)
		printf("Будь моим другом! %d раз.\n", count);
	return 0;
}
// Листинг 6.12. Программа for_cube.c
/* for_cube.c — использование цикла for для построения таблицы кубов */
int for_cube(void)
{
	int num,max=1;
	long qube;
	printf("\n\033[41;1;4mПрограмма  for_cube.c — использование цикла for для построения таблицы кубов\033[0m\n");
	printf("Введите последнее число таблицы:___\b\b\b");
	scanf_s("%d", &max);
	printf("    n \tn в Ky6e\n");
	for(num = 1; num <= max; num++)
	{
		qube = (long)num * (long)num * (long)num; if (qube < 0) { printf("\n\033[41;30mАварийный выход - переполнение!\033[0m\n"); break; }
		printf("%5d \t%5ld\n", num, qube);
	}
	return 0;
}
/* for_down.c */
int for_down(void)
{
	int secs;
	printf("\n\033[41;1;4mПрограмма  for_down.c — использование цикла for с декрементом.\033[0m\n");
	for(secs = 5; secs > 0; secs--)
		printf("%d секунд(ы)!\n", secs);
	printf("Ключ на зажигание!\n");
	return 0;
}
// • При желании можно считать двойками, десятками и т.д.
/* for_13s.c  счет с интервалом 13, начиная с 2 */
int for_13s(void)
{
	int n;			// счет с интервалом 13, начиная с 2
	printf("\n\033[41;1;4mПрограмма  for_13s.c — использование цикла for счет с интервалом 13, начиная с 2\033[0m\n");
	for(n = 2; n < 60; n = n + 13)
		printf("%d \n", n);
	return 0;
}
// • Можно делать подсчет по символам, а не числам.
/* for_char.c */
int for_char(void)
{
	char ch;
	printf("\n\033[41;1;4mПрограмма  for_char.c — использование цикла for подсчет по символам\033[0m\n");
	for (ch = 'А'; ch <= 'z'; ch++)
		printf("Значение ASCII для %c равно %d(%#2x).\n", ch, ch,ch);
	return 0;
}
/* • Можно позволить некоторой величине расти не в арифметической, а в геометрической
прогрессии; т.е.вместо добавления каждый раз фиксированного значения
можно умножать на фиксированное значение. */
/* for_geo.c */
int for_geo(void)
{
	printf("\n\033[41;1;4mПрограмма  for_char.c — использование цикла for для геометрической прогрессии; \033[0m\n");
	double debt;
	for(debt = 100.0; debt < 150.0; debt = debt * 1.1)
		printf("Теперь ваша задолженность составляет $%.2f.\n", debt);
	return 0;
}
/* • В качестве третьего выражения можно использовать любое допустимое выражение.
Что бы вы здесь не поместили, это будет обновляться на каждой итерации. */
/* for_wild.c */
int for_wild(void)
{
	int x;
	int у = 55;
	printf("\n\033[41;1;4mПрограмма  for_wild.c — использование цикла for. В качестве третьего выражения можно использовать любое допустимое выражение.\033[0m\n");
	for(x = 1; у <= 75; у = (++x * 5) + 50)
		printf("%10d %10d\n", x, у);
	return 0;
}
/* • Можно даже оставить одно или несколько выражений пустыми (но не опускайте
точки с запятой). Обеспечьте наличие в цикле оператора, который в конечном
итоге приведет к завершению цикла. */
/* for_none.c */
int for_none(void)
{
	int ans, n;
	ans = 2;
	printf("\n\033[41;1;4mПрограмма  for_none.c — использование цикла for. Можно даже оставить одно или несколько выражений пустыми.\033[0m\n");
	for(n = 3; ans <= 25; )
	{
		ans = ans * n;
		printf("n = %d; ans = %d.\n", n, ans);
	}
	return 0;
} 
/*• Первое выражение не обязательно должно инициализировать переменную.
Вместо этого им могла бы быть какая-то разновидность оператора printf ().
Просто запомните, что первое выражение вычисляется или выполняется только
один раз, до того как начнут выполняться другие части цикла. */
/* for_show.c */
int for_show(void)
{
	int num = 0;
	printf("\n\033[41;1;4mПрограмма  for_show.c — использование цикла for. Первое выражение не обязательно должно инициализировать переменную.\033[0m\n");
	for(printf("Продолжайте вводить числа(пока не введёте 6)!\n"); num != 6; )
	scanf_s("%d", &num);
	printf("Вот то число, которое было нужно!\n");
	return 0;
}
// Листинг 6.13. Программа postage. с
// postage.c -- тарифы почтового обслуживания первого класса
int postage(void)
{
	const int FIRST_OZ = 46;	// тариф 2013 года
	const int NEXT_OZ = 20;		// тариф 2013 года
	int ounces, cost;
	int x, y, z;
	printf("\n\033[41;1;4mПрограмма  postage.c — использование цикла for. Опрератор 'запятая'.\033[0m\n");
	printf(" унции \tтариф\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
		printf("%5d \t$%4.2f\n", ounces, cost / 100.0);
	x = (y = 3, (z = ++y + 2) + 5);
	printf("x = (y = 3, (z = ++y + 2) + 5); В результате: x=%d y=%d z=%d\n", x, y, z);
	return 0;
}
// Листинг 6.14.Программа zeno.с
/* zeno.c — сума последовательности */
	int zeno(void)
{
	int t_ct; // счетчик элементов
	double time, power_of_2;
	int limit;
	printf("\n\033[41;1;4mПрограмма  zeno.c — использование цикла for. Греческий философ Зенон и цикл for.\033[0m\n");
	printf("Введите желаемое количество элементов последовательности:___\b\b\b ");
	scanf_s("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
	{
		time += 1.0 / power_of_2;
		printf("время = %f, когда количество элементов = %d.\n", time, t_ct);
	}
	return 0;
}
//Листинг 6.15. Программа do_while. с
/* do_while.c -- цикл с постусловием */
int do_while(void)
{
	const int secret_code = 13;
	int code_entered;
	printf("\n\033[41;1;4mПрограмма  do_while.c -- цикл с постусловием.\033[0m\n");
	do
	{
		printf("Чтобы войти в клуб лечения трискадекафобии, \n");
		printf("пожалуйста, введите секретный код(тринадцать):___\b\b\b");
		scanf_s("%d", &code_entered);
	} while (code_entered != secret_code);
	printf("Поздравляем! Вас вылечили!\n");
	return 0;
}
// Листинг 6. 16. Программа entry.с
/* entry.c -- цикл с предусловием */
int entry(void)
{
	const int secret_code = 13;
	int code_entered;
	printf("\n\033[41;1;4mПрограмма entry.с - цикл с предусловием.\033[0m\n");
	printf("Чтобы войти в клуб лечения трискадекафобии,\n");
	printf("пожалуйста, введите секретный код:___\b\b\b");
	while ((scanf_s("%d", &code_entered)==1)&&(code_entered != secret_code))
	{
		printf("Чтобы войти в клуб лечения трискадекафобии, \n");
		printf("пожалуйста, введите секретный код: ");
	}
	printf("Поздравляем! Вас вылечили!\n");
	return 0;
}
// Листинг 6.17. Программа rowsl.c
/* rowsl.c -- применение вложенных циклов */
#define ROWS 6
#define CHARS 10
int rows1(void)
{
	int row;
	char ch;
	printf("\n\033[41;1;4mПрограмма rows1.c -- применение вложенных циклов.\033[0m\n");
	for (row = 0; row < ROWS; row++)
	{
		for (ch = 'А'; ch < ('А' + CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}
		return 0;
}
// Листинг 6.18. Программа rows2. с
// rows2.c — применение зависимых вложенных циклов
int rows2(void)
{
	const int _ROWS = 6;
	const int _CHARS = 6;
	int row;
	char ch;
	printf("\n\033[41;1;4mПрограмма rows2.c -- применение вложенных циклов.\033[0m\n");
	for (row = 0; row < _ROWS; row++)
	{
		for (ch = ('А' + row); ch < ('А' + _CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}
// Листинг 6.19. Программа scores_in. с
// scores_in.c — использование циклов для обработки массивов
#define SIZE 10
#define PAR 72
int scores_in(void)
{
	int index, score[SIZE];
	int sum = 0;
	float average;
	printf("\n\033[41;1;4m6.19.Программа scores_in.c — использование циклов для обработки массивов.\033[0m\n");
	printf("Bвeдитe %d результатов игры в гольф:\n", SIZE);
	for (index = 0; index < SIZE; index++)
	{
		printf("%d:_\b",index+1);
		scanf_s("%d", &score[index]);			// чтение 10 результатов игры в гольф
	}
	printf("Введены следующие результаты:\n");
	for (index = 0; index < SIZE; index++)
		printf("%5d ", score[index]);			// проверка введенной информации
	//printf("\n");
	for (index = 0; index < SIZE; index++)
		sum += score[index];					// сложение результатов
	average = (float)sum / SIZE;				// проверенный временем метод
	printf("\nСумма результатов = %d, среднее значение = %.2f\n", sum, average);
	printf("Полученный гандикап равен %.0f.\n", average - PAR);
	return 0;
}
// Листинг 6.20. Программа power. с
// power.c -- возводит числа в целые степени
double power(double n, int р); // прототип ANSI
int powerCall(void)
{
	double х, xpow;
	int ехр;
	printf("\n\033[41;1;4m6.20.Программа power.c -- возводит числа в целые степени.\033[0m\n");
	printf("Введите число и положительную целую степень,");
	printf(" в которую\nчисло будет возведено. Для завершения программы");
	printf(" введите q:___ __\b\b\b\b\b\b");
	while (scanf_s("%lf %d", &х, &ехр) == 2)
	{
		xpow = power(х, ехр);		// вызов функции
		printf("%.3g в степени %d равно %.5g\n", х, ехр, xpow);
		printf("Введите следующую пару чисел или q для завершения:___ __\b\b\b\b\b\b");
	}
	printf("Надеемся, что вы оценили это упражнение -- до свидания!\n");
	return 0;
}
double power(double n, int р)	// определение функции
{
	double pow = 1;
	int i;
	for (i = 1; i <= р; i++)
		pow *= n;
	return pow;					// возвратить значение pow
}
// Вопросы для самоконтроля
// 8. Что выведут приведенные далее программы в случае ввода Go west, young man ! ?
// (В кодировке ASCII символ !следует за символом пробела.)
int test8(void)
{
	char ch;
	printf("\n\033[41;1;4mВопросы для самоконтроля. 8 -- Что выведут приведенные далее программы в случае ввода Go west, young man!\033[0m\n");
	do {
		scanf_s("%c", &ch);
		printf("%c", ch);
	} while (ch != 'g');
	printf("\n");
	return 0;
}
// 9. Что выведет следующая программа ?
int test9(void)
{
	int n, m;
	n = 30;
	printf("\n\033[41;1;4mВопросы для самоконтроля. 9 -- Что выведет следующая программа?\033[0m\n");
	while (++n <= 33)
		printf(" %d|", n) ;
			n = 30;
	do
		printf("%d|", n);
	while (++n <= 33);
	printf("\n***\n");
	for (n = 1; n * n < 200; n += 4)
		printf("%d\n", n);
	printf("\n***\n");
	for (n = 2, m = 6; n < m; n *= 2, m += 2)
		printf("%d %d\n", n, m);
	printf("\n***\n");
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m <= n; m++)
			printf("=");
		printf("\n"); 
	}
	return 0;
	}
// 14. Что выведет следующая программа?
#include <stdio.h>
int test14(void)
{
	int k;
	printf("\n\033[41;1;4mВопросы для самоконтроля. 14 -- Что выведет следующая программа?\033[0m\n");
	for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k), k * k < 26; k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
	return 0;
}