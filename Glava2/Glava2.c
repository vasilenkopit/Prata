/* platinum, � -- ��� ��� � ���������� ����������� */
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdint>
#include <inttypes.h>
#include <string.h>		// ��� ��������� ������� strlen()
//#include <complex.h>

#define DENSITY 62.4	// �������� ����� �������� � ������ �� ���������� ���
#define PRAISE "�� - ���������� ��������."

using namespace std;
int test0(void);
int test1(void);
int test2(void);
int test3(void);
int test4(void);
int test5(void);
int test6(void);
int test7(void);
int test8(void);
int test9(void);
int test10(void);
int test11(void);
int test12(void);
int test13(void);
int test14(void);
int test15(void);
int test16(void);

int main(void)
{
	//SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
	//SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_ALL, "Russian");
	goto test;
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
test:
	test16();
	//char ch = getchar();
}
int test0(void)
{
	float weight = 0;	/* ��� ������������ */
	float value = 0;	/* ���������� ���������� */
	printf("������ ������ ���� ��� � ���������� �����������?\n");
	printf("������� ����������.\n");
	weight = 100;
	printf("����������, ������� ���� ���, ���������� � ������: %.2f:", weight);
	int result = scanf_s("%f", &weight);
	/* �������� ������� ������ �� ������������ */
	//scanf_s("%f", weight);
	/* �������, ��� ���� ����� ����� $1700 �� �������� ����� */
	/* 14.5833 ����������� ��� �������� ����, ����������� � ������, � �������� ����� */
	value = 1700.0 * weight * 14.5833;
	printf("��� ��� %.2f, � � ���������� ����������� ���������� $%.2f.\n", weight, value);
	printf("�� ����� ������ ����� ��������� �����! ���� ���� ������� ������,\n");
	printf("����� ������ ��� ����������� ����� ���������.\n");
	return 0;
}
int test1(void)
{
		int ten = 10;
		int two = 2;
		printf("\ntest1:\n");
		printf("����������� ���������: ");
		printf("%d ����� %d ����� %d\n", ten, 2, ten - two);
		printf("����������� �����������: ");
		printf("%d ����� %d ����� %d\n", ten/*, two, ten - two*/); // ��������� 2 ���������
		return 0;
}
int test2(void)
{
	printf("\ntest2:\n");
		int � = 100;
		long int estine=0;
		long johns = 0;
		short int erns= -32768;
		short ribs= 32767;
		unsigned int s_count= 65535;
		unsigned players= 65535-1;
		unsigned long headcount = 0;
		unsigned short yesvotes = 0;
		long long ago = 0;
		unsigned long long agoll = 0;
		printf("���������� = %d; ������������ = %o; ����������������� = %x; ����������������� = %X\n", �, �, �, �);
		printf("���������� = %d; ������������ = %#o; ����������������� = %#x; ����������������� = %#X\n", �, �, �, �);
		printf("MIN short int = %d; MAX short int = %#o; ����������������� = %#x; ����������������� = %#X\n", s_count, ribs, ribs, ribs);
		return 0;
}
int test3(void)
{
	printf("\ntest3 ����������� unsigned, long, long long:\n");
	unsigned int un = 3000000000; /* ������� � 32-������ ����� int */
	short end = 200; /* � 16-������ ����� short */
	long big = 65537;
	long long verybig = 12345678908642;
	printf("un = %u, �� �� %d\n", un, un);
	printf("end = %hd � %d\n", end, end);
	printf(" ig = % ld, �� ��% hd\n", big, big);
	printf("very�ig = %lld, �� �� %ld\n", verybig, verybig);
	return 0;
}
int test4(void)
{
	printf("\ntest4 ������(����� ������ ���� �������     z):\n");
	unsigned char ch;
	int numLoop = 0;
loop:	//scanf_s("%c", &ch); /* ������������ ������ ������ */
	printf("%d.\t������� �����-������ ������:",++numLoop);
	ch = _getch();
	printf("\tKo� ������� %c ����� %#uhx.\n", ch, ch);
	if (ch != 'z') goto loop;
	return 0;
}
int test5(void)
{
	printf("\ntest5 ����������� ���� ����� leastNN_t fastNN_t intNN_t intmax_t uintmax_t\n");
	int_least8_t lint = 0;
	int_fast8_t fint = 0;
	int32_t i32 = 0;
	intmax_t intMax = 0;
	uintmax_t uintMax = 0;
	int32_t me32 = 0; // me32 -- ��� 32-������ ���������� �� ������
	me32 = 45933945;
	printf("������� �����������, ��� int32_t �������� int: ");
	printf("me32 = %d\n", me32);
	printf("����� �� ����� ������ ������� �������������. \n");
	printf("������ ����� ������������� \"��������\" �� ����� inttypes.h: ");
	printf("me32 = %" PRId32 "\n", me32);
	return 0;
}
int test6(void)
{
	printf("\ntest6 ����������� ���� ����� PRIdLEAST8-PRIdLEAST64 \n");
	/*
	printf("
	PRId8        "hhd"
	PRId16       "hd"
	PRId32       "d"
	PRId64       "lld"
	PRIdLEAST8   PRId8
	PRIdLEAST16  PRId16
	PRIdLEAST32  PRId32
	PRIdLEAST64  PRId64
	PRIdFAST8    PRId8
	PRIdFAST16   PRId32
	PRIdFAST32   PRId32
	PRIdFAST64   PRId64
	PRIdMAX      PRId64
	\n");
	*/
	return 0;
}
int test7(void)
{
	printf("\ntest7 ���� float double long double \n");
	//float floHex = 0��.1fp10;
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f ����� ���� �������� ��� %e\n", aboat, aboat);
	// ��� ������ ��������� ������ ��������� ����������,
	// �������������� �99 ��� ����� ������� ��������
	printf("� ��� %a � �����������������, �������������� ������� 2, ����� ������\n", aboat);
	printf("%f ����� ���� �������� ��� %e\n", abet, abet);
	printf("%Lf ����� ���� �������� ��� %Le\n", dip, dip);
	return 0;
}
int test8(void)
{
	printf("\ntest8 ������������ float ��������� inf, ���� infinity\n");
	float toobig = 3.4E38;
	printf("����������� %e * %e = %e\n", toobig, 100.0f, toobig * 100.0f);
	return 0;

}
int test9(void)
{
	printf("\ntest9 ������ ����������\n");
	float a, b;
	b = 2.0e20 + 1.0;
	a = b - 2.0e20;
	printf("%f \n", a);
	return 0;
}
int test10(void)
{
	//_Bool log = 1;
	printf("\ntest10 ����������� �����\n");
	//_Fcomplex fcplx1 = _FCbuild(1, 2);
	//_Fcomplex fcplx2 = _FCbuild(3, 4);
	//double complex z1 = 1.0 + 3.0 * I;
	//double complex z2 = 1.0 - 4.0 * I;
	//_FCmulcc(fcplx1, fcplx2);
	return 0;
}
int test11(void)
{
	printf("\ntest11 ������� �����\n");
	/* � ��������� �99 ��� �������� ������������ ������������ %zd */
	printf("��� \t\t������(����):\n");
	printf("char \t\t%zd\n", sizeof(char));
	printf("int \t\t%zd\n", sizeof(int));
	printf("long \t\t%zd\n", sizeof(long));
	printf("long long \t%zd\n", sizeof(long long));
	printf("double \t\t%zd\n", sizeof(double));
	printf("long double \t%zd\n", sizeof(long double));
	printf("float \t\t%zd\n", sizeof(float));
	printf("long float \t%zd\n", sizeof(long float));
	return 0;
}
int test12(void)
{
	printf("\ntest12 ������ ����� � printf\n");
	int n = 4;
	int m = 5;
	float f = 7.0f;
	float g = 8.0f;
	printf("��� ���������� ��� ����� ���� �������. %d\n", n, m);	/*������� ����� ���������� * /
	printf("3 �������, �� ���� ����������. \t%d %d %d\n", n);		/* ���������� ������������ */
	printf("������ ������, � ���������� float. \t%d %d\n", f, g);	/* ������������ ���� �������� */
	printf("������ float, � ���������� �����. \t%f %f\n", n, m);	/* ������������ ���� �������� */
	return 0;
}
int test13(void)
{
	printf("\ntest13 ������������� ����������� �������������������\n");
	float salary;
	printf("\a������� �������� ����� �������� ��������:");	/* 1 \a-�������� ������ */
	printf(" $_______\b\b\b\b\b\b\b");						/* 2 \b- ������� �� 1 ������� */
	scanf_s("%f", &salary);
	printf("\n\t$%.2f � ����� ������������� $%.2f � ���.", salary, 	salary *12.0);		/* 3 \t-��������� */
	printf("\rOro!\n");			/* 4 \r- � ������ ������ */
	return 0;
}
int test14(void)
{
	printf("\ntest14 ������� 1. ������������ � ������ ����������\n");
	float fMax= 3.402823466e+38F, fMin= 1.175494351e-38F, fEps= 1.192092896e-07F;
	float hMin= SHRT_MIN, hMax= SHRT_MAX;
	short int iMin = SHRT_MIN, iMax = SHRT_MAX;
	printf("float min=%f \t max=%f.\n", fMin, fMax);
	printf("float ������=%f \t ������������=%f\n", fMin - fEps, fMax + 1+fEps);
	printf("float min=%f \t max=%f.\n",hMin,hMax);
	printf("float ������=%f \t ������������=%f\n", hMin-1, hMax+1);
	printf("int min=%d \t max=%d.\n", iMin, iMax);
	iMin--; iMax++;
	printf("int ������=%d \t ������������=%d\n", iMin, iMax);
	return 0;
}
int test15(void)
{
	printf("\ntest15 ������� 2,3,4. ������ ��� ������� � ����������� ������\n");
	char c='1';
	int ic;
	float f=0.0;
	//2
	printf("������� 2\n");
	printf("����� ��� �������:\n");
	scanf_s("%d", &ic);
	printf("����� ���(%d) �������   %c.\n", ic, ic);
	//3
	printf("������� 3\n");
	printf("\a���������� ��������� ������, ���� ���������� :\n"
	"�� ��� ���� �����, ��� ��� ����!\n");
	//4
	/*������� �������� � ��������� �������: 64.25
	������ � ������������� �������: 64.250000
	���������������� ����� ������: 6.425000e+Ol
	�������-���������������� �������������: Oxl.Olp+6
	*/
	printf("������� 4\n");
	//_getch();
	printf("������� �������� � ��������� �������:\t");
	scanf_s("%f", &f);
	printf("������ � ������������� �������:\t%f\n", f);
	printf("���������������� ����� ������:\t%e\n", f);
	printf("�������-���������������� �������������:\t%0x.0p\n", f);
	//5
	/*5. � ���� ���������� �������� 3.156�107 ������. �������� ���������, �������
	���������� ������ ������� � �����, � ����� ������� �� ����� ������������� ��������
	� ��������.	*/
	int years=0;
	long float secInYear = 3.156E107,secs;
	printf("������� 5\n");
	printf("������� ��� ���:___\b\b\b");
	//_getch();
	scanf_s("%d",&years);
	secs = years * secInYear;
	printf("��� ������� ��� ������: \n%Le \n%Lf\n",secs,secs );
	//6
	/*6. ����� ����� �������� ���� �������������� ���������� 3.�*10E23 �����. ������
	���� ����� �������� 950 �����. �������� ���������, ������� ���������� ������
	�������� ������ ���� � ������� � ���������� ���������� ������� ���� �
	���� ������.*/
	printf("������� 6\n");
	printf("������ ����� ����(�����):___\b\b\b");
	float vol = 0.0, weigth= 950;
	long float weigthw = 3.0E-23;
	scanf_s("%f", &vol);
	printf("� ���� ������ ��������� %Le ������� ����.\n", (vol * weigth) / weigthw);
	//7
	/*7. � ����� ������� 2.54 ����������. �������� ���������, ������� ����������
	������ ���� � ������, ����� ���� ������� �� ����� ���� ���� � �����������.
	����, ���� ��� ��� ������ ��������, ��������� ����� ����������� ���� � �����������
	� ���������� ��� � �����.*/
	float high = 0., d=2.54;
	printf("������� 7\n");
	printf("������ ����(��):___\b\b\b");
	scanf_s("%f", &high);
	printf("������:%.2f \t������:%1.2f \t�����������:%.3e\n", high / d, high / 100., high * 10.);
	//8
	/*8. � ������������ ������� ������ ��������� ������ ����� ����� 2 ������, �����
	� 8 ������, ����� � 2 �������� ������, � �������� ����� � 3 ������ ������.
	�������� ���������, ������� ���������� ������ ����� � ������ � ����������
	������������� �������� � ������, ������, �������� ������ � ������ ������. 
	������ ��� ���� ��������� ��� � ��������� ������� �������� ������, ��� �������������?*/
	int pint_ch = 2, ch_u = 8, u_sl = 2, sl_cl = 3;
	float pint,unch,sl,cl;
	printf("������� 8. ������� ��������� ������ � �������\n");
	printf("������ ����� ��������(� ������):");
	scanf_s("%f", &vol);
	pint = vol / pint_ch;
	unch = vol * ch_u;
	sl = unch * u_sl;
	cl = sl * sl_cl;
	printf("�����:%.1f \t�����:%.2f \t�������� �����:%.1f \t������ �����:%.1f.\n", pint, unch, sl, cl);
	return 0;
}
int test16(void)
{
	float weight, volume;
	int size, letters;
	char name[40]; // name ������������ ����� ������ �� 40 ��������
	//goto NEX;
	printf("������������! ��� ��� �����?:");
	scanf_s("%s", name);
	printf("������, %s, ������� �� ������ � ������?:", name);
	scanf_s("%f", &weight);
	size = sizeof name;
	letters = strlen(name);
	volume = weight / DENSITY;
	printf("������, %s, ��� ����� ���������� %2.2f ���������� �����.\n", name, volume);
	printf("� ���� �� ���� ��� ������� �� %d ����,\n", letters);
	printf("^ �� ����������� 40 ������� ��� ��� ����������.\n", size);
	//
NEX:
	char name16[40]="����";
	printf("Ka� ��� �����? ");
	scanf_s("%s", name16);
	printf("������������, %s. %s\n", name16, PRAISE);
	return 0;
}