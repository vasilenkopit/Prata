#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
// Листинг 11.1. Программа stringsl. с
// strings1.с
#include <stdio.h>
#define MSG "Я - символьная строковая константа."
#define MAXLENGTH 81
int strings1(void)
{
	char words[MAXLENGTH] = "Я являюсь строкой, хранящейся в массиве.";
	const char* pt1 = "Что-то указывает на меня.";
	printf("\n\033[1;4;44mЛистинг 11.1.Программа  strings1.c -- несколько способов представления строк.\033[0m\n");
	puts("Вот несколько строк:");
	puts(MSG);
	puts(words);
	puts(pt1);
	words[14] = 'ф';
	puts(words);
	return 0;
}
// Листинг 11.2. Программа strptr. с
/* quotes.с -- строки как указатели */
int quotes(void)
{
	printf("\n\033[1;4;44mЛистинг 11.2.Программа  quotes.c -- строки как указатели.\033[0m\n");
	printf("%s, %p, %c\n", "Мы", " - ", *"космические бродяги");
	return 0;
}
// Листинг 11 .З. Программа a^ddresses. с
// addresses.c -- адреса строк
#define MSG "Я особенный."
#include <stdio.h>
int addresses()
{
	char ar[] = MSG;
	const char* pt = MSG;
	printf("\n\033[1;4;44mЛистинг 11.3.Программа  quotes.c -- строки как указатели.\033[0m\n");
	printf(" адрес \"Я особенный.\": %p \n", "Я особенный.");
	printf(" адрес ar:             %p\n", ar);
	printf(" адрес pt:             %p\n", pt);
	printf(" адрес MSG:            %p\n", MSG);
	printf(" адрес \"Я особенный.\": %p \n", "Я особенный.");
	return 0;
}
// Листинг 11.4. Программа arrchar. с
// arrchar.c - массив указателей, массив строк
#include <stdio.h>
#define SLEN 40
#define LIM 5
int arrchar(void)
{
	const char* mytalents[LIM] = {
	"Мгновенное складывание чисел",
	"Точное умножение", "Накапливание данных",
	"Исполнение инструкций с точностью до буквы",
	"Знание языка программирования С"
	};
	char yourtalents[LIM][SLEN] = {
	"Хождение по прямой",
	"Здоровый сон", "Просмотр телепередач",
	"Рассылка писем", "Чтение электронной почты"
	};
	int i;
	printf("\n\033[1;4;44mЛистинг 11.4.Программа  arrchar.c - массив указателей, массив строк.\033[0m\n");
	puts("Сравним наши таланты.");
	printf("%-52s %-25s\n", "Мои таланты", "Ваши таланты");
	for (i = 0; i < LIM; i++)
	printf("%-52s %-25s\n", mytalents[i] , yourtalents[i]);
	printf("\npaзмep mytalents: %zd, размер yourtalents: %zd\n", sizeof(mytalents), sizeof(yourtalents));
	return 0;
	}
