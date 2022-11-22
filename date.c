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
#include<time.h>

int main(int argc,char * argv[]){
    time_t t ;
    struct tm *tmp ;
    char MY_TIME[100];
    time( &t );
     
    tmp = localtime( &t );
     
    // using strftime to display time
    strftime(MY_TIME, sizeof(MY_TIME), "%a %b %d %r %Z %G",tmp);
    printf("%s",MY_TIME);
}
