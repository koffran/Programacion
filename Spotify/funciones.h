typedef struct
{
    int idCancion;
    int interprete;
    char titulo [50];
    int duracion;
    int estado;
}eCancion;

typedef struct
{
    int idInterprete;
    char nombre [50];
    char nacionalidad [50];
    int estado;
}eInterprete;

void inicializarCancion (eCancion lista[],int tam);
void inicializarInterprete (eInterprete lista[],int tam);

void listarCanciones (eCancion lista[],int tam);
void listarInterpretes (eInterprete lista[],int tam);

void listarCancionesConInterprete (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI);
void listarCancionesEstadounidenses (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI);
void cancionesPorInterprete (eCancion listaCanciones[],int tamC, eInterprete listaInterprete[],int tamI);
