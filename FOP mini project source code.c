#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    int player, computer;
    int playerScore = 0, computerScore = 0;

    int balls = 18;

    int playerHalf = 0, playerCentury = 0;
    int computerHalf = 0, computerCentury = 0;

    int playerBatsFirst = 1;
    char choice[10];

    srand(time(0));

    /* PLAYER TEAM */
    char players[3][50];
    int playerRuns[3] = {0};
    int playerBalls[3] = {0};

    /* BOWLING STATS */
    int playerWickets[3] = {0};
    int playerRunsGiven[3] = {0};

    printf("===== HAND CRICKET GAME =====\n");
    printf("Match Format: 3 Overs (18 Balls per innings)\n");

    for(int i = 0; i < 3; i++) {
        printf("Enter Player %d name: ", i+1);
        scanf("%s", players[i]);
    }

    printf("\nChoose numbers between 0 and 6\n");
    printf("Same number -> OUT\n");
    printf("ZERO RULE: If batter chooses 0, they copy bowler runs.\n");
    printf("If both choose 0 -> OUT\n\n");

    /* ---------------- TOSS ---------------- */

    printf("----- TOSS TIME -----\n");
    printf("Enter your toss number (1-6): ");
    scanf("%d", &player);

    printf("Choose Odd or Even: ");
    scanf("%s", choice);

    computer = rand() % 6 + 1;
    printf("Computer chose number: %d\n", computer);

    int total = player + computer;
    printf("Total = %d\n", total);

    int playerWinsToss = 0;

    if ((total % 2 == 0 && strcmp(choice, "even") == 0) ||
        (total % 2 != 0 && strcmp(choice, "odd") == 0))
        playerWinsToss = 1;

    if (playerWinsToss) {
        printf("You won the toss!\n");
        printf("Choose Bat or Bowl: ");
        scanf("%s", choice);

        if (strcmp(choice, "bat") == 0)
            playerBatsFirst = 1;
        else
            playerBatsFirst = 0;
    } else {
        printf("Computer won the toss!\n");
        computer = rand() % 2;
        if (computer == 0) {
            printf("Computer chooses to Bat first.\n");
            playerBatsFirst = 0;
        } else {
            printf("Computer chooses to Bowl first.\n");
            playerBatsFirst = 1;
        }
    }

    printf("\n--------------------------------\n");

    /* ================= MATCH ================= */

    if (playerBatsFirst) {

        /* PLAYER BATTING */
        printf("PLAYER BATTING\n");

        int currentBatsman = 0;
        printf("%s comes to bat!\n\n", players[currentBatsman]);

        for(int i = 1; i <= balls; i++) {

            if(currentBatsman == 3) break;

            int over = (i - 1) / 6;
            int ball = (i - 1) % 6 + 1;

            printf("Over %d.%d (Bowler: Computer Player %d)\n", over, ball, over+1);
            printf("%s - Enter run (0-6): ", players[currentBatsman]);
            scanf("%d", &player);

            if(player < 0 || player > 6) {
                printf("Invalid input!\n");
                i--;
                continue;
            }

            playerBalls[currentBatsman]++;
            computer = rand() % 7;

            printf("Computer bowled: %d\n", computer);

            if(player == 0) {
                if(computer == 0) {
                    printf("%s OUT!\n", players[currentBatsman]);
                    currentBatsman++;
                    if(currentBatsman < 3)
                        printf("%s comes to bat!\n\n", players[currentBatsman]);
                    continue;
                } else {
                    playerScore += computer;
                    playerRuns[currentBatsman] += computer;
                }
            }
            else if(player == computer) {
                printf("%s OUT!\n", players[currentBatsman]);
                currentBatsman++;
                if(currentBatsman < 3)
                    printf("%s comes to bat!\n\n", players[currentBatsman]);
                continue;
            }
            else {
                playerScore += player;
                playerRuns[currentBatsman] += player;
            }

            printf("Score: %d\n\n", playerScore);
        }

        printf("Player Final Score = %d\n\n", playerScore);

        /* COMPUTER BATTING (3 WICKETS) */
        printf("COMPUTER BATTING (Target: %d)\n", playerScore + 1);

        int wickets = 0;

        for(int i = 1; i <= balls; i++) {

            if(wickets == 3) break;

            int over = (i - 1) / 6;
            int ball = (i - 1) % 6 + 1;
            int bowler = over % 3;

            printf("Over %d.%d (Bowler: %s)\n", over, ball, players[bowler]);
            printf("Enter bowl (0-6): ");
            scanf("%d", &player);

            if(player < 0 || player > 6) {
                printf("Invalid input!\n");
                i--;
                continue;
            }

            computer = rand() % 7;
            printf("Computer played: %d\n", computer);

            if(computer == 0) {
                if(player == 0) {
                    printf("OUT!\n");
                    playerWickets[bowler]++;
                    wickets++;
                    continue;
                } else {
                    computerScore += player;
                    playerRunsGiven[bowler] += player;
                }
            }
            else if(player == computer) {
                printf("OUT!\n");
                playerWickets[bowler]++;
                wickets++;
                continue;
            }
            else {
                computerScore += computer;
                playerRunsGiven[bowler] += computer;
            }

            printf("Computer Score: %d\n\n", computerScore);

            if(computerScore > playerScore) {
                printf("COMPUTER WON BY %d WICKETS!\n", 3 - wickets);
                break;
            }
        }

        if(computerScore <= playerScore)
            printf("PLAYER WON BY %d RUNS!\n", playerScore - computerScore);

    } else {

        /* COMPUTER BATTING FIRST */
        printf("COMPUTER BATTING\n");

        int wickets = 0;

        for(int i = 1; i <= balls; i++) {

            if(wickets == 3) break;

            int over = (i - 1) / 6;
            int ball = (i - 1) % 6 + 1;
            int bowler = over % 3;

            printf("Over %d.%d (Bowler: %s)\n", over, ball, players[bowler]);
            printf("Enter bowl (0-6): ");
            scanf("%d", &player);

            if(player < 0 || player > 6) {
                printf("Invalid input!\n");
                i--;
                continue;
            }

            computer = rand() % 7;
            printf("Computer played: %d\n", computer);

            if(computer == 0) {
                if(player == 0) {
                    printf("OUT!\n");
                    playerWickets[bowler]++;
                    wickets++;
                    continue;
                } else {
                    computerScore += player;
                    playerRunsGiven[bowler] += player;
                }
            }
            else if(player == computer) {
                printf("OUT!\n");
                playerWickets[bowler]++;
                wickets++;
                continue;
            }
            else {
                computerScore += computer;
                playerRunsGiven[bowler] += computer;
            }

            printf("Computer Score: %d\n\n", computerScore);
        }

        printf("Computer Final Score = %d\n\n", computerScore);

        /* PLAYER CHASE */
        printf("PLAYER BATTING (Target: %d)\n", computerScore + 1);

        int currentBatsman = 0;
        printf("%s comes to bat!\n\n", players[currentBatsman]);

        for(int i = 1; i <= balls; i++) {

            if(currentBatsman == 3) break;

            int over = (i - 1) / 6;
            int ball = (i - 1) % 6 + 1;

            printf("Over %d.%d (Bowler: Computer Player %d)\n", over, ball, over+1);
            printf("%s - Enter run (0-6): ", players[currentBatsman]);
            scanf("%d", &player);

            if(player < 0 || player > 6) {
                printf("Invalid input!\n");
                i--;
                continue;
            }

            playerBalls[currentBatsman]++;
            computer = rand() % 7;

            printf("Computer bowled: %d\n", computer);

            if(player == 0) {
                if(computer == 0) {
                    printf("%s OUT!\n", players[currentBatsman]);
                    currentBatsman++;
                    if(currentBatsman < 3)
                        printf("%s comes to bat!\n\n", players[currentBatsman]);
                    continue;
                } else {
                    playerScore += computer;
                    playerRuns[currentBatsman] += computer;
                }
            }
            else if(player == computer) {
                printf("%s OUT!\n", players[currentBatsman]);
                currentBatsman++;
                if(currentBatsman < 3)
                    printf("%s comes to bat!\n\n", players[currentBatsman]);
                continue;
            }
            else {
                playerScore += player;
                playerRuns[currentBatsman] += player;
            }

            printf("Score: %d\n\n", playerScore);

            if(playerScore > computerScore) {
                printf("PLAYER WON BY %d WICKETS!\n", 3 - currentBatsman - 1);
                break;
            }
        }

        if(playerScore <= computerScore)
            printf("COMPUTER WON BY %d RUNS!\n", computerScore - playerScore);
    }

    /* SCORECARD */
    printf("\n===== SCORECARD =====\n");
    printf("\nBATTING:\n");
    printf("Player\t\tRuns\tBalls\n");

    for(int i = 0; i < 3; i++) {
        printf("%s\t\t%d\t%d\n", players[i], playerRuns[i], playerBalls[i]);
    }

    printf("\nBOWLING:\n");
    printf("Player\t\tWickets\tRuns Given\n");

    for(int i = 0; i < 3; i++) {
        printf("%s\t\t%d\t%d\n", players[i], playerWickets[i], playerRunsGiven[i]);
    }

    printf("\nTotal Score: %d\n", playerScore);

    return 0;
}