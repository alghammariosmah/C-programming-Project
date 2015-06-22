#include <stdio.h>
#include <stdlib.h>


void inserttext(void)
{
    int screen;
    for ( screen = 0; screen < SCREEN_HEIGHT; screen++ )
        putchar ( '\n' );

    DIR *directory;
    struct dirent *read_direcory;
    char Current_path[100];
    directory = opendir("./");

    if (directory != NULL && getcwd(Current_path, sizeof(Current_path)) !=NULL)// to show the directory again.
    {
        fprintf(stdout, "\nYour current working directory where the file should exists:\n%s \n", Current_path);
        closedir(directory);
    }else{
    perror("\nUnable to find the directory!");
    }
    FILE *file1,*file2;
    char *f = malloc(100), *t = malloc(100);
    int l,i,r,y,n,index,nl=0;
    int linelength = 0;
    long offset = 0;

    printf("\n\nEnter a text file name:\n");
    scanf("%99s",f);

    while (access(f,0) == -1)//if the text file does not exist
    {

        printf("\n%s File does not exist!\nPlease Re_enter the file name or enter R to return to the main menu\n", f);
        scanf("%s",f);

        if (strcmp(f,"R")==0)
        {
            free(f);
            return;
        }
    }

    if (access(f,0)!=-1)//if the text file exists
    {
        file1=fopen(f, "r+");
        file2=fopen("f2.txt", "w+");
        for ( screen = 0; screen < SCREEN_HEIGHT; screen++ )
            putchar ( '\n' );
        printf("\nThe file before editing:\n\n");
        while((n=fgetc(file1))!=EOF)// to show the contents of the file before the edit
        {
            putchar(n);
        }
        fclose(file1);
        fclose(file2);

        if(access(f,2)!=-1)//if the file has the write permission
        {
            file1=fopen(f, "r+");
            file2=fopen("f2.txt", "w+");

            printf("\n\nPlease enter your text: \n");
            scanf(" %99[^\n]",t);

            printf("\nSpecify the line number where you want to insert:\n");
            printf("\n!!!!Note!!!\nif you don't specify the correct line, it may not add the text!\n\n");
            scanf("%d", &l);

            while((r=fgetc(file1))!=EOF)//copying file1 contents into file2 contents
            {
                fputc(r,file2);
                if(r == '\n' && ++nl == l){
                    offset = ftell ( file1);//save location in file
                    while ( ( r = fgetc ( file1)) != '\n' && r != EOF) {
                        linelength++;//count characters in line
                    }
                    fseek ( file1, offset, SEEK_SET);//seek  back to start of line
                    //get index where to insert text
                    do {
                        printf("\nline index in this line(less than %d):\n", linelength);
                        if ( ( scanf("%d", &index)) != 1) {
                            scanf ( "%*[^\n]");//input not an integer. clear buffer
                            index = linelength;
                        }
                    } while ( index >= linelength || index < 0);

                    while ( index) {
                        r = fgetc ( file1);
                        fputc(r,file2);
                        index--;
                    }
                    fprintf(file2, " %s ", t);//adding the inserted text
                }
            }
            fclose(file1);
            fclose(file2);

            file1=fopen(f, "w+");
            file2=fopen("f2.txt", "r");
            while((y=fgetc(file2))!=EOF){
                fputc(y,file1);
            }
            fclose(file2);
            fclose(file1);
            remove("f2.txt");

            file1=fopen(f, "r");
            printf("\n");
            for ( screen = 0; screen < SCREEN_HEIGHT; screen++ )
                putchar ( '\n' );
            while((i=fgetc(file1))!=EOF)//showing the result after inserting
            {
                putchar(i);
            }
            fclose(file1);
            printf("\n\nText has been inserted successfully:\n\nPlease enter R to return to the main menu!");
            scanf("%s",f);
            while (strcmp(f,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",f);
            }
            if (strcmp(f,"R")==0)//to return to the main menu
            {
                free(f);
                free(t);
                return;
            }
        }
        else{
            printf("\n%s text file does not have the Write Permission!\n\nPlease Enter R to return to the main menu\n", f);
            while (strcmp(f,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",f);
            }
            if (strcmp(f,"R")==0)//to return to the main menu
            {
                free(f);
                free(t);
                return;
            }
        }
    }
}

