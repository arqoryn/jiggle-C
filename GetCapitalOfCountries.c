#include <stdio.h>
#include <string.h>
int main(){
    FILE *fp;
    fp = fopen("capitals.txt", "r");

    if (fp == NULL){
        printf("File not found!");
        return 1;
    }

    char searchCountry[20];
    printf("Enter the country name to get the capital: ");
    gets(searchCountry);

 
    char FileCountry[50];
    char capital[50];
    while (fscanf(fp, "%s - %[^\n]", FileCountry, capital) == 2){
        if (strcasecmp(searchCountry, FileCountry) == 0){
            printf("Capital of %s is %s", FileCountry, capital);
            return 0;
        }
    }
    printf("Country not found! ");

    return 0;
}
