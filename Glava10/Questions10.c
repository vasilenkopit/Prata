// ������� ��� ������������
// 
// 1. ��� ������� ��������� ���������?
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
// 4. ������ �������� *ptr � *(ptr+2) � ������ �� ��������� �������?
int quest4(void) 
{
	printf("4. ������ �������� *ptr � *(ptr+2) � ������ �� ��������� �������?\n");
	{// �.
		int* ptr;
		int torf[2][2] = { 12, 14, 16 };
		ptr = torf[0];
		printf("*ptr=%d *(ptr+2)=%d\n", *ptr, *(ptr+2));
	}
	{// �.
		int* ptr;
		int fort[2][2] = { {12}, {14, 16} };
		ptr = fort[0];
		printf("*ptr=%d *(ptr+2)=%d\n", *ptr, *(ptr+2));
	}
// 5. ������ �������� **ptr � **(ptr + 1) � ������ �� ��������� �������?
	printf("5. ������ �������� **ptr � **(ptr + 1) � ������ �� ��������� �������?\n");
	//�. 
	{
		int(*ptr)[2];
		int torf[2][2] = { 12, 14, 16 };
		ptr = torf;
		printf("**ptr=%d **(ptr+1)=%d\n", **ptr, **(ptr + 1));
	}
	//�.
	{
		int(*ptr)[2];
		int fort[2][2] = { {12}, {14,16} };
		ptr = fort;
		printf("**ptr=%d **(ptr+1)=%d\n", **ptr, **(ptr + 1));
	}
	{
		// 6. �����������, ��� ������� ��������� ����������:
		int grid[30][100];
		{
		//  �.�������� ����� grid[22][56] ����� ��������.
			int (*prt)[30][100]= grid;
			int i = 0;
			
			//printf{"\n" };
		}
		{
			//	�.�������� ����� grid[22][0] ����� ���������.
			int (*(*prt)[])[100] = grid;
			int(*prt1)[30][100];

			int i = 0;
			//printf{"\n" };
}
		{
			//	�.�������� ����� grid[0][0] ����� ���������.
			int(*prt)[30][100];
			int(*prt1)[30][100];
			int(*prt2)[30][100];
		}
		/*
		6. a. &grid [22][56]
		�. &grid[22][0] ��� grid[22]
			(������ ������� ������������ ����� ��� ����������� �������, ����������
			�� 100 ���������, �.�. ����� ��� ������� ��������, ������� ��������
			grid [22][0].)
		�. &grid[0][0] ��� grid[0] ��� (int *) grid.
			(����� grid[0] � ��� ����� �������� grid[0][0] ���� in t, a g rid � �����
			100-����������� ������� grid[0]. ���������� ��� ������ ����� ���� � ��
			�� ��������, �� ������ ����; ���������� ������ ���� �����������.)
		*/
		{
			/*
			7. �������� ���������� ���������� ��� ������ �� ��������� ���� ����������.
				�. digits ������������ ����� ������ �� 10 �������� int.
				�. rates ������������ ����� ������ �� ����� �������� float.
				�. mat ������������ ����� ������, ��������� �� ���� ��������, ������ �� ������� �������� 5 ����� �����.
				r. psa ������������ ����� ������, ��������� �� 20 ���������� �� char.
				�. pstr ������������ ����� ��������� �� ������, ��������� �� 20 �������� char
			*/
			int digits[10];		// �.
			float rates[6];		// �.
			int mat[3][5];		// �.
			char* psa[20];		// �.
			char(*pstr)[20];	// �.
		}
		{
			/*
			8. ������ ������������� ���� ������.
				�. �������� ������, ��������� �� ����� �������� ���� int, � ���������������
					��� ���������� 1, 2, 4, 8, 16 � 32.
				�. ����������� ����� ������ � �������� ��� ������������� �������� ��������
					(�������� �������� 4) �������, ������������ � ������ �).
				�. �����������, ��� ��������� ������� C99/C11, �������� ������ �� 100 ��������
					���� int � ��������������� ��� ����� �������, ����� ��������� �������
					������� �������� -1; �������� ��������� ��������� ����� ���� �������������.
				�. �����������, ��� ��������� ������� C99/C11, �������� ������ �� 100 ��������
					���� int � ��������������� ��� ���, ����� �������� 5, 10, 11, 12 � 3 ��������
					�������� 101; �������� ��������� ��������� ����� ���� �������������.
			*/
			int arr[6] = { 1, 2, 4, 8, 16 , 32 };	// 
			arr[2];									//
			int arr1[100] = { [99] = -1 };			//
			int arr2[100] = {[2]=101,[4]=101,[9]=101, 101, 101 };			//
			printf("\n");
		}
		{
			/*
			10. �����������, ��� ������� ��������� ����������:
				float rootbeer[10], things[10][5], *pf, value = 2.2;
				int i = 3;
				�������, ����� �� ����������� ���� ���������� ���������, � ����� - ���:
				�. rootbeer [ 2] = value;
				�. scanf("%f", &rootbeer) ;
				�. rootbeer = value;
				�. printf("%f", rootbeer);
				�. things [ 4] [ 4] = rootbeer [ 3] ;
				�. things [5] = rootbeer;
				�. pf = value;
				�. pf = rootbeer;
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
			12. ������� � ���� ��� ���������� ��������:
				doubl e trots[20];
				short clops[10][30];
				long shots[5][10][15] ;
				�. �������� �������� � �������� ������ ��� ������������ ������� ����
				void, ������� ������������ ������ trots, � ��� ������� �, ������������
				������ ���������� �����.
				�. �������� �������� � �������� ������ ��� ������������ ������� ����
				void, ������� ������������ ������ clops, � ��� �������, ������������ ������
				���������� �����.
				�. �������� �������� � �������� ������ ��� ������������ ������� ����
				void, ������� ������������ ������� shots, � ��� �������, ������������
				������ ���������� �����.
			*/
			int i;
			double trots[20];
			short clops[10][30];
			long shots[5][10][15];
			// �.
			void func(int n, double* arr);	
			void process(double arr[], int n);
			//void C(int n, double arr[n]);
			func(20, trots);
			printf("����� ������� func:\n i \ttrots[i]\n");
			for (i = 0; i < 20; i++)
				printf("%2d \t%lf\n",i,trots[i]);
			printf("\n");
			process(trots, 20);
			printf("����� ������� process:\n i \ttrots[i]\n");
			for (i = 0; i < 20; i++)
				printf("%2d \t%lf\n", i, trots[i]);
			printf("\n");
			//C(20, trots);
			// �.
			void func2(int n, int m, short** arr);
			void process2(short arr[30], int n);
			//void C2(int n, int m, short ar[n][m]);
			//func2(10,30,clops);
			//printf("����� ������� func2:\n i \ttrots[i]\n");
			//for (i = 0; i < 20; i++)
			//	printf("%2d \t%lf\n", i, trots[i]);
			//printf("\n");
			process2(clops, 10);
			printf("����� ������� process2:\n [i,j] \tclops[i,j]\n");
			for (i = 0; i < 20; i++)
				for(int j=0;j<30;j++)
				printf("[%2d,%2d] \t%lf\n", i,j, clops[i,j]);
			printf("\n");
			//C2(10,30,clops);
			// �.
			void func3(int n, int m, int k, long*** arr);
			void process�(long arr[10][15], int n);
			//void C3(int n, int m, int k, long arr[n][m][k]);
			func3(5,10,15,shots);
			process�(shots, 5);
			//C3(5,10,15,shots);
		}
		{
			/*
			13. ������� ��� ��������� �������:
				void show(const double ar[], int n) ; // n - ���������� ���������
				void show2(const double ar2[][3], int n) ; // n - ���������� �����
				�. �������� ����� �������, ������� �������� show () ��������� �������, 
				���������� �������� 8, 3, 9 � 2.
				�. �������� ����� �������, ������� �������� show2 () ��������� �������, 
				���������� �������� 8, � � 9 � ������ ������ � �������� 5, 4 � 1 �� ������ ������.
			*/
			printf("13. ������� ��� ��������� �������:\n");
			void show(const double ar[], int n) ; // n - ���������� ���������
			void show2(const double ar2[][3], int n) ; // n - ���������� �����
			//�.
			show((double[]){8,3,9,2}, 4);
			//�.
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
void process�(long arr[10][15], int n) {
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
