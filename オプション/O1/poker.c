#include <stdio.h>

int main(void) {
    int num[5], i, j, count[14] = {0};

    while (scanf("%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]) != EOF) {
        for (i = 0; i < 5; i++) {
            count[num[i]]++;
        }

        int pair = 0, three = 0, four = 0;
        for (i = 1; i <= 13; i++) {
            if (count[i] == 2) pair++;
            if (count[i] == 3) three++;
            if (count[i] == 4) four++;
            count[i] = 0;
        }

        if (four) printf("four of a kind\n");
        else if (three && pair) printf("full house\n");
        else if (three) printf("three of a kind\n");
        else if (pair == 2) printf("two pair\n");
        else if (pair) printf("one pair\n");
        else printf("no pair\n");
    }

    return 0;
}