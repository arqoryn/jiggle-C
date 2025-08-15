// Chishiya-style 80% of Average Game (Human vs Bots)
// Windows console build: cl /std:c11 game.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>  // Sleep, system("cls")

// ----- Config -----
#define NUM_PLAYERS 4      // 1 human + 3 bots
#define HUMAN_INDEX 0
// Fixed bot reasoning levels (can randomize per round if you want)
int BOT_LEVELS[3] = {0, 1, 2}; // Level0=random, Level1=0.8*50, Level2=0.8*(0.8*50)

// ----- Utils -----
int clamp_int(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

// Bot strategy:
// Level 0: random 1..100
// Level k>=1: 50 * (0.8^k), optionally with tiny noise
int bot_guess(int level) {
    if (level <= 0) {
        return (rand() % 100) + 1;
    } else {
        double g = 50.0;
        for (int i = 0; i < level; i++) g *= 0.8; // 50 * (0.8^level)
        // add a tiny ±1 jitter so ties are less frequent
        int jitter = (rand() % 3) - 1; // -1,0,1
        int gi = (int)floor(g + 0.5) + jitter;
        return clamp_int(gi, 1, 100);
    }
}

// Find all winners (closest to target). Returns number of winners and fills winners[] with indices.
int find_winners(const int guesses[], double target, int winners[], int n) {
    double best = 1e9;
    for (int i = 0; i < n; i++) {
        double d = fabs((double)guesses[i] - target);
        if (d < best) best = d;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        double d = fabs((double)guesses[i] - target);
        // Allow tiny FP tolerance
        if (fabs(d - best) < 1e-9) {
            winners[k++] = i;
        }
    }
    return k;
}

int main(void) {
    srand((unsigned)time(NULL));

    int rounds = 10;
    int scores[NUM_PLAYERS] = {0};

    system("cls");
    printf("=== CHISHIYA'S 80%% OF AVERAGE ===\n");
    printf("Rules:\n");
    printf(" - Everyone picks a number (1..100)\n");
    printf(" - Compute Average of all guesses\n");
    printf(" - Target = 0.8 * Average\n");
    printf(" - Closest to Target wins the round (ties allowed)\n\n");
    printf("Enter number of rounds (default 10): ");
    int tmp;
    if (scanf("%d", &tmp) == 1 && tmp > 0) rounds = tmp;

    for (int r = 1; r <= rounds; r++) {
        int guesses[NUM_PLAYERS] = {0};
        system("cls");
        printf("===== ROUND %d / %d =====\n\n", r, rounds);
        Sleep(800);

        // Human input
        int g;
        do {
            printf("Your guess (1-100): ");
            if (scanf("%d", &g) != 1) {
                // clear bad input
                int c; while ((c = getchar()) != '\n' && c != EOF) {}
                g = -1;
            }
        } while (g < 1 || g > 100);
        guesses[HUMAN_INDEX] = g;

        // Bots think & choose
        for (int i = 1; i < NUM_PLAYERS; i++) {
            int level = BOT_LEVELS[i - 1];
            guesses[i] = bot_guess(level);
        }

        printf("\nLocking in guesses");
        for (int dots = 0; dots < 3; dots++) { printf("."); Sleep(500); }
        printf("\n\n");
        Sleep(300);

        // Reveal guesses
        printf("Reveals:\n");
        printf(" - You: %d\n", guesses[HUMAN_INDEX]); Sleep(400);
        for (int i = 1; i < NUM_PLAYERS; i++) {
            printf(" - Bot %d (L%d): %d\n", i, BOT_LEVELS[i - 1], guesses[i]);
            Sleep(400);
        }
        Sleep(700);

        // Compute average and target
        int sum = 0;
        for (int i = 0; i < NUM_PLAYERS; i++) sum += guesses[i];
        double avg = (double)sum / (double)NUM_PLAYERS;
        double target = 0.8 * avg;

        printf("\nAverage = %.2f\n", avg); Sleep(700);
        printf("Target  = 0.8 * Average = %.2f\n", target); Sleep(1200);

        // Determine winner(s)
        int winners[NUM_PLAYERS];
        int k = find_winners(guesses, target, winners, NUM_PLAYERS);

        // Score & announce
        if (k == 1) {
            int w = winners[0];
            scores[w] += 1;
            if (w == HUMAN_INDEX) {
                printf("\n>>> You win the round! (+1)\n");
            } else {
                printf("\n>>> Bot %d wins the round! (+1)\n", w);
            }
        } else {
            printf("\n>>> It's a tie between: ");
            for (int i = 0; i < k; i++) {
                if (winners[i] == HUMAN_INDEX) printf("[You] ");
                else printf("[Bot %d] ", winners[i]);
                scores[winners[i]] += 1; // everyone tied gets +1
            }
            printf("\n");
        }
        Sleep(1500);

        // Show distances
        printf("\nDistances from Target:\n");
        for (int i = 0; i < NUM_PLAYERS; i++) {
            double d = fabs((double)guesses[i] - target);
            if (i == HUMAN_INDEX) printf(" - You: %.2f\n", d);
            else printf(" - Bot %d: %.2f\n", i, d);
        }
        Sleep(1500);

        // Scoreboard
        printf("\nScoreboard:\n");
        printf(" - You: %d\n", scores[HUMAN_INDEX]);
        for (int i = 1; i < NUM_PLAYERS; i++) {
            printf(" - Bot %d: %d\n", i, scores[i]);
        }

        if (r < rounds) {
            printf("\nNext round starting...");
            for (int dots = 0; dots < 3; dots++) { printf("."); Sleep(600); }
            // Clear for the next round
        }
    }

    system("cls");
    printf("===== FINAL RESULTS =====\n\n");
    printf("Scores:\n");
    printf(" - You: %d\n", scores[HUMAN_INDEX]);
    for (int i = 1; i < NUM_PLAYERS; i++) {
        printf(" - Bot %d: %d\n", i, scores[i]);
    }

    // Find overall winners (could tie)
    int best = -1;
    for (int i = 0; i < NUM_PLAYERS; i++) if (scores[i] > best) best = scores[i];

    int youWin = (scores[HUMAN_INDEX] == best);
    int tieCount = 0;
    for (int i = 0; i < NUM_PLAYERS; i++) if (scores[i] == best) tieCount++;

    printf("\n");
    if (tieCount == 1) {
        if (youWin) printf("🎉 You are the overall winner! 🎉\n");
        else {
            // find the bot
            for (int i = 1; i < NUM_PLAYERS; i++)
                if (scores[i] == best) { printf("Bot %d is the overall winner!\n", i); break; }
        }
    } else {
        printf("🤝 Overall tie between: ");
        if (youWin) printf("[You] ");
        for (int i = 1; i < NUM_PLAYERS; i++)
            if (scores[i] == best) printf("[Bot %d] ", i);
        printf("\n");
    }

    printf("\nThanks for playing!\n");
    Sleep(2500);
    return 0;
}
