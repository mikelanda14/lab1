
/** \brief Solicita un caracter del usuario tomando un mensaje[]
*
* \param mensaje[]
* \return Return un caracter
*
*/
char getChar(char mensaje[]);
/** \brief Solicita un entero de usuario tomando un mensaje
*
* \param mensaje[]
* \return Return el entero
*
*/
int getInt(char mensaje[]);
/** \brief solicita un float del usuario
*
* \param mensaje[]
* \return Return un flotante
*
*/
float getFloat(char mensaje[]);
/** \brief solicita una cadena de caractees*
* \param int cantidad el numero de maximo de caracteres a leer
* \param mensaje[] el mensaje que se le dara al usario
* \param nombre[] la cadena donde almacena la cadena de caracteres.
*
*/
void miFgets(char nombre[], int cantidad,char mensaje[]);
/** \brief toma el valor a validar, si es correcto lo retorna
* de lo contrario informa que esta fuera de rango y solicita el valor de nuevo
* \param int anio
*\return int anio
*
*/
int valAnio(int anio);
/** \brief toma el valor a validar, si es correcto lo retorna
* de lo contrario informa que esta fuera de rango y solicita el valor de nuevo
* \param int mes
*\return int mes
*
*/
int valMes(int Mes);
/** \brief toma el valor a validar, si es correcto lo retorna
* de lo contrario informa que esta fuera de rango y solicita el valor de nuevo
*\param int dia
*\return int dia
*
*/
int valDia(int Dia);
/** \brief toma el valor a validar, si es correcto lo retorna
* de lo contrario informa que esta fuera de rango y solicita el valor de nuevo
* \param float sala
*\return float sala
*
*/
float valSalary(float sala);
/** \brief toma el valor a validar, si es correcto lo retorna
* de lo contrario informa que esta fuera de rango y solicita el valor de nuevo
* \param int anio
*\return int anio
*
*/
char valSexo(char sexo);

