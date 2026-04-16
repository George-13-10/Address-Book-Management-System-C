#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "populate.h"

void listContacts(AddressBook *addressBook) 
{
    // Sort contacts based on the chosen criteria
    printf("\nContact list\n");
    printf("-----------------------------------------------------");
    printf("\nName\t\tPhone number\tMail id\n");
    printf("-----------------------------------------------------\n");

    for(int i=0;i< addressBook->contactCount ;i++)
    {
        printf("%s\t%s\t%s\n",addressBook->contacts[i].name ,addressBook->contacts[i].phone , addressBook->contacts[i].email);
    }
    printf("-----------------------------------------------------\n");

    
}


void initialize(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.txt", "r");

    addressBook->contactCount = 0;

    if (fp == NULL)
    {
        // File not found → load dummy contacts
        populateAddressBook(addressBook);
        return;
    }

    while (fscanf(fp, "%[^,],%[^,],%[^\n]\n",
                  addressBook->contacts[addressBook->contactCount].name,
                  addressBook->contacts[addressBook->contactCount].phone,
                  addressBook->contacts[addressBook->contactCount].email) == 3)
    {
        addressBook->contactCount++;
    }

    fclose(fp);
}


void saveAndExit(AddressBook *addressBook)
{
    FILE *fp = fopen("contacts.txt","w");

    if(fp == NULL)
    {
        printf("\nError saving contacts to file\n");
        return ;
    }

    for(int i = 0;i<addressBook->contactCount; i++)
    {
        fprintf(fp, "%s,%s,%s\n",
            addressBook->contacts[i].name,
            addressBook->contacts[i].phone,
            addressBook->contacts[i].email);
    }
    fclose(fp);

    printf("\nContacts saved sucessfully and exits. \n");    
}


void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    printf("Enter name: ");
    scanf(" %[^\n]",addressBook->contacts[addressBook->contactCount].name);

    printf("Enter mobile no : ");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].phone);

    printf("Enter mail id : ");
    scanf(" %s",addressBook->contacts[addressBook->contactCount].email);
    addressBook->contactCount++;
}

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    char nametobefound[100];
    int found =0;

    printf("Enter name to search: ");
    scanf(" %[^\n]",nametobefound);

    for(int i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(nametobefound, addressBook->contacts[i].name) == 0)
        {
            printf("\n    Contact Details    \n");
            printf("Name : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Mail : %s\n", addressBook->contacts[i].email);
            

            found = 1;
            break;
        
        }
    }
    if(found == 0)
    {
        printf("\nContact details not found\n");
    }
}

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    char nametobeedited[100];
    int found =0;
    int choice;

    printf("Enter the name to edit: ");
    scanf(" %[^\n]", nametobeedited);

    for(int i=0;i<addressBook->contactCount ;i++)
    {
        if(strcmp(nametobeedited, addressBook->contacts[i].name)==0)
        {
            found =1;

            printf("\nEnter what to be edited\n");
            printf("1. Name\n");
            printf("2. Phone\n");
            printf("3. Mail\n");
            printf("Enter choice: ");
            scanf("%d",&choice);

            if(choice == 1)
            {
                printf("Enter new name: ");
                scanf(" %[^\n]", addressBook->contacts[i].name);

            }
            else if (choice == 2)
            {
                printf("Enter new phone: ");
                scanf(" %s", addressBook->contacts[i].phone);
            }
            else if(choice == 3)
            {
                printf("Enter new mail: ");
                scanf("%s", addressBook->contacts[i].email);
            }
            else
            {
                printf("Invalid choice\n");
            }

            
        }

    }
    if(!found)
            printf("\nContact details not found\n");

    
    
}

void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */
    char nametobedeleted[100];
    int found = 0;
    

    printf("Enter the name to be deleted: ");
    scanf(" %[^\n]", nametobedeleted);

    for(int i=0;i<addressBook->contactCount ; i++)
    {
        if(strcmp(nametobedeleted, addressBook->contacts[i].name)==0)
        {
            found =1;

            for(int j=i;j<addressBook->contactCount - 1;j++)
            {
                addressBook->contacts[j] = addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
            printf("\nContact deleted sucessfully.\n");
            break;
        }
    }
    if(found == 0)
    {
        printf("\nContact not found.\n");
        
    }
   
}
