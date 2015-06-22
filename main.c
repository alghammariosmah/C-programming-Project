#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/param.h>

#define SCREEN_HEIGHT 25
#include "CreatingFile.h"
#include "DeletingFile.h"
#include "RenameFile.h"
#include "CopyFile.h"
#include "MoveFile.h"
#include "EditText.h"

void helpfile(void);


int main ()
{

    int exit_flag = 0, valid_choice,i;

    char menu_choice;

    while (exit_flag == 0)

    {

        valid_choice = 0;

        while( valid_choice == 0)

        {

            for ( i = 0; i < SCREEN_HEIGHT; i++ )

                putchar ( '\n' );

            printf("\nNote:It is a key sensitive program!\nWhat do you want to do?\n");

            printf("\nA.Create a File\n");

            printf("B.Delete a File\n");

            printf("C.Rename a File\n");

            printf("D.Copy a File\n");

            printf("E.Move a File\n");

            printf("F.Text file menu\n");

            printf("G.Help\n");

            printf("H.Exit\n");

            printf("Enter choice:\n");

            scanf("   %c", &menu_choice );

            if((menu_choice== 'A') || (menu_choice=='B') || (menu_choice=='C')  || (menu_choice=='D')  || (menu_choice=='E')  || (menu_choice=='F') || (menu_choice=='G') || (menu_choice=='H'))

				valid_choice = 1;

			else

				printf("\007Error. Invalid menu choice selected.\n");

        }

        switch( menu_choice ) {

			case 'A' : createFile();  break;

			case 'B' : deleteFile();  break;

			case 'C' : renameFile();  break;

			case 'D' : copyFile();    break;

			case 'E' : MoveFile();    break;

			case 'F' : edittext(); break;

			case 'G' : helpfile(); break;

			case 'H' : exit_flag = 1; break;

			default : printf("Error--- Should not occur.\n"); break;

		}

    }
}




void helpfile(void)
{
    int i;
    for ( i = 0; i < SCREEN_HEIGHT; i++ )
        putchar ( '\n' );//in order to clean the screen.
    char *c;
    c=malloc(sizeof(char));

    printf("Help Utility\nEnter the command that you want to know how to use: (command?) \n");
    printf("\nCreate?\nDelete?\nRename?\nCopy?\nMove?\n\nEnter your option please:\n");
    scanf("%s", c);
    if(strcmp(c,"Create?")==0 || strcmp(c,"create?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis function creates a file in your current working directory.\nAll you have to do is to name your file then it will show you the result\nwhether the file exists or not\n");
        printf("\n\nYou can always return to the main menu by entering R\n");
        scanf("%s", c);
        while (strcmp(c,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",c);
            }
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
            {
                free(c);
                return;// returning to the main menu
            }
    }
    else if(strcmp(c,"Delete?")==0 || strcmp(c,"delete?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis function deletes any file you specify in your current working directory\n");
        printf("\n\nYou can always return to the main menu by entering R\n");
        scanf("%s", c);
        while (strcmp(c,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",c);
            }
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
            {
                free(c);
                return;// returning to the main menu
            }
    }
    else if(strcmp(c,"Rename?")==0 || strcmp(c,"rename?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis function renames any file you specify in your current working directory\n");
        printf("\n\nYou can always return to the main menu by printing R\n");
        scanf("%s", c);
        while (strcmp(c,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",c);
            }
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
            {
                free(c);
                return;// returning to the main menu
            }
    }
    else if(strcmp(c,"Copy?")==0 || strcmp(c,"copy?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis function copies any file you specify from/to any directory you specify.\n");
        printf("\nYou can always return to the main menu by printing R\n");
        scanf("%s", c);
        while (strcmp(c,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",c);
            }
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
            {
                free(c);
                return;// returning to the main menu
            }
    }
    else if(strcmp(c,"Move?")==0 || strcmp(c,"move?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis function moves any file you specify from/to any directory you specify.\n");
        printf("\nYou can always return to the main menu by printing R\n");
        scanf("%s", c);
        while (strcmp(c,"R")!=0)
            {
                printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
                scanf("%s",c);
            }
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
            {
                free(c);
                return;// returning to the main menu
            }
    }
    while (1)
        {
            printf("\nIt is not a correct option!\nPlease Enter R to return to the main menu\n");
            scanf("%s",c);
        if (strcmp(c,"R")==0)//it should be working, but I don't know why :(
        {
            free(c);
            return;// returning to the main menu
        }
        }
}




