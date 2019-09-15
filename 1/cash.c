#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){
    float dolloars;

    //get dolloars from user input,if a good input then go out of loop
    while(1){
        dolloars=get_float("Change owed: ");
        if (dolloars>=0){
            break;
        }
    }

    //chage dolloars to cents
    int cents=round(dolloars*100);
    int conters=0;


    while (cents>0){
        if(cents>=25){
            conters++;
            cents-=25;
        }
        else if(cents>=10){
            conters++;
            cents-=10;
        }
        else if(cents>=5){
            conters++;
            cents-=5;
        }
        else if(cents>=1){
            conters++;
            cents-=1;
        }
    }
    printf("%i\n",conters);
}