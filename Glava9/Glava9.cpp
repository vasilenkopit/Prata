// Glava9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//

#include <Windows.h >

#include <iostream>

//#using namespace std;
extern "C" {
    int lethead1(void);
    int lethead2(void);
    int lesser(void);
    int misuse(void);
    int proto(void);
    int recur(void);
    int factor(void);
    int binary(void);
    int usehotel(void);
    int loccheck(void);
    int swap3(void);

    int test4(void);
    int test5(void);
    int test6(void);
    int test7(void);
    int test9(void);

    int Exsample1(void);
    int Exsample2(void);
    int Exsample3(void);
    int Exsample4(void);
    int Exsample5(void);
    int Exsample6(void);
    int Exsample7(void);
    int Exsample8(void);
    int Exsample9(void);
    int Exsample10(void);
    int Exsample11(void);
    int Exsample12(void);
    int Exsample13(void);
    int Exsample14(void);
    int Exsample15(void);
    int Exsample16(void);
    int Exsample17(void);
    int Exsample18(void);
    int Exsample19(void);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m9.\033[0m\n");
    printf("\033[4;30;46mФункции\033[0m\n");
    printf("Примеры в тексте главы.\n");
    goto run;
    lethead1();
    lethead2();
    lesser();
    misuse();
    proto();
    recur();
    factor();
    binary();
    usehotel();
    loccheck();
    swap3();
    // Примеры использования библиотечных функций из cppreference.com
    printf("Вопросы для самоконтроля.\n");
    test4();
    test9();
    //test3();
    //test4();

    printf("Задания проверки знаний главы.\n");
    Exsample1();
    Exsample2();
    Exsample3();
    Exsample4();
    Exsample5();
    Exsample6();
    Exsample7();
    Exsample8();
    //Exsample9();
    Exsample10();
run:
    Exsample11();
    //Exsample12();
    //Exsample13();
    //Exsample14();
    //Exsample15();
    //Exsample16();
    //Exsample17();
    //Exsample18();
}