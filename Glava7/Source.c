//������� 7.1.��������� colddays.�
// colddays.c -- ��������� ������� �������, ����� ����������� ���������� ���� ����
#include <stdio.h>
int colddays(void)
{
	const int FREEZING = 0;
	float temperature;
	int cold_days = 0;
	int all_days = 0;
	printf("\n\033[1;4;44m������� 7.1.��������� colddays.� \n��������� ������� �������, ����� ����������� ���������� ���� ����\033[0m\n");
	printf("B�e���e ������ ����������� ������� ����������.\n");
	printf("����������� ����� �������; ����� ����� ������, ��� ���������� ������� q:");
	while (scanf_s("%f", &temperature) == 1)
	{
		all_days++;
		if (temperature < FREEZING)
			cold_days++;
	}
	if (all_days != 0)
		printf("%d - ����� ���������� ����: %.1f%% � ������������ ���� ����.\n",
			all_days, 100.0 * (float)cold_days / all_days);
	if (all_days == 0)
		printf("�a���e �� �������!\n");
	return 0;
}
// ������� 7.2. ��������� cypherl .�
// cypherl.c -- ������ ��������� �� ������� ������, �������� �������
#include <stdio.h>
#define SPACE ' '		// �������, ������, �������
int cypher1(void)
{
	char ch;
	printf("\n\033[1;4;44m������� 7.2. ��������� cypher1.� \n����������� ��� �������, �������� �������\033[0m\n");
	printf("B�e���e ������ � ��������� ��� ���:\n");
	ch = getchar();			// ������ ������
	while (ch != '\n')		// ���� �� ���������� ����� ������
	{
		if (ch == SPACE)	// �������� ������ ����������
			putchar(ch);	// ������ �� ��������
		else
			putchar(ch + 1); // �������� ������ �������
		ch = getchar();		 // �������� ��������� ������
	}
	putchar(ch);	// ������� ������ ����� ������
	return 0;
}
// ������� 7.� . ��������� cypher2. �
// cypher2.c -- ������ ������� ������, �������� ����������� �������, ������� �� �������� �������
#include <stdio.h>
#include <ctype.h> // ��� ������� � isalpha ()
int cypher2(void)
{
	char ch;
	printf("\n\033[1;4;44m������� 7.3. ��������� cypher2.� \n������ ������� ������, �������� ����������� ������� �������.\033[0m\n");
	printf("B�e���e ������ � ��������� ��� ���:\n");
	while ((ch = getchar()) != '\n')
	{
		if (isalpha(ch))	// ���� ��� �����,
			putchar(ch + 1);// ���������� ��������� �����
		else// � ��������� ������
			putchar(ch);	// ���������� ������ ��� ����
	}
	putchar(ch);			// ������� ������ ����� ������
	return 0;
}
// ������� 7 .4. ��������� electric. �
// electric.c -- ������������ ����� ��� ����� �� ��������������
#include <stdio.h>
#define RATE1 0.13230	// ����� �� ������ 360 ���/�
#define RATE2 0.15040	// ����� �� ��������� 108 ���/�
#define RATE3 0.30025	// ����� �� ��������� 252 ���/�
#define RATE4 0.34025	// �����, ����� ������ ��������� 720 ���/�
#define BREAK1 360.0	// ������ ����� ������� �������
#define BREAK2 468.0	// ������ ����� ������� �������
#define BREAK3 720.0	// ������ ����� ������� �������
#define BASE1 (RATE1 * BREAK1)
// ��������� 360 ���/�
#define BASE2 (BASE1 + (RATE2 * (BREAK2 - BREAK1)))
// ��������� 468 ���/�
#define BASE3 (BASE1 + BASE2 + (RATE3 *(BREAK3 - BREAK2)))
// ��������� 720 ���/�
int electric(void)
{
	double kwh;		// ��������������� ��������-����
	double bill;	// ����� � ������
	printf("\n\033[1;4;44m������� 7.4. ��������� electric.� -- ������������ ����� ��� ����� �� ��������������.\033[0m\n");
	printf("������� ����� ��������������� �������������� � ���/�:___\b\b\b");
	scanf_s("%lf", &kwh); // %lf ��� ���� double
	if(kwh <= BREAK1)
		bill = RATE1 * kwh;
	else if (kwh <= BREAK2)	// ���������� ���/� � ���������� �� 360 �� 468
		bill = BASE1 + (RATE2 * (kwh - BREAK1));
	else if (kwh <= BREAK3)	// ���������� ���/� � ���������� �� 4 68 �� 720
		bill = BASE2 + (RATE3 * (kwh - BREAK2));
	else                    // ���������� ���/� ��������� 680
		bill = BASE3 + (RATE4 * (kwh - BREAK3));
	printf("����� � ������ �� %.lf ���/� ���������� $%1.2f.\n", kwh, bill);
	return 0;
}
// ������� 7.5. ��������� divisors.�
// divisors.� -- ��������� ��������� if ���������� �������� �����
#include <stdio.h>
#include <stdbool.h>
int divisors(void)
{
	unsigned long num;		// ����������� �����
	unsigned long div;		// ������������� ��������
	bool isPrime;			// ���� �������� �����
	printf("\n\033[1;4;44m������� 7.5. ��������� divisors.� -- ��������� ��������� if ���������� �������� �����\033[0m\n");
	printf("������� ����� ����� ��� �������(q - ����������):__\b\b");
	while (scanf_s("%lu", &num) == 1)
	{
		for (div = 2, isPrime = true; (div * div) <= num; div++)
		{
			if (num % div == 0)
			{
				if ((div * div) != num)
					printf("%lu ������� �� %lu � %lu.\n", num, div, num / div);
				else
					printf("%lu ������� �� %lu.\n",	num, div);
				isPrime = false; // ����� �� �������� ������� 
			}
		}
		if (isPrime)
		printf("%lu �������� ������� ������.\n", num);
		printf("������� ��������� ����� ��� �������; ");
		printf("��� ���������� ������� q.\n"); 
	}
	printf("�� ��������.\n");
	return 0;
}
// ������� 7.6. ��������� chcount.c
// chcount.c -- ������������� ���������� �������� "�"
#include <stdio.h>
#define PERIOD '.'
int chcount(void)
{
	char ch;
	int charcount;
	printf("\n\033[1;4;44m������� 7.6. ��������� chcount.c -- ������������� ���������� �������� ""�""\n\t\t������� ����� �� ������� �� �����.\033[0m\n");
	do {
		charcount = 0;
		printf("������� ������ � ���������(����� - ����� -"".""):_____\b\b\b\b\b");
		while ((ch = getchar()) != PERIOD)
		{
			if (ch != '"' && ch != '\'') charcount++;
		}
		printf("����� ������� %d ��������, �������� �� �������.\n", charcount);
		printf("��������� ������ ����� ������?(y/�):");
	} while (scanf_s(" %c",&ch),ch=='y'||ch=='�');
	return 0;
}
// ������� 7.7. ��������� wordcnt.�
// wordcnt.c -- ���������� ������� ��������, ����, �����
#include <stdio.h>
#include <ctype.h> // ��� isspace()
#include <stdbool.h> // ��� bool, true, false
#define STOP '|'
int wordcnt(void)
{
	char c;				// ����������� ������
	char prev;			// ���������� ����������� ������
	long n_chars = 0L;	// ���������� ��������
	int n_lines = 0;	// ���������� �����
	int n_words = 0;	// ���������� ����
	int p_lines = 0;	// ���������� �������� �����
	bool inword = false;// == true ���� ������ � ��������� ������ �����
	printf("\n\033[1;4;44m������� 7.7. ���������  wordcnt.c -- ���������� ������� ��������, ����, �����.\033[0m\n");
	printf("������� ����� ��� �������(| ��� ����������):\n");
	prev = '\n';		// ������������ ��� ������������� ������ �����
	while ((c = getchar()) != STOP)
	{
		n_chars++;		// ������� �������
		if (c == ' \n')
			n_lines++;	// ������� ������
		if (!isspace(c) && !inword)
		{
			inword = true;	// ������ ������ �����
			n_words++;		// ������� �����
		}
		if (isspace(c) && inword)
			inword = false; // ��������� ����� �����
		prev = c;			// ��������� �������� �������
	}
	if (prev != ' \n')
		p_lines = 1;
	printf("�������� = %ld, ���� = %d, ����� = %d, ", n_chars, n_words, n_lines);
	printf("�������� ����� = %d\n", p_lines);
	return 0;
}
// ������� 7.8. ��������� paint.c
/* paint.c -- ������������� �������� �������� */
#include <stdio.h>
#define COVERAGE 350 // ����� ���������� ����� �� ���� ����� ������
int paint(void)
{
	int sq_feet;
	int cans;
	printf("\n\033[1;4;44m������� 7.8. ��������� paint.c -- ������������� �������� ��������.\033[0m\n");
	printf("������� ���������� ���������� �����, ������� ���������� ���������:___\b\b\b");
	while (scanf_s("%d", &sq_feet) == 1) {
		cans = sq_feet / COVERAGE;
		cans += ((sq_feet % COVERAGE == 0)) ? 0 : 1;
		printf("��� ����� ����������� %d ����%c ������.\n", cans,
			cans == 1 ? '�' : '�');
		printf("������� ��������� �������� (��� q ��� ����������):\n");
	}
	return 0;
}
// ������� 7.9. ��������� skippart.c
/* skippart.c -- ������������� ��������� continue ��� �������� ����� ����� */
#include <stdio.h>
int skippart(void)
{
	const float MIN = 0.0f;
	const float MAX = 100.0f;
	float score;
	float total = 0.0f;
	int n = 0;
	float min = MAX;
	float max = MIN;
	printf("\n\033[1;4;44m������� 7.9. ��������� skippart.c -- ������������� ��������� continue ��� �������� ����� �����.\033[0m\n");
	printf("������� ��������� ������ ����[0,100](��� q ��� ����������):\033[4m   \033[0m\b\b\b");
	while (scanf_s("%f", &score) == 1)
	{
		if (score < MIN || score > MAX)
		{
			printf("%0.1f - ������������ ��������. ��������� �������: ", score);
			continue; // ������� � ������� �������� ����� while
		}
		printf("Accepting %0.1f:", score);
		min = (score < min) ? score : min;
		max = (score > max) ? score : max;
		total += score;
		n++;
		printf("������� ��������� ��������� ����[0,100](��� q ��� ����������):\033[4m   \033[0m\b\b\b");
}
		if (n > 0)
		{
			printf("����������� %d ����. ������� �������� ����� %0.1f.\n" , n, total/n) ;
			printf("����������� = %0.1f, ������������ = %0.1f\n", min, max);
		}
		else
			printf("�� ���� ������� �� ������ ����������� ����������.\n");
		return 0;
	}
