/* ������� 6.1. summing.c -- ��������� ����� �����, ������� � ������������� ������ */
#include <stdio.h>
int summing(void)
{
	long num;
	long sum = 0L; /* ������������� ���������� surn ����� */
	int status;
	printf("\n\033[41;1;4m��������� summing.\033[0m\n");
	printf("������� ����� ����� ��� ������������ ������������ ");
	printf("(��� q ��� ���������� ���������):___\b\b\b");
	status = scanf_s("%ld", &num);
	while (status == 1)				/* == ���������� ��������� */
	{
		sum = sum + num;
		printf("������� ��������� ����� ����� (��� q ��� ���������� ���������):___\b\b\b");
		status = scanf_s("%ld", &num);
	}
	printf("����� ��������� ����� ����� ����� %ld.\n", sum);
	return sum;
}
// ������� 6.2.��������� when.�
// when.c -- ����� ���� �����������?
int when(void)
{
	int n = 5,loop=10,i=0;
	printf("\n\033[41;1;4m��������� when.c -- ����� ���� �����������?.\033[0m\n");
	while (n++ < loop)					// ������ 7
	{
		printf("���������� ���� ����� %d ���. \nn = %d\n",++i, n);
		n++;							// ������ 10
		printf("������ n = %d\n", n);	// ������ 11
	}
	printf("���� ��������.\n");
	return 0;
}
// ������� 6.3.��������� whilel.�
/* while1.c -- ������� �� ��������� �������� */
/* ������������ ����������� ����� ��������� � ������������ ����� */
int while1(void)
{
	int n = 0,i=0;
	printf("\n\033[41;1;4m��������� while1.c -- ������� �� ��������� ��������. �����������.\033[0m\n");
	while (n < 3)
		{printf("n ����� %d\n", n); if (i++ > 20) break;}
		n++;
	printf("��� ���, ��� ������ ������ ���������.\n");
	return 0;
}
// ������� 6.4.��������� while2.�
/* while2.c -- ��������� ������������ ����� � ������� */
int while2(void)
{
	int n = 0;
	printf("\n\033[41;1;4m��������� while2.c -- ��������� ������������ ����� � �������. ��� ���� �����.\033[0m\n");
	while (n++ < 3);				/* ������ 7 */
	printf("n ����� %d\n", n);		/* ������ 8 */
	printf("��� ���, ��� ������ ������ ���������.\n");
	return 0;
}
// ������� 6.5.��������� cmpflt.c
// cmpflt.c -- ��������� ����� � ��������� �������
#include <math.h>
int cmpflt(void)
{
	const double ANSWER = 3.141592653589793;
	double response;
	int status,i=1;
	printf("\n\033[41;1;4m��������� cmpflt.c -- ��������� ����� � ��������� �������.\033[0m\n");
	printf("������ �������� ����� pi(q - �����)?:______\b\b\b\b\b\b");
	status = scanf_s("%lf", &response); if (status != 1) return 0;
	while (fabs(response - ANSWER) > 0.0001)
	{
		printf("B�e���e �������� %d-� ���(q - �����):______\b\b\b\b\b\b",++i);
		status = scanf_s("%lf", &response); if (status != 1) break;
	}
	printf("pi=%lf, �� ����� %lf, ������=%lf. �� ������� %d �������!\n", ANSWER, response, fabs(response - ANSWER),i);
	return 0;
}
// ������� 6.6.��������� t_and_f.c
/* t_and_f.c � �������� � ������ �������� � ����� � */
int t_and_f(void)
{
	int true_val, false_val;
	printf("\n\033[41;1;4m��������� t_and_f.c � �������� � ������ �������� � ����� �.\033[0m\n");
	true_val = (10 > 2);		// �������� ��������� ���������
	false_val = (10 == 2);		// �������� ������� ���������
	printf("true = %d; false = %d \n", true_val, false_val);
	return 0;
}
// ������� 6.7.��������� truth.�
// truth.c � ����� �������� �������� ���������?
int truth(void)
{
	int n = 3;
	printf("\n\033[41;1;4m��������� truth.c � ����� �������� �������� ���������?\033[0m\n");
	while (n)
	printf("%2d �������� ��������\n", n--);
	printf("%2d �������� ������\n", n);
	n = -3;
	while (n)
	printf("%2d �������� ��������\n", n++);
	printf("%2d �������� ������\n", n);
	return 0;
}
// ������� 6.8.��������� t r o ^ l e.�
// trouble.c -- ������������ ���������� �������� =
// �������� � ������������� ������������ �����
int trouble(void)
{
	long num;
	long sum = 0L;
	int status,i=0;
	printf("\n\033[41;1;4m���������  trouble.c -- ������������ ���������� �������� =\033[0m\n");
	printf("������� ����� ����� ��� ������������ ������������");
	printf("(��� q ��� ���������� ��������):___\b\b\b");
	status = scanf_s("%ld", &num);
	while(status = 1)
	{
		sum = sum + num;
		printf("������� ��������� ����� ����� (��� q ��� ���������� ���������):___\b\b\b");
		status = scanf_s("%ld", &num);	if (i++ > 20) { printf("\n\033[41;30m��������� ����� �� ������������!\033[0m\n"); break; }
	}
	printf("Cy��a ��������� ����� ����� ����� %ld.\n", sum);
	return 0;
}
// ������� 6.9.��������� toolean.�
// boolean.c � ������������� ���������� ���� _Bool
#include <stdio.h>
int boolean(void)
{
	long num;
	long sum = 0L;
	_Bool input_is_good;
	printf("\n\033[41;1;4m���������  boolean.c � ������������� ���������� ���� _Bool\033[0m\n");
	printf("������� ����� ����� ��� ������������ ������������");
	printf("(��� q ��� ���������� ��������):___\b\b\b");
	input_is_good = (scanf_s("%ld", &num) == 1);
	while(input_is_good)
	{
		sum = sum + num;
		printf("������� ��������� ����� �����(��� q ��� ���������� ���������):___\b\b\b");
		input_is_good = (scanf_s("%ld", &num) == 1);
	}
	printf("����� ��������� ����� ����� ����� %ld.\n", sum);
	return 0;
}
//������� 6 .1 0.��������� sweetiel.c
// sweetiel.c -- ���� �� ���������
int sweetiel(void)
{
	const int NUMBER = 22;
	int count = 1;				// �������������
	printf("\n\033[41;1;4m���������  sweetiel.c -- ���� �� ���������\033[0m\n");
	while(count <= NUMBER)		// ��������
	{
		printf("���� ���� ������! %d ���.\n",count); // ��������
		count++;				// ���������� �������� count
	}
	return 0;
}
// ������� 6.11.��������� sweetie2.�
// sweetie2.c � ���� for �� ���������
int sweetie2(void)
{
	const int NUMBER = 22;
	int count;
	printf("\n\033[41;1;4m���������  sweetie2.c � ���� for �� ���������\033[0m\n");
	for(count = 1; count <= NUMBER; count++)
		printf("���� ���� ������! %d ���.\n", count);
	return 0;
}
// ������� 6.12. ��������� for_cube.c
/* for_cube.c � ������������� ����� for ��� ���������� ������� ����� */
int for_cube(void)
{
	int num,max=1;
	long qube;
	printf("\n\033[41;1;4m���������  for_cube.c � ������������� ����� for ��� ���������� ������� �����\033[0m\n");
	printf("������� ��������� ����� �������:___\b\b\b");
	scanf_s("%d", &max);
	printf("    n \tn � Ky6e\n");
	for(num = 1; num <= max; num++)
	{
		qube = (long)num * (long)num * (long)num; if (qube < 0) { printf("\n\033[41;30m��������� ����� - ������������!\033[0m\n"); break; }
		printf("%5d \t%5ld\n", num, qube);
	}
	return 0;
}
/* for_down.c */
int for_down(void)
{
	int secs;
	printf("\n\033[41;1;4m���������  for_down.c � ������������� ����� for � �����������.\033[0m\n");
	for(secs = 5; secs > 0; secs--)
		printf("%d ������(�)!\n", secs);
	printf("���� �� ���������!\n");
	return 0;
}
// � ��� ������� ����� ������� ��������, ��������� � �.�.
/* for_13s.c  ���� � ���������� 13, ������� � 2 */
int for_13s(void)
{
	int n;			// ���� � ���������� 13, ������� � 2
	printf("\n\033[41;1;4m���������  for_13s.c � ������������� ����� for ���� � ���������� 13, ������� � 2\033[0m\n");
	for(n = 2; n < 60; n = n + 13)
		printf("%d \n", n);
	return 0;
}
// � ����� ������ ������� �� ��������, � �� ������.
/* for_char.c */
int for_char(void)
{
	char ch;
	printf("\n\033[41;1;4m���������  for_char.c � ������������� ����� for ������� �� ��������\033[0m\n");
	for (ch = '�'; ch <= 'z'; ch++)
		printf("�������� ASCII ��� %c ����� %d(%#2x).\n", ch, ch,ch);
	return 0;
}
/* � ����� ��������� ��������� �������� ����� �� � ��������������, � � ��������������
����������; �.�.������ ���������� ������ ��� �������������� ��������
����� �������� �� ������������� ��������. */
/* for_geo.c */
int for_geo(void)
{
	printf("\n\033[41;1;4m���������  for_char.c � ������������� ����� for ��� �������������� ����������; \033[0m\n");
	double debt;
	for(debt = 100.0; debt < 150.0; debt = debt * 1.1)
		printf("������ ���� ������������� ���������� $%.2f.\n", debt);
	return 0;
}
/* � � �������� �������� ��������� ����� ������������ ����� ���������� ���������.
��� �� �� ����� �� ���������, ��� ����� ����������� �� ������ ��������. */
/* for_wild.c */
int for_wild(void)
{
	int x;
	int � = 55;
	printf("\n\033[41;1;4m���������  for_wild.c � ������������� ����� for. � �������� �������� ��������� ����� ������������ ����� ���������� ���������.\033[0m\n");
	for(x = 1; � <= 75; � = (++x * 5) + 50)
		printf("%10d %10d\n", x, �);
	return 0;
}
/* � ����� ���� �������� ���� ��� ��������� ��������� ������� (�� �� ���������
����� � �������). ���������� ������� � ����� ���������, ������� � ��������
����� �������� � ���������� �����. */
/* for_none.c */
int for_none(void)
{
	int ans, n;
	ans = 2;
	printf("\n\033[41;1;4m���������  for_none.c � ������������� ����� for. ����� ���� �������� ���� ��� ��������� ��������� �������.\033[0m\n");
	for(n = 3; ans <= 25; )
	{
		ans = ans * n;
		printf("n = %d; ans = %d.\n", n, ans);
	}
	return 0;
} 
/*� ������ ��������� �� ����������� ������ ���������������� ����������.
������ ����� �� ����� �� ���� �����-�� ������������� ��������� printf ().
������ ���������, ��� ������ ��������� ����������� ��� ����������� ������
���� ���, �� ���� ��� ������ ����������� ������ ����� �����. */
/* for_show.c */
int for_show(void)
{
	int num = 0;
	printf("\n\033[41;1;4m���������  for_show.c � ������������� ����� for. ������ ��������� �� ����������� ������ ���������������� ����������.\033[0m\n");
	for(printf("����������� ������� �����(���� �� ������ 6)!\n"); num != 6; )
	scanf_s("%d", &num);
	printf("��� �� �����, ������� ���� �����!\n");
	return 0;
}
// ������� 6.13. ��������� postage. �
// postage.c -- ������ ��������� ������������ ������� ������
int postage(void)
{
	const int FIRST_OZ = 46;	// ����� 2013 ����
	const int NEXT_OZ = 20;		// ����� 2013 ����
	int ounces, cost;
	int x, y, z;
	printf("\n\033[41;1;4m���������  postage.c � ������������� ����� for. ��������� '�������'.\033[0m\n");
	printf(" ����� \t�����\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
		printf("%5d \t$%4.2f\n", ounces, cost / 100.0);
	x = (y = 3, (z = ++y + 2) + 5);
	printf("x = (y = 3, (z = ++y + 2) + 5); � ����������: x=%d y=%d z=%d\n", x, y, z);
	return 0;
}
// ������� 6.14.��������� zeno.�
/* zeno.c � ���� ������������������ */
	int zeno(void)
{
	int t_ct; // ������� ���������
	double time, power_of_2;
	int limit;
	printf("\n\033[41;1;4m���������  zeno.c � ������������� ����� for. ��������� ������� ����� � ���� for.\033[0m\n");
	printf("������� �������� ���������� ��������� ������������������:___\b\b\b ");
	scanf_s("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit; t_ct++, power_of_2 *= 2.0)
	{
		time += 1.0 / power_of_2;
		printf("����� = %f, ����� ���������� ��������� = %d.\n", time, t_ct);
	}
	return 0;
}
//������� 6.15. ��������� do_while. �
/* do_while.c -- ���� � ������������ */
int do_while(void)
{
	const int secret_code = 13;
	int code_entered;
	printf("\n\033[41;1;4m���������  do_while.c -- ���� � ������������.\033[0m\n");
	do
	{
		printf("����� ����� � ���� ������� ���������������, \n");
		printf("����������, ������� ��������� ���(����������):___\b\b\b");
		scanf_s("%d", &code_entered);
	} while (code_entered != secret_code);
	printf("�����������! ��� ��������!\n");
	return 0;
}
// ������� 6. 16. ��������� entry.�
/* entry.c -- ���� � ������������ */
int entry(void)
{
	const int secret_code = 13;
	int code_entered;
	printf("\n\033[41;1;4m��������� entry.� - ���� � ������������.\033[0m\n");
	printf("����� ����� � ���� ������� ���������������,\n");
	printf("����������, ������� ��������� ���:___\b\b\b");
	while ((scanf_s("%d", &code_entered)==1)&&(code_entered != secret_code))
	{
		printf("����� ����� � ���� ������� ���������������, \n");
		printf("����������, ������� ��������� ���: ");
	}
	printf("�����������! ��� ��������!\n");
	return 0;
}
// ������� 6.17. ��������� rowsl.c
/* rowsl.c -- ���������� ��������� ������ */
#define ROWS 6
#define CHARS 10
int rows1(void)
{
	int row;
	char ch;
	printf("\n\033[41;1;4m��������� rows1.c -- ���������� ��������� ������.\033[0m\n");
	for (row = 0; row < ROWS; row++)
	{
		for (ch = '�'; ch < ('�' + CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}
		return 0;
}
// ������� 6.18. ��������� rows2. �
// rows2.c � ���������� ��������� ��������� ������
int rows2(void)
{
	const int _ROWS = 6;
	const int _CHARS = 6;
	int row;
	char ch;
	printf("\n\033[41;1;4m��������� rows2.c -- ���������� ��������� ������.\033[0m\n");
	for (row = 0; row < _ROWS; row++)
	{
		for (ch = ('�' + row); ch < ('�' + _CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}
// ������� 6.19. ��������� scores_in. �
// scores_in.c � ������������� ������ ��� ��������� ��������
#define SIZE 10
#define PAR 72
int scores_in(void)
{
	int index, score[SIZE];
	int sum = 0;
	float average;
	printf("\n\033[41;1;4m6.19.��������� scores_in.c � ������������� ������ ��� ��������� ��������.\033[0m\n");
	printf("B�e���e %d ����������� ���� � �����:\n", SIZE);
	for (index = 0; index < SIZE; index++)
	{
		printf("%d:_\b",index+1);
		scanf_s("%d", &score[index]);			// ������ 10 ����������� ���� � �����
	}
	printf("������� ��������� ����������:\n");
	for (index = 0; index < SIZE; index++)
		printf("%5d ", score[index]);			// �������� ��������� ����������
	//printf("\n");
	for (index = 0; index < SIZE; index++)
		sum += score[index];					// �������� �����������
	average = (float)sum / SIZE;				// ����������� �������� �����
	printf("\n����� ����������� = %d, ������� �������� = %.2f\n", sum, average);
	printf("���������� �������� ����� %.0f.\n", average - PAR);
	return 0;
}
// ������� 6.20. ��������� power. �
// power.c -- �������� ����� � ����� �������
double power(double n, int �); // �������� ANSI
int powerCall(void)
{
	double �, xpow;
	int ���;
	printf("\n\033[41;1;4m6.20.��������� power.c -- �������� ����� � ����� �������.\033[0m\n");
	printf("������� ����� � ������������� ����� �������,");
	printf(" � �������\n����� ����� ���������. ��� ���������� ���������");
	printf(" ������� q:___ __\b\b\b\b\b\b");
	while (scanf_s("%lf %d", &�, &���) == 2)
	{
		xpow = power(�, ���);		// ����� �������
		printf("%.3g � ������� %d ����� %.5g\n", �, ���, xpow);
		printf("������� ��������� ���� ����� ��� q ��� ����������:___ __\b\b\b\b\b\b");
	}
	printf("��������, ��� �� ������� ��� ���������� -- �� ��������!\n");
	return 0;
}
double power(double n, int �)	// ����������� �������
{
	double pow = 1;
	int i;
	for (i = 1; i <= �; i++)
		pow *= n;
	return pow;					// ���������� �������� pow
}
// ������� ��� ������������
// 8. ��� ������� ����������� ����� ��������� � ������ ����� Go west, young man ! ?
// (� ��������� ASCII ������ !������� �� �������� �������.)
int test8(void)
{
	char ch;
	printf("\n\033[41;1;4m������� ��� ������������. 8 -- ��� ������� ����������� ����� ��������� � ������ ����� Go west, young man!\033[0m\n");
	do {
		scanf_s("%c", &ch);
		printf("%c", ch);
	} while (ch != 'g');
	printf("\n");
	return 0;
}
// 9. ��� ������� ��������� ��������� ?
int test9(void)
{
	int n, m;
	n = 30;
	printf("\n\033[41;1;4m������� ��� ������������. 9 -- ��� ������� ��������� ���������?\033[0m\n");
	while (++n <= 33)
		printf(" %d|", n) ;
			n = 30;
	do
		printf("%d|", n);
	while (++n <= 33);
	printf("\n***\n");
	for (n = 1; n * n < 200; n += 4)
		printf("%d\n", n);
	printf("\n***\n");
	for (n = 2, m = 6; n < m; n *= 2, m += 2)
		printf("%d %d\n", n, m);
	printf("\n***\n");
	for (n = 5; n > 0; n--)
	{
		for (m = 0; m <= n; m++)
			printf("=");
		printf("\n"); 
	}
	return 0;
	}
// 14. ��� ������� ��������� ���������?
#include <stdio.h>
int test14(void)
{
	int k;
	printf("\n\033[41;1;4m������� ��� ������������. 14 -- ��� ������� ��������� ���������?\033[0m\n");
	for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k), k * k < 26; k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
	return 0;
}