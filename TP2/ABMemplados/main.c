#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define TAM 5
#define DESC 0
#define ASC 1

int main()
{
    char seguir = 's';
    char confirmacion;
    int rta;
    int proxId = 1;
    int opcion;
    int flagAlta = 0;
    Employee lista[TAM];

    if(!initEmployees(lista,TAM)){
        printf("Inicialisacion exitoza.\n");
    }else{
        printf("Fallo al inicializar.");
    }

    do{
        switch(menu()){
        case 1:
            if(!addEmployees(lista, TAM, proxId)){
                proxId++;
                printf("Alta exitosa.\n\n");
            }else{
                printf("No se pudo realizar el alta.\n\n");
            }
            flagAlta = 1;
            break;
        case 2:
            if(flagAlta == 1){
                rta = modifyEmployee(lista, TAM);

                if(!rta){
                    printf("Ha realizado la modificacion con exito.\n\n");
                }else if(rta == 2){
                    printf("Modificacion cancelada por el usuario. \n\n");
                }else{
                    printf("Hubo un problema al intentar realizar la modificacion. \n\n");
                }
            }else{
                printf("Lista vacia,necesita dar de alta a algun empleado\n");
            }
            break;
        case 3:
            if(flagAlta == 1){
                rta = removeEmployee(lista, TAM);

                if(!rta){
                    printf("Ha realizado la baja con exito.\n\n");
                }else if(rta == 2){
                    printf("Baja cancelada por el usuario. \n\n");
                }else{
                    printf("Hubo un problema al intentar realizar la baja. \n\n");
                }
            }else{
                printf("Lista vacia,necesita dar de alta a algun empleado\n");
            }
            break;
        case 4:
            if(flagAlta == 1){
                system("cls");

                printf("*** INFORMES ***\n\n");
                printf("1) Lista de empleados\n");
                printf("2) Informe de salario\n");
                printf("Ingrese una opcion: ");
                fflush(stdin);
                scanf("%d", &opcion);
                if(opcion == 1){
                    system("cls");

                    printf("*** LISTA ***\n\n");
                    printf("1) Orden ascendente\n");
                    printf("2) Orden descendente\n");
                    printf("Ingrese una opcion: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                    if(opcion == 1 && !sortEmployees(lista, TAM, ASC)){
                        printEmployees(lista, TAM);
                    }else if(opcion == 2 && !sortEmployees(lista, TAM, DESC)){
                        printEmployees(lista, TAM);
                    }else{
                        printf("Opcion invalida.\n");
                        printf("Hubo un problema al mostrar la lista de empleados. \n\n");
                    }

                }else if(opcion == 2){
                    informeSalarios(lista, TAM);
                }else{
                    printf("Opcion invalida.\n");
                    printf("Hubo un problema al mostrar los informes. \n\n");
                }
            }else{
                printf("Lista vacia,necesita dar de alta a algun empleado\n");
            }
            break;
        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirmacion);
            confirmacion = tolower(confirmacion);
            if(confirmacion == 's'){
                seguir = 'n';
            }
            break;
        default:
            printf("Opcion invalida.\n");
            break;
    }
        system("pause");
    }while( seguir == 's');

    return 0;
}
