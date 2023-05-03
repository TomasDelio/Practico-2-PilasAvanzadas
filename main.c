#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    Pila dada, aux, aux2, aux3;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&aux2);
    inicpila(&aux3);

    int num, i,prome,total;
    char yes;
    do{
    i=0;
    prome=0;
    total=0;


    printf("Bienvenido a la guia de 'Pilas Avanzadas', por favor eleji un ejercicio: ");
    scanf("%i", &num);
    switch(num)
    {
    case 1:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }while(yes=='s'|| yes=='S');

        while(!pilavacia(&dada))
        {
            i=i+tope(&dada);
            apilar(&aux, desapilar(&dada));
        }
        printf("La suma de los elementos de la Pila DADA es: %i", i);

        break;

    case 2:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        while(!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
            i++;
        }
        printf("La cantidad de elementos de la pila DADA es: %i", i);
        break;

    case 3:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        while(!pilavacia(&dada))
        {
            i=i+tope(&dada);
            prome++;
            apilar(&aux, desapilar(&dada));
        }
        total=i/prome;
        printf("El promedio total es: %i \n", total);
        break;
    case 4:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        if(!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
        }

        while(!pilavacia(&dada))
        {
            if(tope(&dada)<tope(&aux))
            {
                apilar(&aux2, desapilar(&aux));
                apilar(&aux, desapilar(&dada));
            }
            else
            {
                apilar(&aux2, desapilar(&dada));
            }
        }
        while(!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2));
        }

        printf("el menor es %i", tope(&aux));

        break;


    case 5:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("Ingrese el numero que desea insertar: ");
        scanf("%i", &i);

        apilar(&aux, i);

        printf("PILA DADA ORIGINAL");
        mostrar(&dada);

        while(!pilavacia(&dada) && tope(&dada)>tope(&aux))
        {
            apilar(&aux2, desapilar(&dada));
        }

        apilar(&dada, desapilar(&aux));

        while(!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2));
        }
        printf("PILA DADA INSERTADA");
        mostrar(&dada);
        break;

    case 6:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("PILA DADA\n");
        mostrar(&dada);

        while (!pilavacia(&dada))
        {
            apilar(&aux2, desapilar(&dada));

            while(!pilavacia(&dada))
            {
                if(tope(&aux2)>tope(&dada))
                {
                    apilar(&aux, desapilar(&aux2));
                    apilar(&aux2, desapilar(&dada));
                }
                else
                {
                    apilar(&aux, desapilar(&dada));
                }
            }

            while(!pilavacia(&aux))
            {
                apilar(&dada, desapilar(&aux));
            }

            apilar(&aux3, desapilar(&aux2));
        }
        printf("Pila DADA ordenada por seleccion\n");
        mostrar(&aux3);

        break;
    case 7:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("Ingrese el numero que desea encontrar: ");
        scanf("%i", &i);
        apilar(&aux, i);

        while(!pilavacia(&dada))
        {
            if(tope(&dada)==tope(&aux))
            {
                total=1;
                apilar(&aux2, desapilar(&dada));
            }
            else
            {
                apilar(&aux2, desapilar(&dada));
            }
        }

        if(total==1)
        {
            printf("\nEl elemento %i se encuentra en la pila\n", i);
        }
        else
        {
            printf("\nEl elemento %i no encuentra en la pila\n", i);
        }
        break;

    case 8:
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("Ingrese el numero que desea eliminar: ");
        scanf("%i", &i);

        while(!pilavacia(&dada))
        {
            while (!pilavacia(&dada)&&tope(&dada)!=i)
            {
                apilar(&aux, desapilar(&dada));
            }

            if(!pilavacia(&dada))
            {
                apilar(&aux2, desapilar(&dada));
            }

            while (!pilavacia(&aux))
            {
                apilar(&dada, desapilar(&aux));
            }
            apilar(&aux3, desapilar(&dada));
        }

        while(!pilavacia(&aux3))
        {
            apilar(&dada, desapilar(&aux3));
        }

        printf("\nPILA DADA");
        mostrar(&dada);
        break;
    case 9:

        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        while(!pilavacia(&dada))
        {
            apilar(&aux,desapilar(&dada));
            total++;
        }
        prome=total/2;
        for(i=0; i<prome; i++)
        {
            apilar(&dada, desapilar(&aux));
        }

        if(tope(&dada)!=tope(&aux))
        {
            apilar(&aux2, desapilar(&aux));
        }

        while(!pilavacia(&dada) && !pilavacia(&aux) && tope(&dada)==tope(&aux))
        {
            apilar(&aux2, desapilar(&aux));
            apilar(&aux2, desapilar(&dada));

        }
        if(pilavacia(&dada) && pilavacia(&aux))
        {
            printf("La pila ES CAPICUA");
        }
        else
        {
            printf("La pila NO ES CAPICUA");
        }


        break;

    case 10:

        apilar (&dada,1);
        apilar (&dada,2);
        apilar (&dada,3);

        apilar (&aux,2);
        apilar (&aux,3);
        apilar (&aux,5);
        apilar (&aux,7);
        printf("PILA CONJUNTO A:");
        mostrar(&dada);
        printf("PILA CONJUNTO B:");
        mostrar(&aux);

        while(!pilavacia(&dada))
        {
            apilar(&aux2, desapilar(&dada));
        }
        while(!pilavacia(&aux))
        {
            if(tope(&aux2)==tope(&aux))
            {
                apilar(&aux3, desapilar(&aux));
            }
            else
            {
                apilar(&aux2, desapilar(&aux));
            }
        }
        apilar(&aux3, desapilar(&aux2));
        apilar(&aux3, desapilar(&aux2));

        printf("PILA AUB:");
        mostrar(&aux2);

        break;

    case 11:
        printf("CARGUE LA PILA A");
        do
        {
            leer(&dada);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("CARGUE LA PILA B\n");
        do
        {
            leer(&aux);
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }
        while(yes=='s'|| yes=='S');

        printf("PILA ORDENADA 1");
        mostrar(&dada);

        printf("PILA ORDENADA 2");
        mostrar(&aux);

        while(!pilavacia(&dada) && !pilavacia(&aux))
        {
            apilar(&aux2, desapilar(&aux));
            apilar(&aux2, desapilar(&dada));

        }
        while(!pilavacia(&aux2))
        {
            apilar(&dada, desapilar(&aux2));
        }

        while (!pilavacia(&dada))
         {
             apilar(&aux2, desapilar(&dada));

             while(!pilavacia(&dada))
             {
                 if(tope(&aux2)>tope(&dada))
                 {
                     apilar(&aux, desapilar(&aux2));
                     apilar(&aux2, desapilar(&dada));
                 }
                 else
                 {
                     apilar(&aux, desapilar(&dada));
                 }
             }

             while(!pilavacia(&aux))
             {
                 apilar(&dada, desapilar(&aux));
             }

             apilar(&aux3, desapilar(&aux2));
         }

        printf("PILA ORDENADA FINAL");
        mostrar(&aux3);

        break;
    case 12:

         do
        {
            printf("para insertar un numero por favor ");
            leer(&dada);
            apilar(&aux, desapilar(&dada));
             while(!pilavacia(&dada) && tope(&dada)>tope(&aux))
        {
            apilar(&aux2, desapilar(&dada));
        }

        apilar(&dada, desapilar(&aux));

        while(!pilavacia(&aux2))
        {

            apilar(&dada, desapilar(&aux2));
        }
            printf("para agregar un elemento mas a la pila, presione 's'\n");
            fflush(stdin);
            scanf("%c", &yes);
        }while(yes=='s'|| yes=='S');

        printf("La pila quedo se la siguiente manera:");
        mostrar(&dada);

        break;


    case 13:
        srand(time(NULL));
        for(i=0;i<12;i++)
        {
            apilar(&dada, rand()%12+1);
        }
        mostrar(&dada);

        while(!pilavacia(&dada))
        {
            apilar(&aux, desapilar(&dada));
            total=total + tope(&aux);

            apilar(&aux2, desapilar(&dada));
            prome=prome + tope(&aux2);

            apilar(&aux, desapilar(&dada));
            total=total + tope(&aux);

            apilar(&aux2, desapilar(&dada));
            prome=prome + tope(&aux2);

        printf("\n%i\n", total);
        printf("\n%i\n", prome);
        }

        printf("\nTOTAL DE PUNTOS DEL JUGADOR 1: %i\n", total);
        printf("\nTOTAL DE PUNTOS DEL JUGADOR 2: %i\n", prome);
        if(total == prome)
        {
        printf("\n ES UN EMPATE, pero como esta comprado, GANA el jugador 1!!!!!!!\n");
        }else if(total>prome)
        {
        printf("\nEl ganador es el jugador 1!!!!!!!\n");
        }else
        {
        printf("\nEl ganador es el jugador 2!!!!!!!\n");
        }

        break;
    }

    while(!pilavacia(&dada))
    {
        desapilar(&dada);
    }
    while(!pilavacia(&aux))
    {
        desapilar(&aux);
    }
    while(!pilavacia(&aux2))
    {
        desapilar(&aux2);
    }
    while(!pilavacia(&aux3))
    {
        desapilar(&aux3);
    }

    printf("\n\nDesea realizar otro ejercicio?. Presiome 's' para si: ");
    fflush(stdin);
    scanf("%c", &yes);
    }while(yes=='s'|| yes=='S');

    printf("\n\n\nGracias por ver la guia!!!1!!\n\n\n");

    return 0;
}
