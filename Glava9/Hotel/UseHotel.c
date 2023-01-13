// ������� 9.9.����������� ������ usehotel.�
/* usehotel.c � ��������� ����������� ��������� ������� */
/* ������������� ������ � ��������� 9.10 */
#include <stdio.h>
#include "hotel.h" /* ���������� ���������, ��������� ������� */
int usehotel(void)
{
	int nights;
	double hotel_rate;
	int code;
	printf("\n\033[1;4;44m������� 9.9.��������� usehotel.c � ��������� ����������� ��������� �������.\033[0m\n\n");
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
			printf("������!\n");
			break;
		}
		nights = getnights();
		showprice(hotel_rate, nights);
	}
	printf("���������� �� ������������� � ������ �������.\n");
	return 0;
}