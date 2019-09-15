#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int shift(char c);

int main(int argc, string argv[])
{
    //make sure command line argument number is 2,if not print error message and return 1
    if (argc==2){
        //check argv[1] is pure letters,or return 1
        for(int i=0,len=strlen(argv[1]);i<len;++i){
            if(isalpha(argv[1][i]) ){
                //normal case,need do nothing
            }
            else{
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        int shiftConter=0;
        int key=0;


        // int key=atoi(argv[1]);
        string plaintext=get_string("plaintext: ");
        for(int i=0,len=strlen(plaintext),lenOfArg1=strlen(argv[1]);i<len;++i){
            shiftConter%=lenOfArg1;
            //for each char in plaintext,if lowcase or upcase rotate respectively, if not do nothing
            if(islower(plaintext[i])){
                key=shift(argv[1][shiftConter++]);
                plaintext[i]-=97;
                plaintext[i]=(plaintext[i]+key)%26;
                plaintext[i]+=97;
            }
            else if(isupper(plaintext[i])){
                key=shift(argv[1][shiftConter++]);
                plaintext[i]-=65;
                plaintext[i]=(plaintext[i]+key)%26;
                plaintext[i]+=65;
            }
        }
        printf("ciphertext: %s\n",plaintext);
    }
    else{
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

int shift(char c){
    if(islower(c)){
        return c-97;
    }
    else if(isupper(c)){
        return c-65;
    }
    else{
        return 0;
    }
}
