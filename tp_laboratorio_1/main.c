#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "funcionesUTN.h"


int main()
{
    system ("color 8F" ); // Cambia el color de la consola y los textos.
    SetConsoleTitle("TP1 Calculadora"); // Cambia titulo de la consola.

    int opcion;
    float operando1 = 0.0; //Primer numero a operar.
    float operando2 = 0.0; // Segundo numero a operar.
    float resultado = 0.0f;  // Resiltado de las operaciones a realizar.
    int continuar = 1;
    int intentos = 0;


    do{
        system("CLS");
//Se muestra menu con las opciones de la calculadora y se grabaran los operando elegidos.

    printf("\t\t\t\t\t\t  Alumno: Gomez Soto Santiago\n\n\n\n");

    printf("Seleccione la opcion deseada: \n\n");
    printf("1. Ingresar primer operando (A=%f) \n",operando1);
    printf("2. Ingresar segundo operando (B=%f) \n",operando2);
    printf("3. Suma\n");
    printf("4. Resta\n");
    printf("5. Multiplicacion\n");
    printf("6. Division\n");
    printf("7. Factoreo\n");
    printf("8. Calcular todas las operaciones \n");
    printf("9. Salir \n");

    scanf("%d", &opcion);  // Toma la opcion elegida.

    switch (opcion){

            case 1:
                printf("Ingrese el primer operando\n");  // Se toma el primer operando.
                fflush(stdin);
                scanf("%f", &operando1);
                break;
            case 2:
                printf("Ingrese el segundo operando\n"); // Se toma el segundo operando.
                fflush(stdin);
                scanf("%f", &operando2);
                break;
            case 3:
                resultado = sumar(operando1, operando2);        // Sumo ambos operandos.
                printf("El resultado de la suma es: %.2f ", resultado);
                continuar = deseaContinuar();
                system("cls");
                break;
            case 4:
                resultado = restar(operando1, operando2);       // Resta ambos operandos.
                printf("El resultado de la resta es: %.2f", resultado);
                system("pause");
                system("cls");
                break;
            case 5:
                resultado = multiplicar(operando1, operando2);      //Multiplica ambos operandos.
                printf("El resultado de la multiplicacion es: %.2f ", resultado);
                system("pause");
                system("cls");
                break;
            case 6:
                if(operando2!=0){             // Compueba que no se divida por CERO y se dividen ambos operandos.
                    resultado = dividir(operando1, operando2);
                    printf("El resultado de la division es: %.2f ", resultado);
                }else{
                    printf("No se puede dividir por 0. Ingrese un operador B distinto a 0 \n");
                }

                system("pause");
                system("cls");
                break;
            case 7:

                printf("El factorial es: %d \n", factorial(operando1)); // Factoreo el primer operando.
                system("pause");
                system("cls");

                break;
            case 8:
                resultado = sumar(operando1, operando2);      // Realizo todas las operaciones anteriores en un mismo paso.
                printf("El resultado de la suma es: %.2f \n", resultado);

                resultado = restar(operando1, operando2);
                printf("El resultado de la resta es: %.2f \n", resultado);

                resultado = multiplicar(operando1, operando2);
                printf("El resultado de la multiplicacion es: %.2f \n", resultado);

                if(operando2!=0){
                    resultado = dividir(operando1, operando2);
                    printf("El resultado de la division es: %.2f \n", resultado);
                }else{
                    printf("No se puede dividir por 0. Ingrese un operador B distinto a 0 \n");
                }


                printf("El factorial es: %d \n", factorial(operando1) );

                system("pause");
                system ("CLS");
                break;

            case 9:         //Termina el programa.
                continuar = 0;
                break;

            default:        // Si se eligen mas de 4 opciones incorrectas se termina el programa.
                intentos++;
                if (intentos >= 4){
                    continuar = 0;
                    break;
                }
                printf("Error! Opcion invalida\n %d",intentos);

               continuar = deseaContinuar();  // Pregunta si desea continuar.


        }


    system("cls");

    }while(continuar);
}
