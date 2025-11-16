// A console-based piano simulation program that employs the Beep() function to produce a variety of musical notes.
// Author: Mohamad Musadiq (GITHUB: @arqoryn)

#include <stdio.h>
#include <conio.h>
#include <windows.h>

// Functions for each piano note
void playQ() { Beep(261, 400); } // C4
void playW() { Beep(293, 400); } // D4
void playE() { Beep(329, 400); } // E4
void playR() { Beep(349, 400); } // F4
void playT() { Beep(392, 400); } // G4
void playY() { Beep(440, 400); } // A4
void playU() { Beep(493, 400); } // B4
void playI() { Beep(523, 400); } // C5
void playO() { Beep(587, 400); } // D5
void playP() { Beep(659, 400); } // E5

int main() {
    char ch;
    printf("Piano App (press q-w-e-r-t-y-u-i-o-p, press ESC to quit)\n");

    while (1) {
        ch = getch(); // read key

        switch (ch) {
            case 'q': playQ(); break;
            case 'w': playW(); break;
            case 'e': playE(); break;
            case 'r': playR(); break;
            case 't': playT(); break;
            case 'y': playY(); break;
            case 'u': playU(); break;
            case 'i': playI(); break;
            case 'o': playO(); break;
            case 'p': playP(); break;
            case 27: return 0; // ESC key exits
        }
    }
}
