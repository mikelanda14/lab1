typedef struct{
int idMenu;//(autoincremental)
char descripMenu[51];//Descripcion (validar: máximo 51 caracteres)
float importe;//Importe (validar: debe ser mayor a cero)
}eMenu;//Menu (struct):(Solamente el alta con hardcode)
typedef struct{
int dia,mes,anio;
}eFecha;
typedef struct{
int legajo;//(autoincremental)
char apellido[51];//val max 51
char nombre[51];//val max 51
char sexo;//val m o f
float salario;//val mayor que 0
eFecha fechaInge;//validar rangos
int idSector;//validar que exista
int isEmpty;//inicializar
}eEmpleado;

typedef struct{
int idAlmuerzo;//auto incremento
int idMenu;//validar que existe
int legajoEmple;//validar que existe
eFecha fechaAlmuerzo;//validar rangos
int isEmpty;//inicializar
}eAlmuero;
typedef struct{
int idSector;//auto incremento
char descripcion[51]; //validar maximo 51
}eSector;
/** \brief menu de opciones manejo empleados y almuerzos
*\param struc eMenu menu[]
*\param struc eEmpleado empleado[]
*\param struc eAlmuerzo almueroz[]
*\param struc eSector sector[]
*\param int m , c,s,a
*\return int dia
*
*/
void menuSEA(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a);
/** \brief menu de opciones manejo empleados
*\param struc eMenu menu[]
*\param struc eEmpleado empleado[]
*\param struc eAlmuerzo almueroz[]
*\param struc eSector sector[]
*\param int m , c,s,a
*\return int dia
*
*/
void menuEm(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a);
/** \brief menu de opciones manejo Almuerzos
*\param struc eMenu menu[]
*\param struc eEmpleado empleado[]
*\param struc eAlmuerzo almueroz[]
*\param struc eSector sector[]
*\param int m , c,s,a
*\return int dia
*
*/
void menuAl(eMenu menu [],eEmpleado empleado[],eAlmuero almuerzo[],eSector sector[],int m,int c,int s,int a);
/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *\param len int Array length
 *\param Employe[] paso por valor
 *
 */
int initEmployees(eEmpleado empleado[], int len);
int altaEmpleados(eEmpleado empleado[],eSector sector[],int s,int len);
int ifAllEmpty(eEmpleado empleado[],int len);
int generarId(eEmpleado empleado[],int len);
void printEmployees(eEmpleado empleado[], int len,eSector sector[],int s);
int sortEmployees(eEmpleado empleado[], int len);
int valSector(eSector sector[],int s);
void imprimirSubmenu(eSector sector[],int s);
int  removeEmployee(eEmpleado empleado[],int len);
int modEmployees(eEmpleado empleado[],int c,eSector sector[],int s);

int altaAlmuerzos(eEmpleado empleado[],eSector sector[],eMenu menu[],eAlmuero almuerzo[],int s,int c,int m,int a);
int valEmpleado(eEmpleado empleado[],int c);
int valMenu(eMenu menu[],int m);
int initAlmu(eAlmuero almuerzo[], int a);
int generarIdAl(eAlmuero almuerzo[],int a);
void listaSAlmu(eEmpleado empleado[],eMenu menu[],eAlmuero almuerzo[],int c,int m,int a);
void filtrarAlmu(eEmpleado empleado[],eMenu menu[],eAlmuero almuerzo[],int c,int m,int a);
