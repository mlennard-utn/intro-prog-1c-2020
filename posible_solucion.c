

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int obtenerNumeroAleatorio(int);
int obtenerLongitudPassword();
void generarVocalesConsonantes(char*, char*, int);
void generarValores(char*, int, int);

int TAMANO_MINIMO_PASSWORD = 8;
int TAMANO_MAXIMO_PASSWORD = 64;

int CANTIDAD_PARTE_NUMERICA = 2;
int CANTIDAD_PARTE_CARACTERES_ESPECIALES = 1;

int CANTIDAD_VOCALES = 5;
int CANTIDAD_CONSONANTES = 21;
int CANTIDAD_NUMEROS = 10;
int CANTIDAD_CARACTERES_ESPECIALES = 9;

int main()
{
    // Definicion de vectores con valores 
    char consonantes[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    char vocales[5] = {'a','e','i','o','u'};
    char numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    char simbolos[9]={'!','$','%','&','/','(',')','=','_'};
    // Definicion de variable longitud de la password
    int longitud_password;
    
    // Semilla para uso de rand()
    srand(time(0));
    
    // Tomar datos del usuario para longitud de la password
    longitud_password = obtenerLongitudPassword();
    
    // Generar parte de vocales y consonantes intercaladas
    int longitud_vocales_consonantes = longitud_password - CANTIDAD_PARTE_NUMERICA - CANTIDAD_PARTE_CARACTERES_ESPECIALES;
    generarVocalesConsonantes(consonantes, vocales, longitud_vocales_consonantes);
    
    // Generar parte numerica
    generarValores(numeros, CANTIDAD_PARTE_NUMERICA, CANTIDAD_NUMEROS);
    
    // Generar parte caracteres especiales 
    generarValores(simbolos, CANTIDAD_PARTE_CARACTERES_ESPECIALES, CANTIDAD_CARACTERES_ESPECIALES);
    
}
/*
Funcion encargada de solicitar al usuario la longitud de la contraseña a generar.
Valida valores fuera de rango.
Retorna un entero con la longitud
*/
int obtenerLongitudPassword(){
    int longitud;
    printf("Ingrese longitud de la password (valor númerico entre %d y %d): \n", TAMANO_MINIMO_PASSWORD, TAMANO_MAXIMO_PASSWORD);
    scanf("%d", &longitud);
    while(longitud < TAMANO_MINIMO_PASSWORD || longitud > TAMANO_MAXIMO_PASSWORD){
        printf("Valor fuera del rango esperado. \n");
        printf("Ingrese longitud de la password (valor númerico entre %d y %d): \n", TAMANO_MINIMO_PASSWORD, TAMANO_MAXIMO_PASSWORD);
        scanf("%d", &longitud);
    }
    
    return longitud;
}

/*
Funcion encargada de imprimir intercalada una #cantidad de valores aleatorios basados
en los caracteres que poseen los vectores #consonantes y #vocales.
Parametros:
- char*: array de caracteres
- char*: array de caracteres
- int: cantidad de valores a imprimir
*/
void generarVocalesConsonantes(char* consonantes, char* vocales, int cantidad){
    for (int i = 0; i < cantidad; i++) {
        if(i % 2 == 0){ //Para las posiciones pares genero consonantes
            printf("%c", consonantes[obtenerNumeroAleatorio(CANTIDAD_CONSONANTES)]);
        } else {
            printf("%c", vocales[obtenerNumeroAleatorio(CANTIDAD_VOCALES)]);
        }
    }
}

/*
Funcion encargada de imprimir una #cantidad_a_generar de valores aleatorios basados
en los caracteres que posee el vector #valores_posibles
Parametros:
- char*: array de caracteres
- int: cantidad de valores a imprimir
- int: cantidad de valores posibles que posee el array
*/
void generarValores(char* valores_posibles, int cantidad_a_generar, int cantidad_valores_posibles){
    for (int i = 0; i < cantidad_a_generar; i++) {
        printf("%c", valores_posibles[obtenerNumeroAleatorio(cantidad_valores_posibles)]);
    }
}

int obtenerNumeroAleatorio(int maximo){
    return rand() % maximo;
}
