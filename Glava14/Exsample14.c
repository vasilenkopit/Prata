//#include <filesystem>
#include "string.h"
#include <Windows.h >
#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
#include <stdbool.h>
#include <ctype.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
void passnl(void) {
	while (getch() == '\n') {};		// пропустить конец строки
}

/*
Упражнения по программированию Глава 14.Структуры и другие формы данных
*/
/*                // Шаблон задачи 2

* /

int Exsample10(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
	do
	{

	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}

*/

bool getYes(char* quest) {
	char ch, * s, * q = "yYдДnNнН";
	int n;
	printf("%s(Да-\033[32myYдД\033[0m, Нет-\033[32mnNнН\033[0m):"INPUT1, quest);
	do {
		ch = getche();
		s = strchr(q, (int)ch);
		if (s != NULL) {
			n = s - q;
			break;
		}
		printf("\n\033[31mОшибка!\033[0m Требуется один из символов-\033[32m%s\033[0m:"INPUT1, q);
	} while (1);
	//getc(stdin);
	return (n < 4);
}
/*
1. Переделайте задание из вопроса 5 таким образом, чтобы аргумент был представлен
названием месяца, а не его номером. (Не забывайте о функции strcmp().)
Протестируйте готовую функцию в простой программе.
*/
struct month
{
	char name[10];
	char abr[4];
	int nDdays;
	int num;
};
struct month months1[12] = {
	{"январь",	"янв",31,1},
	{"февраль",	"фев",28,2},
	{"март",	"мар",31,3},
	{"апрель",	"апр",30,4},
	{"май",		"май",31,5},
	{"июнь",	"июн",30,6},
	{"июль",	"июл",31,7},
	{"август",	"авг",31,8},
	{"сентябрь","сен",30,9},
	{"октябрь",	"окт",31,10},
	{"ноябрь",	"ноя",30,11},
	{"декабрь",	"дек",31,12},
};
struct month monthsVisocos[12] = {
	{"январь",	"янв",31,1},
	{"февраль",	"фев",29,2},
	{"март",	"мар",31,3},
	{"апрель",	"апр",30,4},
	{"май",		"май",31,5},
	{"июнь",	"июн",30,6},
	{"июль",	"июл",31,7},
	{"август",	"авг",31,8},
	{"сентябрь","сен",30,9},
	{"октябрь",	"окт",31,10},
	{"ноябрь",	"ноя",30,11},
	{"декабрь",	"дек",31,12},
};
int days1(void);
#define MAX_NAME 20
int Exsample1(void)
{
	int i, beg, end;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 1. таблица квадратов и кубов с введёнными границами.\033[0m\n");
	do
	{
		days1();
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
/*
5. Напишите функцию, которая после получения номера месяца возвращает общее
количество дней с начала года до конца указанного месяца. Предположите, что
шаблон структуры, описанный в вопросе 3, и подходящий массив таких структур
объявлены внешне.
*/
int getPassedDays1(int month) {
	int d = 0;
	if (month < 1 || month>12) return 0;
	for (int i = 1; i <= month; i++) d += months1[i - 1].nDdays;
	return d;
}
int getnumday(char* day) {
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(months1[i].name, day)==0) return i + 1;
	}
	return 0;
}
int getnumdayabr(char* abr) {
	for (int i = 0; i < 12; i++)
	{
		if (strcmp(months1[i].abr, abr)==0) return i + 1;
	}
	return 0;
}
int days1(void) {
	char n[MAX_NAME+1];
	int m;
	printf("\033[1;4;32mПроверка знаний 14.5. Программа  days145.c — имени месяца возвращает общее количество дней с начала года до конца указанного месяца\033[0m\n");
	printf("Введите навание месяца(пробел - выход из программы):");
	while (scanf_s("%s", n, MAX_NAME) > 0 && n[0]!=' ') {
		m= getnumday(n);
		printf("От начала года до конца %s прошло %d дней.\n", months1[m - 1].name, getPassedDays1(m));
		puts("Введите навание месяца(пробел - выход из программы):");
	}
	puts("Программа завершена.");
}
/*
2. Напишите программу, которая предлагает пользователю ввести день, месяц и год.
Месяц может быть представлен порядковым номером, названием или аббревиатурой.
Затем программа должна возвратить общее количество дней, истекших с
начала года по указанный день включительно. (Учитывайте високосные годы.)
*/
struct Sdate { int day; int month; int year; };
int getmonth(void);
void getdate(struct Sdate* date);
int getPassedDaysVisocos(struct Sdate* date);
int getPassedDaysRegul(struct Sdate* date);
bool isVisocos(int year);
int Exsample2(void)
{
	int passDeys;
	char ch;
	struct Sdate date;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 2. возвратить общее количество дней, истекших с начала года по указанный день включительно. (Учитывайте високосные годы.)\033[0m\n");
	do
	{
		puts("");
		getdate(&date);
		if (isVisocos(date.year))
			passDeys=getPassedDaysVisocos(&date);
		else
			passDeys = getPassedDaysRegul(&date);
		printf("");
		printf("Введена дата %d/%d/%d. От начала %d года до %d числа %s прошло %d дней.\n",date.day,date.month,date.year,date.year, date.day, months1[date.month-1], passDeys);
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
void getdate(struct Sdate* date){
	int maxdays;
	printf("Введите год(XXXX):");
	scanf_s("%d", &(date->year));
	date->month = getmonth();
	maxdays = (isVisocos(date->year)) ? monthsVisocos[date->month - 1].nDdays : months1[date->month - 1].nDdays;
	printf("Введите день(1-%d):",maxdays);
	scanf_s("%d", &(date->day));
}
int getmonth(void) {
	char inpt[MAX_NAME+1];
	int n;
	printf("Введите месяц(имя(январь), сокращение(янв) или номер(1-12)):");
	scanf_s("%s", inpt, MAX_NAME);
	if ((n = getnumday(inpt)) > 0) return n;
	if ((n = getnumdayabr(inpt)) > 0) return n;
	return atoi(inpt);
}
int getPassedDaysVisocos(struct Sdate* date) {
	int d = 0;
	for (int i = 1; i <= date->month -1; i++) d += monthsVisocos[i - 1].nDdays;
	d += date->day;
	return d;
}
bool isVisocos(int year) {
	return (
			(!(year % 4) && (year % 100)) || 
			(!(year % 400))
		);
}
int getPassedDaysRegul(struct Sdate* date) {
	int d = 0;
	for (int i = 1; i <= date->month - 1; i++) d += months1[i - 1].nDdays;
	d += date->day;
	return d;
}
/*
3. Измените программу из листинга 14.2, чтобы она сначала выводила описания
книг в том порядке, в каком они вводились, затем в алфавитном порядке по названиям
и, наконец, в порядке возрастания цены.
*/
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* максимальное количество книг */
struct book { /* установка шаблона book */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

struct book library[MAXBKS]; /* массив структур типа book */
enum sorttype{not,name,autor,prise};
void manybook143Sort(int typsort, int count);
int manybook143Input(void);
int cmpname(void* op1, void* op2);
int cmpprise(void* op1, void* op2);
int cmpautor(void* op1, void* op2);
int Exsample3(void)
{
	int i, beg, count;
	char ch;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 3.  Измените программу из листинга 14.2,\n"
		"\tчтобы она сначала выводила описания книг в том порядке, в каком они вводились,\n"
		"\tзатем в алфавитном порядке по названиям и, наконец, в порядке возрастания цены.\033[0m\n");
	do
	{
		count=manybook143Input();
		manybook143Sort(not,count);
		manybook143Sort(name,count);
		manybook143Sort(autor, count);
		manybook143Sort(prise, count);
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
int manybook143Input(void)
{
	//struct book library[MAXBKS]; /* массив структур типа book */
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
	return count;
}
void manybook143Sort(int type, int count) {
	struct book lib[MAXBKS];
	int i=0;
	if (count < 1) {
		printf("Вообще нет книг? Очень плохо.\n");
		return;
	}
	memcpy(lib, library, sizeof(library));
	printf("Каталог ваших(%d) книг", count);
	switch (type) {
	case not:
		printf(" в беспорядке:\n");
		break;
	case name:
		printf(" в порядке названий:\n");
		qsort(lib, count,sizeof( struct book), cmpname);
			break;
	case autor:
		printf(" в порядке авторов:\n");
		qsort(lib, count, sizeof(struct book), cmpautor);
		break;
	case prise:
		printf(" в порядке цен:\n");
		qsort(lib, count, sizeof(struct book), cmpprise);
		break;
	default:
		break;
	}
	for (int index = 0; index < count; index++)
		printf("%3d:%s авторства %s: $%.2f\n", index + 1, lib[index].title,	lib[index].author, lib[index].value);
}
int cmpname(void* op1,void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return strcmp(pb1->title, pb2->title);
}
int cmpprise(void* op1, void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return pb1->value>=pb2->value;
}
int cmpautor(void* op1, void* op2) {
	struct book* pb1 = op1, * pb2 = op2;
	return strcmp(pb1->author, pb2->author);
}
/* 
4. Напишите программу, которая создает шаблон структуры с двумя членами в соответствии
   со следующими критериями.
а.	Первым членом является номер карточки социального страхования. 
	Второй член — это структура, состоящая из трех членов. 
		Ее первый член содержит имя, 
		второй член — отчество и 
		третий член — фамилию. 
	Создайте и инициализируйте массив из пяти таких структур. 
	Программа должна выводить данные в следующем формате:
Dribble, Flossie М. — 302039823
Выводиться должна только начальная буква отчества, за которой следует точка.
Разумеется, если этот член пуст, не должен выводиться ни инициал, ни точка.
Напишите функцию, которая выполняет такой вывод, передайте рассматриваемую структуру этой функции.
б. Модифицируйте часть а) так, чтобы вместо адреса передавалась сама структура.
*/
#define MAX1NAME 10
#define MAX2NAME 20
#define MAX3NAME 20
#define MAXCARDS 10
struct NAME { 
	char name1[MAX1NAME+1];
	char name2[MAX2NAME + 1];
	char name3[MAX3NAME + 1];
};
struct SICARD {					// social insurance card
	int sinum;
	struct NAME siname;
};
//struct SICARD* psicCard = NULL;
void sicOut1(struct SICARD sic);
void sicOut2(struct SICARD* sic);
int sicCreate(struct SICARD* sic, int max);
int Exsample4(void)
{
	int n, beg, end;
	char ch;
	struct SICARD* psicCard = NULL;

	//struct SICARD* psicCard=NULL;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 4. Печать данных карты социального страхования.\033[0m\n");
	do
	{
		n = sicCreate(&psicCard, MAXCARDS);
		for (int i = 0; i < n; i++)	{
			sicOut1(psicCard[i]);
		}
		for (int i = 0; i < n; i++)	{
			sicOut2(&psicCard[i]);
		}
		free(psicCard);
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
int sicCreate(struct SICARD** psic,int max) {
	int n, sinum;
	char siname1[MAX1NAME + 1], siname2[MAX2NAME + 1], siname3[MAX3NAME+1];
	printf("\nСоздание массива карточек социального страхования.\n");
loop:
	printf("Сколько карточек создаёте(не больше %d):", max);
	scanf_s("%d",&n);
	if (n == 0 | n > MAXCARDS) {
		printf("\033[31mОшибка!\033[0m Введено %d. Требуется целое >0 и < %d.\n",n,MAXCARDS);
		//passnl();
		goto loop;
	}
	if ((*psic = (struct SICARD*)calloc(n, sizeof(struct SICARD))) == NULL) {
		printf("\033[31mОшибка!\033[0m Недостаточно памяти(требуется %dбайт)./n",n* sizeof(struct SICARD));
		return 0;
	}
	//psicCard = psic;
	for (int i = 0; i < n; i++) {
		printf("Карточка %d. Введите Номер Фамилия Имя Отчество(через пробел):", i+1);
		if (scanf_s("%d %s %s %s", &sinum, siname1, MAX1NAME, siname2, MAX2NAME, siname3, MAX3NAME) == 4) {
			//passnl();
		}
		else {
			printf("\033[31mОшибка!\033[0m Введено не 4 значения. Повторить ввод.\n");
			i--;
			passnl();
			continue;
		}
		(*psic)[i].sinum = sinum;
		siname1[0] = toupper(siname1[0]);
		siname2[0] = toupper(siname2[0]);
		siname3[0] = toupper(siname3[0]);
		strcpy_s((*psic)[i].siname.name1,MAX1NAME, siname1);
		strcpy_s((*psic)[i].siname.name2,MAX1NAME, siname2);
		strcpy_s((*psic)[i].siname.name3,MAX1NAME, siname3);
	}
	return n;
}
void sicOut1(struct SICARD sic) {
	//char* s = "A.";
	//s[0] = sic.siname.name3[0];
	printf("%d \t%s \t%s \t%c.\n", sic.sinum, sic.siname.name1, sic.siname.name2, sic.siname.name3[0]);
}
void sicOut2(struct SICARD* sic) {
	//char* s = "A.";
	//s[0] = sic.siname.name3[0];
	printf("%d \t%s \t%s \t%c.\n", sic->sinum, sic->siname.name1, sic->siname.name2, sic->siname.name3[0]);
}
/*
5. Напишите программу, которая соответствуем следующим требованиям.
а. Программа внешне определяет шаблон сруктуры name с двумя членами: 
	строкой для хранения имени и строкой для хранения фамилии.
б. Программа внешне определяет шаблон структуры student с тремя членами:
	структурой name, массивом grade для хранения трех оценок в виде чисел с плавающей 
	запятой и переменной для хранения среднего значения этих трех оценок.
в. Программа содержит функцию main (), где объявляется массив из CSIZE(=4)
	структур student, в которых инициализируются члены name именами по вашему выбору. 
	Для выполнения задач, описанных в частях г), д),е) и ж), используйте функции.
г. Программа интерактивно вводит оценки для каждого студента, запрашивая
	у пользователя ввод имени студента и его оценок. Поместите оценки в массив
	grade соответствующей структуры. Требуемый цикл можно реализовать в
	main () или в специальной функции по вашему усмотрению.
д. Программа вычисляет среднюю оценку для каждой структуры и присваивает
	ее соответствующему члену.
е. Программа выводит информацию из каждой структуры.
ж. Программа выводит среднее значение по курсу для каждого числового члена структуры.
*/
#define MAXNAME 20
#define MAXSTUDENT 100
struct name {
	char name[MAXNAME];
	char fname[MAXNAME];
};
struct student {
	struct name;
	float grade[3];
	float average;
};
int studCreate(struct student** stdAr);
void studOut(struct student** stdAr, int n);
void studCount(struct student** stdAr, int n);
void studAverage(struct student** stdAr, int n);
int Exsample5(void)
{
	int i, beg, count;
	char ch;
	struct student (*studAr)[];
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание . Оценки студентов.\033[0m\n");
	do
	{
		count = studCreate(&studAr);
		studCount(&studAr, count);
		studOut(&studAr, count);
		studAverage(&studAr, count);
		free(studAr);
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
int studCreate(struct student** stdAr) {
	struct name name[MAXSTUDENT];
	float grade[MAXSTUDENT][3];
	int count=0,status;
	printf("Ввод списка успеваимости студентов.\nВводите: Фамилию Имя Оценка1 Оценка2 Оценка3(через пробел. 0-конец ввода).\n");
	do {
		printf("Студент %d:", count + 1);
		status=scanf_s("%s %s %f %f %f", name[count].fname, MAXNAME, name[count].name, MAXNAME, &grade[count][0], &grade[count][1], &grade[count][2]);
		if (status != 5) {
			printf("\033[31mОшибка!\033[0m Введено не 5 значений. Повторить ввод.\n");
			passnl();
			continue;
		}
		if (name[count].fname[0] == '0') break;
	} while (++count < MAXSTUDENT);
	if (count == 0) {
		printf("В список не введено ни одного студента.\n");
		return 0;
	}
	if ((*stdAr = (struct SICARD*)calloc(count, sizeof(struct student))) == NULL) {
		printf("\033[31mОшибка!\033[0m Недостаточно памяти(требуется %d байт)./n", count * sizeof(struct student));
		return 0;
	}
	for (int i = 0; i < count; i++)	{
		for (int j = 0; j < 3;j++ )(*stdAr)[i].grade[j] = grade[i][j];
		strcpy_s((*stdAr)[i].fname, MAXNAME, name[i].fname);
		strcpy_s((*stdAr)[i].name, MAXNAME, name[i].name);
	}
	return count;
}
void studOut(struct student** stdAr, int n) {
	printf("Список успеваимости студентов:\n");
	printf("Ном Фамилия \tИмя \t\t\t\tОценка1 Оценка2 Оценка3 Среднее\n");
	for (int i = 0; i < n; i++)	{
		printf("%3d %s \t%s \t\t\t\t%7.1f %7.1f %7.1f %7.1f\n", 
			i + 1, (*stdAr)[i].fname, (*stdAr)[i].name, 
			(*stdAr)[i].grade[0], (*stdAr)[i].grade[1], 
			(*stdAr)[i].grade[2], (*stdAr)[i].average);
	}
}
void studCount(struct student** stdAr, int n) {
	float av=0.;
	for (int i = 0; i < n; i++) {
		av = 0.;
		for (int j = 0; j < 3; j++)	{
			av += (*stdAr)[i].grade[j];
		}
		(*stdAr)[i].average=av/3.;
	}
}
void studAverage(struct student** stdAr, int n) {
	float av1 = 0., av2 = 0., av3 = 0., av = 0.;
	printf("Средние оценки по группе студентов:\n");
	for (int i = 0; i < n; i++) {
		av1 += (*stdAr)[i].grade[0];
		av2 += (*stdAr)[i].grade[1];
		av3 += (*stdAr)[i].grade[2];
		av += (*stdAr)[i].average;
	}
	printf("Оценка1=%5.1f\n", av1 / (float)n);
	printf("Оценка2=%5.1f\n", av2 / (float)n);
	printf("Оценка3=%5.1f\n", av3 / (float)n);
	printf("Средняя=%5.1f\n", av / (float)n);
}
/*
6. Текстовый файл содержит информацию о команде по софтболу (разновидность бейсбола). 
В каждой строке данные упорядочены следующим образом:
4 Джесси Джойбет 5 2 1 1
Первым членом является номер игрока (обычно это число из диапазона 0-18).
Второй член — это имя игрока, а третий — его фамилия. Каждое имя состоит из
одного слова. Следующий член показывает, 
сколько раз игрок принимал мяч, 
за которым следует количество нанесенных игроком ударов, 
проходов и 
засчитанных пробежек. 
Файл может содержать результаты более чем одной игры, следовательно,
для одного и того же игрока может быть несколько строк. 
Напишите программу, которая сохраняет соответствующие данные в массиве структур.
Структура должна состоять из членов, в которых представлены фамилия и имя,
количество набранных очков, проходов и засчитанных пробежек, а также средний
результат (эти значения вычисляются позже). В качестве индекса массива
можете использовать номер игрока. Программа должна выполнять чтение до
конца файла, и накапливать итоговые результаты по каждому игроку.
Мир статистики бейсбола довольно сложен. Например, проход или взятие базы
в результате ошибки не расценивается так же высоко, как тот же самый результат,
полученный за счет меткого удара, однако он позволяет получить выигранную
пробежку. Но эта программа должна только читать и обрабатывать файлы
данных, как описано ниже, не заботясь о реалистичности данных.
Простейший способ предусматривает инициализацию содержимого структуры
нулями, чтение данных из файла во временные переменные и затем их добавление
к содержимому соответствующей структуры. После того, как программа завершит
чтение файла, она должна вычислить средний уровень достижений для
каждого игрока и запомнить его в соответствующем члене структуры. Средний
уровень достижений вычисляется путем деления накопленного числа ударов, выполненных
игроком, на количество выходов на ударные позиции; вычисление
должно быть с плавающей запятой. Затем программа должна отобразить накапливаемые
данные по каждому игроку наряду со строкой, в которой содержатся
суммарные статистические данные по всей команде.
*/
#define MAXBALL 20
struct ball {
	int take;
	int hit;
	int pass;
	int jog;
};
struct softball {
	int numb;
	struct name;
	struct ball;
};
int softballCreate(struct softball* sb, int max, struct name* names, int N);
int NameListCreate(int max, char* filename, struct name* names, int N);
void NamesPrint(struct name* names, int n);
void FileNamesWrite(FILE* file, struct name* names, int n);

int Exsample6(void)
{
	int i, beg, count, countName;
	char ch;
	char FileName[MAX_NAME]="NameList.txt";
	struct name names[MAXSTUDENT];
	struct softball(* softballs)[]=NULL;
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("\n\033[1;4;44mЗадание 6. Статистика команды по софтболу.\033[0m\n");
	do
	{
		countName= NameListCreate(MAXSTUDENT, FileName, names, MAXSTUDENT);
		count = softballCreate(softballs, MAXBALL, names, countName);
	} while (getYes("\nЗапустить программу ещё разок?"));
	printf("\nКонец программы\n");
	return 0;
}
int softballCreate(struct softball** sb, int max, struct name *names,int N) {
	//struct name name[MAXSTUDENT];
	struct ball balls[MAXSTUDENT];
	int numbs[MAXSTUDENT];
	int i = 0, status, count;
	printf("Ввод статистических данных игроков софтболса.\nВводите: Мячей Ударов Проходов Пробежек(через пробел. 0-конец ввода).\n");
	do {
		printf("Игрок %d: %s %s ", i + 1,names[i].fname, names[i].name);
		status = scanf_s("%d %d %d %d", &balls[i].take, &balls[i].hit, &balls[i].pass, &balls[i].jog);
		if (names[i].fname[0] == '0' || i+1>=N) break;
		if (status != 4) {
			printf("\033[31mОшибка!\033[0m Введено не 4 числа. Повторить ввод.\n");
			passnl();
			continue;
		}
		i++;
	} while (i < MAXSTUDENT);
	if (i == 0) {
		printf("В список не введено ни одного спортсмена.\n");
		return 0;
	}
	count = i+1;
	if ((sb = (struct SICARD*)calloc(count, sizeof(struct student))) == NULL) {
		printf("\033[31mОшибка!\033[0m Недостаточно памяти(требуется %d байт).\n", count * sizeof(struct student));
		return 0;
	}
	for (int i = 0; i < count; i++) {
		//for (int j = 0; j < 3; j++)
		//memcpy_s( (*sb)[i].take, sizeof(struct ball), &balls[i], sizeof(struct ball));
		/**/
		(*sb)[i].take = balls[i].take;
		(*sb)[i].hit  = balls[i].hit;
		(*sb)[i].pass = balls[i].pass;
		(*sb)[i].jog  = balls[i].jog;
		strcpy_s((*sb)[i].fname, MAXNAME, names[i].fname);
		strcpy_s((*sb)[i].name, MAXNAME, names[i].name);
		/**/
	}
}
int NameListCreate(int max,char* filename, struct name* names, int N) {
	//struct name names[MAXSTUDENT];
	int status,count = 0;
	FILE* file;
	status = fopen_s(&file, filename, "r");
	if (!status) {
		count = FileNamesRead(file, names, MAXSTUDENT);
		fclose(file);
		NamesPrint(names, count);
	}
	else {
		printf("Ввод имён игроков. Вводите: Фамилию Имя.(0-конец ввода).\n");
		do {
			printf("Игрок %d:", count + 1);
			status = scanf_s("%s %s", names[count].fname, MAXNAME, names[count].name, MAXNAME);
			if (names[count].fname[0] == '0') break;
			if (status != 2) {
				printf("\033[31mОшибка!\033[0m Введено не 2 значения. Повторить ввод.\n");
				passnl();
				continue;
			}
			count++;
		} while (count < max);
		status = fopen_s(&file, filename, "w");
		if (status) perror("Ошибка открытия файла для записи");
		else {
			FileNamesWrite(file, names, count);
			fclose(file);
		}
	}

	return count;
}
int FileNamesRead(FILE* file,struct name* names,int max) {
	int status,count=0;
	do
	{
		status = fread_s(&names[count], sizeof(struct name), sizeof(struct name), 1, file);
		if (status > 0) count++;
	} while (status > 0);
	return count;
}
void NamesPrint(struct name* names,int n) {
	printf("Список игроков:\n");
	for (int i = 0; i < n; i++)	{
		printf("%2d %s \t%s\n",i+1,names[i].name,names[i].fname);
	}
}
void FileNamesWrite(FILE* file, struct name* names, int n) {
	int idx = 0;
	//while (idx<n) {
		fwrite(names,sizeof(struct name),n,file);
	//}
}
/*
7. Модифицируйте код в листинге 14.14 так, чтобы каждая запись читалась из фай­ла и отображалась,
чтобы была возможность удалить запись, и можно было изменить ее содержимое. 
Если вы удаляете запись, используйте освободившуюся позицию массива для чтения следующей записи. 
Чтобы разрешить изменение существующего содержимого, вместо режима "а+Ь" необходимо применять "r+b"
и уделять больше внимания установке указателя в файле, не допуская перезапи­сывание существующих записей добавляемыми записями. 
Проще всего внести все изменения в данные, хранящиеся в памяти, и затем записать всю финальную
информацию в файл. Один из возможных подходов к отслеживанию изменений
предполагает добавление в структуру каталога члена, который указывает, дол­жен ли он быть удален.
*/
// Листинг 14. 14. Программа booksave.с
/* booksave.c — сохранение содержимого структуры в файле */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10		/* максимальное количество книг */
//char* s_gets(char* st, int n);
struct book14 { /* определение шаблона book */

	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};
struct Library {
	int booksCount;
	struct book14* books;
};
void inBook(int c);
void delBook();
void listBook(FILE* pbooks, char* filename, int *count, int size);
void editBook();
void createLib(char* filename);
int Exsample7(void)
{
	struct book14 library[MAXBKS];	/* массив структур */
	struct Library lib;
	lib.books = library;
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book14);
	char* filename = "books.dat";
	printf("\033[1;4;32mЛистинг 14.14. Программа  booksave.c — сохранение содержимого структуры в файле\033[0m\n");
	//createLib(filename);
	if ((fopen_s(&pbooks, filename, "a+b")) != NULL)
	{
		printf("\033[31mОшибка!\033[0m Не удается открыть файл %s. ", filename);
		perror("");
		createLib(filename);
		//exit(1);
	}
	//listBook(pbooks, filename, &count, size);
	//rewind(pbooks); /* переход в начало файла */
	//while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	//{
	//	if (count == 0)	printf("Текущее содержимое файла %s:\n", filename);
	//	printf("%2d: %s авторства %s: $ %.2f\n",
	//		count + 1, library[count].title, library[count].author, library[count].value);
	//	count++;
	//}
	filecount = count;
	if (count == MAXBKS)
	{
		printf("Фaйл %s заполнен.\n", filename);
		exit(2);
	}
	puts("0-создать библиотеку\n1-вывод списка книг\n2-добавить книгу\n3-удалить книгу\n4-изменить книгу\0-завершить:");
	char code[2];
	s_gets(code, 2);
			switch (code[0]) {
	case '0':
		createLib(filename);
		break;
	case '1':
		listBook(pbooks, filename, &count, size);
		break;
	case '2':
		inBook(count);
		break;
	default:
		break;
	}
	if (count > 0)
	{
		puts("Каталог ваших книг:");
		for (index = 0; index < count; index++)
			printf("%2d: %s авторства %s: $%.2f\n", index + 1, library[index].title, library[index].author, library[index].value);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("Вообще нет книг? Очень плохо.\n");
	puts("Программа завершена.\n");
	fclose(pbooks);
	return 0;
}

//#include <string>
void inBook(int count) {
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

}
void listBook(FILE* pbooks,char* filename,int *count,int size) {
	int c = *count;
	rewind(pbooks); /* переход в начало файла */
	while (count < MAXBKS && fread(&library[c], size, 1, pbooks) == 1)
	{
		if (count == 0)	printf("Текущее содержимое файла %s:\n", filename);
		printf("%2d: %s авторства %s: $ %.2f\n",
			count + 1, library[c].title, library[c].author, library[c].value);
		c++;
	}
}
void createLib(char* filename) {
	char sfile[MAXNAME];// = "-------------------------------------------------------------------";
	char quest[100] = "Текущий файл библиотеки ";// +filename + ".Создать новую ?";
	strcpy_s(sfile, MAXNAME,filename);
	strcat_s(quest,100, sfile);
	strcat_s(quest, 100, ".Создать новую ?");
	int status;
	if (getYes(quest)) {
		printf("\nВведи имя файла:");
		status = scanf_s("%s", filename, MAXNAME);
	}
	//bool exist = std::filesystem::exists(filename);
}

