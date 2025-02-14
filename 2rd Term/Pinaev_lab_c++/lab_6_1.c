#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
int test_masi=0;

void del_masi (int* b)
{	if (test_masi)
{       free (b); 
		test_masi--;
		printf ("delete:test_masi=%d\n",test_masi);
	}
else printf ("error delete: All memory returned to the heap!\n");
}

int* init_masi (int size, int dm, int neg)	
{	int *b,*tp; // начальный и рабочий указатели
	char cim;
	if (test_masi)
	{printf (" Multiple memory allocation!\n Allocate memory? (y/n) : ");
	 scanf ("%c",&cim);	if (cim=='n') return NULL; 
	}
	 b= (int*) calloc(size, sizeof(*b)); 			
	for (tp=b;tp<b+size;tp++) *tp=rand()%dm-neg;	
	test_masi++;
	printf ("init:test_masi=%d\n",test_masi);
	return b;
}

void print_masi(int* b, int size, int col)	// печать массива в col колонок
{int *tp;	// рабочий указатель
 int i;		// счетчик выведенных чисел
	for (tp=b,i=1; tp<b+size; tp++,i++)
	{printf ("%8d",*tp);
		if (i%col)	printf (" ");
		else 		printf ("\n");
	}
printf ("\n");
}

int main ()
{int *pi, *pi1;

pi= init_masi(10, 100, 0); 
print_masi(pi,10,5);		
system ("pause");
pi1= init_masi(50, 1000, 700); 
if (pi1==NULL)  exit(1); 		
print_masi (pi, 49, 7);		

del_masi (pi);
del_masi (pi1);
del_masi (pi); 
system ("pause");
return 0;
}




