/* shoesl.c -- ����������� ������ ����� � ����� */
#include <stdio.h>
#define ADJUST 7.31 // ���� �� ����� ������������� ���������
int shoes1(void)
{
	const double SCALE = 0.333; // ��� ���� ��� ������������� ���������
	double shoe, foot;
	printf("\n\033[41;1;4m��������� shoes1.\033[0m\n");
	shoe = 9.0;
	foot = SCALE * shoe + ADJUST;
	printf("������ �����(�������) ����� ������\n" ) ;
	printf("%10.1f %20.2f ������\n", shoe, foot);
	return 0;
}
/* shoes2.c -- ��������� ����� ����� ��� ���������� �������� ����� */
int shoes2(void)
{
	const double SCALE = 0.333; // ��� ���� ��� ������������� ���������
	double shoe, foot;
	printf("\n\033[41;1;4m��������� shoes2.\033[0m\n");
	printf("\n������ �����(�������) ����� ������\n");
	shoe = 3.0;
	while (shoe < 18.5) /* ������ ����� while */
	{ /* ������ ����� */
		foot = SCALE * shoe + ADJUST;
		printf("%10.1f %20.2f ������\n", shoe, foot);
		shoe = shoe + 1.0;
	} /* ����� ����� */
	printf("���� ����� ��������, ������ ��.\n");
	return 0;
}

