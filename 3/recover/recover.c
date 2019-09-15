#include <stdio.h>
#include <stdlib.h>

#define FBS 512   //fat filesystem block size

int filenamespp(char *filenames);

int main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(stderr,"Usage: ./recover image\n");
        return 1;
    }
    char* cardfilename=argv[1];
    FILE *pcardraw=fopen(cardfilename,"r");
    if(pcardraw==NULL){
        fprintf(stderr,"Could not open %s.\n",cardfilename);
    }

    char* firstjpgname="001.jpg";
    char filename[8]={'0','0','0','.','j','p','g',0};
    FILE *pjpg=fopen(filename,"w");
    if(pjpg==NULL){
        fclose(pcardraw);
        fprintf(stderr,"Could not create %s\n",filename);
        return 2;
    }
    unsigned char bfOfFatBlock[FBS];

    fread(bfOfFatBlock,FBS,1,pcardraw);

    //make sure pcardraw point first block of first jpg
    while( !(bfOfFatBlock[0]==0xff && bfOfFatBlock[1]==0xd8 && bfOfFatBlock[2]==0xff) ){
        fread(bfOfFatBlock,sizeof(bfOfFatBlock),1,pcardraw);
    }

    fwrite(bfOfFatBlock,FBS,1,pjpg);

    while (1){
        if (fread(bfOfFatBlock,FBS,1,pcardraw)==0){
            break;
        }

        if(bfOfFatBlock[0]==0xff && bfOfFatBlock[1]==0xd8 && bfOfFatBlock[2]==0xff){
            fclose(pjpg);
            filenamespp(filename);
            fopen(filename,"w");
        }
        fwrite(bfOfFatBlock,FBS,1,pjpg);

    }

    fclose(pcardraw);
    fclose(pjpg);
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
