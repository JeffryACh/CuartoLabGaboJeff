﻿/*	Autores:		- Victor Garro Abarca		- Jeffry Araya Chaves		- Gabriel Barrantes Villalobos	FechaDeCreacion: 28/02/2024 17:55	FechaDeUltimaModificacion: 02/03/2024*/#include <stdio.h>#include <windows.h>#include <stdlib.h>#include <string.h>#include <string>#include <stdio.h>#include "stdafx.h"#include <iostream>using namespace std;//LISTA ENLAZADA DOBLE/*	Nodo TArticulo		- int Codigo: Es el codigo del articulo		- char Nombre[20]: Es el nombre del articulo		- int Disponible: Es la cantidad de articulos disponibles		- float Precio: Es el precio del articulo		- TArticulo *Siguiente: Es un puntero que apunta al siguiente articulo		- TArticulo *Anterior: Es un puntero que apunta al articulo anterior*/typedef struct TArticulo{	int Codigo;	char Nombre[20];	int Disponible;	double Precio;	TArticulo*Anterior;	TArticulo*Siguiente;}X;typedef TArticulo * PtrTArticulo;/*	Inicializa la lista de articulos		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos*/void InicializarInventario(PtrTArticulo &Lista){	Lista = NULL;}/*	Crea un articulo		- int NCodigo: Es el codigo del articulo		- int NDisponible: Es la cantidad de articulos disponibles		- float NPrecio: Es el precio del articulo		+ PtrTArticulo: Retorna un puntero de tipo TArticulo*/PtrTArticulo CrearArticulo(int NCodigo, int NDisponible, double NPrecio){	PtrTArticulo Nuevo = new(TArticulo);	char buffer[5];	Nuevo->Codigo = NCodigo;	Nuevo->Disponible = NDisponible;	Nuevo->Precio = NPrecio;	strcpy_s(Nuevo->Nombre,"Pieza") ;	_itoa_s(NCodigo, buffer, 10);	strcat_s(Nuevo->Nombre,buffer);	Nuevo->Anterior = NULL;	Nuevo->Siguiente = NULL;	return Nuevo;}/*	Agrega un articulo al final de la lista		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos		- PtrTArticulo &Nuevo: Es un puntero que apunta al articulo que se va a agregar*/void AgregarFinalInventario(PtrTArticulo &Lista, PtrTArticulo &Nuevo){	PtrTArticulo Aux;	Aux = Lista;	if (Aux == NULL){		Lista = Nuevo;	}	else{		while (Aux->Siguiente != NULL){			Aux = Aux->Siguiente;		}		Aux->Siguiente = Nuevo;		Nuevo->Anterior = Aux;	}}/*	Agrega un articulo al inicio de la lista		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos		- PtrTArticulo &Nuevo: Es un puntero que apunta al articulo que se va a agregar*/void AgregarInicioInventario(PtrTArticulo &Lista, PtrTArticulo &Nuevo){		if (Lista == NULL){		Lista = Nuevo;	}	else	{		Nuevo->Siguiente = Lista;		Lista->Anterior = Nuevo;		Lista = Nuevo;	}}/*	Lista el inventario		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos*/void Listar_Inicio_a_Final(PtrTArticulo &Lista){	PtrTArticulo Aux;	Aux = Lista;	while (Aux!= NULL){		cout << "[";		cout << Aux->Codigo << ",";		cout << Aux->Nombre << ",";		cout << Aux->Precio << "] - ";		Aux = Aux->Siguiente;	}	system("pause");}/*	Lista el inventario		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos*/void Listar_Final_a_Inicio(PtrTArticulo &Lista){	PtrTArticulo Aux;	Aux = Lista;	while (Aux->Siguiente != NULL)  Aux = Aux->Siguiente;	while (Aux != NULL){		cout << "[";		cout << Aux->Codigo << ",";		cout << Aux->Nombre << ",";		cout << Aux->Precio << "] - ";		Aux = Aux->Anterior;	}	system("pause");}/*	Destruye la lista de articulos		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos*/void DestruirInventario(PtrTArticulo &Lista){	PtrTArticulo Aux;	Aux = Lista;	while (Aux != NULL)	{		Lista = Lista->Siguiente;		delete(Aux);		Aux = Lista;	}}//implementar//void BorrarArticulo(PtrTArticulo& Lista, int codigoArticulo)/*	Borra un articulo de la lista		- PtrTArticulo &Lista: Es un puntero que apunta a la lista de articulos		- int codigoArticulo: Es el codigo del articulo que se va a borrar*/void BorrarArticulo(PtrTArticulo& Lista, int codigoArticulo) {	PtrTArticulo Aux;	Aux = Lista;	while (Aux != NULL) {		if (Aux->Codigo == codigoArticulo) {			if (Aux->Anterior == NULL) {				Lista = Aux->Siguiente;				if (Aux->Siguiente != NULL) {					Aux->Siguiente->Anterior = NULL;				}			}			else {				if (Aux->Siguiente != NULL) {					Aux->Anterior->Siguiente = Aux->Siguiente;					Aux->Siguiente->Anterior = Aux->Anterior;				}				else {					Aux->Anterior->Siguiente = NULL;				}			}			delete(Aux);			break;		}		Aux = Aux->Siguiente;	}}/*	Funcion Main*/void main() {	// creacion  de variables	PtrTArticulo Nuevo;	PtrTArticulo Abarrotes;// Carga en la lista c'odigos del 1 al 100, luego los lista del inicio al final y luego del final al inicio.  Finalmente destruye la lista.//INICIO PILOTO AGREGANDO AL INICIO EN LISTA DOBLE	InicializarInventario(Abarrotes);	for (int i = 1; i <= 100; i++)	{		Nuevo = CrearArticulo(i, i, i);		AgregarInicioInventario(Abarrotes, Nuevo);	}	system("pause");	system("cls");	cout << "Listando elementos del Inicio al Final de una lista creada con insercion al inicio"<<endl;	Listar_Inicio_a_Final(Abarrotes);	cout << "Listando elementos del Final al Inicio de una lista creada con insercion al inicio" << endl;	Listar_Final_a_Inicio(Abarrotes);	DestruirInventario(Abarrotes);//FIN PILOTO AGREGANDO AL INICIO EN LISTA DOBLE//INICIO PILOTO AGREGANDO AL FINAL EN LISTA DOBLE	InicializarInventario(Abarrotes);	for (int i = 500; i <= 600; i++)	{		Nuevo = CrearArticulo(i, i, i);		AgregarFinalInventario(Abarrotes, Nuevo);	}	system("pause");	system("cls");	cout << "Listando elementos del Inicio al Final de una lista creada con insercion al final" << endl;	Listar_Inicio_a_Final(Abarrotes);	cout << "Listando elementos del Final al Inicio de una lista creada con insercion al final" << endl;	Listar_Final_a_Inicio(Abarrotes);	DestruirInventario(Abarrotes);//FIN PILOTO AGREGANDO AL FINAL EN LISTA DOBLE}