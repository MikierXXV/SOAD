#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h> 



int main () 

{
    
    int i,j,temp, ascii,a,c;         /*  Define las variables  i,j,temp */
    char string[50];
    char ban,letra,l;  
    char m[20],s[50];            /*  Define las variables  ban */
    
        ban = 's';           /*  Asigna a ban el caracter s  */
        while (ban != 'n')  /* Mientras no haya una n en ban se ejecuta lo siguiente:  */
        {    
/******************************Capturando los datos*********************************/       
         printf("Ingresa un caracter: ");     
         scanf("%c",&letra);  getchar();    
         printf("\n");
         printf("El caracter %c",letra);
         ascii = letra;
         printf(" tiene  codigo ascii: %d\n\n",ascii);  /* de manera natural c da el codigo ascii
                                                                solo basta imprimirlo como digito*/

         printf("Ingresa el numero ascii: ");     
         scanf("%d",&a);  getchar();    
         printf("\n");
         printf("El codigo ascii  %d",a);
         l = toascii(a);                            /*para el caso contrario hay que usar la 
                                                     funcion toascii, es decir para convertir
                                                     un entero a su respectivo caracter ascii*/
         printf(" tiene el caracter: %c\n\n",l); 
         

         
/************************************ Solicita otro caso? ********************************************/          
             printf("\n\n");
             printf("********  Otro caso  s/n: ");     /* Solicita si se quiere  otro caso */
             scanf("%c",&ban);  getchar();            /* Se lee un caracter del teclado, y sigue despues de un pinchazo */
             printf("\n");       /* Si no se escribe n, entonces  sigue el while */
        };  /* Termina el while si ban = n */
}