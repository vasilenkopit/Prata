// Ћистинг 12.6.ѕрограмма partt.с
// partb.c -- остальна€ часть программы
// компилировать вместе с parta.c
#include <stdio.h>
extern int count;			// ссылочное объ€вление, внешнее св€зывание
static int total = 0;		// статическое определение, внутреннее св€зывание
void accumulate(int k);		// прототип
void accumulate(int k)		// k имеет область видимости в пределах блока, св€зывание отсутствует
{
	static int subtotal = 0; // статическа€ переменна€, св€зывание отсутствует
	if (k <= 0)
	{
		printf("итераци€ цикла: %d\n", count);
		printf("subtotal: %d; total: %d\n", subtotal, total);
		subtotal = 0;
	}
	else
	{
		subtotal += k;
		total += k;
	}
}