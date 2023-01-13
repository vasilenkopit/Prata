// Glava10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//

#include <Windows.h >

#include <iostream>

//#using namespace std;
extern "C" {
    int day_mon1(void);
    int no_data(void);
    int designate(void);
    int bounds(void);
    int rain(void);
    int pnt_add(void);
    int day_mon3(void);
    int sum_arr1(void);
    int order(void);
    int ptr_ops(void);
    int arf(void);
    int zippo1(void);
    int zippo2(void);
    int array2d(void);
    int flc(void);
    int quest1(void);
    int quest4(void);


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
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m10.\033[0m\n");
    printf("\033[4;30;46mМассивы и указатели\033[0m\n");
    printf("Примеры в тексте главы.\n");
    goto run;
    day_mon1();
    no_data();
    designate();
    bounds();
    rain();
    pnt_add();
    day_mon3();
    sum_arr1();
    order();
    ptr_ops();
    arf();
    zippo1();
    zippo2();
    array2d();
    flc();
    // Примеры использования библиотечных функций из cppreference.com
    printf("Вопросы для самоконтроля.\n");
   quest1();
   quest4();
    //test9();
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
    Exsample9();
    Exsample10();
    Exsample11();
    Exsample12();
 run:
    Exsample13();
    //Exsample14();
    //Exsample15();
    //Exsample16();
    //Exsample17();
    //Exsample18();
}