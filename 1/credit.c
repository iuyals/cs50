#include <stdio.h>
#include <cs50.h>





int main(){
    long number;
    number=get_long("Number: ");
    long fact=1;
    long sum=0;
    long currentNumber=0;
    int highest2Digit=0;
    int digitCounter=0;
    while(number>0){
        ++digitCounter;
        currentNumber=number%10*fact;
        if (currentNumber<10){
            sum+=currentNumber;
        }
        else{
            sum+=currentNumber%10+currentNumber/10;
        }
        number/=10;
        if (fact==1){
            fact=2;
        }
        else if(fact==2){
            fact=1;
        }
        else{}
        if(number>=10&& number<100){
            highest2Digit=number;
        }
    }
    if(sum%10==0 && (digitCounter==16 || digitCounter==15) ){
        switch(highest2Digit){
            case 37:
            case 34:
                printf("AMEX\n");
                break;
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                printf("MASTERCARD\n");
                break;
            default:
                if(highest2Digit/10==4){
                    printf("VISA\n");
                }
                else{
                    printf("INVALID\n");
                }
        }
    }
    else{
        printf("INVALID\n");
    }
    return 0;
}