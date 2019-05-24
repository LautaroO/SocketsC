/*
 * Servidor.c
 *
 *  Created on: 18 abr. 2019
 *      Author: utnso
 */

#include"Servidor.h"


int main(void){

	int socket_sv, nueva_conexion; //sockets

	socket_sv = iniciar_servidor();
	printf("[Servidor] esperando las conexiones... \n\n");
	pthread_t thread_id_array[3];

	/*Voy a tener 3 conexiones solamente, y hago un thread para gestionar cada una*/
	int i;
	for(i = 0; i<3; i++){
		nueva_conexion = aceptar_conexion(socket_sv);
		printf("[Servidor] Se conecto un cliente, faltan %d \n\n", 2 - i);
		pthread_create(&(thread_id_array[i]),NULL,gestionar_request,nueva_conexion);
	}

	printf("-- El servidor esta esperando a que sus clientes terminen! \n\n");
	/* Espero a que terminen los 3 threads*/
	pthread_join(thread_id_array[0],NULL);
	pthread_join(thread_id_array[1],NULL);
	pthread_join(thread_id_array[2],NULL);

	printf("[Servidor] Termino el Server!\n");
	return EXIT_SUCCESS;
}

void gestionar_request(int socket_conexion){

	int tamanio_msg;

	while(1){
		switch(determinar_operacion(&tamanio_msg, socket_conexion)){
			case DESCONEXION:
				printf("[Servidor ]El usuario con el socket: %d se desconecto. Thread finalizado\n\n ");
				close(socket_conexion);
				return;
			default:
				printf("[Servidor] El socket %d mando: ");
				recibir_mensaje(tamanio_msg, socket_conexion);
				break;
		}
	}

}
