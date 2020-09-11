
#include "funciones.h"


int sumar(int num1,int num2){
    int suma;
    suma = num1 + num2;

    return suma;
}
int restar(int num1, int num2){
    int resta;
    resta = num1 - num2;

    return resta;
}
float dividir(float num1,float num2){
    float division;
    division = num1 / num2;

    return division;
}
int multiplicar(int num1, int num2){
    int multiplicacion;
    multiplicacion = num1 * num2;

    return multiplicacion;
}
int factorial (int num){

    if(num >= 13){
        return -1;
    }else if(num <= 1){
        return 1;
    }else{
        return num * factorial(num - 1);
    }
}
