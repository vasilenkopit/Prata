// Glava13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <Windows.h >
#include <iostream>

//#using namespace std;
extern "C" {
    int count(int argc, char* argv[]);
    int reducto(int argc, char* argv[]);
    int addaword(int argc, char* argv[]);
    int reverse(void);
    int appendmain(void);
    int randbin(void);

    int quest2(int argc, char* argv[]);
    int quest4(int argc, char* argv[]);
    int quest5(int argc, char* argv[]);
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
    int test8(void);

    int Exsample1(int argc, char* argv[]);
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
    int ExsampleSort(void);
}
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
    printf("\033[4;30;46mУпражнения по программированию. Глава \033[24;5;41m13.\033[0m\n");
    printf("\033[4;30;46mФайловый ввод - вывод\033[0m\n");
    printf("Примеры в тексте главы.\n");
    goto run;
    count(argc, argv);
    reducto(argc, argv);
    addaword(argc, argv);
    reverse();
    appendmain();
    randbin();
   printf("Вопросы для самоконтроля.\n");
    quest2( argc,  argv);
    quest4(argc, argv);
    quest5(argc, argv);
    //quest6();
    //quest8();
    //quest9();
    //quest10();
    //quest11();
    //quest12();
    //quest13();
    //test9();
    //test3();
    //test4();

    printf("Задания проверки знаний главы.\n");
  run:
    Exsample1(argc, argv);
    //Exsample2();
    //Exsample3();
    //Exsample4();
    //Exsample5();
    //Exsample6();
    //Exsample7();
    //Exsample8();
    //Exsample9();
    //ExsampleSort();
    //Exsample10();
    //Exsample11();
    //Exsample12();
    //Exsample13(argc, argv);
    //Exsample14(argc, argv);
    //Exsample15();
    //Exsample16();
    //Exsample17();
    //Exsample18();
}