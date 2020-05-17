#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 10000   // Max input string length

// Get string from stdin
int getline(char s[], int lim){
    int i, c;
    i = 0;
    while(--lim>0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if(c == '\n')
        s[i] = '\0';
    return i;
}

int main(){
    // Char array
    char s[] = " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

    srand(time(NULL));  // Rand init
    char x[MAX];        // Input string
    int length = 0;     // Input string length
    int r = 0;          // Random number
    int n = 0;          // Number of attempts

    // Main loop
    while(1){
        // Input string load
        length = getline(x, MAX);
        printf("\nString length: %d\n\n", length);
        n = 0;

        // Timer start
        double start = clock();
        char rs[length];

        // Attempt cycle
        while(strcmp(x, rs) != 0){
            // Random string
            for(int i = 0; i < length; i++){
                r = rand()%strlen(s);
                if(x[i] != rs[i]){
                    rs[i] = s[r];
                }
            }
            rs[length] = '\0';
            printf("Attempt %d\n\n%s\n\n%s\n\n", n, x, rs);
            n++;
        }

        // Timer stop and output
        //printf("Number of attempts: %d\n\n%s\n\n%s\n\n", n, x, rs);
        printf("Time: %.4lf s\n\n", (clock() - start) / CLOCKS_PER_SEC);
    }
}
