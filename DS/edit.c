#include<stdio.h>
#include<string.h>
int main()
{
        int pos;
        FILE *fp = fopen("playlist.wpl", "r");
 
        /* Position the stream to the end of fyle and get the byte offset. */
        fseek(fp, SEEK_END, 0);
        pos = ftell(fp);
 
        /* Do the math. */
        pos /= 2;
        printf("The middle of the file is at %d bytes from the start.\n", pos);
 
        /* Position stream at the middle. */
        fseek(fp, SEEK_CUR, pos);
 
        return 0;
}