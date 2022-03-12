#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Author: Richard Kafui Anatsui
int main(int argc, char * argv[]){
    //if arguments are more than 2
   if(argc>2){
        char *line;
        size_t size= 10;
        line = (char*) malloc(size);
        //iterate through each file
        for(int i=2; i<argc;i++){
            FILE * fpointer = fopen(argv[i],"r");
            //if file cannot be opened
            if (fpointer== NULL){
                printf("wgrep: cannot open file\n");
                exit(1);
            }
            char **line_pointer= &line;

            while(getline(line_pointer,&size,fpointer) != -1){
                //if keyword can be found in line,print
                if(strstr(line,argv[1])!=NULL){
                    printf("%s",line);

                }

            }
//          //close file when done reading
            fclose(fpointer);

        }
    //if only 2 arguments are provided
    }else if( argc ==2){
        char *line;
        size_t size= 10;
        line = (char*) malloc(size);

        char **line_pointer= &line;
        while(getline(line_pointer,&size,stdin) != -1){
                //if keyword can be found in user
                //input, print it
                if(strstr(line,argv[1])!=NULL){
                    printf("%s",line);

                }

            }
    //if no arguments are provided
    }else{
        printf("wgrep: searchterm [file ...]\n");
       exit(1);
    }

    return 0;
}
