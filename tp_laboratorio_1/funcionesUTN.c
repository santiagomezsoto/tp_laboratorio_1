
#include <stdio.h>
#include <stdlib.h>

int deseaContinuar()
{
    char respuesta;
    int contador = 0;


    do{
        if(contador==0)   //Pregunta si desea continuar
        {
            printf("\n\n¿Desea continuar? (s/n)");
        }
        else
        {
            printf("ERROR! Ingrese un caracter valido. ¿Desea continuar? (s/n) ");
        }
        fflush(stdin);
        scanf("%c", &respuesta);
        respuesta=tolower(respuesta);
        contador++;
    }while( respuesta!='s' && respuesta!='n');

    if (respuesta == 's')
    {
        return 1;
    }
    else if (respuesta == 'n')
    {
        return 0;
    }

    return 0;
}


float sumar(float operando1, float operando2)  //Suma 2 valores
{
    return(operando1+operando2);
}

float restar(float operando1, float operando2) //Resta 2 valores.
{
    return(operando1-operando2);
}

float multiplicar(float operando1, float operando2) // Multiplica 2 valores.
{
    return (operando1*operando2);
}

float dividir(float operando1, float operando2)  //Divide 2 valores.
{
    return (operando1/operando2);
}

int factorial(int numero)       // Realiza el factorial de un valor.
{
    int multiplicador = numero - 1;
    int resultado = numero;

    while(multiplicador>=1){
        resultado = resultado * multiplicador;
        multiplicador--;
    }

    return resultado;
}
