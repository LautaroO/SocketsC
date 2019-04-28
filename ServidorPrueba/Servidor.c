/*
 * Servidor.c
 *
 *  Created on: 18 abr. 2019
 *      Author: utnso
 */

#include"Servidor.h"


int main(void){

	int socket_sv, nueva_conexion; //sockets

	fd_set master; //conjunto original de descriptores (sockets)
	fd_set read_fds; //conjunto temporal para el select
	int fdmax; //descriptor maximo
	int i;

	FD_ZERO(&master);
	FD_ZERO(&read_fds);

	socket_sv = iniciar_servidor();

	FD_SET(socket_sv,&master);
	fdmax = socket_sv;

	//nueva_conexion = aceptar_conexion(socket_sv);

	while(1){

		read_fds = master;
		printf("Select esperando\n");
		if(select(fdmax + 1,&read_fds,NULL,NULL,NULL) == -1){
			perror("Select");
			exit(1);
		}

		for(i = 0; i <= fdmax; i++){

			if(FD_ISSET(i,&read_fds)){
				//printf("nueva iteracion del for\n");
				if(i == socket_sv){
					//printf("Prueba nuevo cliente : i = %d\n",i);
					nueva_conexion = aceptar_conexion(socket_sv);
					FD_SET(nueva_conexion,&master);
					fdmax = (fdmax < nueva_conexion) ? nueva_conexion : fdmax;
				}
				else{
					//printf("Prueba nuevo mensaje : i = %d\n",i);
					recibir_mensaje(i,&master);
				}
			}

		}

	}
	printf("Termino el Server!\n");
	return EXIT_SUCCESS;
}

