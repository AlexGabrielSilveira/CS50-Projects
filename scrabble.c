#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int compute_score(string word);

int main (void) {


    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2) {
        printf("Player 1 Wins!\n");
    } else if ( score1 < score2 ) {
        printf("Player 2 Wins! \n");
    }else {
        printf("Tie !\n");
    }
}

int compute_score(string word) {
    int score = 0;

    for(int i = 0, length = strlen(word); i < length; i++) {
        if(isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }else if (islower(word[i])){
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;

}
