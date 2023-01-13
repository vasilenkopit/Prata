// Glava11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//

#include <Windows.h >

#include <iostream>

//#using namespace std;
extern "C" {
    int strings1(void);
    int quotes(void);
    int addresses(void);
    int arrchar(void);
    int p_and_s(void);
    int getsputs(void);
    int fgets1(void);
    int fgets2(void);
    int fgets3(void);
    int scan_str(void);
    int put_out(void);
    int nono(void);
    int put_put(void);
    int test_fit(void);
    int str_cat(void);
    int join_chk(void);
    int nogo(void);
    int compare(void);
    int compback(void);
    int quit_chk(void);
    int quit_chkNull(void);
    int starsrch(void);
    int copy1(void);
    int copy2(void);
    int copyЗ(void);
    int format(void);
    int strFunctions(void);
    int sort_str(void);
    int mod_str(void);
    int repeat(int argc, char* argv[]);
    int hello(int argc, char* argv[]);
    int strcnvt(void);

    int quest1_4(void);
    int quest5(void);
    int quest6(void);
    int quest8(void);
    int quest9(void);
    int quest10(void);
    int quest11(void);
    int quest12(void);
    int quest13(void);

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
    int Exsample13(int argc, char* argv[]);
    int Exsample14(int argc, char* argv[]);
    int Exsample15(void);
    int Exsample16(void);
    int Exsample17(void);
    int Exsample18(void);
    int Exsample19(void);
}
int main(int argc, char* argv[])
{
    repeat(argc, argv);
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m11.\033[0m\n");
    printf("\033[4;30;46mСимвольные строки и строковые функции\033[0m\n");
    printf("Примеры в тексте главы.\n");
    goto run;
    // Примеры использования библиотечных функций из cppreference.com
    strings1();
    quotes();
    addresses();
    arrchar();
    p_and_s();
    getsputs();
    fgets1();
    fgets2();
    fgets3();
    scan_str();
    put_out();
    nono();
    put_put();
    test_fit();
    str_cat();
    join_chk();
    nogo();
    compare();
    compback();
    quit_chk();
    quit_chkNull();
    starsrch();
    copy1();
    copy2();
    copyЗ();
    format();
    strFunctions();
    sort_str();
    mod_str();
    repeat(argc, argv);
    hello(argc, argv);
    strcnvt();
    printf("Вопросы для самоконтроля.\n");
    quest1_4();
    quest5();
    quest6();
    quest8();
    quest9();
    quest10();
    quest11();
    quest12();
    quest13();
    //test9();
    //test3();
    //test4();

    //printf("Задания проверки знаний главы.\n");
    Exsample1();
    Exsample2();
    Exsample3();
    //Exsample4();
    Exsample5();
    Exsample6();
    Exsample7();
    Exsample8();
    Exsample9();
    Exsample10();
    Exsample11();
    Exsample12();
    Exsample13( argc,  argv);
    Exsample14(argc, argv);
    Exsample15();
run:
    Exsample16();
    //Exsample17();
    //Exsample18();
}