// Enter a text and this program with give an audio morse output along with the visual output
#include <stdio.h>
#include <string.h>
#include <windows.h>

void playDot() {
    Beep(500, 100);
}

void playDash() {
    Beep(500, 400);
}

int main() {
    char *morse[26] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    char name[100];
    printf("Enter text: ");
    fgets(name, sizeof(name), stdin);

    int length = strlen(name);

    for (int i = 0; i < length; i++) {
        switch (name[i]) {
            case 'A': case 'a': printf("%s ",morse[0]); playDot(); playDash(); break;
            case 'B': case 'b': printf("%s ",morse[1]); playDash(); playDot(); playDot(); playDot();  break;
            case 'C': case 'c': printf("%s ",morse[2]); playDash(); playDot(); playDash(); playDot(); break;
            case 'D': case 'd': printf("%s ",morse[3]); playDash(); playDot(); playDot(); break;
            case 'E': case 'e': printf("%s ",morse[4]); playDot(); break;
            case 'F': case 'f': printf("%s ",morse[5]); playDot(); playDot(); playDash(); playDot(); break;
            case 'G': case 'g': printf("%s ",morse[6]); playDash(); playDash(); playDot(); break;
            case 'H': case 'h': printf("%s ",morse[7]); playDot(); playDot(); playDot(); playDot(); break;
            case 'I': case 'i': printf("%s ",morse[8]); playDot(); playDot(); break;
            case 'J': case 'j': printf("%s ",morse[9]); playDot(); playDash(); playDash(); playDash(); break;
            case 'K': case 'k': printf("%s ",morse[10]); playDash(); playDot(); playDash(); break;
            case 'L': case 'l': printf("%s ",morse[11]); playDot(); playDash(); playDot(); playDot(); break;
            case 'M': case 'm': printf("%s ",morse[12]); playDash(); playDash(); break;
            case 'N': case 'n': printf("%s ",morse[13]); playDash(); playDot(); break;
            case 'O': case 'o': printf("%s ",morse[14]); playDash(); playDash(); playDash(); break;
            case 'P': case 'p': printf("%s ",morse[15]); playDot(); playDash(); playDash(); playDot(); break;
            case 'Q': case 'q': printf("%s ",morse[16]); playDash(); playDash(); playDot(); playDash(); break;
            case 'R': case 'r': printf("%s ",morse[17]); playDot(); playDash(); playDot(); break;
            case 'S': case 's': printf("%s ",morse[18]); playDot(); playDot(); playDot(); break;
            case 'T': case 't': printf("%s ",morse[19]); playDash(); break;
            case 'U': case 'u': printf("%s ",morse[20]); playDot(); playDot(); playDash(); break;
            case 'V': case 'v': printf("%s ",morse[21]); playDot(); playDot(); playDot(); playDash(); break;
            case 'W': case 'w': printf("%s ",morse[22]); playDot(); playDash(); playDash(); break;
            case 'X': case 'x': printf("%s ",morse[23]); playDash(); playDot(); playDot(); playDash(); break;
            case 'Y': case 'y': printf("%s ",morse[24]); playDash(); playDot(); playDash(); playDash(); break;
            case 'Z': case 'z': printf("%s ",morse[25]); playDash(); playDash(); playDot(); playDot(); break;
            case ' ': Sleep(1000); break; // gap for space
        }
        Sleep(200); // gap between letters
    }

    return 0;
}
