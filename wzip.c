#include <stdio.h>
#include <stdlib.h>
//Author: Richard Kafui Anatsui
int main(int argc, char *argv[]){
    //if arguments are 2 or more
    if (argc>=2){

        int charNum=0;
        int chr=0;
        int chrSwitch=-1;

        //traverse through each file
        for(int i = 1; i<argc; i++){
            FILE* fpointer= fopen(argv[i],"r");
            //if file cannot open
            if (fpointer== NULL){
                printf("wzip: cannot open file\n");
                exit(1);
            }
            //reads each character in file and
            //and returns ascii character
            while((chr= fgetc(fpointer))!=EOF){
                //at the start of the file
                if(chrSwitch==-1){
                    chrSwitch=chr;
                    charNum++;
                //
                }
                //if character occurs again
                //increment counter
                else if(chr==chrSwitch){
                    charNum++;
                }
                //if there is a new character
                //write 4-byte integer and ascii character
                //to binary file
                else if(chr != chrSwitch){
                    fwrite(&charNum,sizeof(int),1, stdout);
                    fputc(chrSwitch,stdout);
                    charNum=1;
                }

                chrSwitch=chr;
            }
            //close file when done
            fclose(fpointer);
        }
        //if character count is not zero
          if(charNum>0)  {
            fwrite(&charNum,sizeof(int),1, stdout);
            fputc(chrSwitch,stdout);
          }

    }


    //if no arguments are given
    else{
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    return 0;
}
