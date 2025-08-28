// Author: Mohamad Musadiq
// Description: This is a Contact Management System, in which you can: Create, Add, View, Edit, Search and Delete Contacts.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

// Function to find the S no. of a string in an array of strings
int findStringPosition(char target[], char arr[][20], int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(target, arr[i]) == 0) {
            return i+1;  // Found, return S no.
        }
    }
    return -1; // Not found
}

int main(){
    char names[20][20];
    char numbers[20][20];


    char another = 'y';
    int count = 0;

    for (int i=0; i<20; i++){
        printf("\n(%d) Enter Name and Number: ", i+1);
        scanf("%s%s", names[i], numbers[i]);

        count++;

        printf("Another entry? (y/n): ");
        another = getche();
        if (another == 'n'){
            break;
        }
    }

    while(1) {

        int choice;
        printf("\nChoose an option: \n\t1. Print full list \n\t2. Search for Name\n\t3. Edit Entry\n\t4. Delete an Entry\n\t5. Add new entry\n\t6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);


        if (choice==1){
            printf("\nTotal entries: %d\n", count);
            for (int i=0; i<count; i++){
                printf("\n%d,\t%s\t%s",i+1, names[i],numbers[i]);
            }
        }

        else if (choice==2){
            
            char target[100];

            printf("Enter string to search: ");
            scanf("%s", target);

            int pos = findStringPosition(target, names, count);

            if (pos != -1)
                printf("Found! \n\tS.no: %d\n\tName: %s\n\tNumber: %s\n", pos,names[pos-1],numbers[pos-1]);
            else
                printf("Not found in the list.\n");
            
        }

        else if (choice == 3){
            int sno;
            printf("\nWhich Serial no. do you want to edit?: ");
            scanf("%d", &sno);

            int index = sno-1;
            
            int whichone;
            printf("\nDo you want to change Name(1) or Number(2): ");
            scanf("%d", &whichone);

            if (whichone==1){
                printf("Enter new name: ");
                scanf("%s", names[index]);
            }
            else if (whichone==2){
                printf("Enter new number: ");
                scanf("%s", numbers[index]);
            }
        }

        else if (choice == 4) {
            int no;
            printf("Enter the S.no you want to delete: ");
            scanf("%d", &no);

            int index = no - 1;

            if (index < 0 || index >= count) {
                printf("Invalid S.no!\n");
            } 
            else {
                char del = 'n';
                printf("Deleting Entry:\n\tS.no: %d\n\tName: %s\n\tNumber: %s\n", no, names[index], numbers[index]);
                printf("Are you sure (y/n): ");
                scanf(" %c", &del);
                if (del == 'y'){
                    for (int i = index; i < count - 1; i++) {
                        strcpy(names[i], names[i+1]);              // moving the array elements one step front starting from index.
                        strcpy(numbers[i], numbers[i+1]);
                    }
                    count--;  // reduce total entries, also if user deletes last entry, count-- does the magic
                    printf("Entry deleted!\n");
                }
            }
        }

        else if (choice == 5) {
            printf("\nEnter Name and Number: ");
            scanf("%s%s", names[count], numbers[count]);
            count++;
            printf("Entry Added!");
        }

        else if (choice == 6) {
            printf("Exiting...\n");
            break;
        }
    }

    return 0;
}
