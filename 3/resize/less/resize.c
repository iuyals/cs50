// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int write_line_piexles(FILE *inptr,FILE *outptr,int scale,int biWidth);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }

    int scale=atoi(argv[1]);
    if(scale<=0 || scale>100){
        fprintf(stderr, "Usage: resize n infile outfile\n");
        return 1;
    }
    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    // write outfile's BITMAPINFOHEADER
    BITMAPFILEHEADER resizedbf=bf;
    BITMAPINFOHEADER resizedbi=bi;
    resizedbi.biWidth*=scale;
    resizedbi.biHeight*=scale;
    int resized_padding=(4 - (bi.biWidth * scale * sizeof(RGBTRIPLE)) % 4) % 4;
    resizedbf.bfSize=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+resized_padding*abs(resizedbi.biHeight)+resizedbi.biWidth*abs(resizedbi.biHeight)*sizeof(RGBTRIPLE);
    int newsz=sizeof(RGBTRIPLE)*abs(resizedbi.biHeight)*resizedbi.biWidth+resized_padding*abs(resizedbi.biHeight);
    //printf("%d\n",newsz);
    resizedbi.biSizeImage=newsz;
    fwrite(&resizedbf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&resizedbi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines


    // iterate over infile's scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        write_line_piexles(inptr,outptr,scale,bi.biWidth);

        for(int m=0;m<scale-1;++m){
            fseek(inptr,-(long)( bi.biWidth*sizeof(RGBTRIPLE)+padding ),SEEK_CUR);
            write_line_piexles(inptr,outptr,scale,bi.biWidth);
        }


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}


int write_line_piexles(FILE *inptr,FILE *outptr,int scale,int biWidth){
    int padding = (4 - (biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int resized_padding=(4 - (biWidth * scale * sizeof(RGBTRIPLE)) % 4) % 4;
    // iterate over pixels in scanline
        for (int j = 0; j < biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile
            for(int k=0;k<scale;++k){
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < resized_padding; k++)
        {
            fputc(0x00, outptr);
        }
        return 0;
}