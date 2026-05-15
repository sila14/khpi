#include <stdio.h>

/*
 * Lab 04_02 (Variant 3)
 * Task: Traffic light. Input color code (1–red, 2–yellow, 3–green) and print the corresponding action.
 * Notes: one switch statement, no loops, no arrays, no user functions.
 */

int main(void) {
    int code;

    printf("Enter traffic light code (1=red, 2=yellow, 3=green): ");
    if (scanf("%d", &code) != 1) {
        puts("Input error");
        return 1;
    }

    switch (code) {
        case 1:
            puts("RED: STOP");
            break;
        case 2:
            puts("YELLOW: WAIT / PREPARE");
            break;
        case 3:
            puts("GREEN: GO");
            break;
        default:
            puts("Error: code must be 1, 2, or 3");
            return 2;
    }

    return 0;
}
