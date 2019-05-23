/*
 * Cliente.c
 *
 *  Created on: 20 abr. 2019
 *      Author: utnso
 */

#include"Cliente.h"

int main(void){

	int conexion;

	conexion = conectar_servidor();

	while(1){

		printf("Mandale un nuevo mensaje:\n ");

		if(!mandar_mensaje(conexion)){
			printf("Te desconectaste! \n");
			break;
		}

	}

	close(conexion);
	return EXIT_SUCCESS;
}

int conectar_servidor(void){

	int socket_conexion;
	struct sockaddr_in their_addr;
	int size_addr = sizeof(struct sockaddr);

	if((socket_conexion = socket(AF_INET,SOCK_STREAM,0)) == -1){
		perror("Fallo al crear el socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(8888);
	inet_aton("127.0.0.1",&(their_addr.sin_addr));
	bzero(&(their_addr.sin_zero),8);

	if(connect(socket_conexion,(struct sockaddr*)&their_addr,size_addr) == -1){
		perror("Fallo al conectar con el Servidor");
		exit(1);
	}

	int size;
	char* buffer = malloc(27);

	if((size = recv(socket_conexion,buffer,26,0)) == -1){
		perror("No llego la notificacion");
		exit(1);
	}

	buffer[size] = '\0';
	printf("%s",buffer);

	return socket_conexion;
}