/* wheat.c � ���������������� ���� */
#define SQUARES 64 // ���������� ������ ��������� �����
int wheat(void)
{
	const double CROP = 2E16; // ������� ������ ������� � ������
	double current, total;
	int count = 1;
	printf("\n\033[41;1;4m��������� � ������� � �������� � �������� wheat.\033[0m\n");
	printf("�������      ���������    �����       �po�e�� �� \n");
	printf("             �����        �����       �������� ������\n");
	total = current = 1.0;		/* �������� � ������ �������� */
	printf("%7d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES)
	{
		count = count + 1;
		current = 2.0 * current;
		/* ������� ���������� ����� �� ��������� ������ */
		total = total + current; /* �������� �������� ����� */
		printf("%7d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	}
	printf("��� � ���.\n");
return 0;
}
int divide(void)
/* divide.c -- �������, ����� �� ��� ����� */
{
	printf("\n\033[41;1;4m��������� ������� ����� divide.\033[0m\n");
	printf("������������� �������: 5/4 ����� %d \n", 5 / 4);
	printf("������������� �������: 6/3 ����� %d \n", 6 / 3);
	printf("������������� �������: 7/4 ����� %d \n", 7 / 4);
	printf("�e�e��e � ��������� �������: 7./4. ����� %1.2f \n", 7. / 4.);
	printf("C�e�a��oe �������: 7./4 ����� %1.2f \n", 7. / 4);
	return 0;
}
/* rules.c - - �������� ����������� */
int rules(void)
{
	int top, score;
	top = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("\033[7mtop = score = -(2 + 5) * 6 + (4 + 3 * (2 + 3))\033[0m top = %d, score = %d\n", top, score);
	return 0;
}
// sizeof.c � ������������� �������� sizeof
// � ������� ����������� ������������ � ��������� �99 ����������� %z; ���� � �����
// ������� ����������� %zd �� ��������������, ���������� ������ ���� %� ��� %lu
int psizeof(void)
{
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n = %d, n ������� �� %zd ������; ��� �������� int ����� %zd ������.\n",	n, sizeof n, intsize);
	return 0;
}
// min_sec.� -- ��������� ������� � ������ � �������
#define SEC_PER_MIN 60 // ���������� ������ � ������
int min_sec(void)
{
	int sec, min, left;
	printf("�epe�o� ������ � ������ � �������!\n");
	printf("������� ���������� ������ (<=� ��� ������):\n");
	scanf_s("%d", &sec); // ������ ���������� ������
	while (sec > 0)
	{
		min = sec / SEC_PER_MIN; // ��������� ���������� �����
		left = sec % SEC_PER_MIN; // ���������� ������ � �������
		printf("%d ������ - ��� %d �����(�) %d ������.", sec,	min, left);
		printf("������� ��������� �������� (<=� ��� ������):\n");
		scanf_s("%d", &sec);
	}
printf("������!\n");
return 0;
}

/* post_pre.c � ����������� � ���������� ����� */
int post_pre(void)
{
	int � = 1, � = 1;
	int a_post, pre_a;
	printf("\033[41;1;4mpost_pre.c ����������� � ���������� �����\033[0m\n");
	a_post = �++; // �������� �++ �� ����� ����� ������������
	pre_a = ++�; // �������� ++� �� ����� ����� ������������
	printf("a\t a_post\t pre_a \n");
	printf("%ld\t %5d\t %5d\n", �, a_post, pre_a);
	return 0;
}
/* ��������� ���������� */
int incProblem(void)
{
	int num = 0;
	printf("\033[41;1;4�������� ����������\033[0m\n");
	printf("\033[1;� �� ���������� �������� ���������� ��� ���������� � ����������, ������� �������� ������ ����� ��� ������ ��������� �������.\n");
	printf("� �� ����������� �������� ���������� ��� ���������� � ����������, ������� ���������� � ��������� ����� ������ ����.\033[0m\n");
	printf("1. ���������� ����� � ����� �������������� ������, ����� �������� ������� printf ��������� ������.\n");
	while (num < 21)
	{
		printf("\t%10d\t %10d\n", num, num * num++);
	}
	printf("2. ���������� ����� ��������� �������� �� � ��� �������, ������� �� ����� � ����.\n");
	int ans;
	ans = num / 2 + 5 * (1 + num++);
	printf("\t%10d\t %10d\n", num, ans);
	printf("3. �������� � �� ��������������, ����� ������ ���� ��������� � = n++ + n++;.\n");
	int n=3, y;
	y = n++ + n++;
	printf("\t%10d\t %10d\n", n, y);
}
/* addemup.c � ���� ����� ���������� */
int addemup(void) /* ������� ���� ������ 20 ����� ����� */
{
	int count, sum; /* �������� ���������� */
	printf("\033[41;1;4m���������. ������� ���� ������ 20 ����� �����\033[0m\n");
	count = 0; /* �������� ������������ */
	sum = 0; /* �������� ������������ */
	while (count++ < 20) /* �������� */
		sum = sum + count; /* while */
	printf("sum = %d\n", sum); /* �������� ������ ������� */
	return 0; /* �������� �������� */
}
/* convert.c -- �������������� �������������� ����� */
int convert(void)
{
	char ch;
	int i;
	float fl;
	printf("\033[41;1;4mconvert.c -- �������������� �������������� �����\033[0m\n");
	fl = i = ch = 'C';
	printf("ch = %c(%#x), i = %d, fl = %.2f\n", ch, ch, i, fl);
	ch = ch + 1;
	i = fl + 2 * ch;
	fl = 2.0 * ch + i;
	printf("ch = %�(%#x), i = %d, fl = %.2f\n", ch, ch, i, fl);
	ch = 1107;
	printf("������ ch = %c(%#x)\n", ch, ch);
	ch = 80.89;
	printf("������ ch = %c(%#x)\n", ch, ch);
	return 0;
}
/* pound.� -- ���������� ������� � ���������� */
void pound(int n); // ���������� ��������� ������� �������� ��������� ANSI
int call_pound(void)
{
int times = 5;
char ch = ' ! ';
float f = 6.0f;
// ASCII-��� ����� 33
printf("\033[41;1;4mpound.� -- ���������� ������� � ����������.\033[0m\n");
printf("�������� �99:\t�������� - ��� ����������� ��������\n\t\t�������� - ��� ���������� ��������\n");
printf("\t\t�������� � ��� ���������� �������, c ��������� ������������� �������� ������� � ���� �� ����������.\n");
for (int k = 0; k < 5; k++)for (int i = 0; i < 10; i++) if (i == 0) printf("%1d", k); else printf("."); printf("\n");
pound(times); // �������� ���� int
pound(ch); // ������������ pound((int)ch);
pound(f);
return 0;
}
// ������������ pound((int) f) ;
void pound(int n) // ��������� ������� � ����� ANSI, ������� ���������,
{ // ��� ������� ��������� ���� �������� int
	while (n-- > 0)
		printf("#");
printf("\n");
}
/* running.� */
const int	 S_PER_M = 60;		// ���������� ������ � ������
const int	 S_PER_H = 3600;	// ���������� ������ � ����
const double M_PER_K = 0.62137; // ���������� ���� � ���������
int running(void)
{
	double distk, distm;
	double rate;
	int min, sec;
	int time;
	double mtime;
	int mmin, msec;
	// ��������� ������� � ���������� � �����
	// ������� �������� � ����� � ���
	// ����� ������� � ������� � ��������
	// ����� ������� ������ � ��������
	// ����� ������� ����� ���� � ��������
	// ����� ������� ����� ���� � ������� � ��������
	printf("\033[41;1;4mrunning.� -- ����������� ����� ������� ���������.\033[0m\n");
	printf("��� �������� ����������� ����� ������� ��������� � ����������� �������\n");
	printf("�� ����� ������� ����� ���� � ��������� ���� �������");
	printf(" c��poc�� � ����� � ���\n");
	printf("������� ��������� ������� � ����������:___\b\b\b");
	scanf_s("%lf", &distk);			// %lf ��� ���� double
	printf("B�e���e ����� � ������� � ��������(����� ������):___ ___\b\b\b\b\b\b\b");
	//printf("Ha����e � ����� �����.\n");
	scanf_s("%d %d", &min, &sec);
	//printf("������ ������� �������.\n");
	//scanf("%d", &sec);
	// ��������� ����� � �������
	time = S_PER_M * min + sec;
	// ��������� ��������� � ����
	distm = M_PER_K * distk;
	// ��������� ���� � ������� �� ���������� ������ � ���� ���� ���������� ���� � ���
	rate = distm / time * S_PER_H;
	// ������� ������� �� ���������� ���� ����� ������� ����� ����
	mtime = (double)time / distm;
	mmin = (int)mtime / S_PER_M; // ���������� ������� ���������� �����
	msec = (int)mtime % S_PER_M; // ���������� ������� � ��������
	printf("�� ��������� %1.2f��(%1.2f����) �� %d���,%d���\n", distk, distm, min, sec);
	printf("����� �������� ������������� ������� ����� ���� �� %d���,", mmin);
	printf("%d���.\n���� ������� �������� ��������� %1.2f����/���(%1.2f��/���).\n", msec, rate, distk /(time/ (double)S_PER_H));
	return 0;
}