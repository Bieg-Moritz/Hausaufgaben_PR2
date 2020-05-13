#include <stdio.h>					
#include <stdlib.h>																							// 11.05.2020
#include <math.h>																							// Luca Schmidt & Moritz Bieg
																											// Newton-Verfahren f�r Funktionen mit 3 Koeffizienten und einem Absolutglied

double Val1 = 1;
double Val2 = -6;
double Val3 = 9;
double Val4 = -8;
double Exp1 = 2;
double Exp2 = 1;
double X = -1;
double Xnew = 0;
double Lsg1, Lsg2;



double Fcn(double Val1, double Val2, double Val3, double Val4, double Exp1, double Exp2, double X)
{
	Lsg1 = pow((X * Val1), Exp1) + pow((X * Val2), Exp2) + Val3*X + Val4;  
																											// Lsg1 = Val1*X ^ Exp1 + Val2*X ^ Exp2 + Val3*X + Val4 
	return Lsg1;
}

double Der(double Val1, double Val2, double Val3, double Exp1, double Exp2, double X)
{
	Lsg2 = pow((Exp1 * Val1 * X), (Exp1 - 1)) + pow((Exp2 * Val2 * X), (Exp2 - 1)) + Val3;					// Fcn abgeleitet

	return Lsg2;
}





int main()
{
	printf("Newton-Raphson-Verfahren:  \n \n");
	printf("Eingegebene Funktion: (%.1f*X ^ %.1f) + (%.1f*X ^ %.1f) + %.1f*X + %.1f \n\n", Val1, Exp1, Val2, Exp2, Val3, Val4);

	Lsg1 = pow((X * Val1), Exp1) + pow((X * Val2), Exp2) + Val3;

	while (  Lsg1 > 0.0000001 || Lsg1 < -0.000001)															// Schleife bis Lsg1 (Y-Wert) fast Null ist
	{
		                

		Lsg1 = Fcn(Val1, Val2, Val3, Val4, Exp1, Exp2, X);													// Lsg1 = Val1*X ^ Exp1 + Val2*X ^ Exp2 + Val3*X + Val4
		
		Lsg2 = Der(Val1, Val2, Val3, Exp1, Exp2, X);														// Fcn abgeleitet

		Xnew = X - (Lsg1 / Lsg2);																			// Newton-Verfahren
		X = Xnew;

	}

	printf("Eine Nullstelle liegt ca. bei: %.5f \n \n", X);													// Ausgabe

}

/*
JW-2020-06-12:
--------------
> good implementation! (8/10) 
> missing extra lib (*.c + *.h) incl. includegard includeguards: -1 Pkt
> missing abort criteria max iterations: -1Pkt
*/
