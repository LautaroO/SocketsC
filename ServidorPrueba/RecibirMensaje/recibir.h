/*
 * recibir.h
 *
 *  Created on: 19 abr. 2019
 *      Author: utnso
 */

#ifndef RECIBIR_H_
#define RECIBIR_H_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<netdb.h>
#include<signal.h>
#include<ctype.h>

typedef enum{
	DESCONEXION,
	MENSAJE
}cod_op;

void recibir_mensaje(int conexion);
void* recibir_buffer(int* size,int conexion);
cod_op determinar_operacion(char* buffer);
void desconectar_cliente(int conexion);

#endif /* RECIBIR_H_ */
