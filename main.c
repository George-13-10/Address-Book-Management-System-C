#include <stdio.h>
#include "contact.h"

int main() {
    AddressBook s;
    initialize(&s); // Initialize the address book
    int choice;

    do{
        printf("\nAddress Book Menu:\n");
        printf("1. Create contact\n");
        printf("2. Edit contact\n");
        printf("3. Search contact\n");
        printf("4. Delete contact\n");
        printf("5. List contact\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice: \n");

        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1:
                createContact(&s);
                break;
            case 2:
                editContact(&s);
                break;
            case 3:
                searchContact(&s);
                break;
            case 4:
                deleteContact(&s);
                break;
            case 5:
                listContacts(&s);
                break;  
            case 6:
                saveAndExit(&s);
                break;
        }
    }
    while (choice != 6);
        return 0;
}
