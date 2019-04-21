/*
 * Servidor.h
 *
 *  Created on: 18 abr. 2019
 *      Author: utnso
 */

#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"IniciarServer/LevantarServer.h"
#include"RecibirMensaje/recibir.h"
#include<sys/select.h>
#include<sys/time.h>

void pedir_nueva_accion(int conexion);

#endif /* SERVIDOR_H_ */
