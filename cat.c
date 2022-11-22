#include<fcntl.h> 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char *argv[]){
    if(strcmp(argv[1],"-n")==0){
        int count=1;
        FILE *f; 
        char c;
        f=fopen(argv[2],"r");
        printf("%d) ",count);
    while(c!=EOF){
        printf("%c",c);
        if(c=='\n'){
            count++;
            printf("%d) ",count);
        }
        c=getc(f);
    }
    fclose(f);
    printf("\n");
    }

    else if(strcmp(argv[1],"-e")==0){
        FILE *f; 
    char c;
    f=fopen(argv[2],"r");
    while(c!=EOF){
        if(c=='\n'){
            printf("$");
        }
        printf("%c",c);
        c=getc(f);
    }
    fclose(f);
    printf("\n");
    }
    else{
    FILE *f; 
    char c;
    f=fopen(argv[1],"r");
    while(c!=EOF){
        printf("%c",c);
        c=getc(f);
    }
    fclose(f);
    printf("\n");
    }
}