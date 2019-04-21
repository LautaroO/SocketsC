/*
 * LevantarServer.h
 *
 *  Created on: 18 abr. 2019
 *      Author: utnso
 */

#ifndef LEVANTARSERVER_H_
#define LEVANTARSERVER_H_

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


#define PUERTO 8888
#define MAXCLIENTES 2

int iniciar_servidor(void);
int aceptar_conexion(int);

#endif /* LEVANTARSERVER_H_ */
