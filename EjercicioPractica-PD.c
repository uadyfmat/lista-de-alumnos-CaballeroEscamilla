//Liblerias
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

//Estructuras
typedef struct{
    char* Nombre;
    int Cred_Aprob;
    int semestre_equival;
}Alumno;

struct nodo{
    Alumno* alumno;
    struct nodo* siguiente;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

//Firmas
char* crearCadena(char* cadena);
Alumno* crearAlumno(char* nombre, int creditos, int semestre);
NodoPtr crearNodo(Alumno* alumno);
int InsertarNodoOrdenado(NodoPtr nodo, NodoPtr* inicioPtr);
void imprimirLista(NodoPtr actual);

//Función principal
int main(void){
    NodoPtr inicioPtr = NULL;

    InsertarNodoOrdenado(crearNodo(crearAlumno("José Perez", 115, 5)), &inicioPtr);
    InsertarNodoOrdenado(crearNodo(crearAlumno("Juan Chavez", 107, 3)), &inicioPtr);
    InsertarNodoOrdenado(crearNodo(crearAlumno("Amisadai Panti", 123, 4)), &inicioPtr);
    InsertarNodoOrdenado(crearNodo(crearAlumno("Eduardo Chable", 140, 6)), &inicioPtr);
    InsertarNodoOrdenado(crearNodo(crearAlumno("María Escmilla", 94, 3)), &inicioPtr);

    imprimirLista(inicioPtr);
}

//Funciones
char* crearCadena(char* cadena){
    int longitud = strlen(cadena);
    char* nuevacadena = malloc(longitud+1);
    strcpy(nuevacadena, cadena);
    return nuevacadena;
}

Alumno* crearAlumno(char* nombre, int creditos, int semestre){
    Alumno* nuevoalumno = malloc(sizeof(Alumno));
    nuevoalumno->Nombre = crearCadena(nombre);
    nuevoalumno->Cred_Aprob = creditos;
    nuevoalumno->semestre_equival = semestre;
    return nuevoalumno;
}

NodoPtr crearNodo(Alumno* alumno){
    NodoPtr nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->alumno = alumno;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

int InsertarNodoOrdenado(NodoPtr nodo, NodoPtr* inicioPtr) {
    NodoPtr anterior = NULL;
    NodoPtr actual = *inicioPtr;

    while (actual != NULL && nodo->alumno->Cred_Aprob < actual->alumno->Cred_Aprob) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (anterior == NULL) {
        nodo->siguiente = *inicioPtr;
        *inicioPtr = nodo;
    } else {
        anterior->siguiente = nodo;
        nodo->siguiente = actual;
    }

    return 0;
}

void imprimirLista(NodoPtr actual){
    if(actual == NULL){
        printf("La lista esta vacia");
    } else {
        printf("Contenido dela lista: \n");
        while(actual != NULL){
            printf("Nombre: %s ; Creditosaprobados: %d; Semestre equivalente: %d \n", actual->alumno->Nombre, actual->alumno->Cred_Aprob, actual->alumno->semestre_equival);
            actual = actual->siguiente;
        }
        printf("NULL\n\n");
    }
}