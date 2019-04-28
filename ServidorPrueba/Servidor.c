/*
 * Servidor.c
 *
 *  Created on: 18 abr. 2019
 *      Author: utnso
 */

#include"Servidor.h"
#include"IniciarServer/LevantarServer.h"



int main(void){

	int socket_sv, nueva_conexion; //sockets

	socket_sv = iniciar_servidor();

	nueva_conexion = aceptar_conexion(socket_sv);

	while(1){

		printf("Estoy esperando un nuevo mensaje\n");
		recibir_mensaje(nueva_conexion);


	}
	printf("Termino el Server!\n");
	return EXIT_SUCCESS;
}

