#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 6

struct Jugadores{

    char nombre[20];
    char apellido [20];
    int camiseta;
    float goles;
    char club [20];
};

typedef struct Jugadores *jugadorPtr;

jugadorPtr crearVector(int t);

jugadorPtr cargarNulos();

void cargarJugadoresNulos(jugadorPtr j[], int t);

void leerArchivoJugadores (jugadorPtr j[]);

void mostrarJugador(jugadorPtr j);

void mostrarJugadores(jugadorPtr j[], int t);

void ordenarPromedio(jugadorPtr j[], int t);

void guardarDatos(jugadorPtr j[], int t);



int main()
{
   jugadorPtr j = crearVector(TAM);

   cargarJugadoresNulos(j,TAM);

   leerArchivoJugadores(j);

   mostrarJugadores(j,TAM);

   ordenarPromedio(j,TAM);

   guardarDatos(j,TAM);
    return 0;
}

jugadorPtr crearVector(int t){

    jugadorPtr j = malloc(t*sizeof(struct Jugadores));
    return j;
};

jugadorPtr cargarNulos(){

    jugadorPtr j = malloc(sizeof(struct Jugadores));

    strcpy(j->nombre, "VACIO");
    strcpy(j->apellido, "VACIO");
    strcpy(j->club, "VACIO");
    j->camiseta = -1;
    j->goles = -1;

    return j;
};

void cargarJugadoresNulos(jugadorPtr j[], int t){

    for(int i=0; i<t; i++){

        j[i] = cargarNulos();
    }

};

void leerArchivoJugadores (jugadorPtr j[]){

    FILE *archivo = fopen("jugador.txt", "r");

    if ( archivo == NULL){

        printf("No se pudo abrir el archivo\n");
        exit(1);
    }

    int pos=0;

    while (!feof(archivo)){

        fscanf(archivo, "%[a-zA-Z], %[a-zA-Z], %d, %f, %[a-zA-Z]\n",
               j[pos]->nombre,
               j[pos]->apellido,
               &j[pos]->camiseta,
               &j[pos]->goles,
               j[pos]->club);

        pos++;
    }

    fclose(archivo);

};

void mostrarJugador(jugadorPtr j){

    printf("---------------\n");
    printf("Nombre: %s\n", j->nombre);
    printf("Apellido: %s\n", j->apellido);
    printf("N de camiseta: %d\n", j->camiseta);
    printf("Goles: %f\n", j->goles);
    printf("Club: %s\n", j->club);

};

void mostrarJugadores(jugadorPtr j[], int t){

    for(int i=0; i<t; i++){

        mostrarJugador(j[i]);
    }
};

void ordenarPromedio(jugadorPtr j[], int t){

    jugadorPtr aux;

    for(int i=0; i<t; i++){
        for(int k=0; k<t-1; k++){
            if(j[k]->goles < j[k+1]->goles){
                aux = k[j];
                k[j] = k[j+1];
                k[j+1] = aux;
            }
        }
    }
};

void guardarDatos(jugadorPtr j[], int t){

    FILE *archivo = fopen("ordenados.txt", "w");

    for(int i=0; i<t; i++){

        fprintf(archivo, "%s %s %d %.2f %s", j[i]->nombre, j[i]->apellido, j[i]->camiseta, j[i]->goles, j[i]->club);
    }

    fclose(archivo);
};
