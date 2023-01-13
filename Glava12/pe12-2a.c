#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
int mode;
double lenght;
double fuel;

void set_mode(int n) {
	if (n < 0 || n>1)
		printf("Указан недопустимый режим. Используется режим %d(%s).\n",mode,(mode==0)?"европейский":"американский");
	else mode = n;
}
void get_info(void) {
	if (mode == 0) {
		printf("Введите пройденное расстояние в километрах :"INPUT3);
		scanf_s("%lf", &lenght);
		printf("Введите объем израсходованного топлива в литрах:"INPUT3);
		scanf_s("%lf", &fuel);
	}
	else if (mode == 1) {
		printf("Введите пройденное расстояние в милях:"INPUT3);
		scanf_s("%lf", &lenght);
		printf("Введите объем израсходованного топлива в галлонах:"INPUT3);
		scanf_s("%lf", &fuel);
	}
}
void show_info(void) {
	if (mode == 0) {
		printf("Расход топлива составляет %.2lf литров на 100 км.\n",fuel/lenght*100.);
	}
	else if (mode == 1) {
		printf("Расход топлива составляет %.1lf мили на галлон.\n",lenght/fuel);
	}

}
