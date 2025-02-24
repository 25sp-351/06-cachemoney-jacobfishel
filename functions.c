#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char memo[MEMOIZATION_LIMIT][MAX_LEN]; // memoized array

char process_money(long long money) {
    char result[MAX_LEN];

    number_to_words(money, result);

    printf("%lld = %s\n", money, result);
    return result;
}

void number_to_words(long long num, char *result) {
    char *units[] = {"",     "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};
    char *teens[] = {"",        "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char *tens[]  = {"",      "ten",   "twenty",  "thirty", "forty",
                     "fifty", "sixty", "seventy", "eighty", "ninety"};
    char *thousands[]    = {"", "thousand", "million", "billion"};

    long long dollars    = num / 100;
    int cents            = num % 100;
    char buffer[MAX_LEN] = "";

    if (dollars == 0) {
        strcat(buffer, "zero dollars");
    } else {
        long long part;
        int i = 0;

        while (dollars > 0) {
            part = dollars % 1000;
            dollars /= 1000;

            if (part > 0) {
                char temp[MAX_LEN] = "";

                if (part >= 100) {
                    strcat(temp, units[part / 100]);
                    strcat(temp, " hundred ");
                    part %= 100;
                }
                if (part >= 20) {
                    strcat(temp, tens[part / 10]);
                    if (part % 10) {
                        strcat(temp, "-");
                        strcat(temp, units[part % 10]);
                    }
                } else if (part >= 11 && part <= 19) {
                    strcat(temp, teens[part - 10]);
                } else if (part > 0) {
                    strcat(temp, units[part]);
                }

                if (i > 0) {
                    strcat(temp, " ");
                    strcat(temp, thousands[i]);
                }

                strcat(temp, " ");
                strcat(temp, buffer);
                strcpy(buffer, temp);
            }
            i++;
        }

        strcat(buffer, "dollars");
    }

    strcat(buffer, " and ");

    if (cents == 0) {
        strcat(buffer, "zero");
    }
    // Convert cents
    else if (cents >= 20) {
        strcat(buffer, tens[cents / 10]);
        if (cents % 10) {
            strcat(buffer, "-");
            strcat(buffer, units[cents % 10]);
        }
    } else if (cents >= 11 && cents <= 19) {
        strcat(buffer, teens[cents - 10]);
    } else if (cents == 10 || cents < 10) {
        strcat(buffer, units[cents]);
    }

    strcat(buffer, " cents");

    strcpy(result, buffer);
}
