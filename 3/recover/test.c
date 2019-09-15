#include <stdio.h>
#include <cs50.h>

int filenamespp(char *filenames);

int main(){
    FILE *ptest;
    fclose(ptest);

    return 0;
}

int filenamespp(char *filenames){
    if(filenames[2]=='9'){
        if(filenames[1]=='9'){
            filenames[2]='0';
            filenames[1]='0';
            filenames[0]++;
        }
        else{
            filenames[2]='0';
            filenames[1]++;
        }
    }
    else{
        filenames[2]++;
    }
    return 0;
}