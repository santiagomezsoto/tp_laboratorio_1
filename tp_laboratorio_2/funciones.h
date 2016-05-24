#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define MAX_PERSONAS 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;
/** \brief Funcion  encargada de inicializar los valores del array
 *
 * \param Puntero al array de personas
 * \return void
 *
 */

void inicializarArray(EPersona* lista){
    int i;
    for(i = 0;i < MAX_PERSONAS; i++){
        lista[i].dni = 0;
        lista[i].estado = 0;
        lista[i].edad = 0;
        lista[i].nombre[50] = "";
    }
}

/** \brief Funcion encargada de buscar un dni
 *
 * \param Puntero al array de personas
 * \param DNI
 * \return Indice en el caso de encontrarlo, -1 en caso de no encontrar
 *
 */

int buscarDNI(EPersona* lista,int dni){
    int i;

    for(i=0;i < MAX_PERSONAS;i++){
        if(lista[i].dni == dni){
            return i;
        }
    }
    return -1;
}
/** \brief Obtiene el primer indice disponible
 *
 * \param Puntero al array de personas
 * \param
 * \return Indice disponible
 *
 */

int obtenerIndiceDisponible(EPersona* lista){
    int i;
    for(i = 0;i < MAX_PERSONAS;i++){
        // Chequeamos que el estado sea 0
        if(!lista[i].estado){
            return i;
        }
    }
    return -1;
}
/** \brief Agrega una persona al array
 *
 * \param Puntero al array de personas
 * \param
 * \return void
 *
 */

void agregarPersona(EPersona* lista){
    int indice = obtenerIndiceDisponible(lista);
    int dni = 0;
    int dni_ingreso = 0;
    // Si el indice es -1 significa que no hay lugar en el array
    if(indice == -1){
        printf("No hay mas espacio disponible\n");
        return;
    }

    printf("Ingrese un nombre:");
    scanf("%s",&lista[indice].nombre);

    printf("Ingrese edad:");
    scanf("%d",&lista[indice].edad);
    // Verificamos que no haya ingresos con DNI Duplicados
    do {
        printf("Ingrese DNI:");
        scanf("%d",&dni_ingreso);
        dni = buscarDNI(lista,dni_ingreso);

    }while(dni != -1);

    lista[indice].dni = dni_ingreso;




    lista[indice].estado = 1;
}
/** \brief Elimina una persona en base a su DNI
 *
 * \param Puntero al array de personas
 * \param
 * \return void
 *
 */

void eliminarPersona(EPersona* lista){
    int dni_ingreso,i;

    printf("Ingrese DNI de la persona a eliminar:");
    scanf("%d",&dni_ingreso);
    i = buscarDNI(lista,dni_ingreso);



    lista[i].estado = 0;
    lista[i].dni = 0;
    lista[i].edad = 0;
    lista[i].nombre[50] = "";

}
/** \brief Imprime una lista ordenada de personas alfabeticamente
 *
 * \param Puntero al array de personas
 * \param
 * \return void
 *
 */

void imprimirListaOrdenada(EPersona* lista){
    int i,j;
    EPersona aux;

    for(i=0; i < MAX_PERSONAS - 1; i++){
        for(j = i + 1; j < MAX_PERSONAS; j++){
            if(strcmp(lista[i].nombre,lista[j].nombre) > 0){
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }

    for(i = 0; i < MAX_PERSONAS; i++){
        if(lista[i].estado){
            printf("Nombre: %s\nEdad: %d\nDNI: %d \n",lista[i].nombre,lista[i].edad,lista[i].dni);
        }
    }
}
/** \brief Imprime un grafico de barras de las edades
 *
 * \param Puntero al array de personas
 * \param
 * \return void
 *
 */
void imprimirGraficoEdades(EPersona* lista){
    int i, hasta18 = 0, de19a35 = 0, mayorDe35 = 0, flag=0, mayor;

    //
    for(i = 0; i < MAX_PERSONAS; i++){
        if(lista[i].estado){
            if(lista[i].edad < 18){
                hasta18++;
            }else if( (lista[i].edad > 18 && lista[i].edad < 35 ) ){
                de19a35++;
            }else if( lista[i].edad > 35){
                mayorDe35++;
            }
        }
    }
    //




    if(hasta18 >= de19a35 && hasta18 >= mayorDe35){
        mayor = hasta18;
    }else{
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else{
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18){
            printf("*");
        }
        if(i<= de19a35){
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d", hasta18, de19a35, mayorDe35);
}
#endif // FUNCIONES_H_INCLUDED
