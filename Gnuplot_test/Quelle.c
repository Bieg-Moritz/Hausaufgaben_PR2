#include <stdio.h>
#include <stdlib.h>

void myPlotFcn(double* xvals, double* yvals, int len)
{
	// write data to *.txt file
	FILE* fptr = fopen("tempData.txt", "w");
	for (int i = 0; i < len; i++) fprintf(fptr, "%lf %lfn", xvals[i], yvals[i]);
	fclose(fptr);

	FILE* gnuplotPipe = _popen("gnuplot -persistent", "w");
	fprintf(gnuplotPipe, "plot ´tempData.txt´\n");
	fprintf(gnuplotPipe, "exit");
	fclose(gnuplotPipe);
}

int main()
{
	int value1, value2 = 0;

	printf("plotting x² from: \n");
	scanf("%d", &value1);
	printf("to: \n");
	scanf("%d", &value2);

	int length = value2 - value1;

	double* xvals = (double*)malloc(sizeof(double) * length);
	double* yvals = (double*)malloc(sizeof(double) * length);

	for (int i = 0; i < length; i++)
	{
		xvals[i] = value1 + i;
		yvals[i] = xvals[i] * xvals[i];
	}

	return 0;
}
