#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {
    char name[51];
    char lastName[51];
    char direccion[51];
    int isEmpty;
    int id_propietario;
   long long int numeroTarjeta;
}ePropietario;


int menu();

/** \brief Inicializa el estado del array para futuras validaciones
 *
 * \param El array a inicializar
 * \param El tamaño del array
 * \return
 *
 */
int initePropietarios (ePropietario*,int);

/** \brief add in a existing list of ePropietarios the values received as parameters
 * in the first empty position
 * \param list ePropietario*
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
int addePropietarios(ePropietario* list, int , int , char [],char [],long long int ,char[]);


/** \brief
 *
 * \param El array en el que se carga la nueva persona
 * \param El indice
 * \return
 *
 */
void altaPropietario (ePropietario *, int );

/** \brief Remove a ePropietario by Id (put isEmpty Flag in 1)
 *
 * \param list ePropietario*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a ePropietario] - (0) if Ok
 *
 */
void removeePropietario (ePropietario*,int, int );

/** \brief Sort the elements in the array of ePropietarios, the argument order
indicate UP or DOWN order
 *
 * \param list ePropietario*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortePropietarios (ePropietario* , int , int );

/** \brief print the content of ePropietarios array
 *
 * \param list ePropietario*
 * \param length int
 * \return int
 *
 */
void printePropietarios (ePropietario *,int );


/** \brief Carga automaticamente datos en el arrayy
 *
 * \param El array
 * \param
 * \return
 *
 */
void hardcodeo (ePropietario []);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePropietario lista[],int);

/** \brief find an ePropietario by Id en returns the index position in array.
 *
 * \param list ePropietario*
 * \param len int
 * \param id int
 * \return Return ePropietario index position or (-1) if [Invalid length or NULL
pointer received or ePropietario not found]
 *
 */
int findePropietarioById(ePropietario* lista, int dni,int tam);



/** \brief Muestra por pantalla un empleado de la lista
 *
 * \param list ePropietario*
 * \param i int el indice del empleado
 * \return void
 *
 */
void printePropietario(ePropietario* list, int i);

/** \brief Permite modificar datos de un empleado
 *
 * \param El array
 * \param El tamaño del array
 * \param El ID del empleado a modificar
 * \return
 *
 */
void modificar (ePropietario* lista, int tam, int id);



#endif // FUNCIONES_H_INCLUDED

