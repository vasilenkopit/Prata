#include <Windows.h >
#include <stdio.h >
#include <conio.h >
//#include <clocale>
int Test2(void);
int main(void)		/* простая программа */
{
	int num;
	num = 1;
	//char* locale = setlocale(LC_ALL, ""); //
	//setlocale(LC_ALL,"Russian");
	SetConsoleCP(1251);			//установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);	//установка кодовой страницы win-cp 1251 в поток вывода
	printf("Я простой "); 
	printf("компьютер.\n");
	printf("Моей любимой цифрой является %d, так как она первая. \n", num);
	int s;
	s = 56;
	printf("B году %d %d %d недель.\n", s,365/7, 12*4);
	printf ("Что?\n/nНе клюет?\n");
	Test2();
	return 0;
}