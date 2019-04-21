/*
 * recibir.c
 *
 *  Created on: 19 abr. 2019
 *      Author: utnso
 */

#include"recibir.h"

char* recibir_mensaje(int conexion){

	int size;
	char* buffer = malloc(11);

	if((size = recv(conexion,buffer,10,0)) == -1){
		perror("No recibi el mensaje");
		exit(1);
	}

	buffer[size] = '\0';

	return buffer;

}

void desconectar_cliente(int conexion){

	if(send(conexion,"[Servidor] Bye!\n",16,0) == -1){
		perror("No pude mandar bye");
	}

	printf("[Servidor] Cliente %d desconectado\n",conexion);
	close(conexion);

}


void pedir_nueva_accion(int conexion){

	if(send(conexion,"[Servidor] Mandame un mensaje de hasta 10 caracteres.\n",54,0) == -1){
		perror("Error al pedir que te mande un mensaje!");
		exit(1);
	}


}

void imprimir_mensaje(char* buffer){

	printf("%s\n",buffer);

}

void notificar_llegada(int conexion){

	if(send(conexion,"[Servidor] Me llego!\n",21,0) == -1){
		perror("no le notifique que me llego");
		exit(1);
	}

}
