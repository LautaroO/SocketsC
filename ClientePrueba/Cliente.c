/*
 * Cliente.c
 *
 *  Created on: 20 abr. 2019
 *      Author: utnso
 */

#include"Cliente.h"

int main(void){

	int conexion;
	char* buffer = NULL;
	int size;

	conexion = conectar_servidor();

	while(1){

		recibir_mensaje(conexion);
		buffer = ingresar_mensaje();
		size = strlen(buffer);
		//printf("%d\n",size); esto esta bien
		enviar_mensaje(conexion,buffer);
		if(!strcmp(buffer,"exit")){
			buffer = malloc(17);
			if((size = recv(conexion,buffer,16,0)) == -1){
				perror("no me desconecto!");
			}
			buffer[size] = '\0';
			printf("%s",buffer);
			break;
		}
		else{
			buffer = malloc(22);
			if((size = recv(conexion,buffer,21,0)) == -1){
				perror("no me notifico!");
			}
			buffer[size] = '\0';
			printf("%s",buffer);
		}

	}

	printf("Termino el cliente!");
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

char* ingresar_mensaje(void){

	char* buffer = readline(">>");

	return buffer;
}

void recibir_mensaje(int conexion){

	char* buffer = malloc(55);
	int size;

	if((size = recv(conexion,buffer,54,0)) == -1){
		perror("recibir mensaje cliente");
		exit(1);
	}

	buffer[size] = '\0';

	printf("%s", buffer);
}

void enviar_mensaje(int conexion,char* buffer){

	int size = strlen(buffer);

	if(send(conexion,buffer,size,0) == -1){
		perror("no le pude mandar el mensaje");
	}


}
