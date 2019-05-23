/*
 * recibir.c
 *
 *  Created on: 19 abr. 2019
 *      Author: utnso
 */

#include"recibir.h"

void* recibir_buffer(int size, int conexion){

	void* buffer;

	buffer = malloc(size);

	if(recv(conexion,buffer,size,MSG_WAITALL) == -1){
			perror("Fallo al recibir el mensaje");
		}

	return buffer;

}

cod_op determinar_operacion(int* size, int conexion){

	int bytes = recv(conexion,size,sizeof(int),MSG_WAITALL);

	if(bytes == -1){
			perror("Fallo al recibir el tamanio.");
			exit(1);
		}
	else if(bytes == 0){
		return DESCONEXION;
	}
	else{
		return MENSAJE;
	}
}

void desconectar_cliente(int conexion){


	close(conexion);
	printf("Cliente %d Desconectado\n", conexion);

}


void recibir_mensaje(int size, int conexion){

	char* buffer;

	buffer = recibir_buffer(size, conexion);

	buffer[size] = '\0';

	printf("Mensaje: %s\n", buffer);

	free(buffer);
}



