#include "Nodo.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

Nodo::Nodo()
{
	this->siguiente = NULL;
	this->dato = NULL;
	this->contador = 0;
}
int Nodo::getDato()
{
	return this->dato;
}
void Nodo::setDato(int valor)
{
	this->dato = valor;
}
void Nodo::insertar()
{
	int numero;
	do 
	{
		numero = atoi(ingresar("Ingresar el dato, debe ser mayor que cero\n"));
	} while (numero <= 0);

	if (this->dato == NULL)
	{
		this->setDato(numero);
		this->siguiente = this;
	}
	else
	{
		Nodo *nuevoNodo = new Nodo();//Creamos un nuevo nodo y reservamos un espacio de memoria para el mismo
		nuevoNodo->setDato(numero);//Asignar n al campo dato del nuevo nodo

		Nodo *nodoAuxiliar = this; //crear nodo auxiliar
		int cont = 1;
		while (cont < this->contador)//recorrer los elementos de la lista hasta llegar al ultimo nodo
		{
			nodoAuxiliar = nodoAuxiliar->siguiente;
			cont++;
		}
		nodoAuxiliar->siguiente = nuevoNodo;//enlazar ultimo nodo con el nuevo nodo
		nuevoNodo->siguiente = this;
	}

	printf("Elemento insertado correctamente\n");
	this->contador++;
	system("pause");
}
void Nodo::modificar()
{
	Nodo *nodoActual = new Nodo();
	nodoActual = this;
	int posicion = atoi(ingresar("Ingrese la posicion del dato que desea modificar"));
	int contador = 0;
	int cont = 1;
	if (nodoActual->dato != NULL)
	{
		while ((contador < posicion) && (cont<this->contador))
		{
			nodoActual = nodoActual->siguiente;
			contador++;
			cont++;
		}
		if (contador == posicion)
		{
			printf("El valor del dato en la posicion %d es %d\n", posicion, nodoActual->dato);
			int numero;
			do
			{
				numero = atoi(ingresar("Ingresar el dato, debe ser mayor que cero\n"));
			} while (numero <= 0);
			nodoActual->setDato(numero);
		}
		else
			printf("El numero de posicion ingresado es muy grande, debe ser menor a %d\n", contador);
	}
	else
	{
		printf("La lista se encuentra vacía\n");
	}
	system("pause");
}
void Nodo::buscar()
{
	Nodo *nodoActual = new Nodo();
	nodoActual = this;
	int posicion = atoi(ingresar("Ingrese la posicion del dato que desea conocer"));
	int contador = 0;
	int cont = 1;
	if (nodoActual->dato != NULL)
	{
		while ((contador < posicion) && (cont<this->contador))
		{
			nodoActual = nodoActual->siguiente;
			contador++;
			cont++;
		}
		if (contador == posicion)
		{
			printf("El valor del dato en la posicion %d es %d\n", posicion, nodoActual->dato);
		}
		else
			printf("El numero de posicion ingresado es muy grande, debe ser menor a %d\n", contador);
	}
	else
	{
		printf("La lista se encuentra vacía\n");
	}
	system("pause");

}
void Nodo::eliminar()//Elimina la primera instancia del valor.
{
	Nodo *nodoActual = new Nodo();
	nodoActual = this;
	Nodo *nodoAnterior = new Nodo();
	int valor = atoi(ingresar("Ingrese el valor del dato que desea borrar"));
	int cont = 1;
	if (nodoActual->dato != NULL)
	{
		while ((nodoActual->getDato() != valor) && (cont<this->contador))
		{
			nodoAnterior = nodoActual;
			nodoActual = nodoActual->siguiente;
			cont++;
		}
		if (nodoActual->getDato() == valor)
		{
			if (nodoAnterior->siguiente != NULL)
				nodoAnterior->siguiente = nodoActual->siguiente;
			else
			{
				if (this->contador > 1)
				{
					this->dato = this->siguiente->dato;
					this->siguiente = this->siguiente->siguiente;
				}
				else
				{
					this->dato = NULL;
					this->siguiente = this;
				}
			}
			this->contador--;
		}
		else
			printf("El valor ingresado no se encuentra en la lista\n");
	}
	else
	{
		printf("La lista se encuentra vacía\n");
	}
	system("pause");

}
void Nodo::imprimir()
{
	Nodo *nodoActual = new Nodo();
	nodoActual = this;
	int cont = 1;
	if (nodoActual->dato != NULL)
	{
		while (cont<=this->contador)
		{
			printf("%d\n", nodoActual->getDato());
			nodoActual = nodoActual->siguiente;
			cont++;
		}
	}
	else
	{
		printf("La lista se encuentra vacía\n");
	}
	system("pause");
}
//Funciones
char *ingresar(char *msg)
{
	char dato[256];
	char c;
	int i = 0;
	printf("%s\n", msg);
	while ((c = _getch()) != 13)//13 es enter
	{
		if (c >= '0'&&c <= '9')
		{
			printf("%c", c);
			dato[i++] = c;
		}
		dato[i] = '\0';//Indica final de la cadena
	}
	printf("\n");

	return dato;
}
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
bool generarMenu(Nodo *&lista)
{
	bool continuar = false;
	system("cls");
	int indice = 1;
	char tecla;
	do
	{
		printf(ANSI_COLOR_BLUE "Elegir una opcion\n" ANSI_COLOR_RESET);
		switch (indice)
		{
		case 1:
			printf(ANSI_COLOR_GREEN "Insertar\n" ANSI_COLOR_RESET);
			printf("Modificar\n");
			printf("Buscar\n");
			printf("Eliminar\n");
			printf("Imprimir\n");
			printf("Salir\n");
			break;
		case 2:
			printf("Insertar\n");
			printf(ANSI_COLOR_GREEN "Modificar\n" ANSI_COLOR_RESET);
			printf("Buscar\n");
			printf("Eliminar\n");
			printf("Imprimir\n");
			printf("Salir\n");
			break;
		case 3:
			printf("Insertar\n");
			printf("Modificar\n");
			printf(ANSI_COLOR_GREEN "Buscar\n"  ANSI_COLOR_RESET);
			printf("Eliminar\n");;
			printf("Imprimir\n");
			printf("Salir\n");
			break;
		case 4:
			printf("Insertar\n");
			printf("Modificar\n");
			printf("Buscar\n");
			printf(ANSI_COLOR_GREEN "Eliminar\n"  ANSI_COLOR_RESET);
			printf("Imprimir\n");
			printf("Salir\n");
			break;
		case 5:
			printf("Insertar\n");
			printf("Modificar\n");
			printf("Buscar\n");
			printf("Eliminar\n");
			printf(ANSI_COLOR_GREEN "Imprimir\n" ANSI_COLOR_RESET);
			printf("Salir\n");
			break;
		case 0:
			printf("Insertar\n");
			printf("Modificar\n");
			printf("Buscar\n");
			printf("Eliminar\n");
			printf("Imprimir\n");
			printf(ANSI_COLOR_GREEN "Salir\n" ANSI_COLOR_RESET);
			break;
		}
		tecla = _getch();
		if (tecla == -32)
		{
			switch (_getch())
			{
			case KEY_LEFT:
			case KEY_UP:
				indice--;
				if (indice < 0)
					indice = 5;
				break;
			case KEY_RIGHT:
			case KEY_DOWN:
				indice++;
				if (indice > 5)
					indice = 0;
				break;
			default:
				printf("Use las flechas!");
				break;
			}
		}
		gotoxy(0, 0);
	} while (tecla != 13);
	if (tecla == 13)
	{
		system("cls");
		switch (indice)
		{
		case 1:
			lista->insertar();
			break;
		case 2:
			lista->modificar();
			break;
		case 3:
			lista->buscar();
			break;
		case 4:
			lista->eliminar();
			break;
		case 5:
			lista->imprimir();
			break;
		case 0:
			printf("Gracias y hasta pronto\n");
			continuar = true;
			break;
		default:
			printf("Ingrese un valor del menu\n");
			break;
		}
	}
	return continuar;
}