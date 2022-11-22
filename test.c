#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
#include<pthread.h>


#define PATH_MAX 4096

void pwd(){
	char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
       printf("%s\n", cwd);
	}
	else{
		printf("error finding directory");
	}
}

int main(){
	char cmdin[100];
	while (1){
		char *arr[100]={0};
		int count=0;
        printf("\n>>>");
        fgets(cmdin,100,stdin);
		char * str=strtok(cmdin," ");
		str[strcspn(str, "\n")] = 0;
		while( str != NULL) {
				arr[count]=str;
				count+=1;
      			str = strtok(NULL, " \n");
		}
		if(strcmp(arr[0],"exit")==0){
			printf("Terminating Shell");
			exit(0);
		}
		else if(strcmp(arr[0],"pwd")==0){
			if(arr[1]=NULL){
				pwd();
			}
			else if(strcmp(arr[1],"-L")==0 || strcmp(arr[1],"-l")==0){
			}
			else if(strcmp(arr[1],"-P")==0 || strcmp(arr[1],"-p")==0){
				pwd();
			}
		}
		else if(strcmp(arr[0],"echo")==0){
			if(strcmp(arr[1],"--help")==0){
				printf("Arguments for echo:\nuse '-h' for help (displays this menu)\n use '*' to print the whole directory");
			}
			else if(strcmp(arr[1],"*")==0){
				//test with mkdir
				DIR *d;
				struct dirent *dir;
				d = opendir(".");
				if (d) {
					while ((dir = readdir(d)) != NULL) {
					printf("%s\n", dir->d_name);
					}
					closedir(d);
				
				}
			}
			else if(arr[1]=NULL){
				printf("Error: 'echo' must have arguments");
			}
			else{
				for(int i=1;i<count;i++){
					printf("%s ",arr[i]);
				}
			}
		}
		else if(strcmp(arr[0],"cd")==0){   
			char s[100];
			chdir(arr[1]);
    	}
		else if(strcmp(arr[0],"date&t")==0){
			pthread_t thread_id;
			char *cmdwargs=malloc(100);
			strcpy(cmdwargs,"date");
			for (int i=1;i<10;i++){
				if (arr[i] !=NULL){
					strcat(cmdwargs," ");
					strcat(cmdwargs, arr[i]);
				}
				else{
					break;
				}
			}
			pthread_create(&thread_id, NULL,(void*)system,"date");
			pthread_join(thread_id,NULL);
		}
		else{
			pid_t  pid;
			int    status;

			if ((pid = fork()) < 0) {     
				printf("ERROR: forking child process failed\n");
				exit(1);
			}
			else if (pid == 0) { 
				if (execv(arr[0],arr) < 0) {    
				printf("ERROR: exec failed\n");
				exit(1);
			}
			}
			else {                                  
				while (wait(&status) != pid);
			}
		}
		
	}
	return 0;

}


