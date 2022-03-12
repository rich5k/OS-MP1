#include <stdio.h>
#include <stdlib.h>

//Author: Richard Kafui Anatsui
int main(int argc, char *argv[]){
    //if no arguments are provided
    if(argc<2){
       exit(0);

    //if arguments are provided
    }else{
        for(int i =1; i<argc;i++){
            //buffer
            char line[512];

            //opens file
            FILE * fpointer = fopen(argv[i],"r");
            //if cannot open file
            if (fpointer==NULL){
                printf("wcat: cannot open file\n");
                exit(1);
            }

            //iterates through each line in the file
            //and prints it
            while(fgets(line,512,fpointer)){
                printf("%s",line);
            }


            //closes file after reading
            fclose(fpointer);
        }
    }

    return 0;
}
