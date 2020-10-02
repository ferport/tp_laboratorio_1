#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief Inicializa un array de empleados,inicializando su campo isEmpty en 1
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si no hubo fallos , 1 si hay fallos
 *
 */
int initEmployees(Employee empleados[], int tam);

/** \brief Menu principal del ABM
 *
 * \return Opcion deseada por el usuario
 *
 */
int menu();

/** \brief Añade un empleado a un array de empleados
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \param Id del empleado
 * \return 0 si no hubo fallos , 1 si hay fallos
 *
 */
int addEmployees(Employee empleados[],int tam,int id);

/** \brief Busca el primer empleado vacio en un array de empleados
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return Indice del array del primer empelado libre
 *
 */
int buscarLibre(Employee empleados[], int tam);

/** \brief Busca un empleado dentro de un array de empleados por el id
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \param Id del empleado que desea buscar
 * \return Indice del array donde se encuentra el empleado con dicho id
 *
 */
int findEmployeeById(Employee empleados[],int tam,int id);

/** \brief Imprime los datos de un solo empleado que no este vacio
 *
 * \param Empleado a mostrar
 *
 */
void printEmployee(Employee empleado);

/** \brief Imprime una lista de empelados que no esten vacios
 *
 * \param Array de empleados a mostrar
 * \param Tamaño del array
 * \return 0 si no hay fallos, 1 si hay fallos
 *
 */
int printEmployees(Employee empleados[], int tam);

/** \brief Cambia el isEmpty por 1 para remover el empleado de la lista
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si no hay fallos, 1 si hay fallos,2 si el usuario cancela la baja
 *
 */
int removeEmployee(Employee empleados[],int tam);

/** \brief Ordena un array de empelados de manera ascendente o descendente
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \param Orden en el que se ordena,1 para ascendente y 0 para descendente
 * \return 0 si no hay fallos, 1 si hay fallos
 *
 */
int sortEmployees(Employee empleados[], int tam, int orden);

/** \brief Modifica los campos name,lastName,salary y sector de una estructura Employee usando su id
 *
 * \param Array de empleados
 * \param Tamaño del array
 * \return 0 si no hay fallos, 1 si hay fallos,2 si el usuario cancela la modificacion
 *
 */
int modifyEmployee(Employee empleados[],int tam);

/** \brief Imprime un informe de salarios
 *
 * \param Array de empleados
 * \param Tamaño del array
 *
 */
void informeSalarios(Employee empleados[],int tam);

/** \brief Formatea un string que contenga nombres simples o compuestos
 *
 * \param String a formatear
 *
 */
void formatearCadena(char cadena[]);

/** \brief Valida que en un string solo se puedan poner letras o espacios o comilla simple
 *
 * \param string a validar
 * \return 0 si no hay fallos, 1 si hay fallos
 *
 */
int validacionCadena(char cadena[]);
