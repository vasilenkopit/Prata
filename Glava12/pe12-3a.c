#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

int set_mode1(int mode,int oldmode) {
	int m=mode;
	if (mode < 0 || mode>1) 
		printf("Указан недопустимый режим. Используется режим %d(%s).\n", m = oldmode, (oldmode == 0) ? "европейский" : "американский");
	return m;
}
void get_info1(int mode,double arr[]) {
	if (mode == 0) {
		printf("Введите пройденное расстояние в километрах :"INPUT3);
		scanf_s("%lf", arr);
		printf("Введите объем израсходованного топлива в литрах:"INPUT3);
		scanf_s("%lf", arr+1);
	}
	else if (mode == 1) {
		printf("Введите пройденное расстояние в милях:"INPUT3);
		scanf_s("%lf", arr);
		printf("Введите объем израсходованного топлива в галлонах:"INPUT3);
		scanf_s("%lf", arr+1);
	}
}
void show_info1(int mode,double  arr[]) {
	if (mode == 0) {
		printf("Расход топлива составляет %.2lf литров на 100 км.\n",arr[1]/arr[0]*100.);
	}
	else if (mode == 1) {
		printf("Расход топлива составляет %.1lf мили на галлон.\n",arr[0]/arr[1]);
	}

}
