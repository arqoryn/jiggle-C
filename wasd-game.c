// Author: Mohamad Musadiq
// Description: A simple yet interesting game project in C with 3 different difficulty settings, the avatar is controlled using W/A/S/D keys.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

// Function to print the 10x15 grid
void printBase(char base[10][15]) {
    printf("\n");
    for (int i = 0; i < 10; i++) {         // 10 rows
        for (int j = 0; j < 15; j++) {     // 15 columns
            printf("%c ", base[i][j]);     // print each cell
        }
        printf("\n");
    }
}

// Function to find the row (i) of player 'O'
int positionI(char base[10][15]){
    for (int i=0; i < 10; i++){
        for (int j=0; j < 15; j++){
            if (base[i][j] == 'O'){
                return i;
            }
        }
    }
    return -1; // not found
}

// Function to find the column (j) of player 'O'
int positionJ(char base[10][15]){
    for (int i=0; i < 10; i++){
        for (int j=0; j < 15; j++){
            if (base[i][j] == 'O'){
                return j;
            }
        }
    }
    return -1; // not found
}

// Function to generate coins at random empty position
void coin(char base[10][15]){
    int i_rand, j_rand;
    do {
        i_rand = rand() % 10;     // random row
        j_rand = rand() % 15;     // random column
    } while (base[i_rand][j_rand] != '-'); // only place coin on empty cell

    base[i_rand][j_rand] = '+';   // place the coin
}

int main() {
    srand(time(NULL)); // initialize random number generator once

    // Create grid and fill with '-'
    char base[10][15];
    for (int i=0;i<10;i++){
        for (int j=0;j<15;j++){
            base[i][j] = '-';
        }
    }

    // Place player at starting position
    base[9][7]= 'O';
    // Place the first coin
    coin(base);

    int gameOver = 0;   // flag for ending the game
    int score = 0;      // track score
    int totalTime;      // total time given based on difficulty
    time_t startTime;   // start time of game
    int started = 0;    // flag for when the game actually starts

    // --- Difficulty Selection ---
    printf("Choose difficulty level:\n");
    printf("1. Easy   (20 seconds)\n");
    printf("2. Medium (15 seconds)\n");
    printf("3. Hard   (10 seconds)\n");
    printf("Enter your choice (1/2/3): ");

    int choice;
    scanf("%d", &choice);

    if (choice == 1){
        totalTime = 20;
    } else if (choice == 2){
        totalTime = 15;
    } else {
        totalTime = 10;
    }

    printf("\nPress W/A/S/D to start the game!\n");

    // --- Main game loop ---
    while(!gameOver){
        system("cls");     // clear console
        printBase(base);   // print the grid

        // If game started, show live score and time
        if (started){
            int elapsed = (int)(time(NULL) - startTime); // how many seconds passed
            int timeLeft = totalTime - elapsed;          // remaining time

            printf("\nScore: %d\n", score);
            printf("Time Left: %d seconds\n", timeLeft);

            // If time runs out -> game over
            if (timeLeft <= 0){
                printf("\nTime's up! Final Score = %d\n", score);
                break;
            }
        } 
        // If not started yet, show initial screen
        else {
            printf("\nScore: %d\n", score);
            printf("Time Left: %d seconds\n", totalTime);
        }

        // Get player's current position
        int i = positionI(base);
        int j = positionJ(base);

        // Wait for key press (WASD)
        char key = getch();  

        // If it's the first key press, start timer
        if (!started){
            started = 1;
            startTime = time(NULL);
        }

        // Variables to hold new position
        int newI = i, newJ = j;

        // Check which key was pressed and move accordingly
        if (key == 'W'  || key == 'w'){
            newI = i - 1; // move up
        }
        else if (key == 'A' || key == 'a'){
            newJ = j - 1; // move left
        }
        else if (key == 'D' || key == 'd'){
            newJ = j + 1; // move right
        }
        else if (key == 'S' || key == 's'){
            newI = i + 1; // move down
        }

        // --- Boundary Check ---
        if (newI < 0 || newI > 9 || newJ < 0 || newJ > 14){
            gameOver = 1;
            printf("\nGame Over! You hit the boundary.\n");
            break;
        }

        // --- Coin Collection ---
        if (base[newI][newJ] == '+'){  
            score++;       // increase score
            coin(base);    // spawn another coin at random spot
        }

        // --- Update Player Position ---
        base[newI][newJ] = 'O'; // new position
        base[i][j] = '-';       // previous position becomes empty
    }

    return 0;
}
