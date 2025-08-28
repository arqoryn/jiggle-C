// Author: Mohamad Musadiq
// Description: A basic 2-player tic tac toe game, with everything but the overwrite prevention functionality

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

char base[3][3]= {{'-','-','-'},
                  {'-','-','-'},
                  {'-','-','-'}};


void printBase(char base[3][3]){
        printf("\n");
        for (int i =0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%c\t", base[i][j]);
        }
        printf("\n\n");
    }
}

void p1(char choice){
        if (choice=='q'||choice=='Q'){
            base[0][0]='X';
        }
        else if (choice=='w'||choice=='W'){
            base[0][1]='X';
        }
        else if (choice=='e'||choice=='E'){
            base[0][2]='X';
        }
        else if (choice=='a'||choice=='A'){
            base[1][0]='X';
        }
        else if (choice=='s'||choice=='S'){
            base[1][1]='X';
        }
        else if (choice=='d'||choice=='D'){
            base[1][2]='X';
        }
        else if (choice=='z'||choice=='Z'){
            base[2][0]='X';
        }
        else if (choice=='x'||choice=='X'){
            base[2][1]='X';
        }
        else if (choice=='c'||choice=='C'){
            base[2][2]='X';
        }
}

void p2(char choice){
        if (choice=='q'||choice=='Q'){
            base[0][0]='O';
        }
        else if (choice=='w'||choice=='W'){
            base[0][1]='O';
        }
        else if (choice=='e'||choice=='E'){
            base[0][2]='O';
        }
        else if (choice=='a'||choice=='A'){
            base[1][0]='O';
        }
        else if (choice=='s'||choice=='S'){
            base[1][1]='O';
        }
        else if (choice=='d'||choice=='D'){
            base[1][2]='O';
        }
        else if (choice=='z'||choice=='Z'){
            base[2][0]='O';
        }
        else if (choice=='x'||choice=='X'){
            base[2][1]='O';
        }
        else if (choice=='c'||choice=='C'){
            base[2][2]='O';
        }
}
int winner(char base[3][3]){

    //horizontal check
    for (int i=0; i <=2; i++){
        if (base[i][0] != '-' && base[i][0]==base[i][1] && base[i][0]==base[i][2]){
            if(base[i][0]=='X') return 1;
            else if (base[i][0]=='O') return 2;
        }
    }

    // vertical check
    for (int i=0; i <=2; i++){
        if (base[i][0] != '-' && base[0][i]==base[1][i] && base[0][i]==base[2][i]){
            if(base[0][i]=='X') return 1;
            else if (base[0][i]=='O') return 2;
        }
    }

    // diagonal check
    if (base[0][0] != '-' && base[0][0]==base[1][1] && base[0][0]==base[2][2]){
        if (base[0][0]=='X') return 1;
        else if (base[0][0]=='O') return 2;
    }
    else if (base[0][2] != '-' && base[0][2]==base[1][1] && base[0][2]==base[2][0]){
        if (base[0][2]=='X') return 1;
        else if (base[0][2]=='O') return 2;
    }

    else return 0;
}


int main(){

    system("cls");
    printBase(base);

    int moves = 0; 

    for (int i=1; i<=9; i++){

        if (i%2!=0){
            int choice;
            printf("Player 1, Make your choice: ");
            moves++;
            choice = getch();
            p1(choice);
        }
        else {
            int choice;
            printf("Player 2, Make your choice: ");
            moves++;
            choice = getch();
            p2(choice);
        }
        system("cls");
        printBase(base);


        int victor = winner(base);
        if (victor == 1){
            printf("Player 1 wins the game!");
            break;
        }
        else if (victor == 2){
            printf("Player 2 wins the game!");
            break;
        }
    }
    if (moves==9){
    printf("DRAW!");
    }
    
    return 0;
}
