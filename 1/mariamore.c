#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height=0;
    while(height<=0 || height>8){
        printf("Height: ");
        scanf("%i",&height);
        printf("%i\n",height);
    }
    int i=0;
    for(i=0;i<height;++i){
        int j=0;
        for(j=0;j<height-i-1;++j){
            printf(" ");
        }
        for(j=0;j<=i;++j){
            printf("#");
        }
        printf("  ");
        for(j=0;j<=i;++j){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
