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
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 10. таблица квадратов и кубов с введёнными границами.\033[0m\n");
    do
    {

        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%c",&ch);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            //getchar();          // Пропустить \n от ответа
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}

*/

/*
1. Напишите программу, которая подсчитывает количество символов во входных
данных до достижения конца файла.
*/

int Exsample1(void)
{
    long long int count;
    char ch,fileName[50];
    FILE* fp;
    printf("\n\033[1;4;44mЗадание 1. подсчитывает количество символов в файле до достижения конца файла.\033[0m\n");
    do
    {
        printf("Введите имя файла:"INPUT3);
        scanf_s("%s", fileName, 49);
        count = 0;
        fopen_s(&fp, fileName, "rb");
        if (fp) {
            while (!feof(fp)) {
                getc(fp); 
                count++;
            }
            printf("В файле %s содержится %lld символов.\n",fileName,count);
        }
        else {
            printf("Файл %s .",fileName);
            perror("Ошибка открытия файла: ");
        }
        printf("\nЕщё разок?(y или д):");
        scanf_s("%c",&ch,1);
        ch=getchar();
        getchar();          // Пропустить \n от ответа
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
/*
2. Напишите программу, которая читает ввод как поток символов, пока не встретит
EOF. Программа должна выводить каждый введенный символ и его десятичный код ASCII. 
Следует отметить, что в кодировке ASCII символы, предшествующие
пробелу, являются непечатаемыми. Трактуйте их особым образом. Если
непечатаемым символом является символ новой строки или символ табуляции,
выводите, соответственно, \n или \t. В противном случае воспользуйтесь нотацией
управляющих символов. Например, ASCII-код 1 — это комбинация <Ctrl+A>,
которую можно отобразить как ^А. Обратите внимание, что ASCII-код символа А
представляет собой значение <Ctrl+A> плюс 64. Аналогичная зависимость имеется
и для других непечатаемых символов. Выводите по 10 пар в строке, кроме
случая, когда встречается символ новой строки. 
(На заметку: операционная система может иметь специальные интерпретации для некоторых управляющих
символов и не допускать их попадания в программу.)
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
    scanf_s("%lc", &wch,1);             // Русские буквы не понимает! Почему?
    puts("Enter your first name:");
    scanf_s("%ls", w_arr,19);           // Русские буквы не понимает! Почему?
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
    //SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    //SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 2. читает ввод как поток символов, пока не встретит EOF.\033[0m\n");
    printf("\033[1;4;44m             выводит код символа и символ или его имя, для служебных.\033[0m\n");
    do
    {
        //wider();
        printf("Вводите текст(конец - Ctrl/Z F6):"INPUT3);
         char* specName[]= { "NUL","SCH","STX","ETX","EOT","ENQ","ACK","BEL","BS", "HT", "LF",
                             "VT", "FF", "CR", "SO", "SI", "DLE","DC1","DC2","DC3","DC4","NAK",
                             "SYN","ETB","CAN","BM", "SUB","ESC","FS", "GS", "RS", "US", "SP"};
         char* specSmb[] = { "^@", "^A", "^B", "^C", "^D", "^E", "^F", "^G", "^H", "^I", "^J",
                             "^K", "^L", "^M", "^N", "^O", "^P", "^Q", "^R", "^S", "^T", "^U",
                             "^V", "^W", "^X", "^Y", "^Z", "^[", "^\\","^]", "^^", "^_", " " };
        while ((ch=getchar()) != EOF) {
            if (ch > 0 && ch <= ' ') {          // Специальные символы
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
        printf("\nЕщё разок?(y или д):");
        scanf_s("%c",&ch,1);
        ch=getchar();
        getchar();          // Пропустить \n от ответа
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}

/*
3. Напишите программу, которая читает ввод как поток символов, пока не получит
EOF. Программа должна сообщать количество прописных букв количество строчных
букв и количество остальных символов во входных данных. Може предполагать,
что числовые значения для строчных букв являются последовательными, и то же
самое справедливо для прописных букв. Либо для большей переносимости можете
использовать подходящие классификационные функции из библиотеки ctуре.h.
*/

int Exsample3(void)
{
    int i, iUp=0, iLo = 0,idig=0, ispc=0,ipun=0,inot=0,iall=0;
    wchar_t ch;
    char ch1;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 3. читает ввод как поток символов, пока не получит EOF.\n"
                          "          считает количество прописных, строчных букв и число прочих символов \033[0m\n");
    do
    {
        iUp = 0; iLo = 0; idig = 0; ispc = 0; ipun = 0; inot = 0; iall = 0;
        printf("Вводите текст(конец - Ctrl/Z F6):"INPUT3);

        while ((char)(ch = getchar()) != EOF) {
            if (ch == 0XFF ||ch==26) break;
            if (isalpha(ch)) {          // буквы
                if (islower(ch))    iLo++;
                else                iUp++;
            }
            else if (isspace(ch))   ispc++;
            else if (isdigit(ch))   idig++;
            else if (ispunct(ch))   ipun++;
            else                    inot++;
            iall++;
        }
        printf("Всего:%d \tБольшие:%d \tМалые:%d \tЦифры:%d \tЗнаки:%d \tПрочие:%d\n",iall,iUp,iLo,idig,ipun,inot);
        do {
            printf("\nЕщё разок?(y или д):");
            ch=getchar();
            if (!(ch == L'y' || ch == L'д' || ch == L'n' || ch == L'н')) printf("Ошибка-%c. Нужно y//n или д//н.",ch);
        } while (!(ch == L'y' || ch == L'д' || ch == L'n' || ch == L'н'));
        if ((ch1 = getchar()) != '\n') _ungetch(ch1);
    } while (ch == L'y' || ch == L'д');
    printf("\nКонец программы\n");
    return 0;
}
/*
4. Напишите программу, которая читает ввод как поток символов, пока не встретит EOF. 
Программа должна сообщать среднее количество букв в словах. Не считайте
пробельные символы в словах буквами. На самом деле, также не должны
учитываться и знаки препинания, но в данном упражнении об этом можно не
беспокоиться. 
(Для учета знаков препинания можно воспользоваться функцией ispunct() из семейства ctype.h.)
*/

int Exsample4(void)
{
    int i, nwords, lword,len;
    wchar_t ch;
    char ch1;
    bool word;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 4. читает ввод как поток символов, пока не встретит EOF.\n"
                         "           выволит среднее количество букв в словах\033[0m\n");
    do
    {
        nwords= lword=len=0;
        word = false;
        printf("Вводите строку(F6 или ^Z - конец):");
        while ((ch = getchar()) != EOF) {
            if (ch == 0XFF || ch == 26) break;
            if (isalpha(ch)) {
                if (!word) word = true;;
                lword++;
            }
            else {
                if (word) {
                    if (lword > 3) {    // слова только длиннее 3 букв
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
            printf("Число слов:%d \tСредняя длина слова:%d\n",nwords, len/nwords);
        else
            printf("В введённой строке нет слов(слово д.б. длиннее 3 символов).\n");
        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            //getchar();          // Пропустить \n от ответа
        }
        if ((ch1 = getchar()) != '\n') _ungetch(ch1);
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
/*
5. Модифицируйте программу угадывания чисел из листинга 8.4, чтобы реализовать
более интеллектуальную стратегию угадывания. Например, программа может
изначально предположить число 50 и запросить, больше ли оно задуманного,
меньше его или же это и есть задуманное число. Если, скажем, предположение
меньше задуманного числа, следующая догадка должна находиться посредине
между 50 и 100, т.е. 75. Если данное предположение больше задуманного числа,
то следующая догадка должна располагаться посредине между 75 и 50 и т.д.
Используя такую стратегию двоичного поиска, программа быстро найдет нравильный 
ответ, во всяком случае, если пользователь не будет обманывать.
*/
#define GUESS_MAX 1000000
int Exsample5(void)
{
    int i, beg, end;
    char ch;
    int num;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 5. угадывание чисел.\033[0m\n");
    do
    {
        num = random(0, GUESS_MAX);
        printf("Выберите целое число в интервале от 1 до %d. Я попробую угадать его. \n",num);
        printf("Нажмите клавишу <, =  или >, если если ваше число <, = или > моего.\n");
        printf("Я знал, что у меня получится! Вы загадали %d.\n", guess5(num));
        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            //getchar();          // Пропустить \n от ответа
        }
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
int guess5(int num)
{
    int guess = num/2,guessL=0,guessP= GUESS_MAX;
    char response='\n';
    do{
        printf("Ваше число %d? (< = >):"INPUT1, guess);
        response = getchar();           /* получить ответ */
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
                printf("нажимайте только < = >.\n");
                while (getchar() != '\n'); 					/* пропустить оставшуюся часть входной строки*/
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
6. Модифицируйте функцию get_first () из листинга 8.8 так, чтобы она возвращала
первый встреченный непробельный символ. Протестируйте ее в какой-нибудь
простой программе.
*/
#define MAX_TEXT 200        // максимальная длина строки ввода
int Exsample6(void)
{
    int i, beg, end;
    wchar_t ch, textOut[MAX_TEXT + 1]={0};
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 6. функция get_first () из листинга 8.8 возвращает\n"
                         "           первый встреченный непробельный символ.\n"
                         "           Программа уберёт все пробелы из вводимой строки.\033[0m\n");
    do
    {
        i = 0;
        printf("Вводите строку с пробелами(или без не длиннее %dсимволов):"INPUT3, MAX_TEXT);
        while ((ch = getchar()) != '\n' && i< MAX_TEXT) {
            if (ch == ' ') ch=get_first6();
            if (ch == '\n') break;
            textOut[i++] = ch;
        }
        textOut[i] = 0;
        printf("\nОбработанная строка(без пробелов):\n%ls\n",textOut);
        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%lc",&ch,1);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            //getchar();          // Пропустить \n от ответа
        }
        getchar();
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
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
7. Модифицируйте упражнение по программированию 8 из главы 7 так, чтобы пункты
меню помечались буквами, а не цифрами; для прекращения ввода используйте
букву q вместо цифры 5.
*/
#define FIRST   300.     //
#define SECND   150.     //
#define PFIRST  15.      // Налоговая ставка:    15% с первых $300
#define PSECND  20.      // 20% со следующих $150
#define PREST   25.      // 25% с остатка
#define PRISE   10.      // тарифная ставка заработной платы = $10,00/час
#define EXTRH   40.      // Сверхурочные часы (превышающие 40 часов в неделю)
#define EXTRK   1.5      // Сверхурочные часы коэффициент 1,5
#define PRISE1   8.75      // тарифная ставка заработной платы
#define PRISE2   9.33
#define PRISE3   10.
#define PRISE4   11.2
int Exsample7(void)
{
    int tarife;
    float hours = 0, many = 0, nalog = 0., tarifInput;
    char ch;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 7. Запрашивает тариф, запрашивает количество часов, отработанных за неделю, и\n"
        "           выводит значения общей суммы начислений, налогов и чистой зарплаты.\033[0m\n");
    do
    {
        printf(
            "************************************************************************\n"
            "| Введите число, соответствующее желаемой тарифной ставке или действию:|\n"
            "| a) $8.75/ч          b) $9.33/ч                                       |\n"
            "| c) $10.00/ч         d) $11.20/ч                                      |\n"
            "| q) Выход                                                             |\n"
            "************************************************************************\n"
        );
        printf("Выберите тариф:"INPUT3);
        if (scanf_s("%c", &ch,1) != 1) { printf("Неверное значение тарифа a b c d q!\n"); continue; };
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
        printf("Введите число отработанных часов за неделю:"INPUT3);
        if (scanf_s("%f", &hours) == 1) {
            if (hours > EXTRH)
                hours += (hours - EXTRH) * EXTRK;
            many = hours * tarifInput;
            if (many < FIRST)                                   nalog = (many * PFIRST) / 100.;
            else if ((many > FIRST) && (many < FIRST + SECND))  nalog = (PFIRST * FIRST) / 100. + (many - FIRST) * PSECND / 100.;
            else                                                nalog = (PFIRST * FIRST) / 100. + SECND * PSECND / 100. + (many - FIRST - SECND) * PREST / 100.;
        }
        printf("За неделю заработок составил:\n");
        printf("Общая сумма начислений: %.2f\n", many);
        printf("Налог:                  %.2f\n", nalog);
        printf("На руки:                %.2f\n", many - nalog);
        printf("\nЕщё разок?(y или д):");
        scanf_s("%c", &ch,1);
        ch = getchar();
        getchar();          // Пропустить \n от ответа
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}
/*
8. Напишите программу, которая выводит на экран меню, предлагающее выбрать сложение,
вычитание, умножение или деление.
После выбора программа должна запросить два числа и затем выполнить затребованную операцию. 
Программа должна принимать только варианты, предлагаемые в меню. 
Для чисел должен использоваться тип float и 
программа должна предоставлять пользователю возможность повторно
вводить числа, если он ввел нечисловые данные. 
В случае деления программа должна предложить пользователю ввести другое значение, 
если он ввел для второго операнда значение 0. 
Выполнение такой программы должно иметь примерно такой вид:
Выберите желаемую операцию:
с. сложение в. вычитание
у. умножение д. деление
з. завершение
с
Введите первое число: 22.4
Введите второе число: о^ дин
один не является числом.
Введите число, такое как 2.5, -1.78Е8 или 3: 1
22.4 + 1 = 23.4
п
Выберите желаемую операцию:
с. сложение в. вычитание
у. умножение д. деление
з. завершение
д 
Введите первое число: 18.4
Введите второе число: О
Введите число, отличное от О: 0.2
18.4 / 0.2 = 92
Выберите желаемую операцию:
с. сложение в. вычитание
у. умножение д. деление
з. завершение
з
Программа завершена.
*/

int Exsample8(void)
{
    int i, op1, op2,err,res;
    char ch,op;
    bool zeroDiv = false;
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\n\033[1;4;44mЗадание 8. Калькулятор.\033[0m\n");
    do
    {
            printf("Вводите: Операция( + - * / 0-конец) Операнд1 Операнд2:"INPUT1);
        while ((err=scanf_s("%c %d %d",&op,1,&op1,&op2)) == 3)
        {
            zeroDiv = false;
            //printf("Операция( + - * // 0-конец):"INPUT1);
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
                    printf("Деление на 0!\n");
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
            if(!zeroDiv) printf("Операция: %d %c %d = %d\n", op1,op,op2,res);
            printf("Вводите: Операция( + - * / 0-конец) Операнд1 Операнд2:"INPUT1);
            //if (op == '\n') continue;
            getchar();

        }
        printf("\nЕщё разок?(y/n или д/н):");
        scanf_s("%c",&ch,1);
        while(!(ch == 'y' || ch == 'д' || ch == 'n' || ch == 'н')) {
            ch = getchar();
            //getchar();          // Пропустить \n от ответа
        }
        getchar();
    } while (ch == 'y' || ch == 'д');
    printf("\nКонец программы\n");
    return 0;
}


