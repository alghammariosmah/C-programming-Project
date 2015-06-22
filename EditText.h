#include <stdio.h>
#include <stdlib.h>

#include "RemoveText.h"
#include "AppendText.h"
#include "InsertText.h"
#include "ShowContent.h"

void helptext(void);

void edittext(void)
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

            printf("\nA.Append Text\n");

            printf("B.Insert Text\n");

            printf("C.Remove text\n");

            printf("D.Show Content\n");

            printf("E.help\n");

            printf("F.Return to the main menu\n");

            printf("Enter choice:\n");

            scanf("   %c", &menu_choice );

            if((menu_choice== 'A') || (menu_choice=='B') || (menu_choice=='C')  || (menu_choice=='D')  || (menu_choice=='E')  || (menu_choice=='F'))

				valid_choice = 1;

			else

				printf("\007Error. Invalid menu choice selected.\n");

        }

        switch( menu_choice ) {

			case 'A' : appendtext();  break;

			case 'B' : inserttext();  break;

			case 'C' : removetext();  break;

			case 'D' : content();    break;

			case 'E' : helptext();    break;

			case 'F' : exit_flag = 1; break;

			default : printf("Error--- Should not occur.\n"); break;

		}

    }
}



void helptext(void)
{
    int i;
    for ( i = 0; i < SCREEN_HEIGHT; i++ )
        putchar ( '\n' );//in order to clean the screen.
    char *c;
    c=malloc(sizeof(char));
    printf("Help Utility\nEnter command that you want to know how to use: (command?) \n");
    printf("\nAppend?\nInsert?\nRemove?\nContent?\n\nEnter your option please:\n");
    scanf("%s", c);
    if(strcmp(c,"Append?")==0 || strcmp(c,"append?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis command append any text at the end of the file.\nAfter entering the file name, then enter the text to append.\n ");
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
    else if(strcmp(c,"Insert?")==0 || strcmp(c,"insert?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis command inserts any text in a specified line and index.\nFirst enter the file name\n,then program will ask which line and index where you want to insert your text\n,then enter text.\n");
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
    else if(strcmp(c,"Remove?")==0 || strcmp(c,"remove?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis command removes everything inside a text file.\nYou just have to enter the file name\n, then it erases everything inside it\nif you have permission.\n");
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
    else if(strcmp(c,"Content?")==0 || strcmp(c,"content?")==0){
        for ( i = 0; i < SCREEN_HEIGHT; i++ )
            putchar ( '\n' );//in order to clean the screen.
        printf("\nThis command shows the content of a text file.\nJust enter the file name\n,then enter the number of lines you want to see.\n");
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




