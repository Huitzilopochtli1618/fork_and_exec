#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <string.h>

int entrada=0;

int main(int argc, char  *argv[])
{
	while(entrada != -1){
		printf("\n%s introduce un numero positivo o -1 para salir: ", argv[1]);
		scanf("%d", &entrada);
		fflush(stdout);
		system("clear");

		printf("███████████████████████████\n");
		printf("███████▀▀▀░░░░░░░▀▀▀███████\n");
		printf("████▀░░░░░░░░░░░░░░░░░▀████\n");
		printf("███│░░░░░░░░░░░░░░░░░░░│███\n");
		printf("██▌│░░░░░░░░░░░░░░░░░░░│▐██\n");
		printf("██░└┐░░░░░░░░░░░░░░░░░┌┘░██\n");
		printf("██░░└┐░░░░░░░░░░░░░░░┌┘░░██\n");
		printf("██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██\n");
		printf("██▌░│██████▌░░░▐██████│░▐██      %d TE GANE!!!\n", entrada+1);
		printf("███░│▐███▀▀░░▄░░▀▀███▌│░███\n");
		printf("██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██\n");
		printf("██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██\n");
		printf("████▄─┘██▌░░░░░░░▐██└─▄████\n");
		printf("█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████\n");
		printf("████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████\n");
		printf("█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████\n");
		printf("███████▄░░░░░░░░░░░▄███████\n");
		printf("██████████▄▄▄▄▄▄▄██████████\n");
		printf("███████████████████████████\n");
	}
	
	
	int padre=getppid();
	char str[10];
	sprintf(str,"%d",padre);

	printf("%s", str);
	fflush(stdout);

	char comando[]="kill ";
	strcat(comando, str);
	system(comando);
	_exit(0);
}