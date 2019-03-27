
#include <string.h>
#include <stdio.h>

#include "command.func.h"

#define DIM 300
#define CYAN "\033[1;36m" // Bold cyan
void talkWithServer(char buf[DIM], int *con,char *argv[],int argc);
void vider_stdin(void);
/* Use https://www.codingame.com/playgrounds/14213/how-to-play-with-strings-in-c/string-split to
 *split a string like an "explode()" in Php, when a string is received, you gotta split the string to 
 *retrieve the parameter(s) of the command 
*/

int main (int argc, char *argv[]){
	char buf [DIM] ;
	int connected=1,send_ok=0,i;
	
	while(connected==1){
		talkWithServer(buf,&connected,argv,argc);
	}
	printf(CYAN "Disconnected.\n");
	return 0;
}
/* */
void talkWithServer(char buf[DIM], int *con,char *argv[],int argc){
	char *pc;
    	char s_buffer[DIM] = {0};
    	

   	int saisie_OK = 0;
	int i;
        while (saisie_OK == 0){
		/* */
		printf("cmd$>: ");
		fflush(stdout);
	 	/*similaire au scanf, mais prend les espaces*/
		fgets(s_buffer, sizeof s_buffer, stdin);
		if ((pc = strchr(s_buffer, '\n')) != NULL)
		{
			*pc = '\0';
			saisie_OK = 1;
			memset(buf,0,DIM);
			strcpy(buf, s_buffer);
		    
			if (!strncmp (buf, "copy", strlen("copy"))) {
				copy_file();
			}else if (!strncmp (buf, "ls", strlen("ls"))) {
				list_file();
			}else if (!strncmp (buf, "touch", strlen("touch"))) {
				create_file("try");
			}else if (!strncmp (buf, "mkdir", strlen("mkdir"))) {
				create_directory("rep");
			}else if (!strncmp (buf, "rm", strlen("mkdir"))) {
				remove_file ("test");
			}else {
			    if(strcmp(buf,"exit") == 0){
					*con=0;
			    }
			}
		}
		else
		{
		    /* saisie trop longue > DIM */
		    fprintf(stderr, "La saisie est trop longue!\n");
		    vider_stdin();
		}
	        memset (buf, 0, DIM);

	}
}
void vider_stdin(void){
    scanf("%*[^\n]");
    getchar();
}