// ������� 7.10. ��������� break. �
/* break.c � ������������� ��������� break ��� ������ �� ����� */
#include <stdio.h>
int breakc(void)
{
	float length, width;
	printf("\n\033[1;4;44m������� 7.10. ��������� break.c � ������������� ��������� break ��� ������ �� �����.\033[0m\n");
	printf("������� ����� ��������������:\033[4m   \033[0m\b\b\b");
	while (scanf_s("%f", &length) == 1)
	{
		printf("����a = \t%0.2f:\n", length);
		printf("������� ������ ��������������:\033[4m   \033[0m\b\b\b");
		if (scanf_s("%f", &width) != 1)
			break;
		printf("������ = \t%0.2f:\n", width);
		printf("������� = \t%0.2f:\n", length * width);
		printf("������� ����� ��������������:\033[4m   \033[0m\b\b\b");
	}
		printf("��������� ���������.\n");
		return 0;
	}
//������� 7.10a. ��������� break. �
/* break2.c � ������������� 2-�� ���������� break ��� ������ �� ����������� � �������� ������ */
#include <stdio.h>
int breakc2(void)
{

	int �, q,status;
	printf("\n\033[1;4;44m������� 7.10a. ��������� break2.c � ������������� 2-�� ���������� break ��� ������ �� ����������� � �������� ������.\033[0m\n");
	printf("��������� ��������� p*q(p>0,0<q<100).\n");
	printf("������� p:\033[4m   \033[0m\b\b\b");
	status=scanf_s("%d", &�);
	while (� > 0 && status==1)
	{
		printf("p = \t%d. ������� q:\033[4m   \033[0m\b\b\b", �);
		status = scanf_s("%d", &q);
		while (q > 0 && status == 1)
		{
			printf("p*q = %d*%d = \t%d\n", �,q,� * q);
			if (q > 100)
				break;				// ����� �� ����������� �����
			printf("������� q:\033[4m   \033[0m\b\b\b");
			status = scanf_s("%d", &q);
		}
		if (q > 100)
			break;					// ����� �� �������� �����
		printf("������� p:\033[4m   \033[0m\b\b\b");
		status = scanf_s("%d", &�);
	}
}
// ������� 7.11.��������� animals.�
/* animals.c -- ������������� ��������� switch */
#include <stdio.h>
#include <ctype.h>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
int animals(void)
{
	char ch;
	printf("\n\033[1;4;44m������� 7.11. ���������  animals.c -- ������������� ��������� switch.\033[0m\n");
	printf("����� ��� ����� ��������, � � ����� ��� ");
	printf("�������� ���������, ������������ � ���� �����. \n");
	printf("������� ����� ��� # ��� ����������:"INPUT1);
	while ((ch = getchar()) != '#')
	{
	if (' \n' == ch) continue;
	if (1/*_islower_l(ch, 1)*/) /* ������ �������� ����� */
		switch (ch)
		{
		case '�':
		case '�':
			printf("apxap, ����� ������ ��������� �����\n");
			break;
		case '�':
			printf("���������, ����� ��������� ������\n");
			break;
		case '�':
			printf("�����, ������ ������������\n");
			break;
		case '�':
			printf("��������, ������������� ��������\n");
			break;
		case '�':
			printf("������, ���������� ^��������\n");
			break;
		case '�':
			printf("�������, ������-���������� ������ \n");
			break;
		default:
			printf("Bo�poc ��������!\n");
		} /* ����� ��������� ������ */
	else
		printf("������������ ������ �������� �����.\n");
	while (getchar() != '\n')
		continue;  /* ���������� ���������� ����� ������� ������ */
	printf("������� ��������� ����� ��� # ��� ����������:"INPUT1);
		} /* ����� ����� while */
	printf("�� ��������.\n") ;
		return 0;
}
// ������� 7.12. ��������� vowels.�
// vowels.c -- ������������� ��������� �����
#include <stdio.h>
int vowels(void)
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;
	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("\n\033[1;4;44m������� 7.12. ���������  vowels.c -- ������������� ��������� ����� switch.\033[0m\n");
	printf("������� ����� ��� # ��� ���������� ���������:"INPUT3);
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case 'a':
		case 'A': a_ct++;
			break;
		case 'e':
		case 'E': e_ct++;
			break;
		case 'i':
		case 'I': i_ct++;
			break;
		case 'o':
		case 'O': o_ct++;
			break;
		case 'u':
		case 'U': u_ct++;
			break;
		default: break;
		} // ����� ��������� switch
	} // ����� ����� while
	printf("���������� �������: \tA \tE \tI \tO \tU\n");
	printf(" \t\t\t%d \t%d \t%d \t%d \t%d\n", a_ct, e_ct, i_ct, o_ct, u_ct);
	return 0;
}
// ������� ��� ������������
/* 3. � ����������� ���� ��������� ������������ ������� ������� ���������
���������, � ����� ����������� ������.��������� ��������� � ��������� ������. 
*/
#include <stdio.h>																					
int question3(void)										/* 1 */
{														/* 2 */								
	int weight, height;		/* ��� � ������, ���� � ������ */
	printf("\n\033[1;4;44m������ 3. ���������  question3.c -- ��������� ��������� � ��������� ������.\033[0m\n");
	printf("������� ��� � ���� ����� ������:(���>100, ����)"INPUT3" \b"INPUT3);
	scanf_s("%d %d" , &weight, &height);				/* 5 */
	if (weight < 100 && height > 64)					/* 6 */
		if (height >= 72)								/* 7 */
			printf("��� ��� ������� ��� ��� ������ �����.\n");
		else if (height < 72 && weight > 64)			/* 9 */
			printf("��� ��� ��� ��� ������ �����.\n");	/* 10 */
		else if (weight > 300 && !(weight <= 300)		/* 11 */
			&& height < 48)								/* 12 */
			if (!(height >= 48))						/* 13 */
				printf("��� ���� ��� ��� ������ ����\n");
			else                                        /* 15 */
				printf("� ��� ��������� ���.\n");		/* 16 */
	return 0;											/* 17 */
}
// 5. ��� ������� ��������� ���������?
#include <stdio.h>
int question5(void)
{
	int num;
	printf("\n\033[1;4;44m������ 5. ���������  question5.c --  ��� ������� ��������� ���������?\033[0m\n");
	for (num = 1; num <= 11; num++)
	{
		if (num % 3 == 0)
			putchar('$');
		else
			putchar('*');
			putchar('#');
		putchar('%');
	}
	putchar('\n');
	return 0;
}
// 6. ��� ������� ��������� ��������� ?
#include <stdio.h>
int question6(void)
{
	int i = 0;
	printf("\n\033[1;4;44m������ 6. ���������  question6.c --  ��� ������� ��������� ���������?\033[0m\n");
	while (i < 3) {
		switch (i ++) {
		case 0:	printf("fat ");
		case 1: printf("hat ");
		case 2: printf("cat ");
		default: printf("Oh no!");
		}
		putchar('\n');
	}
	return 0;
}
// 7. ��� ����������� � ��������� ���������?
#include <stdio.h>
int question7(void)
{
	char ch;
	int lc = 0; /* ������� �������� �������� */
	int uc = 0; /* ������� ��������� �������� */
	int oc = 0; /* ������� ������ �������� */
	printf("\n\033[1;4;44m������ 7. ���������  question7.c --  ��� ����������� � ��������� ���������?\033[0m\n");
	printf("������� ������(��������� - #):"INPUT3);
	while ((ch = getchar()) != '#')
	{
		if (('a' <= ch) && (ch <= 'z'))
			lc++;
		else if ((ch >= 'A') && (ch <= 'Z'))
			uc++;
		else
			oc++;
	} printf(" %d ��������, %d ���������, %d ������\n", lc, uc, oc);
	return 0;
}
// 8. ��� ������� ��������� ���������?
/* retire.c */
#include <stdio.h>
int question8(void)
{
	int age = 20;
	printf("\n\033[1;4;44m������ 8. ���������  question8.c --  ��� ������� ��������� ���������?\033[0m\n");
	while (age++ <= 65)
	{
		if ((age % 20) == 0) /* ������� �� ������� �� 20? */
			printf("BaM %d. ��� �������� � ���������.\n", age);
		if (age == 65)
			printf("BaM %d. �������� ���� ������� ����.\n", age);
	}
	return 0;
}
/* 9. ��� ������� ��������� ��������� ��� ��������� �����?
q
c
h
b
*/
#include <stdio.h>
int question9(void)
{
	char ch;
	printf("\n\033[1;4;44m������ 9. ���������  question9.c --  ��� ������� ��������� ��������� ��� ��������� �����?\033[0m\n");
	printf("q\nc\nh\nb\n#\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf("��� 1\n");
		if(ch == 'c')
			continue;
		else if (ch == 'b')
			break;
		else if (ch == 'h')
			goto laststep;
		printf("��� 2\n");
		laststep: printf("��� 3\n");
	}
	printf("������\n");
	return 0;
}
/* 10. ���������� ��������� �� ������� 9 ���, ����� ��� ��������� ���� ���������,
�� � ��� �� �������������� ��������� continue � goto. */
#include <stdio.h>
int question10(void)
{
	char ch;
	printf("\n\033[1;4;44m������ 10. ���������  question10.c --  ��� ������� ��������� ��������� ��� ��������� �����?\033[0m\n");
	printf("q\nc\nh\nb\n#\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case '\n':
			break;
		case 'b':
			printf("��� 1\n");
			break;
		case 'h':
			printf("��� 1\n");
			printf("��� 3\n");
			break;
		case 'c':
			printf("��� 1\n");
			break;
		case 'q':
			printf("��� 1\n");
			printf("��� 2\n");
			printf("��� 3\n");
		default:
			break;
		}
		if (ch == 'b') break;
	}
	printf("������\n");
	return 0;
}