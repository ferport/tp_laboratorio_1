#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main()
{
    char salir = 'n';
    int num1;
    int num2;
    int rtaSuma;
    int rtaResta;
    int rtaMult;
    int opcion;
    int rtaFactA;
    int rtaFactB;
    int flagA = 0;
    int flagB = 0;
    int flagOperaciones = 0;
    int flagMostrar = 0;
    float rtaDiv;

    do{

        system("cls");

        printf("-----Bienvenido a la calculadora!----- \n\n");
        if(flagA == 0){
            printf("1. Ingresar 1er operando(A=x) \n");
        }else{
            printf("1. Ingresar 1er operando(A=%d) \n",num1);
        }
        if(flagB == 0){
            printf("2. Ingresar 2do operando(B=y) \n");
        }else{
            printf("2. Ingresar 2do operando(B=%d) \n",num2);
        }
        printf("3. Calcular las operanciones \n");
        printf("    a)Calcular la suma(A+B) \n");
        printf("    b)Calcular la resta(A-B) \n");
        printf("    c)Calcular la division(A/B) \n");
        printf("    d)Calcular la multiplicacion(A*B) \n");
        printf("    e)Calcular el factorial(A!) \n");
        printf("4. Informar los resultados \n");
        if(flagMostrar == 0){
            printf("    a)El resultado de A+B es: \n");
            printf("    b)El resultado de A-B es: \n");
            printf("    c)El resultado de A/B es: \n");
            printf("    d)El resultado de A*B es: \n");
            printf("    e)El factorial A es: y el factorial de B es: \n");
        }else{
            printf("    a)El resultado de A+B es: %d \n", rtaSuma);
            printf("    b)El resultado de A-B es: %d \n", rtaResta);
            if(num2 != 0){
                printf("    c)El resultado de A/B es: %.2f \n", rtaDiv);
            }else{
                printf("    c)No es posible dividir por cero \n");
            }
            printf("    d)El resultado de A*B es: %d \n", rtaMult);
            printf("    e)El factorial A es: %d y el factorial de B es: %d \n",rtaFactA,rtaFactB);
        }
        printf("5. Salir del programa \n\n");
        printf("Ingrese la opcion que desee: ");
        fflush(stdin);
        scanf("%d",&opcion);

    switch(opcion){
    case 1:
        printf("Ingrese el primer operando: ");
        scanf("%d", &num1);
        flagA = 1;
        break;
    case 2:
        if(flagA == 0){
            printf("Primero debe ingresar el primer operador \n");
            system("pause");
        }else{
            printf("Ingrese el segundo operando: ");
            fflush(stdin);
            scanf("%d", &num2);
            flagB = 2;
        }
        break;
    case 3:
        if(flagA == 0){
            printf("Primero debe ingresar el primer operador \n");
            system("pause");
        }else if(flagB == 0){
            printf("Primero debe ingresar el segundo operador \n");
            system("pause");
        }else{
            rtaSuma = sumar(num1,num2);
            rtaResta = restar(num1,num2);
            rtaDiv = dividir(num1,num2);
            rtaMult = multiplicar(num1,num2);
            rtaFactA = factorial(num1);
            rtaFactB = factorial(num2);
            printf("Las operaciones ya fueron realizadas. \n");
            system("pause");
            flagOperaciones = 1;
        }
        break;
    case 4:
        if(flagOperaciones == 0){
            printf("Primero debe realizar las operaciones \n");
            system("pause");
        }else{
            flagMostrar = 1;
        }
        break;
    case 5:
        printf("Esta seguro que desea salir? ");
        fflush(stdin);
        scanf("%c",&salir);
        break;
    default:
        printf("Error! Ingrese una opcion valida: \n");
        system("pause");
        break;

    }

    }while(salir == 'n');
    return 0;
}
