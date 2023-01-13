﻿#include "stdio.h"
#include <stdlib.h>
#include "../printfColor.h"
//#include "clocale.h"
//#include <iostream>
#include "string.h"


int Exsample0(void)
{
    /*
Цвет              Текст Фон
черный            30    40
красный           31    41
зеленый           32    42
желтый            33    43
синий             34    44
пурпурный         35    45
зеленовато-голубой  36  46
белый             37    47*/

    SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода


// ASCII smiling face
    const char* s1 = ":-)";
    // UTF-16 (on Windows) encoded WINKING FACE (U+1F609)
    const wchar_t* s2 = L"😉 = \U0001F609 is ;-)";
    // UTF-8  encoded SMILING FACE WITH HALO (U+1F607)
    const char* s3a = u8"😇 = \U0001F607 is O:-)"; // Before C++20
    //const char8_t* s3b = u8"😇 = \U0001F607 is O:-)"; // C++20
    // UTF-16 encoded SMILING FACE WITH OPEN MOUTH (U+1F603)
    //const char16_t* s4 = u"😃 = \U0001F603 is :-D";
    // UTF-32 encoded SMILING FACE WITH SUNGLASSES (U+1F60E)
    //const char32_t* s5 = U"😎 = \U0001F60E is B-)";
    printf("%Ls", s2);

    printf("\033[37;41mTEST\n\033[37;40m");
    printf("\033[37;40m");      // восстановить стандартные цвета текста консоли
    return 0;
}
int Exsample1(void)
{
    /* 
    1. Напишите программу, которая преобразует время в минутах в часы и минуты.
Для значения бО создайте символическую констану посредством #define или
const. Используйте цикл while, чтобы обеспечить пользователю возможность
повторного ввода значений и для прекращения цикла, если вводится значение
времени, меньшее или равное нулю.
    */
    //Exsample0();
    int minuts, tHours,tMinuts;
    const int MIN_HOUR = 60;
    printf("\n\033[1;4;44mЗадание 1. Преобразует время в минутах в часы и минуты\033[0m\n");
    loop:
    printf("Введите минуты(<=0 - конец):_____\b\b\b\b\b");
    scanf_s("%d", &minuts);
    if (minuts <= 0) goto end;
    tHours = minuts / MIN_HOUR;
    tMinuts = minuts % MIN_HOUR;
    printf("%dчас.%dмин\n", tHours, tMinuts);
    goto loop;
    end:
    printf("\033[37;40m");      // восстановить стандартные цвета текста консоли
    return 0;
}
int Exsample2(void)
{
    /*
2. Напишите программу, которая запрашивает у пользователя ввод целого числа, а
затем выводит все целые числа, начиная с этого числа (и включая его) и заканчивая
числом, которое больше введенного значения на 10 (включая его). (То есть,
если вводится число 5, то в выводе должны присутствовать числа от 5 до 15.)
Обеспечьте разделение выводимых значений друг от друга пробелами, символами
табуляции или символами новой строки*/
    int input;
    printf("\n\033[1;4;44mЗадание 2. Выводит 10 целых начиная с заданного.\033[0m\n");
    printf("Введите целое:_____\b\b\b\b\b");
    scanf_s("%d", &input);
    for (int i = 0; i < 10; i++) printf("%d ", i + input);
    return 0;
}
int Exsample3(void)
{
    /*
    3. Напишите программу, которая запрашивает у пользователя ввод количества
    дней и затем преобразует это значение в количество недемь и дней. Например,
    18 дней программа должна преобразовать в 2 недели и 4 дня. Отображайте результаты
    в следующем формате: 18 дней составляют 2 недели и 4 дня.
    Чтобы пользователь мог многократно вводить количество дней, используйте
    цикл while. Цикл должен завершаться при вводе пользователем неположительного значения, например, О или -20.
    */
    int input;
    const int DEYW = 7;
    printf("\n\033[1;4;44mЗадание 3. преобразует дни в недели и дни.\033[0m\n");
    loop:
    printf("Введите число дней(<=0 конец):______\b\b\b\b\b\b");
    scanf_s("%d", &input);
    if (input <= 0) goto end;
    printf("%dнедель %dдней\n ", input/DEYW,input%DEYW);
    goto loop;
end:
    return 0;
}
int Exsample4(void)
{
    /*
    4. Напишите программу, которая запрашивает у пользователя ввод значения высоты
в сантиметрах, после чего отображает высоту в сантиметрах, а также в футах и дюймах. 
Должны быть разрешены дробные части сантиметров и дюймов.
Программа должна позволить пользователю продолжать ввод значений высоты
до тех пор, пока не будет введено неположительное значение. 
Вывод этой программы должен иметь следующий вид:
Введите высоту в сантиметрах: 182
182.0 см = 5 футов, 11.7 дюймов
Введите высоту в сантиметрах (<=О для выхода из програ^ммы) : 168.7
168.0 см = 5 футов, 6.4 дюймов
Введите высоту в сантиметрах (<=О для выхода из програ^ммы) : 0
Работа завершена.
    */
    float input;
    const int FUT_D = 12;       // дюймов в футе
    const float D_SM = 2.54;    // сантиметров в дюйме
    float fite, inch,sFite,sInch;
    printf("\n\033[1;4;44mЗадание 4. Преобразует высоту в сантиметрах в высоту в футах, дюймах, в футах и дюймах.\033[0m\n");
loop:
    printf("Введите высоту(см)(<=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%f", &input);
    if (input <= 0) goto end;
    inch = input / D_SM;
    fite = inch / FUT_D;
    sFite = (int)inch / FUT_D;
    sInch= (int)inch % FUT_D;
    printf("%2.1fсм = %2.1fфут(%2.1fдюйм) или %2.0fфута и %2.1fдюйма.\n ", input, fite , inch, sFite,sInch);
    goto loop;
end:;
    printf("Завершение программы.\n");
    return 0;
}
int Exsample5(void)
{
    /*
   5. Внесите изменения в программу addemup. с (листинг 5.13), которая вычисляет
сумму первых 20 целых чисел. (Если хотите, можете считать addemup. с программой,
которая вычисляет сумму, которую вы будете иметь спустя 20 дней, если в
первый день вы получаете $1, во второй день — $2, в третий день — $3 и т.д.)
Модифицируйте программу так, чтобы можно было интерактивно указать, насколько
далеко должно распространяться вычисление. Другими словами, замените
число 20 переменной, значение которой вводится пользователем.
    */
    int input;
    long int summ;
    printf("\n\033[1;4;44mЗадание 5. Вычисляет сумму ряда от 1 до заданного.\033[0m\n");
loop:
    printf("Введите последнее целое число(<=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%d", &input);
    if (input <= 0) goto end;
    summ = 0;
    for (int i = 1; i <= input; i++) summ += i;
    printf("Сумма ряда 1+2+...+%d = %d\n ", input, summ);
    goto loop;
end:;
    printf("Завершение программы.\n");
    return 0;
}
int Exsample6(void)
{
    /*
  6. Теперь модифицируйте программу из упражнения 5, чтобы она вычисляла сумму
квадратов целых чисел. (Или, если вам гак больше нравится, программа должна
вычислять сумму, которую вы получите, если в первый день вам загшатят $1, во
второй день — $4, в третий день — $9 и т.д.) В языке С отсутствует функция возведения
в квадрат, но, как вы знаете, квадрат числа n равен n*n.
    */
    int input;
    long int summ;
    printf("\n\033[1;4;44mЗадание 6. Вычисляет сумму квадратов ряда от 1 до заданного.\033[0m\n");
loop:
    printf("Введите последнее целое число(<=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%d", &input);
    if (input <= 0) goto end;
    summ = 0;
    for (int i = 1; i <= input; i++) summ += i*i;
    printf("Сумма ряда 1*1+2*2+...+%d*%d = %d\n ",input, input, summ);
    goto loop;
end:;
    printf("Завершение программы.\n");
    return 0;
}
long double qube(double x)
{
    return x * x*x;
}
int Exsample7(void)
{
    /*
  7. Напишите программу, которая запрашивает ввод числа типа double и выводит
значение куба этого числа. Для этого используйте собственную функцию,
которая возводит значение в куб и выводит полученный результат. Программа
main () должна передавать этой функции вводимое значение.
    */
    double input;
    long double qubeVal;
    printf("\n\033[1;4;44mЗадание 7. ввод числа типа double и выводит значение куба этого числа.\033[0m\n");
loop:
    printf("Введите число(<=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%lf", &input);
    if (input <= 0) goto end;
    qubeVal = qube(input);
    printf("Куб числа %lf = %lf\n ", input, qubeVal);
    goto loop;
end:
    printf("Завершение программы.\n");
    return 0;
}
int Exsample8(void)
{
    /*
8. Напишите программу, которая выводит результаты применения операции деления
по модулю. Пользователь должен первым ввести целочисленное значение,
которое используется в качестве второго операнда и остается неизменным.
Затем пользователь должен вводить числа, для которых будет вычисляться результат
деления по модулю. Процесс должен прерываться вводом значения, которое
равно или меньше 0. Пример выполнения этой программы должен выглядеть следующим образом:
Эта программа вычисляет результаты деления по модулю.
Введите целое число, которое будет служить вторым операндом: 256
Теперь введите первьй операнд: 438
438 % 256 равно 182
Введите следующее число для первого операнда (<= О для выхода из
програ^ммы): 1234567
1234567 % 256 равно 135
Введите следующее число для первого операнда (<= О для выхода из
програ^ммы) : О
Готово    */
    int input1,input2;
    printf("\n\033[1;4;44mЗадание 8. Эта программа вычисляет результаты деления по модулю.\033[0m\n");
loop:
    printf("Введите целое число, которое будет служить вторым операндом(<=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%d", &input2);
    if (input2 <= 0) goto end;
    loop1:
    printf("Теперь введите первьй операнд(=0 конец):.......\b\b\b\b\b\b\b");
    scanf_s("%d", &input1);
    if (input1 == 0) goto loop;
    printf("%d\t %% \t%d \tравно \t%d\n ", input1, input2, input1 % input2);
    goto loop1;
end:
    printf("Завершение программы.\n");
    return 0;
}
void Temperatures(double tFarenheit)
{
    const double C1 = 5., C2 = 9., C3 = 32.0, K1=273.16;
    double tCelsium, tKelvin;
    tCelsium = C1 / C2 * (tFarenheit - C3);
    tKelvin = tCelsium + K1;
    printf("Фаренгейт- %2.2lf \tЦельсия- %2.2lf \tКельвина- %2.2lf\t", tFarenheit, tCelsium, tKelvin);
}
int Exsample9(void)
{
    /*
9. Напишите программу, которая запрашивает у пользователя ввод значения температуры
по Фаренгейту. Программа должна считывать значение температуры
как число типа double и передавать его в виде аргумента пользовательской функции
по имени Temperatures(). Эта функция должна вычислять эквивалентные
значения температуры 110 Цельсию и по Кельвину и отображать на экране
все три значения температуры с точностью до двух позиций справа от десятичной
точки. Функция должна идентифицировать каждое значение символом соответствующей
температурной шкалы. Вот формула перевода температуры по
Фаренгейту в температуру по Цельсию:
Температура по Цельсию = 5.0 / 9.0 х ( температура по Фаренгейту - 32.0)
В шкале Кельвина, которая обычно применяется в науке, 0 представляет абсолютный
нуль, т.е. минимальный предел возможных температур. Формула перевода
температуры по Цельсию в температуру по Фаренгейту имеет вид:
Температура по Кельвину = температура по Цельсию + 273.16
Функция Temperatures() должна использовать const для создания символических
представлений трех констант, которые участвуют в преобразованиях. Чтобы
предоставить пользователю возможность многократного ввода значений температуры,
в функции main () должен быть организован цикл который завершается
при вводе символа q или другого нечислового значения. Воспользуйтесь тем фактом,
что функция scanf () возвращает количество прочитанных ею элементов,
поэтому она возвратит 1, если прочитает число, но не будет возвращать 1, когда
пользователь введет q. Операция == выполняет проверку на равенство, так что
ее можно применять для сравнения возвращаемого значения scanf () с 1.
*/
    double input;
    printf("\n\033[1;4;44mЗадание 9. Перевод температурыF в температуруK и температуруC.\033[0m\n");
loop:
    printf("Температура по Фаренгейту(любая буква - конец):.......\b\b\b\b\b\b\b");
    if(scanf_s("%lf", &input) <1) goto end;
    Temperatures(input);
    goto loop;
end:
    printf("Завершение программы.\n");
    return 0;
}

