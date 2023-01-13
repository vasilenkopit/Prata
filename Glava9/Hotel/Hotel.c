// Листинг 9.10.Модуль функций поддержки h o t e l.с
/* hotel.с — функции управления отелем */
#include <stdio.h>
#include "hotel.h"
int menu(void)
{
	int code, status;
	printf("\n%s%s\n", STARS, STARS);
	printf("Введите число, соответствующее выбранному отелю:\n");
	printf("1) Fairfield Arms    2) Hotel Olympic\n");
	printf("3) Chertworthy Plaza 4) The Stockton\n");
	printf("5) в ы х о д \n");
	printf("%s%s\n", STARS, STARS);
	while ((status = scanf_s("%d", &code)) != 1 || (code < 1 || code > 5))
	{
		if (status != 1)
			scanf_s("%*s");					// отбрасывание нецелочисленного ввода
		printf("Bвeдитe целое число от 1 до 5.\n");
	}
	return code;
}
int getnights(void)
{
	int nights;
	printf("Ha сколько суток вы бронируете номер? ");
	while (scanf_s("%d", &nights) != 1)
	{
		scanf_s("%*s"); // исключение нецелочисленного ввода
		printf("Bвeдитe целое число, такое как 2.\n");
	}
	return nights;
}
void showprice(double rate, int nights)
{
	int n;
	double total = 0.0;
	double factor = 1.0;
	for (n = 1; n <= nights; n++, factor *= DISCOUNT)
	total += rate * factor;
	printf("Общая стоимость составляет $%0.2f.\n", total);
}