#include <stdio.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"

int set_mode1(int mode,int oldmode) {
	int m=mode;
	if (mode < 0 || mode>1) 
		printf("������ ������������ �����. ������������ ����� %d(%s).\n", m = oldmode, (oldmode == 0) ? "�����������" : "������������");
	return m;
}
void get_info1(int mode,double arr[]) {
	if (mode == 0) {
		printf("������� ���������� ���������� � ���������� :"INPUT3);
		scanf_s("%lf", arr);
		printf("������� ����� ���������������� ������� � ������:"INPUT3);
		scanf_s("%lf", arr+1);
	}
	else if (mode == 1) {
		printf("������� ���������� ���������� � �����:"INPUT3);
		scanf_s("%lf", arr);
		printf("������� ����� ���������������� ������� � ��������:"INPUT3);
		scanf_s("%lf", arr+1);
	}
}
void show_info1(int mode,double  arr[]) {
	if (mode == 0) {
		printf("������ ������� ���������� %.2lf ������ �� 100 ��.\n",arr[1]/arr[0]*100.);
	}
	else if (mode == 1) {
		printf("������ ������� ���������� %.1lf ���� �� ������.\n",arr[0]/arr[1]);
	}

}
