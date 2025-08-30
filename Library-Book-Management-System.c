// Author: Mohamad Musadiq
// Description: Full Array Based - Library Book Management System with full CRUD Functionality (Add New Book, Search for books, Edit a book, Update/Edit a book, Delete a book, Print all books, Sort (alphabetically/price) wtc...


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book {
    int bid;
    char name[30];
    char author[30];
    int price;
    int amount;
};

int titles = 0;
int nextBid = 1; // auto-incrementing BID

/* helper: consume leftover characters up to newline */
void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* helper: safe line read (removes trailing newline) */
void read_line(char *buf, int size) {
    if (fgets(buf, size, stdin) == NULL) {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

/* find index by name, -1 if not found */
int find_by_name(struct book b[], const char *name) {
    for (int i = 0; i < titles; i++) {
        if (strcmp(b[i].name, name) == 0) return i;
    }
    return -1;
}

int main() {
    struct book b[100];

    while (1) {
        int option;
        printf("\nMENU:\n"
               "\t1. Add New Titles\n"
               "\t2. Print all available books\n"
               "\t3. Edit a Title\n"
               "\t4. Search for a book (by name)\n"
               "\t5. Print Sorted Table (By name)\n"
               "\t6. Print Sorted Table (By price)\n"
               "\t7. Delete a book\n"
               "\t8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        clear_input_buffer(); // remove newline left by scanf

        if (option == 1) {
            int num;
            printf("How many books do you want to add?: ");
            if (scanf("%d", &num) != 1) {
                printf("Invalid number.\n");
                clear_input_buffer();
                continue;
            }
            clear_input_buffer();

            for (int i = 0; i < num; i++) {
                int pos = titles; // insert at end
                if (pos >= 100) {
                    printf("Storage full. Cannot add more books.\n");
                    break;
                }

                b[pos].bid = nextBid++;
                printf("\n\t-- Book %d (ID: %d) --\n", pos + 1, b[pos].bid);

                printf("Book Name: ");
                read_line(b[pos].name, sizeof b[pos].name);

                printf("Book Author: ");
                read_line(b[pos].author, sizeof b[pos].author);

                printf("Book Price: ");
                if (scanf("%d", &b[pos].price) != 1) { b[pos].price = 0; }
                printf("Book Amount: ");
                if (scanf("%d", &b[pos].amount) != 1) { b[pos].amount = 0; }
                clear_input_buffer();

                titles++;
                printf("Book Added!\n");
            }
        }

        else if (option == 2) {
            if (titles == 0) {
                printf("No Titles added yet! Add new titles to print data.\n");
            } else {
                printf("\n%-6s | %-30s | %-30s | %-6s | %-6s\n", "BID", "Book Name", "Author", "Price", "Amount");
                printf("-------------------------------------------------------------------------------------\n");
                for (int i = 0; i < titles; i++) {
                    printf("%-6d | %-30s | %-30s | %-6d | %-6d\n",
                           b[i].bid, b[i].name, b[i].author, b[i].price, b[i].amount);
                }
            }
        }

        else if (option == 3) {
            char bookname[30];
            printf("Name of the book you want to edit: ");
            read_line(bookname, sizeof bookname);

            int index = find_by_name(b, bookname);
            if (index == -1) {
                printf("Book not found!\n");
                continue;
            }

            int info;
            printf("What info do you want to update? (1-Name/2-Author/3-Price/4-Amount): ");
            if (scanf("%d", &info) != 1) {
                printf("Invalid option.\n");
                clear_input_buffer();
                continue;
            }
            clear_input_buffer();

            if (info == 1) {
                printf("Enter New book name: ");
                read_line(b[index].name, sizeof b[index].name);
                printf("Name updated.\n");
            }
            else if (info == 2) {
                printf("Enter New Author of Book (%s): ", b[index].name);
                read_line(b[index].author, sizeof b[index].author);
                printf("Author updated.\n");
            }
            else if (info == 3) {
                printf("Enter New Price of Book (%s): ", b[index].name);
                if (scanf("%d", &b[index].price) != 1) b[index].price = 0;
                clear_input_buffer();
                printf("Price updated.\n");
            }
            else if (info == 4) {
                printf("Enter New Amount of Book (%s): ", b[index].name);
                if (scanf("%d", &b[index].amount) != 1) b[index].amount = 0;
                clear_input_buffer();
                printf("Amount updated.\n");
            } else {
                printf("Invalid choice.\n");
            }
        }

        else if (option == 4) {
            char bookname[30];
            printf("Search book (name): ");
            read_line(bookname, sizeof bookname);

            int index = find_by_name(b, bookname);
            if (index == -1) {
                printf("Book not found!\n");
            } else {
                printf("\n%-6s | %-30s | %-30s | %-6s | %-6s\n", "BID", "Book Name", "Author", "Price", "Amount");
                printf("-------------------------------------------------------------------------------------\n");
                printf("%-6d | %-30s | %-30s | %-6d | %-6d\n",
                       b[index].bid, b[index].name, b[index].author, b[index].price, b[index].amount);
            }
        }

        else if (option == 5) { // sort by name
            if (titles == 0) {
                printf("No Titles added yet! Add new titles first.\n");
            } else {
                struct book sorted[100];
                for (int i = 0; i < titles; i++) sorted[i] = b[i];

                for (int i = 0; i < titles - 1; i++) {
                    for (int j = i + 1; j < titles; j++) {
                        if (strcmp(sorted[i].name, sorted[j].name) > 0) {
                            struct book tmp = sorted[i];
                            sorted[i] = sorted[j];
                            sorted[j] = tmp;
                        }
                    }
                }

                printf("\n%-6s | %-30s | %-30s | %-6s | %-6s\n", "BID", "Book Name", "Author", "Price", "Amount");
                printf("-------------------------------------------------------------------------------------\n");
                for (int i = 0; i < titles; i++) {
                    printf("%-6d | %-30s | %-30s | %-6d | %-6d\n",
                           sorted[i].bid, sorted[i].name, sorted[i].author, sorted[i].price, sorted[i].amount);
                }
            }
        }

        else if (option == 6) { // sort by price
            if (titles == 0) {
                printf("No Titles added yet! Add new titles first.\n");
            } else {
                struct book sortednum[100];
                for (int i = 0; i < titles; i++) sortednum[i] = b[i];

                for (int i = 0; i < titles - 1; i++) {
                    for (int j = i + 1; j < titles; j++) {
                        if (sortednum[i].price > sortednum[j].price) {
                            struct book tmp = sortednum[i];
                            sortednum[i] = sortednum[j];
                            sortednum[j] = tmp;
                        }
                    }
                }

                printf("\n%-6s | %-30s | %-30s | %-6s | %-6s\n", "BID", "Book Name", "Author", "Price", "Amount");
                printf("-------------------------------------------------------------------------------------\n");
                for (int i = 0; i < titles; i++) {
                    printf("%-6d | %-30s | %-30s | %-6d | %-6d\n",
                           sortednum[i].bid, sortednum[i].name, sortednum[i].author, sortednum[i].price, sortednum[i].amount);
                }
            }
        }

        else if (option == 7) { // delete by name
            char bookname[30];
            printf("Enter the book name you want to delete: ");
            read_line(bookname, sizeof bookname);

            int index = find_by_name(b, bookname);
            if (index == -1) {
                printf("Book not found!\n");
            } else {
                char sure[4];
                printf("Are you sure you want to delete '%s' (BID %d)? (y/n): ", b[index].name, b[index].bid);
                read_line(sure, sizeof sure);
                if (sure[0] == 'y' || sure[0] == 'Y') {
                    for (int i = index; i < titles - 1; i++) b[i] = b[i + 1];
                    titles--;
                    printf("Book '%s' deleted successfully!\n", bookname);
                } else {
                    printf("Deletion cancelled.\n");
                }
            }
        }

        else if (option == 8) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}
