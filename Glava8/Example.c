#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
//#include "clocale.h"
//#include <iostream>
#include "string.h"
//#include <consoleapi2.h>
//#include <conio.h >
#include <Windows.h >
//#include <string>
#define INPUT3 "\033[4m___\033[0m\b\b\b"
#define INPUT2 "\033[4m__\033[0m\b\b"
#define INPUT1 "\033[4m_\033[0m\b"
/*

* /

int Exsample10(void)
{
    int i, beg, end;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 10. ������� ��������� � ����� � ��������� ���������.\033[0m\n");
    do
    {

        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%c",&ch);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            //getchar();          // ���������� \n �� ������
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}

*/

/*
1. �������� ���������, ������� ������������ ���������� �������� �� �������
������ �� ���������� ����� �����.
*/

int Exsample1(void)
{
    long long int count;
    char ch,fileName[50];
    FILE* fp;
    printf("\n\033[1;4;44m������� 1. ������������ ���������� �������� � ����� �� ���������� ����� �����.\033[0m\n");
    do
    {
        printf("������� ��� �����:"INPUT3);
        scanf_s("%s", fileName, 49);
        count = 0;
        fopen_s(&fp, fileName, "rb");
        if (fp) {
            while (!feof(fp)) {
                getc(fp); 
                count++;
            }
            printf("� ����� %s ���������� %lld ��������.\n",fileName,count);
        }
        else {
            printf("���� %s .",fileName);
            perror("������ �������� �����: ");
        }
        printf("\n��� �����?(y ��� �):");
        scanf_s("%c",&ch,1);
        ch=getchar();
        getchar();          // ���������� \n �� ������
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
/*
2. �������� ���������, ������� ������ ���� ��� ����� ��������, ���� �� ��������
EOF. ��������� ������ �������� ������ ��������� ������ � ��� ���������� ��� ASCII. 
������� ��������, ��� � ��������� ASCII �������, ��������������
�������, �������� �������������. ��������� �� ������ �������. ����
������������ �������� �������� ������ ����� ������ ��� ������ ���������,
��������, ��������������, \n ��� \t. � ��������� ������ �������������� ��������
����������� ��������. ��������, ASCII-��� 1 � ��� ���������� <Ctrl+A>,
������� ����� ���������� ��� ^�. �������� ��������, ��� ASCII-��� ������� �
������������ ����� �������� <Ctrl+A> ���� 64. ����������� ����������� �������
� ��� ������ ������������ ��������. �������� �� 10 ��� � ������, �����
������, ����� ����������� ������ ����� ������. 
(�� �������: ������������ ������� ����� ����� ����������� ������������� ��� ��������� �����������
�������� � �� ��������� �� ��������� � ���������.)
*/

//
//  wider.c
#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
//#include <string>
//using namespace std;
int wider(void)
{
    wchar_t value = L'\u00f6';
    wchar_t wch = L'I';
    wchar_t w_arr[20] = L"am wide!";
    printf("%lc %ls  %lc\n", wch, w_arr, value);
    puts("Enter your grade:");
    scanf_s("%lc", &wch,1);             // ������� ����� �� ��������! ������?
    puts("Enter your first name:");
    scanf_s("%ls", w_arr,19);           // ������� ����� �� ��������! ������?
    printf("%lc %ls\n", wch, w_arr);
    wchar_t* pw = L"Points to a wide-character string";
    int dozen = 12;
    wprintf(L"Item %d: %ls\n", dozen, pw);
    return 0;
}


int Exsample2(void)
{
    int i = 0;
    unsigned int ich;
    char ch;
    //SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    //SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 2. ������ ���� ��� ����� ��������, ���� �� �������� EOF.\033[0m\n");
    printf("\033[1;4;44m             ������� ��� ������� � ������ ��� ��� ���, ��� ���������.\033[0m\n");
    do
    {
        //wider();
        printf("������� �����(����� - Ctrl/Z F6):"INPUT3);
         char* specName[]= { "NUL","SCH","STX","ETX","EOT","ENQ","ACK","BEL","BS", "HT", "LF",
                             "VT", "FF", "CR", "SO", "SI", "DLE","DC1","DC2","DC3","DC4","NAK",
                             "SYN","ETB","CAN","BM", "SUB","ESC","FS", "GS", "RS", "US", "SP"};
         char* specSmb[] = { "^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H", "^I", "^J",
                             "^K", "^L", "^M", "^N", "^O", "^P", "^Q", "^R", "^S", "^T", "^U",
                             "^V", "^W", "^X", "^Y", "^Z", "^[", "^\\","^]", "^^", "^_", " " };
        while ((ch=getchar()) != EOF) {
            if (ch > 0 && ch <= ' ') {          // ����������� �������
                printf("%#x(%d) %s %s \t", ch, ch,specName[ch],specSmb[ch]);
            }
            else if(ch>0){
                printf("%#x(%d) %c %c \t", ch, ch, ch, ch);
            }
            else {
                ich = (unsigned)ch;
                ich &= 0xFF;
                printf("%#x(%d) %c %c \t", ich, ich, ich, ich);
            }
            i++;
            if (i % 8 == 0) printf("\n");
        }
        printf("\n��� �����?(y ��� �):");
        scanf_s("%c",&ch,1);
        ch=getchar();
        getchar();          // ���������� \n �� ������
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}

/*
3. �������� ���������, ������� ������ ���� ��� ����� ��������, ���� �� �������
EOF. ��������� ������ �������� ���������� ��������� ���� ���������� ��������
���� � ���������� ��������� �������� �� ������� ������. ���� ������������,
��� �������� �������� ��� �������� ���� �������� �����������������, � �� ��
����� ����������� ��� ��������� ����. ���� ��� ������� ������������� ������
������������ ���������� ����������������� ������� �� ���������� ct���.h.
*/

int Exsample3(void)
{
    int i, iUp=0, iLo = 0,idig=0, ispc=0,ipun=0,inot=0,iall=0;
    wchar_t ch;
    char ch1;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 3. ������ ���� ��� ����� ��������, ���� �� ������� EOF.\n"
                          "          ������� ���������� ���������, �������� ���� � ����� ������ �������� \033[0m\n");
    do
    {
        iUp = 0; iLo = 0; idig = 0; ispc = 0; ipun = 0; inot = 0; iall = 0;
        printf("������� �����(����� - Ctrl/Z F6):"INPUT3);

        while ((char)(ch = getchar()) != EOF) {
            if (ch == 0XFF ||ch==26) break;
            if (isalpha(ch)) {          // �����
                if (islower(ch))    iLo++;
                else                iUp++;
            }
            else if (isspace(ch))   ispc++;
            else if (isdigit(ch))   idig++;
            else if (ispunct(ch))   ipun++;
            else                    inot++;
            iall++;
        }
        printf("�����:%d \t�������:%d \t�����:%d \t�����:%d \t�����:%d \t������:%d\n",iall,iUp,iLo,idig,ipun,inot);
        do {
            printf("\n��� �����?(y ��� �):");
            ch=getchar();
            if (!(ch == L'y' || ch == L'�' || ch == L'n' || ch == L'�')) printf("������-%c. ����� y//n ��� �//�.",ch);
        } while (!(ch == L'y' || ch == L'�' || ch == L'n' || ch == L'�'));
        if ((ch1 = getchar()) != '\n') _ungetch(ch1);
    } while (ch == L'y' || ch == L'�');
    printf("\n����� ���������\n");
    return 0;
}
/*
4. �������� ���������, ������� ������ ���� ��� ����� ��������, ���� �� �������� EOF. 
��������� ������ �������� ������� ���������� ���� � ������. �� ��������
���������� ������� � ������ �������. �� ����� ����, ����� �� ������
����������� � ����� ����������, �� � ������ ���������� �� ���� ����� ��
������������. 
(��� ����� ������ ���������� ����� ��������������� �������� ispunct() �� ��������� ctype.h.)
*/

int Exsample4(void)
{
    int i, nwords, lword,len;
    wchar_t ch;
    char ch1;
    bool word;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 4. ������ ���� ��� ����� ��������, ���� �� �������� EOF.\n"
                         "           ������� ������� ���������� ���� � ������\033[0m\n");
    do
    {
        nwords= lword=len=0;
        word = false;
        printf("������� ������(F6 ��� ^Z - �����):");
        while ((ch = getchar()) != EOF) {
            if (ch == 0XFF || ch == 26) break;
            if (isalpha(ch)) {
                if (!word) word = true;;
                lword++;
            }
            else {
                if (word) {
                    if (lword > 3) {    // ����� ������ ������� 3 ����
                        len += lword;
                        nwords++;
                    }
                    lword = 0;
                    word = false;
                }
            }
        }
        if(word&&lword>3){ len += lword; nwords++; }
        if(nwords>0)
            printf("����� ����:%d \t������� ����� �����:%d\n",nwords, len/nwords);
        else
            printf("� �������� ������ ��� ����(����� �.�. ������� 3 ��������).\n");
        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            //getchar();          // ���������� \n �� ������
        }
        if ((ch1 = getchar()) != '\n') _ungetch(ch1);
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
/*
5. ������������� ��������� ���������� ����� �� �������� 8.4, ����� �����������
����� ���������������� ��������� ����������. ��������, ��������� �����
���������� ������������ ����� 50 � ���������, ������ �� ��� �����������,
������ ��� ��� �� ��� � ���� ���������� �����. ����, ������, �������������
������ ����������� �����, ��������� ������� ������ ���������� ���������
����� 50 � 100, �.�. 75. ���� ������ ������������� ������ ����������� �����,
�� ��������� ������� ������ ������������� ��������� ����� 75 � 50 � �.�.
��������� ����� ��������� ��������� ������, ��������� ������ ������ ���������� 
�����, �� ������ ������, ���� ������������ �� ����� ����������.
*/
#define GUESS_MAX 1000000
int Exsample5(void)
{
    int i, beg, end;
    char ch;
    int num;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 5. ���������� �����.\033[0m\n");
    do
    {
        num = random(0, GUESS_MAX);
        printf("�������� ����� ����� � ��������� �� 1 �� %d. � �������� ������� ���. \n",num);
        printf("������� ������� <, =  ��� >, ���� ���� ���� ����� <, = ��� > �����.\n");
        printf("� ����, ��� � ���� ���������! �� �������� %d.\n", guess5(num));
        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            //getchar();          // ���������� \n �� ������
        }
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
int guess5(int num)
{
    int guess = num/2,guessL=0,guessP= GUESS_MAX;
    char response='\n';
    do{
        printf("���� ����� %d? (< = >):"INPUT1, guess);
        response = getchar();           /* �������� ����� */
        if(response =='\n') response = getchar();
        switch (response)
        {
            case '<':
                guessP = guess-1;
                guess = random(guessL, guessP);
                break;
            case '>':
                guessL = guess + 1;
                guess = random(guessL, guessP);
                break;
            case '=':
                break;
            default:
                printf("��������� ������ < = >.\n");
                while (getchar() != '\n'); 					/* ���������� ���������� ����� ������� ������*/
                break;
        }
    } while (response != '=');
    return guess;
}
#include <time.h>
int random(int min, int max) {
    srand(time(NULL));
    return min + rand() % (max - min + 1);
}
/*
6. ������������� ������� get_first () �� �������� 8.8 ���, ����� ��� ����������
������ ����������� ������������ ������. ������������� �� � �����-������
������� ���������.
*/
#define MAX_TEXT 200        // ������������ ����� ������ �����
int Exsample6(void)
{
    int i, beg, end;
    wchar_t ch, textOut[MAX_TEXT + 1]={0};
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 6. ������� get_first () �� �������� 8.8 ����������\n"
                         "           ������ ����������� ������������ ������.\n"
                         "           ��������� ����� ��� ������� �� �������� ������.\033[0m\n");
    do
    {
        i = 0;
        printf("������� ������ � ���������(��� ��� �� ������� %d��������):"INPUT3, MAX_TEXT);
        while ((ch = getchar()) != '\n' && i< MAX_TEXT) {
            if (ch == ' ') ch=get_first6();
            if (ch == '\n') break;
            textOut[i++] = ch;
        }
        textOut[i] = 0;
        printf("\n������������ ������(��� ��������):\n%ls\n",textOut);
        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%lc",&ch,1);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            //getchar();          // ���������� \n �� ������
        }
        getchar();
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
int get_first6(void)
{
    char ch;
    while (isblank((ch = getchar())))
        continue;
    return ch;
}
/*
7. ������������� ���������� �� ���������������� 8 �� ����� 7 ���, ����� ������
���� ���������� �������, � �� �������; ��� ����������� ����� �����������
����� q ������ ����� 5.
*/
#define FIRST   300.     //
#define SECND   150.     //
#define PFIRST  15.      // ��������� ������:    15% � ������ $300
#define PSECND  20.      // 20% �� ��������� $150
#define PREST   25.      // 25% � �������
#define PRISE   10.      // �������� ������ ���������� ����� = $10,00/���
#define EXTRH   40.      // ������������ ���� (����������� 40 ����� � ������)
#define EXTRK   1.5      // ������������ ���� ����������� 1,5
#define PRISE1   8.75      // �������� ������ ���������� �����
#define PRISE2   9.33
#define PRISE3   10.
#define PRISE4   11.2
int Exsample7(void)
{
    int tarife;
    float hours = 0, many = 0, nalog = 0., tarifInput;
    char ch;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 7. ����������� �����, ����������� ���������� �����, ������������ �� ������, �\n"
        "           ������� �������� ����� ����� ����������, ������� � ������ ��������.\033[0m\n");
    do
    {
        printf(
            "************************************************************************\n"
            "| ������� �����, ��������������� �������� �������� ������ ��� ��������:|\n"
            "| a) $8.75/�          b) $9.33/�                                       |\n"
            "| c) $10.00/�         d) $11.20/�                                      |\n"
            "| q) �����                                                             |\n"
            "************************************************************************\n"
        );
        printf("�������� �����:"INPUT3);
        if (scanf_s("%c", &ch,1) != 1) { printf("�������� �������� ������ a b c d q!\n"); continue; };
        switch (ch)
        {
        case 'a':
            tarifInput = PRISE1;
            break;
        case 'b':
            tarifInput = PRISE2;
            break;
        case 'c':
            tarifInput = PRISE3;
            break;
        case 'd':
            tarifInput = PRISE4;
            break;
        default:
            break;
        }
        if (ch == 'q')  break;
        printf("������� ����� ������������ ����� �� ������:"INPUT3);
        if (scanf_s("%f", &hours) == 1) {
            if (hours > EXTRH)
                hours += (hours - EXTRH) * EXTRK;
            many = hours * tarifInput;
            if (many < FIRST)                                   nalog = (many * PFIRST) / 100.;
            else if ((many > FIRST) && (many < FIRST + SECND))  nalog = (PFIRST * FIRST) / 100. + (many - FIRST) * PSECND / 100.;
            else                                                nalog = (PFIRST * FIRST) / 100. + SECND * PSECND / 100. + (many - FIRST - SECND) * PREST / 100.;
        }
        printf("�� ������ ��������� ��������:\n");
        printf("����� ����� ����������: %.2f\n", many);
        printf("�����:                  %.2f\n", nalog);
        printf("�� ����:                %.2f\n", many - nalog);
        printf("\n��� �����?(y ��� �):");
        scanf_s("%c", &ch,1);
        ch = getchar();
        getchar();          // ���������� \n �� ������
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}
/*
8. �������� ���������, ������� ������� �� ����� ����, ������������ ������� ��������,
���������, ��������� ��� �������.
����� ������ ��������� ������ ��������� ��� ����� � ����� ��������� ������������� ��������. 
��������� ������ ��������� ������ ��������, ������������ � ����. 
��� ����� ������ �������������� ��� float � 
��������� ������ ������������� ������������ ����������� ��������
������� �����, ���� �� ���� ���������� ������. 
� ������ ������� ��������� ������ ���������� ������������ ������ ������ ��������, 
���� �� ���� ��� ������� �������� �������� 0. 
���������� ����� ��������� ������ ����� �������� ����� ���:
�������� �������� ��������:
�. �������� �. ���������
�. ��������� �. �������
�. ����������
�
������� ������ �����: 22.4
������� ������ �����: �^ ���
���� �� �������� ������.
������� �����, ����� ��� 2.5, -1.78�8 ��� 3: 1
22.4 + 1 = 23.4
�
�������� �������� ��������:
�. �������� �. ���������
�. ��������� �. �������
�. ����������
� 
������� ������ �����: 18.4
������� ������ �����: �
������� �����, �������� �� �: 0.2
18.4 / 0.2 = 92
�������� �������� ��������:
�. �������� �. ���������
�. ��������� �. �������
�. ����������
�
��������� ���������.
*/

int Exsample8(void)
{
    int i, op1, op2,err,res;
    char ch,op;
    bool zeroDiv = false;
    SetConsoleCP(1251);			//��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251);	//��������� ������� �������� win-cp 1251 � ����� ������
    printf("\n\033[1;4;44m������� 8. �����������.\033[0m\n");
    do
    {
            printf("�������: ��������( + - * / 0-�����) �������1 �������2:"INPUT1);
        while ((err=scanf_s("%c %d %d",&op,1,&op1,&op2)) == 3)
        {
            zeroDiv = false;
            //printf("��������( + - * // 0-�����):"INPUT1);
            switch (op)
            {
            case '+':
                res = op1 + op2;
                break;
            case '-':
                res = op1 - op2;
                break;
            case '*':
                res = op1 * op2;
                break;
            case '/':
                if (op2 > 0) res = op1 / op2;
                else {
                    printf("������� �� 0!\n");
                    res = 0;
                    zeroDiv = true;
                }
                break;
            case '0':
                break;
            default:
                break;
            }
            if (op == '0') break;
            if(!zeroDiv) printf("��������: %d %c %d = %d\n", op1,op,op2,res);
            printf("�������: ��������( + - * / 0-�����) �������1 �������2:"INPUT1);
            //if (op == '\n') continue;
            getchar();

        }
        printf("\n��� �����?(y/n ��� �/�):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == '�' || ch == 'n' || ch == '�')) {
            ch = getchar();
            //getchar();          // ���������� \n �� ������
        }
        getchar();
    } while (ch == 'y' || ch == '�');
    printf("\n����� ���������\n");
    return 0;
}


