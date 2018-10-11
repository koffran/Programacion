#ifndef FUNCIONES2_H_INCLUDED
#define FUNCIONES2_H_INCLUDED
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4
#define ESTACIONADO 1
#define NO_ESTACIONADO 2

typedef struct {
    char patente[7];
    int propietario;
    int estado;
    int id;
    int marca;
}eAutomovil;


/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initeAutomovils (eAutomovil*,int);

/** \brief add in a existing list of eAutomovils the values received as parameters
 * in the first empty position
 * \param list eAutomovil*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param cuit int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addeAutomovils(eAutomovil* list, int , int ,char [],int, int);


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void altaAutos (eAutomovil *, int );

/** \brief Remove a eAutomovil by Id (put estado Flag in 1)
 *
 * \param list eAutomovil*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a eAutomovil] - (0) if Ok
 *
 */
int estacionarAutomovil (eAutomovil*,int);

/** \brief Sort the elements in the array of eAutomovils, the argument order
indicate UP or DOWN order
 *
 * \param list eAutomovil*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sorteAutomovils (eAutomovil* , int , int );

/** \brief print the content of eAutomovils array
 *
 * \param list eAutomovil*
 * \param length int
 * \return int
 *
 */
void printeAutomovils (eAutomovil *,int );


/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeoAutos (eAutomovil []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibreAuto(eAutomovil lista[],int);

/** \brief find an eAutomovil by Id en returns the index position in array.
 *
 * \param list eAutomovil*
 * \param len int
 * \param id int
 * \return Return eAutomovil index position or (-1) if [Invalid length or NULL
pointer received or eAutomovil not found]
 *
 */
int findeAutomovilById(eAutomovil* lista, int dni,int tam);



/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list eAutomovil*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printeAutomovil(eAutomovil* list, int i);

/** \brief Permite modificar datos de un empleado
 *
 * \param El array
 * \param El tamaño del array
 * \param El ID del empleado a modificar
 * \return
 *
 */
void modificarAuto (eAutomovil* lista, int tam, int id);

void printeAutomovilRetirado(eAutomovil* list, int i);
void printeAutomovilsRetirados(eAutomovil* list, int length);

float retirarAutos(eAutomovil* publicaciones,int indice);

int devolverHorasEstadia();
#endif // FUNCIONES_H_INCLUDED
