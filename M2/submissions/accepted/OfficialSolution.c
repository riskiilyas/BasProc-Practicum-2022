#include<stdio.h>
#include<stdlib.h>

int main() {
    int digits, doubler;
    char cash[100], result;

    scanf("%d", &digits);
    scanf("%s", cash);
    getchar();
    scanf("%c", &result);

    if (result == 'W'){
        printf("Win!\n");
        doubler = 2;
    } else if (result == 'J'){
        printf("Jackpot!\n");
        doubler = 5;
    } else {
        printf("Lose! you're no longer a quadrillionaire now :\"(\n");
        return 0;
    }

    int carry = 0;
    for(int i = digits-1; i>=0; i--) {
        int _digit = ((int)(cash[i] - '0') * doubler) + carry;
        carry = _digit/10;

        cash[i] = '0' + (_digit%10);
    }

    printf("Prize: $");
    if(carry!=0) printf("%d", carry);
    for (int i = 0; i < digits; i++){
        printf("%c", cash[i]);
    }

    return 0;
}
