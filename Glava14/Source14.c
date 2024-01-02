#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

// Листинг 14.1. Программа Ьок.с
/* book.c — каталог для одной книги */
#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n) {
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // поиск новой строки
		if (find) // если адрес не равен NULL,
			*find = '\0'; // поместить туда нулевой символ
		else
			while (getchar() != '\n')
				continue; // отбросить остаток строки
	}
	return ret_val;
}
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//	ret_val = fgets(st, n, stdin);
//	if (ret_val) {
//		find = strchr(st, '\n'); // поиск новой строки
//		if (find) // если адрес не равен NULL,
//			*find = '\0'; // поместить туда нулевой символ
//		else
//			while (getchar() != '\n')
//				continue; // отбросить остаток строки
//	}
//	return ret_val;
//}
char* s_gets(char* st, int n);
#define MAXTITL 41	/* максимальная длина названия + 1 */
#define MAXAUTL 31	/* максимальная длина имени автора + 1 */
struct book {		/* шаблон структуры: дескриптором является book */
char title[MAXTITL];
char author[MAXAUTL];
float value;
};					/*конец шаблона структуры */
int book(void)
{
	struct book library;				/* объявление library в качестве переменной типа book */
	printf("\033[1;4;32mЛистинг 14.1. Программа Ьок.с  — каталог для одной книги\033[0m\n");
	printf("Введите название книги.\n");
	s_gets(library.title, MAXTITL);			/* доступ к разделу названия книги */
	printf("Теперь введите ФИО автора.\n");
	s_gets(library.author, MAXAUTL);
	printf("Теперь введите цену.\n");
	scanf_s("%f", &library.value);
	printf("%s авторства %s: $%.2f\n", library.title,library.author, library.value);
	printf("%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
	printf("Готово.\n");
	return 0;
}
// Листинг 14.2. Программа manybook.c
/* manybook.c -- каталог для нескольких книг */
#include <stdio.h>
#include <string.h>
char* s_gets(char* st, int n);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* максимальное количество книг */
//struct book { /* установка шаблона book */
//	char title[MAXTITL];
//	char author[MAXAUTL];
//	float value;
//};
int manybook(void)
{
	struct book library[MAXBKS]; /* массив структур типа book */
	int count = 0;
	int index;
	printf("\033[1;4;32mЛистинг 14.2. Программа manybook.c -- каталог для нескольких книг\033[0m\n");
	printf("Введите название книги.\n");
	printf("Нажмите [enter] в начале строки, чтобы закончить ввод.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Теперь введите ФИО автора.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Теперь введите цену.\n");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n') continue; /* очистить входную строку */
		if (count < MAXBKS) printf("Введите название следующей книги.\n");
	}
	if (count > 0){
		printf("Каталог ваших(%d) книг:\n",count);
		for (index = 0; index < count; index ++)
			printf("%3d:%s авторства %s: $%.2f\n",index+1, library[index].title,
				library[index].author, library[index].value);
	}
	else
		printf("Вообще нет книг? Очень плохо.\n");
	return 0;
}
// Листинг 14.3. Программа friend.c
// friend.c -- пример вложенной структуры
#include <stdio.h>
#define LEN 20
const char* msgs[5] =
{
	" Благодарю вас за чудесно проведенный вечер, ",
	"Вы однозначно продемонстрировали, что ",
	"являет собою особый тип мужчины. Мы обязательно должны встретиться",
	"за восхитительным ужином с ",
	" и весело провести время."
};
struct names{				// первая структура
	char first[LEN];
char last[LEN];
};
struct guy{					// вторая структура
	struct names handle;	// вложенная структура
char favfood[LEN];
char job[LEN];
float income;
};
int friend13(void)
{
	struct guy fellow = {	// инициализация переменной
		{"Билли", "Боне" },
			"запеченными омарами",
			"персональный тренер",
			68112.00
	};
	printf("\033[1;4;32mЛистинг 14.3. Программа friend.c -- пример вложенной структуры\033[0m\n");
	printf("Дорогой %s, \n\n", fellow.handle.first);
	printf("%s%s.\n", msgs[0], fellow.handle.first);
	printf("%s%s\n", msgs[1], fellow.job);
	printf("%s\n", msgs[2]);
	printf("%s%s%s", msgs[3], fellow.favfood, msgs[4]);
	if (fellow.income > 150000.0)
		puts("!!");
	else if (fellow.income > 75000.0)
		puts("!");
	else
		puts(".");
	printf("\n%40s%s\n", " ", "До скорой встречи,");
	printf("%40s%s\n", " ", "Шейла");
	return 0;
}
// Листинг 14.4. Программа friends. с
/* friends.c -- использование указателя на структуру */
#include <stdio.h>
#define LEN 20
//struct names {
//	char first[LEN];
//	char last[LEN];
//};
//struct guy{
//	struct names handle;
//	char favfood[LEN];
//	char job[LEN];
//	float income;
//};
int friends(void)
{
	struct guy fellow[2] = {
		{{"Билли", "Боне" },
		"запеченными омарами",
			"персональный тренер",
			68112.00
			},
		{{ "Джим", "Хокинс" },
			"рыбным фрикасе",
			"редактор таблоида",
			232400.00
		}
	};
	struct guy* him;			/* указатель на структуру */
	printf("\033[1;4;32mЛистинг 14.4. Программа friends.c -- использование указателя на структуру\033[0m\n");
	printf("aдpec #1: \t%p #2: \t%p (#2-#1): \t%d\n", &fellow[0], &fellow[1], &fellow[1]- &fellow[0]);
	him = fellow;			/* сообщает указателю, на что указывать  him = &fellow[0];*/
	printf("указатель #1: \t%p #2: \t%p размер структуры: %d\n", him, him + 1,sizeof(struct guy));
	printf("him->income равно: \t$%.2f \t(*him).income равно: \t$%.2f\n", him->income, (*him).income);
	him++;						/* указатель на следующую структуру */
	printf("him->favfood равно: \t%s \thim->handle.last равно: \t%s\n", him->favfood, him->handle.last);
	return 0;
}
// Листинг 14.5. Программа fundsl. с
/* funds1.c -- передача членов структуры в качестве аргументов */
#include <stdio.h>
#define FUNDLEN 50
struct funds{
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum(double, double);
double sumstruct(const struct funds);	/* аргумент является структурой */
double sumpointer(struct funds*);		/* аргумент является указателем на структуру */
int funds1(void)
{
	struct funds stan = {
		"Garlic-Melon Bank",
		4032.27,
		"Lucky's Savings and Loan",
		8543.94
	};
	printf("\033[1;4;32mЛистинг 14.5-6-7. Программа funds1.c -- передача членов структуры в качестве аргументов\033[0m\n");
	printf("Общая сумма на счетах у Стэна составляет $ %.2f.\n",sum(stan.bankfund, stan.savefund));
	printf("Параметр - указатель на структуру:\nOбщaя сумма на счетах у Стэна составляет $%.2f.\n", sumpointer(&stan));
	printf("Параметр - структура:\nOбщaя сумма на счетах у Стэна составляет $%.2f.\n", sumstruct(stan));
	return 0;
}
/* суммирование двух чисел типа double */
double sum(double х, double у)
{
	return(х + у);
}
double sumpointer(const struct funds* money)
{
	return(money->bankfund + money->savefund);
}
double sumstruct(const struct funds money)
{
	return(money.bankfund + money.savefund);
}
// Листинг 14.8. Программа nameesl. с
/* names1.c -- использует указатели на структуры */
#include <stdio.h>
#include <string.h>
#define NLEN 30
struct namect {
	char fname[NLEN];
	char lname[NLEN];
	int letters;
};
void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
char* s_gets(char* st, int n);
struct namect getinfoStr(void);
struct namect makeinfoStr(struct namect);
void showinfoStr(struct namect);

int names1(void)
{
	struct namect person;
	printf("\033[1;4;32mЛистинг 14.8. Программа names1.c -- использует указатели на структуры\033[0m\n");
	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	printf("Повторяется 14.9 для комплекта функция с параметрами-структурами.\n");
	person = getinfoStr(person);
	person = makeinfoStr(person);
	showinfoStr(person);

	return 0;
}
void getinfo(struct namect* pst)
{
	printf("Введите свое имя.\n");
	s_gets(pst->fname, NLEN);
	printf("Введите свою фамилию.\n");
	s_gets(pst->lname, NLEN);
}
void makeinfo(struct namect* pst)
{
	pst->letters = strlen(pst->fname) +	strlen(pst->lname);
}
void showinfo(const struct namect* pst)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n",	pst->fname, pst->lname, pst->letters);
}
//---------------Комплект функция с параметрами-структурами--------------------------
struct namect getinfoStr(void)
{
	struct namect temp;
	printf("Введите свое имя.\n");
	s_gets(temp.fname, NLEN);
	printf("Введите свою фамилию.\n");
	s_gets(temp.lname, NLEN);
	return temp;
}
struct namect makeinfoStr(struct namect info)
{
	info.letters = strlen(info.fname) + strlen(info.lname);
	return info;
}
void showinfoStr(struct namect info)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n", info.fname, info.lname, info.letters);
}
// Листинг 14.10. Программа names3.c
// names3.c -- использование указателей и функции malloc()
#include <stdio.h>
#include <string.h> // для strcpy (), strlen()
#include <stdlib.h> // для malloc (), free()
#define SLEN 81
struct namect1410 {
	char* fname; // использование указателей
	char* lname;
	int letters;
};
void getinfo1410(struct namect1410*); // выделение памяти
void makeinfo1410(struct namect1410*);
void showinfo1410(const struct namect1410*);
void cleanup1410(struct namect1410*); // освобождение памяти, когда она больше не нужна
char* s_gets(char* st, int n);
int names3(void)
{
	struct namect1410 person;
	printf("\033[1;4;32mЛистинг 14.10. Программа names3.c -- использование указателей и функции malloc()\033[0m\n");
	getinfo1410(&person);
	makeinfo1410(&person);
	showinfo1410(&person);
	cleanup1410(&person);
	return 0;
}
void getinfo1410(struct namect1410* pst)
{
	char temp[SLEN];
	printf("Введите свое имя.\n");
	s_gets(temp, SLEN);
	// выделение памяти для хранения имени
	pst->fname = (char*)malloc(strlen(temp) + 1);
	// копирование имени в выделенную память
	strcpy_s(pst->fname, strlen(temp)+1, temp);
	printf("Введите свою фамилию.\n");
	s_gets(temp, SLEN);
	pst->lname = (char*)malloc(strlen(temp) + 1);
	strcpy_s(pst->lname, strlen(temp)+1, temp);
}
void makeinfo1410(struct namect1410* pst)
{
	pst->letters = strlen(pst->fname) +	strlen(pst->lname);
}
void showinfo1410(const struct namect1410* pst)
{
	printf("%s %s, ваше имя и фамилия содержат %d букв.\n",	pst->fname, pst->lname, pst->letters);
}
void cleanup1410(struct namect1410* pst)
{
	free(pst-> fname);
	free(pst-> lname);
}
// Листинг 14. 11. Программа complit.с
/* complit.c -- составные литералы */
#include <stdio.h>
#define MAXTITL 41
#define MAXAUTL 31
struct book1411 {			// шаблон структуры: book - дескриптор
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct rect{ double x; double y; };
double rect_area(struct rect r) { return r.x * r.y; }
double rect_areap(struct rect* rp) { return rp->x * rp->y; }
int complit(void)
{
	struct book1411 readfirst;
	int score;
	printf("\033[1;4;32mЛистинг 14.11. Программа complit.c -- составные литералы\033[0m\n");
	printf("Введите рейтинг: ");
	scanf_s("%d", &score);
	if (score >= 84)
		readfirst = (struct book1411){ "Преступление и наказание","Федор Достоевский",11.25 };
	else
		readfirst = (struct book1411){ "Красивая шляпа мистера Баунси","Фред Уинсом",5.99 };
	printf("Назначенные вами рейтинги:\n");
	printf("%s Ьу %s: $%.2f\n",readfirst.title,readfirst.author, readfirst.value);

	double area1,area2;
	area1 = rect_area((struct rect){ 10.1, 20.1 });
	area2 = rect_areap(&(struct rect) { 100.5, 200.5 });
	printf("Фактический параметр функции составной литерал и адрес сост.литерала.\narea1=%lf \tarea2=%lf\n",area1,area2);
	return 0;
}
// Листинг 14.12. Программа flexmemb.с
// flexmemb.c --член типа гибкого массива(средство С99)
#include <stdio.h>
#include <stdlib.h>
struct flex
{
	size_t count;
	double average;
	double scores[]; // член с типом гибкого массива
};
void showFlex(const struct flex* р);
int flexmemb(void)
{
	struct flex* pf1, * pf2;
	int n = 5;
	int i;
	int tot = 0;
	printf("\033[1;4;32mЛистинг 14.12. Программа  flexmemb.c --член типа гибкого массива(средство С99)\033[0m\n");
	// выделение памяти для структуры и массива
	pf1 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf1->count = n;
	for (i = 0; i < n; i++)
	{
		pf1->scores[i] = 20.0 - i;
		tot += pf1->scores[i];
	}
	pf1->average = tot / n;
	showFlex(pf1);
	n = 9;
	tot = 0;
	pf2 = malloc(sizeof(struct flex) + n * sizeof(double));
	pf2->count = n;
	for (i = 0; i < n; i++)
	{
		pf2->scores[i] = 20.0 - i / 2.0;
		tot += pf2->scores[i];
	}
	pf2->average = tot / n;
	showFlex(pf2);
	free(pf1);
	free(pf2);
	return 0;
}
void showFlex(const struct flex* p)
{
	int i;
	printf("Рейтинги: ");
	for (i = 0; i < p->count; i++)
		printf("%g ", p->scores[i]);
	printf("\nСреднее значение: %g\n", p->average);
}
// Листинг 14.13. Программа funds4.с
/* funds4.c — передача функции массива структур */
#include <stdio.h>
#define FUNDLEN 50
#define N 2
struct funds1413 {
	char bank[FUNDLEN];
	double bankfund;
	char save[FUNDLEN];
	double savefund;
};
double sum1413(const struct funds1413 money[], int n);
int funds4(void)
{
	struct funds1413 jones[N] = {
		{"Garlic-Melon Bank",  4032.27, "Lucky's Savings and Loan",	8543.94},
		{"Honest Jack's Bank", 3620.88, "Party Time Savings",		3802.91}
	};
	printf("\033[1;4;32mЛистинг 14.13. Программа  funds4.c — передача функции массива структур\033[0m\n");
	printf("Общая сумма на счетах у Джонсов составляет $%.2f.\n", sum1413(jones,N));
	return 0;
}
double sum1413(const struct funds1413 money[], int n)
{
	double total;
	int i;
	for (i = 0, total = 0; i < n; i++)
		total += money[i].bankfund + money[i].savefund;
	return(total);
}
// Листинг 14. 14. Программа booksave.с
/* booksave.c — сохранение содержимого структуры в файле */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10		/* максимальное количество книг */
char* s_gets(char* st, int n);
struct book14{ /* определение шаблона book */
	
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
int booksave(void)
{
	struct book14 library[MAXBKS];	/* массив структур */
	int count = 0;
	int index, filecount;
	FILE * pbooks;
	int size = sizeof (struct book14);
	char* filename = "books.dat";
	printf("\033[1;4;32mЛистинг 14.14. Программа  booksave.c — сохранение содержимого структуры в файле\033[0m\n");
	if ((fopen_s(&pbooks, filename, "a+b") ) != NULL)
	{
		printf ("\033[31mОшибка!\033[0m Не удается открыть файл %s. " , filename);
		perror("");
		exit (1) ;
	}
	rewind(pbooks); /* переход в начало файла */
	while (count < MAXBKS && fread(&library[count], size,1, pbooks) == 1)
	{
		if (count == 0)	printf("Текущее содержимое файла %s:\n", filename);
		printf("%2d: %s авторства %s: $ %.2f\n", 
			count+1,library[count].title,library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		printf("Фaйл %s заполнен.\n", filename);
		exit(2);
	}
	puts("Введите названия новых книг.");
	puts("Нажмите [enter] в начале строки, чтобы закончить ввод.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Теперь введите имя автора.");
		s_gets(library[count].author, MAXAUTL);
		puts("Teпepь введите цену книги.");
		scanf_s("%f", &library[count++].value);
		while (getchar() != '\n') 	continue; /* очистить входную строку */
		if (count < MAXBKS) 	puts("Введите название следующей книги.");
	}
	if (count > 0)
	{
		puts("Каталог ваших книг:");
		for (index = 0; index < count; index++)
			printf("%2d: %s авторства %s: $%.2f\n",index+1, library[index].title,library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("Вообще нет книг? Очень плохо.\n");
	puts("Программа завершена.\n");
	fclose(pbooks);
	return 0;
}
// Листинг 14.15. Программа enwn.с
/* enum.c -- использование перечислимых значений */
#include <stdio.h>
#include <string.h> // для strcmp(), strchr()
#include <stdbool.h> // средство С99
char* s_gets(char* st, int n);
enum spectrurn			{ red,   orange,   yellow,   green,   blue,   violet ,cyan};
const char* colors[] =	{"red", "orange", "yellow",	"green", "blue", "violet","cyan"};
const char* colorsRus[]={"красный", "оранжевый", "жёлтый",	"зелёный", "синий", "фиолетовый","голубой"};
#define LEN 30
int enum14(void)
{
	char choice[LEN];
	enum spectrurn color;
	bool color_is_found = false;
	printf("\033[1;4;32mЛистинг 14.15. Программа  enum.c -- использование перечислимых значений\033[0m\n");
	puts("Введите цвет (или пустую строку для выхода):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0'){
		for (color = red; color <= cyan; color++) {
			if (strcmp(choice, colors[color]) == 0|| strcmp(choice, colorsRus[color]) == 0) {
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color) {
			case red: puts("Розы красные.");
				break;
			case orange: puts("Маки оранжевые.");
				break;
			case yellow: puts("Подсолнухи желтые.");
				break;
			case green: puts("Трава зеленая.");
				break;
			case blue: puts("Колокольчики синие.");
				break;
			case violet: puts("Фиалки фиолетовые.");
				break;
			case cyan: puts("Тюльпаны голубые.");
				break;
			}
		else
			printf("Цвет %s не известен.\n", choice);
		color_is_found = false;
		puts("Введите следующий цвет (или пустую строку для выхода):");
	}
	puts("Программа завершена.");
	return 0;
}
// Листинг 14.16. Программа func_ytr.с
// func_ptr.c — использование указателей на функции
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81
char* s_gets(char* st, int n);
char showmenu(void);
void eatline(void);				// читает до конца строки
void show(void (*fp)(char*), char* str);
void ToUpper(char*);			// преобразует строку в верхний регистр
void ToLower(char*);			// преобразует строку в нижний регистр
void Transpose(char*);			// меняет местами регистры
void Dummy(char*);				// оставляет строку неизмененной
int func_ptr(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	void (*pfun)(char*);			// указывает на функцию, которая имеет аргумент
									// типа char * и ничего не возвращает
	printf("\033[1;4;32mЛистинг 14.16. Программа  func_ptr.c — использование указателей на функции\033[0m\n");
	puts("Введите строку (пустая строка - выход из программы):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0') {
		while ((choice = showmenu()) != 'n') {
			switch (choice) {		// оператор switch устанавливает указатель
			case 'u': pfun = ToUpper; break;
			case 'l': pfun = ToLower; break;
			case 't': pfun = Transpose; break;
			case 'o': pfun = Dummy; break;
			default: pfun = NULL;
			}
			strcpy_s(copy,LEN, line);		// сделать копию для show()
			show(pfun, copy);		// использовать выбранную функцию
		}
		puts("Введите строку (пустая строка - выход из программы):");
	}
	puts("Программа завершена.");
	return 0;
}
char showmenu(void){
	char ans;
	puts("Введите выбранный вариант из меню:");
	puts("u) нижний регистр				l) верхний регистр");
	puts("t) поменять местами регистры	о) исходный регистр");
	puts("n) следующая строка");
	ans = getchar();				// получить ответ
	ans = tolower(ans);				// преобразовать в нижний регистр
	eatline();						// избавиться от оставшейся части строки
	while (strchr("ulton", ans) == NULL){
		puts("Введите u, 1, t, о или n:");
		ans = tolower(getchar());
		eatline();
	}
	return ans;
}
void eatline(void) {
	while (getchar() != '\n') continue;
}
void ToUpper(char* str){
	while (*str){
		*str = toupper(*str);
		str++;
	}
}
void ToLower(char* str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}
void Transpose(char* str){
	while (*str){
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}
void Dummy(char* str) {
	// оставляет строку неизмененной
}
void show(void (*fp)(char*), char* str){
	(*fp)(str);			// применить выбранную функцию к str
	puts(str);			// отобразить результат
}
//====================================
//	вопросы для самоконтроля		||
//====================================
//1. Что неправильно в следующем шаблоне ?
struct myName {
	char itable;
	int num[20];
	char* togs;
};
//2. Н и ж е приведен фрагмент программы.Что он выведет ?
#include <stdio.h>
struct house {
	float sqft;
	int rooms;
	int stories;
	char address[40];
};
int quest2(void)
{
	struct house fruzt = { 1560.0, 6, 1, "22 Spiffo Road" };
	struct house* sign;
	sign = &fruzt;
	printf("%d %d\n", fruzt.rooms, sign->stories);
	printf("%s \n", fruzt.address);
	printf("%c %c\n", sign->address[3], fruzt.address[4]);
	return 0;
}
// 3. Разработайте шаблон структуры, которая будет содержать название месяца, его
//		трехбуквенную аббревиатуру, количество дней в месяце и его номер.
struct month
{
	char name[10];
	char abr[4];
	int nDdays;
	int num;
};
// 4. Определите массив из 12 структур вида, описанного в вопросе 3, и инициализируйте
//		ее для года, который не является високосным.
struct month months[12] = {
	{"январь",	"янв",31,1},
	{"февраль",	"фев",28,2},
	{"март",	"мар",31,3},
	{"апрель",	"апр",30,4},
	{"май",		"май",31,5},
	{"июнь",	"июн",30,6},
	{"июль",	"июл",31,7},
	{"август",	"авг",30,8},
	{"сентябрь","сен",31,9},
	{"октябрь",	"окт",30,10},
	{"ноябрь",	"ноя",31,11},
	{"декабрь",	"дек",30,12},
};
/*
5. Напишите функцию, которая после получения номера месяца возвращает общее
количество дней с начала года до конца указанного месяца. Предположите, что
шаблон структуры, описанный в вопросе 3, и подходящий массив таких структур
объявлены внешне.
*/
int getPassedDays(int month) {
	int d = 0;
	if (month < 1 || month>12) return 0;
	for (int i = 1; i <= month; i++) d += months[i-1].nDdays;
	return d;
}
int days145(void) {
	int m;
	printf("\033[1;4;32mПроверка знаний 14.5. Программа  days145.c — по номеру месяца возвращает общее количество дней с начала года до конца указанного месяца\033[0m\n");
	printf("Введите номер месяца(0 - выход из программы):");
	while (scanf_s("%d",&m)>0  && m>0) {
		//getPassedDays(m);
		printf("От начала года до конца %s прошло %d дней.\n", months[m-1].name, getPassedDays(m));
		puts("Введите номер месяца(0 - выход из программы):");
	}
	puts("Программа завершена.");
}
/*
б.а. Имея показанное ниже определение typedef, объявите 10-элементный массив
указанных структур. Затем с помощью присваивания индивидуальных членов
сделайте так, чтобы третий элемент этого массива описывал объектив марки
Rernarkatar с фокусным расстоянием 500 мм и диафрагмой f/2.0.
*/
#define MAXBRAND 29
#define MAXLENS 100
typedef struct lens {
	float foclen;
	float fstop;
	char brand[MAXBRAND+1];
} LENS;
int photoLens(void) {
	int n;
	char name[MAXBRAND+1];
	float foc;
	float diaf;
	LENS lensarr[MAXLENS];
/*
б. Повторите часть а), но воспользуйтесь в объявлении списком инициализации
с назначенным инициализатором вместо написания отдельных операторов
присваивания для каждого члена.
*/	
	LENS lensarr2[MAXLENS] = { [5]={.brand="Rkkkkk",.foclen=5000,.fstop=4.4}};
	printf("\033[1;4;32mПроверка знаний 14.6a. Программа  photoLens.c — Массив структур typedef LENS.\033[0m\n");
	printf("Введите номер элемента(1-MAXLENS), имя объектива, фокусное расстояние и диафрагму(через пробел)(0 - выход из программы):", MAXLENS);
	while (scanf_s("%d %s %f %f", &n, name, MAXBRAND,&foc,&diaf) > 0 && n > 0 && !(n> MAXLENS)) {
		strcpy_s(lensarr[n-1].brand, MAXBRAND,name);
		lensarr[n - 1].foclen = foc;
		lensarr[n - 1].fstop = diaf;
		eatline();
		printf("%d-ий элемент массива объективов- Бренд:%s \t фокус:%f \tдиафрагма:%f.\n",n, lensarr[n - 1].brand, lensarr[n - 1].foclen,lensarr[n - 1].fstop);
		printf("Введите номер элемента(1-MAXLENS), имя объектива, фокусное расстояние и диафрагму(через пробел)(0 - выход из программы):", MAXLENS);
	}
	puts("Программа завершена.");
}
// 7. Взгляните на следующий фрагмент кода :
struct name {
	char first[20];
	char last[20];
};
struct bem{
	int limbs;
struct name title;
char type[30];
};
/* а.Что выведут приведенные ниже операторы ?
 
*/
void printbem(struct bem* str);
int ques7(void) {
	struct bem* pb;
	struct bem deb = {
		6,
		{"Berbnazel", .last = "Gwolkapwolk"},
		"Arcturan"
	};
	pb = &deb;

	printf("%d\n", deb.limbs);
	printf("%s\n", pb->type);
	printf("%s\n", pb->type + 2);
	//б.Как можно было бы представить "Gwolkapwolk" в форме записи для структур (двумя способами) ?
	/*
	{"Berbnazel", .last="Gwolkapwolk"},
	*/
	/*
в. Напишите функцию, которая принимает адрес структуры bem в качестве своего
аргумента и выводит содержимое этой структуры в показанной ниже форме
(предположите, что шаблон структуры находится в заголовочном файле starfolk. h):
Berbnazel Gwolkapwolk - это 6-конечный Arcturan.
*/
	printbem(&deb);
}
void printbem(struct bem* str) {
	printf("%s %s - это %d-конечный %s.\n",str->title.first, str->title.last, str->limbs,str->type);
}

// 8. Взгляните на следующие объявления:
struct fullname {
char fname[20] ;
char lname[20];
} ;
struct bard {
struct fullname name;
int born;
int died;
} ;
int quest8(void) {
	struct bard willie;
	struct bard* pt = &willie;
	// а. Идентифицируйте член born структуры willie с помощью идентификатора willie.
	int b = willie.born;
	//б. Идентифицируйте член born структуры willie с помощью идентификатора pt.
	b = pt->born;
	//в. С помощью функции scanf() прочитайте значение для члена born, используя идентификатор willie.
	printf("Введите дату рождения(поле структуры):");
	scanf_s("%d", &(willie.born));
	printf("Введено %d.\n", willie.born);
	//г. С помощью функции scanf() прочитайте значение для члена born, используя идентифи катор pt.
	printf("Введите дату рождения(уазатель на поле структуры):");
	scanf_s("%d", &(pt->born));
	printf("Введено %d.\n", pt->born);
	eatline();
	//д. С помощью функции scanf() прочитайте значение для члена lname структуры name, используя идентификатор willie.
	printf("Введите фамилию(поле структуры):");
	scanf_s("%s", willie.name.lname,20);
	printf("Введено %s.\n", willie.name.lname);
	eatline();
	//е. С помощью функции scanf() прочитайте значение для члена lname структуры name, используя идентификатор pt.
	printf("Введите фамилию(уазатель на поле структуры):");
	scanf_s("%s", &(pt->name.lname),20);
	printf("Введено %s.\n", pt->name.lname);
	eatline();
	//ж. Создайте идентификатор для третьей буквы фамили, того, кто описан переменной willie.
	//typedef willie.name.lname[2] Fam3;
	//з. Напишите выражение, которое представляет общее количество букв в имени и фамили и того, кто описан переменной willie.
	printf("Введите фамилию и имя(через пробел):");
	scanf_s("%s %s", willie.name.lname, 20, willie.name.fname, 20);
	char chId = willie.name.lname[2];
	int count = strlen(willie.name.lname) + strlen(willie.name.fname);
	printf("Введено %s %s число символов=%d 3-й символ фамилии=%c.\n", willie.name.lname, willie.name.fname,count, chId);
	eatline();
}
/*
9. Определите шаблон структуры, подходящий для хранения следующих элементов:
марка автомобиля, его мощность в лошадиных силах, экологический рейтинг, колесная
база и год сборки. В качестве дескриптора шаблона используйте car.
*/
struct car
{
	char marka[20];
	float power;
	float ekorait;
	int willbase;
	struct data{
		int day;
		int month;
		int year;
	};
};
int quest9(void) {
	struct car a = { "VOLWO 12EW",123.5,90.3,4,{11,4,2023} };
	printf("Машина\nмарка \t\tмощьн л.с. \tэкорейтинг \tколёсная база \tдата сборки\n%s \t%.1f \t\t%.1f \t\t%d \t\t%d/%d/%d\n",a.marka,a.power,a.ekorait,a.willbase,a.day,a.month,a.year);
	//auto1.
}
/*
10. Предположим, что имеется следующая структура:
а. Напишите функцию, которая принимает аргумент struct gas. Предположите,
	что передаваемая структура содержит информацию distance и gals. 
	Эта функция должна вычислять корректное значение для члена mpg и возвращать уже заполненную структуру.
б. Напишите функцию, которая принимает в качестве аргумента адрес struct gas. 
	Предположите, что передаваемая структура содержит информацию
	distance и gals. Эта функция должна вычислять корректное значение для члена mpg и присваивать его.
*/
struct gas {
float distance;
float gals;
float mpg;
} ;
void func1410(struct gas* g);
void func1410s(struct gas g);
int quest10(void) {
	struct gas a = { 100,222 };
	func1410s(a);
	printf("\nВычисление gas.mpg с параметром-структурой. distance=%.1f  gals=%.1f mpg=%.1f\n",a.distance,a.gals,a.mpg);
	a.distance = 333;
	a.gals = 444;
	func1410(&a);
	printf("\nВычисление gas.mpg с параметром-указателем. distance=%.1f  gals=%.1f mpg=%.1f\n",a.distance,a.gals,a.mpg);
	//auto1.
}
void func1410(struct gas* g) {
	g->mpg = g->distance * g->gals;
}
void func1410s(struct gas g) {
	g.mpg = g.distance * g.gals;
}
/*
11. Объявите перечисление с дескриптором choices, которое устанавливает перечислимые
константы no, yes и maybe в 0, 1 и 2 соответственно.
*/
enum choices {	no, yes, maybe};
/*
12. Объявите указатель на функцию, которая возвращает указатель на char и принимает
в качестве аргументов указатель на char и значение char.
*/
char* funcpChar(char*,char);
/*13. Объявите четыре функции и инициализируйте массив указателей на них.
Каждая функция должна принимать два аргумента double и возвращать значение
double. Кроме того, продемонстрируйте два способа использования массива
для вызова второй функции с аргументами 10.0 и 2.5.*/
double f1(double, double);
double f2(double, double);
double f3(double, double);
double f4(double, double);
int quest12(void) {
	double (*pff[4])(double, double) = {f1,f2,f3,f4};
	for (int i = 0; i < 4; i++) printf("%lf \t\n", pff[i]((i+1)*11.1,(i+1)*22.2));
}
double f1(double p, double d) { printf("Вызвали f1( %lf,%lf)\t",p,d); return 111.111; }
double f2(double p, double d){ printf("Вызвали f2( %lf,%lf)\t", p, d); return 222.2222; }
double f3(double p, double d){ printf("Вызвали f3( %lf,%lf)\t", p, d); return 333.333; }
double f4(double p, double d){ printf("Вызвали f4( %lf,%lf)\t", p, d); return 444.444; }
