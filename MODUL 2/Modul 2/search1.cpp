#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    char firstName [15];
    char lastName [15];
    char Number [15];
    char searchName [15];
    struct Node *next;
} ;

struct Node *Head = NULL;

int printInfoRecieveOption () ;
void clearScreen () ;
void insertEntry ();
void printAll ();
void findEntry (char name []) ;
void deleteEntry () ;


int main ()
{
    int restart, userOption, otherOption, check, findUser;
    char userName [15];

    do{
    userOption = printInfoRecieveOption ();
    if(userOption == 1)
       {
          insertEntry ();
          printf("Contact Added Successfuly!\n\n\n");
       }
    else if(userOption == 2)
       {
          printf("Lookup A Contact\n");
          printf("___________________\n");
          printf("Please Enter The Last Name Of The Contact You Are Trying To Find\n");
          scanf("%s", &userName);
          getchar () ;
          clearScreen () ;
          printf("Contact To Find: %s\n", userName);
          printf("Is This Correct?\n");
          printf("(1) Yes\n");
          printf("(2) No\n");
          scanf("%i", &otherOption);
          getchar () ;
          clearScreen () ;
          if(otherOption > 2 || otherOption < 1)
            check = 3;
          else if(otherOption == 1 || otherOption == 2)
            check = 1;
          while(check == 3)
               {
          printf("Contact To Find: %s\n", userName);
          printf("Is This Correct?\n");
          printf("(1) Yes\n");
          printf("(2) No\n");
          scanf("%i", &otherOption);
          getchar () ;
          clearScreen () ;
          if(otherOption > 2 || otherOption < 1)
            check = 3;
          else if(otherOption == 1 || otherOption == 2)
            check = 1;
              }

           findEntry (userName) ;
       }
    else if(userOption == 3)
       {
          deleteEntry () ;
       }
    else if(userOption == 4)
       {
          printAll ();
       }
    }  while(userOption != 5);
    if(userOption == 5)
    {
      clearScreen () ;
      printf("Goodbye!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
      system("pause");
      return 0;
    }

}


void deleteEntry ()
{
   struct Node *curr = Head;
   char name [15], decide;
   int Decide;
   printf("Last Name To Delete\n");
   scanf("%s", &name);
   getchar ();
   while(curr != NULL)
      {
         if(curr->lastName == name)
           {
              printf("First Name: %s\n", curr->firstName);
              printf("Last Name: %s\n", curr->lastName);
              printf("Phone Number: %s\n", curr->Number);
              printf("Is This The Person You Would Like To Delete ? <Y/N>\n");
              scanf("%c", &decide);
              getchar ();

              if(decide == 'y' || decide == 'Y')
              Decide = 1;

              if(Decide == 1)
                free(curr);
           }
         curr = curr->next;
      }
}


void findEntry (char name [])
{
    struct Node *current = Head;
    char Name [15];
    int find = 0;

	if (current == NULL)
	{
		printf("----------------------------------------\n");
        printf("There Are No Contacts In The Phonebook\n");
        printf("----------------------------------------\n");
	}
	else
	{
		while (current != NULL)
		{
            strncpy(Name,current->lastName , sizeof(current->lastName));
            if(name == Name)
            {
            find = 1;
            }
			current = current ->next;
		}
	}

	if(find == 1)
    printf("Contact Was Found\n");
	else if(find != 1)
	printf("Contact Was Not Found\n");
}







void printAll ()
{
     	struct Node *current = Head;

	if (current == NULL)
	{
		printf("----------------------------------------\n");
        printf("There Are No Contacts In The Phonebook\n");
        printf("----------------------------------------\n");
	}
	else
	{
		while (current != NULL)
		{
            printf("| First Name: %s\n", current->firstName);
			printf("| Last Name: %s\n", current->lastName);
			printf("| Phone Number: %s\n\n\n", current->Number);
			current = current ->next;
		}
	}

	printf("\n");

}






void insertEntry ()
{
     char first [15], last [15], number [15];
     int option1, option2, check;

     do{
     printf("Add A Contact\n");
     printf("_________________\n");
     printf("Please Enter Contacts First Name : ");
           scanf("%s", &first);
           getchar ();
           printf("\n");
     printf("Please Enter Contacts Last Name : ");
           scanf("%s", &last);
           getchar ();
           printf("\n");
     printf("Please Enter Contacts Phone Number (XXX-XXX-XXXX) : ");
           scanf("%s", &number);
           getchar ();
           clearScreen () ;
     printf("The Following Entry Will Be Added :\n");
            printf("First Name: %s\n", first);
            printf("Last Name: %s\n", last);
            printf("Phone Number: %s\n", number);
            printf("________________________\n");
            printf("Add This To The Phonebook ? \n");
            printf("( 1 ) Yes\n");
            printf("( 2 ) No\n");
            scanf("%i", &option1);
            getchar () ;
     clearScreen () ;
     if(option1 == 1 || option1 == 2)
     check = 2;
     else if(option1 > 2 || option1 < 1)
     check = 3;
     while(check == 3)
     {
        printf("ERROR: Please Use Either 1 For Yes or 2 For No\n");
        printf("First Name: %s\n", first);
        printf("Last Name: %s\n", last);
        printf("Phone Number: %s\n", number);
        printf("________________________\n");
        printf("Add This To The Phonebook ? \n");
        printf("( 1 ) Yes\n");
        printf("( 2 ) No\n");
        scanf("%i", &option1);
        getchar () ;
        clearScreen ();
        if(option1< 1 || option1 > 3)
        check = 3;
        else if(option1 == 1 || option1 == 2)
        check = 1;
     }
} while(option1 == 2);
//---------------------------------------------------------------------------

     	struct Node *temp;
	temp = (struct Node *) malloc (sizeof(struct Node));

	if (temp != NULL)
	{
		strncpy(temp->firstName, first, sizeof(temp->firstName));
		strncpy(temp->lastName, last, sizeof(temp->lastName));
		strncpy(temp->Number, number, sizeof(temp->Number));

		if (Head == NULL)
		{
			Head = temp;
			Head -> next = NULL;
		}
		else
		{
			temp->next = Head;
			Head = temp;
		}
	}
}






int printInfoRecieveOption ()
{
    int restart;
    printf("1. Add A Contact\n");
    printf("2. Lookup A Contact\n");
    printf("3. Delete A Contact\n");
    printf("4. Display The Entire Phonebook\n");
    printf("5. Exit The Program\n");
    printf("_____________________________________\n");
    printf("What Would You Like To Do ?\n");
    scanf("%i", &restart);
    getchar () ;
    clearScreen () ;
    while(restart > 5 || restart <1)
    {
       printf("PLEASE USE THE NUMBERS 1 - 5\n");
       printf("1. Add A Contact\n");
       printf("2. Lookup A Contact\n");
       printf("3. Delete A Contact\n");
       printf("4. Display The Entire Phonebook\n");
       printf("5. Exit The Program\n");
       printf("_____________________________________\n");
       printf("What Would You Like To Do ?\n");
       scanf("%i", &restart);
       getchar () ;
       clearScreen () ;
    }

    return restart;
}


void clearScreen ()
{
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
