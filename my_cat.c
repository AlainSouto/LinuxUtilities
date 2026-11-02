#include <stdio.h>  //Trabajo de:Suhar Aristegui, Iker Vicente y Alain Souto
#include <stdlib.h>
#include <string.h>

void my_cat(const char *archivo_a_abrir){
    FILE *archivo;                                              //Declaramos una varable de tipo archivo
    if(archivo_a_abrir!=NULL){                                   //Si el archivo introducido en la funcion no es vacio
       archivo=fopen(archivo_a_abrir, "r");                       //Cambiamos la variable(de tipo archivo) al archivo que nos dan en modo lectura "r"
         if(archivo==NULL){                                     //Si fopen ha tenido problemas para abrir el archivo, devuelve un puntero NULL,
            perror("Hubo un error en la apertura del archivo"); //si esto pasa, salta el error de apertura de archivo, usando perror
               exit(EXIT_FAILURE);                              //Mediante exit nos salimos del programa y (EXIT_FAILURE)le indica al programa que ha habido un error de ejecucion
         }
    }
   else{               //En caso de que no se proporcione ningun archivo
    archivo=stdin;     //Se hara lo que haria en caso de de proporcionar un archivo, 
    }                   //pero en vez de desde ahi(dentro de un archivo), lo hara desde la entrada estandar
    const int tamBuffer = 4096;
    char buffer[tamBuffer];
   while(fgets(buffer, tamBuffer, archivo)!=NULL){ //Leemos el archivo o la entrada estandar linea a linea(lo que hace fgets), y la almacena en buffer
                                                   //tamBuffer se usa para asegurar que fgets no pase los limites que tiene el buffer
           fputs(buffer, stdout);//Escribimos la linea leida(almacenada en el buffer) en la salida estandar
   }
if(archivo_a_abrir!=NULL){//En el caso de que se pasara un archivo(el archivo se habria tenido que abrir)
   fclose(archivo);      //entonces, cerramos esl archivo, mediante fclose(archivo)
}
}

int main(int argc, char *argv[]){
    if(argc>2){ //en caso de haberle proporcionado varios archivos
        for(int i=1; i<argc;i++){
            my_cat(argv[i]);//Llamamos a la funcion my_cat con cada uno de los archivos
        }
    }
    else if(argc==2){
        my_cat(argv[1]);//Si solo nos pasan un archivo abrimos ese unico archivo
    }
    else{    //Si no pasan ningun fichero llamamos a la funcion my_cat con null para que copie de la entrada estandar a la salida estandar
       my_cat(NULL);
    }
    return 0;
}