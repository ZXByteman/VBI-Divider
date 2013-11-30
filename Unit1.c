#define _LARGEFILE_SOURCE 1
#define _LARGEFILE64_SOURCE 1
#define _FILE_OFFSET_BITS   64

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <io.h>

int main(int argc, char* argv[])
{
    double b,current=0;
    char rd;
    long a=0,  i=0, k=0, e=0, fl=1;
    long c = 0;
    FILE *inputFile, *outputFile;
    char filename[200];
    HANDLE *hFile;
    LPDWORD lpNumberOfBytesRead;

    inputFile = fopen("D:\\vbi\\ÎÐÒ6\\6.vbi", "rb");
 /* hFile =  CreateFile(

    TEXT("d:\\vbi\\full1.vbi"),	// pointer to name of the file
    GENERIC_READ	,	// access (read-write) mode
    0,	// share mode
    NULL,	// pointer to security attributes
    OPEN_EXISTING	,	// how to create
    0,	// file attributes
    NULL 	// handle to file with attributes to copy
   );	                                        */

    i=0;

    c = 0;

    while (1)
    {
        if (fl == 1)
        {
            fl = 0;
            sprintf(filename, "D:\\vbi\\ÎÐÒ6\\vbi\\%08d.vbi", c);
            outputFile = fopen(filename, "wb");
        }

        while (i < 1440)
        {
            if (feof(inputFile)/*!ReadFile(hFile, &rd, sizeof(rd), lpNumberOfBytesRead, NULL)*/)
            {
                //CloseHandle(hFile);
                fclose(inputFile);
                fclose(outputFile);
                return 0;
            }
            rd = fgetc(inputFile);

            if (//(a == 5) ||
                //(a == 6) ||
                //(a == 7) ||
                //(a == 8) ||
                //(a == 9) ||
                //(a == 12)||
                  (a == 13)||
                  (a == 14))
            {
                fputc(rd, outputFile);
            }
            i++;

        }
        if (//(a == 5) ||
            //(a == 6) ||
            //(a == 7) ||
            //(a == 8) ||
            //(a == 9) ||
            //(a == 12)||
              (a == 13)||
              (a == 14))
        {
            current++;
        }
        i = 0;
        if (a==16)
            a = 0;
        else
            a++;

        if (current == 32)
        {
            current = 0;
            c++;
            fclose(outputFile);
            fl = 1;
        }
    }
}
//---------------------------------------------------------------------------
