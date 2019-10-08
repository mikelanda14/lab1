
typedef struct{
int codigoJuego; //autoincremento
char descripcion[51];//val max 51
float importe;//val mayor a 0
}eJuegos;
typedef struct{
    int codigoCliente;//autoincremento
    char apellido[31];//validar max 31
    char nombre[31];//validar max 31
    char sexo;//validar F O M
    char domiciolio[51];//
    char telefono[21];//validar max 21
    int isEmpty;
}eClientes;
typedef struct{
int dia,mes,anio;//1900 a 2020
}eFecha;
typedef struct{
int codigoAlquiler;
int codigoJuego;
int codigoCliente;
eFecha fechaAlquiler;
int isEmpty;
}eAlquileres;


/** \brief Inicializa en 1 todos los campos de cliente isEmpty
 *
 * \param cliente[]
 * \param int c
 * \return 0
 *
 */
int initClientes(eClientes cliente[], int c);
/** \brief inicializa el campo isEmty en alquileres para identificar si esta disponible
 *
 * \param alquiler[]
 * \param a
 * \return 0
 *
 */
 int initAlquiler(eAlquileres alquiler[], int a);
 /** \brief Menu para Superior de opciones
  *
  * \param clientes[] struc
  * \param juego[] struc
  * \param alquiler[] struc
  * \param int c tamano
  * \param int a
  * \param int ju
  *
  */
  void menuCJA(eClientes clientes[],eJuegos juego[],eAlquileres alquiler[],int c,int ju,int a);

  /** \brief menu para opciones de cliente
   *
    * \param clientes[] struc
    * \param juego[] struc
    * \param alquiler[] struc
    * \param int c tamano
    * \param int a
    * \param int ju
    *
   */
   void menuCli(eClientes cliente[],eJuegos juego[],eAlquileres alquiler[],int c,int ju,int a);
   /** \brief ALTA PARA CLIENTES
    *
    * \param cliente[]
    * \param int c
    *
    */
    int altaClientes(eClientes cliente[],int c);

/** \brief genera un codigo unico de cliente auto incrementado
 *
 * \param cliente[]
 * \param int c
 * \return el codigo superior en el array aumentado en  1
 *
 */
 int generarId(eClientes cliente[],int c);

/** \brief Verifica si existe algun registro
 *
 * \param cliente[]
 * \param int c
 * \return retorna 0 como ninguno y 1 como existen
 *
 */
 int ifAllEmpty(eClientes cliente[],int c);
/** \brief inprime lista de clientes todos los parametros menos direccion
 *
 * \param cliente[]
 * \param int c
 *
 */
 void printClientes(eClientes cliente[], int c);
 /** \brief organiza los contentes por apellido y nombre segun sea nesesario
  *
  * \param cliente[]
  * \param int c
  * \return retorna 0
  *
  */
  int sortClientes(eClientes cliente[], int c);

/** \brief Da de baja al cliente cambiando el estado de isEmty de 0 a 1
 *
 * \param cliente[]
 * \param int c
 * \return 0
 *
 */
 int  removeCliente(eClientes cliente[],int c);
 /** \brief Modifica los datos del cliente en un array facilitandolo con un sub menu
  *
  * \param cliente[]
  * \param int c
  * \return 0
  *
  */
  int modClientes(eClientes cliente[],int c);
  /** \brief inprime listado de los juegos
   *
   * \param juego[]
   * \param int jue
   *
   */
   void printJuegos(eJuegos juego[], int jue);

/** \brief Ordena los juegos por descripcion en acendente
 *
 * \param juego[]
 * \param int ju
 * \return 0
 *
 */
   int sortJUEGOS(eJuegos juego[], int ju);
/** \brief crea codigo unico autogenerado para array alquiler
 *
 * \param alquiler[]
 * \param int a
 * \return ultimo codigo incrementado en uno
 *
 */
   int generarIdAl(eAlquileres alquiler[],int a);
/** \brief solicita y valia el codigo del cliente
 *
 * \param cliente[]
 * \param int c
 * \return el codigo validado  in sec
 *
 */
   int valCliente(eClientes cliente[],int c);
   /** \brief solicita y valida el codigo del juego
    *
    * \param cliente[]
    * \param int c
    * \return codigo validado
    *
    */
   int valJuego(eJuegos juego[],int ju);

/** \brief Da alta a los alquileres tomando datos de las estructuras juego y cliente
 *
 * \param juego[]
 * \param cliente[]
 * \param alquiler[]
 * \param int a
 * \param int ju
 * \param int c
 * \return 0
 *
 */
 int altaAlquileres(eJuegos juego[],eClientes cliente[],eAlquileres alquiler[],int ju,int c,int a);
/** \brief imprime lista de los alquileres
 *
 * \param juego[]
 * \param cliente[]
 * \param alquiler[]
 * \param int ju
 * \param int c
 * \param int a
 *
 */
 void printAlquileres(eJuegos juego[],eClientes clientes[],eAlquileres alquiler[],int ju,int c,int a);


