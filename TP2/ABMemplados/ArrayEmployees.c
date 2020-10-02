#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int initEmployees(Employee empleados[], int tam){
    int error = 1;
    if(empleados != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            empleados[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int menu(){
    int opcion;

    system("cls");

    printf("*** ABM EMPLEADOS ***\n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICAR\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. SALIR\n\n");
    printf("Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int addEmployees(Employee empleados[],int tam,int id){
    int error = 1;
    int indice;
    int validacion;
    Employee nuevoEmpleado;

    if(empleados != NULL && tam > 0){
        system("cls");

        printf("*** ALTA DE EMPLEADOS ***\n\n");
        indice = buscarLibre(empleados, tam);
        if(indice == -1){
            printf("Lista completa\n");
        }else{
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.id = id;
            do{
                printf("Ingrese apellido: ");
                fflush(stdin);
                formatearCadena(gets(nuevoEmpleado.lastName));
                validacion = validacionCadena(nuevoEmpleado.lastName);
            }while(validacion == 1);
            do{
                printf("Ingrese nombre: ");
                fflush(stdin);
                formatearCadena(gets(nuevoEmpleado.name));
                validacion = validacionCadena(nuevoEmpleado.name);
            }while(validacion == 1);
            printf("Ingrese salario: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.salary);
            printf("Ingrese sector: ");
            fflush(stdin);
            scanf("%d", &nuevoEmpleado.sector);

            empleados[indice] = nuevoEmpleado;
            error = 0;
        }
    }
    return error;
}

int buscarLibre(Employee empleados[], int tam){
    int indice = -1;
    for(int i = 0; i < tam; i++){
        if(empleados[i].isEmpty){
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee empleados[],int tam,int id){
    int indice = -1;
    for(int i = 0; i < tam; i++){
        if(empleados[i].id == id && !empleados[i].isEmpty){
            indice = i;
            break;
        }
    }
    return indice;
}

void printEmployee(Employee empleado){
    printf("  %04d %30.*s %30.*s     %9.2f      %3d \n", empleado.id, 30,empleado.lastName, 30,empleado.name, empleado.salary, empleado.sector);
    printf("------------------------------------------------------------------------------------------------\n");
}

int printEmployees(Employee empleados[], int tam){
    int flag = 0;
    int error = 1;

    if(empleados != NULL && tam > 0){

        printf("                                      *** EMPLEADOS ***  \n\n");
        printf("   ID                        APELLIDO                         NOMBRE       SALARIO     SECTOR\n");
        printf("------------------------------------------------------------------------------------------------\n\n");
        for(int i = 0; i < tam; i++){
            if(!empleados[i].isEmpty){
                printEmployee(empleados[i]);
                flag = 1;
            }
        }
        if(!flag){
            printf("        No hay empleados en la lista\n");
        }
        error = 0;
    }
    return error;
}

int removeEmployee(Employee empleados[],int tam){
    int indice;
    int id;
    int error = 1;
    char confirmacion;

    if(empleados != NULL && tam > 0){
        system("cls");

        printf("*** BAJA DE EMPLEADOS ***\n\n");
        printEmployees(empleados, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = findEmployeeById(empleados, tam, id);

        if(indice == -1){
            printf("No existe ningun empleado con ese id\n");
        }else{
            system("cls");

            printf("*** BAJA DE EMPLEADOS ***\n\n");
            printEmployee(empleados[indice]);
            printf("Confirma la baja(s/n)? ");
            fflush(stdin);
            scanf("%c", &confirmacion);

            if(confirmacion == 's'){
                empleados[indice].isEmpty = 1;
                error = 0;
            }else{
                error = 2;
            }
        }
    }

    return error;
}

int sortEmployees(Employee empleados[], int tam, int orden){
    int error = 1;
    Employee auxEmpleado;
    if(empleados != NULL && tam > 0 && (orden >= 0 || orden <= 1)){
        for(int i = 0; i < tam - 1; i++){
            for(int j = i + 1; j < tam; j++){
                if(orden == 1 && (empleados[i].sector > empleados[j].sector || (empleados[i].sector == empleados[j].sector && stricmp(empleados[i].lastName,empleados[j].lastName) > 0))){
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }else if(!orden && (empleados[i].sector < empleados[j].sector || (empleados[i].sector == empleados[j].sector && stricmp(empleados[i].lastName,empleados[j].lastName) < 0))){
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        error = 0;
    }

    return error;
}

int modifyEmployee(Employee empleados[],int tam){
    int indice;
    int validacion;
    int id;
    int error = 1;
    int flagSalir = 0;
    int flagDef = 0;
    char confirmacion;
    int opcion;
    Employee auxEmpleado;

    if(empleados != NULL && tam > 0){
        system("cls");

        printf("*** MODIFICAR EMPLEADOS ***\n\n");
        printEmployees(empleados, tam);
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = findEmployeeById(empleados, tam, id);
        auxEmpleado = empleados[indice];

        if(indice == -1){
            printf("No existe ningun empleado con ese id\n");
        }else{
            system("cls");

            printf("*** MODIFICAR EMPLEADOS ***\n\n");
            printEmployee(empleados[indice]);
            printf("1) MODIFICAR APELLIDO.\n");
            printf("2) MODIFICAR NOMBRE.\n");
            printf("3) MODIFICAR SALARIO.\n");
            printf("4) MODIFICAR SECTOR.\n");
            printf("5) MENU ANTERIOR.\n");
            printf("Seleccione un opcion: ");
            fflush(stdin);
            scanf("%d", &opcion);

            switch(opcion){
            case 1:
            do{
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                formatearCadena(gets(auxEmpleado.lastName));
                validacion = validacionCadena(auxEmpleado.lastName);
            }while(validacion == 1);
                break;
            case 2:
                do{
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                formatearCadena(gets(auxEmpleado.name));
                validacion = validacionCadena(auxEmpleado.name);
            }while(validacion == 1);
                break;
            case 3:
                printf("Ingrese nuevo salario: ");
                scanf("%f", &auxEmpleado.salary);
                break;
            case 4:
                printf("Ingrese nuevo sector: ");
                scanf("%d", &auxEmpleado.sector);
                break;
            case 5:
                flagSalir = 1;
                error = 2;
                break;
            default:
                flagDef = 1;
                printf("Opcion no valida\n");
                break;
            }
            if(!flagSalir && !flagDef){
                printf("Confirma la modificacion(s/n)? ");
                fflush(stdin);
                scanf("%c", &confirmacion);
                if(confirmacion == 's'){
                    empleados[indice] = auxEmpleado;
                    error = 0;
                }else{
                    error = 2;
                }
            }
        }
    }
    return error;
}

void informeSalarios(Employee empleados[],int tam){
    float promedio;
    float acum = 0;
    int contTotal = 0;
    int contMayorPromedio = 0;

    if(empleados != NULL && tam > 0){
        for(int i = 0; i < tam; i++){
            if(!empleados[i].isEmpty){
                acum = acum + empleados[i].salary;
                contTotal ++;
            }
        }
        promedio = acum/contTotal;
        for(int i = 0; i < tam; i++){
            if(!empleados[i].isEmpty && empleados[i].salary > promedio){
                contMayorPromedio ++;
            }
        }
        system("cls");

        printf("*** SALARIOS ***\n\n");
        printf("-Total de los salarios: $%0.2f \n", acum);
        printf("-Promedio de los salarios: $%0.2f \n", promedio);
        printf("-Empleados por encima del salario promedio: %d\n",contMayorPromedio);
    }
}

void formatearCadena(char cadena[]){
    strlwr(cadena);
    int i = 0;
    cadena[0] = toupper(cadena[0]);
    while(cadena[i] != '\0'){
        if(cadena[i] == ' ' || cadena[i] == 39){
            cadena[i + 1] = toupper(cadena[i + 1]);
        }
        i++;
    }
}

int validacionCadena(char cadena[]){
    int flag = 0;
    int error = 0;
    int tamanio;

    tamanio = strlen(cadena);
    for(int i = 0; i < tamanio; i++){
        if(!((cadena[i] >= 65 && cadena[i] <= 90) || (cadena[i] >= 97 && cadena[i] <= 122) || cadena[i] == ' ' || cadena[i] == 39)){
            flag = 1;
            error = 1;
        }
    }
    if(flag == 1){
        printf("Ingrese cadena valida(solo letras o espacios).\n");
    }
    return error;
}
