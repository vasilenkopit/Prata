// Glava5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//#using namespace std;
extern "C" {
    int shoes1(void);
    int shoes2(void);
    int wheat(void);
    int divide(void);
    int rules(void);
    int psizeof(void);
    int min_sec(void);
    int post_pre(void);
    int incProblem(void);
    int addemup(void);
    int convert(void);
    int call_pound(void);
    int running(void);
    int Exsample1(void);
    int Exsample2(void);
    int Exsample3(void);
    int Exsample4(void);
    int Exsample5(void);
    int Exsample6(void);
    int Exsample7(void);
    int Exsample8(void);
    int Exsample9(void);
}
int main()
{
    setlocale(LC_ALL, "Russian");
    printf("Упражнения по программированию. Глава 5.\n");
    goto run;
    printf("Примеры в тексте главы.\n");
    shoes1();
    shoes2();
    wheat();
    divide();
    rules();
    psizeof();
    min_sec();
    post_pre();
    incProblem();
    addemup();
    convert();
    call_pound();
    running();
    printf("Задания проверки знаний главы.\n");
    Exsample1();
    Exsample2();
    Exsample3();
    Exsample4();
    Exsample5();
    Exsample6();
    Exsample7();
    Exsample8();
   run:
   Exsample9();
}