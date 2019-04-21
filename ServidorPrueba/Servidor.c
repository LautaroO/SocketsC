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

	char* buffer;

	socket_sv = iniciar_servidor();

	nueva_conexion = aceptar_conexion(socket_sv);

	while(1){

		pedir_nueva_accion(nueva_conexion);
		buffer = recibir_mensaje(nueva_conexion);

		if(!strcmp(buffer,"exit")){
			desconectar_cliente(nueva_conexion);
						break;
		}
		else{
			imprimir_mensaje(buffer);
			notificar_llegada(nueva_conexion);
			free(buffer);
		}

	}
	printf("Termino el Server!\n");
	return EXIT_SUCCESS;
}

