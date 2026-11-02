#include <stdio.h>  //Trabajo de:Suhar Aristegui, Iker Vicente y Alain Souto
#include <stdlib.h>
#include <string.h>

void my_grep(const char *patron_filtrar, const char *archivo_filtrar){
    FILE *archi=fopen(archivo_filtrar, "rb");
if(archi==NULL){
    perror("Ha habido un problema con la apertura del archivo");
    exit(EXIT_FAILURE);
}
const int tamBuffer=4096;
char buffer[tamBuffer];
int linea=1;
while(fgets(buffer,tamBuffer,archi)!=NULL){
    if(strstr(buffer,patron_filtrar)!=NULL){//strstr busca un substring en un string, y en caso de que el substring este contenido en el string devuelve un puntero a el string
        printf("Coincidencia en la linea %d: %s",linea, buffer);
    }
}
fclose(archi);
}

int main(int argc, char *argv[]){
    if(argc<3){
        perror("La cantidad de argumentos es menor a la esperada");
        exit(EXIT_FAILURE);
    }
    for(int i=2; i<argc;i++){
        my_grep(argv[1],argv[i]);
    }
    return 0;
}