#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <string.h>

void iniciarJuego(char const *nombre);
void esperarHijos();

int main(int argc, char const *argv[])
{
	char nombre[30];
	do{
		system("clear");

		printf("\n\n        _=====_                               _=====_       		\n");
		printf("       / _____ \\                             / _____ \\			\n");
		printf("     +.-'_____'-.---------------------------.-'_____'-.+			\n");
		printf("    /   |     |  '.                       .'  |  _  |   \\		\n");
		printf("   / ___| /|\\ |___ \\                     / ___| /_\\ |___ \\	\n");
		printf("  / |      |      | ;  __           _   ; | _         _ | ;   	\n");
		printf("  | | <---   ---> | | |__|         |_:> | ||_|       (_)| |   	\n");
		printf("  | |___   |   ___| ;SELECT       START ; |___       ___| ;   	\n");
		printf("  |\\    | \\|/ |    /  _     ___      _   \\    | (X) |    /|   	\n");
		printf("  | \\   |_____|  .','   ', |___|  ,'   ', '.  |_____|  .' |   	\n");
		printf("  |  '-.______.-' /       \\ANALOG/       \\  '-._____.-'   |   	\n");
		printf("  |               |       |------|        |               |   	\n");
		printf("  |              /\\       /      \\       /\\               |   	\n");
		printf("  |             /  '.___.'        '.___.'  \\              |   	\n");
		printf("  |            /                            \\             |   	\n");
		printf("   \\          /                              \\           /		\n");
		printf("    \\________/                                \\_________/		\n");

		printf("\n\n      Jugador ingrese su nombre: ");
		scanf("%s", nombre);

		if(strcmp(nombre,"Sayonnara")!=0){
			pid_t Pid = fork();
			if(Pid==0){
				iniciarJuego(nombre);
			}
		}
	}while(strcmp(nombre,"Sayonnara")!=0);

	printf("Esperando a que termine el resto de partidas...\n");
	system("clear");
	printf("###### Servidor de juegos apagado ######\n");
	esperarHijos();
	
	return 0;
}

void iniciarJuego(char const *nombre){

	char comando[]="./Jalisco ";
	strcat(comando, nombre);
	char *v[]={"xterm", "-bg", "red", "-fa",  "Monospace", "-fs", "11","-hold", "-e", comando, NULL};
	execvp("xterm", v);
	return;
}

void esperarHijos(){
	//espera a todos sus hijos
	int resultado;
	pid_t pidHijo= wait(&resultado);
	while(pidHijo != -1){
		pidHijo=wait(&resultado);
	}
}