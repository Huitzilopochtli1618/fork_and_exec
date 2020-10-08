/***********************************************************
   exec_c.c
   Demuestra el uso de algunas de las funciones exec...
   
***********************************************************/

#include <unistd.h>
#include <stdio.h>

void usar_execvp();
void usar_execlp();


int main ()
{
   char b;
	char c;
	printf("Quieres usar execvp(v) o execlp(l)?: ");
	scanf("%c",&c);
	switch(c)
	{
		case 'v':	usar_execvp(); break;
		case 'l':	usar_execlp(); break;
	}
	
	return 0;
}

void usar_execvp()
{
	char *v[]={"xterm", "-bg", "yellow", "-fa",  "Monospace", "-fs", "18", "-e", "vi", NULL};
	execvp("xterm", v);

   /* Para terminal konsole de KDE */
   //char *v[]={"konsole", "-e", "vi", NULL};
   //execvp("konsole", v);
}

void usar_execlp()
{
	execlp("xterm", "xterm", "-bg", "skyblue", "-fa",  "Monospace", "-fs", "18", "-e", "vi", NULL);
}

