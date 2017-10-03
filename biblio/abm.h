typedef struct
{
    char vec [50];
    int dato;
    int estado;
    int dato2;
}eEstructura;

/** \brief Obtiene el primer indice libre del array.
 *
 * \param lista el array
 * \param el tamaño del array
 * \return el primer indice disponible
 *
 */
int obtenerEspacio(eEstructura lista[],int tam);

/** \brief Obtiene el indice que coincide con el dato pasado por parametro
 *
 * \param lista el array
 * \param el dato a ser buscado en el array
 * \param el tamaño del array.
 * \return el indice en donde se encuentra el elemento que coincide con el parametro dato
 *
 */
int buscar(eEstructura lista [],int, int tam);

/** \brief Elimina la seleccion de la lista
 *
 * \param lista el array
 * \param tamaño del array
 * \param el dato de la persona a borrar
 *
 */
void borrar(eEstructura lista[], int tam, int dato);

/** \brief Pide los datos
 *
 * \param array
 * \param el tamaño del array
 *
 */
void alta(eEstructura lista[],int tam);

/** \brief muestra el array completo
 *
 * \param array
 * \param tamaño del array
 *
 */
void mostrar(eEstructura lista[], int tam);

/** \brief Ordena segun el orden necesario
 *
 * \param array
 * \param tamaño del array
 *
 */
void ordenar (eEstructura lista [],int tam);

