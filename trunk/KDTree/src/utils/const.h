/*
 * const.h
 *	Constantes de configuracion.
 */

#ifndef CONST_H_
#define CONST_H_

#define INSERT 0
#define MODIFY 1
#define OVERFLOW 2
#define UNDERFLOW 3
#define DELETE 4
#define ROOT_UNDERFLOW 5
#define ROOT_OVERFLOW 6
#define C_EOF 256
#define C_ESC 257

#define RANDOM_VOTANTES 1000


#define ARCH_LINEAS "masters/lineas.org"
#define ARCH_FORMACIONES "masters/formaciones.org"
#define ARCH_FALLAS "masters/fallas.org"
#define ARCH_ACCIDENTES "masters/accidentes.org"
#define ARCH_FRANJAS_HORARIAS "masters/franjas_horarias.org"

#define SIZE_LINEA_LEVANTAR 512
//cantidad maxima de susbelementos utilizados para armar la consulta por ejemplo, en el KDTree
#define CANT_SUBELEMENTOS 5
#define NOMBRE_LINEA "linea"
#define NOMBRE_FORMACION "formacion"
#define NOMBRE_FALLA "falla"
#define NOMBRE_ACCIDENTE "accidente"
#define NOMBRE_FRANJAHORARIA "franjaHoraria"
#define NOMBRE_FECHADESDE "fechaDesde"
#define NOMBRE_FECHAHASTA "fechaHasta"

#define NEXT 0
#define MAYOR 1
#define MENOR 2
#define IGUAL 3

#define ELEM_VACIO "0"
#define ELEM_TODO "*"
#define ELEM_TODO_NUM -1
#define ELEM_SEPARADOR ","

#define DIA_DEFAULT 1
#define MES_DEFAULT 1
#define ANIO_DEFAULT 1970
#define HORA_DEFAULT 0
#define MINUTO_DEFAULT 0


#endif /* CONST_H_ */
