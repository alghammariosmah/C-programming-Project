#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>





void MoveFile(void)
{
    int i;
    for ( i= 0; i< SCREEN_HEIGHT; i++ )

        putchar ( '\n' );

    DIR *directory;
    FILE *file1, *file2;
    struct dirent *read_direcory;
    char *file_name = malloc(sizeof(*file_name)), buffer[50],Current_path[100];
    char destination_path[50], relocating_path[50],buffer1[100], buffer3[50];

    int counter,r;
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
    printf("\nEnter just the name of the file you wish to move (e.g) file.txt\n");
    scanf("%s",file_name);
    sprintf(buffer, "\%s", file_name);

    printf("\nWrite the directory where %s file is located \n(for example) %s/ \n", file_name, Current_path);
    scanf("%s", relocating_path);
    sprintf(buffer1, "%s%s",relocating_path, buffer);

    while(access(buffer1, 0) == -1 )//in case if it does not exist

        {
        printf("\n%s file does not exist\nplease re_enter %s's location or R to go back to the main menu.\n", file_name, file_name);
        scanf("%s", relocating_path);
        if (strcmp(relocating_path,"R")==0)//it should be working, but I don't know why :(
        {
            free(file_name);
            return;// returning to the main menu
        }
        sprintf(buffer1, "%s%s",relocating_path, buffer);
        }


    printf("\nWrite the name of the directory where you want to move your file to\n(for example) %s/Pictures/ \n", Current_path);
    scanf("%s", destination_path);//file_name
    sprintf(buffer3,"%s%s",destination_path,buffer);

    while(access(buffer3, 0) != -1)//If the file exists in the destination directory
    {
        printf("\n%s file name already exists\nplease re_enter the name of the directory where you want to copy your file to or R to go back to the main menu.\n", file_name);
        scanf("%s", destination_path);//file_name
        if (strcmp(destination_path,"R")==0)
        {
            return;// returning to the main menu
        }
        sprintf(buffer3,"%s%s",destination_path,buffer);
    }
    if (access(buffer3, 0)==-1)
    {
        file1 = fopen(buffer1,"rb");
        file2 = fopen(buffer3,"wb");
        while((r=fgetc(file1))!=EOF)//copying file1 contents into file2 contents
            {
                fputc(r,file2);
            }
        fclose(file1);
        fclose(file2);
        remove(buffer1);
        printf("Copying the %s file was successful! :D\n\nPlease enter R to return to the main menu\n", file_name);
        scanf("%s", file_name);
        while (strcmp(file_name,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",file_name);
            }
        if (strcmp(file_name,"R")==0)
            {
                free(file_name);
                return;// returning to the main menu
            }
    }

    while (strcmp(destination_path,"R")!=0)
        {
            printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
            scanf("%s",destination_path);
        }
    if (strcmp(destination_path,"R")==0)//it should be working, but I don't know why :(
        {
            free(file_name);
            return;// returning to the main menu
        }
}
