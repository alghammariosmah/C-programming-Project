#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>




void createFile(void)//done
{

    int i;

    for ( i = 0; i < SCREEN_HEIGHT; i++ )

        putchar ( '\n' );//in order to clean the screen.
    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    directory = opendir("./");

    if (directory != NULL && getcwd(Current_path, sizeof(Current_path)) !=NULL)
    {
        fprintf(stdout, "\nYour current working directory: %s \n", Current_path);
        closedir(directory);
    }else{
    perror("\nUnable to find the directory!");
    }
    FILE *NewFile;
    char *file_name = malloc(sizeof(*file_name));
    printf("\nEnter a name of the file you want to create:\n");
    scanf("%s",file_name);

    while(access(file_name, 0) != -1)//in case the file exists

        {

        printf("\n%s file already exists\nplease re_enter your file name or R to go back to the main menu.\n\n", file_name);

        scanf("%s", file_name);

        if(strcmp(file_name,"R")==0)

        {

            free(file_name);

            return;// returning to the main menu

        }

        }

    if(access(file_name, 0) == -1)//if it does not exist

    {

        NewFile = fopen(file_name,"w+");

        fclose(NewFile);

        printf("\nFile has been created successfully! :D\n\nPlease enter R to return to the main menu\n");

        scanf("%s",file_name);

        while (strcmp(file_name,"R")!=0)

        {

            printf("\nIt is not a correct option!\nPlease enter R to return to the main menu\n");
            scanf("%s",file_name);

        }
        if (strcmp(file_name,"R")==0)
        {
            free(file_name);
            return;
        }

    }
}
