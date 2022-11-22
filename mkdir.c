#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[]){
        if(strcmp(argv[1],"-v")==0){
            for(int i=2;i<argc;i++){
            struct stat st = {0};
            if (stat(argv[i], &st) == 0){
                printf("ERROR: Directory %s already exists",argv[i]);
            }
            else{
                mkdir(argv[i],0700);   
                printf("mkdir: created directory '%s'",argv[i]);     
            }
        }
    }
        else if(strcmp(argv[1],"-p")==0){
            int mark=0;
            char temp[100];
            char *s=strtok(argv[2],"/");

		    while( s != NULL) {
                struct stat st = {0};
                strcat(temp,s);
                if (stat(temp, &st) == 0){
                    printf("ERROR: Directory %s already exists",s);
                }
                else{
                    mkdir(temp,0700);        
                }
                
                strcat(temp,"/");
      			s = strtok(NULL, "/");
                
            }
        }

        else{
            for(int i=1;i<argc;i++){
                struct stat st = {0};
                if (stat(argv[i], &st) == 0){
                    printf("ERROR: Directory %s already exists",argv[i]);
                }
                else{
                    mkdir(argv[i],0700);        
                }
            }
}
}