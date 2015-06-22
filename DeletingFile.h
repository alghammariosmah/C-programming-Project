#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>




void deleteFile(void)//done
{

    int i;

    for ( i = 0; i < SCREEN_HEIGHT; i++ )

        putchar ( '\n' );

    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    int counter;
    int status;
    directory = opendir("./");

    if (directory != NULL && getcwd(Current_path, sizeof(Current_path)) !=NULL)
    {
        fprintf(stdout, "\nYour current working directory: %s \n", Current_path);

        counter = 0;

        printf("\nThe files in this directory are\n");

        while ((read_direcory = readdir(directory)) != NULL)//showing the files in the current working directory
            {
                printf("%d %s\n",counter,read_direcory -> d_name);
                counter++;
            }
    closedir(directory);
    }else{
    perror("\nUnable to find the directory!");
    }
    char *file_name = malloc(sizeof(*file_name));


    printf("\nEnter the name,not the number,of the file you want to delete from above.\n");
    scanf("%s",file_name);



    while(access(file_name, 0) == -1 )//in case if it does not exist

        {

        printf("\n%s file does not exist\nplease re_enter your file name or R to go back to the main menu.\n", file_name);

        scanf("%s", file_name);

        if (strcmp(file_name,"R")==0)//it should be working, but I don't know why :(

        {

            free(file_name);

            return;// returning to the main menu

        }

        }



    if (remove(file_name)== 0)//if the name was correct, the removing process shall start.

        {

        printf("\n%s file has been successfully deleted.\n\nPlease Enter R to return to the main menu\n", file_name);

        scanf("%s",file_name);

        while (strcmp(file_name,"R")!=0)

        {

            printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
            scanf("%s",file_name);

        }
        if (strcmp(file_name,"R")==0)
        {
            free(file_name);
            return;
        }
        }
}
