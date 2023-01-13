// Glava8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h >

#include <iostream>

//#using namespace std;
extern "C" {
    int echo(void);
    int echo_eof(void);
    int file_eof(void);
    int cppreference(void);
    int cppreferenceFseek(void);
    int getcExample(void);
    int ungetcCppreference(void);
    int ungetcCall(void);
    int vfscanfCall(void);
    int tmpfileCall(void);

    int guess(void);
    int guess1(void);
    int showchar1(void);
    int showchar2(void);
    int checking(void);
    int menuette(void);


    int question3(void);
    int question5(void);
    int question6(void);
    int question7(void);
    int question8(void);
    int question9(void);
    int question10(void);
    int test8(void);
    int test9(void);
    int test14(void);
    int test14(void);

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
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m8.\033[0m\n");
    printf("\033[4;30;46mСимвольный ввод-вывод и проверка достоверности ввода\033[0m\n");
    printf("Примеры в тексте главы.\n");
    goto run;
    echo();
    echo_eof();
    file_eof();
    // Примеры использования библиотечных функций из cppreference.com
    cppreference();
    cppreferenceFseek();
    getcExample();
    ungetcCppreference();
    ungetcCall();
    vfscanfCall();
    tmpfileCall();
    guess();
    guess1();
    showchar1();
    showchar2();
    checking();
    menuette();
    printf("Вопросы для самоконтроля.\n");
    //test8();
    //test9();
    //test14();

    printf("Задания проверки знаний главы.\n");
    Exsample1();
    Exsample2();
    Exsample3();
    Exsample4();
    Exsample5();
    Exsample6();
    Exsample7();
run:
    Exsample8();
    //Exsample9();
    //Exsample10();
    //Exsample11();
    //Exsample12();
    //Exsample13();
    //Exsample14();
    //Exsample15();
    //Exsample16();
    //Exsample17();
    //Exsample18();
}