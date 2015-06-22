#include <stdio.h>
#include <stdlib.h>


void appendtext(void){
    int o;
    for ( o= 0; o< SCREEN_HEIGHT; o++ )
        putchar ( '\n' );

    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    directory = opendir("./");

    if (directory != NULL && getcwd(Current_path, sizeof(Current_path)) !=NULL)
    {
        fprintf(stdout, "\nYour current working directory where the file should exists: %s \n", Current_path);
        closedir(directory);
    }else{
    perror("\nUnable to find the directory!");
    }
    FILE *pFile;
    FILE *pFile2;
    char *buffer = malloc(100);
    char fn[50], f[20];
    int i;
    printf("\n\nEnter a text file name:\n");
    scanf("%s",fn);
    if (access(fn,0)!=-1){   //if file exists
        if (access(fn,2)!=-1){   //if file has write permission
            pFile=fopen(fn, "a");
            printf("Enter a text ->\n");

            scanf(" %[^\n]s ",buffer);
            if (buffer[0]!='\0'){
                fprintf(pFile,"\r\n" );
                fprintf(pFile, "%s", buffer);
            }
            fclose(pFile);

            while(1)
            {
                pFile=fopen(fn, "a");
                for ( o= 0; o< SCREEN_HEIGHT; o++ )
                    putchar ( '\n' );
                printf("\nText Added Succcessfully.\n");
                printf("Enter another text or R to return to the main menu->\n");
                scanf(" %[^\n]s ",buffer);
                if(strcmp(buffer,"R")==0){
                    fclose(pFile);
                    free(buffer);
                    return;
                }
                if (buffer[0]!='\0'){
                    fprintf(pFile,"\r\n" );
                    fprintf(pFile, "%s", buffer);
                    fclose(pFile);
                }
            }
        }
        else{  //if file does not have write permission
           printf("\n%s text file does not have the Write Permission!\n\nPlease Enter R to return to the main menu\n", fn);
            while (strcmp(fn,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",fn);
            }
            if (strcmp(fn,"R")==0)//to return to the main menu
            {
                free(buffer);
                return;
            }
        }
    }
    else{  //if file does not exist
        printf("File does not exist. Do you want to open a new file? Y/N \n");
        scanf("%s", fn);
        if(strcmp(fn,"Y") == 0){
            printf("\nEnter the name for your text file:\n ");
            scanf("%s",f);
            pFile2=fopen(f, "w+");
            fclose(pFile2);
            pFile2=fopen(f, "a");
            printf("Enter a text ->\n ");
            scanf(" %[^\n]s ",buffer);
            if (buffer[0]!='\0'){
                fprintf(pFile2,"\r\n" );
                fprintf(pFile2, "%s", buffer);
            }
            fclose(pFile2);


            while(1)
            {
                pFile2=fopen(f, "a");
                printf("\nText Added Succcessfully.\n");
                printf("Enter another text or R to return to the main menu->\n ");
                scanf(" %[^\n]s ",buffer);
                if(strcmp(buffer,"R")==0){
                    fclose(pFile2);
                    pFile2=fopen(f, "r");
                    while((i=fgetc(pFile2))!=EOF)//to show the content
                    {
                        putchar(i);
                    }
                    fclose(pFile2);
                    return;
                }
                if (buffer[0]!='\0'){
                    fprintf(pFile2,"\r\n" );
                    fprintf(pFile2, "%s", buffer);
                    fclose(pFile2);
                }
            }
        }
        else if(strcmp(fn,"N") == 0){
            return;
        }
    }
    free(buffer);
}
