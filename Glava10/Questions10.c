// вопросы для самоконтроля
// 
// 1. Что выведет следующая программа?
#include <stdio.h>
int quest1(void)
{
	int ref[] = { 8, 4, 0, 2 };
	int* ptr;
	int index;
	for (index = 0, ptr = ref; index < 4; index++, ptr++)
		printf("%d %d\n", ref[index], *ptr);
	return 0;
}
// 4. Каковы значения *ptr и *(ptr+2) в каждом из следующих случаев?
int quest4(void) 
{
	printf("4. Каковы значения *ptr и *(ptr+2) в каждом из следующих случаев?\n");
	{// а.
		int* ptr;
		int torf[2][2] = { 12, 14, 16 };
		ptr = torf[0];
		printf("*ptr=%d *(ptr+2)=%d\n", *ptr, *(ptr+2));
	}
	{// б.
		int* ptr;
		int fort[2][2] = { {12}, {14, 16} };
		ptr = fort[0];
		printf("*ptr=%d *(ptr+2)=%d\n", *ptr, *(ptr+2));
	}
// 5. Каковы значения **ptr и **(ptr + 1) в каждом из следующих случаев?
	printf("5. Каковы значения **ptr и **(ptr + 1) в каждом из следующих случаев?\n");
	//а. 
	{
		int(*ptr)[2];
		int torf[2][2] = { 12, 14, 16 };
		ptr = torf;
		printf("**ptr=%d **(ptr+1)=%d\n", **ptr, **(ptr + 1));
	}
	//б.
	{
		int(*ptr)[2];
		int fort[2][2] = { {12}, {14,16} };
		ptr = fort;
		printf("**ptr=%d **(ptr+1)=%d\n", **ptr, **(ptr + 1));
	}
	{
		// 6. Предположим, что имеется следующее объявление:
		int grid[30][100];
		{
		//  а.Выразите адрес grid[22][56] одним способом.
			int (*prt)[30][100]= grid;
			int i = 0;
			
			//printf{"\n" };
		}
		{
			//	б.Выразите адрес grid[22][0] двумя способами.
			int (*(*prt)[])[100] = grid;
			int(*prt1)[30][100];

			int i = 0;
			//printf{"\n" };
}
		{
			//	в.Выразите адрес grid[0][0] тремя способами.
			int(*prt)[30][100];
			int(*prt1)[30][100];
			int(*prt2)[30][100];
		}
		/*
		6. a. &grid [22][56]
		б. &grid[22][0] или grid[22]
			(Второй вариант представляет собой имя одномерного массива, состоящего
			из 100 элементов, т.е. адрес его первого элемента, которым является
			grid [22][0].)
		в. &grid[0][0] или grid[0] или (int *) grid.
			(Здесь grid[0] — это адрес элемента grid[0][0] типа in t, a g rid — адрес
			100-элементного массива grid[0]. Упомянутые два адреса имеют одно и то
			же значение, но разные типы; приведение делает типы одинаковыми.)
		*/
		{
			/*
			7. Создайте подходящее объявление для каждой из описанных ниже переменных.
				а. digits представляет собой массив из 10 значений int.
				б. rates представляет собой массив из шести значений float.
				в. mat представляет собой массив, состоящий из трех массивов, каждый из которых содержит 5 целых чисел.
				r. psa представляет собой массив, состоящий из 20 указателей на char.
				д. pstr представляет собой указатель на массив, состоящий из 20 значений char
			*/
			int digits[10];		// а.
			float rates[6];		// б.
			int mat[3][5];		// в.
			char* psa[20];		// г.
			char(*pstr)[20];	// д.
		}
		{
			/*
			8. Решите перечисленные ниже задачи.
				а. Объявите массив, состоящий из шести значений типа int, и инициализируйте
					его значениями 1, 2, 4, 8, 16 и 32.
				б. Используйте форму запись с массивом для представления третьего элемента
					(имеющего значение 4) массива, объявленного в пункте а).
				в. Предполагая, что действуют правила C99/C11, объявите массив из 100 значений
					типа int и инициализируйте его таким образом, чтобы последний элемент
					получил значение -1; значения остальных элементов монут быть произвольными.
				г. Предполагая, что действуют правила C99/C11, объявите массив из 100 значений
					типа int и инициализируйте его так, чтобы элементы 5, 10, 11, 12 и 3 получили
					значение 101; значения остальных элементов могут быть произвольными.
			*/
			int arr[6] = { 1, 2, 4, 8, 16 , 32 };	// 
			arr[2];									//
			int arr1[100] = { [99] = -1 };			//
			int arr2[100] = {[2]=101,[4]=101,[9]=101, 101, 101 };			//
			printf("\n");
		}
		{
			/*
			10. Предположим, что имеются следующие объявления:
				float rootbeer[10], things[10][5], *pf, value = 2.2;
				int i = 3;
				Укажите, какие из приведенных ниже операторов допустимы, а какие - нет:
				а. rootbeer [ 2] = value;
				б. scanf("%f", &rootbeer) ;
				в. rootbeer = value;
				г. printf("%f", rootbeer);
				д. things [ 4] [ 4] = rootbeer [ 3] ;
				е. things [5] = rootbeer;
				ж. pf = value;
				з. pf = rootbeer;
							*/
			float rootbeer[10], things[10][5], * pf, value = 2.2;
			int i = 3;
			rootbeer[2] = value;
			//scanf("%f", &rootbeer);
			//rootbeer = value;
			//printf("%f", rootbeer);
			things[4][4] = rootbeer[3];
			//things[5] = rootbeer;
			//pf = value;
			pf = rootbeer;
		}
		{
			/*
			12. Имеются е ются три объявления массивов:
				doubl e trots[20];
				short clops[10][30];
				long shots[5][10][15] ;
				а. Напишите прототип и оператор вызова для традиционной функции типа
				void, которая обрабатывает массив trots, и для функции С, использующей
				массив переменной длины.
				б. Напишите прототип и оператор вызова для традиционной функции типа
				void, которая обрабатывает массив clops, и для функции, использующей массив
				переменной длины.
				в. Напишите прототип и оператор вызова для традиционной функции типа
				void, которая обрабатывает массива shots, и для функции, использующей
				массив переменной длины.
			*/
			int i;
			double trots[20];
			short clops[10][30];
			long shots[5][10][15];
			// а.
			void func(int n, double* arr);	
			void process(double arr[], int n);
			//void C(int n, double arr[n]);
			func(20, trots);
			printf("После функции func:\n i \ttrots[i]\n");
			for (i = 0; i < 20; i++)
				printf("%2d \t%lf\n",i,trots[i]);
			printf("\n");
			process(trots, 20);
			printf("После функции process:\n i \ttrots[i]\n");
			for (i = 0; i < 20; i++)
				printf("%2d \t%lf\n", i, trots[i]);
			printf("\n");
			//C(20, trots);
			// б.
			void func2(int n, int m, short** arr);
			void process2(short arr[30], int n);
			//void C2(int n, int m, short ar[n][m]);
			//func2(10,30,clops);
			//printf("После функции func2:\n i \ttrots[i]\n");
			//for (i = 0; i < 20; i++)
			//	printf("%2d \t%lf\n", i, trots[i]);
			//printf("\n");
			process2(clops, 10);
			printf("После функции process2:\n [i,j] \tclops[i,j]\n");
			for (i = 0; i < 20; i++)
				for(int j=0;j<30;j++)
				printf("[%2d,%2d] \t%lf\n", i,j, clops[i,j]);
			printf("\n");
			//C2(10,30,clops);
			// в.
			void func3(int n, int m, int k, long*** arr);
			void processЗ(long arr[10][15], int n);
			//void C3(int n, int m, int k, long arr[n][m][k]);
			func3(5,10,15,shots);
			processЗ(shots, 5);
			//C3(5,10,15,shots);
		}
		{
			/*
			13. Имеются два прототипа функций:
				void show(const double ar[], int n) ; // n - количество элементов
				void show2(const double ar2[][3], int n) ; // n - количество строк
				а. Напишите вызов функции, который передает show () составной литерал, 
				содержащий значения 8, 3, 9 и 2.
				б. Напишите вызов функции, который передает show2 () составной литерал, 
				содержащий значения 8, З и 9 в первой строке и значения 5, 4 и 1 во второй строке.
			*/
			printf("13. Имеются два прототипа функций:\n");
			void show(const double ar[], int n) ; // n - количество элементов
			void show2(const double ar2[][3], int n) ; // n - количество строк
			//а.
			show((double[]){8,3,9,2}, 4);
			//б.
			double(*pdd)[3] = (double[][3]){{8, 3, 9}, {5,4,1}};
			show2( (double[][3]){ {8, 3, 9}, { 5,4,1 } }, 2);
			show2( pdd, 2);
		}
	}
}
void func(int n, double* arr) {
	for (int i = 0; i < n; i++) {
		arr[i] = 1.01*(i + 1);
		printf("ar[%d](%p) = %lf \t*(arr+%d)(%p) = %lf\n", i,&arr[i], arr[i], i,&(*(arr + i)), *(arr + i));
	}
}
void process(double arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = 10.001 * (i + 1);
		printf("ar[%d](%p) = %lf \t*(arr+%d)(%p) = %lf\n", i, &arr[i], arr[i], i, &(*(arr + i)), *(arr + i));
	}
}
void func2(int n, int m, short** arr) {
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) {
			arr[i][j] = (j + 1) * .001 + (i + 1) * 1.;
			printf("ar[%d,%d] = %lf \t*(arr+%d*%d+%d) = %lf\n", i,j, arr[i,j], i,m,j, *(arr + i*m+j));
		}
	}
}
void process2(short arr[30], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 30; j++) {
			////arr[i][j] = (j + 1) * .001 + (i + 1) * 1.;
			printf("ar[%d,%d] = %lf \t*(arr+%d*%d+%d) = %lf\n", i, j, arr[i, j], i, 30, j, *(arr + i * 30 + j));
		}
	}
}
void func3(int n, int m, int k, long*** arr) {
	for (int i = 0; i < n; i++) printf("ar[%d] = %lf \t*(arr+i) = %lf\n", i, arr[i],i,*(arr+i));
}
void processЗ(long arr[10][15], int n) {
	for (int i = 0; i < n; i++) printf("ar[%d] = %lf \t*(arr+i) = %lf\n", i, arr[i],i,*(arr+i));
}
void show2(const double ar2[][3], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			printf("ar[%d,%d] = %lf \t*(arr+%d*%d+%d) = %lf\n", i, j, ar2[i, j], i, 3, j, **(ar2 + i * 3 + j));
		}
	}
}
void show(const double ar[], int n) {
	for (int i = 0; i < n; i++) 
		printf("ar[%d](%p) = %lf \t*(arr+%d)(%p) = %lf\n", i, &ar[i], ar[i], i, &(*(ar + i)), *(ar + i));

}
