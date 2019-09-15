#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //make sure command line argument number is 2
    if (argc==2){
        //check argv[1] is number
        for(int i=0,len=strlen(argv[1]);i<len;++i){
            if(isdigit(argv[1][i]) ){
                //normal case,need do nothing
            }
            else{
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        int key=atoi(argv[1]);
        string plaintext=get_string("plaintext: ");
        for(int i=0,len=strlen(plaintext);i<len;++i){
            //for each char in plaintext,if lowcase or upcase rotate respectively, if not do nothing
            if(islower(plaintext[i])){
                plaintext[i]-=97;
                plaintext[i]=(plaintext[i]+key)%26;
                plaintext[i]+=97;
            }
            else if(isupper(plaintext[i])){
                plaintext[i]-=65;
                plaintext[i]=(plaintext[i]+key)%26;
                plaintext[i]+=65;
            }
        }
        printf("ciphertext: %s\n",plaintext);
    }
    else{
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
