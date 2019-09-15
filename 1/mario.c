#include <cs50.h>
#include <stdio.h>

int main(){
    int height;

    while (1) {
        height=get_int("Height: ");
        if(height>=1&& height<=8){
            break;
        }
    }
    for(int i=0;i<height;++i){
        for(int j=0;j<height-i-1;++j){
            printf(" ");
        }
        for(int j=0;j<=i;++j){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}