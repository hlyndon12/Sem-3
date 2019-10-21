#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void play();
void main () {
   play();
} 
void play()
{
    char command[50];
    char name[50];
    strcpy(command,"start ");
    printf("enter songs name\n");
    scanf("%[^\n]%*c", name);
    strcat(command, name);
    strcat(command,".mp3");
    printf("%s",command);
}