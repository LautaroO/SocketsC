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

typedef enum{
	ERROR = -1,
	DESCONEXION,
	MENSAJE
}cod_op;

char* recibir_mensaje(int conexion);
void pedir_nueva_accion(int conexion);
void desconectar_cliente(int conexion);
void imprimir_mensaje(char* buffer);
void notificar_llegada(int conexion);

#endif /* RECIBIR_H_ */
