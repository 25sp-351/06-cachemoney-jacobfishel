#include <stdio.h>
#include "cache.h"

long results[MEMOIZATION_LIMIT][MAX_LEN];

char_func_ptr original_provider;
char_func_ptr money_to_word_pointer;

long long *cache(long val) {
    if (val > MEMOIZATION_LIMIT) {
        printf("Returned a memoized value");
        return (*original_provider)(val);

    }
    if (results[val][0] == NOT_PRESENT) {
        results[val][0] = (*original_provider)(val);
        // printf("Cached: %ld", results[val][0]);
    }
    return results[val][0];
}

void init_cache() {
    for (int i = 0; i < 150000; i++) {
        results[i][0] = NOT_PRESENT;
    }
}