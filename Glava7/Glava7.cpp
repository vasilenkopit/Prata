// Glava7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h >

#include <iostream>

//#using namespace std;
extern "C" {
    int colddays(void);
    int cypher1(void);
    int cypher2(void);
    int electric(void);
    int divisors(void);
    int chcount(void);
    int wordcnt(void);
    int paint(void);
    int skippart(void);
    int breakc(void);
    int breakc2(void);
    int animals(void);
    int vowels(void);
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
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m7.\033[0m\n");
    printf("\033[4;30;46mУправляющие операторы С:ветвление и переходы\033[0m\n"); 
    printf("Примеры в тексте главы.\n");
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    goto run;
    colddays();
    cypher1();
    cypher2();
    electric();
    divisors();
    chcount();
    wordcnt();
    paint();
    skippart();
    breakc();
    breakc2();
    animals();
    vowels();
   
    printf("Вопросы для самоконтроля.\n");
    question3();
    question5();
    question6();
    question7();
    question8();
    question9();
    question10();
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
    Exsample8();
    Exsample9();
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