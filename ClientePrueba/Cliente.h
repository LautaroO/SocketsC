/*
 * Cliente.h
 *
 *  Created on: 20 abr. 2019
 *      Author: utnso
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_


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
#include<readline/readline.h>
#include<readline/history.h>
#include"Mensajes/mensajes.h"


int conectar_servidor(void);

#endif /* CLIENTE_H_ */
