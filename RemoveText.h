#include <stdio.h>
#include <stdlib.h>



void removetext(void)//done
{
    int i;
    for ( i = 0; i < SCREEN_HEIGHT; i++ )
        putchar ( '\n' );

    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    directory = opendir("./");

    if (directory != NULL && getcwd(Current_path, sizeof(Current_path)) !=NULL)
    {
        fprintf(stdout, "\nYour current working directory where the file should exists:\n%s \n", Current_path);
        closedir(directory);
    }else{
    perror("\nUnable to find the directory!");
    }
    FILE *File;
    char *fn;
    fn=malloc(sizeof(char));

    printf("\nEnter a text file name:\n");
    scanf("%s",fn);

    while (access(fn,0) == -1)//if the file does not exist
    {

        printf("\n%s File does not exist!\nPlease Re_enter the file or enter R to return to the main menu\n", fn);
        scanf("%s",fn);

        if (strcmp(fn,"R")==0)
        {
            free(fn);
            return;
        }

    }
    if (access(fn,0)!=-1)// if the file exists.
    {
        if (access(fn,2)!=-1) // if the file writable
        {
            File=fopen(fn,"w+");
            fclose(File);
            printf("\n%s's text has been removed successfully! :D\n\nPlease Enter R to return to the main menu\n", fn);
            scanf("%s",fn);

            while (strcmp(fn,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",fn);
            }
            if (strcmp(fn,"R")==0)//to return to the main menu
            {
                free(fn);
                return;
            }
        }
        else{
            printf("\n%s text file does not have the Write Permission!\n\nPlease Enter R to return to the main menu\n", fn);
            while (strcmp(fn,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",fn);
            }
            if (strcmp(fn,"R")==0)//to return to the main menu
            {
                free(fn);
                return;
            }
        }
    }
}
