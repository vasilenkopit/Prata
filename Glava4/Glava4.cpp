// Glava4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

//#using namespace std;
extern "C" {
    int Exsample1(void);
    int Exsample2(void);
    int Exsample3(void);
    int Exsample4(void);
    int Exsample5(void);
    int Exsample6(void);
    int Exsample7(void);
    int Exsample8(void);
}
int main()
{
    setlocale(LC_ALL,"Russian");
    printf("Упражнения по программированию. Глава 4.\n");
    goto run;
    Exsample1();
    Exsample2();
    Exsample3();
    Exsample4();
    Exsample5();
    Exsample6();
    Exsample7();
run:
    Exsample8();
}