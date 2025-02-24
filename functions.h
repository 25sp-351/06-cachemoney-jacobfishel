#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMOIZATION_LIMIT 150000
#define MAX_LEN 500

// Function prototypes
void number_to_words(long long num, char *result);
char process_money(long long money);

#endif