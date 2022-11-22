#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[]){ 
    if(strcmp(argv[1],"-i")==0){
        for(int i=2;i<argc;i++){
        char yn;
        printf("are you sure you want to delete %s ? (y/n)",argv[i]);
        scanf("%c",&yn);
        if(yn=='y'){
            if(unlink(argv[i])){
                printf("ERROR: unable to delete file");
            }
        }
        
    }
    }
    else if(strcmp(argv[1],"-I")==0){
        char yn;
        printf("are you sure you want to delete all files?");
        scanf("%c",&yn);
        if(yn=='y'){
        for(int i=2;i<argc;i++){
            if(unlink(argv[i])){
                printf("ERROR: unable to delete file");
           
        }
    }
    }
    }
    else if(argv[1]==NULL){
        printf("ERROR: rm must have arguments");
    }
    else{
        for(int i=1;i<argc;i++){
            printf("%s",argv[i]);
            if(unlink(argv[i])){
                printf("ERROR: unable to delete file");
            }
    }
}

}
