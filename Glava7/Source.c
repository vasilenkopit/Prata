//Листинг 7.1.Программа colddays.с
// colddays.c -- вычисляет процент случаев, когда температура опускается ниже нуля
#include <stdio.h>
int colddays(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf("\n\033[1;4;44mЛистинг 7.1.Программа colddays.с \nвычисляет процент случаев, когда температура опускается ниже нуля\033[0m\n");
	printf("Bвeдитe список минимальных дневных температур.\n");
	printf("Используйте шкалу Цельсия; можно через пробел, для завершения введите q:");
	while (scanf_s("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}
	if (all_days != 0)
		printf("%d - общее количество дней: %.1f%% с температурой ниже нуля.\n",
			all_days, 100.0 * (float)cold_days / all_days);
	if (all_days == 0)
		printf("Дaнныe не введены!\n");
	return 0;
}
// Листинг 7.2. Программа cypherl .с
// cypherl.c -- вносит изменения во входные данные, сохраняя пробелы
#include <stdio.h>
#define SPACE ' '		// кавычка, пробел, кавычка
int cypher1(void)
{
	char ch;
	printf("\n\033[1;4;44mЛистинг 7.2. Программа cypher1.с \nувеличивает код символа, сохраняя пробелы\033[0m\n");
	printf("Bвeдитe строку с пробелами или без:\n");
	ch = getchar();			// читать символ
	while (ch != '\n')		// пока не встретится конец строки
	{
		if (ch == SPACE)	// оставить пробел нетронутым
			putchar(ch);	// символ не меняется
		else
			putchar(ch + 1); // изменить другие символы
		ch = getchar();		 // получить следующий символ
	}
	putchar(ch);	// вывести символ новой строки
	return 0;
}
// Листинг 7.З . Программа cypher2. с
// cypher2.c -- меняет входные данные, оставляя неизменными символы, которые не являются буквами
#include <stdio.h>
#include <ctype.h> // для доступа к isalpha ()
int cypher2(void)
{
	char ch;
	printf("\n\033[1;4;44mЛистинг 7.3. Программа cypher2.с \nменяет входные данные, оставляя неизменными символы небуквы.\033[0m\n");
	printf("Bвeдитe строку с пробелами или без:\n");
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))	// если это буква,
			putchar(ch + 1);// отобразить следующую букву
		else// в противном случае
			putchar(ch);	// отобразить символ как есть
	}
	putchar(ch);			// вывести символ новой строки
	return 0;
}
// Листинг 7 .4. Программа electric. с
// electric.c -- подсчитывает сумму для счета за электроэнергию
#include <stdio.h>
#define RATE1 0.13230	// тариф за первые 360 кВт/ч
#define RATE2 0.15040	// тариф за следующие 108 кВт/ч
#define RATE3 0.30025	// тариф за следующие 252 кВт/ч
#define RATE4 0.34025	// тариф, когда расход превммает 720 кВт/ч
#define BREAK1 360.0	// первая точка разрыва тарифов
#define BREAK2 468.0	// вторая точка разрыва тарифов
#define BREAK3 720.0	// третья точка разрыва тарифов
#define BASE1 (RATE1 * BREAK1)
// стоимость 360 кВт/ч
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
// стоимость 468 кВт/ч
#define BASE3 (BASE1 + BASE2 + (RATE3 *(BREAK3 - BREAK2)))
// стоимость 720 кВт/ч
int electric(void)
{
	double kwh;		// израсходованные киловатт-часы
	double bill;	// сумма к оплате
	printf("\n\033[1;4;44mЛистинг 7.4. Программа electric.с -- подсчитывает сумму для счета за электроэнергию.\033[0m\n");
	printf("Введите объем израсходованной электроэнергии в кВт/ч:___\b\b\b");
	scanf_s("%lf", &kwh); // %lf для типа double
	if(kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2)	// количество кВт/ч в промежутке от 360 до 468
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3)	// количество кВт/ч в промежутке от 4 68 до 720
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else                    // количество кВт/ч превышает 680
		bill = BASE3 + (RATE4 * (kwh - BREAK3));
	printf("Сумма к оплате за %.lf кВт/ч составляет $%1.2f.\n", kwh, bill);
	return 0;
}
// Листинг 7.5. Программа divisors.с
// divisors.с -- вложенные операторы if отображают делители числа
#include <stdio.h>
#include <stdbool.h>
int divisors(void)
{
	unsigned long num;		// проверяемое число
	unsigned long div;		// потенциальные делители
	bool isPrime;			// флаг простого числа
	printf("\n\033[1;4;44mЛистинг 7.5. Программа divisors.с -- вложенные операторы if отображают делители числа\033[0m\n");
	printf("Введите целое число для анализа(q - завершение):__\b\b");
	while (scanf_s("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++)
		{
			if (num % div == 0)
			{
				if ((div * div) != num)
					printf("%lu делится на %lu и %lu.\n", num, div, num / div);
				else
					printf("%lu делится на %lu.\n",	num, div);
				isPrime = false; // число не является простым 
			}
		}
		if (isPrime)
		printf("%lu является простым числом.\n", num);
		printf("Введите следующее число для анализа; ");
		printf("для завершения введите q.\n"); 
	}
	printf("До свидания.\n");
	return 0;
}
// Листинг 7.6. Программа chcount.c
// chcount.c -- использование логической операции "И"
#include <stdio.h>
#define PERIOD '.'
int chcount(void)
{
	char ch;
	int charcount;
	printf("\n\033[1;4;44mЛистинг 7.6. Программа chcount.c -- использование логической операции ""И""\n\t\tсчитает число не кавычек до точки.\033[0m\n");
	do {
		charcount = 0;
		printf("Введите строку с кавычками(конец - точка -"".""):_____\b\b\b\b\b");
		while ((ch = getchar()) != PERIOD)
		{
			if (ch != '"' && ch != '\'') charcount++;
		}
		printf("Здесь имеется %d символов, отличных от кавычек.\n", charcount);
		printf("Повторить анализ новой строки?(y/д):");
	} while (scanf_s(" %c",&ch),ch=='y'||ch=='д');
	return 0;
}
// Листинг 7.7. Программа wordcnt.с
// wordcnt.c -- производит подсчет символов, слов, строк
#include <stdio.h>
#include <ctype.h> // для isspace()
#include <stdbool.h> // для bool, true, false
#define STOP '|'
int wordcnt(void)
{
	char c;				// прочитанный символ
	char prev;			// предыдущий прочитанный символ
	long n_chars = 0L;	// количество символов
	int n_lines = 0;	// количество строк
	int n_words = 0;	// количество слов
	int p_lines = 0;	// количество неполных строк
	bool inword = false;// == true если символ с находится внутри слова
	printf("\n\033[1;4;44mЛистинг 7.7. Программа  wordcnt.c -- производит подсчет символов, слов, строк.\033[0m\n");
	printf("Введите текст для анализа(| для завершения):\n");
	prev = '\n';		// используется для идентификации полных строк
	while ((c = getchar()) != STOP)
	{
		n_chars++;		// считать символы
		if (c == ' \n')
			n_lines++;	// считать строки
		if (!isspace(c) && !inword)
		{
			inword = true;	// начало нового слова
			n_words++;		// считать слова
		}
		if (isspace(c) && inword)
			inword = false; // достигнут конец слова
		prev = c;			// сохранить значение символа
	}
	if (prev != ' \n')
		p_lines = 1;
	printf("символов = %ld, слов = %d, строк = %d, ", n_chars, n_words, n_lines);
	printf("неполных строк = %d\n", p_lines);
	return 0;
}
// Листинг 7.8. Программа paint.c
/* paint.c -- использование условной операции */
#include <stdio.h>
#define COVERAGE 350 // число квадратных футов на одну банку краски
int paint(void)
{
	int sq_feet;
	int cans;
	printf("\n\033[1;4;44mЛистинг 7.8. Программа paint.c -- использование условной операции.\033[0m\n");
	printf("Введите количество квадратных футов, которые необходимо покрасить:___\b\b\b");
	while (scanf_s("%d", &sq_feet) == 1) {
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
		printf("Для этого потребуется %d банк%c краски.\n", cans,
			cans == 1 ? 'а' : 'и');
		printf("Введите следующее значение (или q для завершения):\n");
	}
	return 0;
}
// Листинг 7.9. Программа skippart.c
/* skippart.c -- использование оператора continue для пропуска части цикла */
#include <stdio.h>
int skippart(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	printf("\n\033[1;4;44mЛистинг 7.9. Программа skippart.c -- использование оператора continue для пропуска части цикла.\033[0m\n");
	printf("Введите результат первой игры[0,100](или q для завершения):\033[4m   \033[0m\b\b\b");
	while (scanf_s("%f", &score) == 1)
	{
		if (score < MIN || score > MAX)
		{
			printf("%0.1f - недопустимое значение. Повторите попытку: ", score);
			continue; // переход к условию проверки цикла while
		}
		printf("Accepting %0.1f:", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("Введите результат следующей игры[0,100](или q для завершения):\033[4m   \033[0m\b\b\b");
}
		if (n > 0)
		{
			printf("Результатов %d штук. Среднее значение равно %0.1f.\n" , n, total/n) ;
			printf("Минимальное = %0.1f, максимальное = %0.1f\n", min, max);
		}
		else
			printf("Не было введено ни одного допустимого результата.\n");
		return 0;
	}
// Листинг 7.10. Программа break. с
/* break.c — использование оператора break для выхода из цикла */
#include <stdio.h>
int breakc(void)
{
	float length, width;
	printf("\n\033[1;4;44mЛистинг 7.10. Программа break.c — использование оператора break для выхода из цикла.\033[0m\n");
	printf("Введите длину прямоугольника:\033[4m   \033[0m\b\b\b");
	while (scanf_s("%f", &length) == 1)
	{
		printf("Длинa = \t%0.2f:\n", length);
		printf("Введите ширину прямоугольника:\033[4m   \033[0m\b\b\b");
		if (scanf_s("%f", &width) != 1)
			break;
		printf("Ширина = \t%0.2f:\n", width);
		printf("Площадь = \t%0.2f:\n", length * width);
		printf("Введите длину прямоугольника:\033[4m   \033[0m\b\b\b");
	}
		printf("Программа завершена.\n");
		return 0;
	}
//Листинг 7.10a. Программа break. с
/* break2.c — использование 2-ух операторов break для выхода из внутреннего и внешнего циклов */
#include <stdio.h>
int breakc2(void)
{

	int р, q,status;
	printf("\n\033[1;4;44mЛистинг 7.10a. Программа break2.c — использование 2-ух операторов break для выхода из внутреннего и внешнего циклов.\033[0m\n");
	printf("Программа вычисляет p*q(p>0,0<q<100).\n");
	printf("Введите p:\033[4m   \033[0m\b\b\b");
	status=scanf_s("%d", &р);
	while (р > 0 && status==1)
	{
		printf("p = \t%d. Введите q:\033[4m   \033[0m\b\b\b", р);
		status = scanf_s("%d", &q);
		while (q > 0 && status == 1)
		{
			printf("p*q = %d*%d = \t%d\n", р,q,р * q);
			if (q > 100)
				break;				// выход из внутреннего цикла
			printf("Введите q:\033[4m   \033[0m\b\b\b");
			status = scanf_s("%d", &q);
		}
		if (q > 100)
			break;					// выход из внешнего цикла
		printf("Введите p:\033[4m   \033[0m\b\b\b");
		status = scanf_s("%d", &р);
	}
}
// Листинг 7.11.Программа animals.с
/* animals.c -- использование оператора switch */
#include <stdio.h>
#include <ctype.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
int animals(void)
{
	char ch;
	printf("\n\033[1;4;44mЛистинг 7.11. Программа  animals.c -- использование оператора switch.\033[0m\n");
	printf("Дайте мне букву алфавита, и я укажу вам ");
	printf("название животного, начинающееся с этой буквы. \n");
	printf("Введите букву или # для завершения:"INPUT1);
	while ((ch = getchar()) != '#')
	{
	if (' \n' == ch) continue;
	if (1/*_islower_l(ch, 1)*/) /* только строчные буквы */
		switch (ch)
		{
		case 'а':
		case 'А':
			printf("apxap, дикий горный азиатский баран\n");
			break;
		case 'б':
			printf("бабирусса, дикая малайская свинья\n");
			break;
		case 'к':
			printf("коати, носуха обыкновенная\n");
			break;
		case 'в':
			printf("выхухоль, водоплавающее существо\n");
			break;
		case 'е':
			printf("ехидна, игольчатый ^муравьед\n");
			break;
		case 'р':
			printf("рыболов, светло-коричневая куница \n");
			break;
		default:
			printf("Boпpoc озадачил!\n");
		} /* конец оператора выбора */
	else
		printf("Распознаются только строчные буквы.\n");
	while (getchar() != '\n')
		continue;  /* пропустить оставшуюся часть входной строки */
	printf("Введите следующую букву или # для завершения:"INPUT1);
		} /* конец цикла while */
	printf("До свидания.\n") ;
		return 0;
}
// Листинг 7.12. Программа vowels.с
// vowels.c -- использование множества меток
#include <stdio.h>
int vowels(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("\n\033[1;4;44mЛистинг 7.12. Программа  vowels.c -- использование множества меток switch.\033[0m\n");
	printf("Введите текст или # для завершения программы:"INPUT3);
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case 'a':
		case 'A': a_ct++;
			break;
		case 'e':
		case 'E': e_ct++;
			break;
		case 'i':
		case 'I': i_ct++;
			break;
		case 'o':
		case 'O': o_ct++;
			break;
		case 'u':
		case 'U': u_ct++;
			break;
		default: break;
		} // конец оператора switch
	} // конец цикла while
	printf("Количество гласных: \tA \tE \tI \tO \tU\n");
	printf(" \t\t\t%d \t%d \t%d \t%d \t%d\n", a_ct, e_ct, i_ct, o_ct, u_ct);
	return 0;
}
// вопросы для самоконтроля
/* 3. В приведенной ниже программе присутствуют излишне сложные выражения
отношений, а также откровенные ошибки.Упростите программу и исправьте ошибки. 
*/
#include <stdio.h>																					
int question3(void)										/* 1 */
{														/* 2 */								
	int weight, height;		/* вес в фунтах, рост в дюймах */
	printf("\n\033[1;4;44mВопрос 3. Программа  question3.c -- Упростите программу и исправьте ошибки.\033[0m\n");
	printf("Введите вес и рост через пробел:(вес>100, рост)"INPUT3" \b"INPUT3);
	scanf_s("%d %d" , &weight, &height);				/* 5 */
	if (weight < 100 && height > 64)					/* 6 */
		if (height >= 72)								/* 7 */
			printf("Ваш вес слишком мал для вашего роста.\n");
		else if (height < 72 && weight > 64)			/* 9 */
			printf("Ваш вес мал для вашего роста.\n");	/* 10 */
		else if (weight > 300 && !(weight <= 300)		/* 11 */
			&& height < 48)								/* 12 */
			if (!(height >= 48))						/* 13 */
				printf("Ваш рост мал для вашего веса\n");
			else                                        /* 15 */
				printf("У вас идеальный вес.\n");		/* 16 */
	return 0;											/* 17 */
}
// 5. Что выведет следующая программа?
#include <stdio.h>
int question5(void)
{
	int num;
	printf("\n\033[1;4;44mВопрос 5. Программа  question5.c --  Что выведет следующая программа?\033[0m\n");
	for (num = 1; num <= 11; num++)
	{
		if (num % 3 == 0)
			putchar('$');
		else
			putchar('*');
			putchar('#');
		putchar('%');
	}
	putchar('\n');
	return 0;
}
// 6. Что выведет следующая программа ?
#include <stdio.h>
int question6(void)
{
	int i = 0;
	printf("\n\033[1;4;44mВопрос 6. Программа  question6.c --  Что выведет следующая программа?\033[0m\n");
	while (i < 3) {
		switch (i ++) {
		case 0:	printf("fat ");
		case 1: printf("hat ");
		case 2: printf("cat ");
		default: printf("Oh no!");
		}
		putchar('\n');
	}
	return 0;
}
// 7. Что неправильно в следующей программе?
#include <stdio.h>
int question7(void)
{
	char ch;
	int lc = 0; /* счетчик строчных символов */
	int uc = 0; /* счетчик прописных символов */
	int oc = 0; /* счетчик других символов */
	printf("\n\033[1;4;44mВопрос 7. Программа  question7.c --  Что неправильно в следующей программе?\033[0m\n");
	printf("Введите строку(окончание - #):"INPUT3);
	while ((ch = getchar()) != '#')
	{
		if (('a' <= ch) && (ch <= 'z'))
			lc++;
		else if ((ch >= 'A') && (ch <= 'Z'))
			uc++;
		else
			oc++;
	} printf(" %d строчных, %d прописных, %d других\n", lc, uc, oc);
	return 0;
}
// 8. Что выведет следующая программа?
/* retire.c */
#include <stdio.h>
int question8(void)
{
	int age = 20;
	printf("\n\033[1;4;44mВопрос 8. Программа  question8.c --  Что выведет следующая программа?\033[0m\n");
	while (age++ <= 65)
	{
		if ((age % 20) == 0) /* делится ли возраст на 20? */
			printf("BaM %d. Вас повысили в должности.\n", age);
		if (age == 65)
			printf("BaM %d. Получите свои золотые часы.\n", age);
	}
	return 0;
}
/* 9. Что выведет следующая программа при указанном вводе?
q
c
h
b
*/
#include <stdio.h>
int question9(void)
{
	char ch;
	printf("\n\033[1;4;44mВопрос 9. Программа  question9.c --  Что выведет следующая программа при указанном вводе?\033[0m\n");
	printf("q\nc\nh\nb\n#\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf("Шаг 1\n");
		if(ch == 'c')
			continue;
		else if (ch == 'b')
			break;
		else if (ch == 'h')
			goto laststep;
		printf("Шаг 2\n");
		laststep: printf("Шаг 3\n");
	}
	printf("Готово\n");
	return 0;
}
/* 10. Перепишите программу из вопроса 9 так, чтобы она сохранила свое поведение,
но в ней не использовались операторы continue и goto. */
#include <stdio.h>
int question10(void)
{
	char ch;
	printf("\n\033[1;4;44mВопрос 10. Программа  question10.c --  Что выведет следующая программа при указанном вводе?\033[0m\n");
	printf("q\nc\nh\nb\n#\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '\n':
			break;
		case 'b':
			printf("Шаг 1\n");
			break;
		case 'h':
			printf("Шаг 1\n");
			printf("Шаг 3\n");
			break;
		case 'c':
			printf("Шаг 1\n");
			break;
		case 'q':
			printf("Шаг 1\n");
			printf("Шаг 2\n");
			printf("Шаг 3\n");
		default:
			break;
		}
		if (ch == 'b') break;
	}
	printf("Готово\n");
	return 0;
}