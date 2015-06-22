#include <stdio.h>
#include <stdlib.h>


void content(void)//done
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

    FILE *pFile;
    char *f = malloc(100);
    int c, l, nl=0;

    printf("\nEnter a text file name:\n");
    scanf("%s",f);

    while (access(f,0) == -1)//if the file does not exist
    {

        printf("\n%s File does not exist!\nPlease Re_enter the file name or enter R to return to the main menu\n", f);
        scanf("%s",f);

        if (strcmp(f,"R")==0)
        {
            free(f);
            return;
        }
    }

    if (access(f,0)!=-1)//if the file exists
    {
        if (access(f,4)!=-1)//if it is writable
        {
            printf("\nSpecify the number of the lines that will be shown: ");
            scanf("%d", &l);

            for ( i = 0; i < SCREEN_HEIGHT; i++ )
                putchar ( '\n' );

            pFile=fopen(f, "r+");
            while((c=fgetc(pFile))!=EOF){
                putchar(c);
                if(c == '\n' && ++nl == l)
                    break;
            }
            while (1)
            {
                printf("\n\nPlease enter any key to show more lines or R to return to the main menu\n");
                scanf("%s",f);

                if (strcmp(f,"R")==0)
                {
                free(f);
                fclose(pFile);
                return;
                }
                for ( i = 0; i < SCREEN_HEIGHT; i++ )
                    putchar ( '\n' );

                l+=l;
                while((c=fgetc(pFile))!=EOF){
                    putchar(c);
                    if(c == '\n' && ++nl == l)
                        break;
                }
            }
        }else{
            printf("\n%s text file does not have the Write Permission!\n\nPlease Enter R to return to the main menu\n", f);
            while (strcmp(f,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",f);
            }
            if (strcmp(f,"R")==0)//to return to the main menu
            {
                free(f);
                return;
            }
        }
    }
}
