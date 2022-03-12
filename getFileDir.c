//Author:Richard Kafui Anatsui
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <regex.h>
#include <sys/types.h>
#include <sys/stat.h>

//prints names of files and folders in given directory
void getfNames(char * direc){
    DIR *directory;
    struct dirent *dir;
    directory= opendir(direc);
    if(directory){
        while((dir = readdir(directory))!=NULL){
            printf("%s\n", dir->d_name);
        }
        closedir(directory);
    }
    else
        printf("\nError occurred while opening given directory\n");
}

//prints all files in that directory including ones in subdirectories
void getOnlyFiles(char * direcName, int currentLevel, int maxLevel){
    DIR *directory;

    struct dirent *dir;
    directory= opendir(direcName);
    if(currentLevel++>maxLevel){
        return;

    }
    if(directory!=NULL){
        while((dir=readdir(directory))!=NULL){
            char fPath[1024]="";
            strncpy(fPath, direcName, strlen(direcName));
            if(fPath[strlen(direcName)-1]!='/'){
                strncat(fPath,"/",1);
            }
            strncat(fPath, dir->d_name,strlen(dir->d_name));
            if(strncmp(dir->d_name,".",1)!=0 && strncmp(dir->d_name, "..",2)!=0){
                if(dir->d_type == DT_DIR){
                    getOnlyFiles(fPath,currentLevel,maxLevel);
                }
                //print path if not directory
                else{
                    printf("%s\n",fPath);

                }

            }
        }

    }
    closedir(directory);

}

int main(int argc, char *argv[]){

    char *direcName=".";
    struct stat sb;
    int currentLevel=1;
    int maxLevel=INT_MAX;

    //an argument is provided
    if (argc==2){
        direcName=argv[1];
        printf("Files and Folders in directory:\n");
        getfNames(direcName);
        printf("********************\n");
        printf("\nAll Files in directory including those in subdirectories\n");
        if (stat(direcName, &sb) == -1){
            perror("stat");
            exit(1);
         }



        if (S_ISDIR(sb.st_mode)) {
            getOnlyFiles(direcName, currentLevel, maxLevel);
        }
    }
    //no argument provided
    else{
        printf("Files and Folders in directory:\n");
        getfNames(direcName);
        printf("********************\n");
        printf("\nAll Files in directory including those in subdirectories\n");
         if (stat(direcName, &sb) == -1){
            perror("stat");
            exit(1);
         }



        if (S_ISDIR(sb.st_mode)) {
            getOnlyFiles(direcName, currentLevel, maxLevel);
        }
    }
    return(0);
}
