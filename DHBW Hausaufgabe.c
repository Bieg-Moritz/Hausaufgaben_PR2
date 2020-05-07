#include <stdio.h>					// Moritz Bieg
#include <stdlib.h>					// 07.05.2020

int main() {						

	int len = 5;

	double*vec = (double*)malloc(sizeof(double)*len);

	printf("Value of vec: \n");
	for(int i =0; i < len; i++)
	{
		printf("value %d = %d \n", i, vec[i]);
	}

	printf("\nAdress of vec: \n");
	for (int i = 0; i < len; i++)
	{
		printf("mem(ptr[i] = %p\n",&vec[i]);		// & ist das die Adresse angegeben wird   %
	}

	printf("\n Adress in dec: \n");
	for (int i = 0; i < len; i++) printf("mem(ptr[i]= %d\n", &vec[i]);

	return 0;
}  