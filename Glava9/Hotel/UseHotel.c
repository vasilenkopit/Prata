// Ћистинг 9.9.”правл€ющий модуль usehotel.с
/* usehotel.c Ч программа определени€ стоимости номеров */
/* компилируетс€ вместе с листингом 9.10 */
#include <stdio.h>
#include "hotel.h" /* определ€ет константы, объ€вл€ет функции */
int usehotel(void)
{
	int nights;
	double hotel_rate;
	int code;
	printf("\n\033[1;4;44mЋистинг 9.9.ѕрограмма usehotel.c Ч программа определени€ стоимости номеров.\033[0m\n\n");
	while ((code = menu()) != QUIT)
	{
		switch (code)
		{
		case 1: hotel_rate = HOTEL1;
			break;
		case 2: hotel_rate = HOTEL2;
			break;
		case 3: hotel_rate = HOTEL2;
			break;
		case 4: hotel_rate = HOTEL4;
			break;
		default: hotel_rate = 0.0;
			printf("ќшибка!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("Ѕлагодарим за использование и желаем успехов.\n");
	return 0;
}