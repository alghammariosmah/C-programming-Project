#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void renameFile(void)//done
{

    int i;

    for ( i = 0; i < SCREEN_HEIGHT; i++ )

        putchar ( '\n' );


    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    int counter;
    char old_name[50],new_name[50];

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


    printf("\nEnter the name,not the number, of the file you want to rename.\n");
    scanf("%s", old_name);



    while(access(old_name, 0) == -1 )//in case if it does not exist

        {

        printf("\n%s file does not exist\nplease re_enter your file name or R to go back to the main menu.\n", old_name);

        scanf("%s", old_name);

        if (strcmp(old_name,"R")==0)//it should be working, but I don't know why :(

        {
            return;// returning to the main menu
        }

        }

    if (access(old_name, 0) != -1)//If it exists.

        {

        printf("\nEnter the new name for %s file.\n", old_name);
        scanf("%s", new_name);

        while(access(new_name, 0) != -1 )//in case if the new name exists
        {
        printf("\n%s file name already exists\nplease re_enter your file name or R to go back to the main menu.\n", new_name);
        scanf("%s", new_name);

        if (strcmp(new_name,"R")==0)//it should be working, but I don't know why :(
        {
            return;// returning to the main menu
        }
        }
        if ((rename(old_name,new_name))== 0)//Renaming the old one with the new name.
        {
            printf("\n%s file has been successfully renamed to %s.\n\nPlease Enter R to return to the main menu\n", old_name, new_name);
            scanf("%s",old_name);
        while (strcmp(old_name,"R")!=0)
        {
            printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
            scanf("%s",old_name);
        }
        if (strcmp(old_name,"R")==0)//it should be working, but I don't know why :(
        {
            return;// returning to the main menu
        }
        }
        }
}
