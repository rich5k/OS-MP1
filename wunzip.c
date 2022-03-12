#include <stdio.h>
#include <stdlib.h>

//Author: Richard Kafui Anatsui
int main(int argc, char *argv[]){
    //if more than one argument is provided
    if (argc>2){
        int charNum;
        //iterate through each file
        for(int i = 1;i<argc;i++){
            FILE *fp;
            int letter;
            fp=fopen(argv[i],"r");
            //if file did not open
            if(fp==NULL){
                printf("\nwunzip:cannot open file");
                exit(1);
            }
            //reads binary data in file
            while(fread(&charNum,sizeof(int),1,fp)){
                //gets characters from binary file
                letter=fgetc(fp);
                //prints the number of occurrences
                //of a character
                for(int j= 0; j<charNum;j++){
                    printf("%c",letter);

                }
            }
            //close file when done
            fclose(fp);
        }
    //if only one argument
    }else if(argc==2){
        int charNum;
        FILE *fp;
        int letter;
        //opens file
        fp=fopen(argv[1],"r");
        //if file cannot open
        if(fp==NULL){
            printf("\nwunzip:cannot open file");
            exit(1);
        }
        //reads data from binary file
        while(fread(&charNum,sizeof(int),1,fp)){
            //gets a character from file
            letter=fgetc(fp);
            //prints the number of occurrences
            //of a character
            for(int j= 0; j<charNum;j++){
                printf("%c",letter);

            }
        }
        //close file when done
        fclose(fp);

    //if no argument have been given
    }else{
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    return 0;
}
