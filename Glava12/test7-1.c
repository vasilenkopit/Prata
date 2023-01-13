#include <stdio.h>
// 7. Каким функциям известна каждая переменная в следующем коде? Если ли в коде ошибки?
/* файл 1 */
int dais;
void root();
int stem();
int peta1();
int test7(void)
{
	int lily;
	printf("test7:int lily- &lily=%p, \t&dais=%p. \n", &lily, &dais);
	stem();
	root();
	peta1();
	return 0;
}
int peta1()
{
	extern int dais;// , lily;
	printf("peta1: \t\t&dais=%p\n", &dais);// , & lily);
	return 0;
}