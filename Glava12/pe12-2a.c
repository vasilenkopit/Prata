#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
int mode;
double lenght;
double fuel;

void set_mode(int n) {
	if (n < 0 || n>1)
		printf("������ ������������ �����. ������������ ����� %d(%s).\n",mode,(mode==0)?"�����������":"������������");
	else mode = n;
}
void get_info(void) {
	if (mode == 0) {
		printf("������� ���������� ���������� � ���������� :"INPUT3);
		scanf_s("%lf", &lenght);
		printf("������� ����� ���������������� ������� � ������:"INPUT3);
		scanf_s("%lf", &fuel);
	}
	else if (mode == 1) {
		printf("������� ���������� ���������� � �����:"INPUT3);
		scanf_s("%lf", &lenght);
		printf("������� ����� ���������������� ������� � ��������:"INPUT3);
		scanf_s("%lf", &fuel);
	}
}
void show_info(void) {
	if (mode == 0) {
		printf("������ ������� ���������� %.2lf ������ �� 100 ��.\n",fuel/lenght*100.);
	}
	else if (mode == 1) {
		printf("������ ������� ���������� %.1lf ���� �� ������.\n",lenght/fuel);
	}

}
