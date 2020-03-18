# intro-prog-1c-2020

Google Chrome nos contrata para armar un programa que genera contraseñas aleatorias.
    
Nos solicitaron ciertas restricciones a la hora de generar una contraseña:
    
- Primero: que el usuario decida la longitud de esa contraseña (la longitud tiene que ser entre 8 y 64)
- Segundo: Que se componga de una mezcla de caracteres alfanumericos (letras y numeros) y de caracteres especiales.
- Tercero: Que los caracteres no numericos itercalen consonantes y vocales
- Cuarto: Que los ultimos 3 digitos contengan 2 numeros y el ultimo sea un caracter especial.
- Quinto: Los caracteres especiales validos son los siguientes: !·$%&/()=_
    
Por ejemplo: 
El usuario ingresa longitud 8, el resultado puede ser: mimol12$
El usuario ingresa longitud 12, el resultado podrá ser: jiloqapan00%
    
Como se trata de generar valores aleatorias, se debe usar la funcion rand() que es parte de #include <stdlib.h>
Esta funcion devuelve un valor entero aleatorio. Si combinamos el resultado de esa funcion con la operacion modulo (%) podremos
generar un numero aleatorio acotado a nuestra necesidad.
    
A continuacion un programita que tiene una funcion que devuelve un valor numerico a partir lo que escriba el usuario 
como maximo definido por él


#include <stdio.h>
#include <stdlib.h>
int valor_aleatorio(int);
int main()
{
        
    srand(time(0)); 
    int maximo;
    scanf("%d", &maximo);
    printf("Aleatorio: %d " , valor_aleatorio(maximo));
    
}
int valor_aleatorio(int maximo){
    return rand()%maximo + 1;
} (edited) 


