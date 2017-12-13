#include <stdio.h>
#include "Nodo.h"
#include <conio.h>
#include <windows.h>


void main()
{
	Nodo *lista = new Nodo();
	bool continuar = false;
	do
	{
		continuar = generarMenu(lista);

	} while (continuar == false);
	system("pause");
}