// Листинг 11.5. Программа p _ a n d _ s . с
/* p_and_s.c -- указатели и строки */
int p_and_s(void)
{
	const char* mesg = "Не позволяйте себя запутать!";
	const char* сору;
	сору = mesg;
	printf("\n\033[1;4;44mЛистинг 11.5.Программа  p_and_s.c -- указатели и строки.\033[0m\n");
	printf("%s\n", сору);
	printf("mesg = %s; &mesg = %p; value = %p\n",
		mesg, &mesg, mesg);
	printf("copy = %s; &сору = %p; value = %p\n",
		сору, &сору, сору);
	return 0;
}
// Листинг 11.6. Программа getsputs. с
/* getsputs.c -- использование функций gets () и puts () */
#include <stdio.h>
#define STLEN 81
int getsputs(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44mЛистинг 11.6.Программа  getsputs.c -- использование функций gets () и puts ().\033[0m\n");
	puts("Введите строку.");
	gets(words);
	printf("Ваша строка, выведенная дважды:\n");
	printf("%s\n", words);
	puts(words);
	puts("Готово.");
	return 0;
}
// Листинг 11.7. Программа fgetsl. с
/* fgets1.c -- использование функций fgets() и fputs() */
#include <stdio.h>
#define STLEN 15
int fgets1(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44mЛистинг 11.7.Программа  fgets1.c -- использование функций fgets() и fputs().\033[0m\n");
	puts("Введите строку.");
	fgets(words, STLEN, stdin);
	printf("Ваша строка, выведенная дважды (с помощью puts(), а затем fputs()) :\n");
	puts(words);
	fputs(words, stdout);
	puts("Введите еще одну строку.");
	fgets(words, STLEN, stdin);
	printf("Ваша строка, выведенная дважды (с помощью puts(), а затем fputs()):\n");
	puts(words);
	fputs(words, stdout);
	puts("Готово.");
	return 0;
}
// Листинг 11.8. Программа fgets2. с
/* fgets2.c -- использование функций fgets() и fputs() */
#include <stdio.h>
#define STLEN 10
int fgets2(void)
{
	char words[STLEN];
	printf("\n\033[1;4;44mЛистинг 11.8.Программа  fgets2.c -- использование функций fgets() и fputs().\033[0m\n");
	puts("Введите строки (или пустую строку для выхода из программы):");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
		fputs(words, stdout);
	puts("Готово.");
	return 0;
}
// Листинг 11.9. Программа fgets3. с
/* fgets3.c -- использование функции fgets() */
#include <stdio.h>
#define STLEN 10
int fgets3(void)
{
	char words[STLEN];
	int i;
	printf("\n\033[1;4;44mЛистинг 11.9.Программа  fgets3.c -- использование функции fgets().\033[0m\n");
	puts("Введите строки (или пустую строку для выхода из программ) : ");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else // требуется наличие words [i] == '\0'
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("Готово.");
	return 0;
}
// Листинг 11.10. Функция s_gets()
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;
		ret_val = fgets(st, n, stdin);
		if (ret_val)			// т.е. ret_val != NULL
		{
			while (st[i] != '\n' && st[i] != '\0') i++; // Поиск конца введённой строки
			if (st[i] == '\n') st[i] = '\0';			// Строка короче выделенного места
			else										// Строка длиннее
				while (getchar() != '\n') continue;		// Отбросить все неуместившиеся символы входной строки
		}
		return ret_val;
}
// Листинг 11.11. Программа scan_str.с
/* scan_str.c -- использование функции scanf() */
#include <stdio.h>
int scan_str(void)
{
	char name1[11], name2[11];
	int count;
	printf("\n\033[1;4;44mЛистинг 11.11.Программа scan_str.c -- использование функции scanf().\033[0m\n");
	printf("Введите два имени через пробел.\n");
	count = scanf_s("%5s %10s", name1,10, name2,10);
	printf("Прочитано %d имени: %s и %s.\n", count, name1, name2);
	return 0;
}
// Листинг 11.12. Программа put_out.с
/* put_out.c -- использование функции puts() */
#include <stdio.h>
#define DEF "Я - строка, определенная директивой #define."
int put_out(void)
{
	char str1[80] = "Массив был инициализирован моим значением.";
	const char* str2 = "Указатель был инициализирован моим значением.";
	printf("\n\033[1;4;44mЛистинг 11.12.Программа put_out.c -- использование функции puts().\033[0m\n");
	puts("я - аргумент функции puts().");
	puts(DEF);
	puts(str1);
	puts(str2);
	puts(&str1[6]);
	puts(str2 + 4);
	return 0;
}
// Листинг 11.13. Программа nono.с
/* Программа nono.с -- не делайте так! */
int nono(void)
{
	char side_a[] = "Сторона А";
	char dont[] = {'У', 'Р', 'А', '!'};
	char side_b[] = "Сторона Б";
	printf("\n\033[1;4;44mЛистинг 11.13.Программа nono.с -- не делайте так!\033[0m\n");
	puts(dont); /* dont не является строкой */
	return 0;
}
// Листинг 11.14.Функция put1()
/* put1.с — выводит строку без добавления символа \n */
#include <stdio.h>
void put1(const char* string) /* строка не изменяется */
{
	while (*string != '\0')
		putchar(*string++);
}
// Листинг 11.15. Функция put2()
/* put2.c -- выводит строку и подсчитывает символы */
#include <stdio.h>
int put2(const char* string)
{
	int count = 0;
	while (*string) /* общепринятый подход */
	{
		putchar(*string++);
		count++;
	}
	putchar('\n'); /* символ новой строки не учитывается */
	return(count);
}
// Листинг 11.16. Программа putyut.c
// put_put.c -- функции вывода, определенные пользователем
#include <stdio.h>
void put1(const char*);
int put2(const char*);
int put_put(void)
{
	printf("\n\033[1;4;44mЛистинг 11.16.Программа put_put.c -- функции вывода, определенные пользователем\033[0m\n");
	put1("Если бы у меня было столько денег,");
	put1(" сколько я мог бы потратить,\n");
	printf("Получилось %d символов.\n",	put2("то я никогда не заботился бы о починке старых башмаков."));
	return 0;
}
//void put1(const char* string)
//{
//	while (*string) /* эквивалентно *string != '\0' */
//		putchar(*string++);
//}
//int put2(const char* string)
//{
//	int count = 0;
//	while (*string)
//	{
//		putchar(*string++);
//		count++;
//	}
//		putchar('\n');
//	return(count);
//}
// Листинг 11.17. Программа test_fit.c
/* test_fit.c -- использование функции укорачивания строк */
#include <stdio.h>
#include <string.h> /* содержит прототипы строковых функций */
void fit(char*, unsigned int);
int test_fit(void)
{
	char mesg[] = "Все должно быть максимально простым,"
		" но не более. ";
	printf("\n\033[1;4;44mЛистинг 11.17.Программа test_fit.c -- использование функции укорачивания строк\033[0m\n");
	puts(mesg);
	fit(mesg, 35);
	puts(mesg);
	puts("Рассмотрим еще несколько строк.");
	puts(mesg + 36);
	return 0;
}
void fit(char* string, unsigned int size)
{
	if (strlen(string) > size)
		string[size] = '\0';
}
// Листинг 11.18. Программа str_cat.c
/* str_cat.c -- объединяет две строки */
#include <stdio.h>
#include <string.h> /* объявление strcat() */
#define SIZE 80
char* s_gets(char* st, int n);
int str_cat(void)
{
	char flower[SIZE];
	char addon[] = " пахнет как старые валенки.";
	printf("\n\033[1;4;44mЛистинг 11.18.Программа str_cat.c -- объединяет две строки\033[0m\n");
	puts("Kaкoй у вас любимый цветок?");
	if (s_gets(flower, SIZE))
	{
		strcat_s(flower, SIZE, addon);
		puts(flower);
		puts(addon);
	}
	else
		puts("Обнаружен конец файла!");
	puts("Программа завершена.");
	return 0;
}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	int i = 0;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		while (st[i] != '\n' && st[i] != '\0')
//			i++;
//		if (st[i] == '\n')
//		st[i] = '\0 ';
//		else // требуется наличие words[i] == '\0'
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}
// Листинг 11.19. Программа join_chk. с
/* join_chk.c -- объединяет две строки, предварительно проверив размер */
#include <stdio.h>
#include <string.h>
#define SIZE 33
#define BUGSIZE 23
char* s_gets(char* st, int n);
int join_chk(void)
{
	char flower[SIZE];
	char addon[] = " пахнет как старые валенки.";
	char bug[BUGSIZE];
	int available;
	printf("\n\033[1;4;44mЛистинг 11.19.Программа join_chk.c -- объединяет две строки, предварительно проверив размер\033[0m\n");
	puts("Какой у вас любимый цветок?");
	s_gets(flower, SIZE);
	if ((strlen(addon) + strlen(flower) + 1) <= SIZE)
		strcat_s(flower, SIZE, addon);
	puts(flower);
	puts("Какое у вас любимое насекомое?");
	s_gets(bug, BUGSIZE);
	available = BUGSIZE - strlen(bug) - 1;
	strncat_s(bug, BUGSIZE, addon, available);
	puts(bug);
	return 0;
}
// Листинг 11.20. Программа nogo.с
/* nogo.c — будет ли это работать? */
#include <stdio.h>
#define ANSWER "Грант"
#define SIZE 40
char* s_gets(char* st, int n);
int nogo(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44mЛистинг 11.20.Программа nogo.c — будет ли это работать?\033[0m\n");
	puts("Кто похоронен в могиле Гранта?");
	s_gets(try, SIZE);
	while (try != ANSWER)
	{
		puts("Неправильно! Попытайтесь еще раз.");
		s_gets(try, SIZE); 
	}
	puts("Теперь правильно!");
	return 0;
}
// Листинг 11.21. Программа compare. с
/* compare.c -- эта программа будет работать */
#include <stdio.h>
#include <string.h> // объявление strcmp()
#define ANSWER "Грант"
#define SIZE 40
char* s_gets(char* st, int n);
int compare(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44mЛистинг 11.21.Программа compare.c -- эта программа будет работать\033[0m\n");
	puts("Кто похоронен в могиле Гранта?");
	s_gets(try, SIZE);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("Неправильно! Попытайтесь еще раз.");
		s_gets(try, SIZE);
	}
	puts("Teneрь правильно!");
	return 0;
}
// Листинг 11.22. Программа сошрЬаск. с
/* compback.c -- значения, возвращаемые функцией strcmp() */
#include <stdio.h>
#include <string.h>
int compback(void)
{
	printf("\n\033[1;4;44mЛистинг 11.22.Программа compback.c -- значения, возвращаемые функцией strcmp()\033[0m\n");
	printf("strcmp(\"A\", \"A\") возвращает ");
	printf("% d\n", strcmp("A", "A"));
	printf("strcmp(\"A\", \"B\") возвращает ");
	printf("% d\n", strcmp("A", "В"));
	printf("strcmp(\"B\", \"A\") возвращает ");
	printf("% d\n", strcmp("B", "A"));
	printf("strcmp(\"C\", \"A\") возвращает ");
	printf("% d\n", strcmp("C", "A"));
	printf("strcmp(\"Z\", \"a\") возвращает ");
	printf("% d\n", strcmp("Z", "a"));
	printf("strcmp(\"apples\", \"apple\") возвращает ");
	printf("% d\n", strcmp("apples", "apple"));
	return 0;
}
// Листинг 11.23. Программа quit_chk. с
/* quit_chk.c -- начало некоторой программы */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_gets(char* st, int n);
int quit_chk(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf("\n\033[1;4;44mЛистинг 11.23.Программа quit_chk.c -- начало некоторой программы\033[0m\n");
	printf("Введите до %d строк (или quit для завершения):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && strcmp(input[ct], STOP) != 0)
	{
		ct++;
	}
	printf("Введено %d строк (и) \n", ct);
	return 0;
}
// Листинг 11.23a. Программа quit_chkNull. с
/* quit_chkNull.c -- начало некоторой программы */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10
#define STOP "quit"
char* s_gets(char* st, int n);
int quit_chkNull(void)
{
	char input[LIM][SIZE];
	int ct = 0;
	printf("\n\033[1;4;44mЛистинг 11.23a.Программа quit_chkNull.c -- начало некоторой программы, завершение-пустая строка\033[0m\n");
	printf("Введите до %d строк (Enter - завершение ввода):\n", LIM);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ct++;
	}
	printf("Введено %d строк (и) \n", ct);
	return 0;
}
// Листинг 11.24. Программа starsrch. с
/* starsrch.c -- использование функции strncmp() */
#include <stdio.h>
#include <string.h>
#define LISTSIZE 6
int starsrch()
{
	const char* list[LISTSIZE] =
	{
		"астрономия", "астатиэм",
		"астрофизика", "остракизм",
		"астеризм", "астролябия"
	};
	int count = 0;
	int i;
	printf("\n\033[1;4;44mЛистинг 11.24.Программа starsrch.c -- использование функции strncmp()\033[0m\n");
	for (i = 0; i < LISTSIZE; i++)
		if (strncmp(list[i], "астро", 5) == 0)
		{
			printf("Haйдeнo: %s\n", list[i]);
			count++;
		}
	printf("Количество слов в списке,"
		" начинающихся с астро: %d\n", count);
	return 0;
}
// Листинг 11.25. Программа copy1.с
/* copy1.с — демонстрация использования strcpy() */
#include <stdio.h>
#include <string.h> // объявление strcpy()
#define SIZE 40
#define LIM 5
char* s_gets(char* st, int n);
int copy1(void)
{
	char qwords[LIM][SIZE];
	char temp[SIZE];
	int i = 0;
	printf("\n\033[1;4;44mЛистинг 11.25.Программа copy1.с — демонстрация использования strcpy()\033[0m\n");
	printf("Bвeдитe % d слов, которые начинаются с буквы к: \n", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'к')
			printf("%s не начинается с буквы к!\n ", temp);
		else
		{
			strcpy_s(qwords[i], SIZE, temp);
			i++;
		}
	}
	puts("Список принятых слов:");
	for(i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}
// Листинг 11.26. Программа copy2.с
/* copy2.с -- демонстрация использования strcpy() */
#include <stdio.h>
#include <string.h> // объявление strcpy ()
#define WORDS "наихудшим"
#define SIZE 40
int copy2(void)
{
	const char* origin = WORDS;
	char copy[SIZE] = "Будьте лучшим, чем могли бы быть.";
	char* ps;
	printf("\n\033[1;4;44mЛистинг 11.26.Программа copy2.с -- демонстрация использования strcpy()\033[0m\n");
	puts(origin);
	puts(copy);
	strcpy_s(copy + 7,10, origin);
	puts(copy);
	//puts(ps);
	return 0;
}
// Листинг 11.27. Программа copyЗ. с
/* copyЗ.с -- демонстрация использования strncpy() */
#include <stdio.h>
#include <string.h> /* объявление strncpy () */
#define SIZE 40
#define TARGSIZE 15
#define LIM 5
char* s_gets(char* st, int n);
int copyЗ(void)
{
	char qwords[LIM][TARGSIZE];
	char temp[SIZE];
	int i = 0;
	printf("\n\033[1;4;44mЛистинг 11.27.Программа copyЗ.с -- демонстрация использования strncpy()\033[0m\n");
	printf("Введите %d слов, которые начинаются с буквы к:\n ", LIM);
	while (i < LIM && s_gets(temp, SIZE))
	{
		if (temp[0] != 'к')
			printf("%s не начинается с буквы к!\n ", temp);
		else
		{
			strncpy_s(qwords[i], TARGSIZE, temp, TARGSIZE - 1);
			qwords[i][TARGSIZE - 1] = '\0';
			i++;
		}
	}
	puts("Список принятых слов:");
	for (i = 0; i < LIM; i++)
		puts(qwords[i]);
	return 0;
}
// Листинг 11.28. Программа format.с
/* format.c — форматирование строки */
#include <stdio.h>
#define MAX 20
char* s_gets(char* st, int n);
int format(void)
{
	char first[MAX];
	char last[MAX];
	char forma1[2* MAX +10];
	double prize;
	printf("\n\033[1;4;44mЛистинг 11.28.Программа format.c — форматирование строки\033[0m\n");
	puts("Введите свое имя:");
	s_gets(first, MAX);
	puts("Введите свою фамилию:");
	s_gets(last, MAX);
	puts("Введите сумму денежного приза:");
	scanf_s("%lf", &prize);
	sprintf_s(forma1, 2* MAX +10, "%s, %-19s: $%6.2f\n", last, first, prize);
	puts(forma1);
	return 0;
}
// Листинг 11.28a. Программа strFunctions.с
/* strFunctions.с -- Пример вызова строковых функций */
#define MAX 80
int strFunctions(void) {
	char tok_sArr[20][20] = { 0,0,0,0,0,0,0,0,0,0,0 };
	int n;
	char* pstr;
	char copy[MAX];
	char last[MAX];
	char buff[100];
	const char* source = "Исходная строка для примера.";
	printf("\n\033[1;4;44mЛистинг 11.28a.Программа strFunctions.c — Пример вызова строковых функций\033[0m\n");
	printf("Пример strcpy_s(copy, source):\n");
	strcpy_s(copy,29, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n",copy,source);

	printf("\nПример strncpy_s(copy,29, source,10):\n");
	strncpy_s(copy,29, source,10);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n",copy,source);

	printf("\nПример strcat_s(copy,MAX, source):\n");
	strcat_s(copy,MAX, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n", copy, source);

	printf("\nПример strncat_s(copy,MAX, source,5):\n");
	strncat_s(copy, MAX, source,5);
	printf("copy=   \"%s\"  \nsource= \"%s\"\n", copy, source);

	printf("\nПример n=strcmp(copy, source):\n");
	n=strcmp(copy, source);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\nПример n=strncmp(copy, source,8):\n");
	n=strncmp(copy, source,8);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\nПример n=strncmp(copy, source,12):\n");
	n=strncmp(copy, source,12);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%d\n", copy, source,n);

	printf("\nПример pstr=strchr(copy, 'ы'):\n");
	pstr = strchr(copy, 'ы');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strchr(copy, 'я'):\n");
	pstr = strchr(copy, 'я');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strpbrk(copy, \"чыщц\"):\n");
	pstr = strpbrk(copy, "чыщц");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strpbrk(copy, \"чыщцр\"):\n");
	pstr = strpbrk(copy, "чыщцр");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strrchr(copy,'р'):\n");
	pstr = strrchr(copy, 'р');
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strstr(copy,\"для\"):\n");
	pstr = strstr(copy, "для");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример pstr=strstr(copy,\"бля\"):\n");
	pstr = strstr(copy, "бля");
	printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%s\n", copy, source, pstr);

	printf("\nПример n=strlen(copy):\n");
	n = strlen(copy);
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%zd\n", copy, source, n);

	printf("\nПример n=strspn(copy, \"Исходящая\"):\n");
	n = strspn(copy, "Исходящая");
	printf("copy=   \"%s\"  \nsource= \"%s\"\nn=%zd\n", copy, source, n);

	//printf("\nПример pstr=strtok(source, \". \"):\n");
	//pstr = strtok_s(source, ". ", tok_sArr);
	//printf("%s\n", pstr);
	////while (pstr=strtok(NULL, ". "))	{
	////	printf("%s\n", pstr);
	////}
	//printf("copy=   \"%s\"  \nsource= \"%s\"\npstr=%p\n", copy, source, pstr);
		printf("\nПример pstr=strtok(source, \". \"):\n");
		char data[] = " С приносит\t очень #много \nрадости!";
		const char tokseps[] = " \t\n#";	/* разделители */
		char context[10][10];
		char * pt;
		puts(data);
		pt = strtok_s(data,tokseps, context) ;		/* первый вызов */
		while (pt)			/* выход в случае NULL */
		{
			puts (pt);		/* показать лексему */
			pt = strtok_s(NULL, tokseps, context);	/* следующая лексема */
		}

		//printf("1........01........01........01........01........01........01........01........01........01........01........0\n");
	printf("\nПример pstr = strerror_s(buff,100,i);\n");
	int len,k=2,l;
	for (int i = 0; i < 999; i++) {
		n = strerror_s(buff, 100, i);
		len = strlen(buff);
		printf("i=%3d-%s ",i, buff);
		k = (i < 140) ? 2 : 5;
		l = (i < 140) ? 50 : 15;
		if (i % k) { if (len < l) for (int j = 0; j < l - len;j++) printf(" "); }
		if (!(i % k)) printf("\n");
	}

return 0;
}
// Листинг 11.29. Программа sort_str.c
/* sort_str.c -- считывает строки и сортирует их */
#include <stdio.h>
#include <string.h>
#define SIZE 81			/* лимит на длину строки, включая \0 */
#define LIM 20			/* максимальное количество читаемых строк */
#define HALT			/* нулевая строка для прекращения ввода */
void stsrt(char* strings[], int num, int arr[]);/* функция сортировки строк */
char* s_gets(char* st, int n);
int sort_str(void)
{
	char input[LIM][SIZE];	/* массив для сохранения входных данных */
	char* ptstr[LIM];		/* массив переменных типа указателя */
	int ct = 0;				/* счетчик ввода */
	int k;					/* счетчик вывода */
	int idx[LIM] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};			/* Номера строк */
	printf("\n\033[1;4;44mЛистинг 11.29.Программа sort_str.c -- считывает строки и сортирует их\033[0m\n");
	printf("Введите до %d строк, и они будут отсортированы.\n", LIM);
	printf("Чтобы остановить ввод, наймите клавишу Enter в начале строки.\n %d:",1);
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0')
	{
		ptstr[ct] = input[ct]; /* установка указателей на строки */
		//idx[ct] = ++ct;
		printf("%2d:", ++ct + 1);
	}
	stsrt(ptstr, ct,idx);			/* сортировщик строк */
	puts("\nОтсортированный список:\n");
	for (k = 0; k < ct; k++)
		printf("%2d(%2d): %s\n",k+1,idx[k], ptstr[k]);
		//puts(ptstr[k]);			/* отсортированные указатели */
	printf("\n");
	return 0;
}
/* функция сортировки указателей на строки */
void stsrt(char* strings[], int num,int arr[])
{
char* temp;
int itemp;
int top, seek;
for (top = 0; top < num - 1; top++)
	for (seek = top + 1; seek < num; seek++)
		if (strcmp(strings[top], strings[seek]) > 0)
		{
			temp = strings[top];
			strings[top] = strings[seek];
			strings[seek] = temp;
			itemp = arr[top];
			arr[top] = arr[seek];
			arr[seek] = itemp;
		}
}
// Листинг 11.30. Программа mod_str.с
/* mod_str.c — модифицирует строку */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81
void ToUpper(char*);
int PunctCount(const char*);
int mod_str(void)
{
	char line[LIMIT];
	char* find;
	printf("\n\033[1;4;44mЛистинг 11.30.Программа mod_str.c — модифицирует строку\033[0m\n");
	puts("Введите строку:");
	fgets(line, LIMIT, stdin);
	find = strchr(line, '\n');	// поиск символа новой строки
	if (find)					// если адрес не является NULL,
		*find = '\0';			// поместить туда нулевой символ
	ToUpper(line);
	puts(line);
	printf("Эта строка содержит %d знаков препинания. \n", PunctCount(line));
	return 0;
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}
int PunctCount(const char* str)
{
	int ct = 0;
	while (*str)
	{
		if (ispunct(*str++)) ct++;
		//str++;
	}
	return ct;
}
//Листинг 11.31.Программа r e ^ a t.c
/* repeat.c -- функция rnain() с аргументами */
#include <stdio.h>
int repeat(int argc, char* argv[])
{
	int count;
	printf("\n\033[1;4;44mЛистинг 11.31.Программа repeat.c -- функция rnain() с аргументами\033[0m\n");
	printf("Количество аргументов, указанных в командной строке: %d\n", argc - 1);
	for (count = 1; count < argc; count++)
		printf("%d: %s\n", count, argv[count]);
	printf("\n");
	return 0;
}
//Листинг 11.32.Программа hello.с
/* hello.c -- преобразует аргумент командной строки в число */
#include <stdio.h>
#include <stdlib.h>
int hello(int argc, char* argv[])
{
	int i, times;
	printf("\n\033[1;4;44mЛистинг 11.32.Программа hello.c -- преобразует аргумент командной строки в число\033[0m\n");
	if (argc < 2 || (times = atoi(argv[1])) < 1)
		printf("Использование: %s положительное-число\n", argv[0]);
	else
		for (i = 0; i < times; i++)
			puts("Xopoшего дня!");
	return 0;
}
// Листинг 11.33. Программа strcnvt. с
/* strcnvt.c -- использование функции strtol() */
#include <stdio.h>
#include <stdlib.h>
#define LIM 30
char* s_gets(char* st, int п);
int strcnvt()
{
	char number[LIM];
	char* end;
	long lvalue10,lvalue16;
	int ivalue;
	double dvalue;
	float fvalue;
	printf("\n\033[1;4;44mЛистинг 11.33.Программа strcnvt.c -- использование функции strtol()\033[0m\n");
	puts("Введите число (или пустую строку для выхода из программы):"INPUT3);
	while (s_gets(number, LIM) && number[0] != '\0')
	{
		lvalue10 = strtol(number, &end, 10);		/* по основанию 10 */
		printf("десятичный ввод, десятичный вывод: %ld, прекращен на %s (%d)\n", lvalue10, end, *end);
		ivalue = _strtoi64(number, &end, 16);
		dvalue = strtod(number, &end);
		fvalue = strtof(number, &end);
		lvalue16 =  strtol(number, &end, 16);		/* по основанию 16 */
		printf("шестнадцатеричный ввод, шестнадцатеричный вывод: %ld, прекращен на %s (%d)\n", lvalue16, end, *end);
		puts("Следующее число:"INPUT3);
	}
	puts("Программа завершена.\n");
	return 0;
}

// 1. Bопросы для самоконтроля.
int quest1_4(void) {
	char name[] = { 'Л', 'у', 'н', 'а',0 };
	char sname[] = { "Луна" };
	char cname[] =  "Луна";
	printf("\n\033[1;4;44mBопросы для самоконтроля. 1 - Какая ошибка допущена в представленном объявлении символьной строки?\033[0m\n");
	printf("%s ------- %s ------- %s", name,sname,cname);

	printf("\n\033[1;4;44mBопросы для самоконтроля. 2. Что выведет следующая программа?\033[0m\n");
	char note[] = "Увидимся завтра в кафе.";
	char* ptr;
	ptr = note;
	puts(ptr);
	puts(++ptr);
	note[7] = '\0' ;
	puts(note);
	puts(++ptr);
	
	printf("\n\033[1;4;44mBопросы для самоконтроля. 3. Что выведет следующая программа?\033[0m\n");
	char food[] = "Вкусно";
	char* qptr;
	qptr = food + strlen(food);
	while (--qptr >= food) puts(qptr);

	printf("\n\033[1;4;44mBопросы для самоконтроля. 4. Что выведет следующая программа?\033[0m\n");
	char goldwyn[31] = "огу я смог ";
	char samuel[41] = "За всю дор";
	const char* quote = "осилить лишь часть.";
	strcat_s(goldwyn,31, quote);
	strcat_s(samuel,41, goldwyn);
	puts(samuel);
	return 0;
}
/*
5. Приведенные ниже вопросы позволят попрактиковаться со строками, циклами,
указателями и их инкрементированием. Предположим, что имеется такое определение функции:char *pr(char *str)
#include <stdio.h>

Взгляните на следующий вызов функции:
х = pr("Хо Хо Хо !");
а. Что он выводит?
б. Какой тип должна иметь переменная х?
в. Какое значение получает переменная х?
г. Что означает выражение *--рс, и чем оно отличается от --*рс ?
д. Что будет выведено, если *--рc заменить выражением *рc-- ?
е. Для чего предназначены два выражения проверки в операторах while?
ж. Что произойдет, если функции pr() передать в качестве аргумента пустую строку?
з. Что придется сделать в вызывающей функции, чтобы pr() можно было использовать так, как показано выше?
*/
char* pr(char* str)
{
	char* pc;
	pc = str;
	while (*pc) putchar(*pc++);
	while (pc > str) {
		putchar(*--pc);
	};
	return (pc);
}
char* pr1(char* str)
{
	char* pc;
	pc = str;
	while (*pc) putchar(*pc++);
	do {
		putchar(*pc--);
	} while (pc - str);
	return (pc);
}

int quest5(void) {
	char* x;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 5. имеется такое определение функции:char *pr(char *str)\033[0m\n");
	x = pr("Хо Хо Хо !");			// Хо Хо Хо !! оХ оХ оХ
	printf("\n%s\n", x);			// Хо Хо Хо !!
	x = pr1("Хи Хи Хи !");			// Хи Хи Хи !! иХ иХ и
	printf("\n%s\n", x);			// Хи Хи Хи !
	x = pr("");						// изменить второй цикл на while (pc >= str){};
	printf("\n%s\n", x);			// Вызвано необработанное исключение: нарушение доступа для чтения.	pc было 0x7FF6C130FFFF.

}
// 	7. Что выведет следующая программа ?
#include <stdio.h>
#include <string.h>
#define M1 "How are уа, sweetie?"
int quest6(void) {
	char M2[40] = "Beat the clock.";
	char* M3 = "chat";
	char words[80];
	printf("\n\033[1;4;44mBопросы для самоконтроля. 7. Что выведет следующая программа ?\033[0m\n");
	printf(M1);
	puts(M1);
	puts(M2);
	puts(M2 + 1);
	strcpy_s(words,80, M2);
	strcat_s(words,80, " Win а toy.");
	puts(words);
	words[4] = '\0';
	puts(words);
	while (*M3)
		puts(M3++);
	puts(--M3);
	puts(--M3);
	puts(--M3);
	puts(--M3);
	M3 = M1;
	puts(M3);
	return 0;
}
// 8. Что выведет следующая программа?
#include <stdio.h>
char* s_getsPtr(char* st, int n);
int quest8(void)
{
	char str1[] = "gawsie";
	char str2[] = "bletonism";
	char* ps;
	int i = 0;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 8. Что выведет следующая программа?\033[0m\n");
	for (ps = str1; *ps != '\0'; ps++) {
		if (*ps == 'a' || * ps == 'e')
			putchar(*ps);
		else
			(*ps)--;
		putchar(*ps);
	}
	putchar('\n');
	while (str2[i] != '\0') {
		printf("%c", i % 3 ? str2[i] : '*');
		++i;
	}
	return 0;
}
// 9. Функцию s_gets(), определенную в этой главе, можно переписать в форме с использованием
//указателей, а не массивов, чтобы исключить из нее переменную i. Сделайте это.
int quest9(void) {
	char* arr[80];
	char* sptr;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 9. Переписать s_gets с указателями.\033[0m\n");
	printf("Вводите слово:"INPUT3);
	sptr = s_getsPtr(arr,80);
	printf("Введено: %s",sptr);
	return 0;
}
//  Функция s_getsPtr() аналог s_gets с указателями
char* s_getsPtr(char* st, int n)
{
	char* ret_val;
	//int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)			// т.е. ret_val != NULL
	{
		while (*st != '\n' && *st != '\0') st++;	// Поиск конца введённой строки
		if (*st == '\n') *st = '\0';				// Строка короче выделенного места
		else										// Строка длиннее
			while (getchar() != '\n') continue;		// Отбросить все неуместившиеся символы входной строки
	}
	return ret_val;
}
/*
10. Функция strlen() принимает указатель на строку в качестве аргумента и возвращает
длину строки. Напишите свою версию этой функции.
*/
int strlen10(char* in);
int quest10(void) {
	char* arr=  "1234567890123456789012345678901234567890123456789012345678901234567890" ;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 10. Написать int strlen(cyar* in)\033[0m\n");
	printf("strlen(\"QWERTYUIOP\")=%d strlen(arr)=%d strlen(\"\")=%d", strlen10("QWERTYUIOP"), strlen10(arr), strlen(""));
	return 0;
}
int strlen10(char* in) {
	int l=0;
	while (*in++)l++;
	return l;
}
/*
11. Функцию s_gets(), определенную в этой главе, можно переписать с использованием
функции strchr() вместо цикла while для обнаружения символа новой строки. Сделайте это.
*/
char* s_gets11(char* st, int n);
int quest11(void) {
	char arr[100];
	char* ptr;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 11. Переписать s_gets() с использованием функции strchr()\033[0m\n");
	printf("Введите строку:"INPUT3);
	ptr = s_gets11(arr, 70);
	printf("Ввели строку:%s\n",ptr);
	return 0;
}
char* s_gets11(char* st, int n){
	char* ret_val;
	char* ptr;
	int i = 0;
	ret_val = fgets(st, n, stdin);
	if (ret_val)			// т.е. ret_val != NULL
	{
		ptr=strchr(st, '\n');
		if (ptr) *ptr = '\0';
		else
			while (getchar() != '\n') continue;		// Отбросить все неуместившиеся символы входной строки
	}
	return ret_val;
}
/*
12. Разработайте функцию, которая принимает указатель на строку в качестве аргумента
и возвращает указатель на первый символ пробела, расположенный в
указанной позиции внутри строки или после нее. Функция должна возвращать
нулевой указатель, если пробелы не найдены.
*/
char* findspb(char* str);
int quest12(void) {
	char* test1 = "aaa sss";
	char* test2 = "ddddddddddd";
	char* ptr;
	printf("\n\033[1;4;44mBопросы для самоконтроля. 12. Написать функцию поиска первого пробела.\033[0m\n");
	ptr = findspb(test1);
	if(ptr)printf("Найден пробел:----%s\n", ptr);
	ptr = findspb(test2);
	if(!ptr)printf("Не найден пробел:----%s\n", ptr);

}
char* findspb(const char* str) {
	while (*str) {
		if (*str++ == ' ') return --str;
	}
	return NULL;
}
/*
13. Перепишите программу из листинга 11.21, используя функции из ctype.h для
того, чтобы программа распознавала правильный ответ независимо от применения
пользователем прописных или строчных букв.
*/
int compare13(void);
int quest13(void) {
	printf("\n\033[1;4;44mBопросы для самоконтроля. 13. Переписать листинг 11.21 для маленьких и больших букв.\033[0m\n");
	return compare13();
}

// Листинг 11.21. Программа compare. с
/* compare.c -- эта программа будет работать */
#include <stdio.h>
#include <string.h> // объявление strcmp()
#define ANSWER "ГРАНТ"
#define SIZE 40
char* s_gets(char* st, int n);
char* toUpperStr(char* str);
int compare13(void)
{
	char try[SIZE];
	printf("\n\033[1;4;44mЛистинг 11.21.Программа compare.c -- эта программа будет работать\033[0m\n");
	puts("Кто похоронен в могиле Гранта?");
	s_gets(try, SIZE);
	toUpperStr(try);
	while (strcmp(try, ANSWER) != 0)
	{
		puts("Неправильно! Попытайтесь еще раз.");
		s_gets(try, SIZE);
	}
	puts("Teneрь правильно!");
	return 0;
}
char* toUpperStr(char* str) {
	int d1 = 'а' - 'А';
	char ch;
	char* ptr=str;
	while (ch=*str) {
		if (ch >= 'а' && ch <= 'я') *str = (ch - d1);
		str++;
	}
	return ptr;
}