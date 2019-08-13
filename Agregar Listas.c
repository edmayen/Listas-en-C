#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 50
struct datos
{
    char nombre[T];
    int edad;
    struct datos *sigui;
};
typedef struct datos nodo;
nodo* Nuevos();
void Cargar(nodo*,nodo*,nodo*);
void Imprimir(nodo*,nodo*,nodo*);
void Borrar(nodo*,nodo*);

int main()
{
    system("color f0");
    nodo *ini=NULL,*ant=NULL,*act=NULL;
    Cargar(ini,ant,act);
    Imprimir(ini,ant,act);
    Borrar(ini,act);
}

nodo* Nuevos()
{
    nodo *aux=NULL;
    aux=(nodo*)malloc(sizeof(aux));
    if(aux==NULL)
    {
        printf("\n\nError. No hay Memoria Suficiente.\n\n");
        getchar();
        exit -1;
    }
    else
    {
        return aux;
    }
}

void Cargar(nodo *ini, nodo *ant, nodo *act)
{
    int centi=0,dato;
    char *var,cad[T];
    printf("\n\nIngresa la Informacion. Para terminar de Cargar Ingresa el Nulo.\n\n");
    printf("Ingresa el Primer Nombre: ");
    var=gets(cad);
    while(var!=NULL)
    {
        printf("Ingresa la Edad de %s: ",cad);
        scanf("%d",&dato);
        if(centi==0)
        {
            ini=ant=act=Nuevos();
            strcpy(act->nombre,cad);
            act->edad=dato;
            act->sigui=NULL;
            centi=1;
        }
        else
        {
            act=Nuevos();
            strcpy(act->nombre,cad);
            act->edad=dato;
            act->sigui=NULL;
            ant=act;
        }
        fflush(stdin);
        printf("\nIngresa el Nombre: ");
        var=gets(cad);
    }
}

void Imprimir(nodo *ini, nodo *ant, nodo *act)
{
    printf("\n\nImpresion\n");
    for(act=ini;act!=NULL;act=act->sigui)
    {
        printf("\nNombre: %s",act->nombre);
        printf("\nEdad: %d",act->edad);
    }
}

void Borrar(nodo *ini, nodo *act)
{
    printf("\n\nBorrar\n\n");
    while(ini->sigui!=NULL)
    {
        act=ini;
        ini=ini->sigui;
        free(act);
    }
    free(ini);
}
