/* Nimigean Emanuela- gr30226; Metode directe de sortare;
Se cere implementarea ​ corecta și ​ eficienta a 3 metode directe de sortare (sortarea bulelor, sortarea prin inserție – folosind inserție liniară sau binară, și sortarea prin selecție)    
Intrare: un șir de numere <a1,a2,...,an>  
Ieșire: o permutare ordonata a șirului de la intrare. 
Am implementat:
-Sortarea prin inserare ce consta in impartirea sirului intr-unul sortat(1->i) si unul nesortat(i+1->n) si se extrage in timp constant cate un element din partea nesortata, inserandu-se in partea sortata pe pozitia corespunzatoare, gasita in timp liniar.
Cazul favorabil este determinat de sirul gata ordonat, iar cel defavorabil, de cel ordonat invers.
-Sortarea prin selectie ce consta in selectarea acelui element din partea nesortata care corespunde pozitiei finale a partii sortate, in O(n-(i+1)), adaugarea facandu-se in timp constant.
Cazul favorabil este determinat de sirul gata ordonat, iar cel defavorabil, de cel ordonat invers.
-Sortarea bazata pe adiacenta ce presupune interschimbarea valorilor vecine din sir, doua cate doua, pana se obtine sirul ordonat. n-1 parcurgeri garanteaza sortarea, insa putem parcurge sirul doar atat timp cat la parcurgerea anterioara s-au mai realizat interschimbari si doar pana la pozitia ultimei interschimbari pentru a face sortarea mai eficienta.
Cazul favorabil este determinat de sirul gata ordonat, iar cel defavorabil, de cel ordonat invers, insa si un sir in care minimul este pus la final iar in rest este ordonat este tot defavorabil(ordonare crescatoare), in timp ce unul in care cea mai mare valoare este pe prima pozitie, iar restul sunt ordonate este considerat aproape favorabil deoarece, in cazul ordonarii crescatoare, shiftarea se face la stanga.
In sectiunea finala, Rulare, se verifica functionarea celor 3 metode pt sirul a[] = { 2,11,1,5,26 }.
Ca eficienta, insertion-sort si selection-sort sunt opuse, tinand cont ca sortarea prin inserare se face printr-o extragere usoara, iar cea prin selectie, printr-o adaugare usoara, compensand ca numar total de operatii.
*/


#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>



void insertionSort(int a[], int n, int *ass, int *comp)
{
	int j, k;
	for (int i = 1;i < n;i++)
	{
		k = a[i]; (*ass)++;
		j = i - 1;
		while (j >= 0 && k < a[j])
		{
			(*comp)++;
			a[j + 1] = a[j];  (*ass)++;
			j--;
		} //(*comp)++;
		a[j + 1] = k; (*ass)++;
	}
}

void swap(int *x1, int *x2)
{
	int aux;
	aux = *x1;
	*x1 = *x2;
	*x2 = aux;
}

void selectionSort(int a[], int n, int *ass, int *comp)
{
	for (int i = 0;i < n;i++)
	{
		int aux = i;
		for (int j = i + 1;j < n;j++)
		{
			(*comp)++;
			if (a[j] < a[aux])
			{
				aux = j;   (*ass) += 3;
			}
		}
		swap(&a[i], &a[aux]);  
	}
}

void bubbleSort(int a[], int n, int *ass, int *comp)
{
	int i = 0, sch = 0;
	while (!sch)
	{
		sch = 1;
		for (int j = 0;j < n - i - 1;j++)
		{
			if (a[j + 1] < a[j])
			{
				sch = 0;
				swap(&a[j + 1], &a[j]);
				(*ass) += 3;
			}
			(*comp)++;
		}
		i++;
	}
}

void generateBest(int *a, int n)
{
	for (int i = 0;i < n;i++)
		a[i] = i;
}

void generateWorst(int *a, int n)
{
	for (int i = 0;i < n;i++)
		a[i] = n - i-1;
}

void generateRandom(int *a, int n)
{
	for (int i = 0;i < n;i++)
		a[i] = rand();
}

void printArr(int a[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		printf("%d; ", a[i]);
	printf("\n");
}

int main()
{
	
	int ass = 0, comp = 0;
	//int a[10000];
	/*for (int i = 100;i <= 10000;i += 500)
	{
		generateBest(a, i);
		//insertionSort(a, i, &ass, &comp);
	    //selectionSort(a, i ,&ass, &comp);
		//bubbleSort(a, i, &ass, &comp);
		printf("\n %d %d", ass, comp);

	}
	for (int i = 100;i <= 10000;i += 500)
	{
		generateWorst(a, i);
		//insertionSort(a, i, &ass, &comp);
		//selectionSort(a, i ,&ass, &comp);
		bubbleSort(a, i, &ass, &comp);
		printf("\n %d,%d,%d", ass, comp, ass+comp);

	}
	
	
	
	
		for (int i = 100;i <= 10000;i += 500)
		{
			int as = 0, co = 0;
			for (int j = 0;j < 5;j++)
			{
				
				generateRandom(a, i);
				//insertionSort(a, i, &ass, &comp);
				//selectionSort(a, i ,&ass, &comp);
				//bubbleSort(a, i, &ass, &comp);
				//printf("\n %d,%d,%d", ass, comp, ass + comp);
				as += ass;
				co += comp;
			}
			as /= 5;co /= 5;
			printf("\n %d,%d,%d", as, co , as + co);
		}
		*/
		
	
	
	/*//Rulare:
	int a[] = { 2,11,1,5,26 };
	int n = sizeof(a) / sizeof(int);
	insertionSort(a, n, &ass, &comp);
	//selectionSort(a, n ,&ass, &comp);
	//bubbleSort(a, n, &ass, &comp);
	printArr(a, n);
	printf("\n%d %d", ass, comp);*/
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
