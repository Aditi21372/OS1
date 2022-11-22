#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char * argv[]){
    struct dirent *d;
    DIR *dh=opendir(".");
    if(argv[1]==NULL){
        while ((d = readdir(dh)) != NULL){
		if (d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
	}
    }
    else if(strcmp(argv[1],"-a\n")==0){
        while ((d = readdir(dh)) != NULL){
		printf("%s  ", d->d_name);
    }
    }
    else if(strcmp(argv[1],"-l\n")==0){
        int count=1;
        while ((d = readdir(dh)) != NULL){
		if (d->d_name[0] == '.')
			continue;
		printf("%d: %s  \n",count, d->d_name);
        count++;
       
    }
    }
    else{
        printf("ERROR: Invalid argument for ls");
    }
} 