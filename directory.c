#include <dirent.h>
#include <stdio.h>
#include<string.h>
#include<sys/types.h>
#include<conio.h>
#include <sys/stat.h>
#include <errno.h>


// *****************    GLOBAL VARIABLES ***********************
int level=-1,i,directorycounter=0,filecounter=0,size;
//**************************************************************


int isDirectory(const char *path) {
    struct stat statbuf;

   if (stat(path, &statbuf) != 0)
       return 0;
   return S_ISDIR(statbuf.st_mode);
}
int sizeoffile(const char *path){
    struct stat statbuf;
   if(stat(path, &statbuf)!=0)
        return 0;
return (statbuf.st_size);
}

void printtree(char path[]){
    strcat(path,"/");
    struct dirent *dir;
    DIR *d;

    d = opendir(path);
    level++;
     while ((dir = readdir(d)) != NULL)
        {
            char a[1000]="";

            if(strcmp("..",dir->d_name)==-1&&strcmp(".",dir->d_name)==-1){


                for(i=0;i<level;i++)
                printf("  ");
            printf("|");

                printf("--%s\n", dir->d_name,level);
                strcat(a,path);
                strcat(a,dir->d_name);
                if(isDirectory(a)){
                    directorycounter++;
                }
                else
                    filecounter++;
                printtree(a);
            }
        }
    closedir(d);
    level--;
}
int main()
{
    DIR *d;
    char path[100]="../Algorithms";
    if (d)
    {
        printtree(path);
        printf("%i directories , %i files ",directorycounter,filecounter);
    }
    return(0);

}
