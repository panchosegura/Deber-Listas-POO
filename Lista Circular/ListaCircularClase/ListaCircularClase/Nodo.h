#ifndef NODO_H
#define NODO_H


// Definiciones
#define ANSI_COLOR_GREEN   "\x1b[32;1m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_BLUE    "\x1b[34;1m"
#define _CRT_SECURE_NO_WARNINGS
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

class Nodo {
private:
	int dato;
	int contador;
	Nodo *siguiente;
public:
	Nodo();
	int getDato();
	void setDato(int dato);
	void insertar();
	void modificar();
	void buscar();
	void eliminar();
	void imprimir();
};

//Prototipo
void gotoxy(int x, int y);
bool generarMenu(Nodo *&lista);
char *ingresar(char *msg);

#endif // !NODO_H



